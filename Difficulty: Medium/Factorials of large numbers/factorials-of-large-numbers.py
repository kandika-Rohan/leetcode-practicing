#User function Template for python3

class Solution:
    def factorial(self, N):
        fact=1;
        for i in range(1,N+1):
            fact*=i
        a=str(fact);
        
        L=[int(i) for i in a]
        
        return L;


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.factorial(N)
        for i in ans:
            print(i, end="")
        print()

# } Driver Code Ends