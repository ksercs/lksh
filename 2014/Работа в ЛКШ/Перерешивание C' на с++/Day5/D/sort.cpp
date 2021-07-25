#include <iostream>
#include <fstream>
#include <map>
//#include <conio.h>

using namespace std;

int count_num, main_num, help_num;
pair <int, int> pi;
multimap <int, int > mp;
multimap <int, int > ::iterator it;


void in()
{
     ifstream cin ("sort.in");
     cin >> count_num;
     for (int i=0; i<count_num; i++)
     {
         cin >>main_num >>help_num;
         pi.first=main_num; pi.second=help_num;
         mp.insert(pi);
         //cout <<pi.first <<" " <<pi.second <<"\n"; getch();
     }
}

void solution()
{ 
}

void out()
{
     ofstream cout ("sort.out");
     //cout <<count <<"\n"; getch();
     //int sz= mp.size();
     //cout <<sz <<"\n";
     for (it=mp.begin(); it!=mp.end(); it++)
     {
         cout <<(*it).first <<" " <<(*it).second <<"\n"; //getch();
     }
}

int main()
{
    in();
    //solution();
    out();
    return 0;
}
