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
#include <algorithm>
#include <cstring>

using namespace std;

int readInt(std::istream& input = std::cin, std::ostream& output = std::cout)
{

	int num;

	while (!(input >> num))
	{
		input.clear();
		input.ignore(INT_MAX, '\n');
		output << endl;
		//output << MSG_INVALID_SYMBOL_TRY_AGAIN;
	}

	return num;

}

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

int printFlightsFromItalyToDestination(string arrivalDestination)
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
		stmt.bind(0, arrivalDestination.c_str());
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

int printFlightsFromFranceToDestination(string arrivalDestination)
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
		stmt.bind(0, arrivalDestination.c_str());
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

int printFlightsFromGermanyToDestination(string arrivalDestination)
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
		stmt.bind(0, arrivalDestination.c_str());
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

int printFlightsTimeForFrance(string timeFrance)
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
              WHERE  ArrivalDestination = ? AND Time = ?
              
    )");
		string name1 = "France,Paris";
		stmt.bind(0, name1.c_str());
		stmt.bind(1, timeFrance.c_str());
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
	catch (...)
	{
		cout << "There's not flight for " << timeFrance << "!" << endl;
		return EXIT_FAILURE;
	}
}

int printFlightsTimeForItaly(string timeItaly)
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
              WHERE  ArrivalDestination = ? AND Time = ?
              
    )");
		string name1 = "Italy,Venice";
		stmt.bind(0, name1.c_str());
		stmt.bind(1, timeItaly.c_str());
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
	catch (...)
	{
		cout << "There's not flight for " << timeItaly << "!" << endl;

		return EXIT_FAILURE;
	}
}

int printFlightsTimeForGermany(string timeGermany)
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
              WHERE  ArrivalDestination = ? AND Time = ?
              
    )");
		string name1 = "Germany,Berlin";
		stmt.bind(0, name1.c_str());
		stmt.bind(1, timeGermany.c_str());
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
	catch (...)
	{
		cout << "There's not flight for " << timeGermany << "!" << endl;
		return EXIT_FAILURE;
	}
}

int insertTicket(int countryId) {
	try {
		auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=AirPort;Trusted_Connection=yes;");
		nanodbc::connection conn(connstr);

		nanodbc::statement stmt(conn);

		nanodbc::prepare(stmt, "insert into AirPort.dbo.Tickets (CountryId) values (?);");
		stmt.bind(0, &countryId);
		execute(stmt);


		return EXIT_SUCCESS;
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
		return EXIT_FAILURE;
	}
}