class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> v = score;//sorted scores
        sort(v.begin(),v.end(), greater<int>());
        vector<string> medals={"Gold Medal","Silver Medal","Bronze Medal"};
        unordered_map<int, string> rankMapping;
        for(int i =0;i<v.size(); i++){
            if(i<3){
                rankMapping[v[i]] = medals[i];
            }
            else{
                rankMapping[v[i]] = to_string(i+1);
            }
        }
        vector<string> result;
        for(int s: score){
            result.push_back(rankMapping[s]);
        }
        return result;
    }
};