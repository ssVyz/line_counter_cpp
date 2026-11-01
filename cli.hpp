#pragma once
#include <iostream>
#include <filesystem>
#include <vector>


struct App {
    bool verbose = false;
    std::string file_ext = "missing";

    std::filesystem::path cwd = std::filesystem::current_path();

    void load_args(std::vector<std::string> args);
    void dump_contents();
};

void dump_path_vec(std::vector<std::filesystem::path> vec);