//Ez Racancoj this program allows the user to select from different oporation 
//and keeps track of their fitness bassed on the information given 
//due date 10/3.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int QUIT = 0;
    const int NAME = 1;
    const int GENDER = 2;
    const int AGE = 3;
    const int WEIGHT = 4;
    const int EX_TYPE = 5;
    const int EX_TIME = 6;
    const int DISPLAY = 7;

    int input = -1; // Initialize input to a non-menu value
    string exerciseType;
    string gender;
    string name;
    int age = 0; // Initialize age and weight to default values
    double weight = 0.0;
    double exerciseTime = 0.0;

    cout << "Please choose one of the options" << endl;
    cout << '\n';

    do
    {
        cout << "Enter 1 to fill out your name" << endl;
        cout << "Enter 2 to fill out your gender" << endl;
        cout << "Enter 3 to fill out your age" << endl;
        cout << "Enter 4 to fill out your weight" << endl;
        cout << "Enter 5 to fill out what type of exercise you did today" << endl;
        cout << "Enter 6 to fill out how much time you exercised today" << endl;
        cout << "Enter 7 to display your information" << endl;
        cout << "Enter 0 to quit" << endl;

        cin >> input;

        while (cin.fail()) // Check if the user input is valid
        {
            cout << "Input fail: " << cin.fail() << endl;
            cout << "Please enter a valid numeric value: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> input;
        }

        switch (input)
        {
        case NAME:
            cout << "Please enter your name: " << endl;
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, name);
            break;
        case GENDER:
            cout << "Please enter your gender: " << endl;
            cin >> gender;
            break;
        case AGE:
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
            break;
        case WEIGHT:
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
            break;
        case EX_TYPE:
            cout << "Please enter what type of exercise you did: " << endl;
            cin.ignore(); // Clear the newline character from the buffer
            getline(cin, exerciseType);
            break;
        case EX_TIME:
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
            break;
        case DISPLAY:
            // Print the user’s information to the console
            cout << '\n';
            cout << name << " (" << gender << ", " << age << " years)" << endl;
            cout << "Weight: " << weight << " kg" << endl;
            cout << "Exercise: " << exerciseType << " (" << exerciseTime << " minutes)" << endl;
            cout << '\n';
            break;
        case QUIT:
            break;
        default:
            cout << "Invalid input. Please enter a valid menu option." << endl;
        }

    } while (input != QUIT);

    return 0;
}