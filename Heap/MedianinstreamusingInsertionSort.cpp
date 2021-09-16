#include <bits/stdc++.h>
using namespace std;
void swap(int *x,int*y){
   int temp=*x;
    *x=*y;
     *y=temp;
}
void print(vector<int>v){
    for(auto i:v){
        cout<<i<<"|";
    }
    cout<<endl;
}

float median(vector<int>&v){
   int n=v.size();
   if(n%2)
   {
      return v[(n-1)/2]; 
   }
   else{
          float ans=v[(n-1)/2] +v[(n+1)/2];
         return (ans/2);
   }
}
void addElement(vector<int>&v,int x){
    v.push_back(x);
      int j=v.size()-1;
     while(j>0 && v[j]<v[j-1]){
          swap(v[j],v[j-1]);
          j--;
  }
  print(v);    
}
void deleteElement(vector<int>&v){
 v.pop_back();
}
int main()
{
    vector<int>v{10};
    addElement(v,3);
  cout<< median(v)<<endl;
    addElement(v,6);
    cout<<median(v);

    return 0;
}