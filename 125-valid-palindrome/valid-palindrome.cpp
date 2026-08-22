class Solution {
public:
    bool isPalindrome(string s) {
        string x="";
        for(int i=0;i<s.size();i++){
            int asc =int(s[i]); 
            if((asc >=65 && asc <=90) || (asc>=97 && asc<=122)
            || (asc >= 48 && asc <= 57)){
                x+=s[i];
            }
        }
        for(char &ch: x){
            ch=tolower(ch);
        }

        int i=0, j=x.size()-1;
        while(i<j){
            if(x[i]!=x[j]) return false;
            i++,j--;
        }
        return true;

    }
};