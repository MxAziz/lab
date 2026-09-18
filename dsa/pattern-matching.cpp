// 4. Find a given pattern from text using the Naive Pattern Matching algorithm
#include <iostream>
#include <string>
using namespace std;

void patternMatch(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    bool found = false;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            found = true;
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

    patternMatch(text, pattern);

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