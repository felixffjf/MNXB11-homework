#include <iostream>
#include <string>
#include <cstdlib>

int computeChecksum(const std::string& first_argument) {
    int checksum_of_first_arg = 0;

    for (char c : first_argument) {
        checksum_of_first_arg += c;
    }
    
    return checksum_of_first_arg;
}

int calculateKey(int checksum, char first_char, std::size_t length) {
    return (checksum ^ (first_char * 3)) << (length & 0x1f);
}

int main(int nr_of_args, char *args[]) {
    bool has_3_arguments = (nr_of_args == 3);

    if (has_3_arguments) {
        std::string program_name{args[0]};
        char first_char_of_first_arg{*(args[1])};
        std::size_t program_name_length{program_name.size()};
        int expected_value{std::atoi(args[2])};

        std::string first_argument{args[1]};
        int checksum_of_first_arg = computeChecksum(first_argument);

        int key = calculateKey(checksum_of_first_arg, first_char_of_first_arg, program_name_length);
        std::cout << "The checksum key is: " << key << std::endl;

        std::cout << "The expected key is: " << expected_value << std::endl;

        std::cout << "The checksum of the first argument is: " << checksum_of_first_arg << std::endl;
        




        if (key == expected_value) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong!" << std::endl;
        }
    } else {
        std::cout << "Invalid input" << std::endl;
        std::cout << "Usage" << args[0] << " <first_argument> <some_integer>" << std::endl;
        return 1;
    }
    

    
}

