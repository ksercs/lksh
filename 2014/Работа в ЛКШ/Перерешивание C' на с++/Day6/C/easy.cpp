#include <iostream>
#include <fstream>
#include <algorithm>
//#include <conio.h>

using namespace std;

long long copies, ks1, ks2, g_time, ans_time, left_board, right_board;
int p;

long long binary_search_R(long long l, long long r)
{// cout <<l <<" " <<r <<"\n"; getch();
    if (l>r) {/*cout <<"##" <<l <<"\n";getch();*/  g_time=l; /*cout <<"GETAME   " <<g_time <<"\n";*/  return g_time;}
    long long r_time=(r+l)/2, temp = r_time/ks1 + r_time/ks2;
    if (temp == copies) { while (r_time/ks1 + r_time/ks2==copies)
                          {
                           r_time--;
                          } 
                          g_time=r_time+1;          
                         /*cout <<"!!!!" <<g_time <<"\n";getch();*/ return g_time;}    
    if (temp < copies) {/*cout<<"LEFT   "; getch();*/ binary_search_R(r_time+1, r);}   
    else               {/*cout<<"RIGHT   "; getch();*/ binary_search_R(l, r_time-1);}
}

void in()
{
     ifstream cin ("easy.in");
     cin >>copies >>ks1 >>ks2;
}

void solution()
{ 
     //cout <<";¹;" <<" " <<left_board <<" " <<right_board <<"\n"; getch();
     if (copies==1) {p=1;}
     else           {
                         ans_time += min(ks1,ks2);
                         left_board = min(ks1,ks2);
                         right_board = copies*left_board;
                         copies = copies-1;
                         binary_search_R(left_board, right_board);
                      }
 //cout <<"324    " <<copies <<"\n";
     /*g_time = */
     /*cout <<"g_time " <<" " <<g_time<<"\n"; getch();*/
     ans_time += g_time;
     //cout <<ans_time <<"\n"; getch();
}

void out()
{
     ofstream cout ("easy.out");
     if(p==1) {cout <<min(ks1,ks2) <<"\n";}
     else      {cout <<ans_time <<"\n";}
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
