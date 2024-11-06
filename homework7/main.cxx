#include <fast/cpp/csv.h>
#include <iostream>
#include <string>
#include <vector>
#include <date/date.h>

int main(int argc, char** argv) {
    CLI::App app{"CSV File Reader with Date Support"};
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

    // Ex: using the date library
    using namespace date;
    using namespace std::chrono;
    auto today = floor<days>(system_clock::now());
    std::cout << "Today's date is: " << today << std::endl;

    return 0;
}