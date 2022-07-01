#include <bits/stdc++.h>
#include<iostream>
using namespace std;

bool comp(vector<int>& a, vector<int>& b){
    return a[1]>b[1];
}
 
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int ans = 0;
    sort(boxTypes.begin(), boxTypes.end(), comp);
        
    for(int i=0; i<boxTypes.size(); i++){
        if(boxTypes[i][0]>truckSize){
            ans+=truckSize*boxTypes[i][1];
            truckSize=0;
        }
        else{
            ans+=boxTypes[i][0]*boxTypes[i][1];
            truckSize-=boxTypes[i][0];
            }
        }
        return ans;
    }
