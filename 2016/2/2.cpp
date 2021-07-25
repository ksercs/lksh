#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int VERTEX_COUNT = 1000+15;

int n, m, s;

int used[VERTEX_COUNT];

vector < vector <int> > gr;
vector <int> ans;

void DFS(int v)
{
    used[v] = 1;
    for (int i = 0; i < gr[v].size(); i++)
    {
        int to = gr[v][i];
        if (!used[to]) DFS(to);
    }
}

void in()
{
    ifstream cin("leonard.in");
    cin >> n >> m >> s;
    gr.resize(n+1);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
}

void solution()
{
    DFS(s);
    for (int i = 1; i <= n; i++)
    {
        if (!used[i]) ans.push_back(i);
    }
}

void out()
{
   ofstream cout("leonard.out");
   if (!ans.size()) cout << "-1\n";
   else
   {
       for (int i = 0; i < ans.size()-1; i++)
       {
           cout << ans[i] << " ";
       }
       cout << ans[ans.size()-1] << "\n";
   }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
