#include <iostream>

int main()
{
    std::cout << "Hello World - Assignment Operators\n\n";
    
    // Basic assignment (=)
    std::cout << "Basic assignment (=) operator:\n";
    int x = 10;
    std::cout << "x = 10, x is now: " << x << "\n";
    
    // Add and assign (+=)
    std::cout << "\nAdd and assign (+=) operator:\n";
    x += 5;  // Same as: x = x + 5
    std::cout << "x += 5 (add 5 to x), x is now: " << x << "\n";
    
    // Subtract and assign (-=)
    std::cout << "\nSubtract and assign (-=) operator:\n";
    x -= 3;  // Same as: x = x - 3
    std::cout << "x -= 3 (subtract 3 from x), x is now: " << x << "\n";
    
    // Multiply and assign (*=)
    std::cout << "\nMultiply and assign (*=) operator:\n";
    x *= 2;  // Same as: x = x * 2
    std::cout << "x *= 2 (multiply x by 2), x is now: " << x << "\n";
    
    // Divide and assign (/=)
    std::cout << "\nDivide and assign (/=) operator:\n";
    x /= 4;  // Same as: x = x / 4
    std::cout << "x /= 4 (divide x by 4), x is now: " << x << "\n";
    
    // Modulus and assign (%=)
    std::cout << "\nModulus and assign (%=) operator:\n";
    int y = 17;
    std::cout << "Starting with y = " << y << "\n";
    y %= 5;  // Same as: y = y % 5
    std::cout << "y %= 5 (y modulus 5), y is now: " << y << "\n";
    
    // Real world example: score tracking
    std::cout << "\nReal world example - Game score:\n";
    int score = 100;
    std::cout << "Initial score: " << score << "\n";
    
    score += 50;  // Bonus points
    std::cout << "After bonus (+= 50): " << score << "\n";
    
    score -= 25;  // Penalty
    std::cout << "After penalty (-= 25): " << score << "\n";
    
    score *= 2;   // Double points event
    std::cout << "After double points (*= 2): " << score << "\n";
    
    return 0;
}