// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.
// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

// Example 1:
// Input: tasks = [2,2,3,3,2,4,4,4,4,4]
// Output: 4
// Explanation: To complete all the tasks, a possible plan is:
// - In the first round, you complete 3 tasks of difficulty level 2. 
// - In the second round, you complete 2 tasks of difficulty level 3. 
// - In the third round, you complete 3 tasks of difficulty level 4. 
// - In the fourth round, you complete 2 tasks of difficulty level 4.  
// It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

// Example 2:
// Input: tasks = [2,3,3]
// Output: -1
// Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
 
// Constraints:
// 1 <= tasks.length <= 105
// 1 <= tasks[i] <= 109

// Intuition: question revolves around frequency so we will use map

// Approach:
// From observation, we can see that there's only 3 possible outcomes.

// 1. If the frequency is 1, the task cannot be performed so we return -1.
// 2. If the frequency is 3, the task can be performed and we return frequency/3.
// 3. Now if the frequency is not completely divisible by 3, then the possible remainders are 1 and 2. Lets check them out:
// If remainder is 1, i.e, lets take 7 frequency, then 🔮🔮🔮🔮🔮🔮🔮 the groups are something like this "🔮🔮🔮" "🔮🔮🔮" "🔮", i.e, one 🔮 is left alone so the solution is to break the second last group into two parts of 2 and 1 so that it becomes like: "🔮🔮🔮" "🔮🔮" "🔮🔮", i.e, one is added to the division by 3.
// If remainder is 2, i.e, lets take 8 frequency, then 🔮🔮🔮🔮🔮🔮🔮🔮 the groups are something like this "🔮🔮🔮" "🔮🔮🔮" "🔮🔮", i.e, two 🔮 are left so the solution is to just add 1,i.e, one group of two to the solution.

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        
        int output=0;
        
        for (auto freq : mp){
            if(freq.second==1)
                return -1;
            if(freq.second%3==0){
                output += freq.second/3;
            }
            else{
                output += freq.second/3 + 1;
            }
        }
        return output;
    }
};
