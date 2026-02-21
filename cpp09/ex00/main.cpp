/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:39:30 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/20 02:45:10 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <map>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::map<std::string, double> rates;
    if (!BitcoinExchange::parseDataFile("data.csv" ))
        return 1;

    if (!parseDataFile("data.csv", rates))
        return 1;

    processInputFile(argv[1], rates);
    return 0;
}