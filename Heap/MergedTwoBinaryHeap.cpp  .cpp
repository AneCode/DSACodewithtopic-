// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       vector<int>res;
      make_heap(res.begin(),res.end());
      make_heap(a.begin(),a.end());
      make_heap(b.begin(),b.end());
       if(n==0 || m==0){
           if(n==0) return a; else return b;
       }
      if(n>=m){
          while(b.size()){
              int r1=a.front();
              int r2=b.front();
              pop_heap(a.begin(), a.end());
             a.pop_back();
             pop_heap(b.begin(), b.end());
             b.pop_back();
              if(r1>r2)
              {
                  res.push_back(r1);
                 push_heap(res.begin(),res.end());
                 res.push_back(r2);
                 push_heap(res.begin(),res.end());
              }
              else{
                  res.push_back(r2);
                 push_heap(res.begin(),res.end());
                 res.push_back(r1);
                 push_heap(res.begin(),res.end());
              }
              
          }
          while(a.size()){
            int r1=a.front(); 
              pop_heap(a.begin(), a.end());
             a.pop_back();
             res.push_back(r1);
            push_heap(res.begin(),res.end());
          }
          
      }
      else{
          while(a.size()){
              int r1=a.front();
              int r2=b.front();
              pop_heap(a.begin(), a.end());
             a.pop_back();
             pop_heap(b.begin(), b.end());
             b.pop_back();
              if(r1>r2)
              {
                  res.push_back(r1);
                  push_heap(res.begin(),res.end());
                   res.push_back(r2);
                  push_heap(res.begin(),res.end());
              }
              else{
                  res.push_back(r2);
                  push_heap(res.begin(),res.end());
                   res.push_back(r1);
                  push_heap(res.begin(),res.end());
              }
              
          }
          while(b.size()){
            int r1=b.front(); 
              pop_heap(b.begin(), b.end());
             b.pop_back();
             res.push_back(r1);
            push_heap(res.begin(),res.end());
          }
      }
      return res;
    }
};

// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
  // } Driver Code Ends