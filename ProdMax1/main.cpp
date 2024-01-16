#include <iostream>

using namespace std;
int a[100001], n;

int pivotare(int st, int dr) {
    int i = st, j = dr, pasi = 0, pasj = 1;
    while (i < j) {
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            swap(pasi, pasj);
        }
        i = i + pasi;
        j = j - pasj;
    }
    return i;
}

// Algoritm Quicksort -> sortam in stanga si in dreapta pivotului repetat
void quicksort(int st, int dr) {
    if (st < dr) {
        int newPivot = pivotare(st, dr);
        quicksort(st, newPivot - 1);
        quicksort(newPivot + 1, dr);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Sortam crescator elementele, de la indicele 1 pana la n
    quicksort(1, n);

    long long x, y;
    x = (long long) a[n] * a[n - 1];
    y = (long long) a[1] * a[2];

    // Consideram si cazul in care cele mai mici 2 numere sunt negative
    // si prin inmultire rezulta un numar mai mare decat produsul ultimelor 2.
    if (x >= y) {
        cout << x;
    } else { // a[1], a[2] < 0; a[1] * a[2] > a[n - 1] * a[n]
        cout << y;
    }
    return 0;
}