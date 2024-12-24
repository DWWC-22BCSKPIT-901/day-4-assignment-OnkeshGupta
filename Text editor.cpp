#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
    string S;
    stack<pair<int, string>> history;

public:
    void append(const string& W) {
        history.push({1, W});
        S += W;
    }

    void deleteChars(int k) {
        string deletedPart = S.substr(S.size() - k, k);
        history.push({2, deletedPart});
        S.erase(S.size() - k, k);
    }

    void print(int k) {
        if (k > 0 && k <= S.size()) {
            cout << S[k - 1] << endl;
        }
    }

    void undo() {
        if (history.empty()) return;

        auto lastOperation = history.top();
        history.pop();

        if (lastOperation.first == 1) {
            int len = lastOperation.second.size();
            S.erase(S.size() - len, len);
        } else if (lastOperation.first == 2) {
            S += lastOperation.second;
        }
    }
};

int main() {
    TextEditor editor;
    int Q;
    cin >> Q;

    while (Q--) {
        int operationType;
        cin >> operationType;

        if (operationType == 1) {
            string W;
            cin >> W;
            editor.append(W);
        } else if (operationType == 2) {
            int k;
            cin >> k;
            editor.deleteChars(k);
        } else if (operationType == 3) {
            int k;
            cin >> k;
            editor.print(k);
        } else if (operationType == 4) {
            editor.undo();
        }
    }

    return 0;
}