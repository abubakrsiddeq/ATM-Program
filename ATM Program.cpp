// Color codes:
#define RESET "\033[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main() {
    string correct_pin = "5678";
    string pass = "";
    char ch;
    bool access_granted = false;

    while (!access_granted) {
        pass = "";
        cout << CYAN << "Please Enter your PIN:\n " << RESET;
        ch = _getch();

        while (ch != 13) {  // character 13 is enter
            pass.push_back(ch);
            cout << MAGENTA << "*" << RESET;
            ch = _getch();
        }

        if (pass == correct_pin) {
            access_granted = true;
            cout << MAGENTA << "\n Access Granted: P\n" << RESET << endl;
        }
        else {
            cout << RED << "\n Incorrect PIN. Please try again.\n" << RESET << endl;
        }
    }

    int choice;
    double balance = 10000, deposit, withdraw;
    cout << MAGENTA << "Welcome to ATM Machine:\n " << RESET << endl;
    do {
        cout << CYAN << "\n\t    --------------Menu------------------ ";
        cout << "\n\t    |                                   |";
        cout << "\n\t    |     1. Check Your Balance         |";
        cout << "\n\t    |     2. Deposit Amount             |";
        cout << "\n\t    |     3. Withdraw Now               |";
        cout << "\n\t    |     4. Quit/Exit                  |";
        cout << "\n\t    |                                   |";
        cout << "\n\t    -------------------------------------" << RESET;

        cout << MAGENTA << "\nEnter Your Choice: " << RESET;
        cin >> choice;

        switch (choice) {
        case 1:
            cout << CYAN << "\n Your Current Balance is:  " << balance << " Rupees" << RESET;
            break;
        case 2:
            cout << RED << "Please Enter Your Deposit Amount: ";
            cin >> deposit;
            balance += deposit;
            cout << CYAN << "\n Your Current Balance After Deposit is: " << balance << " Rupees" << RESET;
            break;
        case 3:
            cout << CYAN << "\n Enter your Withdraw Amount: " << RESET;
            cin >> withdraw;
            if (withdraw <= balance) {
                balance -= withdraw;
                cout << CYAN << "\n You have successfully Withdrawn: " << withdraw << " Rupees" << RESET << endl;
                cout << "\n Now your current Balance is: " << balance << " Rupees" << endl;
            }
            else {
                cout << CYAN << "\n Your Balance is Insufficient: " << RESET << endl;
            }
            break;
        case 4:
            cout << CYAN << "\n Thank You for using this ATM. " << RESET << endl;
            break;
        default:
            cout << CYAN << "\n Invalid Choice! Please Enter the Correct choice. " << RESET << endl;
            break;
        }
    } while (choice != 4);

    cout << CYAN << "Thank You For Using the ATM: " << RESET << endl;

    return 0;
}