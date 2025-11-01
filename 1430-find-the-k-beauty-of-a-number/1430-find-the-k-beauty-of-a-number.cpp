class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count =  0;

        for( int i =0; i+k <= s.size(); i++){
            string sub = s.substr(i,k);
            int val = stoi(sub);
             if (val != 0 && num % val == 0) { // check divisibility and avoid divide by zero
                count++;
            }
        }
        return count;
    }
};