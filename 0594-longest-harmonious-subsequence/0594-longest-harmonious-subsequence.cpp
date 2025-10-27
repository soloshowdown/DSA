class Solution {
public:
    int findLHS(vector<int>& arr) {
        int max_count = 0 ,  count = 0  ;
        int l = 0 , r = 0 ;
        int n = arr.size() ;
        sort( arr.begin() , arr.end() ) ;
        while ( r < n  ) {
            int min = arr[l] ;
            
            if ( abs( arr[r] - min ) == 1 ) {
                count = r - l + 1 ;
                if ( count > max_count ) {
                    max_count = count ;
                }
                r++ ;
            }
            else if ( abs( arr[r]  - min ) > 1 ) {
                while ( abs( arr[r] - arr[l] ) > 1 ) {
                    l++ ;
                }
            }
            else {
                r++ ;
            }
        }
        return max_count ;
    }
};