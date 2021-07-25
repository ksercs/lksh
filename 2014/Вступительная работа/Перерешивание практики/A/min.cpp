#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int b=4, maxCH=20000, maxN=10000;

long long lon[4];
int zn[4], celS[4], celF[4], drS[4], drF[4];
int ans;
char str[4][maxCH];

int men(int str1, int str2)
{
  for ( int f=celS[str1]; f<=celF[str1]; f++)
     {
      for ( int d=celS[str2]; d<=celF[str2]; d++)
        {
            if (str[str1][f]<str[str2][d]) {ans=str1; break;}
            if (str[str1][f]>str[str2][d]) {ans=str2; break;}
            if (str[str1][f]==str[str2][d]) {ans=str1; break;}            
        }            
     }
}

void in()
{
     ifstream cin("min.in");
     for ( int i=0; i<=b-1; i++)
      {
         cin.getline(str[i],maxCH);
      }
}

void solution()
{  
  int t[4];
  int d, j;
      for (int i=0; i<=b-1; i++)
      {
         lon[i]=strlen(str[i]); 
         
         if (str[i][0]=='-') {zn[i]=0; celS[i]=0;}
         else                {
                               if (str[i][0]=='+') {zn[i]=1; celS[i]=1;}
                               else                {zn[i]=1; celS[i]=0;}
                             }
         
         for (int g=0; g<=lon[i]; g++)
         {
           if (str[i][g]==',') {celF[i]=g-1; drS[i]=g+1; drF[i]=lon[i]-celS[i]; t[4]=1; break;}
         }
         if (t[i]!=1) {celF[i]=lon[i]-celS[i];} 
      }
      
      for (int l=0; l<=b-1; l++)
      {
          lon[l]=lon[l]-celS[l];
          celF[l]=celF[l]-celS[l];
          drS[l]=drS[l]-celS[l];
          drF[l]=drF[l]-celS[l];   
      }
      
void out()
{
     ofstream cout ("min.out");
     
}

int main ()
{
    in();
    solution();
    out();
return 0;
}
