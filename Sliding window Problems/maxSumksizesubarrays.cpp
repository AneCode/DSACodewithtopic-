// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &v , int N){
       int csum=0,max=-1e7,pre,i;
       for( i=0;i<K;i++){
           csum+=v[i];
       }
       pre=0;
       if(max<csum)
       max=csum;
       for(i;i<N;i++){
           csum=csum-v[pre++]+v[i];
           if(max<csum)
           max=csum;
       }
       return max;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends
