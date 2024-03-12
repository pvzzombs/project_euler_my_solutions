#include <iostream>
#include <sstream>
#include <vector>

#define INVALID_VALUE 0

class LatticePaths {
  unsigned int totalRoutes;
  unsigned int lastIndex;
  std::vector<std::vector<unsigned long long>> grid;
public:
  void move(unsigned int row, unsigned int col) {
    if(row == lastIndex && col == lastIndex) {
      totalRoutes++;
    }
    if(row > lastIndex || col > lastIndex) {
      return;
    }
    move(row + 1, col);
    move(row, col + 1);
  }
  int run(unsigned int n) {
    lastIndex = n;
    totalRoutes = 0;
    move(0, 0);
    return totalRoutes;
  }
  unsigned long long moveOptimized(unsigned int row, unsigned int col) {
    unsigned long long result = 0;
    unsigned long long right = 0;
    unsigned long long down = 0;
    if(row > lastIndex || col > lastIndex) {
      return INVALID_VALUE;
    }

    if(grid.at(row).at(col) != INVALID_VALUE) {
      result = grid.at(row).at(col);
    } else {
      down = moveOptimized(row + 1, col);
      right = moveOptimized(row, col + 1);
      if(down != INVALID_VALUE) {
        result += down;
      }
      if(right != INVALID_VALUE) {
        result += right;
      }
      grid.at(row).at(col) = result;
    }
    return result;
  }
  unsigned long long runOptimized(unsigned int n) {
    lastIndex = n;
    grid.clear();
    grid.resize(n + 1);
    for(auto &v: grid) {
      v.resize(n + 1);
      for(auto &e: v) {
        e = INVALID_VALUE;
      }
    }
    grid.at(lastIndex).at(lastIndex) = 1;
    return moveOptimized(0, 0);
  }
};

int main() {
  LatticePaths app;
  unsigned int testCases;
  unsigned int gridSize;
  std::stringstream ss;

  // std::cin >> testCases;
  testCases = 1;
  for(int i=1; i<=testCases; i++) {
    // std::cin >> gridSize;
    gridSize = 20;
    ss << "Testcase #";
    ss << i;
    ss << ", Grid size: ";
    ss << gridSize;
    ss << ", Total routes: ";
    // ss << app.run(gridSize);
    ss << app.runOptimized(gridSize);
    ss << std::endl;
  }
  std::cout << ss.str() << std::endl;
  return 0;
}