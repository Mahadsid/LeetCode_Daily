// You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. The score of the team is the sum of scores of all the players in the team.
// However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. A conflict does not occur between players of the same age.
// Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, return the highest overall score of all possible basketball teams.

// Example 1:
// Input: scores = [1,3,5,10,15], ages = [1,2,3,4,5]
// Output: 34
// Explanation: You can choose all the players.

// Intuition of this Problem:
// This problem is same as longest increasing subsequence and we can solve this problem using dynamic programming.

// NOTE - PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.

// Approach for this Problem:
// Create a pair array of size n where n is the size of scores and ages arrays.
// Store each player's score and age as a pair in the above array.
// Sort the pair array in increasing order of age.
// Initialize an array dp of size n and set dp[i] to be the score of player i for all 0 <= i < n.
// Initialize a variable ans to store the maximum overall score.
// Loop through the pair array from index i = 0 to i = n - 1.
// For each i, loop through j from 0 to i - 1.
// If the score of player j is less than or equal to the score of player i, update dp[i] to be the maximum of dp[i] and dp[j] + score[i].
// Set ans to be the maximum of ans and dp[i].
// Return ans as the result.
 
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int dp[n], ans = 0;
        vector<pair<int, int>> players;
        for(int i = 0; i < n; i++) 
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        for(int i = 0; i < n; i++) {
            dp[i] = players[i].second;
            for(int j = 0; j < i; j++) {
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
