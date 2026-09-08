#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    pair<vector<int>, long long> bubbleSortSwapCount(vector<int> nums) {
        long long trocas = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    trocas++;
                }
            }
        }
        return {nums, trocas};
    }
};
int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 1, 5};
    pair<vector<int>, long long> resultado = sol.bubbleSortSwapCount(nums);
    for (int i = 0; i < resultado.first.size(); i++) {
        cout << resultado.first[i] << (i == resultado.first.size() - 1 ? "" : " ");
    }
    cout << "\n" << resultado.second << "\n";
    return 0;
}
