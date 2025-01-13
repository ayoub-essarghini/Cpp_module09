#pragma once

#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
class BitcoinExchange
{
private:
  
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    bool isValidDate(const std::string &date);
    std::string findClosestDate(const std::map<std::string, double> &db, const std::string &date);

};

