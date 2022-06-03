#include <bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum = sum + nums[i];
            nums[i] = sum;
            
        }
        return nums;
    }
};