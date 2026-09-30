#include<iostream>
using namespace std;

int main() {
    int C[11], D[7], i;
    int P1, P2, P4, P8, error_pos;

    cout << "Enter 11-bit received codeword: ";
    for (i = 0; i < 11; i++) {
        cin >> C[i];
    }

    P1 = C[10] ^ C[8] ^ C[6] ^ C[4] ^ C[2] ^ C[0];
    P2 = C[9] ^ C[8] ^ C[6] ^ C[5] ^ C[1] ^ C[0];
    P4 = C[7] ^ C[6] ^ C[5] ^ C[4];
    P8 = C[3] ^ C[2] ^ C[1] ^ C[0];

    error_pos = (P8 * 8) + (P4 * 4) + (P2 * 2) + P1;

    if (error_pos != 0) {
        cout << "\nError detected at position: " << error_pos;
        if (error_pos <= 11) {
            C[11 - error_pos] = !C[11 - error_pos];
            cout << "\nError corrected.";
        }
    } else {
        cout << "\nNo error detected.";
    }

    D[0] = C[0];
    D[1] = C[1];
    D[2] = C[2];
    D[3] = C[4];
    D[4] = C[5];
    D[5] = C[6];
    D[6] = C[8];

    cout << "\nDecoded message: ";
    for (i = 0; i < 7; i++) {
        cout << D[i];
    }

    return 0;
}
