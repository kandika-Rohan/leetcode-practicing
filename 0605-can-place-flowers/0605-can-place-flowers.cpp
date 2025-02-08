class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int m=flowerbed.size();

        if(m == 1){
            if(flowerbed[0] == 0 && n <= 1){
                return true;
            }
        }

        vector<int>nums=flowerbed;

        if(m>=2){

            if(nums[0]==0 && nums[1] == 0){
                nums[0]=1;
                n--;
            }
        }

        if(m>=2 && nums[m-1] == 0 && nums[m-2] == 0){
            nums[m-1]=1;
            n--;
        }


        for(int i=1;i<m-1;i++){

            if(nums[i-1] != 1 && nums[i+1] != 1 && nums[i] == 0){
                nums[i]=1;
                n--;
            }
            if(n<=0){
                return true;
            }
        }

        return n<=0;
        
    }
};