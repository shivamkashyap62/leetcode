class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        int row_start=0;
        int row_end=n-1;
        int col_start=0;
        int col_end=m-1;

        int total=m*n;
        int count=0;

        vector<int>ans;
        while(count<=total){
            //rowstart , colstart->colend;
            for(int i=col_start;i<=col_end;i++){
                ans.push_back(matrix[row_start][i]);
                count++;
            }
            row_start++;

            if(count==total) break;

            //colend, rowstart->rowend
            for(int i=row_start;i<=row_end;i++){
                ans.push_back(matrix[i][col_end]);
                count++;
            }
            col_end--;

            if(count==total) break;

            //rowsend, colend->colstart;
            for(int i=col_end;i>=col_start;i--){
                ans.push_back(matrix[row_end][i]);
                count++;
            }
            row_end--;
            if(count==total) break;

            //colstart, rowend->rowstart
            for(int i=row_end;i>=row_start;i--){
                ans.push_back(matrix[i][col_start]);
                count++;
            }
            col_start++;
            if(count==total) break;

        }
        return ans;
    }
};