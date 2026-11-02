#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

#include "analysis.hpp"



// counter addition helper
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
    if (file_ext == "missing") {
        std::cout << "No file extension provided or file extension parsing failed\n";
        return result_vec;
    }
    for (const auto& item : std::filesystem::directory_iterator(cur_dir)) {
        // case its a folder
        if (std::filesystem::is_directory(item)) {
            //if (item.path().string().find(".git") == std::string::npos) {continue;}
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

// this walks the found files vector
Counter_t execute_count(std::vector<std::filesystem::path> vec) {
    Counter_t main_count{0, 0, 0};
    for (std::filesystem::path file : vec) {
        Counter_t new_count = add_counts(main_count, count_file(file));
        main_count = new_count;
    }
    return main_count;
}

// this processes a single file
Counter_t count_file(std::filesystem::path f) {
    Counter_t file_count{0, 0, 0};
    std::ifstream file(f);
    if (!file.is_open()) {
        std::cerr << "could not open file: " << f.string();
        return file_count;
    }

    int char_counter = 0;
    char c;
    while (file.get(c)) {
        char_counter++;
    }
    file_count.chars = char_counter;

    // reset stream 
    file.clear();
    file.seekg(0, std::ios::beg);

    int line_counter = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.length() > 1) {
            line_counter++;
        }
    }
    file_count.lines = line_counter;

    file_count.files = 1;

    return file_count;
}

