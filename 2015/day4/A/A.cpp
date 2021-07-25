#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("rect.in");
    ofstream cout("rect.out");

    const int MAX_SIZE = int(1e9);

    int n, minx = MAX_SIZE + 1, miny = MAX_SIZE, maxx = -1 * MAX_SIZE + 1, maxy = -1 * MAX_SIZE, xl, xr, yl, yr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> xl >> yl >> xr >> yr;
        maxx = max(maxx, xl);
        minx = min(minx, xr);
        maxy = max(maxy, yl);
        miny = min(miny, yr);
    }
    if (minx >= maxx && miny >= maxy)
    {
        cout << maxx << " " << maxy << " " << minx << " " << miny << "\n";
    }
    else
    {
        cout << "-1\n";
    }
    return 0;
}
