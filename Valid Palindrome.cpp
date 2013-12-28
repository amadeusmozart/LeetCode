class Solution {
public:
    struct my_predicate : std::unary_function<char, bool>
    {
        bool operator()(char c) const {
            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                return false;
            else
                return true; 
        }
    };
    
    bool ispal(string s)
    {
        int len = s.length();
        bool b;
        
        while(len >= 2)
        {
            if(s[0] == s[len - 1])
                b = true;
                
            else if((s[0] >= 'a' && s[0] <= 'z') && (s[len - 1] >= 'A' && s[len - 1] <= 'Z') && (s[0] - 'a' + 'A') == s[len - 1])
                b = true;
                
            else if((s[len - 1] >= 'a' && s[len - 1] <= 'z') && (s[0] >= 'A' && s[0] <= 'Z') && s[0] == (s[len - 1] - 'a' + 'A'))
                b = true;
                
            else
                return false;
                
            s = s.substr(1, len - 2);
            len = len - 2;
            
            if(b == true)
                continue;
                
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), my_predicate()), s.end());
        return ispal(s);
    }
};
