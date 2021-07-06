/*#include <iostream>
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

void displayPlane()
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
    spaces(20);  cout << "||                   1.Reserve ticke  t                ||" << endl;
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
    spaces(20);  cout << "||                   5. Exit                         ||" << endl;
    wait();
    spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
    wait();
    cout << endl;
}
int main()
{
    welcome();
    displayFlightsMenu();
}*/

#include <nanodbc.h>
#include <iostream>
#include <exception>

using namespace std;

int main() try
{
    auto const connstr = NANODBC_TEXT("Driver={ODBC Driver 17 for SQL Server};Server=(localdb)\\MSSQLLocalDB;Database=BikeStores;Trusted_Connection=yes;");
    nanodbc::connection conn(connstr);

    nanodbc::statement stmt(conn);

    nanodbc::prepare(stmt, R"(
            SELECT TOP (1000) [customer_id]
                  ,[first_name]
                  ,[last_name]
                  ,[phone]
                  ,[email]
                  ,[street]
                  ,[city]
                  ,[state]
                  ,[zip_code]
              FROM [BikeStores].[sales].[customers]
            WHERE customer_id > ? AND customer_id < ?
    )");

    int id1 = 4;
    int id2 = 8;
    stmt.bind(0, &id1);
    stmt.bind(1, &id2);

    auto result = nanodbc::execute(stmt);

    while (result.next())
    {
        cout << result.get<int>("customer_id", -1)
            << ", "
            << result.get<nanodbc::string>("first_name", "!")
            << ", "
            << result.get<nanodbc::string>("last_name", "!")
            << ", "
            << result.get<nanodbc::string>("phone", "!")
            << endl;
    }

    return EXIT_SUCCESS;
}
catch (std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}