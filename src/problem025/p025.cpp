#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <mini-gmp.h>

class FibonacciNumber {
public:
  unsigned long long run() {
    // int a = 1, b = 1, temp;
    // int index = 1;
    mpz_t a;
    mpz_t b;
    mpz_t temp;
    // for(int i = 0; i < 10; i++) {
    //   std::cout << index << ": "<< a << std::endl;
    //   temp = a + b;
    //   a = b;
    //   b = temp;
    //   index++;
    // }
    unsigned long long index = 1;
    // char result[1001]; // 1000 digits + extra null character
    mpz_init_set_ui(a, 1);
    mpz_init_set_ui(b, 1);
    mpz_init_set_ui(temp, 0);

    while(mpz_sizeinbase(a, 10) < 1000) {
      mpz_add(temp, a, b);
      mpz_set(a, b);
      mpz_set(b, temp);
      index++;
    }
    // mpz_out_str(stdout, 10, a);
    // std::cout << "The value is " << mpz_get_str(result, 10, a) << std::endl;

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(temp);
    return index;
  }
};

int main() {
  FibonacciNumber app;
  std::stringstream ss;
  ss << "The index of the first term in the Fibonacci sequence to contain 1000 digits is ";
  ss << app.run();
  ss << ".";
  std::cout << ss.str() << std::endl;
  return 0;
}