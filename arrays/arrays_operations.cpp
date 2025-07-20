#include <iostream>

int main()
{
    std::cout << "Hello World - Array Operations\n\n";
    
    // Creating and initializing arrays
    std::cout << "=== Creating Arrays ===\n";
    
    // Method 1: Declare with size and initialize
    int numbers[5] = {10, 20, 30, 40, 50};
    std::cout << "Method 1 - int numbers[5] = {10, 20, 30, 40, 50};\n";
    
    // Method 2: Let compiler determine size
    int moreNumbers[] = {1, 2, 3, 4, 5, 6};  // Size automatically becomes 6
    std::cout << "Method 2 - int moreNumbers[] = {1, 2, 3, 4, 5, 6};\n";
    
    // Method 3: Declare first, assign later
    int grades[3];
    grades[0] = 95;
    grades[1] = 87;
    grades[2] = 92;
    std::cout << "Method 3 - Declare then assign individual elements\n\n";
    
    // Accessing array elements
    std::cout << "=== Accessing Elements ===\n";
    std::cout << "First number: " << numbers[0] << "\n";
    std::cout << "Last number: " << numbers[4] << "\n";
    std::cout << "Middle grade: " << grades[1] << "\n\n";
    
    // Modifying array elements
    std::cout << "=== Modifying Elements ===\n";
    std::cout << "Before: numbers[2] = " << numbers[2] << "\n";
    numbers[2] = 99;  // Change third element
    std::cout << "After: numbers[2] = " << numbers[2] << "\n\n";
    
    // Array with different data types
    std::cout << "=== Different Data Types ===\n";
    char letters[4] = {'A', 'B', 'C', 'D'};
    double prices[3] = {19.99, 25.50, 12.75};
    bool flags[2] = {true, false};
    
    std::cout << "Character array: ";
    for (int i = 0; i < 4; i++) {
        std::cout << letters[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Price array: ";
    for (int i = 0; i < 3; i++) {
        std::cout << "$" << prices[i] << " ";
    }
    std::cout << "\n";
    
    std::cout << "Boolean array: ";
    for (int i = 0; i < 2; i++) {
        std::cout << flags[i] << " ";
    }
    std::cout << "\n\n";
    
    // Finding array size
    std::cout << "=== Array Size ===\n";
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    std::cout << "Size of numbers array: " << arraySize << " elements\n";
    
    return 0;
}