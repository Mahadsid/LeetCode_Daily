#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// Approach 1-> using two nested for loops

  vector<int> twoSum(vector<int> & nums, int target){
          for(int i = 0; i < nums.size(); i++){
		         for(int j  = 0; j < nums.size(); j++){
				     if(nums[i] + nums[j] == target){
					        return {i, j};
					}
				}
			}
			return {-1, -1};
	 }
//Time Complexity = O(n^2)
//Space Complexity = O(1)
	 
     
//Approach-2>  using Hashmap   
vector<int> twoSum(vector<int> & nums, int target){
	    unordered_map<int, int> map;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int k = target - nums[i];        // a + b = target, then b = target - a;
            
            if(map.find(k) != map.end()){ // map.count(k) is same as map.find(k) != map.end();
                ans.push_back(map[k]);   // map[k] is giving index
                ans.push_back(i);
                
                return ans;
            }
            
            map[nums[i]] = i;
        }
            return ans;
}
  //Time Complexity = O(n)
  //Space Complexity = O(n)      // we have used hashmap


// Approach-3>
  vector<int> twoSum(vector<int> & nums, int target){
               vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++){
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        int start = 0, end = nums.size() - 1;
        
        while(start < end){
            int sum = v[start].first + v[end].first;
            if(sum == target){
                return {v[start].second, v[end].second};
            }else if(sum > target){
                end--;
            }else{
                start++;
            }
        }
        
        return {-1, -1};
  }
  //Time Complexity = O(nlogn) // due to sorting
  //Space Complexity = O(n)      // we have used pair