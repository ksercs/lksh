#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
char str[100000];
char a;

pair <char, char> sf;
vector <char> v;
pair < pair < char, char >, vector <char> > pi;
set < pair < pair < char, char >, vector <char> > > dict;
set <string> st;
vector <int> ans;

char s_cmp(char a, char b)
{
    if ( (int)a > (int) b) {return 1;}
    else    {return 0;}
}

void in()
{
    ifstream cin ("first-last-anagram.in");
    cin >>n;
    for (int i=1; i<=n; i++)
    {
        cin >>str;
        if (strlen(str)>2)
        {
        sf.first=str[0];
        sf.second=str[strlen(str)-1];
        for (int i=1; i<strlen(str)-1; i++)
        {
            v.push_back(str[i]);
        }
        sort(v.begin(), v.end(), s_cmp);
        pi.first=sf;
        pi.second=v;
        dict.insert(pi);
        v.clear();
        }
        else
        {
            st.insert(string(str));
        }
       /* cout <<"<" <<pi.first.first <<", " <<pi.first.second <<"> <";
        for(int i=0; i<(pi.second).size()-1; i++)
        {
            cout <<pi.second[i] <<", ";
        }
        cout <<pi.second[(pi.second).size()-1] <<">\n";*/

    }
   // cout <<"\n\n";
    cin >>m;
    for(int i=1; i<=m; i++)
    {
        cin >>str;
        if (strlen(str)>2)
        {
        sf.first=str[0];
        sf.second=str[strlen(str)-1];
        for (int i=1; i<strlen(str)-1; i++)
        {
            v.push_back(str[i]);
        }
        sort(v.begin(), v.end(), s_cmp);
        pi.first=sf;
        pi.second=v;
        v.clear();
       /* cout <<"<" <<pi.first.first <<", " <<pi.first.second <<"> <";
        for(int i=0; i<(pi.second).size()-1; i++)
        {
            cout <<pi.second[i] <<", ";
        }
        cout <<pi.second[(pi.second).size()-1] <<">\n";*/
        if (dict.count(pi)) {ans.push_back(1);}
        else                {ans.push_back(0);}
        }
        else
        {
        if (st.count(str)) {ans.push_back(1);}
        else                {ans.push_back(0);}
        }
    }
}

void solution()
{

}

void out()
{
    ofstream cout ("first-last-anagram.out");
    for (int i=0; i<m; i++)
    {
        if (ans[i]==1) {cout <<"YES\n";}
        else           {cout <<"NO\n";}
    }
}

int main()
{
    in();
    solution();
    out();
}
