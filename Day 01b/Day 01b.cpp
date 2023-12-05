// Day 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <fstream>
#include <string>
#include <regex>

char processDigit(std::string digit)
{
    char RetVal = digit[0];
    if (digit == "one")
        RetVal = '1';
    if (digit == "two")
        RetVal = '2';
    if (digit == "three")
        RetVal = '3';
    if (digit == "four")
        RetVal = '4';
    if (digit == "five")
        RetVal = '5';
    if (digit == "six")
        RetVal = '6';
    if (digit == "seven")
        RetVal = '7';
    if (digit == "eight")
        RetVal = '8';
    if (digit == "nine")
        RetVal = '9';

    return RetVal;
}

int processLine(std::string& line)
{
    std::cout << line << std::endl;
    std::string regLine = line;

    std::regex RegExpr ("(?:one|two|three|four|five|six|seven|eight|nine|[0-9])");

    std::smatch matches;
    char DigitOne = 0;
    char DigitTwo = 0;

    int SearchMax = 1;
    while (!DigitOne || !DigitTwo)
    {
        if (!DigitOne)
        {
            std::string SubStr = line.substr(0, SearchMax);
            if (std::regex_search(SubStr, matches, RegExpr, std::regex_constants::format_first_only))
            {
                DigitOne = processDigit(matches[0]);
                std::cout << matches[0] << " " << DigitOne << std::endl;
            }
        }

        if (!DigitTwo)
        {
            std::string SubStr = line.substr(line.length() - SearchMax);
            if (std::regex_search(SubStr, matches, RegExpr, std::regex_constants::format_first_only))
            {
                DigitTwo = processDigit(matches[0]);
                std::cout << matches[0] << " " << DigitTwo << std::endl;
            }
        }

        SearchMax++;
    }

    std::string number;

    number.push_back(DigitOne);
    number.push_back(DigitTwo);

    std::cout << regLine << std::endl;
    std::cout << number << std::endl << std::endl;

    return std::stoi(number);
}

int main()
{
    std::ifstream inputFile;
    inputFile.open("../Data_Day01.txt");
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
