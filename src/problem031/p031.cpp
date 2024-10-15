#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define INVALID_VALUE 987654321

class CoinSums {
  std::unordered_map<unsigned int, std::unordered_set<unsigned int>> table;
  // std::unordered_map<std::vector<unsigned int>, bool> table2;
  std::unordered_map<std::string, bool> table2;
  std::unordered_map<unsigned int, std::unordered_set<std::string>> table3;
  std::unordered_map<unsigned int, std::unordered_set<std::string>> table4;
  std::unordered_map<unsigned int, std::unordered_set<std::string>> table5;
  std::vector<std::vector<unsigned int>> table6;
  std::vector<unsigned int> tableOptimized;

public:
  std::unordered_set<unsigned int> count(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    if(table.count(amount) > 0) {
      return table.at(amount);
    } else {
      int temp;
      std::unordered_set<unsigned int> newSet;
      std::unordered_set<unsigned int> tempSet;
      for(unsigned int i = 0; i < coinAmounts.size(); i++) {
        temp = amount - coinAmounts.at(i);
        if(temp < 0) { continue; }
        tempSet = count(temp, coinAmounts);
        // newSet.insert(tempSet.begin(), tempSet.end());
        for(auto j = tempSet.begin(); j != tempSet.end(); ++j) {
          newSet.insert((*j) + 1);
        }
      }
      table.insert(std::make_pair(amount, newSet));
      return table.at(amount);
    }
  }
  unsigned int run(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    table.clear();
    table.insert(std::make_pair<unsigned int, std::unordered_set<unsigned int>>(0, {0}));
    table.insert(std::make_pair<unsigned int, std::unordered_set<unsigned int>>(1, {1}));
    count(amount, coinAmounts);
    return table.at(amount).size();
  }
  std::string vectorToString(const std::vector<unsigned int> &arr) {
    std::string temp = "";
    for(unsigned int i = 0; i < arr.size(); i++) {
      temp += std::to_string(arr.at(i));
      temp += ",";
    }
    return temp;
  }
  std::vector<unsigned int> stringToVector(const std::string &str) {
    std::vector<unsigned int> output;
    std::string num = "";
    output.clear();
    for(unsigned int i = 0; i < str.size(); i++) {
      if(str.at(i) >= '0' && str.at(i) <= '9') {
        num += str.at(i);
      } else {
        output.push_back(std::stoul(num));
        num = "";
      }
    }
    if(num.size() > 0) {
      output.push_back(std::stoul(num));
    }
    return output;
  }
  void count2(unsigned int amount, const std::vector<unsigned int> &coinAmounts, std::vector<unsigned int> &arr) {
    int temp;
    if(amount == 0) {
      std::string str;
      std::vector<unsigned int> newArr = arr;
      std::sort(newArr.begin(), newArr.end());
      str = vectorToString(newArr);
      if(table2.count(str) == 0) {
        table2.insert(std::make_pair(str, true));
      }
      return;
    }
    for(unsigned int i = 0; i < coinAmounts.size(); i++) {
      temp = amount - coinAmounts.at(i);
      if(temp < 0) { continue; }
      arr.push_back(coinAmounts.at(i));
      count2(temp, coinAmounts, arr);
      arr.pop_back();
    }
  }
  unsigned int run2(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    std::vector<unsigned int> combos;
    table2.clear();
    combos.clear();
    count2(amount, coinAmounts, combos);
    return table2.size();
  }
  void count3(unsigned int startAmount, unsigned int targetAmount, const std::vector<unsigned int> &coinAmounts, std::vector<unsigned int> &arr) {
    unsigned int temp;
    std::string newStr;
    std::vector<unsigned int> newArr;

    newArr = arr;
    std::sort(newArr.begin(), newArr.end());
    newStr = vectorToString(newArr);
    if(table3.count(startAmount) > 0) {
      table3[startAmount].insert(newStr);
    }
    if(startAmount == targetAmount) {
      table3[startAmount].insert(newStr);
      return;
    }
    for(unsigned int i = 0; i < coinAmounts.size(); i++) {
      temp = startAmount + coinAmounts.at(i);
      if(temp > targetAmount) { continue; }
      arr.push_back(coinAmounts.at(i));
      newArr = arr;
      std::sort(newArr.begin(), newArr.end());
      newStr = vectorToString(newArr);
      if(table3.count(temp) > 0) {
        table3.at(temp).insert(newStr);
      } else { 
        table3[temp] = { newStr };
      }
      count3(temp, targetAmount, coinAmounts, arr);
      arr.pop_back();
    }
  }
  unsigned int run3(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    std::vector<unsigned int> combos;
    table3.clear();
    combos.clear();
    count3(0, amount, coinAmounts, combos);
    return table3.at(amount).size();
  }
  std::unordered_set<std::string>* count4(unsigned int amount, unsigned int targetAmount, const std::vector<unsigned int> &coinAmounts) {
    if(amount == targetAmount) {
      return &(table4.at(targetAmount));
    }
    if(table4.count(amount) > 0) {
      return &(table4.at(amount));
    } else {
      unsigned int temp;
      std::unordered_set<std::string> *tempSet = nullptr;
      std::unordered_set<std::string> newSet;
      std::string tempStr;
      std::vector<unsigned int> tempVec;
      for(auto &e: coinAmounts) {
        temp = e + amount;
        if(temp > targetAmount) { continue; }
        tempSet = count4(temp, targetAmount, coinAmounts);
        if(tempSet->empty()) {
          tempStr = std::to_string(e);
          tempStr += ",";
          newSet.insert(tempStr);
        } else {
          for(auto &i: *tempSet) {
            tempVec = stringToVector(i);
            tempVec.push_back(e);
            std::sort(tempVec.begin(), tempVec.end());
            tempStr = vectorToString(tempVec);
            newSet.insert(tempStr);
          }
        }
      }
      table4.insert(std::make_pair(amount, newSet));
      return &(table4.at(amount));
    }
  }
  unsigned int run4(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    table4.clear();
    table4.reserve(amount + 1);
    table4[amount] = {};
    count4(0, amount, coinAmounts);
    return table4.at(0).size();
  }
  unsigned int parseString(const std::string &str, unsigned int index) {
    unsigned int num = 0;
    unsigned int i = 0;
    for(auto &c: str) {
      if(c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      } else {
        if(i == index) {
          return num;
        }
        num = 0;
      }
    }
    return num;
  }
  std::unordered_set<std::string> count5(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    /* ----- Incomplete ----- */
    if(table5.count(amount) > 0) {
      return table5.at(amount);
    } else {
      int temp;
      std::unordered_set<std::string> newSet;
      std::unordered_set<std::string> tempSet;
      std::string tempStr;
      unsigned int totalCount, startCount;
      for(unsigned int i = 0; i < coinAmounts.size(); i++) {
        temp = amount - coinAmounts.at(i);
        if(temp < 0) { continue; }
        tempSet = count5(temp, coinAmounts);
        // newSet.insert(tempSet.begin(), tempSet.end());
        for(auto j = tempSet.begin(); j != tempSet.end(); ++j) {
          tempStr = *j;
          totalCount = parseString(tempStr, 0);
          startCount = parseString(tempStr, 1);
          // newSet.insert((*j) + 1);
        }
      }
      table5.insert(std::make_pair(amount, newSet));
      return table5.at(amount);
    }
  }
  unsigned int run5(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    /* ----- Incomplete ----- */
    table5.clear();
    table5.insert(std::make_pair<unsigned int, std::unordered_set<std::string>>(0, {"0,0"}));
    table5.insert(std::make_pair<unsigned int, std::unordered_set<std::string>>(1, {"1,1"}));
    count(amount, coinAmounts);
    return table.at(amount).size();
  }
  void decompose(std::vector<unsigned int> &arr, unsigned int num, unsigned int start, const std::vector<unsigned int> &coinAmounts) {
    unsigned int temp;
    arr.clear();
    for(unsigned int i = start; i < coinAmounts.size(); i++) {
      temp = coinAmounts.at(i);
      while(num >= temp) {
        arr.push_back(temp);
        num -= temp;
      }
    }
  }
  void decomposeIgnore(std::vector<unsigned int> &arr, unsigned int num, unsigned int ignore, const std::vector<unsigned int> &coinAmounts) {
    unsigned int ptr, temp;
    arr.clear();
    for(unsigned int i = 0; i < coinAmounts.size(); i++) {
      if(ignore > coinAmounts.at(i)) {
        ptr = i;
        break;
      }
    }
    for(; ptr < coinAmounts.size(); ptr++) {
      temp = coinAmounts.at(ptr);
      while(num >= temp) {
        arr.push_back(temp);
        num -= temp;
      }
    }
  }
  void count6(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    unsigned int len = coinAmounts.size();
    unsigned int last = coinAmounts.back();
    unsigned int startIndex;
    unsigned int ptr, hsum;
    std::vector<unsigned int> arr, as, am;
    for(unsigned int i = 0; i < len; i++) {
      if(amount >= coinAmounts.at(i)) {
        startIndex = i;
        break;
      }
    }
    for(unsigned int i = startIndex; i < len; i++) {
      decompose(arr, amount, i, coinAmounts);
      table6.push_back(arr);
      ptr = arr.size() - 1;
      hsum = 0;
      while(ptr > 0) {
        if(arr.at(ptr) == last) {
          hsum += 1;
          ptr -= 1;
        } else {
          as.clear();
          for(unsigned int temp = 0; temp < ptr; temp++) {
            as.push_back(arr.at(temp));
          }
          decomposeIgnore(am, arr.at(ptr) + hsum, arr.at(ptr), coinAmounts);
          arr.clear();
          for(auto &e: as) {
            arr.push_back(e);
          }
          for(auto &e: am) {
            arr.push_back(e);
          }
          ptr = arr.size() - 1;
          hsum = 0;
          table6.push_back(arr);
        }
      }
    }
  }
  unsigned int run6(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    table6.clear();
    count6(amount, coinAmounts);
    return table6.size();
  }
  void countOptimized(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    int temp;
    for(auto &c: coinAmounts) {
      for(unsigned int i = 0; i <= amount; i++) {
        temp = i - c;
        if(temp >= 0) {
          tableOptimized.at(i) += tableOptimized.at(temp);
        }
      }
    }
  }
  unsigned int runOptimized(unsigned int amount, const std::vector<unsigned int> &coinAmounts) {
    std::vector<unsigned int> denom = coinAmounts;
    tableOptimized.resize(amount + 1);
    for(auto &e: tableOptimized) {
      e = 0;
    }
    tableOptimized.at(0) = 1;
    std::sort(denom.begin(), denom.end());
    countOptimized(amount, denom);
    return tableOptimized.back();
  }
};

int main() {
  CoinSums app;
  std::stringstream ss;
  unsigned int coinPenceAmount = 200;
  std::vector<unsigned int> coinAmounts = {200, 100, 50, 20, 10, 5, 2, 1};
  ss << "There are ";
  // ss << app.run6(coinPenceAmount, coinAmounts);
  ss << app.runOptimized(coinPenceAmount, coinAmounts);
  ss << " different ways ";
  ss << coinPenceAmount;
  ss << "p can be made using any number of coins.";
  std::cout << ss.str() << std::endl;
  return 0;
}