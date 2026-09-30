#include <iostream>
using namespace std;

int main() {
    int tf[40], d[10], temp[40], i, j, m, n;

    cout << "Enter size of transmitted frame: ";
    cin >> m;

    cout << "Enter size of divisor: ";
    cin >> n;

    cout << "Enter bits of transmitted frame: ";
    for (i = 0; i < m; i++) {
        cin >> tf[i];
        temp[i] = tf[i];
    }

    cout << "Enter bits of divisor: ";
    for (j = 0; j < n; j++) {
        cin >> d[j];
    }

    int original_msg_size = m - n + 1;

    cout << "\n--- Calculation Steps (XOR Division at Receiver) ---\n";
    cout << "Received Frame: ";
    for (i = 0; i < m; i++) cout << temp[i] << " ";
    cout << "\n\n";

    for (i = 0; i < original_msg_size; i++) {
        if (temp[i] == 1) {
            cout << "Step " << i + 1 << ": Leading bit is 1. XORing with divisor...\n";
            for (int space = 0; space < i; space++) cout << "  ";
            for (j = 0; j < n; j++) cout << d[j] << " ";
            cout << " (Divisor)\n";

            for (j = 0; j < n; j++) {
                temp[i + j] = temp[i + j] ^ d[j];
            }

            for (int space = 0; space < i + 1; space++) cout << "  ";
            for (int k = i + 1; k < m; k++) {
                cout << temp[k] << " ";
            }
            cout << " (Current Remainder)\n\n";
        } else {
            cout << "Step " << i + 1 << ": Leading bit is 0. Skipping XOR...\n\n";
        }
    }

    cout << "---------------------------------------\n";
    
    bool error = false;
    cout << "Final Remainder: ";
    for (i = original_msg_size; i < m; i++) {
        cout << temp[i] << " ";
        if (temp[i] != 0) {
            error = true;
        }
    }
    cout << endl;

    if (error) {
        cout << "Result: Error detected in transmission. Frame rejected." << endl;
    } else {
        cout << "Result: No error detected. Frame accepted successfully." << endl;
        cout << "Original Message: ";
        for (i = 0; i < original_msg_size; i++) {
            cout << tf[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
