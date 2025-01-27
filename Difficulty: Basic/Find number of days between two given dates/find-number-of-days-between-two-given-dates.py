#User function Template for python3

from datetime import date

class Solution:
    def noOfDays(self, d1, m1, y1, d2, m2, y2):
        # code here 
        date1=date(y1,m1,d1)
        
        date2=date(y2,m2,d2)
        
        return abs((date2-date1).days)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        d1,m1,y1=map(int,input().split())
        d2,m2,y2=map(int,input().split())
        
        ob = Solution()
        print(ob.noOfDays(d1,m1,y1,d2,m2,y2))
# } Driver Code Ends