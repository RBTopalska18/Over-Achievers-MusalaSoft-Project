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
#define PURPLE  "\033[1;35m"

//BACK END




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
    spaces(20);  cout << "||                   3.Flight time                   ||" << endl;
    wait();
    spaces(20);  cout << "||                   4. Exit                         ||" << endl;
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
    spaces(20);  cout << "||                   1.Italy                         ||" << endl;
    wait();
    spaces(20);  cout << "||                   2.France                        ||" << endl;
    wait();
    spaces(20);  cout << "||                   3.Germany                       ||" << endl;
    wait();
    spaces(20);  cout << "||                   4. Exit                         ||" << endl;
    wait();
    spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
    wait();
    cout << endl;
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

            while (countryChoice > 2 || countryChoice < 1)
            {
                cout << endl;
                cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;

            }
            system("cls");
            switch (countryChoice)
            {
            case 1:
                int flightChoice;
                displayFlightsMenu();
                cout << endl;
                spaces(20); cout << "Enter an option: ";
                cin >> flightChoice;

                while (flightChoice > 2 || flightChoice < 1)
                {
                    cout << endl;
                    cout << RED << "You have to enter a number between 1 and 2! Please try again!" << RESET;

                }
                system("cls");
                switch (flightChoice)
                {
                    case 1:
                        //function that display all flights to Italy/France/Germany
                        break;
                    case 2:
                        //function that display cheaper flights to Italy/France/Germany
                        break;
                    case 3:
                        //function that display choosen time flights to Italy/France/Germany
                        break;
                }
                
                break;
            case 2:
                displayFlightsMenu();
                break;
            case 3:
                displayFlightsMenu();
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
 
}

