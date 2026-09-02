class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;
        for(int i=0;i<heights.size();i++){
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end());
        int j=0;
        for(int i=heights.size()-1;i>=0;i--){
            names[j]=v[i].second;
            j++;
        }
        return names;
    }
};