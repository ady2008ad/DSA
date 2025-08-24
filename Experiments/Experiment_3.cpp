//WAP to perform addition of Two 2-Variable Polynomials using Array Representation.
#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 3; // max powers of x and y
    int poly1[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} }; // example polynomial 1
    int poly2[3][3] = { {9,8,7}, {6,5,4}, {3,2,1} }; // example polynomial 2
    int sum[3][3];

    // Polynomial addition
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            sum[i][j] = poly1[i][j] + poly2[i][j];
        }
    }

    // Display result
    cout << "Sum of Polynomials:\n";
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(sum[i][j] != 0) {
                cout << sum[i][j] << "x^" << i << "y^" << j;
                if(j != n-1) cout << " + ";
            }
        }
        cout << endl;
    }

    return 0;
}