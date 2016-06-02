#ifndef __SHODDY_H
#define __SHODDY_H

#include <cstddef>
#include <string>
#include <vector>

struct UserInput
{
  bool valid;
  std::string command;
  std::vector<std::string> args;
  std::size_t arg_count;
};

class Shoddy
{
public:
  UserInput get_line(std::string prompt = "");

private:
  std::vector<std::string> tokenize(std::string);
};

#endif
