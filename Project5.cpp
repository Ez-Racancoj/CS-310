// Ez Racancoj this program keeps track of the users weekly fitness iformation
//using functions to allow the user to select from different oporations on a text menu
//and arrays to store the weekly information


#include <iostream>
#include <string>
using namespace std;

const int ONE_WEEK = 7;//constant to compare the array size to

struct FitnessData//used to group the vars for the exersice info
{
    double weight;
    string exerciseType;
    double exerciseTime;
};


void getUserInfo(string& name, string& gender, int& age)//gets the users basic information
{
    cout << "Please enter your name: " << endl;
    getline(cin, name);//store user input in the name string using getline so white space can be present in input

    cout << "Please enter your gender: " << endl;
    cin >> gender; //store user input in the gender string using cin since white space should not be included

    cout << "Please enter your age as an integer: " << endl;
    cin >> age;

    while (cin.fail()) // Check if the user input is valid
    {
        cout << endl;
        cout << "Input fail: " << cin.fail() << endl;
        cout << "Please enter a valid numeric value for age: " << endl;//error message for user
        cin.clear();//clear error flags
        cin.ignore(100, '\n');//ignore 100 characters or untill the new line
        cin >> age;//attempt to store age in the age int again
    }

}

void showMenu(int uInput, int display, int printHistory, int quit)//displays test menu usings cout statements
{
    cout << "Enter " << uInput << " to fill out your information" << endl;
    cout << "Enter " << display << " to display your information" << endl;
    cout << "Enter " << printHistory << " to print history" << endl;
    cout << "Enter " << quit << " to quit" << endl;
}

int getUserChoice(int& input)//gets the users choice of operation
{
    cout << "Please choose one of the options" << endl;
    cin >> input;

    while (cin.fail()) // Check if the user input is valid
    {
        cout << "Input fail: " << cin.fail() << endl;
        cout << "Please enter a valid numeric value corresponding to a menu option: " << endl;//error message for user
        cin.clear();
        cin.ignore(100, '\n');
        cin >> input;
    }
    return input;//returns the users choice
}
void exerciseInfo(FitnessData history[], int& historySize)//gets the users ecerise information
{
    if (historySize < ONE_WEEK)//checks if the size of the array in less then 7
    {
        cout << "Please enter your weight in kg: " << endl;
        cin >> history[historySize].weight;//attempts to store user input in the weight int

        while (cin.fail())//checks if the users input is valid
        {
            cout << "Input fail. Please enter a valid numeric value for weight: " << endl;//error  message for user
            cin.clear();
            cin.ignore(100, '\n');
            cin >> history[historySize].weight;//attampts to store in the weight int again
        }

        cout << "Please enter what type of exercise you did: " << endl;
        cin.ignore();
        getline(cin, history[historySize].exerciseType);//stores input in the exerciseType var 

        cout << "Please enter the time you exercised in minutes: " << endl;
        cin >> history[historySize].exerciseTime;//attemps to store input in the exerciseTime var

        while (cin.fail())
        {
            cout << "Input fail. Please enter a valid numeric value for exercise time: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> history[historySize].exerciseTime;//reattemps to store input in the exerciseTime var
        }

        historySize++;//increment the historySize var to match the number of elements in the history array
    }
    else {
        // Remove the oldest fitness info
        for (int i = 0; i < ONE_WEEK - 1; i++)
        {
            history[i] = history[i + 1]; // Shift each element to the left to remove the oldest user input
        }

        // ask for new input and store it in the array
        cout << "Please enter your weight in kg: " << endl;
        cin >> history[ONE_WEEK - 1].weight;
        while (cin.fail())
        {
            cout << "Input fail. Please enter a valid numeric value for weight: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> history[ONE_WEEK - 1].weight;
        }

        cout << "Please enter what type of exercise you did: " << endl;
        cin.ignore();
        getline(cin, history[ONE_WEEK - 1].exerciseType);

        cout << "Please enter the time you exercised in minutes: " << endl;
        cin >> history[ONE_WEEK - 1].exerciseTime;
        while (cin.fail())
        {
            cout << "Input fail. Please enter a valid numeric value for exercise time: " << endl;
            cin.clear();
            cin.ignore(100, '\n');
            cin >> history[ONE_WEEK - 1].exerciseTime;
        }
    }

}

void displayInfo(string name, string gender, int age, FitnessData history[], int historySize) {

    if (historySize == 0)//check if the user has chose the option to enter their exercise information
    {
        cout << endl;
        cout << "No fitness data to print" << endl;
        cout << endl;
        return;
    }

    // Print the users information to the console
    cout << '\n';//separate from menu
    cout << name << " (" << gender << ", " << age << " years)" << endl;

    cout << "Weight: " << history[historySize - 1].weight << " kg" << endl;
    cout << "Exercise: " << history[historySize - 1].exerciseType << " (" << history[historySize - 1].exerciseTime << " minutes)" << endl;
    cout << endl;

}
void displayInfoHistory(string name, string gender, int age, FitnessData history[], int historySize)
{
    if (historySize == 0)//check if the user has chose the option to enter their exercise information
    {
        cout << endl;
        cout << "No fitness data to print" << endl;
        cout << endl;
        return;
    }

    cout << '\n';
    cout << name << " (" << gender << ", " << age << " years)" << endl;//print users basic info once before printing input history
    cout << '\n';

    for (int i = historySize - 1; i >= 0; i--)//print input history
    {
        cout << "Weight: " << history[i].weight << " kg" << endl;
        cout << "Exercise: " << history[i].exerciseType << " (" << history[i].exerciseTime << " minutes)" << endl;
        cout << endl;
    }
}


int main() {
    const int USER_INPUT = 1;//constant for the exercies input option no the text menu 
    const int DISPLAY = 2;//constant for the displaying the most recent exercies input option on the text menu
    const int PRINT_HISTORY = 3;//constant for the print all inputs up to the 7 most recent ones on the text menu 
    const int QUIT = 4;//constant for the quit option on the text menu

    int input = 0;//in var to store the users chose from the text menu 
    string exerciseType;
    string gender;
    string name;
    int age = 0;

    FitnessData history[ONE_WEEK];//making a FitnessData type array to hold up to 7 most recent fitness inputs 
    int historySize = 0;//int var to store the size of the history array 

    getUserInfo(name, gender, age);//call the function to get the users basic info 

    do
    {
        showMenu(USER_INPUT, DISPLAY, PRINT_HISTORY, QUIT);//call the function the display the text menu

        getUserChoice(input);//call the function to get the users chose from the text menu

        switch (input)
        {

        case USER_INPUT://if the user chooses to enter their exercies info 

            exerciseInfo(history, historySize);//call fonction to get the users exercise info 

            break;//leves this case 

        case DISPLAY://if the user chooses to display their most recent fitness input

            displayInfo(name, gender, age, history, historySize);

            break;

        case PRINT_HISTORY://if the user chooses to display their 7 most recent fitness inputs 

            displayInfoHistory(name, gender, age, history, historySize);

            break;

        case QUIT:

            break;

        default://if the user enters an invalid input 

            cout << endl;
            cout << "Invalid input. Please enter a valid menu option." << endl;//error message for user
            cout << endl;
        }

    } while (input != QUIT);//will loop till input equelse the value of the QUIT constant 

    return 0;
}
