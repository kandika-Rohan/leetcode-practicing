//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;


// } Driver Code Ends
// User function Template for Java

class Solution {

    int countPairs(int arr[], int target) {
        // Complete the function
        int count=0;
        HashMap<Integer,Integer> k=new HashMap<>();
        for(int i=0;i<arr.length;i++){
            k.put(arr[i],k.getOrDefault(arr[i],0)+1);
        }
        for(int i=0;i<arr.length;i++){
            if(k.containsKey(target-arr[i]) && target-arr[i]!=arr[i]){
                count+=k.get(target-arr[i]);
            }
            else if(k.containsKey(target-arr[i]) && target-arr[i]==arr[i]){
                k.put(arr[i],k.get(arr[i])-1);
                count+=k.get(target-arr[i]);
                continue;
            }
            if(k.get(arr[i])>1){
                k.put(arr[i],k.get(arr[i])-1);
            }
            else{
                k.remove(arr[i]);
            }
        }
        return count;
    }
}


//{ Driver Code Starts.
class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim()); // Inputting the testcases
        while (t-- > 0) {
            String[] inputLine = br.readLine().trim().split(" ");
            int[] arr = new int[inputLine.length];
            for (int i = 0; i < inputLine.length; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            inputLine = br.readLine().trim().split(" ");
            int target = Integer.parseInt(inputLine[0]);

            Solution obj = new Solution();
            int res = obj.countPairs(arr, target);
            System.out.println(res);
            System.out.println("~");
        }
    }
}
// } Driver Code Ends