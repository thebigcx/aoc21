#include <iostream>
#include <fstream>

int main()
{
    int counts[12] = { 0 };

    std::ifstream file("diagnostic.txt");
    for (std::string line; std::getline(file, line);)
        for (size_t i = 0; i < line.size(); i++)
            counts[i] += line[i] == '1';

    uint32_t gamma = 0;
    for (size_t i = 0; i < 12; i++)
    {
        if (counts[i] >= 500)
            gamma |= 1 << (11 - i);
    }

    std::cout << "Total: " << gamma * (~gamma & 0xfff) << "\n";
    return 0;
}