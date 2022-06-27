#include <benchmark/benchmark.h>
#include <vector>

using namespace std;

static void BM_Insert(benchmark::State &state)
{
    vector<double> v(0);
    auto val = v.begin();
    while (state.KeepRunning())
    {
        for (int i = 0; i < state.range_x(); ++i)
        {
            val = v.insert(val, i);
        }
    }
}
BENCHMARK(BM_Insert)->DenseRange(0, 1024, 128);

static void BM_InitVec(benchmark::State &state)
{
    for (auto _ : state)
    {
        std::vector<int> v(state.range(0), state.range(0));
        benchmark::DoNotOptimize(v.data());
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_InitVec)->DenseRange(0, 1024, 128);

BENCHMARK_MAIN();
