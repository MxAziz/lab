// 4. Find a given pattern from text using the Naive Pattern Matching algorithm
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    int n = text.length(), m = pattern.length();
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
        cout << "Pattern not found" << endl;

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