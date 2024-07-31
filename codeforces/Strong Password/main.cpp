#include <bits/stdc++.h>
using namespace std;

char gen(char a, char b) {
    for (int i = 'a'; i <= 'z'; i++) {
        bool found = false;
        char c = (char) i;
        if (c != a && c != b) {
            return c;
        }
    }
    return ' ';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string password;
        cin >> password;
        bool inserted = false;
        for (int i = 1; i < password.length(); i++) {
            if (password[i] == password[i - 1]) {
                password.insert(i, 1, gen(password[i], password[i - 1]));
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            password += gen(password[password.length() - 1], ' ');
        }
        cout << password << endl;
    }
    return 0;
}