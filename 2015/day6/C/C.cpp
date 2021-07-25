#include <iostream>
//#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <string> cm;
vector <char> ans;
int n, k;

void subset(int balance, int cnt)
{
    string str;
    str = "";
    if (ans.size() == 2 * cnt)
    {
        for (int i = 0; i < ans.size(); i++)
        {
           str += ans[i];
        }
        cm.push_back(str);
        if (cm.size() == k)
        {
            return;
        }
    }
    else
    {
        if (2 * cnt - ans.size() >= balance + 1)
        {
            ans.push_back('(');
            subset(balance + 1, cnt);
            ans.pop_back();
        }
        if (balance > 0)
        {
            ans.push_back(')');
            subset(balance - 1, cnt);
            ans.pop_back();
        }
    }
}

void in()
{
    //ifstream cin("build.in");
    cin >> n >> k;
}

void solution()
{
    subset(0, n);
    sort(cm.begin(), cm.end());
}

void out()
{
     //ofstream cout("build.out");
     cout << cm[k-1] << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
