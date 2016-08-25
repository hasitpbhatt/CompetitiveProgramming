// O(n) : 4 ms

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry = 1;
        for(int i=0;i<digits.size();i++) {
            if(digits[i]+carry < 10) {
                digits[i] += carry;
                carry = 0;
                break;
            } else {
                digits[i] = 0;
            }
        }
        if(carry)
            digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};