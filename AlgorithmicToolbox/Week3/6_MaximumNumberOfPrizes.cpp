#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

typedef long long int lli;

vector<lli> optimal_summands(lli n) {
  lli k = floor((sqrt(8*n+1)-1)/2);

  vector<lli> summands(k);
  
  for (lli i = 0; i < k-1; i++){
    summands[i] = i+1;
    n -= i+1;
  }

  summands[k-1] = n;

  return summands;
}

int main() {
  lli n;
  std::cin >> n;
  vector<lli> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
