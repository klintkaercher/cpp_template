cmake_minimum_required(VERSION 3.14)
project(MyProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# --- GoogleTest ---
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# --- Google Benchmark ---
FetchContent_Declare(
  benchmark
  URL https://github.com/google/benchmark/archive/refs/heads/main.zip
)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
FetchContent_MakeAvailable(benchmark)

enable_testing()

# # --- Main Library or Executable (Optional) ---
add_library(${PROJECT_NAME}_lib src/lib.cpp include/lib.h)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME} PRIVATE include/)

# --- Tests ---
file(GLOB TEST_SOURCES tests/*.cpp)
add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests PRIVATE gtest_main ${PROJECT_NAME}_lib)
target_include_directories(runTests PRIVATE include/)

include(GoogleTest)
gtest_discover_tests(runTests)

# # --- Benchmarks ---
file(GLOB BENCH_SOURCES benchmarks/*.cpp)
add_executable(runBenchmarks ${BENCH_SOURCES})
target_link_libraries(runBenchmarks PRIVATE benchmark::benchmark ${PROJECT_NAME}_lib)
target_include_directories(runBenchmarks PRIVATE include/)
