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
    cout<<"Replace each 'a' by 'dd', and delete each 'b'"<<endl;
    int count_a=0, count_b=0;
    for (char c : s) {
        if (c=='a')
            count_a++;
        if (c=='b')
            count_b++;
    }
    cout <<"count_a="<<count_a<<endl;
    cout <<"count_b="<<count_b<<endl;
    string output;
    output.resize(s.size()+count_a-count_b);
    cout <<"output size ="<<output.size()<<endl;
    int k = 0;
    for (int i=0; i<s.size(); ++i) {
        if (s[i]=='a') {
            output[k]='d';
            k++;
            output[k]='d';
            k++;
        }
        else if (s[i]=='b') {
            // do nothing
        }
        else {
            output[k]=s[i];
            k++;
        }
    }
    cout<<"k="<<k<<endl;
    return output;
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
    
    
  default_random_engine gen((random_device())());
  for (int times = 0; times < 1; ++times) {
    string s;
    if (argc == 2) {
      s = argv[1];
    } else {
      uniform_int_distribution<int> dis(1, 50);
      s = RandString(dis(gen));
    }
    cout << s << endl << endl;
    string ans = ReplaceAndRemove(s);
    cout << ans << endl;
    CheckAns(s, ans);
  }
  return 0;
}
