#include <iostream>
#include <fstream>
//#include <string>
//#include <cstring>
//#include <conio.h>

using namespace std;


int ch_count, start, temp, finish;

    //ifstream in ("hanoi.in");
    //ofstream out ("hanoi.out");

void hanoy(int ch, int start, int finish, int temp)
{
    if (ch == 1){
                    cout <<start <<" " <<finish <<"\n";
                    //return 1, start, finish;
                    }
    else            {
                    hanoy(ch - 1, start, temp, finish);
                    cout <<start <<" " <<finish <<"\n";
                    hanoy(ch - 1, temp, finish, start);
                    }
}


int main()
{
    cin >> ch_count;
    start = 1;
    finish = 2;
    temp = 3;
    hanoy(ch_count, start, finish, temp);
return 0;
}
