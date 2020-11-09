#include <bits/stdc++.h>

#define MAX 1001

using namespace std;

int n, m, q;
int i, j, k;
int x, x2, y, y2;
int a[MAX][MAX];
int c[MAX][MAX];
string s[MAX];

int main() {
    // kezdeti adatok beolvasása (string formátumban a feladat szerint)
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> s[i];
    }
    // a stringből egész számokat tartalmazó tömböt készítünk,
    // a prefix összegzést végző tömböt nullázzuk
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = s[i][j] - '0';
            c[i][j] = 0;
        }
    }

    cin >> q;
    for (k = 0; k < q; k++) {
        // beolvasás, illetve az 1-től indexelés miatt az értékek csökkentése
        cin >> x >> y >> x2 >> y2;
        x--;
        y--;
        y2--;
        x2--;
        // a prefix összegzést megelőzően a megfelelő
        // helyekre 1 illetve -1 kerül
        c[x][y]++;
        if (x2 + 1 < n && y2 + 1 < m) {
            c[x2 + 1][y2 + 1]++;
        }
        if (x2 + 1 < n) {
            c[x2 + 1][y]--;
        }
        if (y2 + 1 < m) {
            c[x][y2 + 1]--;
        }
    }
    // prefix összegzés
    for (j = 1; j < m; j++) {
        c[0][j] += c[0][j - 1];
    }
    for (i = 1; i < n; i++) {
        for (j = 1; j < m; j++) {
            c[i][j] += c[i][j - 1];
        }
        for (j = 0; j < m; j++) {
            c[i][j] += c[i - 1][j];
        }
    }
    // aszerint, hogy páros vagy páratlan alkalommal
    // fordult a bit, vagy az eredeti tömb elemét írjuk ki,
    // vagy az ellentétét
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (c[i][j] % 2) {
                if (a[i][j] == 1) {
                    cout << 0;
                } else {
                    cout << 1;
                }
            } else {
                cout << a[i][j];
            }
        }
        cout << "\n";
    }
}
