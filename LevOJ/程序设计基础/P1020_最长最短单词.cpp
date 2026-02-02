/*
给定由若干个单词组成的字符串，字符串的长度小于500，
单词和单词之间由空格分开，求出其中的最长最短单词
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);

    // 这题用sstream流切割字符串最方便~
    istringstream iss(str);
    string word, min_word, max_word;
    int min_len = 500;

    while (iss >> word) {
        if (word.length() > max_word.length())
            max_word = word;
        if (word.length() < min_len) {
            min_word = word;
            min_len = word.length();
        }
    }

    cout << max_word << "\n" << min_word;
}
