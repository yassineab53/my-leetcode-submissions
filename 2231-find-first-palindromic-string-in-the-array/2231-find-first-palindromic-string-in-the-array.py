class Solution(object):
    def firstPalindrome(self, words):
   
        for i in words:
            if i == i[::-1]:
                return i 
        return ""
        