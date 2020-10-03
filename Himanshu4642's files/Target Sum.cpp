/*The problem is same as CountofSubsetswithgivenDiff*/

int CountofSubsetswithgivenSum(int arr[],int sum,int n){
	int dp[n+1][sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0 && j==0)
			dp[i][j]=1;
			else if(i==0)
			dp[i][j]=0;
			else if(j==0)
			dp[i][j]=1;
			else{
				if(arr[i-1]<=j){
					dp[i][j]=(dp[i-1][j-arr[i-1]])+(dp[i-1][j]);
				}else{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}
	return dp[n][sum];
}

int countofsubsetswithgivenTargetSum(int arr[],int tsum,int n){
	int sum=0;
	for(int i=0;i<n;i++)
	sum+=arr[i];
	int s1=(tsum+sum)/2;
	return CountofSubsetswithgivenSum(arr,s1,n);
}

