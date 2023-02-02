// // In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
// // Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

// // Example 1:
// // Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// // Output: true
// // Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
// Intuition
// The idea behind this code is to verify if the words in the words vector are sorted according to the given alien dictionary. To achieve this, the code first creates a mapping of each character in order to its index. Then, it sorts the words in the words vector according to the mapping and compares the sorted vector with the original vector. If the two vectors are equal, it means that the words in words are sorted according to the alien dictionary.

// Approach
// Create an unordered map m to store the mapping of each character in order to its index.
// Define a custom comparison function cmp that takes two strings as input and returns a boolean indicating if the first string is smaller than the second string according to the alien dictionary.
// In the cmp function, compare the characters in the two strings by looking up their indices in m. If a character in the first string has a smaller index than the character in the second string, return true to indicate that the first string is smaller. If a character in the first string has a larger index than the character in the second string, return false to indicate that the first string is larger. If the characters are the same, continue to compare the next characters.
// If all the characters in the two strings are the same and the first string is shorter than or equal to the second string, return true. Otherwise, return false.
// In the isAlienSorted function, use the sort function to sort the words in the words vector using the custom comparison function cmp.
// Finally, return the result of comparing the sorted vector with the original vector. If the two vectors are equal, it means that the words in words are sorted according to the alien dictionary, so return true. Otherwise, return false.


unordered_map<char, int> m;

bool cmp(string a, string b){
    int n = min(a.length(), b.length());
    for(int i = 0; i < n; i++){
        if(m[a[i]] < m[b[i]]){
            return true;
        }
        else if(m[a[i]] > m[b[i]]){
            return false;
        }
    }
    if(a.length() <= b.length()){
        return true;
    }
    return false;
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.length(); i++){
            m[order[i]] = i;
        }
        vector<string> temp = words;
        sort(temp.begin(), temp.end(), cmp);
        return temp == words;
    }
};
