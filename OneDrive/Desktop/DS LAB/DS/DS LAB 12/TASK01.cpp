#include <iostream>
#include <cstring>

using namespace std;

void searchPattern(const char* text, const char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (int i = 0; i <= textLength - patternLength; ++i) {
        int j = 0;
        while (j < patternLength && text[i + j] == pattern[j])
            ++j;

        if (j == patternLength)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    const char* text = "ABABABA";
    const char* pattern = "ABA";
    searchPattern(text, pattern);
    return 0;
}
