#include <iostream>
#include <vector>

using namespace std;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

bool deveTrocar(int a, int b) {
    bool aPar = a % 2 == 0;
    bool bPar = b % 2 == 0;

    if (aPar && !bPar) return false;
    if (!aPar && bPar) return true;
    if (aPar && bPar) return a > b;
    return a < b;
}

int main() {
    IOFAST();

    int n;
    cin >> n;

    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (deveTrocar(vet[j], vet[j + 1])) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << vet[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
