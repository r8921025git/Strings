// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

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

// @include
string ReplaceAndRemove(string s) {

}
// @exclude

string RandString(int len) {
  default_random_engine gen((random_device())());
  string ret;
  while (len--) {
    uniform_int_distribution<char> dis('a', 'd');
    ret += dis(gen);
  }
  return ret;
}

void CheckAns(const string &s, const string &ans) {
  string temp;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'a') {
      temp += 'd', temp += 'd';
    } else if (s[i] != 'b') {
      temp += s[i];
    }
  }
  assert(ans.compare(temp) == 0);
}

int main(int argc, char *argv[]) {
    cout<<"Replace each 'a' by 'dd', and delete each 'b'"<<endl;
    
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1; ++times) {
    string s;
    if (argc == 2) {
      s = argv[1];
    } else {
      uniform_int_distribution<int> dis(1, 1000);
      s = RandString(dis(gen));
    }
    cout << s << endl << endl;
    string ans = ReplaceAndRemove(s);
    cout << ans << endl;
    CheckAns(s, ans);
  }
  return 0;
}
