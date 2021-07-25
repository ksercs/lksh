#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long ans;
int num[20], used[20];

void DFS(int s, int f)
{
    /*for (int i = 0; i < n; i++)
    {
        cout << used[i] << " ";
    }
    cout << "\n";*/
    if (s == f)
    {
        long long ch = 1;
        int fl=0;
        for (int i = 0; i < n-1; i++)
        {
            if (used[i]) {ch*=(num[i]%m); ch%=m; fl = 1;}
        }
        long long pre_ans = fl*ch;
        ans = max(ans, pre_ans);
        /*for (int i = 0; i < n-1; i++)
        {
            cout << used[i] << " ";
        }
        cout << "1\n";*/
        pre_ans*=(num[n-1]%m);
        pre_ans%=m;
        ans = max(ans, pre_ans);
    }
    else
    {
        used[s] = 1;
        DFS(s+1, f);
        used[s] = 0;
        DFS(s+1, f);
    }
}

void in()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
}

void solution()
{
    DFS(0, n-1);
}

void out()
{
    cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
