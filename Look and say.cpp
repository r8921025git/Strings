// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <sstream>
#include <string>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::stoi;
using std::string;
using std::stringstream;
using std::to_string;
using std::uniform_int_distribution;



string LookAndSay(int n) {
    if (n==0) {
        return "";
    }
    if (n==1) {
        return "1";
    }
    if (n==2) {
        return "11";
    }
    string prev_res =LookAndSay(n-1);
    string new_res = "";
    
    int count = 1;
    for (int i=1; i<prev_res.size(); ++i) {
        char c = prev_res[i];
        char d = prev_res[i-1];
        if (c==d) {
            count++;
        }
        else {
            string str_count = std::to_string(count);
            new_res += str_count;
            new_res += string(1,d);
        }
    }
    string str_count = std::to_string(count);
    new_res += str_count;
    char d = prev_res.back();
    new_res += string(1,d);
    
    cout<<"my result: "<<new_res<<endl;
    return new_res;
}



int main(int argc, char** argv) {
  default_random_engine gen((random_device())());
  int n;
  if (argc == 2) {
    n = stoi(argv[1]);
  } else {
    uniform_int_distribution<int> dis(1, 6);
    n = dis(gen);
  }
  assert(!LookAndSay(1).compare("1"));
  assert(!LookAndSay(2).compare("11"));
  assert(!LookAndSay(3).compare("21"));
  assert(!LookAndSay(5).compare("111221"));
  cout << "n = " << n << endl;
  cout << LookAndSay(n) << endl;
  return 0;
}
