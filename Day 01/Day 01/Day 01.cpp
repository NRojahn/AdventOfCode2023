// Day 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int processLine(std::string& line)
{
    std::string numLine = std::regex_replace(line, std::regex("[^0-9]+"),"");

    std::string number;

    number.push_back(numLine[0]);
    number.push_back(numLine[numLine.length()-1]);

    std::cout << line << std::endl;
    std::cout << numLine << std::endl;
    std::cout << number << std::endl;

    return std::stoi(number);
}

int main()
{
    std::ifstream inputFile;
    inputFile.open("Data.txt");
    if (inputFile.is_open())
    {
        int sum = 0;
        for (std::string line; getline(inputFile, line);)
        {
            sum += processLine(line);
        }

        inputFile.close();
        std::cout << sum << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
