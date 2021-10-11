#include<bits/stdc++.h>
using namespace std;

int skip_whitespace(const string &sentence, int idx) {
    while (idx < sentence.length() && sentence[idx] == ' ') {
        idx += 1;
    }

    return idx;
}

int normalize_word(string &sentence, int idx) {
    if (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = toupper(sentence[idx]);
        idx += 1;
    }

    while (idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = tolower(sentence[idx]);
        idx += 1;
    }

    return idx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    int idx = 0;

    while (idx < copy.length()) {
        idx = skip_whitespace(copy, idx);
        idx = normalize_word(copy, idx);
    }

    return copy;
}