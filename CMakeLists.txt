
cmake_minimum_required(VERSION 3.16)

project(line_counter_cpp LANGUAGES CXX)

add_executable(count_lines
    main.cpp
    cli.cpp
    analysis.cpp
)

target_compile_features(count_lines PRIVATE cxx_std_17)