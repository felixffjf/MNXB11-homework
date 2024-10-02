#include <iostream>
#include <string>
int main(int nr_of_args, char *args[]) {

  bool has_3_arguments = (nr_of_args == 3);

  if (has_3_arguments) {
    std::string program_name{args[0]};
    char first_char_of_first_arg{*(args[1])};
    std:size_t program_name_length{program_name.size()};
    int expected_value{std::atoi(args[2])};
    int ascii_sum_of_first_arg = 0;
    int char_index = 0;
    std::string first_argument{args[1]};
    while (true) {
      ascii_sum_of_first_arg += first_argument[char_index++];
      if (char_index >= static_cast<int>(first_argument.size())) {
        break;
      }
    }
    if ((ascii_sum_of_first_arg ^ first_char_of_first_arg * 3) << (program_name_length & 0x1f) == expected_value) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
