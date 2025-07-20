#include <iostream>

int main()
{
    std::cout << "Hello World - Logical Operators\n\n";
    
    bool condition1 = true;
    bool condition2 = false;
    bool condition3 = true;
    
    // Logical AND (&&)
    std::cout << "Logical AND (&&) operator:\n";
    std::cout << "true && true = " << (condition1 && condition3) << "\n";
    std::cout << "true && false = " << (condition1 && condition2) << "\n";
    std::cout << "false && false = " << (condition2 && condition2) << "\n";
    
    // Logical OR (||)
    std::cout << "\nLogical OR (||) operator:\n";
    std::cout << "true || false = " << (condition1 || condition2) << "\n";
    std::cout << "false || false = " << (condition2 || condition2) << "\n";
    std::cout << "true || true = " << (condition1 || condition3) << "\n";
    
    // Logical NOT (!)
    std::cout << "\nLogical NOT (!) operator:\n";
    std::cout << "!true = " << (!condition1) << "\n";
    std::cout << "!false = " << (!condition2) << "\n";
    
    // Real world examples with numbers
    int age = 20;
    int income = 25000;
    
    std::cout << "\nReal world examples:\n";
    
    // Using AND: both conditions must be true
    bool eligible_for_loan = (age >= 18) && (income >= 20000);
    std::cout << "Eligible for loan (age >= 18 AND income >= 20000): " << eligible_for_loan << "\n";
    
    // Using OR: at least one condition must be true
    bool gets_discount = (age < 18) || (age >= 65);
    std::cout << "Gets senior/child discount (age < 18 OR age >= 65): " << gets_discount << "\n";
    
    // Using NOT: opposite of condition
    bool not_adult = !(age >= 18);
    std::cout << "Not an adult (!(age >= 18)): " << not_adult << "\n";
    
    // Complex example
    bool weekend = true;
    bool has_homework = false;
    bool can_play_games = weekend && !has_homework;
    std::cout << "Can play games (weekend AND no homework): " << can_play_games << "\n";
    
    return 0;
}