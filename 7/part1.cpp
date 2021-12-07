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

    // Sort the vector
    std::sort(crabs.begin(), crabs.end());

    // Retrieve the median number based on even/odd
    double tot;
    if (crabs.size() % 2)
        tot = crabs[crabs.size() / 2];
    else
        tot = (crabs[crabs.size() / 2] + crabs[crabs.size() / 2 - 1]) / 2;

    // Get the fuel consumption
    size_t fuel = 0;
    for (auto& crab : crabs)
        fuel += abs(tot - crab);

    std::cout << "Horizontal position: " << tot << " Total fuel: " << fuel << "\n";
    return 0;
}