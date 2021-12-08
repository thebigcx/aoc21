#include <iostream>
#include <fstream>

int main()
{
    int tot = 0;

    std::ifstream file("entries.txt");
    for (std::string line; std::getline(file, line);)
    {
        line.erase(0, line.find('|') + 2);
    
        for (size_t pos = line.find(' '); pos != std::string::npos; pos = line.find(' '))
        {
            switch (line.substr(0, pos).size())
                case 2: case 3: case 4: case 7: tot++;
            line.erase(0, pos + 1);
        }
        switch (line.size())
            case 2: case 3: case 4: case 7: tot++;
    }

    std::cout << "Total: " << tot << "\n";

    return 0;
}