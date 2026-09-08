#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long insertionInversions(vector<int> nums) {
        long long inversoes = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int chave = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > chave) {
                nums[j + 1] = nums[j];
                inversoes++;
                j--;
            }
            nums[j + 1] = chave;
        }
        return inversoes;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 4, 1, 3, 5};
    long long resultado = sol.insertionInversions(nums);
    cout << resultado << "\n";
    return 0;
}
