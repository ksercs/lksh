#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

const int MAX_COUNT = 50000;

int n, ans;
vector <pair <int, int> > cost;

void in()
{
    ifstream cin("company.in");
    int k;
    cin >> n;
    string str;
    int mon;
    for (int i = 0; i < n; i++)
    {
       cin >> k;
       for (int j = 0; j < k; j++)
       {
           cin >> str >> mon;
           cost.push_back(make_pair((str[0] - '0') * 100000 + (str[1] - '0') * 10000 + (str[3] - '0') * 1000 + (str[4] - '0') * 100 + (str[6] - '0') * 10 + (str[7] - '0'), mon));
       }
    }
}

void solution()
{
    int money = 0;
    sort(cost.begin(), cost.end());
    for (int i = 0; i < cost.size(); i++)
    {
        money += cost[i].second;
        ans = min(ans, money);
    }
}

void out()
{
     ofstream cout("company.out");
     cout << -1 * (ans) << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
