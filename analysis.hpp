#pragma once
#include <filesystem>
#include <vector>
#include <string>
#include <fstream>

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

Counter_t execute_count(std::vector<std::filesystem::path> vec);

Counter_t count_file(std::filesystem::path f);
