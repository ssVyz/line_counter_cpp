#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "cli.hpp"
#include "analysis.hpp"


void dump_counter(Counter_t c) {
    std::cout << "Dumping counter: \n" << "Chars: " << c.chars << "\nLines: " << c.lines << "\nfiles: " << c.files << "\n";
}

void pretty_result(const Counter_t& c, const App& app) {
    std::cout << "Found " << c.files << " files with the extension " << app.file_ext << " in this directory tree.\n";
    std::cout << "Lines of code: " << c.lines << "\nChars (bytes): " << c.chars << "\n";
}


int main(int argc, char *argv[]) {
    // set up the app instance
    App app = App{};

    // transfer args into a vector
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        std::string s = argv[i];
        args.push_back(s);
    }

    // run load_args
    app.load_args(args);
    if (app.verbose) {app.dump_contents();}

    // run analysis
    auto files = find_files(std::filesystem::current_path(), app.file_ext, app.verbose);
    if (app.verbose) {dump_path_vec(files);}
    auto result_c = execute_count(files);

    //dump_counter(result_c);

    pretty_result(result_c, app);

    return 0;
}