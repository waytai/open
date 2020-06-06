package com.tutorialspoint;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("Beans.xml");

        System.out.println("===");
        TextEditor te = (TextEditor) context.getBean("textEditor");
        te.spellCheck();
        SpellChecker sp = (SpellChecker) context.getBean("spellChecker");
        sp.checkSpelling();
    }
}