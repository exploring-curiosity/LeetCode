class Solution {
    vector<string> res;
    string letters(char n){
        
        switch(n){
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: return "";    
        }   
        
    }
public:
    vector<string> letterCombinations(string digits) {
        
        int n= digits.size();
        if(n==0)
            return vector<string>{};
        string let = letters(digits[0]);
        for(int i=0;i<let.length();i++){
            string s="";
            res.push_back(s+let[i]);
        }
        
        for(int i=1;i<n;i++){
            string let = letters(digits[i]); 
            int m = res.size();
            for(int j=0;j<m;j++){
                for(int k=0;k<let.length();k++){
                    res.push_back(res[0]+let[k]);  
                }
                res.erase(res.begin());
            }
        }
    return res;    
        
    }
};