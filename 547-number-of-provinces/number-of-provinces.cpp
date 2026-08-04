class Solution {
public:
    void bfs(int i,vector<bool>&vis ,vector<int>list[]){
        vis[i]=true;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it : list[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>list[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j) list[i].push_back(j);
            }
        }

        vector<bool>vis(n,false);

        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                count++;
                bfs(i,vis,list);
            }
        }
        return count;

    }
};