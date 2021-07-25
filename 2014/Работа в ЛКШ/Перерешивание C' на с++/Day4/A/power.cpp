#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>
//#include <conio.h>

using namespace std;


long long ch, stepen, modul;


long long f_power(long long os, long long step)
{
  //  cout << os <<" " <<step <<"\n"; getch();
    if (os == 1) {return 1;}
    if (step == 0) {return 1;}
    if (step == 1) {return (os % modul);}
    else         { 
                   if (step % 2 == 0) {cout <<"#"; long long temp = f_power (os, step / 2); return ( ((temp % modul) * (temp % modul)) % modul);}
                   else               {cout <<"$"; return ((f_power(os, step - 1) % modul) * (os % modul) ) % modul;} 
                 }
}
void in()
{
    ifstream cin ("power.in");
    cin >>ch >>stepen >>modul;
}

void solution()
{
}

void out()
{
     ofstream cout ("power.out");
 cout <<f_power(ch,stepen) <<"\n";
//cout <<ch <<" " <<stepen <<" " <<modul <<"\n";
}

int main()
{
    in();
  //  solution();
    out();
return 0;
}
