#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include "sorting.h"

// ==================== Тесты для BubbleSort ====================
TEST(BubbleSortTest, EmptyVector) {
    std::vector<int> v;
    BubbleSort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(BubbleSortTest, SingleElement) {
    std::vector<int> v = {42};
    BubbleSort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(BubbleSortTest, AlreadySorted) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    BubbleSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BubbleSortTest, ReverseSorted) {
    std::vector<int> v = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    BubbleSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BubbleSortTest, RandomVector) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> expected = {1, 1, 2, 3, 4, 5, 6, 9};
    BubbleSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BubbleSortTest, VectorWithDuplicates) {
    std::vector<int> v = {2, 2, 1, 1, 3, 3};
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    BubbleSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

// ==================== Тесты для QuickSort ====================
TEST(QuickSortTest, EmptyVector) {
    std::vector<int> v;
    QuickSort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(QuickSortTest, SingleElement) {
    std::vector<int> v = {42};
    QuickSort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(QuickSortTest, AlreadySorted) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    QuickSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTest, ReverseSorted) {
    std::vector<int> v = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    QuickSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTest, RandomVector) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> expected = {1, 1, 2, 3, 4, 5, 6, 9};
    QuickSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTest, VectorWithDuplicates) {
    std::vector<int> v = {2, 2, 1, 1, 3, 3};
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    QuickSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

// ==================== Тесты для MergeSort ====================
TEST(MergeSortTest, EmptyVector) {
    std::vector<int> v;
    MergeSort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(MergeSortTest, SingleElement) {
    std::vector<int> v = {42};
    MergeSort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MergeSortTest, ReverseSorted) {
    std::vector<int> v = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    MergeSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MergeSortTest, RandomVector) {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    std::vector<int> expected = {1, 1, 2, 3, 4, 5, 6, 9};
    MergeSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(MergeSortTest, VectorWithDuplicates) {
    std::vector<int> v = {2, 2, 1, 1, 3, 3};
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    MergeSort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

// ==================== Сравнительные тесты ====================
TEST(ComparisonTest, AllSortsProduceSameResult) {
    std::vector<int> original = {3, 1, 4, 1, 5, 9, 2, 6};
    
    std::vector<int> bubble_result = original;
    std::vector<int> quick_result = original;
    std::vector<int> merge_result = original;
    std::vector<int> std_result = original;
    
    BubbleSort(bubble_result.begin(), bubble_result.end());
    QuickSort(quick_result.begin(), quick_result.end());
    MergeSort(merge_result.begin(), merge_result.end());
    std::sort(std_result.begin(), std_result.end());
    
    EXPECT_EQ(bubble_result, std_result);
    EXPECT_EQ(quick_result, std_result);
    EXPECT_EQ(merge_result, std_result);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}