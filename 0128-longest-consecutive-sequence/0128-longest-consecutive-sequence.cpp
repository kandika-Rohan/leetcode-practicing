#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]); 
    }

    void unite(int x, int y) {
        int u = find(x);
        int v = find(y);

        if (u != v) {  
            if (size[u] < size[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }

    int sizeof_comp(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
       int n=nums.size();

       DSU ds(n);

       if(n==0)return 0;
       if(n == 1)return 1;

       unordered_map<int,int>map;

       for(int i=0;i<nums.size();i++){

        if(map.find(nums[i]) != map.end())continue;

        map[nums[i]]=i;

        if(map.find(nums[i]+1) != map.end()){
            ds.unite(i,map[nums[i]+1]);
        }
        if(map.find(nums[i]-1) != map.end()){
            ds.unite(i,map[nums[i]-1]);
        }
       }

       int ans=0;

       for(int i=0;i<n;i++){
        if(i == ds.find(i)){
            ans=max(ans,ds.sizeof_comp(i));
        }
       }

       return ans;
    }
};
