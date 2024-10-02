#include <iostream>
#include <string>
#include <cstdlib>

int computeAsciiSum(const std::string& first_argument) {
    int ascii_sum_of_first_arg = 0;

    for (char c : first_argument) {
        ascii_sum_of_first_arg += c;
    }
    
    return ascii_sum_of_first_arg;
}

int main(int nr_of_args, char *args[]) {
    bool has_3_arguments = (nr_of_args == 3);

    if (has_3_arguments) {
        std::string program_name{args[0]};
        char first_char_of_first_arg{*(args[1])};
        std::size_t program_name_length{program_name.size()};
        int expected_value{std::atoi(args[2])};

        std::string first_argument{args[1]};
        int ascii_sum_of_first_arg = computeAsciiSum(first_argument);

        if ((ascii_sum_of_first_arg ^ first_char_of_first_arg * 3) << (program_name_length & 0x1f) == expected_value) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong!" << std::endl;
        }
    } else {
        std::cout << "Usage: " << args[0] << " <first_argument> <expected_value>" << std::endl;
    }

    return 0;
}

