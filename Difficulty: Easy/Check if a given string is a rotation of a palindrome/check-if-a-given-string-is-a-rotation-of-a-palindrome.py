#User function Template for python3
class Solution:
    def ispalindrome(self,s):
        l=0
        h=len(s)-1
        while(h>l):
            l+=1
            h-=1
            if(s[l-1]!=s[h+1]):
                return False
        return True
	def isRotatedPalindrome(self, s):
		#code here
		n=len(s)
		c=s+s
		for i in range(n):
		    if self.ispalindrome(c[i:i+n]):
		        return 1
		return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
	T = int(input())

	for _ in range(T):
		s = input()
		ob = Solution()
		answer = ob.isRotatedPalindrome(s)
		print(answer)
		
# } Driver Code Ends