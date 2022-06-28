#include <benchmark/benchmark.h>
#include <vector>
#include <fstream>
using namespace std;
/*
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
*/
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

static void BM_Calc(benchmark::State &state)
{
    double a = 123;
    for (auto _ : state)
    {
        a = (a * a - a) / (a + a);
        benchmark::DoNotOptimize(a);
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_Calc);

static void BM_FileWin(benchmark::State &state)
{
    for (auto _ : state)
    {
        const char *fileName = "C://Users/tlab/scdp/test.txt";

        ofstream ofs(fileName);

        ofs << "abcdefg" << endl;
    }
}
BENCHMARK(BM_FileWin);

static void BM_FileCur(benchmark::State &state)
{
    for (auto _ : state)
    {
        const char *fileName = "../test.txt";

        ofstream ofs(fileName);

        ofs << "abcdefg" << endl;
    }
}
BENCHMARK(BM_FileCur);

BENCHMARK_MAIN();
