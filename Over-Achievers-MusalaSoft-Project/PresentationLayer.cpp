#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <sstream> 
#include <conio.h>
#include <chrono>
#include <thread>
#include <nanodbc.h>
#include <exception>
#include <algorithm>
#include <cstring>
#include "DataLayer.h"

using namespace std;

#define RESET "\033[0m"
#define RED "\033[1;91m" 
#define YELLOW "\033[1;93m"  
#define PURPLE "\033[1;95m"
#define CYAN "\033[1;96m"
#define GREEN "\033[1;92m"
#define BLUE "\033[1;94m"
#define WHITE "\033[2;37m"
#define ANIMATION_ENABLED true

void spaces(unsigned short int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " ";
	}
}

void wait(int delay = 200)
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

void displayTicketOutMenu()
{
	cout << endl;
	wait(500);
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "||                  _____MENU_____                  ||" << RESET << endl;
	wait();
	spaces(20);  cout << "||                                                   ||" << endl;
	wait();
	spaces(20);  cout << "||                   1.Reserve another ticket        ||" << endl;
	wait();
	spaces(20);  cout << "||                   2. Exit                         ||" << endl;
	wait();
	spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
	wait();
	cout << endl;
}

void flightChoiceItaly()
{
	int ticketOutChoice;
	int flightChoice;
	double priceItaly;
	string destinationItaly;
	string timeItaly;
	int ticketChoice;
	displayFlightsMenu();
	cout << endl;
	spaces(20); cout << "Enter an option: ";
	cin >> flightChoice;

	while (flightChoice > 5 || flightChoice < 1)
	{
		cout << endl;
		cout << RED << "You have to enter a number between 1 and 5! Please try again!" << RESET;
		flightChoice = readInt();
	}
	system("cls");
	switch (flightChoice)
	{
	case 1:
		if (printAllFlightsFromItaly())
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			while (ticketChoice > 20 || ticketChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 20! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceItaly();
				break;
			case 2:
				exit(0);
				break;
			}
		}

		break;
	case 2:
		cout << "Enter the biggest price you can allow:";
		cin >> priceItaly;
		cout << endl;
		if (printCheaperFlightsFromItaly(priceItaly))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceItaly();
				break;
			case 2:
				exit(0);
				break;
			}
		}

		break;
	case 3:
		displayDestinationForItaly();
		cout << endl;
		cout << "Type the destination, not the number: ";
		cin >> destinationItaly;
		cout << endl;
		if (printFlightsFromItalyToDestination(destinationItaly))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceItaly();
				break;
			case 2:
				exit(0);
				break;
			}
		}

		break;
	case 4:
		cout << "Enter the time you want to fly: ";
		cin >> timeItaly;
		cout << endl;
		if (printFlightsTimeForItaly(timeItaly))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceItaly();
				break;
			case 2:
				exit(0);
				break;
			}
		}


		break;
	case 5:
		exit(0);
		break;
	}
}

void flightChoiceFrance()
{
	int ticketOutChoice;
	int flightChoice;
	int ticketChoice;
	double priceFrance;
	string destinationFrance;
	string timeFrance;
	displayFlightsMenu();
	cout << endl;
	spaces(20); cout << "Enter an option: ";
	cin >> flightChoice;

	while (flightChoice > 5 || flightChoice < 1)
	{
		cout << endl;
		cout << RED << "You have to enter a number between 1 and 5! Please try again!" << RESET;
		flightChoice = readInt();
	}
	system("cls");
	switch (flightChoice)
	{
	case 1:
		if (printAllFlightsFromFrance())
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cin >> ticketChoice;
			while (ticketChoice > 20 || ticketChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 20! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceFrance();
				break;
			case 2:
				exit(0);
				break;
			}
		}

		break;
	case 2:
		cout << "Enter the biggest price you can allow:";
		cin >> priceFrance;
		cout << endl;
		if (printCheaperFlightsFromFrance(priceFrance))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceFrance();
				break;
			case 2:
				exit(0);
				break;
			}
		}
		break;
	case 3:
		cout << endl;
		cout << "Type the destination, not the number: ";
		displayDestinationForFrance();
		cin >> destinationFrance;
		cout << endl;
		if (printFlightsFromFranceToDestination(destinationFrance))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceFrance();
				break;
			case 2:
				exit(0);
				break;
			}
		}
		break;
	case 4:
		cout << "Enter the time you want to fly: ";
		cin >> timeFrance;
		cout << endl;
		if (printFlightsTimeForFrance(timeFrance))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceFrance();
				break;
			case 2:
				exit(0);
				break;
			}
		}

		break;
	case 5:
		exit(0);
		break;
	}
}

void flightChoiceGermany()
{
	int ticketOutChoice;
	int flightChoice;
	int ticketChoice;
	double priceGermany;
	string destinationGermany;
	string timeGermany;
	displayFlightsMenu();
	cout << endl;
	spaces(20); cout << "Enter an option: ";
	cin >> flightChoice;

	while (flightChoice > 5 || flightChoice < 1)
	{
		cout << endl;
		cout << RED << "You have to enter a number between 1 and 5! Please try again!" << RESET;
		flightChoice = readInt();
	}
	system("cls");
	switch (flightChoice)
	{
	case 1:
		if (printAllFlightsFromGermany())
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			while (ticketChoice > 20 || ticketChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 20! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceGermany();
				break;
			case 2:
				exit(0);
				break;
			}

		}
		break;
	case 2:
		cout << "Enter the biggest price you can allow:";
		cin >> priceGermany;
		cout << endl;
		if (printCheaperFlightsFromGermany(priceGermany))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceGermany();
				break;
			case 2:
				exit(0);
				break;
			}
		}
		break;
	case 3:
		displayDestinationForGermany();
		cout << endl;
		cout << "Type the destination, not the number: ";
		cin >> destinationGermany;
		cout << endl;
		if (printFlightsFromGermanyToDestination(destinationGermany))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceGermany();
				break;
			case 2:
				exit(0);
				break;
			}
		}
	case 4:
		cout << "Enter the time you want to fly: ";
		cin >> timeGermany;
		cout << endl;
		if (printFlightsTimeForGermany(timeGermany))
		{
			exit(0);
		}
		else
		{
			cout << endl;
			cout << "Enter the number of the ticket: ";
			cin >> ticketChoice;
			insertTicket(ticketChoice);
			displayTicketOutMenu();
			cout << endl;
			spaces(20); cout << "Enter the option you want: ";
			cin >> ticketOutChoice;
			while (ticketOutChoice > 2 || ticketOutChoice < 1)
			{
				cout << endl;
				cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
				ticketChoice = readInt();
			}
			switch (ticketOutChoice)
			{
			case 1:
				flightChoiceGermany();
				break;
			case 2:
				exit(0);
				break;
			}
		}

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
	while (choice != 4) {
		cout << endl;
		displayTicketMenu();
		cout << endl;
		spaces(20); cout << "Enter an option: ";
		cin >> choice;

		while (choice > 2 || choice < 1)
		{
			cout << endl;
			cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;
			choice = readInt();
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
				countryChoice = readInt();
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