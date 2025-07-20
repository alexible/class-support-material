#include <iostream>

int main()
{
    std::cout << "Hello World - Subtraction Operator (-)\n\n";
    
    // Basic subtraction with integers
    int a = 10;
    int b = 4;
    int difference = a - b;
    std::cout << a << " - " << b << " = " << difference << "\n";
    
    // Subtraction with decimal numbers
    double x = 8.5;
    double y = 3.2;
    double decimal_diff = x - y;
    std::cout << x << " - " << y << " = " << decimal_diff << "\n";
    
    // Subtracting to get negative result
    int small = 5;
    int big = 12;
    int negative_result = small - big;
    std::cout << small << " - " << big << " = " << negative_result << "\n";
    
    // Real world example: calculating change
    int money = 50;
    int cost = 32;
    int change = money - cost;
    std::cout << "Money: $" << money << " - Cost: $" << cost << " = Change: $" << change << "\n";
    
    return 0;
}