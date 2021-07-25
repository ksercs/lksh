#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>


using namespace std;

int n, m, a, sum, ans1, it;

pair <int, int> pi;
vector < pair <int, int> > vec;
vector <int> ans;

void in()
{
    ifstream cin("arrival.in");

    pi.first = 0; pi.second = 0;
    vec.push_back(pi);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a;
        pi.first = a; pi.second = i;
        vec.push_back(pi);
    }

    /*   for(int i=0; i<vec.size(); i++)
    {
        cout <<vec[i].first <<" " <<vec[i].second <<"\n";
    }*/
}

void solution()
{
    sort(vec.begin(), vec.end());

   /* for(int i=0; i<vec.size(); i++)
    {
        cout <<vec[i].first <<" " <<vec[i].second <<"\n";
    }*/

    for (int i = m; i >= 1; i--)
    {
        it = i;
     sum+=vec[i].first;
     ans.push_back(vec[i].second);
     if (sum >= n) {break;}
    }

   /* for(int i=0; i<ans.size(); i++)
    {
        cout <<ans[i] <<" ";
    }*/
}

void out()
{
     ofstream cout("arrival.out");

    /* for(int i=1; i<=m; i++)
     {
         cout <<vec[i].first <<" ";
     }*/

     sort(ans.begin(), ans.end());

     if (sum < n) {cout <<"-1\n";}
     else {
            cout <<m-it+1 <<"\n";
            for (int i = 0; i < ans.size(); i++)
            {
                cout <<ans[i] <<" ";
            }
            cout <<"\n";
          }
}

int main()
{
    in();
    solution();
    out();
return 0;
}
