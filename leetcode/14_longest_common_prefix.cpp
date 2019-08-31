class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count;
        string empty = "", s1, s2, result = "";
        // invalid case
        if(strs.empty())
            return empty;       
        if(strs.size() < 2)
            return strs[0];
        // valid case
        s1 = strs[0];    
        for(int i = 0; i < s1.length(); i++){
            count = 0;
            for(int j = 1 ; j < strs.size(); j++){ 
                s2 = strs[j];
                if(s1[i] == s2[i])
                    count++;         
            }
            if(count == strs.size() - 1)
                result += s1[i]; 
            else
                return result;
        }
        return result;
    }
};
    
