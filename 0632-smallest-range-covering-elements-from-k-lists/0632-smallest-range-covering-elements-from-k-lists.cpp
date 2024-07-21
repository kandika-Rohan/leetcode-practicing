class Solution {
public:
    class node{
        public:
        int data;
        int row;
        int col;
        node(int d,int r,int c){
            this->data = d;
            this->row = r;
            this->col = c;
        }
    };
    class compare{
        public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> pq;
        int n = nums.size();
        int m = nums[0].size();
        for(int i = 0; i < n; i++){
            int element = nums[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element); // Mistake: Incorrectly declared a new 'int maxi' instead of using the existing 'maxi'
            node* newnode = new node(element, i, 0);
            pq.push(newnode);
        }
        int start = mini;
        int end = maxi;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            mini = temp->data; // Mistake: Re-declaring mini. Should not redeclare mini.
            int row = temp->row;
            int col = temp->col;
            if(end - start > maxi - mini){
                start = mini;
                end = maxi;
            }
            if(col + 1 <  nums[row].size()){
                node* newnode = new node(nums[row][col + 1], row, col + 1);
                pq.push(newnode); 
                maxi = max(maxi, nums[row][col + 1]); 
            }
            else{
                break;
            }
        }
        return {start, end};
    }
};
