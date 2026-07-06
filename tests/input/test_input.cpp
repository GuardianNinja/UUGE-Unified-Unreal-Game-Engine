#include "../../Engine/Input/Input.h"

void run_input_tests() {
    Input input;

    input.SetKeyDown("A");
    report("Input KeyDown", input.IsKeyDown("A"));

    input.SetKeyUp("A");
    report("Input KeyUp", !input.IsKeyDown("A"));
}
