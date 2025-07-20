// daniisakov@gmail.com

#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

namespace ariel
{

    template <typename T>
    class MyContainer
    {
    private:
        std::vector<T> elements;

        std::vector<T> ascending_copy;
        std::vector<T> descending_copy;
        std::vector<T> side_cross_copy;
        std::vector<T> reverse_copy;
        std::vector<T> middle_out_copy;

    public:
        class Iterator
        {
        private:
            typename std::vector<T>::iterator current;

        public:
            Iterator(typename std::vector<T>::iterator it);
            T &operator*();
            Iterator &operator++();
            bool operator!=(const Iterator &other) const;
        };

        void addElement(const T &element);
        void remove(const T &element);
        size_t size() const;

        Iterator begin_ascending_order();
        Iterator end_ascending_order();

        Iterator begin_descending_order();
        Iterator end_descending_order();

        Iterator begin_side_cross_order();
        Iterator end_side_cross_order();

        Iterator begin_reverse_order();
        Iterator end_reverse_order();

        Iterator begin_order();
        Iterator end_order();

        Iterator begin_middle_out_order();
        Iterator end_middle_out_order();
    };

    template <typename T>
    std::ostream &operator<<(std::ostream &os, MyContainer<T> &container);

}
