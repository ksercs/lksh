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
#include <map>

using namespace std;

const int MAX_SIZE = 50000 + 5, DAY_H = 43200;

int n, cost, ans, m_time;

int hr[MAX_SIZE];

void in()
{
    ifstream cin("watches.in");
    string str;
    int h, m, s, ch = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str[1] == ':')
        {
            h = str[0]-'0';
            ch = 1;
        }
        else {h = (str[0]-'0')*10 + (str[1]-'0');}
        m = (str[3-ch]-'0')*10 + (str[4-ch]-'0');
        s = (str[6-ch]-'0')*10 + (str[7-ch]-'0');
        hr[i] = (h - 1) * 3600 + m * 60 + s;
        ch = 0;
    }
}

void solution()
{
    sort(hr, hr+n);
    for (int i = 0; i < n; i++)
    {
        cost += (DAY_H - (hr[i] - hr[0])) % DAY_H;
    }
    m_time = cost;
    for (int i = 0; i < n-1; i++)
    {
        cost += n * (hr[i + 1] - hr[i]) - DAY_H;
        if (cost < m_time)
        {
          ans = i + 1;
          m_time = cost;
        }
    }
}


void out()
{
    ofstream cout("watches.out");
    int sec = hr[ans];
    int h = sec/3600;
    int m = (sec%3600)/60;
    int s = (sec%3600)%60;
    cout << h + 1 <<":";
    if (m >= 10) {cout << m << ":";}
    else         {cout << "0" << m <<":";}
    if (s >= 10) {cout << s << "\n";}
    else         {cout << "0" << s <<"\n";}
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
