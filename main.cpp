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
BENCHMARK(BM_Insert)->Range(1, 1 << 4);

BENCHMARK_MAIN();