project_name := "MyProject"

alias b := build
alias r := run
alias t := test
alias f := format

@build:
    cmake --build build

@full-build: init build

@init:
    cmake -B build -G Ninja

@run:
    ./build/{{project_name}}

@test:
    ./build/runTests

@bench:
    ./build/runBenchmarks

@clean:
    rm -rf build/ Testing/

@format:
    clang-format -i include/* src/*
