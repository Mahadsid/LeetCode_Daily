class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

double ans = 0;

for ( int i = 0; i < nums2.size(); i++)
    nums1.push_back(nums2[i]);

sort(nums1.begin(),nums1.end());

int start = 0 , end = nums1.size()-1;

int mid = start + (end + start)/2;

if( end % 2 == 0){
    ans = nums1[mid];
}
else{
    ans = nums1[mid] + nums1[++mid];
    ans = ans/2;
    
}
return ans;
    }
};
