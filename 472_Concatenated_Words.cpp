// Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
// Example 1:
// Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
// "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
//solution https://leetcode.com/problems/concatenated-words/solutions/3104096/c-image-detailed-explanation-recursion/
class Solution {
public: bool concat_possible(string &word,vector<string>& words, unordered_map<string,int>&mp){
          int size=word.size();
          for(int i=1;i<size;++i){ 
              string prefix=word.substr(0,i);// left subpart
              string suffix=word.substr(i);  // right subpart
              if(mp[prefix] && (mp[suffix] || concat_possible(suffix,words,mp))){   /*checking if left and right subpart is present in map or not .
if one subpart is present(lets say prefix) and other is not(lets say suffix) then recursively check the suffix subpart .if both subparts is present then return true*/
                  return true;
              }
          }
          return false;
}
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;
        unordered_map<string,int>mp; 
        for(auto string:words){   //storing each words into unordered_map
            mp[string]++;
        }


        for(auto &word:words){  //check for each word .if its return true then add it into our solution
            if(concat_possible(word,words,mp)){
                ans.push_back(word);
            }
        }
        return ans;
    }
};
