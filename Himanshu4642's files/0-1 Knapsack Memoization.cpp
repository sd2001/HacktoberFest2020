//Initial steps
int dp[n+1][W+1];
memset(dp,-1,sizeof(dp));

//function for filling the dp table
int knapsack(int wt[],int val[],int W,int n){
	if(W==0||n==0){
		return 0;
	}
	if(dp[n][W]!=-1)
	return dp[n][W];
	if(wt[n-1]<=W){
		return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
	}
	else{
		return dp[n][W]=knapsack(wt,val,W,n-1);
	}
}
