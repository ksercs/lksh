#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int n, k, a, ans=1, ch, m=1, od;
int mass[100+5];

vector <int> v;
set <int> st;


void in()
{
    ifstream cin ("permutations.in");
    cin >>n >>k;
    for (int i=0; i<k; i++)
    {
        cin >>a;
        mass[i]=a;
        v.push_back(a);
        st.insert(a);

    }
}

void solution()
{
    for (int i=2; i<=n; i++)
    {
        ans*=i;
    }
    ch=n-k;
    for (int i=2; i<=ch; i++)
    {
        m*=i;
    }

    for (int i=0; i<k; i++)
    {
        if (mass[i]<=n && mass[i]>=1) {od++;}
    }

    if (v.size()==st.size() && v.size()<=9 && od==k)
    {
        ans-=m;
    }
}

void out()
{
    ofstream cout ("permutations.out");
    cout <<ans <<"\n";
}

int main()
{
    in();
    solution();
    out();
}
