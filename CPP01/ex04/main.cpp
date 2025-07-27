#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: number of arguments not correct" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(fileName.c_str());
    if (!infile)
    {
        std::cerr << "Error: opening file" << std::endl;
        return 1;
    }

    std::ofstream oufile((fileName + ".replace").c_str());
    if (!oufile)
    {
        std::cerr << "Error: cannot create output file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        oufile << line << '\n';
    }

    infile.close();
    oufile.close();
    return 0;
}