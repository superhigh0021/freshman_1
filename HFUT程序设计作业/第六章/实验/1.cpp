#include<iostream>
using namespace std;
int main()
{
    int n, i, j, k, m;
    cout << "ÇëÊäÈën£º";
    cin >> n;
    for (i = 1; i < n; i++) {
        for (j = i; j < n; j++)
            cout << j << " ";
        for (k = 0; k < i; k++)
            cout << k << " ";
        cout << endl;
    }
    for (m = 0; m < n; m++)
        cout << m << " ";
    cout << endl;
    return 0;
}