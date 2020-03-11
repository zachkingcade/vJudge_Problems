#include <iostream>
#include <vector>
#include <string>


#define endl "\n"

using namespace std;

typedef vector<int> vectorInt;
typedef pair<int ,int> intPair;
typedef vector<intPair> vectorIntPair;


const int VISITED = 1;
const int UNVISITED = -1;

vectorInt dfs_num;
vector<vectorIntPair> AdjList;

void dfs(int u){
    dfs_num[u] = VISITED;
    cout <<"-dfs:"<<u<<" ";
    for(int j = 0; j < (int) AdjList[u].size(); j++){
        intPair v = AdjList[u][j];
        if(dfs_num[v.first] == UNVISITED){
            dfs(v.first);
        } 
    }
}

/**
 * 637 Booklet Printing
 */
int main(int argc, char** argv){
    //n is number of nodes
    //m is number of edges
    int n,m;
    int u,v;

    cin>>n>>m;

    AdjList.resize(n+1);
    dfs_num.resize(n+1,-1);

   for(int i=0;i<m;i++)
   {
      
      cin>>u>>v;
      cout<<u<<" "<<v<<endl;

      
    /*Here u->v is the edge and pair second term can be used to store weight in
      case of weighted graph.
    */
      AdjList[u].push_back(make_pair(v,10));
   }
 
   //To print the edges stored in the adjacency list
   for(int i=1;i<=n;i++)
   {
       for(int j=0;j<(int)AdjList[i].size();j++)
       {
           cout<<"Edge is "<<i<<" -> "<<AdjList[i][j].first<<endl;
           cout<<"Weight is "<<AdjList[i][j].second<<endl;
       }
   }

   dfs(1);

    return 0;
}