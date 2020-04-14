/*
As this code is directly provided by PPP2, I do not claim to be the author.
Purpose: This drill gives multiple ways of printing out "success" which will
         have some number of errors in them, possibly 0. Each version can
         be viewed through previous commits.
*/

#include "../std_lib_facilities.h"

int main()
try {
  cout << "success" << '\n';
  keep_window_open();
  return 0;
}
catch (exception& e) {
  cerr << "error: " << e.what() << '\n';
  keep_window_open();
  return 1;
}
catch (...) {
  cerr << "Oops: unknown exception!\n";
  keep_window_open();
  return 2;
}
