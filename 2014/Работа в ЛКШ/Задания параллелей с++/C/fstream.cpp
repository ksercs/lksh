#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream in("test.in");
  ofstream out("test.out");
  int n;
  char c1, c2, c3;
  string s;
  double d1, d2, d3;
  in >> n >> c1 >> s >> c2 >> d1 >> c3 >> d2 >> d3;
  // example content: "666 42__^_^__Billy ~.1 ?    3.5 1e-5"
  out << n << ' ' << s << ' ' << d1 << ' ' << d2 << ' ' << d3 << ' ' << c1
    << ' ' << c2 << ' ' << c3 << '\n';
  out.close(); // recommended but often not needed. Ensures that output file will be saved.
  return 0;
}