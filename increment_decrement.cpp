#include <iostream>

int main()
{
    std::cout << "Hello World - Increment and Decrement Operators\n\n";
    
    // Increment operator (++)
    std::cout << "Increment operator (++):\n";
    int a = 5;
    std::cout << "Starting value of a: " << a << "\n";
    
    // Post-increment (a++)
    std::cout << "Post-increment a++: " << a++ << " (prints current value, then increments)\n";
    std::cout << "Value of a after post-increment: " << a << "\n";
    
    // Pre-increment (++a)
    std::cout << "Pre-increment ++a: " << ++a << " (increments first, then prints)\n";
    std::cout << "Value of a after pre-increment: " << a << "\n";
    
    std::cout << "\n" << std::string(40, '-') << "\n\n";
    
    // Decrement operator (--)
    std::cout << "Decrement operator (--):\n";
    int b = 10;
    std::cout << "Starting value of b: " << b << "\n";
    
    // Post-decrement (b--)
    std::cout << "Post-decrement b--: " << b-- << " (prints current value, then decrements)\n";
    std::cout << "Value of b after post-decrement: " << b << "\n";
    
    // Pre-decrement (--b)
    std::cout << "Pre-decrement --b: " << --b << " (decrements first, then prints)\n";
    std::cout << "Value of b after pre-decrement: " << b << "\n";
    
    // Real world examples
    std::cout << "\nReal world examples:\n";
    
    // Counter example
    int lives = 3;
    std::cout << "Player has " << lives << " lives\n";
    std::cout << "Player loses a life: " << lives-- << " (shows current, then decreases)\n";
    std::cout << "Lives remaining: " << lives << "\n";
    
    // Level progression
    int level = 1;
    std::cout << "\nCurrent level: " << level << "\n";
    std::cout << "Level up! New level: " << ++level << " (increases first, then shows)\n";
    
    // Loop counter simulation
    std::cout << "\nSimple counting:\n";
    int count = 0;
    std::cout << "Count: " << ++count << "\n";  // 1
    std::cout << "Count: " << ++count << "\n";  // 2
    std::cout << "Count: " << ++count << "\n";  // 3
    
    return 0;
}