
// Ez Racancoj

#include <iostream>
using namespace std;

bool isPrime(int value)
{
    int count = 0;
    bool is_prime = true;
    for (int i = value - 1; i > 1; i--)
    {
        if (value % i == 0)
        {
            is_prime = false;
            break;
        }
    }
    return is_prime;
}

void displayPrimeNimbers(int n, int m = 10)
{

    int count = 2;
    int numOfPrimes = 0;
    while (numOfPrimes < n)
    {
        if (isPrime(count))
        {
            numOfPrimes++;
          cout << count << "\t";
          if (numOfPrimes % m == 0)
          {
              cout << endl;
          }

        }
        count++;
    }

}


int main()
{
    displayPrimeNimbers(100, 20);
    displayPrimeNimbers(40);
    //cout << boolalpha << isPrime(5);

    return 0;
}
