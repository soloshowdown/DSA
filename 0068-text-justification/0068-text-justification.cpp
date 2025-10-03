class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i, lineLen = 0;

            // Step 1: Choose words for the current line
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int spaces = maxWidth - lineLen;
            int gaps = j - i - 1;
            string line = "";

            // Step 2: If last line OR only one word → left justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } 
            // Step 3: Otherwise → distribute spaces evenly
            else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
