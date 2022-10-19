#ifndef FORMALLANG_LANG_H
#define FORMALLANG_LANG_H

#include <iostream>
#include <stack>

class Language {
 public:
  static inline char x_;
  Language() = default;
  explicit Language(char c) : letter_(c) {
    if (c == '1') {
      have_e_ = true;
    }
    if (c == x_) {
      full_x_letter_ = true;
      left_block_ = 1;
      right_block_ = 1;
    }
  };
  char GetLetter() { return letter_; }
  Language Plus(Language& sec);
  Language Concatenation(Language& sec);
  void CliniStar();
  bool FindWord(size_t k);

 private:
  size_t left_block_ = 0;
  size_t centre_block_ = 0;
  size_t right_block_ = 0;
  bool have_e_ = false;
  char letter_ = 0;
  bool full_x_letter_ = false;
};

bool CreateALanguage(const std::string& regular_expression, char x, size_t k);

#endif  // FORMALLANG_LANG_H