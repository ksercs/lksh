#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

char place, champion[100 + 2], ch;

void in()
{
     ifstream cin ("d.in");
     cin.getline();
}
/*void solution()
{
}*/
void out()
{
     ofstream cout ("d.out");
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
return 0;
}
