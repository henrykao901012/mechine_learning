#include <bits/stdc++.h>

using namespace std;

int n;
string s;
const string ans[] = {"NO", "YES"};

int isSolve()
{
    int zero = s.find("0");
    int count = 0;

    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (s[i] < s[j])
            {
                count++;
                // printf("%c < %c\n", s[i], s[j]);
            }
        }
    }
    // printf("count = %d\n", count);
    return (count - zero + zero / 4 + 1) & 1;
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> s;
        cout << ans[isSolve()] << "\n";
        // isSolve();
    }

    // system("pause");
    return 0;
}
