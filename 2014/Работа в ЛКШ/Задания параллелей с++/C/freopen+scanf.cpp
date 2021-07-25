#include <cstdio>    // freopen, stdin, stdout

using namespace std;

int main() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n;
  char c1, c2, c3;
  char s[100];
  double d1, d2, d3;
  scanf("%d %c %s %c %lf %c %lf %lf", &n, &c1, s, &c2, &d1, &c3, &d2, &d3);
  // example content: "666 42__^_^__Billy ~.1 ?    3.5 1e-5"
  // there is a difference between "%d%c" and "%d %c"
  // single whitespace in pattern skips all subsequent whitespace characters
  // (including ' ', '\t', '\n').
  // DO NOT FORGET ABOUT "&"! Except for "%s".
  printf("%d %s %lf %lf %lf %c %c %c", n, s, d1, d2, d3, c1, c2, c3);
  fclose(stdout); // recommended but often not needed. Ensures that output file will be saved.
  return 0;
}