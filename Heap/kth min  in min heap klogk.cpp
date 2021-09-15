#include <bits/stdc++.h>
using namespace std; 
  int parent(int i){return (i-1)/2 ;}
    int left(int i){return 2*i+1 ;}
    int right(int i){return 2*i+2;}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>h;
  
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        h.push_back(x);
    }
    make_heap(h.begin(),h.end(),greater<int>());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    p.push(make_pair(h[0],0));
    int count=0;
   for(int i=0;i<k-1;i++){
        int j=p.top().second;
        p.pop();
            if(left(j)<h.size())
            p.push(make_pair(h[left(i)],left(i)));
            if(right(j)<h.size())
            p.push(make_pair(h[right(i)],right(i)));

    }
    cout<<p.top().first;
     return 0; 
}