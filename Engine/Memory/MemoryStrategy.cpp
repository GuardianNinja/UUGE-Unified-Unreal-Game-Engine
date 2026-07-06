#include "MemoryStrategy.h"

#include <cstdint>

LinearArena::LinearArena(std::size_t capacityBytes)
    : CapacityBytes(capacityBytes)
{
    Buffer = new unsigned char[CapacityBytes];
}

LinearArena::~LinearArena()
{
    delete[] Buffer;
}

void* LinearArena::Allocate(std::size_t size, std::size_t alignment)
{
    if (Buffer == nullptr || size == 0)
    {
        return nullptr;
    }

    std::uintptr_t current = reinterpret_cast<std::uintptr_t>(Buffer + Offset);
    const std::size_t mask = alignment - 1;
    const std::uintptr_t aligned = (current + mask) & ~static_cast<std::uintptr_t>(mask);
    const std::size_t alignedOffset = static_cast<std::size_t>(aligned - reinterpret_cast<std::uintptr_t>(Buffer));

    if (alignedOffset + size > CapacityBytes)
    {
        return nullptr;
    }

    Offset = alignedOffset + size;
    return Buffer + alignedOffset;
}

void LinearArena::Reset()
{
    Offset = 0;
}

std::size_t LinearArena::GetUsedBytes() const
{
    return Offset;
}

std::size_t LinearArena::GetCapacityBytes() const
{
    return CapacityBytes;
}

MemoryStats GetMemoryStats(const LinearArena& arena)
{
    MemoryStats stats;
    stats.ArenaUsedBytes = arena.GetUsedBytes();
    stats.ArenaCapacityBytes = arena.GetCapacityBytes();
    return stats;
}
