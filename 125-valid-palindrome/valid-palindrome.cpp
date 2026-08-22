class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            char cl=tolower(s[i]);
            char cr=tolower(s[j]);
             
            if(!isalnum(cl)) i++; 
            else if(!isalnum(cr)) j--;

            else{
                if(cl!=cr) return false;
                i++,j--;
            } 
        }
        return true;

    }
};