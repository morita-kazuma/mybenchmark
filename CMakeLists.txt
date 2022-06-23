cmake_minimum_required(VERSION 3.1)
project(myproject CXX)

add_subdirectory(benchmark)
add_executable(mybenchmark main.cpp)
target_compile_options(mybenchmark PUBLIC -O2)
target_compile_features(mybenchmark PUBLIC cxx_std_17)
target_link_libraries(mybenchmark benchmark::benchmark)