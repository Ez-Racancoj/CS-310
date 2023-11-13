//Ez Racancoj this program allows the user to select from different oporation 
//and keeps track of their fitness bassed on the information given 
//due date 10/3.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int USER_INPUT = 1;
    const int DISPLAY = 2;
    const int QUIT = 3;

    int input = 0; // Initialize input to a non-menu value
    string exerciseType;
    string gender;
    string name;
    int age;
    bool information = false;
    double weight;
    double exerciseTime;

    //name
    cout << "Please enter your name: " << endl;
    //cin.ignore(); // Clear the newline character from the buffer
    getline(cin, name);

    //gender
    cout << "Please enter your gender: " << endl;
    cin >> gender;

    //age
    cout << "Please enter your age as an integer: " << endl;
    cin >> age;
    while (cin.fail()) // Check if the user input is valid
    {
        cout << "Input fail: " << cin.fail() << endl;
        cout << "Please enter a valid numeric value for age: " << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> age;
    }

    do
    {
        // Menu Display
        cout << "Please choose one of the options" << endl;
        cout << "Enter " << USER_INPUT << " to fill out your information" << endl;
        cout << "Enter " << DISPLAY << " to display your information" << endl;
        cout << "Enter " << QUIT << " to quit" << endl;

        cin >> input;

        while (cin.fail()) // Check if the user input is valid
        {
            cout << "Input fail: " << cin.fail() << endl;
            cout << "Please enter a valid numeric value corresponding to a menu option: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
        }

        switch (input)
        {
        case USER_INPUT:
            cout << "Please enter your weight in kg: " << endl;
            cin >> weight;
            while (cin.fail()) // Check if the user input is valid
            {
                cout << "Input fail: " << cin.fail() << endl;
                cout << "Please enter a valid numeric value for weight: " << endl;
                cin.clear();
                cin.ignore(100, '\n');
                cin >> weight;

               
            }
            cout << "Please enter what type of exercise you did: " << endl;
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, exerciseType);

            cout << "Please enter the time you exercised in minutes: " << endl;
            cin >> exerciseTime;
            while (cin.fail()) // Check if the user input is valid
            {
                cout << "Input fail: " << cin.fail() << endl;
                cout << "Please enter a valid numeric value for exercise time: " << endl;
                cin.clear();
                cin.ignore(100, '\n');
                cin >> exerciseTime;
            }
            information = true;
            break;
        case DISPLAY:
            //chaeck if information was filled out
            if (information)
            {
                // Print the user’s information to the console
                cout << '\n';//separate from menu 
                cout << name << " (" << gender << ", " << age << " years)" << endl;
                cout << "Weight: " << weight << " kg" << endl;
                cout << "Exercise: " << exerciseType << " (" << exerciseTime << " minutes)" << endl;//print ecercise information
                cout << '\n';//separate from menu 
            }
            else
            {
                cout << "No fitness data to print" << endl;
            }
            break;

        case QUIT:
            break;

        default:
            cout << "Invalid input. Please enter a valid menu option." << endl;
        }

    } while (input != QUIT);

    return 0;
}
