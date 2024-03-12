#include <iostream>
#include <sstream>

#define BLANK " "

int main() {
  std::stringstream ss;
  ss << 1 << BLANK;
  ss << 2 << BLANK;
  ss << 3 << BLANK;
  ss << 4 << 5 << 6;
  for(int i=0; i<5; i++) {
    int temp;
    ss >> temp;
    std::cout << temp << std::endl;
  }
  return 0;
}