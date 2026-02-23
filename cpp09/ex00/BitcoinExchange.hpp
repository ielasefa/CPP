/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:43:17 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/23 02:04:12 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;
        bool    findValue(const std::string &date, float &rate);
        bool    isValidDate(const std::string &date);
        bool    isValidValue(const std::string &valueStr, float &value);
        void    handleLine(const std::string &line);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        void    parseDatabase(const std::string &fileName);
        void    parseInputFile(const std::string &fileName);
};

#endif // BITCOINEXCHANGE_HPP
