// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
// If the town judge exists, then:
// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

// Example 1:
// Input: n = 2, trust = [[1,2]]
// Output: 2
// Example 2:
// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3
// Example 3:
// Input: n = 3, trust = [[1,3],[2,3],[3,1]]
// Output: -1

// Constraints:
// 1 <= n <= 1000
// 0 <= trust.length <= 104
// trust[i].length == 2
// All the pairs of trust are unique.
// ai != bi
// 1 <= ai, bi <= n
// Approach
// I have created two vectors trusting which represents ith element trusts how many people and trusted whose ith element represents it is trusted by how many people.
// I have incremented respective indexes in each iteration.
// Finally I have initialized ans = -1, if there exist any i which trusts nobody i.e. trusting[i] = 0 && it is trusted by all accept him i.e. trusted[i] = n-1 then update ans.
// return ans
// Complexity
// Time complexity: O(n)
// Space complexity: O(n)
// Code
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //Initialized vectors of size n+1 with 0 to be able to store values for index 1 to n
        vector<int> trusting(n+1,0); 
        vector<int> trusted(n+1,0);

        for(int i=0;i<trust.size();i++){
            trusting[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }

        int ans = -1;

        for(int i=1;i<=n;i++){
            if(trusting[i] == 0 && trusted[i] == n-1)
                ans = i;
        }

        return ans;

    }
};
