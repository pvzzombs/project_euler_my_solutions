#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>

class NumberSpiralDiagonals {
  enum PathDirection {goUp, goDown, goLeft, goRight};
  std::vector<std::vector<unsigned int>> square;
  unsigned int middle;

public:
  void calculateSpiral() {
    unsigned int topLimit = middle;
    unsigned int downLimit = middle;
    unsigned int leftLimit = middle;
    unsigned int rightLimit = middle;
    unsigned int currentNum = 1;
    unsigned int currentRow = middle;
    unsigned int currentCol = middle;

    // unsigned int newSquareCount = 1;
    // unsigned int oldSquareCount = 0;
    // unsigned int squareCount = 1;
    unsigned int squareCount = 0;

    PathDirection direction;

    square.at(currentRow).at(currentCol) = currentNum++;
    for(unsigned int i = 0; i < middle; i++) {
      topLimit--;
      downLimit++;
      leftLimit--;
      rightLimit++;

      currentCol++;

      // oldSquareCount = newSquareCount;
      // newSquareCount = newSquareCount + 2;
      // squareCount = (newSquareCount * newSquareCount) - (oldSquareCount * oldSquareCount);
      squareCount += 8;
      direction = goDown;
      for(unsigned int j = 0; j < squareCount; j++) {
        // down, left, up, right
        square.at(currentRow).at(currentCol) = currentNum;
        currentNum++;
        switch(direction) {
          case goDown:
            if(currentRow < downLimit) {
              currentRow++;
            } else {
              direction = goLeft;
              currentCol--;
            }
            break;
          case goLeft:
            if(currentCol > leftLimit) {
              currentCol--;
            } else {
              direction = goUp;
              currentRow--;
            }
            break;
          case goUp:
            if(currentRow > topLimit) {
              currentRow--;
            } else {
              direction = goRight;
              currentCol++;
            }
            break;
          case goRight:
            if(currentCol < rightLimit) {
              currentCol++;
            }
            break;
        }
      }
    }
  }
  unsigned int run(unsigned int sideLength) {
    unsigned int runningSum;
    unsigned int currentCol;
    unsigned int currentRow;
    unsigned int anotherCol;
    square.resize(sideLength);
    for(auto &a: square) {
      a.resize(sideLength);
    }
    middle = sideLength / 2;
    runningSum = 0;
    currentCol = currentRow = 0;
    anotherCol = square.size() - 1;
    calculateSpiral();
    // for(auto &a: square) {
    //   for(auto &i: a) {
    //     std::cout << std::setfill('0') << std::setw(7) << i << " ";
    //   }
    //   std::cout << std::endl;
    // }
    while(currentRow < square.size()) {
      runningSum += square.at(currentRow).at(currentCol);
      runningSum += square.at(currentRow).at(anotherCol);
      currentRow++;
      currentCol++;
      anotherCol--;
    }
    return runningSum - 1;
  }
  unsigned int runOptimized(unsigned int sideLength) {
    // assume sideLength is odd
    unsigned int newSideLength = sideLength - 1;
    unsigned int runningSum = 0;
    unsigned int currentNum = 1;
    runningSum += currentNum;
    for(unsigned int i = 2; i <= newSideLength; i += 2) {
      for(unsigned int j = 0; j < 4; j++) {
        currentNum += i;
        runningSum += currentNum;
      }
    }
    return runningSum;
  }
};

int main() {
  NumberSpiralDiagonals app;
  std::stringstream ss;
  unsigned int sideLength = 1001;
  ss << "The sum of the numbers on the diagonals in a ";
  ss << sideLength;
  ss << " by " ;
  ss << sideLength;
  ss << " spiral is ";
  // ss << app.run(sideLength) << std::endl;
  ss << app.runOptimized(sideLength) << std::endl;
  std::cout << ss.str() << std::endl;
  return 0;
}