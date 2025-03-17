class Solution {
public:
    int recurr(vector<int>&coins,int index, int amount,vector<vector<int>>&v){
        if(amount==0){
            v[index][amount] = 0;
            return v[index][amount];
        }
        if(index == 0){
            if(amount % coins[index] == 0){
                v[index][amount] = amount / coins[index];
                return v[index][amount];
            }
            else{
                v[index][amount] = 1e9;
                return v[index][amount];
            }
        }
        if(v[index][amount] != -1){
            return v[index][amount];
        }
        int pick = 1e9;
        if(coins[index] <= amount){
            pick = 1+ recurr(coins,index,amount-coins[index],v);
        }
        int no_pick = recurr(coins,index-1,amount,v);
        v[index][amount] = min(pick,no_pick);
        return v[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>v(n,vector<int>(amount+1,-1));
        int result = recurr(coins,n-1,amount,v);
        if(result >= 1e9)return -1;
        return result;
    }
};
