#include "./include/lang.h"
#include <iostream>

int main() {
  std::cout << "Enter regular expression, symbol and degree\n";
  std::string regular_expression;
  int k = 0;
  char x = 0;
  std::cin >> regular_expression >> x >> k;
  if (CreateALanguage(regular_expression, x, k)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
  return 0;
}
