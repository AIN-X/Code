#include <iostream>
#include <vector>
using namespace std;

void sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    cout << "Prime numbers up to " << n << ": ";
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            cout << p << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n < 2)
    {
        cout << "No primes less than 2." << endl;
    }
    else
    {
        sieveOfEratosthenes(n);
    }

    return 0;
}