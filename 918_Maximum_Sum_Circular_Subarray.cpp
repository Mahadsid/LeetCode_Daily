// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
// Example 1:
// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.
// Example 2:
// Input: nums = [5,-3,5]
// Output: 10
// Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
// Example 3:
// Input: nums = [-3,-2,-3]
// Output: -2
// Explanation: Subarray [-2] has maximum sum -2.
 
// Constraints:
// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// Approach
// There are 2 possibility of The maximum subarray sum in circular array

// 1. Maximum subarray sum in non circular array
//      If max subarray sum in non circular array then we can simply apply Kadane's Algorithm and we will calculate the max_sum_subarray
//      Example A=[-3,-5,3,5,7,3,5,-9] ans= 23
// 2. Maximum subarray sum in circular array.
//      If max subarray sum in circular array then we will calculate the minimum sum of subarray and Subtract it from total_sum of array.
//      Example A=[11,1,-17,2,-15,9,13]
//      Here we will remove {17,2,-15} from our total sum that will give us max subarray sum because max sum include some prefix and suffix part:-
//      Ans= max(prefix+suffix)
//      Ans= max(total sum - subarray)
//      Ans=total sum + max(-subarray)
//      Ans= total sum - min(subarray)
// 3. Corner case -When all the element in the array are negative then our answer will be max_sum_subarray because if when all the element are negative at that time our total_sum - minsum_subary=0
//    and it will return 0 means empty subarray thats why we will return max sum of subarray
// 4. At last we will return
//      max(subarray sum in non circular array,Maximum subarray sum in circular array)

// Complexity
// Time complexity:O(N)
// Space complexity:O(1)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
        for(auto i:A)
        {
            total_sum+=i; curr_sum1+=i; curr_sum2+=i;
            mxsum_subary=max(mxsum_subary,curr_sum1);
            if(curr_sum1<0) curr_sum1=0;
           minsum_subary=min(curr_sum2,minsum_subary);
            if(curr_sum2>0) curr_sum2=0;
        }
        return (total_sum==minsum_subary)?mxsum_subary:max(mxsum_subary,total_sum-minsum_subary);  
    }
};
