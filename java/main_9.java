package com.tutorialspoint;

import java.util.SortedSet;
import java.util.TreeSet;
//from w  w w.  j  a  va 2s . c  o m
public class main_9 {
  public static void main(String[] args) {
    // Create a sorted set of some names
    SortedSet<String> sortedNames = new TreeSet<>();
    sortedNames.add("Java");
    sortedNames.add("SQL");
    sortedNames.add("HTML");
    sortedNames.add("CSS");

    // Print the sorted set of names
    System.out.println(sortedNames);
  }

}