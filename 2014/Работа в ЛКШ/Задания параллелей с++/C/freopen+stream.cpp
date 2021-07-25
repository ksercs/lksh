#include <cstdio>    // freopen, stdin, stdout
#include <iostream>  // cin, cout
#include <string>

using namespace std;

int main() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  ios_base::sync_with_stdio(false); // not needed, makes i/o operations run faster
  int n;
  char c1, c2, c3;
  string s;
  double d1, d2, d3;
  cin >> n >> c1 >> s >> c2 >> d1 >> c3 >> d2 >> d3;
  // example content: "666 42__^_^__Billy ~.1 ?    3.5 1e-5"
  cout << n << ' ' << s << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << c1
    << ' ' << c2 << ' ' << c3 << '\n';
  fclose(stdout); // recommended but often not needed. Ensures that output file will be saved.
  return 0;
}