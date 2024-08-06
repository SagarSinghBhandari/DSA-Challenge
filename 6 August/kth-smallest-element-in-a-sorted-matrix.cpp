class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n  = matrix.size();
        int visisted = 1e9 +1 ,res;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pq.push(matrix[i][j]);
            }
        }
        while(!pq.empty() && k>0){
            res = pq.top();
            pq.pop();
            k--;
        }
        return res;
    }
};