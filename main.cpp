//Created By Quintan M. Calvert on 19 October 2022

// Locker Program: The Locker program will show the current person assigned to each of twenty five lockers.
//You will also be able to reassign people to a specific locker.

#include <iostream> //Header files
#include <iomanip>
#include <string>

using namespace std;    // The standard Namespace

struct lockerType   // This is the structure definition. I use an array of these structs to store the data about each locker.
{
    string firstName = "";  //Each locker has three properties, the first name of the user, last name, and thier phone number, should they need contacted.
    string lastName= "";
    string phoneNum = "";
};

//Function prototypes, the definitions follow main. Both of these functions are vital to the program.

int assign(lockerType param[]); // This function is used to assign a person to a certain locker. Lockers are numbered 1 thorugh 25, to correspond with the 0 - 24 indexes of the array
void print(lockerType param[]); // This function prints all of the occupants of the lockers, that is, thier names and phone numbers.

//Begin Main Routine

int main()
{
    lockerType allLockers[25];  //This is the array of structs. The array type is lockerType. Each of the 25 componets has three components of its own, as described by lockerType.
    
    char userIn;    //Used to collect user input and control the program execution, stop the program, change assingments, etc.
    
    print(allLockers);  //Function call. The entire array allLockers is passed by reference (The only way to pass an array to a function) to the function print.
    
    cout << "Press any key to assign a locker or Q to quit: ";  //User control mechanism. Used to allow user to change locker assignments or exit the program.
    cin >> userIn;  //collect user input.
    cout << endl;
    
    userIn = toupper(userIn);   //Safeguard so if a lowercase character is entered, the checker for 'Q' for quit is not undermined.
    
    while (userIn != 'Q')   //Heart of the program, contiunes operation until the user wishes to quit.
    {
        assign(allLockers); //Assign a new locker, then print the current assingments, and repeat as the user sees fit.
        print(allLockers);
        
        cout << "Press any key to continue assigning lockers or Q to quit: ";   //Continuation of earlier code, part of loop. Neccesary for input to be accepted repeatedly.
        cin >> userIn;
        userIn = toupper(userIn);   //Safeguard
    }
    
    return 0;
}

//End Main Routine

int assign(lockerType param[])  //The assign person to a certain locker function. Defined here.
{
    int num;    //Locker number, 1 - 25, representing 0 - 24 (Augmented)
    
    cout << "Which Locker would you like to reassign? ";    //Lets user choose locker number to edit assignment of, gets input.
    cin >> num;
    
    cout << "Enter First Name: ";   // Input data of new person assigned to that locker.
    cin >>  param[(num - 1)].firstName;
    
    cout << "Enter Last Name: ";
    cin >>  param[(num - 1)].lastName;
    
    cout << "Enter Phone Number: ";
    cin >>  param[(num - 1)].phoneNum;

    return 0;
}

void print(lockerType param[])  //The print function
{
    int cnt = 0;    //used to manage loop, maintain bounds of the array, and add space to keep formatting aligned.
    
    cout << "Here are all of the current Locker Assignments:" << endl << endl;
    
    cout << "Locker #" << endl;
    
    while (cnt < 25)    //Loop used to output the entire array, member by member, now augmented with data inside.
    {
        if (cnt < 9)    //Used to add a space to keep double digit and single digit number outputs aligned.
            cout << " ";
        
        cout << "     " << (cnt + 1) << ": ";   //Augments the count of the array, ie. 0 -24 becomes 1-25, more intuitive.

        cout << param[cnt].firstName << " " << param[cnt].lastName << " ";
        
        cout << param[cnt].phoneNum;    //Traditional loop management
        cout << endl;
        cnt++;
        

    }
    
    cnt = 0;
    
    cout << endl;
    
    return;
}
