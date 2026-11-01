#include <iostream>
#include <string>
#include <filesystem>

#include "analysis.hpp"




Counter_t add_counts(Counter_t a, Counter_t b) {
    Counter_t new_count = Counter_t{};
    new_count.chars = a.chars + b.chars;
    new_count.lines = a.lines + b.lines;
    new_count.files = a.files + b.files;
    return new_count;

}

//filefinder recursive function
std::vector<std::filesystem::path> find_files(std::filesystem::path cur_dir, std::string file_ext, bool verbose) {
    std::vector<std::filesystem::path> result_vec;
    for (const auto& item : std::filesystem::directory_iterator(cur_dir)) {
        // case its a folder
        if (std::filesystem::is_directory(item)) {
            if (verbose) {std::cout << "Going to directory: " << item.path() << "\n";}
            std::vector<std::filesystem::path> new_vec = find_files(item, file_ext, verbose);
            result_vec.insert(result_vec.end(), new_vec.begin(), new_vec.end());
        }
        // case its a file
        if (std::filesystem::is_regular_file(item)) {
            // std::cout << "Comparing: " << item.path().extension() << " with " << file_ext << "\n";
            if (item.path().extension() == file_ext) {
                result_vec.push_back(item.path());
                if (verbose) {std::cout << "Found file: " << item.path() << " CORRECT type!\n";}
            } else {
                if (verbose) {std::cout << "Found file: " << item.path() << " not right type, ignore!\n";}
            }
        }
    }
    return result_vec;
}
