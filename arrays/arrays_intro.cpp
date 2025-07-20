#include <iostream>

int main()
{
    std::cout << "Hello World - Introduction to Arrays\n\n";
    
    // What is an array?
    std::cout << "=== What is an Array? ===\n";
    std::cout << "An array is a collection of elements of the same type\n";
    std::cout << "stored in consecutive memory locations.\n\n";
    
    // Single variables vs Array
    std::cout << "=== Without Arrays (using single variables) ===\n";
    int student1_score = 85;
    int student2_score = 92;
    int student3_score = 78;
    int student4_score = 95;
    int student5_score = 88;
    
    std::cout << "Student 1 score: " << student1_score << "\n";
    std::cout << "Student 2 score: " << student2_score << "\n";
    std::cout << "Student 3 score: " << student3_score << "\n";
    std::cout << "Student 4 score: " << student4_score << "\n";
    std::cout << "Student 5 score: " << student5_score << "\n";
    std::cout << "This is tedious for many students!\n\n";
    
    // Using arrays instead
    std::cout << "=== With Arrays (much better!) ===\n";
    int scores[5] = {85, 92, 78, 95, 88};  // Array of 5 integers
    
    std::cout << "All student scores in one array:\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "Student " << (i + 1) << " score: " << scores[i] << "\n";
    }
    
    std::cout << "\n=== Array Declaration Syntax ===\n";
    std::cout << "int arrayName[size] = {values};\n";
    std::cout << "int scores[5] = {85, 92, 78, 95, 88};\n\n";
    
    // Array indexing
    std::cout << "=== Array Indexing (starts from 0) ===\n";
    std::cout << "scores[0] = " << scores[0] << " (first element)\n";
    std::cout << "scores[1] = " << scores[1] << " (second element)\n";
    std::cout << "scores[2] = " << scores[2] << " (third element)\n";
    std::cout << "scores[3] = " << scores[3] << " (fourth element)\n";
    std::cout << "scores[4] = " << scores[4] << " (fifth element)\n";
    
    return 0;
}