#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace StringUtil {
    bool isPalindrome(const string& str, int start, int end) {
        if (start >= end)
            return true;
        if (str[start] != str[end])
            return false;
        return isPalindrome(str, start + 1, end - 1);
    }

    void reverseString(string& str, int start, int end) {
        if (start >= end)
            return;
        swap(str[start], str[end]);
        reverseString(str, start + 1, end - 1);
    }
}

int main() {
    string str;
    cout << "Enter a word: ";
    getline(cin, str);

    // Check if the entered string is a palindrome
    if (StringUtil::isPalindrome(str, 0, str.length() - 1))
        cout << "Word is a palindrome.\n";
    else
        cout << "word is not a palindrome.\n";

    // Reverse the entered string
    StringUtil::reverseString(str, 0, str.length() - 1);
    cout << "Word in reverse: " << str << endl;

    return 0;
}
