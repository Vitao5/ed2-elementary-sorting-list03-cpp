#include <iostream>
#include <vector>
#include <utility>

using namespace std;

using ll = long long;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void showMinNumberVector(vector<int> list, int countMin) {
    for (int i = 0; i < countMin; i++) {
        cout << list[i] << " ";
    }
}

void selectionSort(vector<int> list, int countMin) {
    vector<int> listVector = list;
    int sizeVetor = listVector.size();
    int minIndex;
    for (int i = 0; i < sizeVetor - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < sizeVetor; j++) {
            if (listVector[j] < listVector[minIndex]) {
                minIndex = j;
            }
        }

        int temp = listVector[i];
        listVector[i] = listVector[minIndex];
        listVector[minIndex] = temp;

    }

    showMinNumberVector(listVector, countMin);

}

int main() {
    IOFAST();
    selectionSort({8,5,3,9,1}, 3);

    return 0;
}