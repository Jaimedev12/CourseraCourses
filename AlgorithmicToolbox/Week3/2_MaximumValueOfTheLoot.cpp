#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double maxValue = 0.0;
  double maxRatio = 0.0;

  while(!(capacity == 0 || weights.empty())){

    int n = weights.size();

    int m = 0;
    maxRatio = 0;
    for (int i = 0; i < n; i++){
      if (((double) values[i] / weights[i]) > maxRatio){
        m = i;
        maxRatio = ((double) values[i] / weights[i]);
      }
    }
    
    double amount = std::min(weights[m], capacity);
  
    double value = values[m] * (amount/weights[m]);
  
    weights.erase(weights.begin() + m);
    values.erase(values.begin() + m);
  
    if (weights[m] <= capacity){
      capacity -= weights[m];
    } else{
      capacity -= ((double)capacity / weights[m]) * weights[m];
      
    }

    maxValue += value;
  }

  /*
  if(capacity == 0 || weights.empty()){return 0;}

  int m = 0;
  for (int i = 0; i < n; i++){
    if (values[i] > maxValue){
      m = i;
      maxValue = values[i];
    }
  }

  cout << "M: " << m << endl;
  cout << "Size: " << weights.size() << endl;

  double amount = std::min(weights[m], capacity);
  
  double value = values[m] * (amount/weights[m]);

  weights.erase(weights.begin() + m);
  values.erase(values.begin() + m);

  if (weights[m] <= capacity){
    capacity -= weights[m];
  } else{
    cout << "Entró" << endl;
    capacity -= (capacity / weights[m]) * weights[m];
  }

  cout << "Capacity: " << capacity << endl;

  return value + get_optimal_value(capacity, weights, values);  

  */

  return maxValue;

}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}

