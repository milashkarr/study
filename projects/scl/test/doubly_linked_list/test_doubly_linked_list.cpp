#include "pch.h"
#include "../doubly_linked_list/doubly_linked_list.hpp"
#include <gtest/gtest.h>

using IBusko::DoublyLinkedList;

// Тест для метода push_back
TEST(DoublyLinkedListTest, pushBack) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_TRUE(list.has_item(1));
    ASSERT_TRUE(list.has_item(2));
    ASSERT_TRUE(list.has_item(3));
    ASSERT_EQ(list.size(), 3);
}

// Тест для метода has_item
TEST(DoublyLinkedListTest, hasItem) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    ASSERT_TRUE(list.has_item(1));
    ASSERT_TRUE(list.has_item(2));
    ASSERT_FALSE(list.has_item(3));
}

// Тест для метода remove_first
TEST(DoublyLinkedListTest, removeFirst) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_TRUE(list.remove_first(2));
    ASSERT_FALSE(list.has_item(2));
    ASSERT_EQ(list.size(), 2);
}

// Тест для метода size
TEST(DoublyLinkedListTest, size) {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    ASSERT_EQ(list.size(), 3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
