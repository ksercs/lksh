#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 20;
int cnt[MAXN][MAXN];
vector<int> data;

void init() {
  for (int i = 1; i < MAXN; i++) {
    cnt[0][i] = 1;
    cnt[i][i] = 1;
    for (int j = i - 1; j > 0; j--) {
      cnt[i][j] = cnt[i - j][j] + cnt[i][j + 1];
    }
  }
}

void fillPartByNum(int n, int m) {
  data.clear();
  int lower = 1;
  while (n > 0) {
    if (m < cnt[n - lower][lower]) {
      data.push_back(lower);
      n -= lower;
    } else {
      m -= cnt[n - lower][lower];
      lower++;
    }
  }
}

int numByPart(int n) {
  int m = 0;
  int lower = 1;
  int j = 0;
  while (n > 0) {
    if (data[j] == lower) {
      j++;
      n -= lower;
    } else {
      m += cnt[n - lower][lower];
      lower++;
    }
  }
  return m;
}

int main() {
  init();
  int n;
  cin >> n;
  for (int m = 0; m < cnt[n][1]; m++) {
    fillPartByNum(n, m);
    for (int i = 0; i < data.size(); i++) {
      cout << data[i] << ' ';
    }
    cout << "num = " << numByPart(n) << '\n';
  }
  return 0;
}