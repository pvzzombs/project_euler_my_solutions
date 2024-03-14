#include <iostream>
#include <sstream>

class Multiples3or5 {
public:
  unsigned int run() {
    unsigned int sum = 0;
    for(unsigned int i = 1; i < 1000; i++) {
      if(i % 3 == 0 || i % 5 == 0) {
        sum = sum + i;
      }
    }
    return sum;
  }
};

int main() {
  std::stringstream ss;
  Multiples3or5 app;
  ss << "The sum of all the multiples of 3 or 5 below 1000 is " << app.run() << std::endl;
  std::cout << ss.str() << std::endl;
  return 0;
}