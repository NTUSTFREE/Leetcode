class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minLen = INT_MAX;
        for(auto &str: strs)
            if(str.length() < minLen)
                minLen = str.length();
        
        int L=1;
        int R=minLen;
        
        while(L<=R)
        {
            int mid = (L+R)/2;
            if(isCommonPrefix(strs, mid))
                L=mid+1;
            else{
                R=mid-1;
            }
            
        }
        
        return strs[0].substr(0,(L+R)/2);
    }
    
    static bool isCommonPrefix(vector<string>& strs, int len){
        
        string s = strs[0].substr(0,len);
        for(auto &cmpstr: strs)
        {
            if(cmpstr.substr(0,len) != s)
                return false;
        }
        
        return true;
    }
};