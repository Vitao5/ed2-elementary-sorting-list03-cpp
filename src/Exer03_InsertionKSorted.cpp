#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    pair<vector<int>, long long> insertionSortKSorted(vector<int> nums) {
        long long comparacoes = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int chave = nums[i];
            int j = i - 1;
            while (j >= 0) {
                comparacoes++;
                if (nums[j] > chave) {
                    nums[j + 1] = nums[j];
                    j--;
                } else {
                    break;
                }
            }
            nums[j + 1] = chave;
        }
        return {nums, comparacoes};
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 4, 6};
    pair<vector<int>, long long> resultado = sol.insertionSortKSorted(nums);
    for (int i = 0; i < resultado.first.size(); i++) {
        cout << resultado.first[i] << (i == resultado.first.size() - 1 ? "" : " ");
    }
    cout << "\n" << resultado.second << "\n";
    return 0;
}
