#include "vector.hpp"
#include <iostream>
#include <algorithm>

using namespace IBusko;

template <typename T>
Vector<T>::Vector() noexcept {
    arr = new T[capacity];
}

template <typename T>
Vector<T>::~Vector() noexcept {
    delete[] arr;
}

template <typename T>
void Vector<T>::push_back(const T& value) noexcept {
    if (size == capacity) {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[size++] = value;
}
    
template <typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool Vector<T>::insert(const int position, const T& value) {
    if (position < 0 || position > size) {
        return false;
    }

    if (size == capacity) {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < position; ++i) {
            newArr[i] = arr[i];
        }
        for (int i = position; i < size; ++i) {
            newArr[i + 1] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    else {
        for (int i = size; i > position; --i) {
            arr[i] = arr[i - 1];
        }
    }

    arr[position] = value;
    ++size;
    return true;
}

template <typename T>
void Vector<T>::print() const noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool Vector<T>::remove_first(const T& value) noexcept {
    for (std::size_t i = 0; i < size; ++i) {
        if (arr[i] == value) {
            for (std::size_t j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            --size;
            return true;
        }
    }
    return false;
}

template <typename T>
std::size_t Vector<T>::get_size() const noexcept {
    return size;
}
