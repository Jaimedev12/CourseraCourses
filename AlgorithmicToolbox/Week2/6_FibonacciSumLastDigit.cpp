#include <iostream>

using namespace std;

typedef long long int lli;

int getLastDigitsSum(int n){

  if (n <= 1){
    return n;
  }
  
  int sumOfFirst60Digits = 280;
  lli timesRepeated = n / 60;
  n %= 60;

  lli fib;

  int lastDigitSum = 1;
  int lastDigit;

  lli prevPrev = 0;
  lli prev = 1;

  for (int i = 2; i <= n; i++){
    fib = prevPrev + prev;
    prevPrev = prev;
    prev = fib;
    lastDigit = fib % 10;
    lastDigitSum += lastDigit;
    //cout << lastDigit << endl;
    //cout << lastDigitSum << endl;
  }

  return (lastDigitSum + (sumOfFirst60Digits * timesRepeated)) % 10;
  
}

int fibonacci_sum_naive(long long n) {
  if (n <= 1)
    return n;

  long long previous = 0;
  long long current  = 1;
  long long sum      = 1;

  for (long long i = 0; i < n - 1; ++i) {
    long long tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
    sum += current;
  }

  return sum % 10;
}

int main() {
  long long n = 2;
  cin >> n;
  //cout << fibonacci_sum_naive(n);
  
  cout << getLastDigitsSum(n);

  


  
}
