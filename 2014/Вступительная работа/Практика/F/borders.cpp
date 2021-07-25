#include <iostream>
#include <fstream>

using namespace std;

int i, n, m, k, f, g, j, t, p;
int xmin[22], ymin[22], xmax[22], ymax[22], ans[102][102];

int main()
{
    ifstream cin ("borders.in");
    ofstream cout ("borders.out");
    cin >>n >>m;
    cin >>k;
    for (i=1; i<=k; i++)
    {
        cin >>xmin[i] >>ymin[i] >>xmax[i] >>ymax[i];
    }
    /*cout <<n<<" " <<m <<"\n";
    cout <<k<<"\n";
    for (i=1; i<=k; i++)
    {
        cout <<Xmin[i]<<" " <<Ymin[i]<<" " <<Xmax[i]<<" " <<Ymax[i] <<"\n";
    }*/
    for (p=1; p<=k; p++)
    {
        
      for(g=ymin[p]; g<=ymax[p]; g++)
        {
                   ans[g][xmin[p]]=1; ans[g][xmax[p]]=1;
        }    
      for(f=xmin[p]; f<=xmax[p]; f++)
        {
                   ans[ymin[p]][f]=1; ans[ymax[p]][f]=1;}
        }  
      for (j=1; j<=m; j++)
        {
          for (t=1; t<=n; t++)
            {
                cout <<ans[j][t];
            }
          cout <<"\n";       
     }
    cout <<"\n";

return 0;
}
