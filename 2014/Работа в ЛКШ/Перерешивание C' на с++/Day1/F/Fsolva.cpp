#include <iostream>
#include <cstring>
#include <string>
//#include <fstream>

using namespace std;

const int MAX_len_S = 100, MAX_count_hate= 25, MAX_count_lock = 100; 
string name, hate, lock;
int NoChar[128], NoNum[MAX_len_S + 2];
int i, j, k;
char love;

void in()
{
     //ifstream cin ("F.in");
     getline(cin, name);
     getline(cin, hate);
     getline(cin, lock);
     cin >>love;
}

void solution()
{
     for (i=0; i<hate.size(); i+=2)
       {
         NoChar[hate[i]] = 1;
       }
     for (j=0; j<lock.size(); j+=2)
       {
         NoNum[lock[j]-'0'] = 1; 
       }
     for (k=0; k<name.size(); k++)
      {
        if ( (NoChar[name[k]] == 1) && (NoNum[k] != 1) ) {name[k] = love;}
      }  
}

void out()
{
    //ofstream cout ("F.out");
     //cout <<name <<"\n";
     /*cout <<name <<"\n"; 
     cout <<hate <<"\n" ;
     cout <<lock <<"\n" ;    
     cout <<love <<"\n" ;*/
     cout <<name <<"\n"; //system("PAUSE");
     //cout <<lock['2'-'0'] <<"\n";
        /* for (j=0; j<name.size(); j+=1)
       {
         cout  <<NoNum[lock[j]-'0'] <<" " ; 
       }*/
     /*for (i=0; i<128; i++)
       {
         cout <<NoChar[i] <<" ";
       }
       cout <<"\n";
     for (j=0; j<100; j++)
       {
         cout <<NoNum[j] <<" ";
       }
       cout <<"\n";
       cout <<love <<"\n";*/
}

int main()
{
in();
solution();
out();
return 0;
}
