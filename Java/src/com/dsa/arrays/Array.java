package com.dsa.arrays;

import java.util.*;

import static com.dsa.arraylists.ArrayList.sortArrUsingComparator;

public class Array {

    // The Arrays.sort method uses the compareTo method on the type of objects the array is consists of.
    // For custom objects, we've to write the custom compareTo method
    // The compareTo method (obj1.compareTo(obj2)) return one of the three values:
    // negative -> means the first object is smaller and comes first
    // zero -> means both the objects are the same/equal
    // positive -> means the second object is smaller and comes first


    /** Generic sort method
     * @param <T> generic array
     */
    private static <T> void sortArray(T[] arr) {
        Arrays.sort(arr);
    }

    private static <T> void sortArrayInReverseOrder(T[] arr) {
        Arrays.sort(arr, Collections.reverseOrder());
    }

    private static <T> void displayArr(T[] arr) {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        Employee[] employees = new Employee[5];

        employees[0] = new Employee("John", 22, 10000);
        employees[1] = new Employee("Smith", 22, 20000);
        employees[2] = new Employee("Tom", 15, 15000);
        employees[3] = new Employee("Chandler", 25, 18000);
        employees[4] = new Employee("Rock", 18, 12000);

        Arrays.sort(employees);
        System.out.println(Arrays.toString(employees));

        List<Integer> numbers = new ArrayList<>();
        numbers.add(10);
        numbers.add(23);
        numbers.add(15);
        numbers.add(24);
        numbers.add(12);

        // sorting the array 'numbers' elements based on their sum of digits using a comparator
        /*Collections.sort(numbers, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return getSum(a) - getSum(b);
            }
        });*/

        //numbers.sort(Comparator.comparingInt(Array::getSum));
        sortArrUsingComparator(numbers);
        System.out.println(numbers);
    }
}
