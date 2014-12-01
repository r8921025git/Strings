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

vector<string> PhoneMnemonic_iterative(const string& phone_number) {
    vector<string> output;
    for (int i=0; i<phone_number.size(); ++i) {
        int digit = phone_number[i]-'0';
        string letters = M[digit].c_str();
        
        vector<string> new_output;
        if (output.size()==0) {
            for (int k=0; k<letters.size(); ++k) {
                string tmp = std::string(letters[k]);
                output.push_back(tmp);
            }
        }
        else {
            for (auto res : output) {
            
            }
        }
        
    }
    return output;
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
  auto result = PhoneMnemonic_iterative(num);
  cout << "number = " << num << endl;
  for (const auto& str : result) {
    cout << str << endl;
  }
  return 0;
}
