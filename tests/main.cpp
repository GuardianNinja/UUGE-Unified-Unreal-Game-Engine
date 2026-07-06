#include <iostream>

int passed = 0;
int failed = 0;

void report(const std::string& name, bool result) {
    if (result) {
        std::cout << "[PASS] " << name << "\n";
        passed++;
    } else {
        std::cout << "[FAIL] " << name << "\n";
        failed++;
    }
}

int main() {
    std::cout << "Running UUGE Tests...\n";

    extern void run_ecs_tests();
    extern void run_physics_tests();
    extern void run_scene_tests();
    extern void run_memory_tests();
    extern void run_input_tests();
    extern void run_network_tests();
    extern void run_serialization_tests();

    run_ecs_tests();
    run_physics_tests();
    run_scene_tests();
    run_memory_tests();
    run_input_tests();
    run_network_tests();
    run_serialization_tests();

    std::cout << "\nPassed: " << passed << "\nFailed: " << failed << "\n";

    return failed == 0 ? 0 : 1;
}
