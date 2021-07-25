#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000000, MAX_SIZE = 100+15;

int n, m, ans=INF, num, res, rn;

int w[MAX_SIZE], used[MAX_SIZE];

typedef pair <int, int> pa;

vector <vector <pair <int, int> > > gr;

set <pa> st;

void BFS()
{
    while (!st.empty())
    {
        pair <int, int> p = (*st.begin());
        int v = (*st.begin()).second, weh = (*st.begin()).first;
        for (int j = 0; j < gr[v].size(); j++)
        {
            int to = gr[v][j].first, wg = gr[v][j].second;
            if (!used[to])
            {
                used[to] = 1;
                st.insert(make_pair(wg, to));
                if (res <= w[v]+wg)
                {
                    rn = to;
                    res = w[v]+wg;
                    w[to] = res;
                  //  cout << rn <<  " " << res << " " << "\n";
                }
            }
        }
        st.erase(p);
    }
}

void in()
{
    ifstream cin("fire.in");
    cin >> n >> m;
    gr.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        gr[a].push_back(make_pair(b, w));
        gr[b].push_back(make_pair(a, w));
    }
}


void solution()
{
   for (int i = 1; i <= n; i++)
   {
       for (int g = 1; g <= 100; g++)
       {
           used[g] = 0;
           w[g] = INF;
       }
       st.insert(make_pair(0, i));
       used[i] = 1;
       w[i] = 0;
       BFS();
      // cout <<"\n-----NEXT-----\n";
       if (ans > res)
       {
           ans = res;
           num = i;
       }
       res = 0;
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
