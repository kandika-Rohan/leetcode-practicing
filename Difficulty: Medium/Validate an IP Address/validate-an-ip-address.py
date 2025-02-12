#User function Template for python3
class Solution:
    
    def isValid(self, s):
        # Split the string by dots
        arr = s.split('.')

        # Check if there are exactly 4 parts
        if len(arr) != 4:
            return False

        for i in arr:
           
            if not i.isdigit():
                return False

           
            if len(i) > 1 and i[0] == '0':
                return False

           
            num = int(i)
            if num < 0 or num > 255:
                return False

        return True





#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends