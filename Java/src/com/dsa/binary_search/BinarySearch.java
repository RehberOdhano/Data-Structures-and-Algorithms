package com.dsa.binary_search;

public class BinarySearch {

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
