#include <iostream>

int main()
{
    std::cout << "Hello World - Addition Operator (+)\n\n";
    
    // Basic addition with integers
    int a = 5;
    int b = 3;
    int sum = a + b;
    std::cout << a << " + " << b << " = " << sum << "\n";
    
    // Addition with decimal numbers
    double x = 2.5;
    double y = 3.7;
    double decimal_sum = x + y;
    std::cout << x << " + " << y << " = " << decimal_sum << "\n";
    
    // Adding multiple numbers
    int result = 10 + 20 + 30;
    std::cout << "10 + 20 + 30 = " << result << "\n";
    
    // Adding variables and numbers
    int score = 85;
    int bonus = 15;
    int final_score = score + bonus;
    std::cout << "Score: " << score << " + Bonus: " << bonus << " = Final Score: " << final_score << "\n";
    
    return 0;
}