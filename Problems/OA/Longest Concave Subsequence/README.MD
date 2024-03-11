## Problem Statement
A concave subsequence is a subsequence where the first and last elements are greater than all other elements in between. For example, [100, 0, 25, 11, 200] is concave, while [100, 0, 110, 200] is not since the 3rd element is greater than the 1st element.

Given an array that contains a permutation of n integers arr[n], determine length of the longest concave subsequence.

A permutation is a sequence of integers from 1 to n that contains each number exactly once. For example [1, 3, 2] is a permutation while [1, 2, 1] and [1, 2, 4] are not.

A subsequence is derived from a sequence by deleting 0 or more elements without changing the order of the remaining elements. For example [3, 4] is a subsequence of [5, 3, 2, 4], but [4, 3] is not.

