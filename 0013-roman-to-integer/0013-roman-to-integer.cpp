#include <queue>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;              // Final result (integer value of Roman numeral)
        int previousValue = 1001;   // Start with a large value (greater than max Roman i.e., 1000)
        int count = 0;              // Keeps track of how many times the same Roman numeral repeats

        // Traverse each character in the Roman numeral string
        for (char c : s) {
            int value = getIntValue(c); // Convert Roman character to integer

            // Case 1: Current value is greater than previous value
            // → Subtraction rule (like IV = 4, IX = 9, etc.)
            if (value > previousValue) {
                total -= count * previousValue; // Subtract the entire group of previous values
                count = 0;                      // Reset the group
            }
            // Case 2: Current value is smaller than previous value
            // → Previous group is complete, add it to total
            else if (value < previousValue) {
                total += count * previousValue; // Add the entire group of previous values
                count = 0;                      // Reset the group
            }

            // Add current value to the group (count how many same values we have seen)
            count++;
            // Update previousValue for the next iteration
            previousValue = value;
        }

        // After loop ends, last group might still be pending → add it
        total += count * previousValue;

        return total;
    }

    // Helper function: convert single Roman character into its integer value
    int getIntValue(char r) {
        switch (r) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // For safety, though input is always valid
        }
    }
};
