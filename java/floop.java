/*************************************************************************
    > File Name: floop.java
    > Author: wayne
    > Mail: @163.com 
    > Created Time: 2015年08月20日 星期四 15时11分36秒
 ************************************************************************/
public class floop{
    public static void main(String args[]){
        double nums[] = {10.1, 11.2, 12.3, 13.4, 14.5};
        double result = 0;
        int i;
        for(i=0; i < nums.length; i++)
        {
            result += nums[i];
        }
        System.out.println(result);
    }
}
