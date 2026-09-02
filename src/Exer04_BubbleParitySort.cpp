#include <iostream>
#include <vector>
#include <utility>

using namespace std;


#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    IOFAST();

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    int comparacoes = 0;

    for (int i = 1; i < n; i++) {
        int chave = vet[i];
        int j = i - 1;

        while (j >= 0) {
            comparacoes++;

            if (vet[j] > chave) {
                vet[j + 1] = vet[j];
                j--;
            } else {
                break;
            }
        }
        vet[j + 1] = chave;
    }

    for (int i = 0; i < n; i++) {
        cout << vet[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    cout << comparacoes << "\n";

    return 0;
}