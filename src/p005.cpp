#include <iostream>
#include <sstream>

class SmallestMultiple {
public:
  unsigned int lcm(unsigned int a, unsigned int b) {
    unsigned int commonFactors = 1;
    unsigned int result = 1;
    if(a > b) {
      std::swap(a, b);
    }
    if(a == 0) {
      return 0;
    }
    for(unsigned int i = a; i > 1; i--) {
      while((a % i == 0) && (b % i == 0)) {
        commonFactors *= i;
        a /= i;
        b /= i;
      }
    }
    result = commonFactors * a * b;
    return result;
  }
  unsigned int run(unsigned int num) {
    unsigned int currentNumber = 1;
    for(unsigned int i = 2; i <= num; i++) {
      currentNumber = lcm(currentNumber, i);
    }
    return currentNumber;
  }
};

int main() {
  std::stringstream ss;
  SmallestMultiple app;
  ss << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is ";
  ss << app.run(20);
  ss << "." << std::endl;
  std::cout << ss.str() << std::endl;
  return 0;
}