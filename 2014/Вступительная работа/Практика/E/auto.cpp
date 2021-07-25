#include <iostream>
#include <fstream>

using namespace std;

int K, N, Q, nom, gr, y, ch=1, z, f=-1;

//1<K<4, 2<N<7, 2<Q<100.


int main()
{
    ifstream cin ("auto.in");
    ofstream cout ("auto.out");
    cin >>K>>N>>Q;

if (K==1) {nom=26;}
if (K==2) {nom=650;}
if (K==3) {nom=15600;}
if (K==4) {nom=358800;}

    for (y=1; y<=N; y++)
        {
           ch=ch*10; f=f+1;   
        }

   z=ch/100*2+f;

//cout <<nom <<" " <<ch <<" " <<z <<" ";
gr=nom*ch+z*26;
cout <<gr <<"\n";
    
return 0;
}
