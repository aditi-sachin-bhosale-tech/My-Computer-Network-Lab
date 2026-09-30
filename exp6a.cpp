#include <iostream>
using namespace std;

int main() {
    int f[20], msg[40], d[10], temp[40], i, j, m, n;

    cout << "Enter size of frame: ";
    cin >> m;
    cout << "Enter size of divisor: ";
    cin >> n;

    cout << "Enter bits of frame: ";
    for (i = 0; i < m; i++) {
        cin >> f[i];
    }

    cout << "Enter bits of divisor: ";
    for (j = 0; j < n; j++) {
        cin >> d[j];
    }

    for (i = 0; i < m; i++) {
        msg[i] = f[i];
    }

    for (i = 0; i < n - 1; i++) {
        msg[m + i] = 0;
    }

    int total_bits = m + n - 1;

    for (i = 0; i < total_bits; i++) {
        temp[i] = msg[i];
    }

    cout << "\n--- Calculation Steps (XOR Division) ---\n";
    cout << "Initial Dividend: ";
    for (i = 0; i < total_bits; i++) cout << temp[i] << " ";
    cout << "\n\n";

    for (i = 0; i < m; i++) {
        if (temp[i] == 1) {
            cout << "Step " << i + 1 << ": Leading bit is 1. XORing with divisor...\n";
            
            for (int space = 0; space < i; space++) cout << "  ";
            for (j = 0; j < n; j++) cout << d[j] << " ";
            cout << " (Divisor)\n";
            
            for (j = 0; j < n; j++) {
                temp[i + j] = temp[i + j] ^ d[j];
            }

            for (int space = 0; space < i + 1; space++) cout << "  ";
            for (int k = i + 1; k < total_bits; k++) {
                cout << temp[k] << " ";
            }
            cout << " (Current Remainder)\n\n";
        } else {
            cout << "Step " << i + 1 << ": Leading bit is 0. Skipping XOR...\n\n";
        }
    }

    cout << "---------------------------------------\n";
    
    cout << "Message with zeros: ";
    for (i = 0; i < total_bits; i++) {
        cout << msg[i] << " ";
    }
    cout << endl;

    cout << "Remainder (CRC): ";
    for (i = m; i < total_bits; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;

    cout << "Final Transmitted Frame: ";
    for (i = 0; i < m; i++) {
        cout << msg[i] << " ";
    }
    for (i = m; i < total_bits; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;

    return 0;
}
