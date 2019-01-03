project(bm)

cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "disable dependency on googletest")
add_subdirectory(benchmark)
add_subdirectory(src)
