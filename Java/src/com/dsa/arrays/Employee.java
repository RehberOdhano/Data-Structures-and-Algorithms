package com.dsa.arrays;

public class Employee implements Comparable<Employee> {
    private final String name;
    private final int age;
    private final int salary;

    public Employee(String name, int age, int salary) {
        this.name = name;
        this.age = age;
        this.salary = salary;
    }

    /**
     * When we use the Arrays.sort() on employees array, it'll invoke this method for comparison
     * Here we're if the age of the two employees is the same then we'll sort them based on their salaries
     * Note: This function only works if the class implements the Comparable interface
     * @param employee the object to be compared.
     * @return integer value
     */
    public int compareTo(Employee employee) {
        if(this.age == employee.age) {
            return this.salary - employee.salary;
        }

        return this.age - employee.age;
    }

    public String toString() {
        return String.format("(%s, %d, %d)", this.name, this.age, this.salary);
    }
}
