#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, ans;
vector <pair <int,int> > vir;

void in()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      int ch, ch1;
      cin >> ch;
      if (ch1 != ch) vir.push_back(make_pair(ch,1));
      ch1 = ch;
  }
}

void solution()
{
    int i = 1;
    /*for (int j = 0; j < vir.size(); j++)
    {
        cout << vir[j].first << " ";
    }
    cout << "\n";*/
    while (i != vir.size()-1)
    {
        //cout << i << ": " << vir[i-1].first << " " << vir[i+1].first << "\n"; system("pause");
        if (vir.size()==1) break;
        if (i==0) {i++; continue;}
        if (vir[i-1].first == vir[i+1].first)
        {
            vir.erase(vir.begin() + i-1);
            vir.erase(vir.begin() + i-1);
            /*for (int j = 0; j < vir.size(); j++)
            {
                cout << vir[j].first << " ";
            }
            cout << "\n";*/
            ans++;
            i-=2;
        }
        i++;
    }
    ans += vir.size();
}

void out()
{
   cout <<ans << "\n";
}

int main()
{
    in();
    solution();
    out();
    return 0;
}
