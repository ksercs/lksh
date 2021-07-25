#include <iostream>
#include <fstream>
#include <algorithm>
//#include <conio.h>
#include <set>
using namespace std;

long long ice_house[10001+2], ice_house_count, ice_man_count, mid, length;
int p, L, R, mid_index, ch;
int used[10001+2];
pair <long long, pair <int, int> > pi;
typedef pair <long long, pair <int, int> > pairs; 
multiset <pairs> ms;
multiset <pairs>::iterator it;    

int binary_search_R(int zleft, int zright)
{
    //cout <<zleft <<" " <<zright <<"\n";
    if (zleft>zright) { mid_index=zleft; return mid_index;}
    int check;
    check = zleft+(zright-zleft)/2;
    if (ice_house[check] == mid) { mid_index = -(check); return mid_index;}
    if (ice_house[check] < mid) { binary_search_R(check+1, zright); }  
    if (ice_house[check] > mid) { binary_search_R(zleft, check-1); }
}


void in()
{
     ifstream cin ("ice-cream.in");
     cin >>ice_house_count >> ice_man_count;
     for (int i=0; i<ice_house_count; i++)
     {
         cin >>ice_house[i];
     }
}

void solution()
{ 
     L=0; R=ice_house_count-1;
     used[L]=used[R]=1;   
     mid=ice_house[L]+(ice_house[R]-ice_house[L])/2;
     length=-(ice_house[R]-ice_house[L]);
     pi.first=length; 
     pi.second.first=L; 
     pi.second.second=R;
     ms.insert(pi);
     it = ms.begin();        
     //cout <<(*it).first <<" " <<(*it).second.first <<" " <<(*it).second.second  <<"\n"; getch();
     //cout <<-(*it).first <<"\n"; getch();
    while(ch < ice_man_count-2)
  {   
      it = ms.begin();
     L = (*it).second.first;
     R = (*it).second.second;
     //cout <<-(*it).first <<" " <<(*it).second.first <<" " <<(*it).second.second  <<"\n\n\n\n"; getch();
     //cout <<-(*it).first <<"\n"; getch();
     mid=ice_house[L]+(ice_house[R]-ice_house[L])/2;     
     binary_search_R(L, R);
  if (mid_index<0) {mid_index*=(-1);}
  else  {
          if ( (used[mid_index]!=1) && (used[mid_index-1]!=1) ) {
                                                                 if ( (ice_house[mid_index]-mid) > (mid-ice_house[mid_index-1]) ) {mid_index-=1; }
                                                                }
          if (used[mid_index]==1) {mid_index-=1;}
        }
  used[mid_index]=1;
  //cout <<mid_index <<" " <<ice_house[mid_index] <<"\n\n\n\n";
  if ( (mid_index==R-1) && (mid_index!=L+1) ) { 
                                                ms.erase(*it);
                                                R=mid_index;
                                                length=-(ice_house[R]-ice_house[L]);
                                             //   cout <<length <<"\n\n"; getch();
                                                 pi.first=length; 
                                                 pi.second.first=L; 
                                                 pi.second.second=R; 
                                                 ms.insert(pi);
                                                 //it = ms.begin();        
                                                  //cout <<(*it).first <<" " <<(*it).second.first <<" " <<(*it).second.second  <<"\n"; getch();
                                                  //cout <<-(*it).first <<"\n"; getch();
                                                // cout <<"111111  " <<-length <<"\n";getch();                                        
                                              }
  else{if ( (mid_index!=R-1) && (mid_index==L+1) ) {
                                                ms.erase(*it);          
                                                L=mid_index;
                                                length=-(ice_house[R]-ice_house[L]);
                                                 pi.first=length; 
                                                 pi.second.first=L; 
                                                 pi.second.second=R; 
                                                 ms.insert(pi);                                               
                                                //cout <<"222222  " <<-length <<"\n";getch();
                                              } else{  
  //cout <<"Indeksi koordinat "<<L <<" " <<R <<"\n";
  if ( (mid_index!=R-1) && (mid_index!=L+1) ) {
                                                ms.erase(*it);       
                                                length=-(ice_house[R]-ice_house[mid_index]);
                                                 pi.first=length; 
                                                 pi.second.first=mid_index; 
                                                 pi.second.second=R; 
                                                 ms.insert(pi);
                                                 //cout <<"333331111  " <<-length <<"\n";     getch();       
                                                length=-(ice_house[mid_index]-ice_house[L]);
                                                 pi.first=length; 
                                                 pi.second.first=L; 
                                                 pi.second.second=mid_index; 
                                                 ms.insert(pi);
                                                 //cout <<"3333333322222  " <<-length <<"\n"; getch();                                                                                             
                                              } else  
  if ( (mid_index==R-1) && (mid_index==L+1) ) {
                                                ms.erase(*it);
                                                if ( (ice_house[mid_index]-ice_house[L]) > (ice_house[R]-ice_house[mid_index]) )       
                                                {length=-(ice_house[R]-ice_house[mid_index]);}
                                                else {length=-(ice_house[mid_index]-ice_house[L]);} 
                                                //cout <<"44444444  " <<-length <<"\n"; getch();                                                                                         
                                              }}}                                                    
  //cout <<L <<" " <<R <<" " <<mid <<"\n"; getch();
  //cout <<mid_index <<"\n"; getch(); 
   ch++;
  }
    
}

void out()
{
     ofstream cout ("ice-cream.out");
     /*for (int j=0; j<ice_man_count; j++)
     {
         cout <<sep[j] <<" ";
     }
     cout <<"\n";*/
     cout <<-length <<"\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
