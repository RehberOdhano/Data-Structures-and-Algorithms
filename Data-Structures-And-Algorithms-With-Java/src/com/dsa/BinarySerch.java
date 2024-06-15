package com.dsa;

public class BinarySerch {
    public static int binarySearchIterative(int[] array, int target) {
        int start = 0, end = array.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (array[mid] == target) {
                return mid;
            } else if (target > array[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

    public static int binarySearchRecursive(int[] array, int target, int start, int end) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;
        if (array[mid] == target) return mid;
        else if (target > array[mid]) return binarySearchRecursive(array, target, mid + 1, end);
        else return binarySearchRecursive(array, target, start, mid - 1);
    }

    // Order Agnostic Binary Search is basically Binary Search on the sorted array, but we don't know whether the
    // array is sorted in ascending or descending order.
    // So first we will find whether the array is sorted on ascending or descending order and based on that we will
    // apply the binary search
    public static int orderAgnosticBinarySearch(int[] array, int target) {
        int start = 0, end = array.length - 1;
        boolean isArrSortedInAscendingOrder = array[start] < array[end];

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (array[mid] == target) return mid;
            if (isArrSortedInAscendingOrder) {
                if (target > array[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (target < array[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
}
