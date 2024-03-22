#include <cmath>
#include <iostream>
#include <sstream>

class PalindromeProduct {
public:
  unsigned int reverseNum(unsigned int num) {
    unsigned int result = 0;
    unsigned int currentNum = num;
    while(currentNum > 0) {
      result = result * 10 + (currentNum % 10);
      currentNum /= 10;
    }
    return result;
  }
  bool isPalindrome(unsigned int num) {
    unsigned int reversedNum = reverseNum(num);
    return num == reversedNum;
  }
  unsigned int run() {
    unsigned int maxPalindromeProduct = 0;
    unsigned int factor1, factor2, temporaryProduct;
    for(unsigned int i = 999; i >= 400; i--) {
      for(unsigned int j = 999; j >= 400; j--) {
        temporaryProduct = i * j;
        if(isPalindrome(temporaryProduct)) {
          if(temporaryProduct > maxPalindromeProduct) {
            // factor1 = i;
            // factor2 = j;
            maxPalindromeProduct = temporaryProduct;
          }
        }
      }
    }
    return maxPalindromeProduct;
  }
};

int main() {
  std::stringstream ss;
  PalindromeProduct app;

  ss << "The largest palindrome made from the product of two 3-digit numbers is ";
  ss <<  app.run();
  ss << ".";
  ss << std::endl;
  std::cout << ss.str() << std::endl;
  return 0;
}