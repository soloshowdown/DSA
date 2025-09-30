class Solution {
public:
    string intToRoman(int num) {
        // Roman numeral symbols and their integer values
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result = "";

        for(int i = 0; i < values.size(); i++) {
            // While the current value can fit into num
            while(num >= values[i]) {
                num -= values[i];          // Reduce num
                result += symbols[i];      // Add Roman symbol
            }
        }

        return result;
    }
};
