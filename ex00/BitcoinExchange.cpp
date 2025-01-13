#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    (void)other;
    return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }
    return true;
}

std::string BitcoinExchange::findClosestDate(const std::map<std::string, double> &db, const std::string &date)
{
    std::map<std::string, double>::const_iterator it = db.lower_bound(date);
    if (it == db.begin() && it->first > date)
        return "";
    if (it == db.end() || it->first > date)
        --it;
    return it->first;
}

BitcoinExchange::~BitcoinExchange()
{
}