// Ez Racancoj 
// This program allows the user to select from different oporations from a text menu
// and keeps track of their fitness bassed on the information given

#include <iostream>
#include <string>
using namespace std;

void getUserInfo(string& name, string& gender, int& age)// To get the users basic information 
{
    //name
    cout << "Please enter your name: " << endl;
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
}


void showMenu(int uInput, int display, int quit)// To display the text menu
{
    // Menu Display
    cout << "Enter " << uInput << " to fill out your information" << endl;
    cout << "Enter " << display << " to display your information" << endl;
    cout << "Enter " << quit << " to quit" << endl;
}
int getUserChoice(int& input) // To get the users choice from the text menu
{
    cout << "Please choose one of the options" << endl;
    cin >> input;

    while (cin.fail()) // Check if the user input is valid
    {
        cout << "Input fail: " << cin.fail() << endl;
        cout << "Please enter a valid numeric value corresponding to a menu option: " << endl;
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
    }
    return input;
}
void exerciseInfo(double& weight, string& exerciseType, double& exerciseTime) // To get the users exercise infromation 
{
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

}
void displayInfo(string name, string gender, int age, double weight, string exerciseType, double exerciseTime, bool information)
{
    //chaeck if information was filled out

        // Print the user’s information to the console
    cout << '\n';//separate from menu
    cout << name << " (" << gender << ", " << age << " years)" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "Exercise: " << exerciseType << " (" << exerciseTime << " minutes)" << endl;//print ecercise information
    cout << '\n';//separate from menu

}
int main()
{
    const int USER_INPUT = 1;
    const int DISPLAY = 2;
    const int QUIT = 3;

    int input = 0; // Initialize input to a non-menu value
    string exerciseType;
    string gender;
    string name;
    int age = 0;
    bool information = false;
    double weight;
    double exerciseTime;

    getUserInfo(name, gender, age);

    do
    {
        showMenu(USER_INPUT, DISPLAY, QUIT);

        getUserChoice(input);

        //system("cls");

        switch (input)
        {
        case USER_INPUT:
            exerciseInfo(weight, exerciseType, exerciseTime);
            information = true;
            break;
        case DISPLAY:
            if (information) // Check if the user chose to the option to enter their exercise information
            {
                displayInfo(name, gender, age, weight, exerciseType, exerciseTime, information);
                break;
            }
            else // If they di not display a message telling the user that there is no informstion to display 
            {
                cout << "No information to be displayed" << endl;
            }

        case QUIT: // To quit the program 
            break;

        default: // If the users input does not match an option on the text menu
            cout << "Invalid input. Please enter a valid menu option." << endl;
        }

    } while (input != QUIT); // Will loop as long as the user input does not equal the value stored in the QUIT constant 

    return 0;
}
