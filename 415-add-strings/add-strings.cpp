class Solution {
public:
    void add(string a,string b,string &result){
        int i=a.size()-1, j=b.size()-1;
        int carry=0;
        
        int sum=0;
        while(j>=0){
            sum= (a[i]-'0')+(b[j]-'0')+carry;
            char c='0'+sum%10;
            result+=c;
            carry=sum/10;
            i--,j--;
        }
        while(i>=0)
        {
            sum=(a[i]-'0')+ carry;
            char c='0'+sum%10;
            result+=c;
            carry=sum/10;
            i--;
        }
        if(carry) result+='1';

        reverse(result.begin(),result.end());
        
    }
    string addStrings(string num1, string num2) {
        string result="";
        if(num1.size()<num2.size()){
            add(num2,num1,result);
        }
        else add(num1,num2,result);
        return result;
    }
    
};