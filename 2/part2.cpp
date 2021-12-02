#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("instructions.txt");

    int horiz = 0, depth = 0, aim = 0;

    for (std::string line; std::getline(file, line);)
    {
        auto end_dir = line.find(" ");
        auto dir = line.substr(0, end_dir);
        auto num = std::stoi(line.substr(end_dir + 1, line.size() - end_dir - 1));
    
        if      (dir == "down") aim += num;
        else if (dir == "up")   aim -= num;
        else if (dir == "forward")
        {
            horiz += num;
            depth += num * aim;
        }
    }

    std::cout << "Horizontal position multiplied by depth: " << horiz * depth << "\n";
    return 0;
}