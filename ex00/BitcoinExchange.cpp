#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _database(copy._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
        _database = src._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseDatabase(const std::string &fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open data file." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line == "date,exchange_rate")
            continue;

        std::stringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        float rate = std::atof(rateStr.c_str());
        _database[date] = rate;
    }
}

void BitcoinExchange::parseInputFile(const std::string &fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line == "date | value")
            continue;

        handleLine(line);
    }
}

void BitcoinExchange::handleLine(const std::string &line)
{
    size_t sep = line.find(" | ");
    if (sep == std::string::npos)
    {
        std::cerr << "Error: bad input => " << line << std::endl;
        return;
    }

    std::string date = line.substr(0, sep);
    std::string valueStr = line.substr(sep + 3);

    float value;

    if (!isValidDate(date) || !isValidValue(valueStr, value))
        return;

    float rate;

    if (!findValue(date, rate))
        return;

    std::cout << date << " => " << value << " = " << rate * value << std::endl;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());

    if (month < 1 || month > 12)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
    {
        std::cerr << "Error: no rate available. => " << date << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::findValue(const std::string &date, float &rate)
{
    std::map<std::string, float>::iterator it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date)
    {
        rate = it->second;
        return true;
    }

    if (it == _database.begin())
    {
        std::cerr << "Error: no rate available." << std::endl;
        return false;
    }

    --it;
    rate = it->second;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value)
{
    std::istringstream ss(valueStr);
    ss >> value;

    if (ss.fail() || !ss.eof())
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}