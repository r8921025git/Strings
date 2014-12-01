// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

char ToLower(const char &c) {
    char out = c;
    if (c>='A' && c<='Z') {
        out -= ('A'-'a');
    }
    return out;
}


bool IsAlphaNumeric(const char &c) {
    if ((c>='0'&& c<='9') || (c>='a' && c<='z' || (c>='A'&&c<='Z')))
        return true;
    else
        return false;
}

bool IsPalindrome(const string& s) {
    string rs = s;
    std::reverse(rs.begin(),rs.end());
    cout<<"s="<<s<<endl;
    cout<<"rs = "<<rs<<endl;
    int k=0;
    for (int i=0; i<s.size(); ++i) {
        if (!IsAlphaNumeric(s[i]))
            continue;
        while (!IsAlphaNumeric(rs[k])) {
            k++;
            if (k>=rs.size())
                break;
        }
       // cout<<"s[i]="<<s[i]<<", rs[k]="<<rs[k]<<endl;
        if (ToLower(s[i]) != ToLower(rs[k])) {
            return false;
        }
        k++;
    }
  return true;
}


int main(int argc, char** argv) {
  assert(IsPalindrome("A man, a plan, a canal: Panama"));
  assert(!IsPalindrome("race a car"));
  assert(IsPalindrome(""));
  return 0;
}
