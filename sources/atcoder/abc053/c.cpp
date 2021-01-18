#include <iostream>
using namespace std;

using ll = long long;

int main(int argc, char *argv[]) {
  ll x;
  cin >> x;

  // just be greedy
  // and do 6/5 forever
  ll div11 = x / 11;
  ll y = x - div11 * 11;

  ll ans = div11 * 2;
  if(y >= 7) {
    ans += 2;
  } else if (y != 0) {
    ans += 1;
  }
  cout << ans << endl;
}
