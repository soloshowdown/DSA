class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        colors.push_back(colors[0]);
        colors.push_back(colors[1]);
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[i+1] && colors[i+2]==colors[i]) count++;

        }
        return count;
    }
};