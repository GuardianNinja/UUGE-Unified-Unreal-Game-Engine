#include "../../Engine/Memory/Arena.h"

void run_memory_tests() {
    Arena arena(1024);

    void* a = arena.Allocate(128);
    void* b = arena.Allocate(128);

    report("Arena Allocation", a != nullptr && b != nullptr);

    arena.Reset();
    void* c = arena.Allocate(128);

    report("Arena Reset", c != nullptr);
}
