#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> selectionKSmallest(vector<int> nums, int k) {
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
            swap(nums[i], nums[minIndex]);
        }
        return vector<int>(nums.begin(), nums.begin() + k);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {29, 10, 14, 37, 13, 42};
    vector<int> resultado = sol.selectionKSmallest(nums, 3);
    for (int i = 0; i < resultado.size(); i++) {
        cout << resultado[i] << (i == resultado.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}
