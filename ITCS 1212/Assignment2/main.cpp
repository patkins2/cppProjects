/*
Paul Atkins
Assignment #2
ATM Machine
11/2015
*/

/*
Pseudo-Code

An ATM machine with input validation
Program has seven functions to run
There are two menus. The first menu is before login
and will prompt user to login, create account or quit program

Create account writes username and password to a txt file
Login function reads through text file and matches
information to grant login

After login there are options to deposit funds, withdraw
or show balance. All of these functions use a global variable.
All of these functions validate input against that variable.

*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//FUNCTION PROTOTYPES
void mainMenu(); // MAIN MENU
void createAccount (); // WRITE NEW ACCOUNTS TO FILE
void login(); // LOGIN VALIDATION AND FILE SEARCH
void loginMenu(); // MENU FOR SUCCESSFUL LOGIN
void depositAmount(); // DEPOSIT FUNDS TO ACCOUNT
void withdrawAmount(); // WITHDRAW FUNDS FROM ACCOUNT
void displayAmount(); // DISPLAY ACCOUNT BALANCE

//GLOBAL VARIABLE FOR ACCOUNT BALANCE
float accountBalance;


int main()
{
    //CALL TO MAINMENU FUNCTION
    //MAINMENU FUNCTION WILL CALL OTHER
    //FUNCTIONS AS NEEDED
    mainMenu();

    return 0;
}

void mainMenu() // MAIN MENU BEFROE SUCCESSFUL LOGIN
{
    char choice; // container for user choice

    /*
    // MENU FOR USER TO MAKE CHOICE
    // EACH OPTION WILL CALL FUNCTION
    // ACCORDING TO CHOICE
    */

    cout << "\nPlease Make A Selection \n";
    cout << "C Create Account \n";
    cout << "L Login to Account \n";
    cout << "Q Quit Program \n";
    cout << "Selection: ";
    cin >> choice;

    // INPUT VALIDATION LOOP
    // USER CAN ONLY SELECT C L OR Q
    while (choice != 'c' && choice != 'C' && choice != 'L' && choice != 'l' && choice != 'q' && choice!= 'Q')
    {
        cout << "Invalid Choice!" << endl;
        cout << "Please make a selection" << endl;
        cin >> choice;
    }
    //CALL TO CREATE ACCOUNT FUNCTION
    if (choice == 'C' || choice == 'c')
    {
        createAccount();
    }
    // CALL TO LOGIN FUNCTION
    else if (choice == 'L' || choice == 'l')
    {
        login();
    }
    // EXIT PROGRAM
    else if (choice == 'Q' || choice == 'q')
    {
        cout << "Goodbye";
        exit(0);
    }
}
void createAccount() // CREATE ACCOUNT AND WRITE TO FILE
{
    fstream outputFile; // CREATE FILE OBJECT
    outputFile.open("TOPSECRETBANKINFO.txt", ios::out | ios::app);
    /*
        OPEN FILE FOR ACCOUNT
        FILE CAN ONLY BE WRITTEN TO FROM HERE
        ALL DATA WILL BE ADDED TO END OF FILE
        DATA WILL BE FORMATTED VIA ENTRY
        FORMAT WILL BE USERNAME PASSWORD NEWLINE
    */

    string username; // CONTAINER FOR USERNAME
    string password; // CONTAINER FOR PASSWORD

    cout << "USER ID: ";
    cin >> username;
    outputFile << username; // WRITE USERNAME TO FILE

    cout << "\nPASSWORD: ";
    cin >> password;
    outputFile << password << endl; // WRITE PASSWORD TO FILE

    cout << "\nAccount Created!" << endl; // ALERT USER TO SUCCESSFUL CREATION

    mainMenu(); //RETURN TO MAINMENU FUNCTION
}

/*
//
//  FUNCTION ASKS USER FOR WITHDRAW AMOUNT
//  AMOUNT IS VALIDATED AGAINST ACCOUNT BALANCE
//
*/
void withdrawAmount() // WITHDRAW FUNDS FROM ACCOUNT
{
    float withdraw; // CONTAINER FOR USER ENTRY
    cout << "Enter Withdrawal Amount: ";
    cin >> withdraw;

    while (withdraw > accountBalance) // INPUT VALIDATION FOR WITHDRAWAL
    {
        cout << "Withdrawal Exceeds Balance"<<endl;
        cout << "Enter Withdrawal Amount: ";
        cin >> withdraw;
    }
    while (withdraw < 0) //INPUT VALIDATION FOR WITHDRAWAL
    {
        cout << "Invalid Amount" << endl;
        cout << "Enter Withdrawal Amount: ";
        cin >> withdraw;
    }

    accountBalance = accountBalance - withdraw; // WITHDRAW FROM BALANCE

    loginMenu(); // RETURN TO MENU
}
/*
// *****WARNING******
//  DEPOSIT AMOUNT USES GLOBAL VARIABLE
*/

void depositAmount() // DEPOSIT FUNDS TO ACCOUNT
{
    float deposit; // CONTAINER FOR DEPOSIT
    cout << "Enter Deposit Amount: ";
    cin >> deposit;
    accountBalance = accountBalance + deposit;//ADD FUNDS TO ACCOUNT BALANCE

    loginMenu(); // RETURN TO MENU
}
void displayAmount() // DISPLAY ACCOUNT BALANCE
{
    cout << "Account balance is $" << accountBalance << endl;
    loginMenu(); // RETURN TO MENU

}
/*
 ********FUNCTION FOR USER LOGIN**********
    FUNCTION OPENS FILE WITH USER DATA
    ASKS USER FOR NAME AND PASSWORD
    SEARCH FILE FOR DATA
    GRANT OR DENY ACCESS BASED ON SEARCH

*/
void login()
{
    fstream inputFile;
    inputFile.open("TOPSECRETBANKINFO.txt", ios::in); // open file for data read

    string username; //to search for username
    string password; // to search for password

    cout << "Username: " << endl; // ask user for username
    cin >> username;

    cout << "Password: " << endl; // ask user for password
    cin >> password;

    username = username+password; //concatenate for search

    string searchterm; // string for username and password lookup

    bool loginValid = false; // flag for found username password

    while(getline(inputFile, searchterm)) // loop for searching file
    {
        if(searchterm == username) // compare search to username and password
        {
            loginValid = true; // found username and password combo
            break; //end loop if username and password found
        }

    }

    inputFile.close(); // close file
    if(loginValid)//for valid username and password
        {
            cout << "\nAccess Granted!\n"; //successful login
            loginMenu(); // goto login menu
        }

    else
        {
            cout << "\nInvalid Login!\n"; // bad login
            mainMenu(); // return to main menu
        }
}
/*
//      MENU FOR SUCCESSFUL LOGIN
//
//      DISPLAY OPTIONS FOR WITHDRAW
//      DEPOSIT OR DISPLAY BALANCE
//
*/

void loginMenu()
{
    char choice; // CONTAINER FOR USER CHOICE
    cout << "\nPlease Make Selection: \n";
    cout << "W Withdraw" << endl;
    cout << "D Deposit" << endl;
    cout << "S Show Balance" << endl;
    cout << "Q Quit" << endl;
    cout << "Selection: ";
    cin >> choice;

    // INPUT VALIDATION FOR MENU
    while (choice != 'W' && choice != 'w' && choice != 'D' && choice != 'd' && choice != 'S' && choice != 's' && choice != 'Q' && choice != 'q')
    {
        cout << "Invalid Selection";
        cout << "Selection: ";
        cin >> choice;
    }

    if (choice == 'W' || choice == 'w') // CALL TO WITHDRAW FUNCTION
    {
        withdrawAmount();
    }
    else if (choice == 'D' || choice == 'd') // CALL TO DEPOSIT FUNCTION
    {
        depositAmount();
    }
    else if (choice == 'S' || choice == 's') // CALL TO DISPLAY BALANCE FUNCTION
    {
        displayAmount();
    }
    else if (choice == 'Q' || choice == 'q') // EXIT PROGRAM
    {
        cout << "Goodbye \n";
        exit (0);
    }
}
