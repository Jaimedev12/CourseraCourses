#include <iostream>

using namespace std;

typedef long long int lli;

lli lcm_fast(int a, int b){

  int hcf = a;
  int temp = b;

  while (hcf != temp){
    if (hcf > temp){
      hcf -= temp;
    } else{
      temp -= hcf;
    }
  }

  //cout << "HCF: " << hcf << endl;
  //cout << "a * b: " << a*b << endl;
 
  return ((long long) a * b) / hcf;
}

/*
lli lcm_naive(int a, int b) {
  for (long l = 1; l <= (lli) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (lli) a * b;
}
*/

int main() {
  int a, b;
  cin >> a >> b;
  //cout << lcm_naive(a, b) << endl;
  cout << lcm_fast(a, b) << endl;
  return 0;
}
