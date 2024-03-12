#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

class CollatzSequence {
  int numberOfRunCalls;
  std::unordered_map<unsigned int, unsigned int> store;
public:
  void init(int n) {
    store.reserve(n * 2);
  }
  void reset() {
    numberOfRunCalls = 0;
  }
  void resetStore() {
    store.clear();
    store[1] = 1;
  }
  int run(unsigned int n) {
    ++numberOfRunCalls;
    int newN;
    if(n == 1) {
      return 1;
    }
    newN = (n % 2) ? (3 * n + 1) : (n / 2);
    return 1 + run(newN);
  }
  int runOptimized(unsigned int n) {
    // std::cout << n << std::endl;
    ++numberOfRunCalls;
    unsigned int newN, result = 0;
    if(n == 1) {
      return 1;
    }

    if(store.count(n) > 0) {
      result = store.at(n);
    } else {
      //newN = (n % 2) ? (3 * n + 1) : (n / 2);
      if(n % 2 > 0) {
        newN = 3 * n + 1;
      } else {
        newN = n / 2;
      }
      // if(newN <= 0) {
      //   std::cout << "n is " << n << std::endl;
      //   std::exit(1);
      // }
      result = 1 + runOptimized(newN);
      store[n] = result;
    }

    // if(n < 0) {
    //   std::cout << "n: " << n << std::endl;
    // }
    // if(newN < 0) {
    //   std::cout << "newN: " << newN << std::endl;
    // }
    
    return result;
  }
  int countCalls() {
    return numberOfRunCalls;
  }
};

int main() {
  CollatzSequence app;
  unsigned int testCases;
  unsigned int startNum;
  std::stringstream ss;

  unsigned int index = 0, maxtermsCount = 0, currentTermsCount = 0;

  app.resetStore();
  // std::cin >> testCases;
  testCases = 1000000;
  // app.init(testCases);
  for(unsigned int i=1; i<=testCases; i++) {
    // std::cin >> startNum;
    startNum = i;
    // std::cout << startNum << std::endl;
    app.reset();
    currentTermsCount = app.runOptimized(startNum);

    if(currentTermsCount > maxtermsCount) {
      maxtermsCount = currentTermsCount;
      index = startNum;
    }

    // ss << "Testcase ";
    // ss << i;
    // ss << ": ";
    // ss << startNum;
    // ss << ": ";
    // //ss << app.run(startNum);
    // ss << currentTermsCount;
    // ss << std::endl;

    // ss << "Number of calls: ";
    // ss << app.countCalls();
    // ss << std::endl;
  }
  ss << "The number that produced the longest chain is " << index << " with " << maxtermsCount << " terms.";
  std::cout << ss.str() << std::endl;
  // std::cout << app.runOptimized(113383) << std::endl;
  return 0;
}