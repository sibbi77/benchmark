# Auto generate moc files
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Threads REQUIRED)


add_executable(bm1 main.cpp)
target_include_directories(bm1 PUBLIC ../benchmark/include)
target_compile_options(bm1 PUBLIC "-pthread")
target_link_libraries(bm1
    Threads::Threads
    Qt5::Core
    benchmark
)
