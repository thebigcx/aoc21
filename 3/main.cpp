#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("instructions.txt");

    int x = 0, y = 0;

    for (std::string line; std::getline(file, line);)
    {
        auto end_dir = line.find(" ");
        auto dir = line.substr(0, end_dir);
        auto num = std::stoi(line.substr(end_dir + 1, line.size() - end_dir - 1));
    
        if (dir == "forward")   x += num;
        else if (dir == "down") y += num;
        else if (dir == "up")   y -= num;
    }

    std::cout << "Horizontal position multiplied by depth: " << x * y << "\n";
    return 0;
}