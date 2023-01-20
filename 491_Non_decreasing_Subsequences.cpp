// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// Example 1:
// Input: nums = [4,6,7,7]
// Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// Example 2:
// Input: nums = [4,4,3,2,1]
// Output: [[4,4]]
// Constraints:
// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100
// We iterate through each element of array and perform following opration:
// 1. We pick the element at that index.
// 2. Or we do not pick that element and increase the index.
// 3. when we iterate all elements i.e index==n, we check if size of the answer is greater than one (>1). If true then we add it otherwise ignore it.

//                     {index, {output}}
//                     {initial, {}}
//                         /    \
//                        /      \
//                    {0, {}}  {0, {4}}
//                     /  \        /   \
//                    /    \      /     \
//             {1, {}}  {1,{6}} {1,{4}} {1,{4,6}}
//                 |       |       |        |
//                 |       |       |        |
                
// Approach : Backtracking
// Time Complexity : O(N.2^N)
// Space Complexity : O(N*N)
class Solution {
public:
    // Recursive function to find all increasing subsequences
    void solve(vector<int> nums, int index, vector<int> output, set<vector<int>>& ans){
        // Base case: if we have reached the end of the input array
        if(index>=nums.size()){
            // Only insert into ans if output has more than one element
            if(output.size()>1)
                ans.insert(output);
            return ;
        }
        // If output is empty or current element is greater than or equal to the last element in output
        if(output.size()==0 || nums[index] >= output.back()){
            output.push_back(nums[index]);
            solve(nums, index+1, output, ans);
            output.pop_back();
        }
        solve(nums, index+1, output, ans);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // Initialize output and set to store all increasing subsequences
        vector<int> output;
        set<vector<int>> ans;
        // Call recursive function to find all increasing subsequences
        solve(nums, 0, output, ans);
        // Return ans as a vector
        return vector(ans.begin(), ans.end());
    }
};
