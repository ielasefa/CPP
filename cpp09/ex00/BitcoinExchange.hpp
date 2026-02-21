/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:43:17 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/20 03:11:50 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        std::string _dataFile;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& dataFile);
        ~BitcoinExchange();
        bool parseDataFile(const char* filename, std::map<std::string, double>& rates)
        void procesDatabase(const std::string& inputFile)

};


#endif // BITCOINEXCHANGE_HPP