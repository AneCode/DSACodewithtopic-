#include <bits/stdc++.h>
using namespace std;
int parent(int i){
  return (i-1)/2;  
} 
int  main(){
   
    int n;
   cin>>n;
   vector<int>v;
   for(int i=0;i<n;i++){
       int x;
       cin>>x;
       v.push_back(x);
   }
   make_heap(v.begin(),v.end(),greater<int>());
   int i=v.size()-1;
   i=parent(i)+1;
   int max=-1;
   for(int j=i;j<v.size();j++){
       if(max<v[j])
       max=v[j];
   }   
   cout<<"max:"<<max;

    return 0;
}