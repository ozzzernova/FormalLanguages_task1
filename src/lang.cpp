#include "../include/lang.h"

Language Language::Plus(Language& sec) {  //  объединение
  Language result;
  result.have_e_ = have_e_ || sec.have_e_;
  result.full_x_letter_ = full_x_letter_ || sec.full_x_letter_;
  result.left_block_ = std::max(left_block_, sec.left_block_);
  if (full_x_letter_) {
    result.left_block_ = std::max((sec.left_block_ == SIZE_MAX || left_block_ == SIZE_MAX) ? SIZE_MAX : sec.left_block_ + left_block_, result.left_block_);
  }
  result.right_block_ = std::max(right_block_, sec.right_block_);
  if (sec.full_x_letter_) {
    result.right_block_ = std::max((sec.right_block_ == SIZE_MAX || right_block_ == SIZE_MAX) ? SIZE_MAX : sec.right_block_ + right_block_, result.right_block_);
  }
  result.centre_block_ = std::max(centre_block_, sec.centre_block_);
  return result;
}

Language Language::Concatenation(Language& sec) {  //  конкатенация
  Language result;
  result.have_e_ = have_e_ && sec.have_e_;
  result.left_block_ = have_e_ ? std::max(left_block_, sec.left_block_) : left_block_;
  if (full_x_letter_) {
    result.left_block_ = std::max((sec.left_block_ == SIZE_MAX || left_block_ == SIZE_MAX) ? SIZE_MAX : sec.left_block_ + left_block_, result.left_block_);
  }
  result.right_block_ = sec.have_e_ ? std::max(sec.right_block_, right_block_) : sec.right_block_;
  if (sec.full_x_letter_) {
    result.right_block_ = std::max((sec.right_block_ == SIZE_MAX || right_block_ == SIZE_MAX) ? SIZE_MAX : sec.right_block_ + right_block_, result.right_block_);
  }
  result.centre_block_ = (sec.left_block_ == SIZE_MAX || right_block_ == SIZE_MAX) ? SIZE_MAX : sec.left_block_ + right_block_;
  result.full_x_letter_ = full_x_letter_ && sec.full_x_letter_;
  return result;
}

void Language::CliniStar() {  //  звезда клини
  have_e_ = true;
  centre_block_ = (left_block_ == SIZE_MAX || right_block_ == SIZE_MAX) ? SIZE_MAX : left_block_ + right_block_;
  if (full_x_letter_) {
    centre_block_ = SIZE_MAX;
    left_block_ = SIZE_MAX;
    right_block_ = SIZE_MAX;
  }
}

bool Language::FindWord(size_t k) {
  return left_block_ >= k || right_block_ >= k || centre_block_ >= k;
}

bool CreateALanguage(const std::string& regular_expression, char x, size_t k) {
  std::stack<Language> exp;
  Language::x_ = x;
  for (char i : regular_expression) {
    if (i == '+') {
      Language second = exp.top();
      exp.pop();
      Language first = exp.top();
      exp.pop();
      exp.push(first.Plus(second));
    } else if (i == '.') {
      Language second = exp.top();
      exp.pop();
      Language first = exp.top();
      exp.pop();
      exp.push(first.Concatenation(second));
    } else if (i == '*') {
      Language first = exp.top();
      exp.pop();
      first.CliniStar();
      exp.push(first);
    } else {
      exp.push(Language(i));
    }
  }
  Language out = exp.top();
  return out.FindWord(k);
}