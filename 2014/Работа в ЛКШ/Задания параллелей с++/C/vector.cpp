#include <vector>
#include <iostream>

using namespace std;

vector<int> data1;
vector<int> data2;

int main() {
  int n;
  cin >> n;
  data1.resize(n);
  cout << data1.size() << '\n';
  for (int i = 0; i < n; ++i) {
    cin >> data1[i];
  }
  data2.reserve(1e5);
  cout << data2.size() << '\n';
  int current;
  while (cin >> current) {
    data2.push_back(current);
  }
  cout << data2.size() << '\n';
  return 0;
}