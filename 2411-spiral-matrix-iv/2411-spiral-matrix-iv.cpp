/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));

        int top=0;
        int left=0;
        int bottom=m-1;
        int right=n-1;
        vector<int>list(m*n,-1);
        int i=0;
        while(head){
            list[i]=head->val;
            i++;
            head=head->next;
        }
        int j=0;
        while(top<=bottom && left <=right){

            for(int i=left;i<=right;i++){
                mat[top][i]=list[j];
                j++;
            }
            top++;

            for(int i=top;i<=bottom;i++){
                mat[i][right]=list[j];
                j++;
            }
            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    mat[bottom][i]=list[j];
                    j++;
                }
                bottom--;
            }

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    mat[i][left]=list[j];
                    j++;
                }
                left++;
            }
        }

        return mat;
    }
};