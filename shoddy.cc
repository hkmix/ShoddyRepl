#include "shoddy.h"

#include <iostream>
#include <iterator>
#include <sstream>

UserInput Shoddy::get_line(std::string prompt)
{
  std::cout << prompt;

  std::string input;
  std::getline(std::cin, input);

  UserInput user_input;
  user_input.arg_count = 0;
  user_input.raw_input = input;

  if (std::cin.eof() || std::cin.bad()) {
    user_input.valid = false;
    return user_input;
  }

  auto tokens = tokenize(input);

  if (tokens.size() == 0) {
    user_input.valid = false;
    return user_input;
  }

  user_input.arg_count = tokens.size() - 1;
  user_input.command = tokens[0];
  user_input.valid = true;

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
