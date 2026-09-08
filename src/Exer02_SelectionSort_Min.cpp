#include <iostream>
#include <vector>

using namespace std;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    IOFAST();

    int n, k;
    cin >> n >> k;

    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    for (int i = 0; i < k; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[minIndex]) {
                minIndex = j;
            }
        }
        int temp = vet[i];
        vet[i] = vet[minIndex];
        vet[minIndex] = temp;
    }

    for (int i = 0; i < k; i++) {
        cout << vet[i] << (i == k - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
