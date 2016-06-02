# Shoddy REPL

This is a basic REPL implemented in C++. `test_repl.cc` shows sample usage:

```cpp
#include <iostream>

#include "shoddy.h"

int main()
{
  Shoddy repl;

  auto input = repl.get_line("> ");

  if (!input.valid) {
    std::cout << "invalid input" << std::endl;
    return 0;
  }

  std::cout << input.command << "[" << input.arg_count << "]";
  for (auto &arg : input.args) {
    std::cout << " " << arg;
  }
  std::cout << std::endl;

  return 0;
}
```
