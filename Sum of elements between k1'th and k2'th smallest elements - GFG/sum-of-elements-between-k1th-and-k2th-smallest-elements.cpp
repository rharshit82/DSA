// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        priority_queue<long long> pq;
        for(long long i=0;i<N;i++){
            pq.push(A[i]);
            if(pq.size()>K2) pq.pop();
        }
        long long K2thSmallest = pq.top();
        long long res=0;
        for(long long i=0;i<K2-K1-1;i++){
            pq.pop();
            res+=pq.top();
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends