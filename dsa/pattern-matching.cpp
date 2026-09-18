// Find a given pattern from text using the Knuth-Morris-Pratt (KMP) algorithm
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Build the LPS (Longest Proper Prefix which is also Suffix) array
void computeLPSArray(string pattern, int m, vector<int> &lps) {
    int len = 0; // length of the previous longest prefix suffix
    lps[0] = 0;  // lps[0] is always 0
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
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

void KMPSearch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0) {
        cout << "Pattern is empty." << endl;
        return;
    }

    vector<int> lps(m);
    computeLPSArray(pattern, m, lps);

    bool found = false;
    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        cout << "Pattern not found in the text." << endl;
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    KMPSearch(text, pattern);

    return 0;
}

/*
Sample Input:
Enter the text: AABAACAADAABAABA
Enter the pattern: AABA

Sample Output:
Pattern found at index 0
Pattern found at index 9
Pattern found at index 12
*/