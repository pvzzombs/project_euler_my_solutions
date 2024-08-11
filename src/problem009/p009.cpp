#include <iostream>
#include <sstream>
#include <cmath>

class PythagoreanTriplet {
public:
  int run() {
    for (int a = 2; a <= 996; a++) {
      for (int b = a + 1; b <= 996; b++) {
        int c_squared = a * a + b * b;
        int c = std::sqrt(c_squared);
        if (c * c != c_squared) {
          continue;
        } 
        if (a + b + c == 1000) {
          // std::cout << a << " " << b << " " << c << std::endl;
          return a * b * c;
        }
      }
    }
    return -1;
  }
};

int main() {
  std::stringstream ss;
  PythagoreanTriplet app;
  ss << "Product: ";
  ss << app.run();
  std::cout << ss.str() << std::endl;
  return 0;
}