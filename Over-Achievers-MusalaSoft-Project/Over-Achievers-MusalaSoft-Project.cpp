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
    spaces(20); cout << WHITE << "                          NOTE                         " << RESET << endl;
    spaces(20); cout << WHITE << "                          LIST                         " << RESET << endl;
    spaces(20); cout << YELLOW << "*******************************************************" << RESET << endl;

}
void displayMainMenu()
{
    cout << endl;
    wait(500);
    spaces(20);  cout << YELLOW << "_______________________________________________________" << RESET << endl;
    wait();
    spaces(20);  cout << "||                                                   ||" << endl;
    wait();
    spaces(20);  cout << YELLOW << "||                  _____MENU_____                   ||" << RESET << endl;
    wait();
    spaces(20);  cout << "||                                                   ||" << endl;
    wait();
    spaces(20);  cout << "||                   1. Last Note                    ||" << endl;
    wait();
    spaces(20);  cout << "||                   2. All Notes                    ||" << endl;
    wait();
    spaces(20);  cout << "||                   3. Add Note                     ||" << endl;
    wait();
    spaces(20);  cout << "||                   4. Delete Note                  ||" << endl;
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
    displayMainMenu();
}
