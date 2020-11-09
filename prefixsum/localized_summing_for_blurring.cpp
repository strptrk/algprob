#include <bits/stdc++.h>

#define N 1001

using namespace std;

int a[N][N];

// két megadott cella közötti összeget kiszámító fv.
inline int area(int arr[][N], int x1, int y1, int x2, int y2) {
    int ret = arr[x2][y2];
    if (y1 > 0) {
        ret -= arr[x2][y1 - 1];  // bal oldali teglalap
    }
    if (x1 > 0) {
        ret -= arr[x1 - 1][y2];  // felso teglalap
    }
    if ((x1 > 0) && (y1 > 0)) {
        ret += arr[x1 - 1][y1 - 1];  // metszet
    }
    return ret;
}

int i, j;
int n, m;
long result, tmp;

bool fst = true;

int main() {
    while (cin >> n >> m) {
        // az online judge sajátos formázási követelményei miatt szükséges
        if (!fst) {
            cout << endl;

        } else {
            fst = false;
        }
        // inicializálja a tömböt és beolvassa az adatokat a standard inputról
        memset(a, 0, sizeof(a));
        result = 0;
        for (i = n - 1; i >= 0; i--) {
            for (j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        // prefix összegzés
        for (j = 1; j < n; j++) {
            a[0][j] += a[0][j - 1];
        }
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                a[i][j] += a[i][j - 1];
            }
            for (j = 0; j < n; j++) {
                a[i][j] += a[i - 1][j];
            }
        }
        // a feladat válaszát megadó blokk
	// a feladat szerint a bal alsó sarokból kell kezdeni a kiírást
        for (i = n - m; i >= 0; i--) {
            for (j = 0; j <= n - m; j++) {
                tmp = area(a, i, j, i + m - 1, j + m - 1);
                result += tmp;
                cout << tmp << '\n';
            }
        }
        cout << result << '\n';
    }
}
