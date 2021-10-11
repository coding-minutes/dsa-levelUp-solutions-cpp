#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(const string &str){   
    int n = str.length();
    string output;
    for (int i = 0; i < n; i++) {
 
        // Count occurrences of current character
        int count = 1;
 
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
 
        // Store the Character and its count
        output += str[i];
        output += to_string(count);
    }
    if(output.length()>str.length()){
        return str;
    }
    return output;
}