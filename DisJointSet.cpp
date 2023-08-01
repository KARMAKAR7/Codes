#include<bits/stdc++.h>
 using namespace std;
 // creating the disjoint class
  class DisJoinSet{
     vector<int>rank,parent,size;
     public:
        DisJoinSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1,0);
            size.resize(n+1,0);
              for(int i =0 ;i<=n;i++){
                 parent[i]=i;
                 size[i]=1;
              }
        }
        // find prent funcation and path comparsion
         int findUpar(int node){
            if(node==parent[node])
              return node;
              // path comparision
            return parent[node]=findUpar(parent[node]);
         }
       // unionmake funcation
         void  UnionByRnak(int u , int v)
             {
              int ulp_u = findUpar(u);
              int ulp_v = findUpar(v);
               if(ulp_u==ulp_v) return ;
               if(rank[ulp_u]<rank[ulp_v]){
                    parent[ulp_u]=ulp_v;
               }
               else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
               }
               else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
             }
         }
          void  UnionBySize(int u , int v)
             {
              int ulp_u = findUpar(u);
              int ulp_v = findUpar(v);
               if(ulp_u==ulp_v) return ;
                
                 if(size[ulp_u]<size[ulp_v]){
                     parent[ulp_u]=ulp_v;
                      size[ulp_v]+=size[ulp_u];
                 }
                 else{
                    parent[ulp_v]=ulp_u;
                      size[ulp_u]+=size[ulp_v];
                 }

             }
 };
  int main(){
    // make a disjoint function 
        DisJoinSet ds(7);
         ds.UnionBySize(1,2);
         ds.UnionBySize(2,3);
         ds.UnionBySize(4,5);
         ds.UnionBySize(6,7);
         ds.UnionBySize(5,6);
         // check if 3 and 7 same or not

          if(ds.findUpar(3)==ds.findUpar(7)){
               cout<<"Same\n";
          }else{
            cout<<"Not Same\n";
          }
         ds.UnionBySize(3,7);
           if(ds.findUpar(3)==ds.findUpar(7)){
               cout<<"Same\n";
          }else{
            cout<<"Not Same\n";
          }


     return 0;
  }