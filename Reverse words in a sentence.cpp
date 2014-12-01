// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::string;
using std::uniform_int_distribution;

string RandString(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    //uniform_int_distribution<int> dis(0, 52);
    uniform_int_distribution<int> dis(0, 60);
    int ch = dis(gen);
    if (ch >= 52) {
      ret += ' ';
    } else if (ch < 26) {
      ret += ch + 'a';
    } else {
      ret += ch - 26 + 'A';
    }
  }
  return ret;
}

// @include
void ReverseWords(string* s) {
    // first reverse the whole string
    std::reverse(s->begin(),s->end());
    cout << *s << endl;
    // then reverse each word separately
    int b = 0;
    for (size_t i=0; i<s->size(); ++i) {
        if ((*s)[i]==' ') {
            cout<<"b="<<b<<" , i="<<i<<endl;
            std::reverse(s->begin()+b, s->begin()+i);
            cout << *s << endl;
            b = i+1;
        }
    }
}
// @exclude

void check_answer(const string &ori, string* str) {
  ReverseWords(str);
  assert(ori.compare(*str) == 0);
}

int main(int argc, char *argv[]) {
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1; ++times) {
    string str;
    if (argc >= 2) {
      str += argv[1];
      for (int i = 2; i < argc; ++i) {
        str += ' ';
        str += argv[i];
      }
    } else {
      uniform_int_distribution<int> dis(0, 50);
      str = RandString(dis(gen));
    }
    string original_str(str);
    cout<<endl<<endl<<"---Original string:"<<endl;
    cout << str << endl;
    ReverseWords(&str);
    cout <<endl<< "---My answer: "<<endl<<str << endl;
   // check_answer(original_str, &str);
  }
  return 0;
}
