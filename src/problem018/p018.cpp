#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

#define INVALID_VALUE 0

class PathSum1 {
  unsigned int lastRowIndex;
  unsigned int lastColIndex;
  unsigned int maxSum;
  unsigned int moveCalls;
  unsigned int bottomCalls;
public:
  void move(unsigned int row, unsigned int col, unsigned int previousSum, std::vector<std::vector<unsigned int>> &input) {
    moveCalls++;
    // base case
    if(row == lastRowIndex) {
      bottomCalls++;
      if(previousSum > maxSum) {
        maxSum = previousSum;
      }
    } else {
      move(row + 1, col, previousSum + input.at(row + 1).at(col), input);
      move(row + 1, col + 1, previousSum + input.at(row + 1).at(col + 1), input);
    }
  }
  unsigned int run(std::vector<std::vector<unsigned int>> &input) {
    lastRowIndex = input.size() - 1;
    lastColIndex = input.at(lastRowIndex).size() - 1;
    maxSum = 0;
    moveCalls = 0;
    bottomCalls = 0;
    move(0, 0, input.at(0).at(0), input);
    // std::cout << "Bottom calls: " << bottomCalls << std::endl;
    // std::cout << "Total calls: " << moveCalls << std::endl;
    return maxSum;
  }
  unsigned int moveOptimized(unsigned int row, unsigned int col, std::vector<std::vector<unsigned int>> &input,
  std::vector<std::vector<unsigned int>> &dp) {
    moveCalls++;
    // base case
    if(row == lastRowIndex) {
      bottomCalls++;
      dp.at(row).at(col) = input.at(row).at(col);
      return input.at(row).at(col);
    }
    if(dp.at(row).at(col) != INVALID_VALUE) {
      return dp.at(row).at(col);
    } else {
      unsigned int left = moveOptimized(row + 1, col, input, dp);
      unsigned int right = moveOptimized(row + 1, col + 1, input, dp);
      dp.at(row).at(col) = input.at(row).at(col) + std::max(left, right);
      return dp.at(row).at(col);
    }
  }
  unsigned int runOptimized(std::vector<std::vector<unsigned int>> &input) {
    std::vector<std::vector<unsigned int>> dp;
    unsigned int result;
    lastRowIndex = input.size() - 1;
    lastColIndex = input.at(lastRowIndex).size() - 1;
    moveCalls = 0;
    bottomCalls = 0;
    dp.resize(input.size());
    for(unsigned int i = 0; i < input.size(); i++) {
      dp.at(i).resize(input.at(i).size());
      for(unsigned int j = 0; j < input.at(i).size(); j++) {
        dp.at(i).at(j) = INVALID_VALUE;
      }
    }
    result = moveOptimized(0, 0, input, dp);
    // std::cout << "[Optimized] Bottom calls: " << bottomCalls << std::endl;
    // std::cout << "[Optimized] Total calls: " << moveCalls << std::endl;
    return result;
  }
};

int main() {
  PathSum1 app;
  std::stringstream ss;
  std::ifstream input018;

  std::vector<std::vector<unsigned int>> input;
  unsigned int testCases;
  unsigned int rowsCount;

  // let's try to open the input file
  input018.open("input018.txt");

  if(!input018.is_open()) {
    throw;
  }
  // std::cin >> testCases;
  // testCases = 1;
  input018 >> testCases;
  for(unsigned int i = 1; i <= testCases; i++) {
    // std::cin >> rowsCount;
    // rowsCount = 4;
    input018 >> rowsCount;
    input.clear();
    input.resize(rowsCount);
    for(unsigned int r = 1; r <= rowsCount; r++) {
      input.at(r - 1).resize(r);
      for(unsigned int c = 1; c <= r; c++) {
        // std::cin >> input.at(r - 1).at(c - 1);
        input018 >> input.at(r - 1).at(c - 1);
      }
    }
    // input = {
    //   {3},
    //   {7, 4},
    //   {2, 4, 6},
    //   {8, 5, 9, 3}
    // };
    
    // ss << app.run(input);
    // ss << std::endl;
    ss << "The maximum total from top to bottom of the triangle #";
    ss << i;
    ss << " is ";
    ss << app.runOptimized(input);
    ss << ".";
    ss << std::endl;
    // for(auto &a: input) {
    //   for(auto &e: a) {
    //     std::cout << e << ", ";
    //   }
    //   std::cout << std::endl;
    // }
  }
  input018.close();
  std::cout << ss.str() << std::endl;
  return 0;
}