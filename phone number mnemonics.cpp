// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

//#include <array>
#include <iostream>
#include <random>
#include <string>
#include <vector>

//using std::array;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::vector;
using std::uniform_int_distribution;



//const int kNumTelDigits = 10;

// The mapping from digit to corresponding characters.
const vector<string> M = {{"0", "1", "ABC", "DEF", "GHI",
                                         "JKL", "MNO", "PQRS", "TUV",
                                         "WXYZ"}};

vector<string> PhoneMnemonic(const string& phone_number) {

}

string RandString(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    uniform_int_distribution<char> dis('0', '9');
    ret += dis(gen);
  }
  return ret;
}

int main(int argc, char *argv[]) {
  string num;
  if (argc == 2) {
    num = argv[1];
  } else {
    num = RandString(2);
  }
  auto result = PhoneMnemonic(num);
  cout << "number = " << num << endl;
  for (const auto& str : result) {
    cout << str << endl;
  }
  return 0;
}
