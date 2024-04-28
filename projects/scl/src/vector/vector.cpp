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
        std::copy(arr, arr + size, newArr);
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
        std::copy(arr, arr + position, newArr);
        std::copy(arr + position, arr + size, newArr + position + 1);
        delete[] arr;
        arr = newArr;
    }else {
        std::copy_backward(arr + position, arr + size, arr + size + 1);
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
            std::copy(arr + i + 1, arr + size, arr + i);
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
