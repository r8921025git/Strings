// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

// @include
bool IsPalindrome(const string& s) {
    string rs = s;
    std::reverse(rs.begin(),rs.end());
    cout<<"s="<<s<<endl;
    cout<<"rs = "<<rs<<endl;
  return true;
}
// @exclude

int main(int argc, char** argv) {
  assert(IsPalindrome("A man, a plan, a canal: Panama"));
  assert(!IsPalindrome("race a car"));
  assert(IsPalindrome(""));
  return 0;
}
