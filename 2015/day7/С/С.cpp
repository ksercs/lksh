#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

long long m, n, x, y, ans;

void in()
{
    ifstream cin("queen.in");
    cin >> m >> n;
    cin >> x >> y;
}

void solution()
{
    ans += m - 1;
    ans += n - 1;
    ans += min(x - 1, y - 1);
    ans += min(m - x, n - y);
    ans += min(x - 1, n - y);
    ans += min(y - 1, m - x);
}

void out()
{
     ofstream cout("queen.out");
     cout << ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
