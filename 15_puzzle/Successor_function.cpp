#include <bits/stdc++.h>

using namespace std;

int n;
string s;
const string dir_dic[] = {"up", "down", "left", "right"};
const int dir[][2] = {0, -1, 0, 1, -1, 0, 1, 0};

pair<int, string> successor()
{
    int count = 0;
    int zero = s.find("0");
    string ans;

    for (int i = 0; i < 4; i++)
    {
        int x = zero % 4 + dir[i][0];
        int y = zero / 4 + dir[i][1];
        if (0 <= x && x < 4 && 0 <= y && y < 4)
        {
            string t = s;
            t[zero] = t[x + y * 4];
            t[x + y * 4] = '0';
            ans += "move 0 to " + dir_dic[i] + "\n" + t + "\n";
            count++;
        }
    }
    return {count, ans};
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> s;

        pair<int, string> get = successor();
        cout << get.first << "\n"
             << get.second;
    }

    // system("pause");
    return 0;
}
