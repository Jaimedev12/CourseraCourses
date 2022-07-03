#include <iostream>

typedef unsigned long long int ulli;

using namespace std;

ulli getFibonacciLastDigitFast(ulli n){

  // Fibonacci numbers (last digit) repeat after the 60th number
  n %= 60;
  
  ulli arr[n];

  arr[0] = 0;
  arr[1] = 1;
  
  for (int i = 2; i <= n; i++){
    arr[i] = arr[i-1] + arr[i-2];
  }

  return arr[n] % 10;
}

/*
int get_fibonacci_last_digit_naive(int n) {
  if (n <= 1)
      return n;

  int previous = 0;
  int current  = 1;

  for (int i = 0; i < n - 1; ++i) {
    int tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % 10;
}
*/

int main() {
  int n;
  cin >> n;
  cout << getFibonacciLastDigitFast(n) << endl;
}
