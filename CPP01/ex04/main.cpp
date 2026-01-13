/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:16:30 by iel-asef          #+#    #+#             */
/*   Updated: 2025/10/28 02:16:30 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: number of arguments not correct" << std::endl;
        return 1;
    }

    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty())
    {
        std::cerr << "Error: search string cannot be empty" << std::endl;
        return 1;
    }

    std::string outFileName = fileName + ".replace";
    std::ifstream infile(fileName.c_str());
    if (!infile)
    {
        std::cerr << "Error: opening input file" << std::endl;
        return 1;
    }

    std::ofstream oufile(outFileName.c_str());
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
    
    return 0;
}
