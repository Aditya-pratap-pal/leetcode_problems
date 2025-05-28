class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        priority_queue<int,vector<int>, greater<int>> used_query;
        priority_queue<int> available_query;
        sort(queries.begin(),queries.end());
        int cq=0,use_count=0;
        for(int i=0;i<n;i++){
            //ith index query inserted at this place..
            while(cq<queries.size() && queries[cq][0]==i){
                available_query.push(queries[cq][1]);
                cq++;
            }  
            nums[i]-=used_query.size();
            while(nums[i]>0 && !available_query.empty() && available_query.top()>=i){
                used_query.push(available_query.top());
                available_query.pop();
                nums[i]--;
                use_count++;
            }
            if(nums[i]>0)return -1;
            while(!used_query.empty() && used_query.top()==i){
                used_query.pop();
            }
        }
            return queries.size()-use_count;
    }
};