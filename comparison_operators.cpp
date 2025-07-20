#include <iostream>

int main()
{
    std::cout << "Hello World - Comparison Operators\n\n";
    
    int a = 10;
    int b = 5;
    int c = 10;
    
    // Equal to (==)
    std::cout << "Equal to (==) operator:\n";
    std::cout << a << " == " << b << " is " << (a == b) << " (1=true, 0=false)\n";
    std::cout << a << " == " << c << " is " << (a == c) << "\n";
    
    // Not equal to (!=)
    std::cout << "\nNot equal to (!=) operator:\n";
    std::cout << a << " != " << b << " is " << (a != b) << "\n";
    std::cout << a << " != " << c << " is " << (a != c) << "\n";
    
    // Less than (<)
    std::cout << "\nLess than (<) operator:\n";
    std::cout << b << " < " << a << " is " << (b < a) << "\n";
    std::cout << a << " < " << b << " is " << (a < b) << "\n";
    
    // Greater than (>)
    std::cout << "\nGreater than (>) operator:\n";
    std::cout << a << " > " << b << " is " << (a > b) << "\n";
    std::cout << b << " > " << a << " is " << (b > a) << "\n";
    
    // Less than or equal to (<=)
    std::cout << "\nLess than or equal to (<=) operator:\n";
    std::cout << b << " <= " << a << " is " << (b <= a) << "\n";
    std::cout << a << " <= " << c << " is " << (a <= c) << " (equal values)\n";
    
    // Greater than or equal to (>=)
    std::cout << "\nGreater than or equal to (>=) operator:\n";
    std::cout << a << " >= " << b << " is " << (a >= b) << "\n";
    std::cout << a << " >= " << c << " is " << (a >= c) << " (equal values)\n";
    
    // Real world example
    int age = 18;
    int voting_age = 18;
    std::cout << "\nReal world example:\n";
    std::cout << "Age " << age << " >= voting age " << voting_age << ": " << (age >= voting_age) << "\n";
    
    return 0;
}