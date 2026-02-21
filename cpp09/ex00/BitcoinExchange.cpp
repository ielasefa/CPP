/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:48:51 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/21 00:11:56 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    if (this != &src)
        this->_database = src._database;

    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(s[start]))
        start++;

    size_t end = s.size();
    while (end > start && isspace(s[end - 1]))
        end--;

    return s.substr(start, end - start);
}

bool BitcoinExchange::parseDataFile(const char* filename,
                   std::map<std::string, double>& rates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
            continue;

        date = trim(date);
        rateStr = trim(rateStr);

        rates[date] = atof(rateStr.c_str());
    }

    file.close();
    return true;
}

void processInputFile(const char* filename,
                      const std::map<std::string, double>& rates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        line = trim(line);

        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') ||
            !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }