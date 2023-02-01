// For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
// Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

// Example 1:
// Input: str1 = "ABCABC", str2 = "ABC"
// Output: "ABC"

// Approach
// str1+str2 == str2+str1 if and only if str1 and str2 have a gcd .
// E.g. str1=abcabc, str2=abc, then str1+str2 = abcabcabc = str2+str1
// This(str1+str2==str2+str1) is a requirement for the strings to have a gcd. If one of them is NOT a common part then gcd is "".It means we will return empty string
// Proof:-str1 = mGCD, str2 = nGCD, str1 + str2 = (m + n)GCD = str2 + str1
// Both the strings are made of same substring added multiple times.
// Since they are multiples, next step is simply to find the gcd of the lengths of 2 strings e.g. gcd(6,3) = 3, (we can use gcd function to find that)and get the substring of length 3 from either str1 or str2.
// In c++ it will be str1.substr(0, gcd)
  
// Intuition
// If the two strings have a common prefix, then concatenating them in either order should result in the same string.
// The length of the common prefix is equal to the greatest common divisor of the lengths of the two strings.strings.
// Approach
// Concatenate the two strings in two different orders: str1+str2 and str2+str1.
// Compare the two concatenated strings.
// If the two concatenated strings are equal, then the two original strings share a common prefix.
// Find the greatest common divisor of the lengths of the two strings.
// Use the GCD as the length of the common prefix and return it using str1.substr(0, gcd(str1.length(), str2.length())).
// If the two concatenated strings are not equal, then there is no common prefix, so return an empty string.

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 == str2 + str1){
            return str1.substr(0, gcd(str1.length(), str2.length()));
        }
        return "";
    }
};
