#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

#define lli long long int

using namespace std; 


lli maxPairwiseProductFast(const vector<lli> &nums){

  int n = nums.size();
  
  int bigIndex1 = 0;
  for (int i = 0; i < n; i++){
    if ((nums[i] > nums[bigIndex1])){
      bigIndex1 = i;
    }
  }

  int bigIndex2 = -1;
  for (int i = 0; i < n; i++){
    if ((bigIndex1 != i) && ((bigIndex2 == -1) || (nums[i] > nums[bigIndex2]))){
      bigIndex2 = i;
    }
  }
  
  return (lli) nums[bigIndex1] * nums[bigIndex2];
}


// Slow version (checking all pairs)

lli maxPairwiseProduct(const vector<lli>& numbers) {
  lli max_product = 0;
  int n = numbers.size();

  for (int first = 0; first < n; ++first) {
    for (int second = first + 1; second < n; ++second) {
      max_product = max(max_product,
        numbers[first] * numbers[second]);
    }
  }

  return max_product;
}


int main() {

  int n = 0;

  // Ciclo de debugging
  /*while (true){
    n = rand() % 4 + 2;
    vector<lli> nums(n);

    for (int i = 0; i < n; i++){
      nums[i] = rand() % 10;
    }

    int r1 = maxPairwiseProduct(nums);
    int r2 = maxPairwiseProductFast(nums);

    cout << n << endl;

    for (int i = 0; i < n; i++){
      cout << nums[i] << " ";
    }

    cout << endl;
    
    if (r1 != r2){
      cout << r1 << " " << r2 << endl << endl;     
      break;
    } else{
      cout << "OK" << endl;
    }
  }
  */

  cin >> n;
  vector<lli> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  
  cout << maxPairwiseProductFast(nums) << "\n";
  return 0;
}