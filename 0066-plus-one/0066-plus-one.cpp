class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;      //checking if there is a nine
        }
        vector<int> new_number(n + 1, 0);   // altering if all are nines by making a new array which ia a old array+1 in size and making the first digit as one rest zeros
        new_number[0] = 1;
        return new_number;
    }
};