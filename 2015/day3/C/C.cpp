#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;

const int MAX_SEG = 100000 + 5;

int n, op, cl;

pair <pair <int, int> , int> sg[2 * MAX_SEG];
int ans[MAX_SEG];

bool cmp(pair <pair <int, int>, int> pi1, pair <pair <int, int>, int> pi2)
{
    if (pi1.first.first != pi2.first.first)
    {
        return pi1.first.first < pi2.first.first;
    }
    else
    {
        return pi1.first.second > pi2.first.second;
    }
}

void in()
{
    int s, f;
    ifstream cin("upsolving.in");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> f;
        sg[2*i].first.first = s; sg[2*i].first.second = 1; sg[2*i].second = i;
        sg[2*i+1].first.first = f; sg[2*i+1].first.second = -1; sg[2*i+1].second = i;
    }
    op = n;
    sort(sg, sg + 2*n, cmp);
    /*for (int i = 0; i < 2*n; i++)
    {
        cout << sg[i].first.first << " " << sg[i].first.second << " " << sg[i].second << "\n";
    }*/
}

void solution()
{
    for (int i = 0; i < 2*n; i++)
    {
        if (sg[i].first.second == 1) {op--; ans[sg[i].second] += cl;}
        else                         {ans[sg[i].second] += op; cl++;}
    }
}

void out()
{
    ofstream cout("upsolving.out");
    for (int i = 0; i < n; i++)
    {
        cout << n - ans[i] - 1 << "\n";
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
