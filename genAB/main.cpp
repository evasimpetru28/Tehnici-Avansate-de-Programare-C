#include <iostream>

using namespace std;

int A, B;
int s[101];

int checkCondition(int k) {
    while (k > 9) {
        int lastDigit = k%10;
        int nextToLastDigit = k/10%10;
        if (lastDigit - nextToLastDigit != 1 && lastDigit - nextToLastDigit != -1) {
            return 0;
        }
        k = k/10;
    }
    return 1;
}

void bkt(int k) {
    int i, v;
    for (v = A; v <= B; v++) {
//        s[k] = v;
        if (checkCondition(k) == 1)
            if (s[k] >= A && s[k] <= B) {
                for (i = 1; i <= k; i++)
                    printf("%d ", s[i]);
                printf("\n");
            } else
                bkt(k + 1);
    }
}

int main() {


    printf("A (limita inf) = ");
    cin >> A;
    printf("B (limita sup) = ");
    cin >> B;

    bkt(1);

    return 0;
}
