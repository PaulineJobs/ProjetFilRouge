package com.abcd.jni;

public class HelloWorldJNI {

    // Load shared library
    static {
        System.loadLibrary("native");
    }
    
    public static void main(String[] args) {

	HelloWorldJNI hello = new HelloWorldJNI();
	long sum;
	String fullName;

        hello.sayHello();

	sum = hello.sumIntegers(2,3);
	System.out.println("Java : sum : "+sum);

	fullName = hello.sayHelloToMe("Marc",false);
	System.out.println("Java : fullName : "+fullName);

	fullName = hello.sayHelloToMe("Pauline",true);
	System.out.println("Java : fullName : "+fullName);

    }

    // Declare native methods 

    // void with no arguments
    private native void sayHello();

    // long with arguments
    private native long sumIntegers(int first, int second);

    // string with arguments
    private native String sayHelloToMe(String name, boolean isFemale);
}

