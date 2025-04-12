#include <iostream>
#include <cstring>

using namespace std;

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

void computeLPSArray(const char* pattern, int patternLength, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < patternLength) {
        if (toLowerCase(pattern[i]) == toLowerCase(pattern[len])) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const char* text, const char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int* lps = new int[patternLength];

    computeLPSArray(pattern, patternLength, lps);

    int i = 0, j = 0;

    while (i < textLength) {
        if (toLowerCase(pattern[j]) == toLowerCase(text[i])) {
            i++;
            j++;
        }

        if (j == patternLength) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < textLength && toLowerCase(pattern[j]) != toLowerCase(text[i])) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    delete[] lps;
}

int main() {
    const char* text = "Data Structures";
    const char* pattern = "data";
    KMPSearch(text, pattern);
    return 0;
}
