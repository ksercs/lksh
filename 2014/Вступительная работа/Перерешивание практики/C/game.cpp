#include <iostream>
#include <fstream>

using namespace std;


int const SUM=100;
const char boygirl[2][12]={"ENDER","VALENTINE"};

int n=1, ch, i, sum=0, g;
int a[SUM+2]; 

void in()
{
      ifstream cin ("game.in");
          for (i=1; i<=SUM; i++)
    {
          cin >>a[i];
    }
}

void solution()
{
      for (g=1; g<=SUM; g++)
        {
          sum=sum+a[g]; 
          if (sum>SUM){break;} 
          n=n+1; 
        }
     
}

void out()
{
    ofstream cout ("game.out");
    cout <<boygirl[n%2] <<"\n";
}

int main()
{
in();
solution();
out();
return 0;
}


