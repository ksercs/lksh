#include <iostream>
#include <fstream>
#include <algorithm>
#include <conio.h>
#include <utility>

using namespace std;

const int MAX_money=100;

int n, m, h, i1, i2;
pair <int, int> pi;
typedef pair <int, int> pa;
int money[MAX_money+6][MAX_money+6], used[MAX_money+6][MAX_money+6];
long long sum;
long long rez[MAX_money+6][MAX_money+6];
pa prv[MAX_money+6][MAX_money+6];

/*long long knight(int x, int y)
{
    int i1, i2, jo;
    long long sum;
    if (jo!=1){
    i1=x; i2=y;
    pi.first=i1; pi.second=i2;
    prv[x][y]=pi;}
    jo++;
    used[x][y]+=1;
    rez[x][y]=rez[prv[x][y].first][prv[x][y].second]+money[x][y];
    if (used[x][y]<2)
    {
    if ( (money[x+1][y+2]!=0) && (used[x+1][y+2]==0)) {knight(x+1, y+2);}
    else                                              {
                                                        if ((money[x+2][y+1]!=0) && (used[x+2][y+1]==0)) {knight(x+2, y+1);}
                                                        else                                             {knight(prv[x][y].first, prv[x][y].second);}
                                                      }
    }
    else {knight(prv[x][y].first, prv[x][y].second);}
    if ( (x==n-2) && (y==m-2) ) {
                                 if (rez[x][y]>sum) {sum=rez[x][y];}
                                }
    if ( used[2][2]==3 )        {
                                if (sum==0) {sum=-1; return sum;}
                                else         {return sum; }   
                                }
}*/

void Fknight(int x, int y)
{ 
  //int i1, i2;
  if ( (money[3][4]==0) && (money[4][3]==0) ) {sum=(-1); cout <<"11111  \n"; getch(); return; }   
  else {
       if ( (money[3][4]==0) || (money[4][3]==0) )  {
                                                     if ( (used[2][2]==2) && (sum<=0) ) {sum=(-1);cout << sum <<"  22222  \n"; getch();return;}   
                                                    }
       else                                         {
                                                     if ( (used[2][2]==3) && (sum<=0) ) {sum=(-1);cout <<"333333  \n";getch();return;}
                                                    }
       }
  used[x][y]+=1;
  if ( (h!=0) && (x>i1) && (y>i2)) {
                                     pi.first=i1; pi.second=i2;
                                     prv[x][y]=pi;
                                   }
  //cout <<pi.first <<" " <<pi.second <<"\n";getch();
  //cout <<prv[x][y].first <<" " <<prv[x][y].second <<"\n"; getch();
   i1=x; i2=y;            
  //cout <<" i1=" <<i1-2 <<" i2=" <<i2-2 <<"\n"; getch();
  //if (h==0) {cout <<x-2 <<" " <<y-2 <<"\n"; getch();}
  //else      {cout <<x-2 <<" " <<y-2 <<" PREDOK:" <<prv[x][y].first-2 <<" " <<prv[x][y].second-2 <<"\n"; getch();}
  h=1;

  int a = prv[x][y].first;
  int b = prv[x][y].second;
  if (rez[x][y] < rez[a][b]+money[x][y]) {rez[x][y] = rez[a][b]+money[x][y];}
  if ( (x==n+1) && (y==m+1) && (26) ) {sum=rez[x][y]; cout<<rez[x][y] <<"ewfwergerg\n"; getch(); return;}
  int g=0;;
  //cout <<x-2 <<" " <<y-2 <<"\n"; getch();
 if ( (money[x+1][y+2]!=0) && (money[x+2][y+1]!=0))
 {
      if (used[x][y]==3) {Fknight(a, b);}
      if (used[x][y]==2) {Fknight(x+2, y+1);}
      if (used[x][y]==1) {Fknight(x+1, y+2);}
 }
 if ( (money[x+1][y+2]!=0) && (money[x+2][y+1]==0))
 {
      if (used[x][y]==2) {Fknight(a, b);}
      else {Fknight(x+1, y+2);}
 }
 if ( (money[x+1][y+2]==0) && (money[x+2][y+1]!=0))
 {
      if (used[x][y]==2) {Fknight(a, b);}
      else {Fknight(x+2, y+1);}
 }      
 if ( (money[x+1][y+2]==0) && (money[x+2][y+1]==0))
 {
      if (used[x][y]==1) {Fknight(a, b);}
 }
}

void in()
{
     ifstream cin ("knight.in");
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
 Fknight(2,2);    
}

void out()
{
     ofstream cout ("knight.out");
    /*cout <<n <<" " <<m <<"\n";
     for(int i=0;i<n;i++)
     {
          for (int j=0;j<m; j++)
          {
              cout <<money[i][j] <<" ";
          }
          cout <<"\n";
     }
     for (int i=0;i<n+4;i++)
     {
          for (int j=0; j<m+4; j++)
          {
              cout <<money[i][j] <<" ";
          }
          cout <<"\n";
     }*/  
     cout <<sum <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
