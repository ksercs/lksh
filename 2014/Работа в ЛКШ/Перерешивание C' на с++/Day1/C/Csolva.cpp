#include <iostream>
//#include <conio.h>
#include <string>

using namespace std;

string str;

void in()
{
     cin >>str;
}

void solution()
{
     if (str.size() == 1 and str=="s" ) {str= str + str;}
     else
         if (str[str.size()-1] == 's') {str= str+ str[str.size()-2] + str[str.size()-1];}
         if (str.size() > 10 ) {str= str + str;}
}

void out()
{
     cout << str <<"\n"; //getch();
}

int main()
{
in();
solution();
out();    
return 0;
}
