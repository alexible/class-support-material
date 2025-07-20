#include <iostream>

int main()
{
    std::cout << "Hello World - Division Operator (/)\n\n";
    
    // Basic division with integers (integer division)
    int a = 15;
    int b = 3;
    int quotient = a / b;
    std::cout << a << " / " << b << " = " << quotient << " (integer division)\n";
    
    // Integer division with remainder lost
    int c = 17;
    int d = 5;
    int int_result = c / d;
    std::cout << c << " / " << d << " = " << int_result << " (remainder is lost in integer division)\n";
    
    // Division with decimal numbers for precise results
    double x = 17.0;
    double y = 5.0;
    double decimal_result = x / y;
    std::cout << x << " / " << y << " = " << decimal_result << " (decimal division)\n";
    
    // Real world example: splitting equally
    int total_candy = 24;
    int children = 6;
    int candy_per_child = total_candy / children;
    std::cout << "Candy distribution: " << total_candy << " candies / " << children << " children = " << candy_per_child << " candies each\n";
    
    // Converting to double for precise division
    int num1 = 7;
    int num2 = 2;
    double precise_result = (double)num1 / num2;
    std::cout << "Precise division: " << num1 << " / " << num2 << " = " << precise_result << "\n";
    
    return 0;
}