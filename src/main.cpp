#include "khelper.h"
#include "lib.h"

auto main() -> i32 {
    println("Hello world. " + to_string(helper::add(42, 30)));
    return 0;
}
