#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, k, q, l, r, x;
pair < int, int > ppl[70000+2];

int bin_search(int left, int right, int num)
{
    int mid;
    while (right-left > 1)
    {
        mid = (left + right) / 2;
        if (ppl[mid].first < num || (ppl[mid].first == num && ppl[mid].second < l))
        {
            left = mid;
        }
        else
        {
            if (ppl[mid].first > num || ppl[mid].first == num && ppl[mid].second > r)
            {
                right = mid;
            }
            else
            {
                return 1;
            }
        }
    }
    if (ppl[left].first == num && ppl[left].second >= l && ppl[left].second <= r || ppl[right].first == num && ppl[right].second >= l && ppl[right].second <= r)
    {
        return 1;
    }
    return 0;
}

int main()
{
    //ifstream cin("queries.in");
    //ofstream cout("queries.out");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ppl[i].first;
        ppl[i].second = i;
    }
    sort(ppl + 1, ppl + n + 1);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r >> x;
        cout << bin_search(1, n, x);
    }
    cout << "\n";
return 0;
}
