regex exponent1("^[+-]?[0-9]+[.]?[0-9]*([eE][+-]?[0-9]+)?");
regex exponent2("^[+-]?[.][0-9]+([eE][+-]?[0-9]+)?");
class Solution {
public:
    bool isNumber(string s){      
        if(regex_match(s,exponent1))
            return true;
        if(regex_match(s,exponent2))
            return true;
        return false;                
    }
};