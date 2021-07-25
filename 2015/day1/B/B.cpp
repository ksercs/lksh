#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, km, cost;

pair < int, int > m_cost[1000+2], m_km[1000+2];
int ans[1000+2];

pair < int, int > pi1;
pair < int, int > pi2;

void in()
{
    ifstream cin("taxi.in");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> km;
        m_km[i] = make_pair(km, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> cost;
        m_cost[i] = make_pair(cost, i);
    }
}

void solution()
{
    sort(m_km, m_km+n+1);
    sort(m_cost, m_cost+n+1);
    for (int i = 1; i <= n; i++)
    {
        ans[m_km[i].second] = m_cost[n-i+1].second;
    }
}

void out()
{
     ofstream cout("taxi.out");
    /*    for (int i = 1; i <= n; i++)
    {
        cout <<m_km[i].first << " " <<m_km[i].second <<"\n";
    }
    cout <<"\n";
    for (int i = 1; i <= n; i++)
    {
        cout <<m_cost[i].first << " " <<m_cost[i].second <<"\n";
    }*/
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
