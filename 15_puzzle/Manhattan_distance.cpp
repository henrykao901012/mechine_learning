#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int manhanttan_distance()
{
    int count = 0;
    for (int i = 0; i < 16; i++)
    {
        if (s[i] != '0')
        {
            int t = s[i] >= 'A' ? s[i] - 'A' + 10 : s[i] - '0';
            count += abs(i % 4 - t % 4) + abs(i / 4 - t / 4);
            // printf("mannh %c = %d\n", s[i], abs(i % 4 - t % 4) + abs(i / 4 - t / 4));
        }
    }

    return count;
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> s;
        cout << manhanttan_distance() << "\n";
    }

    // system("pause");
    return 0;
}
