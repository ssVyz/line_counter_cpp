#include <iostream>
#include <string>
#include <vector>

#include "cli.hpp"


int main(int argc, char *argv[]) {
    // set up the app instance
    App app = App{};

    // transfer args into a vector
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        std::string s = argv[i];
        args.push_back(s);
    }

    //run load_args
    app.load_args(args);

    app.dump_contents();


    /*
    std::cout << "Number of args is " << argc  << "\n";

    for (int i = 0; i < argc; i++) {

        std::cout << argv[i] << "\n";

    }

    */

    return 0;
}