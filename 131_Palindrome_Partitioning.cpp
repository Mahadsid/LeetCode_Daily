// // Given a string s, partition s such that every 
// // substring
// //  of the partition is a 
// // palindrome
// // . Return all possible palindrome partitioning of s.

// // Example 1:
// // Input: s = "aab"
// // Output: [["a","a","b"],["aa","b"]]

// // Example 2:
// // Input: s = "a"
// // Output: [["a"]]

// // Constraints:
// // 1 <= s.length <= 16
// // s contains only lowercase English letters.


// 1. lets us consider string aab here we take first string that is a and check whether it is palindrome or not ;
// 2. if it is palindrome then we add it to temp vector and recursively call dfs function for substring(i+1) i.e ab
// 3. now here also we check first substring i.e a is palindrome or not as we did earlier and add it to temp if it is palindrome, recursively call function for b alone by now our temp contains ["a","a"];
// 4. now when we are left with b only then on recursive call fun, our temp becomes ["a","a","b"]. we call fn after b then there is empty string and we consider it base condition. storing temp in ans vector.
// 5. whatever changes we made need to backtrack for next possible solution so we backtrack by poping out from temp . after one pop up we get temp as ["a","a"]. we backtrack and check for ab only as ab is not palindrome so we increase i and check for next. repeat the same ..

class Solution {

    bool ispalindrome(string s){
        for(int i=0;i<s.size()/2;++i){
            if(s[i]==s[s.size()-1-i]){
                continue;
            }
            return false;
        }
        return true;
    }
public: void dfs(vector<vector<string>>&ans,vector<string>&temp,string s){
   if(s.size()==0){  //base condistion when there is no string left
       ans.push_back(temp);
       return;
   }
    for(int i=0;i<s.size();++i){
        string check=s.substr(0,i+1);
        if(ispalindrome(check)){
            temp.push_back(check);
            dfs(ans,temp,s.substr(i+1));
            temp.pop_back();

        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        dfs(ans,temp,s);
        return ans;
    }
};
