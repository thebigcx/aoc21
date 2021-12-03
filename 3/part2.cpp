#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define NLEN 12

uint32_t filter(const std::vector<uint32_t>& vec, int sig)
{
    std::vector<uint32_t> ret = vec;
    for (size_t i = 0; i < NLEN && ret.size() > 1; i++)
    {
        uint32_t mask = 1 << ((NLEN - 1) - i);
        size_t ones = 0, zeroes = 0;
        for (auto& n : ret)
        {
            if (n & mask) ones++;
            else zeroes++;
        }

        int cond = sig ? ones >= zeroes : ones < zeroes;
        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](uint32_t x) { return cond ? !(x & mask) : x & mask; }), ret.end());
    }

    return ret[0];
}

int main()
{
    std::vector<uint32_t> nums;

    std::ifstream file("diagnostic.txt");
    for (std::string line; std::getline(file, line);)
        nums.push_back(std::stoi(line, 0, 2));

    std::cout << "Total: " << filter(nums, 0) * filter(nums, 1) << "\n";
    return 0;
}