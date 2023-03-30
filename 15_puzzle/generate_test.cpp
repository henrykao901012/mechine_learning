#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Create an array of the hexadecimal digits
    array<char, 16> digits = {'0', '1', '2', '3', '4', '5', '6', '7',
                              '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    // Shuffle the array using a random engine
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    shuffle(digits.begin(), digits.end(), gen);

    // Output the shuffled digits
    for (char digit : digits)
    {
        cout << digit;
    }
    cout << "\n";

    return 0;
}
