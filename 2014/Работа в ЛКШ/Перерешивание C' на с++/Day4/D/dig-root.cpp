#include <iostream>
#include <fstream>
#include <set>
//#include <conio.h>
//#include <string>
//#include <cstring>

using namespace std;

long long numbers[200+2], digital_root_numbers[200+2], mass_index[200+2] ;
int i;

pair <int, int> para;
multiset < pair <int, int> > mm;
multiset < pair <int, int> >::iterator it;

long long digital_root_R(long long number)
{
     if (number < 10) {return number;}
      int summ=0;
     while (number>0)
     {
        summ += number % 10;
        number /= 10;
     }
     return digital_root_R(summ);
}

/*long long fcmp(int index1, int index2)
{
    if (digital_root_numbers[index1] == digital_root_numbers[index2]) {
                                                                       if (numbers[index1] > numbers[index2]) 
                                                                        {return 1;}
                                                                      }      
    if (digital_root_numbers[index1] < digital_root_numbers[index2]) {return 1;}    
    else                                                             {return 0;}
}*/


void in()
{
ifstream cin ("dig-root.in");
    while (cin>>numbers[i])
    {      
           i++;   
    }
}

void solution()
{
     //cout <<i <<"\n"<<"\n"<<"\n"; getch();
     for (int h=0; h<i; h++)
    {
        digital_root_numbers[h] = digital_root_R(numbers[h]);
        //cout <<digital_root_numbers[h] <<" "; getch();
    }
     for (int y=0; y<i; y++)
    {
        para.first = digital_root_numbers[y];
        para.second = numbers[y];
        mm.insert(para);
        //cout <<pi.first <<" " <<pi.second <<"\n"; getch();
    }
     /*for (int g=0; g<i; g++)
    {
        mass_index[g]=g;
    }*/
    //sort(mass_index, mass_index+i, fcmp);
}

void out()
{
     ofstream cout ("dig-root.out");
     /*for(int b=0; b<i; b++)
    {
        cout <<mass_index[b] <<" ";        
    }
       cout <<"\n";
    for(int j=0; j<i; j++)
    {
        cout <<numbers[j] <<" ";        
    }
       cout <<"\n";
       for(int j=0; j<i; j++)
    {
        cout <<digital_root_numbers[j] <<" ";        
    }
       cout <<"\n";*/
       
       /* for(int r=0; r<i; r++)
    {
        if (r!=i-1) {cout <<numbers[mass_index[r]] <<" ";}
        else        {cout <<numbers[mass_index[r]];}        
    }
       cout <<"\n";*/
    for(it=mm.begin(); it!=mm.end(); it++)
    {
     cout <<(*it).second <<" ";        
    }
       cout <<"\n";
}

int main()
{
    in();
    solution();
    out();
return 0;
}
