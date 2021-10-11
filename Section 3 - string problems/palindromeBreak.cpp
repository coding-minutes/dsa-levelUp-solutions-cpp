#include<bits/stdc++.h>
using namespace std;

    string breakPalindrome(string palindrome) {
	//If we have string size == 1, return "". Since any replacement cannot break the palindrome.
        if(palindrome.size() == 1)
            return "";
        
        vector<vector<int>> count(26);
        int firstNonA = -1;
        
        for(int i = 0; i < palindrome.size(); i++)
        {
            count[palindrome[i] - 'a'].push_back(i);
            
            //Update firstNonA index if its not yet found.
            if(firstNonA == -1 && palindrome[i] != 'a')
                firstNonA = i;
        }
        
        //If we have N-1 a's, we need to replace last a with b
        if(count[0].size() >= palindrome.size() - 1)
            palindrome[count[0].back()] = 'b';
        //Else replace first non-'a' character with 'a'
        else
            palindrome[firstNonA] = 'a';
        
        return palindrome;
    }