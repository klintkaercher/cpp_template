#include <benchmark/benchmark.h>
#include "lib.h"


static void BM_Add(benchmark::State& state) {
    for (auto _ : state) {
        benchmark::DoNotOptimize(helper::add(123, 456));
    }
}
BENCHMARK(BM_Add);

BENCHMARK_MAIN();
