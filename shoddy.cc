#include "shoddy.h"

#include <iostream>
#include <iterator>
#include <sstream>

UserInput Shoddy::get_line(std::string prompt)
{
  std::cout << prompt;

  UserInput user_input;
  user_input.arg_count = 0;

  std::string input;
  if (!std::getline(std::cin, input)) {
    std::cin.clear();
    return user_input;
  }

  user_input.raw_input = input;

  if (std::cin.eof()) {
    user_input.eof = true;
    std::cin.clear();
    return user_input;
  }

  if (std::cin.bad()) {
    std::cin.clear();
    return user_input;
  }

  auto tokens = tokenize(input);

  if (tokens.size() == 0) {
    return user_input;
  }

  user_input.valid = true;
  user_input.arg_count = tokens.size() - 1;
  user_input.command = tokens[0];

  for (std::size_t i = 1; i < tokens.size(); ++i) {
    user_input.args.push_back(tokens[i]);
  }

  return user_input;
}

std::vector<std::string> Shoddy::tokenize(std::string input)
{
  std::stringstream strstr{input};

  std::istream_iterator<std::string> it(strstr);
  std::istream_iterator<std::string> end;
  std::vector<std::string> ret(it, end);

  return ret;
}
