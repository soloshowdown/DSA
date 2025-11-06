class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int n=nums.size();
        int curr=0; //keep track of the OR of current subrray
        int start=0;
        vector<int>freq(32,0); // storing frequency of bits in this vector as we go on 
        
        for(int i=0;i<n;i++){
            
            curr=0;
            for(int j=0;j<32;j++){
                freq[j]+= ((nums[i]>>j) & 1)==1 ? 1 : 0 ;
                if(freq[j]>=1){
                    curr= curr | (1<<j);
                }
            }
            
            while(start<=i && curr>=k){
                ans=min(ans,i-start+1);
                curr=0;
                for(int j=0;j<32;j++){
                 freq[j]+= ((nums[start]>>j) & 1)==1 ? -1 : 0 ;
                if(freq[j]>=1){
                    curr= curr | (1<<j);}
                }  
               start++;
            }
            
            
        }
        return ans==INT_MAX ? -1 : ans;  
    }
};