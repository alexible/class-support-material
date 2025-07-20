#include <iostream>

int main()
{
    std::cout << "Hello World - Practical Array Examples\n\n";
    
    // Example 1: Student Grade Management
    std::cout << "=== Example 1: Student Grade Management ===\n";
    int studentGrades[5] = {88, 92, 76, 95, 84};
    std::string subjects[5] = {"Math", "Science", "English", "History", "Art"};
    
    std::cout << "Student Report Card:\n";
    int totalPoints = 0;
    for (int i = 0; i < 5; i++) {
        std::cout << subjects[i] << ": " << studentGrades[i] << "%\n";
        totalPoints += studentGrades[i];
    }
    double gpa = (double)totalPoints / 5;
    std::cout << "Overall GPA: " << gpa << "%\n\n";
    
    // Example 2: Inventory Management
    std::cout << "=== Example 2: Store Inventory ===\n";
    std::string products[4] = {"Apples", "Bananas", "Oranges", "Grapes"};
    int quantities[4] = {50, 30, 25, 40};
    double prices[4] = {1.50, 0.80, 2.00, 3.25};
    
    std::cout << "Current Inventory:\n";
    double totalValue = 0;
    for (int i = 0; i < 4; i++) {
        double itemValue = quantities[i] * prices[i];
        totalValue += itemValue;
        std::cout << products[i] << ": " << quantities[i] 
                  << " units @ $" << prices[i] 
                  << " each = $" << itemValue << "\n";
    }
    std::cout << "Total Inventory Value: $" << totalValue << "\n\n";
    
    // Example 3: Temperature Analysis
    std::cout << "=== Example 3: Monthly Temperature Analysis ===\n";
    int monthlyTemps[12] = {32, 35, 45, 60, 70, 80, 85, 83, 75, 60, 45, 35};
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
    // Find hottest and coldest months
    int hottestMonth = 0, coldestMonth = 0;
    for (int i = 1; i < 12; i++) {
        if (monthlyTemps[i] > monthlyTemps[hottestMonth]) {
            hottestMonth = i;
        }
        if (monthlyTemps[i] < monthlyTemps[coldestMonth]) {
            coldestMonth = i;
        }
    }
    
    std::cout << "Hottest month: " << months[hottestMonth] 
              << " (" << monthlyTemps[hottestMonth] << "°F)\n";
    std::cout << "Coldest month: " << months[coldestMonth] 
              << " (" << monthlyTemps[coldestMonth] << "°F)\n";
    
    // Count months above 70°F
    int warmMonths = 0;
    std::cout << "Months above 70°F: ";
    for (int i = 0; i < 12; i++) {
        if (monthlyTemps[i] > 70) {
            std::cout << months[i] << " ";
            warmMonths++;
        }
    }
    std::cout << "\nTotal warm months: " << warmMonths << "\n\n";
    
    // Example 4: Simple Search
    std::cout << "=== Example 4: Finding an Element ===\n";
    int numbers[8] = {10, 25, 7, 33, 42, 18, 9, 51};
    int searchFor = 33;
    bool found = false;
    int position = -1;
    
    std::cout << "Searching for " << searchFor << " in array: ";
    for (int i = 0; i < 8; i++) {
        std::cout << numbers[i] << " ";
        if (numbers[i] == searchFor) {
            found = true;
            position = i;
        }
    }
    std::cout << "\n";
    
    if (found) {
        std::cout << "Found " << searchFor << " at position " << position 
                  << " (index " << position << ")\n";
    } else {
        std::cout << searchFor << " not found in the array\n";
    }
    
    return 0;
}