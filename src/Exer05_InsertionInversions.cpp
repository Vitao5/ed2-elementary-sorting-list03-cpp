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

    long long inversoes = 0;

    for (int i = 1; i < n; i++) {
        int chave = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > chave) {
            vet[j + 1] = vet[j];
            inversoes++;
            j--;
        }
        vet[j + 1] = chave;
    }

    cout << inversoes << "\n";

    return 0;
}
