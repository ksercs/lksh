#include <iostream>
#include <fstream>

using namespace std;

int a, b, c, d;
int main()
{
    ifstream cin ("min.in");
    ofstream cout ("min.out");
  cin >>a >>b >>c >>d;
  if (a>b) {a=b;}
  if (a>c) {a=c;}
  if (a>d) {a=d;}
  cout <<a <<"\n";
return 0;
}
