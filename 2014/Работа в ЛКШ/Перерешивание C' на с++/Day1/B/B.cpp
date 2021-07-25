#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int place[100 + 2], i;
char champion[100 + 2];

void in()
{
     while(cin >> place[i++]);
}
/*void solution()
{
}*/
void out()
{
     for (int k=0; k<(i-1); k++)
     {
         cout << place[k] <<" "; 
     }
     cout <<place[i] <<"\n"; 
     
}


int main()
{
in();
out();
getch();
return 0;
}
