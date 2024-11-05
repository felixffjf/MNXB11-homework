#include <fast/cpp/csv.h>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    CLI::App app{"CSV File Reader"};
    std::string input_file;

    app.add_option("-i,--input-file", input_file, "Input CSV file")->required();

    CLI11_PARSE(app, argc, argv);

    // Read and parse the CSV file
    fastcsv::CsvParser parser(input_file);
    while (parser.has_next()) {
        const fastcsv::CsvRow& row = parser.get_next_row();
        for (const auto& col : row) {
            std::cout << col << " "; // Output each column
        }
        std::cout << std::endl;
    }

    return 0;
}