class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        map_v = { 'I' :1 ,  'V' :5 ,  'X' :10 ,  'L' :50,'C':100 ,'D':500 ,'M':1000}
        res = 0
        for i in range(len(s)):
            if i < len(s) -1 and map_v[s[i]] < map_v[s[i+1]]:
                res -= map_v[s[i]]
            else:
                res += map_v[s[i]] 
            
        return res

        