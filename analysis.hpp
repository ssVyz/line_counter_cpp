#pragma once
#include <filesystem>
#include <vector>

#include "cli.hpp"


// types 
struct Counter_t {
    int chars;
    int lines;
    int files;
};

// functions
Counter_t add_counts(Counter_t a, Counter_t b);

std::vector<std::filesystem::path> find_files(std::filesystem::path cur_dir, std::string file_ext, bool verbose);


