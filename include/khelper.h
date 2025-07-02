#include <cstdint>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>

using i8  = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8  = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using String = std::string;
using str    = const char*;

template <typename T>
using sptr = std::shared_ptr<T>;
using std::make_shared;

template <typename T>
using uptr = std::unique_ptr<T>;
using std::make_unique;

template <typename T>
void println(T input) {
    std::cout << input << '\n';
}

using std::array;

template <typename T>
using Vec = std::vector<T>;

template <typename T>
using Option = std::optional<T>;

using V = void;

using std::getline;
using std::to_string;
