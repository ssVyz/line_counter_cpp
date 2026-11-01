#include <filesystem>
#include <iostream>
#include <vector>

#include "cli.hpp"


void App::load_args(std::vector<std::string> args) {
    if (args.empty()) {
        return;
    }
    for (std::string s : args) {
        if (s == "-v" || s == "--verbose") {
            this->verbose = true;
        } else {
            if (s[0] != ('.')) {
                this->file_ext = "." + s;
            } else {
                this->file_ext = s;
            }
        }
    }
}

void App::dump_contents() {
    std::cout << "Verbose flag set: " << this->verbose << "\n";
    std::cout << "Working directory: " << this->cwd << "\n";
    if (this->file_ext == "missing") {
        return;
    } 
    std::cout << "Recognized file extension: " << this->file_ext << "\n";
}

void dump_path_vec(std::vector<std::filesystem::path> vec) {
    std::cout << "Dumping found files:\n";
    for (std::filesystem::path item : vec) {
        std::cout << item.string() << "\n";
    }
}