#include <iostream>
#include <fstream>
#include <vector>

// Uncomment the part
//#define PART1
#define PART2

#ifdef PART1
#define ITER 80
#else
#define ITER 256
#endif

int main()
{
    std::ifstream file("fish.txt");
    std::string line;
    std::getline(file, line);
    
    // Number of lanternfish of each timer value - 256 iterations
    // will simply not work with a std::vector of each timer value
    uint64_t timers[9] = { 0 }; 

    // Tokenize the input at commas
    for (; line.find(',') != std::string::npos; line.erase(0, line.find(',') + 1))
        timers[std::stoi(line.substr(0, line.find(',')))]++;
    timers[std::stoi(line)]++;

    // Iterate 256 times
    for (size_t i = 0; i < ITER; i++)
    {
        // Store number of 0's for later use
        uint64_t zeroes = timers[0];

        // 1=2, 2=3, 3=4, etc
        for (size_t j = 0; j < 8; j++)
            timers[j] = timers[j + 1];

        // Reset 0's to 6's, and 'spawn' a new lanternfish at 8
        timers[6] += zeroes;
        timers[8] = zeroes;
    }

    // Total the timers of each value
    uint64_t tot = 0;
    for (size_t i = 0; i < 9; i++)
        tot += timers[i];

    std::cout << "Total lanternfish: " << tot << "\n";
    
    return 0;
}