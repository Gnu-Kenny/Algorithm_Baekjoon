#include <iostream>
#include <algorithm>
using namespace std;
int a[10];
int num[10];
bool check[10];
void go(int index, int n, int m) {
    if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << num[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = true;
        a[index] = i;
        go(index + 1, n, m);
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    go(0, n, m);
    return 0;
}