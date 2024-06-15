package com.dsa;

import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        int[] arr = {-1, 0, 4, 6, 8, 11, 13};
        int target = 6, start = 0, end = arr.length;
        int result = BinarySerch.binarySearchIterative(arr, target);
        System.out.println("The target " + target + " is present at index: " + result);
        result = BinarySerch.binarySearchRecursive(arr, target, start, end);
        System.out.println("The target " + target + " is present at index: " + result);
        Collections.singletonList(Arrays.stream(arr).toArray()).sort(Collections.reverseOrder());
        result = BinarySerch.orderAgnosticBinarySearch(arr, target);
        System.out.println("The target " + target + " is present at index: " + result);
    }
}