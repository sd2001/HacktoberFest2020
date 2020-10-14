/*There is a slight difference in 0-1 knapsack and subset sum problem.
First diff is the initialisation and changing max into Bitwise OR operation.
Rest ignore val[] array and change wt[] array into the problem arr[] array.*/


bool subsetSum(int arr[],int sum,int n){
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0 && j==0)
			dp[i][j]=true;
			else if(i==0)
			dp[i][j]=false;
			else if(j==0)
			dp[i][j]=true;
			else{
				if(arr[i-1]<=j){
					dp[i][j]=(dp[i-1][j-arr[i-1]])||(dp[i-1][j]);
				}else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}
	return dp[n][sum];
}
