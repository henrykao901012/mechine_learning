#include <bits/stdc++.h>

using namespace std;

int n;
string str;
int g_s, s_s;

class state_data
{
public:
    string state;
    int g_score; // g: so-far cost; h: estimated cost to goal; f = g + h
    int h_score;
    int time;
    inline static int time_count = 0;

    state_data(string st, int g, int s) : state(st), g_score(g), h_score(s), time(time_count++) {}
    // state_data(const state_data &a) : state(a.state), g_score(a.g_score), h_score(a.h_score), time(a.time) {} // time will be incorrct in state_date t(a) case;

    bool operator<(const state_data &a) const
    {
        if (g_score + h_score == a.g_score + a.h_score)
            return time > a.time;
        return g_score + h_score > a.g_score + a.h_score;
    }
};

priority_queue<state_data> pq;

void print_pq()
{
    int i = 1;
    priority_queue<state_data> pq_copy = pq;
    while (!pq_copy.empty())
    {
        state_data t(pq_copy.top());
        printf("%d state = %s,  g = %d, s = %d, time = %d, f = %d\n", i++, t.state.c_str(), t.g_score, t.h_score, t.time, t.g_score + t.h_score);
        pq_copy.pop();
    }
    cout << "\n";
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> str;

        if (str[0] == 'e')
        {
            cin >> str >> g_s >> s_s;
            pq.push(state_data(str, g_s, s_s));
            cout << "Insert OK!\n";
            // print_pq();
        }
        else
        {
            if (pq.empty())
                cout << "Queue is empty!!\n";
            else
            {
                cout << "Got " << pq.top().state << "\n";
                pq.pop();
                // print_pq();
            }
        }
    }

    // system("pause");
    return 0;
}
