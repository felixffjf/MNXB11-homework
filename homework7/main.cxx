#include <CLI11/CLI11.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    CLI::App app{"CSV File Reader"};
    std::string input_file;

    app.add_option("-i,--input-file", input_file, "Input CSV file")->required();

    CLI11_PARSE(app, argc, argv);



    return 0;
}
