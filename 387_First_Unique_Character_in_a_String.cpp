class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            int c=s[i]-'a';
            arr[c]++;
        }
        for(int i=0;i<s.length();i++){
            int c=s[i]-'a';
            if(arr[c]==1){
                return i;
            }
        }
        return -1;
    }
};

//map solution
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    for(int i=0;i<s.length();i++){
        if(mp[s[i]]==1) return i;
    }
    
    return -1;
    }
};
