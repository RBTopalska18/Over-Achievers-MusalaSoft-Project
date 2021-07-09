#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <sstream> 
#include <conio.h>
#include <vector>
#include <chrono>
#include <thread>
#include <nanodbc.h>
#include <exception>


using namespace std;

void wait(int delay = 200);

//DEFINE

#define RESET "\033[0m"
#define RED "\033[1;91m" 
#define YELLOW "\033[1;93m"  
#define PURPLE "\033[1;95m"
#define CYAN "\033[1;96m"
#define GREEN "\033[1;92m"
#define BLUE "\033[1;94m"
#define WHITE "\033[2;37m"
#define ANIMATION_ENABLED true

//BACK END

int printAllFlightsFromItaly()
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE Name = ?
              
    )");


		string name1 = "Italy,Venice";
		stmt.bind(0, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printAllFlightsFromFrance()
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE Name = ?
              
    )");


		string name1 = "France,Paris";
		stmt.bind(0, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printAllFlightsFromGermany()
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE Name = ?
              
    )");


		string name1 = "Germany,Berlin";
		stmt.bind(0, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printCheaperFlightsFromItaly(double priceItaly)
{ 
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE  Price < ? AND Name = ?
              
    )");
		string name1 = "Italy,Venice";
		stmt.bind(0, &priceItaly); 
		stmt.bind(1, name1.c_str()); 
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1)<<" eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printCheaperFlightsFromFrance(double priceFrance)
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE  Price < ? AND Name = ?
              
    )");
		string name1 = "France,Paris";
		stmt.bind(0, &priceFrance);
		stmt.bind(1, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1)
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printCheaperFlightsFromGermany(double priceGermany)
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE  Price < ? AND Name = ?
              
    )");
		string name1 = "France,Paris";
		stmt.bind(0, &priceGermany);
		stmt.bind(1, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printFlightsFromItalyToDestination(string ArrivalDestination)
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE  ArrivalDestination = ? AND Name = ?
              
    )");
		string name1 = "Italy,Venice";
		stmt.bind(0, ArrivalDestination.c_str());
		stmt.bind(1, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printFlightsFromFranceToDestination(string ArrivalDestination)
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE  ArrivalDestination = ? AND Name = ?
              
    )");
		string name1 = "France,Paris";
		stmt.bind(0, ArrivalDestination.c_str());
		stmt.bind(1, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

int printFlightsFromGermanyToDestination(string ArrivalDestination)
{
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [CountryId]
                  ,[Name]
                  ,[Time]
                  ,[ArrivalDestination]
                  ,[Price]
              FROM [AirPort].[dbo].[Country]
              WHERE  ArrivalDestination = ? AND Name = ?
              
    )");
		string name1 = "Germany,Berlin";
		stmt.bind(0, ArrivalDestination.c_str());
		stmt.bind(1, name1.c_str());
		auto result = nanodbc::execute(stmt);

		while (result.next())
		{
			std::cout << result.get<int>("CountryId", -1)
				<< ", "
				<< result.get<nanodbc::string>("Name", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("Time", "NULL")
				<< ", "
				<< result.get<nanodbc::string>("ArrivalDestination", "NULL")
				<< ", "
				<< result.get<double>("Price", -1) << " eu"
				<< endl;
		}

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}

//FRONT END
void spaces(unsigned short int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	}
}

void wait(int delay)
{
	if (ANIMATION_ENABLED)
	{
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

void welcome()
{
	spaces(20); cout << YELLOW << "*******************************************************" << RESET << endl;
	spaces(20); cout << WHITE << "                         AIRPLANE                        " << RESET << endl;
	spaces(20); cout << WHITE << "                          AGENCY                         " << RESET << endl;
	spaces(20); cout << YELLOW << "*******************************************************" << RESET << endl;

}

void displayFlightsMenu()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____FLIGHTS_____                ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.All flights                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   2.Cheaper price                 ||" << endl;
	wait();
	spaces(20);  cout << "||                   3.Destination                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   4.Time                          ||" << endl;
	wait();
	spaces(20);  cout << "||                   5.Exit                          ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	cout << endl;
}

void displayTicketMenu()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____TICKETS_____                ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.Reserve ticket                ||" << endl;
	wait();
	spaces(20);  cout << "||                   2. Exit                         ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	cout << endl;
}

void displayCountry()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____COUNTRY_____                ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.Italy,Venice                  ||" << endl;
	wait();
	spaces(20);  cout << "||                   2.France,Paris                  ||" << endl;
	wait();
	spaces(20);  cout << "||                   3.Germany,Berlin                ||" << endl;
	wait();
	spaces(20);  cout << "||                   4.Exit                          ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	cout << endl;
}

void displayDestinationForItaly()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____DESTINATION_____            ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.Germany,Berlin                ||" << endl;
	wait();
	spaces(20);  cout << "||                   2.France,Paris                  ||" << endl;
	wait();
	spaces(20);  cout << "||                   3.England,London                ||" << endl;
	wait();
	spaces(20);  cout << "||                   4.Spain,Barcelona               ||" << endl;
	wait();
	spaces(20);  cout << "||                   5.Turkey,Istanbul               ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20); cout << "Enter destination: ";
}

void displayDestinationForFrance()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____DESTINATION_____            ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.Romania,Bucharest             ||" << endl;
	wait();
	spaces(20);  cout << "||                   2.South Korea,Seoul             ||" << endl;
	wait();
	spaces(20);  cout << "||                   3.Ukraine,Kyiv                  ||" << endl;
	wait();
	spaces(20);  cout << "||                   4.Germany,Hamburt               ||" << endl;
	wait();
	spaces(20);  cout << "||                   5.Bulgaria,Sofia                ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	cout << endl;
}

void displayDestinationForGermany()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____DESTINATION_____            ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.France,Paris                  ||" << endl;
	wait();
	spaces(20);  cout << "||                   2.Brazil,Rio de Janeiro         ||" << endl;
	wait();
	spaces(20);  cout << "||                   3.USA,New York                  ||" << endl;
	wait();
	spaces(20);  cout << "||                   4.Egypt,Cairo                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   5.Georgia,Atlanta               ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20); cout << "Enter destination: ";
}

void flightChoiceItaly()
{
	int flightChoice;
	double priceItaly;
	string destinationItaly;
	displayFlightsMenu();
	cout << endl;
	spaces(20); cout << "Enter an option: ";
	cin >> flightChoice;

	while (flightChoice > 5 || flightChoice < 1)
	{
		cout << endl;
		cout << RED << "You have to enter a number between 1 and 5! Please try again!" << RESET;

	}
	system("cls");
	switch (flightChoice)
	{
	case 1:
		printAllFlightsFromItaly();
		break;
	case 2:
		cout << "Enter the biggest price you can allow:";
		cin >> priceItaly;
		cout << endl;
		printCheaperFlightsFromItaly(priceItaly);
		break;
	case 3:
		displayDestinationForItaly();
		cin >> destinationItaly;
		cout << endl;
		printFlightsFromItalyToDestination(destinationItaly);
		break;
	case 4:
		break;
	case 5:
		exit(0);
		break;
	}
}

void flightChoiceFrance()
{
	int flightChoice;
	double priceFrance;
	string destinationFrance;
	displayFlightsMenu();
	cout << endl;
	spaces(20); cout << "Enter an option: ";
	cin >> flightChoice;

	while (flightChoice > 5 || flightChoice < 1)
	{
		cout << endl;
		cout << RED << "You have to enter a number between 1 and 5! Please try again!" << RESET;

	}
	system("cls");
	switch (flightChoice)
	{
	case 1:
		printAllFlightsFromFrance();
		break;
	case 2:
		cout << "Enter the biggest price you can allow:";
		cin >> priceFrance;
		cout << endl;
		printCheaperFlightsFromFrance(priceFrance);
		break;
	case 3:
		displayDestinationForFrance();
		cin >> destinationFrance;
		cout << endl;
		printFlightsFromFranceToDestination(destinationFrance);
		break;
	case 4:
		break;
	case 5:
		exit(0);
		break;
	}
}

void flightChoiceGermany()
{
	int flightChoice;
	double priceGermany;
	string destinationGermany;
	displayFlightsMenu();
	cout << endl;
	spaces(20); cout << "Enter an option: ";
	cin >> flightChoice;

	while (flightChoice > 5 || flightChoice < 1)
	{
		cout << endl;
		cout << RED << "You have to enter a number between 1 and 5! Please try again!" << RESET;

	}
	system("cls");
	switch (flightChoice)
	{
	case 1:
		printAllFlightsFromGermany();
		break;
	case 2:
		cout << "Enter the biggest price you can allow:";
		cin >> priceGermany;
		cout << endl;
		printCheaperFlightsFromGermany(priceGermany);
		break;
	case 3:
		displayDestinationForGermany();
		cin >> destinationGermany;
		cout << endl;
		printFlightsFromGermanyToDestination(destinationGermany);
		break;
		break;
	case 4:
		break;
	case 5:
		exit(0);
		break;
	}
}

void printMenu()
{
	int choice = 0;
	welcome();
	while (choice != 5) {
		cout << endl;
		displayTicketMenu();
		cout << endl;
		spaces(20); cout << "Enter an option: ";
		cin >> choice;

		while (choice > 2 || choice < 1)
		{
			cout << endl;
			cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;

		}
		system("cls");
		switch (choice)
		{
		case 1:
			int countryChoice;
			displayCountry();
			cout << endl;
			spaces(20); cout << "Enter an option: ";
			cin >> countryChoice;

			while (countryChoice > 4 || countryChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 4! Please try again!" << RESET;

			}
			system("cls");
			switch (countryChoice)
			{
			case 1:
				flightChoiceItaly();
				break;
			case 2:
				flightChoiceFrance();
				break;
			case 3:
				flightChoiceGermany();
				break;
			case 4:
				exit(0);
				break;
			}
			break;
		case 2:
			exit(0);
			break;
		}
	}
}

int main()
{
	printMenu();
}

