#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};

    auto position = lower_bound(vec.begin(), vec.end(), 8);  // 8以上の要素のうち、最小の要素
    int idx_lower = distance(vec.begin(), position);
    cout << "vec[" << idx_lower << "] = " << vec[idx_lower] << "\n";

    // cout << "vec[" << idx_lower << "] = " << *position << "\n"; でも良い

    position = upper_bound(vec.begin(), vec.end(), 8);  // 8より大きい要素のうち、最小の要素
    idx_lower = distance(vec.begin(), position);
    cout << "vec[" << idx_lower << "] = " << vec[idx_lower] << "\n";

    cout << upper_bound(vec.begin(), vec.end(), 8) - lower_bound(vec.begin(), vec.end(), 8) << endl; // vec中の8の個数
    
}
