#include <iostream>

using namespace std;

int gcd_fast(int a, int b){
  int rest = 0;

  while(a != 0 && b != 0){
    if (a > b){
      a = a % b;    
    } else if(a < b){
      b = b % a;
    } else{
      return a;
    }  
  }

  return max(a, b);
}

/*
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
*/

int main() {
  int a, b;
  cin >> a >> b;
  //cout << gcd_naive(a, b) << endl;
  cout << gcd_fast(a, b) << endl;
  return 0;
}
