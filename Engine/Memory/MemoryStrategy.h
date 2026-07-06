#pragma once

#include <array>
#include <cstddef>
#include <new>
#include <type_traits>
#include <utility>

class LinearArena
{
public:
    explicit LinearArena(std::size_t capacityBytes);
    ~LinearArena();

    LinearArena(const LinearArena&) = delete;
    LinearArena& operator=(const LinearArena&) = delete;

    void* Allocate(std::size_t size, std::size_t alignment = alignof(std::max_align_t));
    void Reset();

    std::size_t GetUsedBytes() const;
    std::size_t GetCapacityBytes() const;

private:
    unsigned char* Buffer = nullptr;
    std::size_t CapacityBytes = 0;
    std::size_t Offset = 0;
};

template<typename T, std::size_t N>
class ObjectPool
{
public:
    template<typename... Args>
    T* Acquire(Args&&... args)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            if (!Used[i])
            {
                Used[i] = true;
                T* ptr = reinterpret_cast<T*>(&Storage[i]);
                new (ptr) T(std::forward<Args>(args)...);
                return ptr;
            }
        }
        return nullptr;
    }

    bool Release(T* object)
    {
        if (object == nullptr)
        {
            return false;
        }

        const auto begin = reinterpret_cast<T*>(&Storage[0]);
        const auto end = reinterpret_cast<T*>(&Storage[N - 1]) + 1;
        if (object < begin || object >= end)
        {
            return false;
        }

        const std::size_t index = static_cast<std::size_t>(object - begin);
        if (!Used[index])
        {
            return false;
        }

        object->~T();
        Used[index] = false;
        return true;
    }

    std::size_t GetUsedCount() const
    {
        std::size_t count = 0;
        for (bool flag : Used)
        {
            if (flag)
            {
                ++count;
            }
        }
        return count;
    }

private:
    using StorageType = typename std::aligned_storage<sizeof(T), alignof(T)>::type;
    std::array<StorageType, N> Storage{};
    std::array<bool, N> Used{};
};

struct MemoryStats
{
    std::size_t ArenaUsedBytes = 0;
    std::size_t ArenaCapacityBytes = 0;
};

MemoryStats GetMemoryStats(const LinearArena& arena);
