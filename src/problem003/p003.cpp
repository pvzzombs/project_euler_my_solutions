#include <iostream>
#include <sstream>
#include <vector>

class LargestPrimeFactor {
  std::vector<unsigned long long> primeFactors;
public:
  unsigned long long run(unsigned long long num) {
    // We will assume that num > 1
    primeFactors.clear();
    for(unsigned long long i = 2; i <= num; i++) {
      while(num % i == 0) {
        primeFactors.push_back(i);
        num /= i;
      }
    }
    // does not matter if num is prime or composite
    return primeFactors.back();
  }
};

int main() {
  LargestPrimeFactor app;
  std::stringstream ss;
  unsigned int testCases;
  unsigned long long num;
  unsigned long long result;

  // std::cin >> testCases;
  testCases = 1;
  for(unsigned int i = 1; i <= testCases; i++) {
    // std::cin >> num;
    num = 600851475143ULL;
    result = app.run(num);
    ss << "The largest prime factor of the number ";
    ss << num;
    ss << " is ";
    ss << result;
    ss << ".";
    ss << std::endl;
  }
  std::cout << ss.str() << std::endl;
  return 0;
}