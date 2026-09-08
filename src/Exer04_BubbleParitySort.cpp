#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool deveTrocar(int a, int b) {
        bool aPar = a % 2 == 0;
        bool bPar = b % 2 == 0;
        if (aPar && !bPar) return false;
        if (!aPar && bPar) return true;
        if (aPar && bPar) return a > b;
        return a < b;
    }
    vector<int> bubbleParitySort(vector<int> nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (deveTrocar(nums[j], nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {5, 2, 9, 8, 1, 6, 3, 4};
    vector<int> resultado = sol.bubbleParitySort(nums);
    for (int i = 0; i < resultado.size(); i++) {
        cout << resultado[i] << (i == resultado.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}
