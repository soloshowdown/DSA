class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
       int n = nums.size();
      // int size = n-k+1;
        vector<int> ans;
        int cnt =0;
        unordered_map<int,int> map ;
        int ind =0;
        for(int i=0;i<n;i++){
        while(i<n && cnt!=k){
            map[nums[i]]++;
            //cout<<nums[i]<<" cnt : "<<map[nums[i]]<<endl;
            i++;
            cnt++;
        }
        // in hashmap it will store like this 1--> 2 
        // now we will store in an hashmap       
        //  int temp = map.size();
        priority_queue<pair<int,int>> pq ;
        for(auto &it : map){
            int f = it.first;
            int s = it.second ;
            pq.push({s,f}); 
        }
        int temp=x;
        int sum =0;
        while( !pq.empty() && temp>0  ){
            int fre = pq.top().first;
            int ele =pq.top().second ;
            sum+= (fre*ele);
            pq.pop();
            temp--;
        }
        ans.push_back(sum);
       
       map[nums[ind]]--;
     //   cout<<"deletinf "<<nums[ind]<<"its cnt : "<<map[nums[ind]]<<endl;
       cnt--;
       if( map[nums[ind]]==0) {
        map.erase(nums[ind]);
       // cout<<"deleted elemnt "<<endl;
       }
       ind++;
      // cout<<"the inde is : "<<ind<<endl;
       i--;
      }
      return ans ;
    }
};