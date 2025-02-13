class Solution:
    def partitionString(self, s: str) -> int:
        result = 0

        temp = set()

        for i in range(len(s)):
            if(s[i] in temp):
                result += 1
                temp = set()
            temp.add(s[i])
        if(temp):
            return result + 1
        return result            

