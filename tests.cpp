#include <gtest/gtest.h>
#include "test_lab.c"

using testing::Eq;

int wordcount(int argc, char *argv[3]);

TEST(wordCountTest, tests) {
    char *arr[3] = {"WordCount.exe", "-l", "input.txt"};
    ASSERT_EQ(wordcount(3, arr), 3);
    char *arr1[3] = {"WordCount.exe", "-c", "input.txt"};
    ASSERT_EQ(wordcount(3, arr1), 72);
    char *arr2[3] = {"WordCount.exe", "-w", "input.txt"};
    ASSERT_EQ(wordcount(3, arr2), 17);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}