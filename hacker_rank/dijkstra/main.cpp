#include <bits/stdc++.h>

using namespace std;
typedef struct edge
{
    int u;
    int v;
    int w;
}edge;

template <class T>
class HEAP
{
  private:
    typedef struct node{
      T val;
      int key;
    }node;
    node *X=NULL;
    int *positionHolder;
    int heapSize;
    int maxSize;
    void swap(int i,int j)
    {
      node temp=X[i];
      X[i]=X[j];
      X[j]=temp;
    }
    void swappos(int i,int j)
    {
      int t=positionHolder[i];
      positionHolder[i]=positionHolder[j];
      positionHolder[j]=t;
    }

  public:
    HEAP()
    {
      maxSize=1;
      heapSize=0;
      X =(node*)malloc(sizeof(node));
      positionHolder=(int*)malloc(sizeof(int));
    }

    int Insert(T value,int key){
        heapSize++;
        if(heapSize>maxSize)
        {
          X=(node*)realloc(X,heapSize*sizeof(node));
          positionHolder=(int*)realloc(positionHolder,heapSize*sizeof(int));
          maxSize=heapSize;
        }
        int position = heapSize-1;
        X[position].val=value;
        X[position].key=key;
        positionHolder[value]=position;
        while(position>0&&X[position].key<X[(position-1)/2].key)
        {

          swap(position,(position-1)/2);
          swappos(position,(position-1)/2);
          position=(position-1)/2;
        }
    }


    T DeleteMin(int *keyReturn=NULL){
      if(heapSize==0)
      {
        return-1;
      }
      node t=X[0];
      X[0]=X[heapSize-1];
      heapSize--;
      int i=0,min;
      while(2*i+2<=heapSize)
      {
        min=i;
        if(X[2*i+1].key<X[min].key){
          min=2*i+1;
        }
        if(X[2*i+2].key<X[min].key){
          min=2*i+2;
        }
        if(min==i)
        {
          break;
        }
        else
        {
          swap(i,min);
          swappos(i,min);
          i=min;
        }
      }
      if(keyReturn!=NULL)
      {
        *keyReturn=t.key;
      }
      return t.val;
    }


    int decreaskey(T n_val,int new_key){
      int position;
      position=positionHolder[n_val];
      if(position==-1)return -1;
      if(new_key>=X[position].key)
      {
        return -1;
      }
      else
      {
        X[position].key=new_key;
        while(position>0&&X[position].key<X[(position-1)/2].key)
        {
          swap(position,(position-1)/2);
          swappos(position,(position-1)/2);
          position=(position-1)/2;
        }
      }
      return 0;
    }
    int SizeH(){
      return heapSize;
    }
    int maxSizeH(){
      return maxSize;
    }
    T LookMinVal(){
      return X[0].val;
    }
    int LookMinKey(){
      return X[0].key;
    }
    ~HEAP(){
      free(X);
    }

};

typedef struct GRAPH
{
    int n;
    int m;
    vector<vector<int> >AL(n);
    vector<vector<int> >AL_dist(n);
}GRAPH;

vector<int> Dijkstra(int s,GRAPH G)
{
    vect<int> distA(n);
    int visited[n];
    priority_queue<int>distQ;
    int i;
    HEAP<int> H;
    for(i=0; i<n; i++)
    {
        distA[i]=INT_MAX;
        H.Insert(i,dist[i]);
    }
    dist[s]=0;
    visited[s]=1
    H.decreaseKey(s,0);
    int node;
    int alt;
    int v;
    int v_cur_dist;
    while(H.SizeH()!=0)
    {
        node=H.DeleteMin();
        visited[node]=1;

    }
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int m;
        cin >> n >> m;
        //vector<edge>eT(m);
        //vector<vector<int>>AL(n);
        //vector<vector<int>>AL_dist(n);
        GRAPH G;
        G.n=n;
        G.m=m;
        for(int a1 = 0; a1 < m; a1++)
        {
            int u,v,w;
            cin >> u >> v >> w;
            G.AL[u].push_back(v);
            G.AL[u].push_back(w);
            G.AL[v].push_back(u);
            G.AL[v].push_back(w);

        }
        int s;
        cin >> s;
        vector<int> distFinal;
        distFinal=Dijkstra(s,G);
    }
    return 0;
}
