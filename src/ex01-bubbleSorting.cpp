#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
class Solution {
public:
    pair<vector<int>, ll> bubbleSortSwapCount(vector<int> list) {
        int countSwap = 0;
        vector<int> vectorList = list;
        int sizeVetor  = list.size();

        for (int i = 0; i < sizeVetor -1; i++) {
            for (int j = 0; j < sizeVetor -i -1; j++) {
                if (vectorList[j] > vectorList[j + 1]) {
                    int temp = vectorList[j];

                    vectorList[j] = vectorList[j + 1];
                    vectorList[j + 1] = temp;
                    countSwap++;
                }
            }
        }
        cout << countSwap << endl;
        for (int i = 0; i < vectorList.size(); i++) {
            cout << vectorList[i] << " ";
        }
        return {list, 0};
    }
};

int main() {
    IOFAST();
    bubbleSortSwapCount({1,4,3,5});
    return 0;
}