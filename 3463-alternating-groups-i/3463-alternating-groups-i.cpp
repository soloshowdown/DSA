class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c) {
        int n = c.size();
        int count = 0;
        c.push_back(c[0]);
        c.push_back(c[1]);
        for(int i=0;i<n;i++){
            if(c[i]!=c[i+1] && c[i+2]==c[i]) count++;
        }
        return count;
    }
};