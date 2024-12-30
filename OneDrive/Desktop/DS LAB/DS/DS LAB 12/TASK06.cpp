#include <iostream>
#include <cstring>

using namespace std;

bool isPalindrome(const char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        ++start;
        --end;
    }
    return true;
}

void findPalindromes(const char* text) {
    int n = strlen(text);
    int base = 31, mod = 1000000007;
    int* hashPrefix = new int[n + 1];
    int* hashSuffix = new int[n + 1];
    int* power = new int[n + 1];

    hashPrefix[0] = 0;
    hashSuffix[n] = 0;
    power[0] = 1;

    for (int i = 1; i <= n; ++i) {
        hashPrefix[i] = (1LL * hashPrefix[i - 1] * base + (text[i - 1] - 'A' + 1)) % mod;
        power[i] = (1LL * power[i - 1] * base) % mod;
    }

    for (int i = n - 1; i >= 0; --i) {
        hashSuffix[i] = (1LL * hashSuffix[i + 1] * base + (text[i] - 'A' + 1)) % mod;
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            int prefixHash = (hashPrefix[j + 1] - 1LL * hashPrefix[i] * power[len] % mod + mod) % mod;
            int suffixHash = (hashSuffix[i] - 1LL * hashSuffix[j + 1] * power[len] % mod + mod) % mod;

            if (prefixHash == suffixHash && isPalindrome(text, i, j)) {
                for (int k = i; k <= j; ++k)
                    cout << text[k];
                cout << endl;
            }
        }
    }

    delete[] hashPrefix;
    delete[] hashSuffix;
    delete[] power;
}

int main() {
    const char* text = "ABCBAB";
    findPalindromes(text);
    return 0;
}
