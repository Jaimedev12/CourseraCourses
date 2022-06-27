#include <iostream>
#include <vector>
#include <algorithm>

#define lli long long int

using namespace std; 

lli MaxPairwiseProduct(const vector<lli>& numbers) {
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
    int n;
    cin >> n;
    vector<lli> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}