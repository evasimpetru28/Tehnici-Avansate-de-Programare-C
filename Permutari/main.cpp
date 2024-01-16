#include <bits/stdc++.h>

using namespace std;
ifstream fin("permutari.in");
ofstream fout("permutari.out");
int n, x[10], viz[10];

void afisare() {
    for (int i = 1; i <= n; i++) {
        fout << x[i] << " ";
    }
    fout << "\n";
}

void bck(int k) {
    for (int i = 1; i <= n; i++)
        if (!viz[i]) {
            x[k] = i;
            viz[i] = 1;
            if (k == n)afisare();
            else bck(k + 1);
            viz[i] = 0;
        }
}

int main() {
    fin >> n;
    bck(1);
    return 0;
}