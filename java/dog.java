package com.tutorialspoint;


public class dog {
	  public static void main(String[] args) {
	    Phone myPhone = new Phone();
	// ww  w .  j a v a 2  s . c o  m
	    myPhone.model = "iPhone";
	    myPhone.year = 2009;
	    myPhone.price = 16000.0;

	    dog.test(myPhone);
	  }

	  public static void test(final Phone xPhone) {
	    System.out.println("#2: model  = " + xPhone.model + ", year   = "
	        + xPhone.year + ",  price = " + xPhone.price);

	    // Let's make xyCar refer to a new object
	    //xPhone = new Phone();
	  }
	}
	class Phone {
	  public String model = "Unknown";
	  public int year = 2014;
	  public double price = 0.0;
	}