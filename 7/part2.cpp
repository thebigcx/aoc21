#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
    // Open the file
    std::ifstream file("crabs.txt");
    std::string line;
    std::getline(file, line);
    
    std::vector<int> crabs;

    // Tokenize the input at commas
    for (; line.find(',') != std::string::npos; line.erase(0, line.find(',') + 1))
        crabs.push_back(std::stoi(line.substr(0, line.find(','))));
    crabs.push_back(std::stoi(line));
    
    // Set initial candidate to maximum value
    size_t fuel = UINT64_MAX;

    // Iterate over 1200 horizontal positions
    for (size_t i = 0; i < 1200; i++)
    {
        // Get the fuel consumption
        size_t tot = 0;
        for (auto& crab : crabs)
        {
            // 1+2+3+4+... can be expressed as n(n+1)/2
            size_t dist = abs(i - crab);
            tot += dist * (dist + 1) / 2;
        }

        if (tot < fuel) fuel = tot;
    }

    std::cout << "Total fuel: " << fuel << "\n";
    return 0;
}