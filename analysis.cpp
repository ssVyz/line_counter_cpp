#include <iostream>
#include <string>
#include <filesystem>

#include "analysis.hpp"




Counter_t add_counts(Counter_t a, Counter_t b) {
    Count_t new_count = Counter_t{};
    new_count.chars = a.chars + b.chars;
    new_count.lines = a.lines + b.lines;
    new_count.files = a.files + b.files;
    return new_count;

}


std::vector<std::filesystem::path> find_files(std::filesystem::path cur_dir, std::string file_ext, bool verbose) {
    std::vector<std::filesystem::path> result_vec;
    for (const auto% item : std::filesystem::directory_iterator(cur_dir)) {
        if (std::filesystem::is_directory(item)) {
            if (verbose) {std::cout << "Going to directory: " << item.path();}
            result_vec.append_range(find_files(cur_dir, file_ext, verbose))
        }
    }


    return result_vec;
}
