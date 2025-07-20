#include <iostream>

int main()
{
    std::cout << "Hello World - Arrays with Loops\n\n";
    
    // Sample data
    int temperatures[7] = {72, 75, 68, 70, 73, 76, 74};  // Week temperatures
    std::cout << "=== Daily Temperatures This Week ===\n";
    
    // Displaying array with for loop
    std::cout << "Method 1 - Using for loop:\n";
    for (int i = 0; i < 7; i++) {
        std::cout << "Day " << (i + 1) << ": " << temperatures[i] << "°F\n";
    }
    
    std::cout << "\n=== Finding Maximum Temperature ===\n";
    int maxTemp = temperatures[0];  // Start with first element
    int maxDay = 0;
    
    for (int i = 1; i < 7; i++) {
        if (temperatures[i] > maxTemp) {
            maxTemp = temperatures[i];
            maxDay = i;
        }
    }
    
    std::cout << "Highest temperature: " << maxTemp << "°F on Day " << (maxDay + 1) << "\n";
    
    std::cout << "\n=== Finding Minimum Temperature ===\n";
    int minTemp = temperatures[0];  // Start with first element
    int minDay = 0;
    
    for (int i = 1; i < 7; i++) {
        if (temperatures[i] < minTemp) {
            minTemp = temperatures[i];
            minDay = i;
        }
    }
    
    std::cout << "Lowest temperature: " << minTemp << "°F on Day " << (minDay + 1) << "\n";
    
    std::cout << "\n=== Calculating Average Temperature ===\n";
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += temperatures[i];
    }
    double average = (double)sum / 7;
    std::cout << "Average temperature: " << average << "°F\n";
    
    std::cout << "\n=== Counting Days Above Average ===\n";
    int daysAboveAverage = 0;
    for (int i = 0; i < 7; i++) {
        if (temperatures[i] > average) {
            daysAboveAverage++;
            std::cout << "Day " << (i + 1) << ": " << temperatures[i] << "°F (above average)\n";
        }
    }
    std::cout << "Total days above average: " << daysAboveAverage << "\n";
    
    std::cout << "\n=== Modifying Array Elements ===\n";
    std::cout << "Adding 2 degrees to each day's temperature:\n";
    for (int i = 0; i < 7; i++) {
        temperatures[i] += 2;  // Add 2 to each temperature
        std::cout << "Day " << (i + 1) << ": " << temperatures[i] << "°F\n";
    }
    
    return 0;
}