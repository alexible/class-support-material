#include <iostream>

int main()
{
    std::cout << "Hello World - Modulus Operator (%)\n\n";
    
    // Basic modulus operation
    int a = 17;
    int b = 5;
    int remainder = a % b;
    std::cout << a << " % " << b << " = " << remainder << " (remainder when 17 is divided by 5)\n";
    
    // Even/odd number checking
    int number1 = 8;
    int number2 = 9;
    std::cout << number1 << " % 2 = " << number1 % 2 << " (even numbers have remainder 0)\n";
    std::cout << number2 << " % 2 = " << number2 % 2 << " (odd numbers have remainder 1)\n";
    
    // Finding remainder with different numbers
    int dividend = 25;
    int divisor = 7;
    int mod_result = dividend % divisor;
    std::cout << dividend << " % " << divisor << " = " << mod_result << "\n";
    
    // Real world example: time calculations
    int total_minutes = 150;
    int hours = total_minutes / 60;        // How many full hours
    int remaining_minutes = total_minutes % 60;  // Remaining minutes
    std::cout << total_minutes << " minutes = " << hours << " hours and " << remaining_minutes << " minutes\n";
    
    // Checking if a number is divisible by another
    int num = 20;
    int divisor2 = 4;
    if (num % divisor2 == 0) {
        std::cout << num << " is divisible by " << divisor2 << " (remainder is 0)\n";
    }
    
    return 0;
}