package com.dsa.binary_search;

public class BinarySearch {
    public static int binarySearchIterative(int[] arr, int target) {
        int start = 0, end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) start = mid + 1;
            else end = mid - 1;
        }

        return -1;
    }

    public static int binarySearchRecursive(int[] arr, int start, int end, int target) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, end, target);
        else return binarySearchRecursive(arr, start, mid - 1, target);
    }

    public static int orderAgnosticBinarySearch(int[] arr, int target) {
        int start = 0, end = arr.length - 1;
        boolean isArrSortedInAscOrder = arr[start] < arr[end];

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) return mid;

            if (isArrSortedInAscOrder) {
                if (arr[mid] < target) start = mid + 1;
                else end = mid - 1;
            } else {
                if (arr[mid] > target) start = mid + 1;
                else end = mid - 1;
            }

        }

        return -1;
    }
}
