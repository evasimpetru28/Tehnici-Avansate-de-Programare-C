#include<iostream>

using namespace std;

int s[101], n;

void bkt(int k) {

    int i;
    cout << "Nivel " << k << endl;
    cout << "s[k]=" << s[k] << endl;


    // VARIANTA 1: scade cu 1, daca poate
    if (s[k - 1] != 0) {
        s[k] = s[k - 1] - 1;
        if (k == n - 1) {
            for (i = 1; i <= n; i++) {
                cout << s[i] << " ";
            }
            cout << endl;
        } else {
            bkt(k + 1);
        }


    }

    // VARIANTA 2: creste cu 1
    if (s[k - 1] != 9) {
        s[k] = s[k - 1] + 1;
        if (k == n - 1) {
            for (i = 1; i <= n; i++) {
                cout << s[i] << " ";
            }
            cout << endl;
        } else {
            bkt(k + 1);
        }
        

    }

//    for (v = 0; v <= 9; v++) {
//        s[k] = v;
//        if (solp(k) == 1)
//            if (k == n - 1) {
//                for (i = 1; i <= n; i++) {
//                    cout << s[i] << " ";
//                }
//                cout << endl;
//            } else {
//                bkt(k + 1);
//            }
//    }
}

int main() {
    cin >> n;
    s[1] = 0;
    s[2] = 1;
    s[n - 1] = 1;
    s[n] = 0;
    bkt(2);
    return 0;
}