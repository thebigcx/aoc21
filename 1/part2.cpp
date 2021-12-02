#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream file("readings.txt");

    std::vector<int> readings;
    for (std::string line; std::getline(file, line);)
        readings.push_back(std::stoi(line));

    int prev = 999999, total = 0;
    for (size_t i = 0; i < readings.size() - 2; i++)
    {
        int window = readings[i] + readings[i + 1] + readings[i + 2];
        total += window > prev;
        prev = window;
    }
    
    std::cout << "Number of increases: " << total << "\n";
    return 0;
}