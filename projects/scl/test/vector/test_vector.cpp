#include "pch.h"
#include "../vector/vector.hpp"
#include <gtest/gtest.h>

using IBusko::Vector;

// Тест для метода push_back
TEST(VectorTest, pushBack) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    ASSERT_EQ(vec.get_size(), 2);
    ASSERT_TRUE(vec.has_item(1));
    ASSERT_TRUE(vec.has_item(2));
}

// Тест для метода has_item
TEST(VectorTest, hasItem) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    ASSERT_TRUE(vec.has_item(1));
    ASSERT_TRUE(vec.has_item(2));
    ASSERT_FALSE(vec.has_item(3));
}

// Тест для метода insert
TEST(VectorTest, insert) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    ASSERT_TRUE(vec.insert(1, 3));
    ASSERT_EQ(vec.get_size(), 3);
    ASSERT_TRUE(vec.has_item(3));
}

// Тест для метода remove_first
TEST(VectorTest, removeFirst) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    ASSERT_TRUE(vec.remove_first(1));
    ASSERT_EQ(vec.get_size(), 2);
    ASSERT_FALSE(vec.has_item(1));
}

// Тест для метода get_size
TEST(VectorTest, getSize) {
    Vector<int> vec;
    ASSERT_EQ(vec.get_size(), 0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    ASSERT_EQ(vec.get_size(), 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
