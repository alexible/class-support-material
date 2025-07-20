#include <iostream>

int main()
{
    std::cout << "Hello World - Multiplication Operator (*)\n\n";
    
    // Basic multiplication with integers
    int a = 6;
    int b = 4;
    int product = a * b;
    std::cout << a << " * " << b << " = " << product << "\n";
    
    // Multiplication with decimal numbers
    double x = 2.5;
    double y = 4.0;
    double decimal_product = x * y;
    std::cout << x << " * " << y << " = " << decimal_product << "\n";
    
    // Multiplying by zero
    int number = 25;
    int zero = 0;
    int zero_result = number * zero;
    std::cout << number << " * " << zero << " = " << zero_result << "\n";
    
    // Real world example: calculating area
    int length = 8;
    int width = 5;
    int area = length * width;
    std::cout << "Rectangle area: " << length << " * " << width << " = " << area << " square units\n";
    
    // Multiplication table example
    int table_num = 3;
    std::cout << "\nMultiplication table for " << table_num << ":\n";
    std::cout << table_num << " * 1 = " << table_num * 1 << "\n";
    std::cout << table_num << " * 2 = " << table_num * 2 << "\n";
    std::cout << table_num << " * 3 = " << table_num * 3 << "\n";
    
    return 0;
}