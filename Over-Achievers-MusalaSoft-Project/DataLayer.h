#pragma once
#include <string>
#include <fstream>
#include <iostream>

int readInt(std::istream& input = std::cin, std::ostream& output = std::cout);
int printAllFlightsFromItaly();
int printAllFlightsFromFrance();
int printAllFlightsFromGermany();
int printCheaperFlightsFromItaly(double priceItaly);
int printCheaperFlightsFromFrance(double priceFrance);
int printCheaperFlightsFromGermany(double priceGermany);
int printFlightsFromItalyToDestination(std::string arrivalDestination);
int printFlightsFromFranceToDestination(std::string arrivalDestination);
int printFlightsFromGermanyToDestination(std::string arrivalDestination);
int printFlightsTimeForFrance(std::string timeFrance);
int printFlightsTimeForItaly(std::string timeItaly);
int printFlightsTimeForGermany(std::string timeGermany);
int insertTicket(int countryId);
