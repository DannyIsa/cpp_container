// daniisakov@gmail.com

#include "MyContainer.hpp"
#include <string>

namespace ariel {

template<typename T>
MyContainer<T>::Iterator::Iterator(typename std::vector<T>::iterator it) : current(it) {}

template<typename T>
T& MyContainer<T>::Iterator::operator*() {
    return *current;
}

template<typename T>
typename MyContainer<T>::Iterator& MyContainer<T>::Iterator::operator++() {
    ++current;
    return *this;
}

template<typename T>
bool MyContainer<T>::Iterator::operator!=(const Iterator& other) const {
    return current != other.current;
}

template<typename T>
void MyContainer<T>::addElement(const T& element) {
    elements.push_back(element);
}

template<typename T>
void MyContainer<T>::remove(const T& element) {
    auto original_size = elements.size();
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    
    if (elements.size() == original_size) {
        throw std::runtime_error("Element not found in container");
    }
}

template<typename T>
size_t MyContainer<T>::size() const {
    return elements.size();
}

// Ascending order iterator
template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::begin_ascending_order() {
    ascending_copy = elements;
    std::sort(ascending_copy.begin(), ascending_copy.end());
    return Iterator(ascending_copy.begin());
}

template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::end_ascending_order() {
    return Iterator(ascending_copy.end());
}

// Descending order iterator
template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::begin_descending_order() {
    descending_copy = elements;
    std::sort(descending_copy.begin(), descending_copy.end(), std::greater<T>());
    return Iterator(descending_copy.begin());
}

template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::end_descending_order() {
    return Iterator(descending_copy.end());
}

// Side cross order iterator
template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::begin_side_cross_order() {
    side_cross_copy.clear();
    
    std::vector<T> sorted = elements;
    std::sort(sorted.begin(), sorted.end());
    
    size_t left = 0, right = sorted.size() - 1;
    bool take_left = true;
    
    while (left <= right) {
        if (take_left) {
            side_cross_copy.push_back(sorted[left++]);
        } else {
            side_cross_copy.push_back(sorted[right--]);
        }
        take_left = !take_left;
        if (left > right) break;
    }
    
    return Iterator(side_cross_copy.begin());
}

template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::end_side_cross_order() {
    return Iterator(side_cross_copy.end());
}

// Reverse order iterator
template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::begin_reverse_order() {
    reverse_copy = elements;
    std::reverse(reverse_copy.begin(), reverse_copy.end());
    return Iterator(reverse_copy.begin());
}

template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::end_reverse_order() {
    return Iterator(reverse_copy.end());
}

// Original order iterator
template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::begin_order() {
    return Iterator(elements.begin());
}

template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::end_order() {
    return Iterator(elements.end());
}

// Middle out order iterator
template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::begin_middle_out_order() {
    middle_out_copy.clear();
    
    if (elements.empty()) {
        return Iterator(middle_out_copy.begin());
    }
    
    size_t middle = elements.size() / 2;
    middle_out_copy.push_back(elements[middle]);
    
    // Add elements alternating left and right from middle
    size_t right_offset = 1;
    size_t left_offset = 1;
    bool go_left = true;  // Start with left after middle
    
    while (middle + right_offset < elements.size() || middle >= left_offset) {
        if (go_left && middle >= left_offset) {
            middle_out_copy.push_back(elements[middle - left_offset]);
            left_offset++;
        } else if (!go_left && middle + right_offset < elements.size()) {
            middle_out_copy.push_back(elements[middle + right_offset]);
            right_offset++;
        }
        
        go_left = !go_left;
        
        if (middle + right_offset >= elements.size() && middle < left_offset) {
            break;
        }
    }
    
    return Iterator(middle_out_copy.begin());
}

template<typename T>
typename MyContainer<T>::Iterator MyContainer<T>::end_middle_out_order() {
    return Iterator(middle_out_copy.end());
}

template<typename T>
std::ostream& operator<<(std::ostream& os, MyContainer<T>& container) {
    os << "[";
    bool first = true;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        if (!first) {
            os << ", ";
        }
        os << *it;
        first = false;
    }
    os << "]";
    return os;
}

template class MyContainer<int>;
template class MyContainer<float>;
template class MyContainer<double>;
template class MyContainer<std::string>;

template std::ostream& operator<<(std::ostream& os, MyContainer<int>& container);
template std::ostream& operator<<(std::ostream& os, MyContainer<float>& container);
template std::ostream& operator<<(std::ostream& os, MyContainer<double>& container);
template std::ostream& operator<<(std::ostream& os, MyContainer<std::string>& container);

}