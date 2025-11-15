class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n =fruits.size() ;
        int maxi = INT_MIN;
         unordered_map<int, int>mp;
             int i = 0 ;
         for(int  j = 0 ; j< n ; j++){
            mp[fruits[j]]++;
            while (mp.size() >2 ){
                mp[fruits[i]]--;
                if (mp[fruits[i]]== 0)
                mp.erase(fruits[i]);
                  i++;
            }
          maxi = max(maxi ,j-i+1);

         }
         return maxi; //Akshay
    }
};