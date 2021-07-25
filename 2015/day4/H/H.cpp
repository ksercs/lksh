#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int st1, st2, fn1, fn2;
string str1[] = {"001.dat", "002.dat", "003.dat", "004.dat", "005.dat", "006.dat", "007.dat", "008.dat", "009.dat", "010.dat", "011.dat", "012.dat", "013.dat", "014.dat", "015.dat", "016.dat", "017.dat", "018.dat", "019.dat", "020.dat"};
string str2[] = {"001.ans", "002.ans", "003.ans", "004.ans", "005.ans", "006.ans", "007.ans", "008.ans", "009.ans", "010.ans", "011.ans", "012.ans", "013.ans", "014.ans", "015.ans", "016.ans", "017.ans", "018.ans", "019.ans", "020.ans"};
void in()
{
    srand(time(0));
    st1 = rand() % 1000000000;
    st2 = rand() % 1000000000;
    fn1 = rand() % 1000000000;
    fn2 = rand() % 1000000000;
}

void solution()
{
    if (st1 > fn1)
    {
        swap(st1, fn1);
    }
    if (st2 > fn2)
    {
        swap(st2, fn2);
    }
    if (st1 > st2)
    {
        swap(st1, st2);
        swap(fn1, fn2);
    }
}

void out()
{
    for (int i = 0; i < 20; i ++)
    {
          ofstream cout(str1[i]);
          cout <<st1 <<" " <<fn1 <<" " <<st2 <<" " <<fn2 <<"\n";
          ofstream cout (str2[i]);
              if (fn1 < st2)
    {
        cout << "0\n";
    }
    if (st2 < fn1)
    {
        if (fn2 >= fn1)
        {
            cout << fn1 - st2 + 1 << "\n";
        }
        else
        {
            cout << fn2 - st2 + 1 << "\n";
        }
    }
    if (st2 == fn1)
    {
        cout << "1\n";
    }
    }
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
