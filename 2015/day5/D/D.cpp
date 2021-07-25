#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

void subset(int balance, int cnt, vector <char> &ans)
{
    if (ans.size() == 2 * cnt)
    {
        for (int i = 0; i < 2 * cnt; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
    else
    {
        if (2 * cnt - ans.size() >= balance + 1)
        {
            ans.push_back('(');
            subset(balance + 1, cnt, ans);
            ans.pop_back();
        }
        if (balance > 0)
        {
            ans.push_back(')');
            subset(balance - 1, cnt, ans);
            ans.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector <char> answer;
    subset(0, n, answer);
    return 0;
}
