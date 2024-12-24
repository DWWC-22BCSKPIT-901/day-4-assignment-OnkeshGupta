#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string s = "loveleetcode";
    cout << "The index of the first non-repeating character is: " << firstUniqChar(s) << endl;
    return 0;
}
