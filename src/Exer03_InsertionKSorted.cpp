#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

void insertionSortKSorted(vector<int> list) {
    vector<int> vectorList = list;[cite: 1, 2]
    int sizeVetor = vectorList.size();[cite: 1, 2]
    int countComparisons = 0;

    for (int i = 1; i < sizeVetor; i++) {
        int key = vectorList[i];
        int j = i - 1;

        // Cada verificação de condição do while conta como uma comparação
        while (j >= 0) {
            countComparisons++;
            if (vectorList[j] > key) {
                vectorList[j + 1] = vectorList[j];
                j--;
            } else {
                break; // Parou de deslocar, mas a comparação ocorreu
            }
        }
        vectorList[j + 1] = key;
    }

    // Saída conforme especificado na questão
    for (int i = 0; i < sizeVetor; i++) {
        cout << vectorList[i] << (i == sizeVetor - 1 ? "" : " ");
    }
    cout << "\n";
    cout << countComparisons << "\n";
}

int main() {
    IOFAST();[cite: 1, 2]

    int n, k;
    if (cin >> n >> k) {
        vector<int> list(n);
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }
        insertionSortKSorted(list);
    }

    return 0;
}