#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, ans=1000000000, res, unus, num;

vector <int> used(105);

vector <vector <pair <int, int> > > gr;

set <pair <int ,int> > st;
set <pair <int ,int> >:: iterator it;

void BFS()
{
    while (unus != 0)
    {
        int v = (*st.begin()).second, w = (*st.begin()).first;
        cout << "\nSOSTOYZNIT SETA\n";
        for (it = st.begin(); it != st.end(); it++)
        {
            cout << (*it).first << " " << (*it).second << "\n";
        }
        cout << "CONEZ\n";
        /*cout << "GRAPH NACHALO\n";
            for (int j = 0; j < gr[v].size(); j++)
            {
                cout << gr[v][j].first << " " << gr[v][j].second << "\n";
            }
            cout <<  "\n\n";
        cout <<"GRAPH CONEZ\n";*/
        for (int j = 0; j < gr[v].size(); j++)
        {
            int to = gr[v][j].first;
            if (!used[to]) { cout << to << " " << w+gr[v][j].second << "\n"; st.insert(make_pair(w+gr[v][j].second, to)); used[to] = 1;unus--;}
        }
        st.erase(st.begin());
        if (unus == 0) res = (*st.rbegin()).first;
        else res = (*st.begin()).first;//res += w;
        //st.erase(st.begin());
        system("PAUSE");
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
        unus = n;
        st.insert(make_pair(0, i));
        used[i] = 1; unus--;
        BFS();
        cout << i << ": " << res << "\n";
        if (res <= ans) {ans = res; num = i;}
        used.clear();
        used.resize(110);
        st.clear();
        res = 0;
        cout << "\n\nNEXTNEXTNEXTNEXTNEXT\n\n";
    }
}

void out()
{
    ofstream cout("fire.out");
    cout <<num << " " << ans << "\n";
    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < gr[i].size(); j++)
        {
            cout << gr[i][j].first << " " << gr[i][j].second << "\n";
        }
        cout <<  "\n\n";
    }*/
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
