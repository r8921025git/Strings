// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>


using std::default_random_engine;


using std::numeric_limits;
using std::random_device;

using std::uniform_int_distribution;

std::string RandIntString(int len) {
  default_random_engine gen((random_device())());
  std::string ret;
  if (len == 0) {
    return {"0"};
  }
  uniform_int_distribution<int> pos_or_neg(0, 1);
  if (pos_or_neg(gen)) {
    ret.push_back('-');
  }
  uniform_int_distribution<int> num_dis('1', '9');
  ret.push_back(num_dis(gen));
  while (--len) {
    uniform_int_distribution<int> dis('0', '9');
    ret.push_back(dis(gen));
  }
  return ret;
}

// @include
std::string IntToString(int x) {
    const int ori_x = x;
    int m = 10;
    std::vector<char> vec_char;
    bool bIsNegative = false;
    if (x<0) {
        bIsNegative = true;
        x = x*(-1);
    }
    while (1) {
        int s = x % m;
        x = int(x / m);
        vec_char.push_back(s);
        if (x==0) {
            break;
        }
    }
    std::reverse(vec_char.begin(),vec_char.end());
    std::string output = "";
    if (bIsNegative)
        output += '-';
        
    for (char c : vec_char) {
        printf("c=%d\n",c);
        output += '0' + c;
    }
    return output;
}

int StringToInt(const std::string& s) {

}
// @exclude

int main(int argc, char* argv[]) {
  default_random_engine gen((random_device())());

    for (int times = 0; times < 3; ++times) {
      uniform_int_distribution<int> dis(numeric_limits<int>::min(),
                                        numeric_limits<int>::max());
      int x = dis(gen);
      printf("intput x = %d\n", x);
      std::string str = IntToString(x);
      std::cout << x << " " << str << std::endl;
      assert(x == std::stoi(str));
      
      printf("\n\n  Preparing for string-to-int\n\n");
      uniform_int_distribution<int> len_dis(0, 9);
      str = RandIntString(len_dis(gen));
      x = StringToInt(str);
      std::cout << str << " " << x << std::endl;
      assert(x == std::stoi(str));
    }
  
  return 0;
}
