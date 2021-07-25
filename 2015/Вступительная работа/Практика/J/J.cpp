#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>


using namespace std;

int ver, ed, a, b, c;
long long sum;

int used[100000+5];

vector < long long > ans;
pair < int, int > pi;
vector < pair < int, int > > mass[100000+5];

int dfs(int u)
{
    //cout <<u <<" ";
    used[u]=1;
    for(int g=0; g<mass[u].size(); g++)
    {
        if(used[mass[u][g].first]==0) {sum+=mass[u][g].second;  dfs(mass[u][g].first); }
        else    {sum+=mass[u][g].second;}
    }
    used[u]=2;
}


void in()
{
    ifstream cin ("coins-collecting.in");
    cin >>ver >>ed;
    for(int i=1; i<=ed; i++)
    {
        cin >>a >>b >>c;
        pi.first=b; pi.second=c;
        mass[a].push_back(pi);
        pi.first=a;
        mass[b].push_back(pi);
    }
}

void solution()
{
 for (int i=1; i<=ver; i++)
 {
     if (used[i]==0) {dfs(i); ans.push_back(sum); sum=0;}
 }
 sort(ans.begin(), ans.end());
}

void out()
{
    ofstream cout ("coins-collecting.out");
 if (ans.size()==0) {cout <<"0\n";}
 else   {cout <<ans[ans.size()-1]/2 <<"\n";}
 /*for(int i=1; i<=ver; i++)
 {
     for (int g=0; g<mass[i].size(); g++)
     {
         cout <<"<" <<mass[i][g].first <<" , " <<mass[i][g].second <<">    ";
     }
     cout <<"\n";
 }*/
}

int main()
{
    in();
    solution();
    out();
}
