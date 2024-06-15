package com.dsa;

import com.dsa.binary_search.BinarySearch;

public class Main {
    public static void main(String[] args) {
        int[] arr = {-1, 0, 4, 6, 8, 11, 13};
        int target = -2, start = 0, end = arr.length - 1;
        int result = BinarySearch.binarySearchIterative(arr, target);
        System.out.println("The target " + target + " is present at index: " + result);
        result = BinarySearch.binarySearchRecursive(arr, start, end, target);
        System.out.println("The target " + target + " is present at index: " + result);
        arr = new int[]{13,11,8,6,4,0,-1};
        result = BinarySearch.orderAgnosticBinarySearch(arr, target);
        System.out.println("The target " + target + " is present at index: " + result);
    }
}