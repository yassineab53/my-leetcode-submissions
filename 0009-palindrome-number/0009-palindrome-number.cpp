class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        std::string str = std::to_string(x);

        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;  
            }
            left++;
            right--;
        }

        return true; 
    }
};  
