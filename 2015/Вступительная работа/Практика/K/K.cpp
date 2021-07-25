#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, m, x=1, x1=1, y1=1, s, ch, sum, p, d=1;
int mass[7][7], dp[7][7];
int dx[30];

void m_out_1()
{
          ofstream cout ("rectangle-sum-0.out");
 if (n==1 && m!=1)
 {
     for(int i=1; i<=m; i++)
     {
         if (mass[1][i]==0) {sum++;}
     }
     if (sum==m) {
                    cout <<"YES\n";
                    for (int i=1; i<m; i++)
                    {
                        cout <<"0 ";
                    }
                    cout <<"0\n";
                 }
     else {cout <<"NO\n";}
 }
 if (m==1 && n!=1)
 {
     for(int i=1; i<=n; i++)
     {
         if(mass[i][1]==0) {sum++;}
     }
     if (sum==n) {
                    cout <<"YES\n";
                    for (int i=1; i<=n; i++)
                    {
                        cout <<"0\n";
                    }
                 }
     else  {cout <<"NO\n";}
 }
 if (m==1 && n==1)  {
                        if (mass[1][1]==0)
                        {
                            cout <<"YES\n";
                            cout <<"0\n";
                        }
                        else {cout <<"NO\n";}
                    }
}

void m_out()
{
        ofstream cout ("rectangle-sum-0.out");
        if (ch==1)
        {
            cout <<"YES\n";
            for(int i=1; i<=n; i++)
                {
                    for(int g=1; g<=m; g++)
                    {
                        cout <<dp[i][g] <<" ";
                    }
                    cout <<"\n";
                }
        }
        else {cout <<"NO\n";}
}

int dfs_r(int a)
{
if (a<=n*m)
{
 if (dx[a]<0) {dx[a]*=(-1);}
 dfs_r(a+1);
 if (dx[a]>0) {dx[a]*=(-1);}
 dfs_r(a+1);
}
else
{
     for(int g=1; g<=n*m; g++)
     { //cout <<dx[g] <<" ";
         dp[x1][y1]=dx[g]; y1++;
         if (y1==m+1) {x1++; y1=1;}
     }
     //cout <<"\n";
     /*for(int i=1; i<=n; i++)
     {
         for(int g=1; g<=m; g++)
         {
             cout <<dp[i][g] <<" ";
         }
         cout <<"\n\n";
     }*/
     for(int i=1; i<=n; i++)
     {
         for(int g=1; g<=m; g++)
         {
             dp[i][m+1]+=dp[i][g];
             dp[n+1][g]+=dp[i][g];
             if (g==m) {if (dp[i][m+1]==0) {s++;} dp[i][m+1]=0; }
             if (i==n) {if (dp[n+1][g]==0) {s++;} dp[n+1][g]=0;}
         }
     }
    /* for(int i=1; i<=n; i++)
     {
         if (dp[i][m+1]==0) {s++;}
         dp[i][m+1]=0;
     }
    for(int i=1; i<=m; i++)
     {
         if (dp[n+1][i]==0) {s++;}
         dp[n+1][i]=0;
     }*/
     //cout <<s <<"\n\n";
     if(s==n+m) {ch=1; m_out(); exit(0);}
     else {
           s=0;x1=1;y1=1;p++;
           if (p==d/2) {m_out(); exit(0);}
          }
}
}


void in()
{
    ifstream cin ("rectangle-sum-0.in");
    cin >>n >>m;
    for(int i=1; i<=n; i++)
    {
        for(int g=1; g<=m; g++)
        {
            cin >>mass[i][g]; dx[x]=mass[i][g]; x++;
        }
    }
}

void solution()
{
//if (n!=1 && m!=1) {dfs_r(1);}
for(int i=1; i<=m*n; i++)
{
    d*=(2);
}
}

void out()
{
    ofstream cout ("rectangle-sum-0.out");
 if (n==1 || m==1) {m_out_1();}
else {dfs_r(1);}
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
