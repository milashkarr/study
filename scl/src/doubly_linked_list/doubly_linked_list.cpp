#include "doubly_linked_list.hpp"

using namespace IBusko;

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
    Node* current = begin;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::push_back(const T& value) noexcept {
    Node* newNode = new Node(value);
    if (end == nullptr) {
        begin = end = newNode;
    }
    else {
        end->next = newNode;
        newNode->prev = end;
        end = newNode;
    }
}

template <typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    Node* current = begin;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* current = begin;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
    Node* current = begin;
    while (current != nullptr) {
        if (current->value == value) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                begin = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                end = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
std::size_t DoublyLinkedList<T>::size() const noexcept {
    std::size_t count = 0;
    Node* current = begin;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
