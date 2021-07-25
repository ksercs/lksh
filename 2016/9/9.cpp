#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector <string> cm;
vector <char> ans;
int n, k;
string str;

void out()
{
     cout << cm[k] << "\n";
}

void subset(int balance, int cnt)
{
    //cout << balance << " " <<cnt << "\n"; system("PAUSE");
    str = "";
    if (ans.size() == 2 * cnt)
    {
        for (int i = 0; i < ans.size(); i++)
        {
           str += ans[i];
        }
        //cout << str << "\n"; system("PAUSE");
        cm.push_back(str);
        /*if (cm.size() == k+1)
        {
           out(); exit(0);
        }*/
    }
    else
    {
        if (2 * cnt - ans.size() >= balance + 1)
        {
            //cout <<"(\n";
            ans.push_back('(');
            subset(balance + 1, cnt);
            ans.pop_back(); ans.resize(ans.size());
        }
        if (balance > 0)
        {
            //cout <<")\n";
            ans.push_back(')');
            subset(balance - 1, cnt);
            ans.pop_back(); ans.resize(ans.size());
        }
    }
}

void in()
{
    cin >> n >> k;
}

void solution()
{
    subset(0, n);
}

int main()
{
    in();
    solution();
    //out();
    return 0;
}
