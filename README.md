## count_lines

Hand-written C++ line counter for projects and repos

Provide a file extension and run from a project root.

The program crawls every folder and collects files with that file extension.

It then counts lines and chars and presents a report.

### How to build

Tested with gcc:

> g++ main.cpp cli.cpp analysis.cpp -o bin/count_lines

Put bin on your path to use the tool.
(this will be improved later)

### usage

In your project root directory:

>count_lines .EXT

E.g. if python project:

>count_lines .py

If you want to see the internals, append "-v" or "--verbose"

Only one file extension can be counted at a time.
