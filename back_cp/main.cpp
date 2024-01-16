#include <iostream>

using namespace std;

int n, m;
char s[27];

bool checkSubstring(int k) {
    return !(k >= 2 && s[k - 1] == 'P' && s[k - 2] == 'C' && s[k] == 'C');
}

void bkt(int k, int countC, int countP) {
    if (k > n + m) {
        for (int i = 1; i <= n + m; i++) {
            cout << s[i];
        }
        cout << endl;
    } else {
        // Verificam daca putem adauga litera C
        if (countC < n && (k < 2 || s[k - 1] != 'C' || s[k - 2] != 'C')) {
            s[k] = 'C';
            bkt(k + 1, countC + 1, countP);
        }

        // Verificam daca putem adauga litera P
        if (countP < m && (k < 2 || s[k - 1] != 'P' || s[k - 2] != 'C')) {
            s[k] = 'P';
            bkt(k + 1, countC, countP + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    bkt(1, 0, 0);
    return 0;
}