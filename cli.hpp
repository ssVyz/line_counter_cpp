#pragma once
#include <iostream>
#include <filesystem>
#include <vector>


struct App {
    bool verbose = false;
    std::filesystem::path cwd = std::filesystem::current_path();

    void load_args(std::vector<std::string> args);
    void dump_contents();
};