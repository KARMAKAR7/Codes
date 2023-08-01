#include<bits/stdc++.h>
     using namespace std;
          int main(){
             int n,m,source;
                cin>>n>>m;
                vector<pair<int,int>>g[n+1];//1 index adjency list
                 int a,b,wt;
                 for(int i=0;i<n;i++)
                 {
                    cin>>a>>b>>wt;
                    g[a].push_back({b,wt});
                    g[b].push_back({a,wt});
                 }
                 cin>>source;
                  
                //Dijakstra algo
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //min heap
                     vector<int>dis(n+1,INT_MAX);// 1 index arry for calculating the sortest path
                      dis[source]=0;
                        pq.push({0,source});//{dist,from}
                          while(!pq.empty()){
                             int dist= pq.top().first;
                             int prev=pq.top().second;
                              pq.pop();
                               for(auto it:g[prev]){
                                  int next=it.first;
                                  int nextdist=it.second;
                                  if(dis[next]>dist+nextdist){
                                    dis[next]=dist+nextdist;
                                    pq.push({dis[next],next});
                                  }
                               }

                          }
                          cout<<"The Distance from the source:"<< source<<"are:\n";
                           for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
                          

              return 0;
          }
               
          