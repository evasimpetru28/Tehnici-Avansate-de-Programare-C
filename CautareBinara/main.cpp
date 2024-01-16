#include <iostream>

using namespace std;

int m, n;

bool binarySearch(int x[], int elem, int st, int dr) {
    if (st > dr) { // Elementul nu se afla in lista
        return false;
    }
    int mijloc = (st + dr) / 2;
    if (elem == x[mijloc]) { //Elementul a fost gasit
        return true;
    } else {
        if (elem > x[mijloc]) {
            st = mijloc + 1;
        } else {
            dr = mijloc - 1;
        }
        binarySearch(x, elem, st, dr);
    }

}

int main() {

    cin >> n;
    int x[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    cin >> m;
    int y[m];
    for (int i = 0; i < m; ++i) {
        cin >> y[i];
    }

    // Cautarea binara se realizeaza in vectorul sorta, adica x
    // deci parcurgerem vectorul y si le cautam in x
    for (int i = 0; i < m; ++i) {
        cout << binarySearch(x, y[i], 0, n - 1) << " ";
    }

    return 0;
}
