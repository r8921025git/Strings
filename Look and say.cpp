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


// @include
string LookAndSay(int n) {

}

// @exclude

int main(int argc, char** argv) {
  default_random_engine gen((random_device())());
  int n;
  if (argc == 2) {
    n = stoi(argv[1]);
  } else {
    uniform_int_distribution<int> dis(1, 50);
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
