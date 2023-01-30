// The Tribonacci sequence Tn is defined as follows: 
// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
// Given n, return the value of Tn.

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Tribonacci Series
// The tribonacci series is a generalization of the Fibonacci sequence where each term is the sum of the three preceding terms.
// The Tribonacci Sequence:
// 0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, 121415, 223317, 410744, 755476, 1389537, 2555757, 4700770, 8646064, 15902591, 29249425, 53798080, 98950096, 181997601, 334745777, 615693474, 1132436852… so on
// General Form of Tribonacci number:

//     a(n) = a(n-1) + a(n-2) + a(n-3) 
//     with 
//     a(0) = a(1) = 0, a(2) = 1. 
// Intuition
// First we initialise the starting 3 numbers of the series and then check:

// If n==0 then return 0.
// If n==1 or n==2 then return 1;
// After that we run a loop from i=3 to n and find the series as
// d = a + b + c
// a = b
// b = c
// c = d
// Complexity
// Time complexity: O(n)
// Space complexity: O(1)
// Code
class Solution {
public:
    int tribonacci(int n) {
        int a=0, b=1, c=1,d;  // Initialize the first three terms of the sequence
        if(n==0)
            return a;  // If n is 0, return the first term
        if(n==1 || n==2)
            return 1;  // If n is 1 or 2, return the second or third term respectively
        for(int i=3;i<=n;i++){  // Start the loop from the third term
            d = a + b + c;  // Calculate the next term in the sequence
            a = b;  // Update the value of a
            b = c;  // Update the value of b
            c = d;  // Update the value of c
        }
        return d;  // Return the nth term
    }
};
