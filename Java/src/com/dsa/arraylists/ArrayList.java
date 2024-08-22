package com.dsa.arraylists;

import java.util.Comparator;
import java.util.List;

public class ArrayList {

    private static <T> int getSum(T number) {
        int sum = 0;
        int val = (int) number;
        while(val > 0) {
            sum += val % 10;
            val /= 10;
        }

        return sum;
    }
    public static <T> void sortArrUsingComparator(List<T> arr) {
        arr.sort(Comparator.comparingInt(ArrayList::getSum));
    }

    public static void main(String[] args) {
        List<Integer> numbers = new java.util.ArrayList<>();
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
