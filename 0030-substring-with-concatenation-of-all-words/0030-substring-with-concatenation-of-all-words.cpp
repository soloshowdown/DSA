class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();          // length of each word
        int numWords = words.size();            // total number of words
        int windowLen = wordLen * numWords;     // total window size

        if (s.size() < windowLen) return result;

        // Step 1: Store frequency of words
        unordered_map<string, int> wordCount;
        for (string &word : words)
            wordCount[word]++;

        // Step 2: Try every starting offset (0 to wordLen - 1)
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            // Step 3: Move window in chunks of wordLen
            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen); // current word

                if (wordCount.find(word) != wordCount.end()) {
                    seen[word]++;
                    count++;

                    // If word frequency exceeds expected, shrink window
                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If all words matched
                    if (count == numWords)
                        result.push_back(left);
                }
                else {
                    // Invalid word → reset window
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
