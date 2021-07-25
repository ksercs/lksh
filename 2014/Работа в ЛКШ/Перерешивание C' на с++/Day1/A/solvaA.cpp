#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

double lenght, ans;

int main()
{
    cin >> lenght;
    ans = (pow((lenght + 38.0), 3.0)) / 125.0 * 7.0;
    cout.setf(ios::showpoint); cout << ans << "\n"; getch();
return 0;
}
