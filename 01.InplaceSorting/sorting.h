#ifndef SORTING_H
#define SORTING_H

// Header-only

#include <vector>
#include <algorithm>
#include <iterator>

#include "collvalue.h"

// ----------------------------- Bubble Sort --------------------------------------
template <typename Iterator>
void BubbleSort(Iterator begin, Iterator end) {
    if (begin == end) return;
    for (auto i = begin; i != end; ++i) {
        for (auto j = begin; j != end - 1; ++j) {
            if (*j > *(j+1)) {
                using std::swap;
                swap(*j, *(j+1));
            }
        }
    }
}

// --------------------------- QuickSort ---------------------------------------
template <typename Iterator>
auto Partition(Iterator begin, Iterator end) {
    auto x = *end;
    auto less = begin;
    for (auto i = begin; i < end; ++i) {
        if (*i <= x) {
            using std::swap;
            swap(*i, *less);
            ++less;
        }
    }
    using std::swap;
    swap(*less, *end);
    return less;
}

template <typename Iterator>
void QuickSort(Iterator begin, Iterator end) {
    if (begin >= end) return;
    auto q = Partition(begin, end-1);
    QuickSort(begin, q);
    QuickSort(q+1, end);
}


//----------------------------- Merge Sort --------------------------------------
template<typename Iterator>
void MergeSortImpl(std::vector<typename std::iterator_traits<Iterator>::value_type>& buffer, Iterator begin, Iterator end, int buffer_left) {
    if (begin >= end) return;
    
    auto m = begin + (end - begin) / 2;
    int left_size = (m - begin) + 1;
    
    MergeSortImpl(buffer, begin, m, buffer_left);
    MergeSortImpl(buffer, m + 1, end, buffer_left + left_size);
    
    int k = buffer_left;
    auto i = begin;
    auto j = m + 1;
    
    while (i <= m && j <= end) {
        if (*i <= *j) {
            buffer[k] = *i;
            i++;
        } else {
            buffer[k] = *j;
            j++;
        }
        k++;
    }
    
    while (i <= m) {
        buffer[k] = *i;
        i++;
        k++;
    }
    
    while (j <= end) {
        buffer[k] = *j;
        j++;
        k++;
    }
    
    k = buffer_left;
    for (auto it = begin; it <= end; ++it) {
        *it = buffer[k];
        k++;
    }
}

template <typename Iterator>
void MergeSort(Iterator begin, Iterator end) {
    if (begin == end) return;
    using ValueType = typename std::iterator_traits<Iterator>::value_type;
    std::vector<ValueType> buffer(std::distance(begin, end));
    MergeSortImpl(buffer, begin, end - 1, 0);
}

#endif // SORTING_H