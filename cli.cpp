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
        }
    }

}

void App::dump_contents() {
    std::cout << "Verbose flag set: " << this->verbose << "\n";
    std::cout << "Working directory: " << this->cwd << "\n";
}