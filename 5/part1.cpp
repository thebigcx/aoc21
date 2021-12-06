#include <iostream>
#include <fstream>
#include <cstring>

struct Line
{
    int x1, y1, x2, y2;
};

int main()
{
    uint8_t cells[1000][1000];
    memset(cells, 0, 1000 * 1000);

    std::ifstream file("lines.txt");
    for (std::string str; std::getline(file, str);)
    {
        Line line;
        line.x1 = std::stoi(str.substr(0, str.find(',', 0)));
        str.erase(0, str.find(',', 0) + 1);

        line.y1 = std::stoi(str.substr(0, str.find("->", 0) - 1));
        str.erase(0, str.find("->", 0) + 2);

        line.x2 = std::stoi(str.substr(0, str.find(',', 0)));
        str.erase(0, str.find(',', 0) + 1);

        line.y2 = std::stoi(str);

        if (line.x1 != line.x2 && line.y1 != line.y2) continue;

        if (line.y1 == line.y2)
        {
            for (size_t i = 0; i < abs(line.x2 - line.x1) + 1; i++)
                cells[line.x2 > line.x1 ? line.x1 + i : line.x2 + i][line.y1]++;
        }
        else if (line.x1 == line.x2)
        {
            std::cout << line.y1 << "," << line.y2 << "\n";
            for (size_t i = 0; i < abs(line.y2 - line.y1) + 1; i++)
                cells[line.x1][line.y2 > line.y1 ? line.y1 + i : line.y2 + i]++;
        }
    }

    size_t tot = 0;
    for (size_t i = 0; i < 1000; i++)
    for (size_t j = 0; j < 1000; j++)
        tot += cells[i][j] >= 2;        

    std::cout << "Total: " << tot << "\n";

    return 0;
}