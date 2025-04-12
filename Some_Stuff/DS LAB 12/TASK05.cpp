#include <iostream>
#include <cstring>

using namespace std;

struct Pattern {
    char* pattern;
    int length;
    int badCharTable[256];
};

void preprocessBadChar(Pattern& pat) {
    for (int i = 0; i < 256; ++i)
        pat.badCharTable[i] = pat.length;

    for (int i = 0; i < pat.length - 1; ++i)
        pat.badCharTable[(unsigned char)pat.pattern[i]] = pat.length - i - 1;
}

int searchPattern(const char* text, int textLength, const Pattern& pat) {
    int shift = 0;
    while (shift <= textLength - pat.length) {
        int j = pat.length - 1;
        while (j >= 0 && pat.pattern[j] == text[shift + j])
            --j;

        if (j < 0)
            return shift;
        
        shift += pat.badCharTable[(unsigned char)text[shift + pat.length - 1]];
    }
    return -1;
}

void searchMultiplePatterns(const char* text, int textLength, char** patterns, int* patternLengths, int numPatterns) {
    Pattern* pats = new Pattern[numPatterns];
    for (int i = 0; i < numPatterns; ++i) {
        pats[i].pattern = patterns[i];
        pats[i].length = patternLengths[i];
        preprocessBadChar(pats[i]);
    }

    for (int i = 0; i < textLength; ++i) {
        for (int j = 0; j < numPatterns; ++j) {
            int foundIndex = searchPattern(text + i, textLength - i, pats[j]);
            if (foundIndex == 0) {
                cout << "Pattern found: " << pats[j].pattern << " at index " << i << endl;
            }
        }
    }

    delete[] pats;
}

int main() {
    const char* text = "ABCDEFG";
    int textLength = strlen(text);

    char* patterns[] = { "ABC", "EFG" };
    int patternLengths[] = { 3, 3 };
    int numPatterns = 2;

    searchMultiplePatterns(text, textLength, patterns, patternLengths, numPatterns);

    return 0;
}
