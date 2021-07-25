#include <iostream>
#include <fstream>

using namespace std;

int m, n;
int mt[350+5][350+5], dp[350+5][350+5];

void in()
{
    ifstream cin ("matrix.in");
    cin >>n >>m;
    for(int i=1; i<=n; i++)
    {
        for(int g=1; g<=m; g++)
        {
            cin >>mt[i][g];
        }
    }
}

void solution()
{
   if (n!=1 && m!=1)
   {
    for(int i=1; i<=n; i++)
    {
        for(int g=1; g<=m; g++)
        {
            if (i!=1 && g!=1 && i!=n && g!=m) {dp[i][g]=mt[i+1][g]+mt[i-1][g]+mt[i][g+1]+mt[i][g-1];}
            if (i==1 && g==1 && i!=n && g!=m) {dp[i][g]=mt[i+1][g]+mt[i][g+1];}
            if (i!=1 && g!=1 && i==n && g==m) {dp[i][g]=mt[i-1][g]+mt[i][g-1];}
            if (i==1 && g!=1 && i!=n && g==m) {dp[i][g]=mt[i+1][g]+mt[i][g-1];}
            if (i!=1 && g==1 && i==n && g!=m) {dp[i][g]=mt[i-1][g]+mt[i][g+1];}
            if (i==1 && g!=1 && i!=n && g!=m) {dp[i][g]=mt[i+1][g]+mt[i][g+1]+mt[i][g-1];}
            if (i!=1 && g==1 && i!=n && g!=m) {dp[i][g]=mt[i+1][g]+mt[i-1][g]+mt[i][g+1];}
            if (i!=1 && g!=1 && i==n && g!=m) {dp[i][g]=mt[i-1][g]+mt[i][g+1]+mt[i][g-1];}
            if (i!=1 && g!=1 && i!=n && g==m) {dp[i][g]=mt[i+1][g]+mt[i-1][g]+mt[i][g-1];}
        }
    }
   }
    if ( n==1 && m!=1)
    {
        for(int g=1; g<=m; g++)
        {
            dp[1][1]=mt[1][2];
            dp[1][m]=mt[1][m-1];
            if (g!=1 && g!=m) {dp[1][g]=mt[1][g-1] + mt[1][g+1];}
        }
    }
    if (n!=1 && m==1)
    {
        for(int i=1; i<=n; i++)
        {
            dp[1][1]=mt[2][1];
            dp[n][1]=mt[n-1][1];
            if (i!=1 && i!=m) {dp[i][1]=mt[i-1][1] + mt[i+1][1];}
        }
    }

}

void out()
{
    ofstream cout ("matrix.out");
    if (n!=1 && m!=1)
    {
    for(int i=1; i<=n; i++)
    {
        for(int g=1; g<=m; g++)
        {
            cout <<dp[i][g] <<" ";
        }
        cout <<"\n";
    }
    }
    if (n==1 && m==1) {cout <<"0\n";}
    if (n==1 && m!=1)
    {
        for(int g=1; g<=m; g++)
        {
            cout <<dp[1][g] <<" ";
        }
        cout <<"\n";
    }
    if (n!=1 && m==1)
    {
        for(int i=1; i<=n; i++)
        {
           cout <<dp[i][1] << "\n";
        }
    }
}

int main()
{
    in();
    solution();
    out();
}
