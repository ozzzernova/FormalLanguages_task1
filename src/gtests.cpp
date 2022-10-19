#include <iostream>
#include <gtest/gtest.h>
#include "../include/lang.h"

GTEST_API_ int main(int argc, char ** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(test1, test) {
  std::string regular = "1a.b*.a.a.";
  size_t num = std::rand() % SIZE_MAX;
  EXPECT_EQ(false, CreateALanguage(regular, 'a', num));
}
TEST(test2, test) {
  std::string regular = "a*b*.c+1.";
  size_t num = std::rand() % SIZE_MAX;
  EXPECT_EQ(true, CreateALanguage(regular, 'b', num));
}

TEST(test3, test) {
  std::string regular = "a1b*+.c.";
  size_t num = std::rand() % SIZE_MAX;
  EXPECT_EQ(true, CreateALanguage(regular, 'b', num));
}

TEST(test4, test) {
  std::string regular = "ab+ab+.ac+.";
  size_t num = std::rand() % SIZE_MAX;
  EXPECT_EQ(true, CreateALanguage(regular, 'a', 3));
}

TEST(test5, test) {
  std::string regular = "ab*.a.";
  size_t num = std::rand() % SIZE_MAX;
  EXPECT_EQ(false, CreateALanguage(regular, 'a', 3));
}