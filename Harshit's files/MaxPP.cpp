#include <iostream>
#include <cstdlib>
#include <array>
using namespace std;

/*int MaxPairwiseProduct(int arrofnos[ ])
{
	//why is .size() not working?!
	int n = 0;
	//array<int,5> myInts;
	//cout << myInts.size();
	n = sizeof(arrofnos)/sizeof(arrofnos[0]);
	cout << sizeof(arrofnos) << " " << sizeof(arrofnos[0]) << endl;
	cout << "n = " << n << endl;
	for(int a=0;a<=n;a++)
		cout << arrofnos[a] << " ";
	int maxIndex1 = -1;
	int maxIndex2 = -1;
	for (int k=0;k<=n;k++)
	{
		if (arrofnos[k]>arrofnos[maxIndex1])
		{
			maxIndex1=k;
		}
	}
	for (int j=0;j<=n;j++)
	{
		if(j==maxIndex1)
		{
			continue;
		}
		if (arrofnos[j]>arrofnos[maxIndex2])
		{
			maxIndex2=j;
		}
	}
	int result = arrofnos[maxIndex1]*arrofnos[maxIndex2];
	
	return result;
}*/

int main()
{
	//defining size of array and creating it
	int n = 0;
	cin >> n;
	int arr_of_nos[n];
	for (int i=0;i<n;i++)
		cin >> arr_of_nos[i];
		
	/*stress testing
	int n = (rand() % 50)+2;
	int arr_of_nos[n];
	for (int i=0;i<n;i++)
	{
		arr_of_nos[i] = (rand()%100000);
		cout << arr_of_nos[i] << " ";
	}
	cout << endl;*/
	
	//choosing maximum 2 numbers
	int maxIndex1 = -1;
	int maxIndex2 = -1;
	for (int k=0;k<n;k++)
	{
		if (arr_of_nos[k]>arr_of_nos[maxIndex1])
		{
			maxIndex1=k;
		}
	}
	for (int j=0;j<n;j++)
	{
		if(j==maxIndex1)
		{
			continue;
		}
		if (arr_of_nos[j]>arr_of_nos[maxIndex2])
		{
			maxIndex2=j;
		}
	}
	
	
	int result = arr_of_nos[maxIndex1]*arr_of_nos[maxIndex2];
	
	//int nresult = MaxPairwiseProduct(arr_of_nos);
	cout << result << "\n";
	//cout << nresult << "\n";
	return 0;
	
}


