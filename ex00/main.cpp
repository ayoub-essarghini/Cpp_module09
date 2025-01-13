#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: incorrect number of arguments." << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    // Load db file
    std::ifstream dbFile("data.csv");
    if (!dbFile) {
        std::cerr << "Error: could not open database file." << std::endl;
        return 1;
    }

    std::map<std::string, double> bitcoinPrices;
    std::string line, date;
    double price;

    // Skip the header line
    std::getline(dbFile, line);

    while (std::getline(dbFile, line)) {
        std::istringstream iss(line);
        if (std::getline(iss, date, ',') && (iss >> price)) {
            bitcoinPrices[date] = price;
        }
    }
    dbFile.close();

    // Process the input file
    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Skip header line
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string inputDate, valueStr;
        double value;

        if (!std::getline(iss, inputDate, '|') || !(iss >> valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim spaces
        inputDate.erase(inputDate.find_last_not_of(" ") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" "));

        // Validate date
        if (!exchange.isValidDate(inputDate)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Validate value
        value = std::atof(valueStr.c_str());
        if (value <= 0 || value > 1000) {
            std::cerr << (value <= 0 ? "Error: not a positive number." : "Error: too large a number.") << std::endl;
            continue;
        }

        // Find closest date
        std::string closestDate = exchange.findClosestDate(bitcoinPrices, inputDate);
        if (closestDate.empty()) {
            std::cerr << "Error: no valid date in database." << std::endl;
            continue;
        }

        // Calculate and output result
        double result = value * bitcoinPrices[closestDate];
        std::cout << inputDate << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
    }

    inputFile.close();
    return 0;
}