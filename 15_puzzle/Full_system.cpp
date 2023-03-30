#include <bits/stdc++.h>

using namespace std;

class state_data;

const string goal = "0123456789ABCDEF";
const char *dir_dic[] = {"up", "down", "left", "right"};
const int dir[][2] = {0, -1, 0, 1, -1, 0, 1, 0};

priority_queue<state_data> pq;
vector<state_data> save;
string s;
state_data *ans;

class state_data
{
public:
    string state;
    int g_score;
    int h_score;

    int action;
    state_data *p;

    int time;
    inline static int time_count = 0;

    state_data(string st, int g, int act, state_data *parent) : state(st), g_score(g), h_score(manhanttan_distance()),
                                                                action(act), p(parent), time(time_count++) {}
    //~state_data() { delete p; }

    bool operator<(const state_data &a) const
    {
        if (g_score + h_score == a.g_score + a.h_score)
            return time > a.time;
        return g_score + h_score > a.g_score + a.h_score;
    }

    int manhanttan_distance()
    {
        int count = 0;
        for (int i = 0; i < 16; i++)
        {
            if (state[i] != '0')
            {
                int t = state[i] >= 'A' ? state[i] - 'A' + 10 : state[i] - '0';
                count += abs(i % 4 - t % 4) + abs(i / 4 - t / 4);
                // printf("mannh %c = %d\n", s[i], abs(i % 4 - t % 4) + abs(i / 4 - t / 4));
            }
        }
        return count;
    }

    bool isSolve()
    {
        int zero = state.find("0");
        int count = 0;

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (state[i] < state[j])
                {
                    count++;
                    // printf("%c < %c\n", s[i], s[j]);
                }
            }
        }
        // printf("count = %d\n", count);
        return (count - zero + zero / 4 + 1) & 1;
    }

    void successor()
    {
        save.clear();
        int zero = state.find("0");
        // string ans;

        for (int i = 0; i < 4; i++)
        {
            int x = zero % 4 + dir[i][0];
            int y = zero / 4 + dir[i][1];
            if (0 <= x && x < 4 && 0 <= y && y < 4)
            {
                string t = state;
                t[zero] = t[x + y * 4];
                t[x + y * 4] = '0';
                save.push_back(state_data(t, g_score + 1, i, this));
            }
        }
    }
};

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0);

    cin >> s;
    state_data t(s, 0, -1, nullptr);

    if (s == goal)
        cout << "It is the goal state.\n";
    else if (!t.isSolve())
        cout << "No solution!!\n";
    else
    {
        pq.push(t);

        while (!pq.empty())
        {
            // state_data t = pq.top();
            state_data *t = new state_data(pq.top());
            pq.pop();

            if (t->state == goal)
            {
                ans = t;
                break;
            }

            t->successor();
            for (auto &i : save)
            {
                pq.push(i);
                // printf("push %s in, which is <- %s(%d)\n", i.state.c_str(), i.p->state.c_str(), i.action);
            }
            // cout << "\n";
        }

        if (ans)
        {
            int rev_ans[100000];
            int count = 0;
            while (ans)
            {
                rev_ans[count++] = ans->action;
                ans = ans->p;
            }
            for (int i = count - 2; i >= 0; i--)
                printf("move 0 to %s\n", dir_dic[rev_ans[i]]);
        }
        else
            cout << "No solution!!\n";
    }

    // system("pause");
    return 0;
}
