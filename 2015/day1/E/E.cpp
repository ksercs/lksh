#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, k, ch, answer;

vector <int> vec;

char mass1[11] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char mass2[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int str_to_int(string s)
{
    int ans = 0, num, ten;
    for (int i = 0; i < s.size(); i++)
    {
        ten = 1;
        num = s[i] - '0';
        for (int g = 1; g < s.size() - i; g++)
        {
            ten *= 10;
        }
        ans += num * ten;
    }
    return ans;
}

void out()
{
    ofstream cout("lexsort.out");
    for (int h = 0; h < vec.size(); h++)
    {
        cout << vec[h] <<"\n";
    }
    //cout << answer << "\n";
}

void dfs(string s, int ind)
{
  for (int i = 0; i < 10; i++)
  {
      int num = str_to_int(s+mass2[i]);
      if (num <= n)
      {
        s += mass2[i];
        ch++;
        //cout << ch <<"\n";
        vec.push_back(num);
        if (ch == k) {answer = num; out(); exit(0);}
        dfs(s, ind+1);
        s.erase(s.size()-1, s.size());
      }
  }
}

void in()
{
    ifstream cin("lexsort.in");
    cin >> n >> k;
}

void solution()
{
  string str;
  for (int g = 0; g < 9; g++)
  {
      str += mass1[g];
      int nu = str_to_int(str);
      if (nu <= n)
      {
        ch++;
        vec.push_back(nu);
        if (ch == k) {answer = nu; out();}
        else{dfs(str, 1);}
      }
      str.clear();
  }
}

int main()
{
  in();
  solution();
  return 0;
}
