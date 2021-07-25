#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int INF = 1000000000, MAX_SIZE = 100000+5;

int n, m, st, fn, ans=INF, num;

int w[MAX_SIZE], used[MAX_SIZE];

typedef pair <int, int> pa;

set <pa> way;
set <pa>:: iterator iter;

map <int,vector <pa> > ed;

void dijkstra(int v)
{
    /*for (int i = 1; i <= n; i++)
    {
        cout << w[i] << " ";
    }
    cout << "\n";*/
    pa pr;
    pr = (*way.begin());
    //cout << v << "\n"; system("PAUSE");
    used[v] = 1;
    for (int i = 0; i < ed[v].size(); i++)
    {
        int tmp = w[v]+ed[v][i].second, to = ed[v][i].first;
        if (!used[to])
        {
            if (w[to] > tmp )
            {
                way.erase(make_pair(w[to],to));
                way.insert(make_pair(tmp, to));
                w[to] = tmp;
            }
        }
    }
    way.erase(pr);
    iter = way.begin();
    //cout << (*iter).first << " " << (*iter).second <<  "\n";
    if (v == n) return;
    if (!used[(*iter).second]) {dijkstra((*iter).second);}
    else                        {iter++;dijkstra((*iter).second);}
}

void in()
{
    ifstream cin ("fire.in");
    cin >> n >> m;
    for (int i =0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ed[a].push_back(make_pair(b, c));
        ed[b].push_back(make_pair(a, c));
    }
}

void solution()
{
   /* for (iter = way.begin(); iter != way.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << "\n";
    }*/
    for (int st = 1; st <= n; st++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == st) {way.insert(make_pair(0, i));}
            else         {way.insert(make_pair(INF, i));}
        }
        for (int i = 1; i <= 100; i++)
        {
            used[i] = 0;
            w[i] = INF;
        }
        int res = 0;
        w[st] = 0;
        dijkstra(st);
        for (int i = 1; i <= n; i++)
        {
          if (w[i] >  res) {res = w[i];}
        }
        if (res < ans) {ans = res; num = st;}
        way.clear();
    }
}

void out()
{
     ofstream cout ("fire.out");
     cout <<num << " " << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
