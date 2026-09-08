#include <iostream>
#include <vector>

using namespace std;

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    IOFAST();

    int n;
    cin >> n;

    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    long long trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocas++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << vet[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    cout << trocas << "\n";

    return 0;
}
