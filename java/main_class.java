/*************************************************************************
    > File Name: class.java
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月21日 星期五 14时54分40秒
 ************************************************************************/

class Rectangle{
    double width;
    double height;
    Rectangle(){
        width = 10;
        height= 10;
    }
    double area(){
        return width*height;
    }
}

public class main_class{
    public static void main(String args[]){

        Rectangle mybox = new Rectangle();
        double area;
        area = mybox.area();
        System.out.println("Arean is " + area);
    }
}


