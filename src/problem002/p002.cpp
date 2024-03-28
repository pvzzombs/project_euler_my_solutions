#include <iostream>
#include <sstream>

class EvenFibonacciNumbers {
public:
  unsigned int run() {
    unsigned int sum = 0, temp;
    unsigned int a = 1, b = 1;
    while(a <= 4000000) {
      if(a % 2 == 0) {
        sum += a;
      }
      temp = a;
      a = a + b;
      b = temp;
    }
    return sum;
  }
};

int main() {
  std::stringstream ss;
  EvenFibonacciNumbers app;
  ss << "The sum of the even-valued terms not exceeding four million is " << app.run() << std::endl;
  std::cout << ss.str() << std::endl;
  return 0;
}