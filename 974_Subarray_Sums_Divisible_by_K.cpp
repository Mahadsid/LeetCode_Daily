// // Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
// // A subarray is a contiguous part of an array.

// // Example 1:
// // Input: nums = [4,5,0,-2,-3,1], k = 5
// // Output: 7
// // Explanation: There are 7 subarrays with a sum divisible by k = 5:
// // [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// Understanding the Question
// Subarray Sums divisible by k. Let's break the question down in small steps.

// Firstly, we need subarray sums. There are n*(n-1)/2 of these for an n-length array.
// Secondly, we need to count the number of subarray sums divisible by k (given).
// So the first approach that inevitably comes to mind is to loop over all the possible subarrays, taking their sums and checking if they are divisible by k. But as soon as this comes to one's mind, one must also realize that this is an extremely naive solution as it is.
// We would need to choose the starting and ending points (O(n) each) and then loop over the subarray to calculate its sum (again O(n)), giving a total of O(n3)O(n^3)O(n 
// 3
//  ) time complexity, which is not permitted by the constraints given.

// The next thing one may think is of using prefix sum array, to reduce the calculation of the sum to O(n2)O(n^2)O(n 
// 2
//  ), but this will still not make the cut.

// Look for Hints in the Constraints
// The constraints are as follows:
// 1<=n<=3∗1041 <= n <= 3*10^41<=n<=3∗10 
// 4
 
// −104<=nums[i]<=104-10^4 <= nums[i] <= 10^4−10 
// 4
//  <=nums[i]<=10 
// 4
 
// 2<=k<=1042 <= k <= 10^42<=k<=10 
// 4
 

// As we can see, the constraints won't permit an O(n2)O(n^2)O(n 
// 2
//  ), and hence we need to make use of all the information in the question in such a way that we can do this in O(nlogn)O(nlogn)O(nlogn) or less.

// A Curious Observation
// Let us consider the following example:
// nums = [4,5,0,-2,-3,1], k = 5
// If we consider the prefix sum of the above array and the remainders when they are divided by k (i.e prefixSum[i]%k), we get the following:

// prefixSum = [4, 9, 9, 7, 4, 5]
//    ..%k   = [4, 4, 4, 2, 4, 0]
// For any subarray [i..j] whose sum is divisible by k, we can easily see that prefixSum[j] - prefixSum[i-1] = 0.
// Thus if there are any repetitions in our prefixSum%k array, that represents a required subarray.

// So if we have the count of every possible value of prefixSum%k, we can determine if there are any subarray that end at the current index and the sum is divisible by k.

// Approach
// We loop over the array, calculating the prefixSum on the way. We don't need to store this as they are never reused. We maintain the count of every sum%k we can get.
// If we get a repitition, this index can be paired by any of the other indices that have the same sum%k, and hence contributes count[sum%k] to the total.

// For considering the case of the prefixSums being themselves divisible by k and the case of the whole array being a subarray whose sum is divisible by k, we need to initialize count[0] = 1.

// Complexity
// Time complexity: O(n+k)O(n + k)O(n+k)

// Space complexity: O(k)O(k)O(k)

// Code
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        for(int i = 0; i<n; i++) {
            currSum = (currSum + nums[i]%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;
    }
};
