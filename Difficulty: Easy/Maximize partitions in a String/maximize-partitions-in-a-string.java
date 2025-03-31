//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();

        while (tc-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();
            int ans = obj.maxPartitions(s);
            System.out.println(ans);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    public int maxPartitions(String s) {
        HashMap<Character,Integer> maxIndex = new HashMap<>();
        
        for(int i=0; i<s.length(); i++){
            maxIndex.put(s.charAt(i),i);
        }
        
        int max = 0;
        int cnt = 0;
        
        for(int i=0; i<s.length(); i++){
            int curMax = maxIndex.get(s.charAt(i));
            max = Math.max(curMax,max);
            if(curMax == i && max == i){
                cnt++;
            }
        }
        
        return cnt;
    }
}