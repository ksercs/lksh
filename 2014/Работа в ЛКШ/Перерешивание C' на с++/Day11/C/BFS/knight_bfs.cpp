#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
//#include <conio.h>

using namespace std;

const int MAX_money=100;;

int n, m, ch, t, i1, i2;
int dx[4] = {2, 1}, 
    dy[4] = {1, 2};
  
typedef pair <int, int> pa;  
    
int money[MAX_money+6][MAX_money+6];
int rez[MAX_money+6][MAX_money+6];

queue < pair <pa, int> > q;
pair <pa, int> pi;

void bfs()
{
     
     while (!(q.empty()))
     {
           i1 =(q.front()).first.first; i2 =(q.front()).first.second;
           ch=(q.front()).second;
           for(int i=0; i<2; i++)
           {
                   t= rez[i1+dx[i]][i2+dy[i]];
                   if (t==0) {
                              rez[i1+dx[i]][i2+dy[i]] = max(ch + money[i1+dx[i]][i2+dy[i]], 
                                                            rez[i1+dx[i]][i2+dy[i]]); 
                              pi.second = rez[i1+dx[i]][i2+dy[i]];
                              pi.first.first = i1+dx[i];
                              pi.first.second = i2+dy[i];
                              q.push(pi);
                             }
                   if (t>0) {
                              if ( (ch + money[i1+dx[i]][i2+dy[i]]) > 
                                                            rez[i1+dx[i]][i2+dy[i]] ) 
                              {
                              rez[i1+dx[i]][i2+dy[i]] = max(ch + money[i1+dx[i]][i2+dy[i]], 
                                                            rez[i1+dx[i]][i2+dy[i]]);                               
                              pi.second = rez[i1+dx[i]][i2+dy[i]];
                              pi.first.first = i1+dx[i];
                              pi.first.second = i2+dy[i];
                              q.push(pi);
                              }
                             }
          // cout <<q.size() <<"\n"; getch();
           }
           q.pop();
     }
}

void in()
{
    ifstream cin ("knight_bfs.in");
     cin >>n >>m;
     for (int i=0;i<n+4;i++)
     {
          for (int j=0;j<m+4; j++)
          {
              money[i][j]=0;
          }
     }    
     for (int i=2;i<n+2;i++)
     {
          for (int j=2;j<m+2; j++)
          {
              cin>>money[i][j];
          }
     }  
}

void solution()
{
    for (int i=0; i<n+4; i++)
    {
      rez[0][i] = -1;
      rez[1][i] = -1;  
      rez[n+2][i] = -1;
      rez[n+3][i] = -1;
    }
    for (int i=0; i<m+4; i++)
    {
      rez[i][0] = -1; 
      rez[i][1] = -1; 
      rez[i][m+2] = -1;
      rez[i][m+3] = -1;
    }
    pi.first.first = 2;
    pi.first.second = 2;
    pi.second = money[2][2]; 
    q.push(pi);
    rez[2][2] = q.front().second;
    bfs();
}

void out()
{
     ofstream cout ("knight_bfs.out");
    /*cout <<n <<" " <<m <<"\n";
     for(int i=0;i<n;i++)
     {
          for (int j=0;j<m; j++)
          {
              cout <<money[i][j] <<" ";
          }
          cout <<"\n";
     }*/
     for (int i=2; i<n+2;i++)
     {
          for (int j=2; j<m+2; j++)
          {
              cout <<rez[i][j] <<" ";
          }
          cout <<"\n";
     }
     if (rez[n+1][m+1]!=0) {cout <<rez[n+1][m+1] <<"\n";}
     else  { cout <<"-1\n";} 

}

int main()
{
    in();
    solution();
    out();
return 0;
}
