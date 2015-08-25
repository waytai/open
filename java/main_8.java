package com.tutorialspoint;

import java.util.ArrayList;
import java.util.Collection;
/*w  w  w.ja  v  a2  s.c  o m*/
public class main_8 {
  public static void main(String[] args) {
    Collection<String> names = new ArrayList<>();
    System.out.printf("Size = %d, Elements = %s%n", names.size(), names);
    names.add("XML");
    names.add("HTML");
    names.add("CSS");
    System.out.printf("Size   = %d, Elements   = %s%n",
        names.size(), names);
    names.remove("CSS");
    System.out.printf("Size   = %d, Elements   = %s%n",
        names.size(), names);
    names.clear();
    System.out.printf("Size   = %d, Elements   = %s%n",
        names.size(), names);
  }
}