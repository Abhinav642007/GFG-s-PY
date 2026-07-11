class Solution:
    def isvowel(self,ch):
        vowels="aeiouAEIOU"
        return ch in vowels
    def modify(self, s):
        # code here
        s=list(s)
        i=0
        j=len(s)-1
        while(i<j):
            if not self.isvowel(s[i]):
                i+=1
            elif not self.isvowel(s[j]):
                j-=1
            else:
                s[i],s[j]=s[j],s[i]
                i+=1
                j-=1
        
        return "".join(s)