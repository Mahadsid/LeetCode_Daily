// You are given an array of n strings strs, all of the same length.

// The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:
// abc
// bce
// cae
// You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

// Return the number of columns that you will delete.

// Example 1:
// Input: strs = ["cba","daf","ghi"]
// Output: 1
// Explanation: The grid looks as follows:
//   cba
//   daf
//   ghi
// Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

// Example 2:
// Input: strs = ["a","b"]
// Output: 0
// Explanation: The grid looks as follows:
//   a
//   b
// Column 0 is the only column and is sorted, so you will not delete any columns.

// Example 3:
// Input: strs = ["zyx","wvu","tsr"]
// Output: 3
// Explanation: The grid looks as follows:
//   zyx
//   wvu
//   tsr
// All 3 columns are not sorted, so you will delete all 3.
 
// Constraints:
// n == strs.length
// 1 <= n <= 100
// 1 <= strs[i].length <= 1000
// strs[i] consists of lowercase English letters.

//********SOLUTION***********
// Intuition: use a counter and if each char is lexicographically sorted column-wise.

// Approach:
// We can see that we are going through all the columns for comparision, so this is point 1.
// We need to compare the current char with the next char row-wise thus traversing will row-1, so this is point 2.
// If we find at any traversal that the order is not maintained, we need to delete the column according to the ques. So increment the counter and use break since the order is broken and we do not want to check that column any more, this is point 3.
// That's it, just return the counter value now.

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int delete_count=0;
        int row = strs.size();
        int col = strs[0].size();
        
        for(int j=0; j<col; j++)
        {
            for(int i=0; i<row-1; i++)
            {
                if(strs[i][j]>strs[i+1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};
