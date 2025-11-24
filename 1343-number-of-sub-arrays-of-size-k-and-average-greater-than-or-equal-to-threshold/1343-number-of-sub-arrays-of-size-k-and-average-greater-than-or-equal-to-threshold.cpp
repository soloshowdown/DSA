class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sz=arr.size()+5;
        vector<int>pre(sz,0);
        int ans=0;
        pre[0]=0;
        for(int i=1;i<=arr.size();i++){
            pre[i]=pre[i-1]+arr[i-1];
        }int j=1;
        for(int i=k;i<=arr.size();i++){
            int val=(pre[i]-pre[j-1])/k;
            if(val>=threshold){
                ans++;
            }
            j++;
        }
        return ans;
    }
};