class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> v=heights;
        stack<int> s;
        s.push(-1);
        int maxi = INT_MIN;
        for(int i=0;i<v.size();i++){
            while(s.top()!=-1 && v[i]<v[s.top()]){
                int height = v[s.top()];
                s.pop();
                int width = i-s.top()-1;
                maxi = max(maxi,height*width);
            }
            s.push(i);
        }
        while(s.top()!=-1){
            int height = v[s.top()];
            s.pop();
            int width = v.size()-s.top()-1;
            maxi = max(maxi,height*width);
        }
        return maxi;
    }
};