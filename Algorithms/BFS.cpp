/**
 * One of the problems with using C++ for a graph algorithm is that, when dealing with adjacency martices, 
 * we usually want to send in a 2-D array. We can either: send an array with fixed dimensions 
 * (or with fixed column number , but either way the space is wasted), or we can send in a "pointer to pointer", 
 * like I do below. However, if we send a pointer to pointer, then the whole allocation of the array will be scattered all over the heap.
 * This will posiibly lead to slower code, offsetting the advantages of using an adjacency matrix.
 * 
 * Therefore I wrote 2 implementations of the graph.
 * 
 * */

#include <iostream> 
#include <queue>
using namespace std;

int main(){


    return 0;
}

void BFS_M(int n, bool ** a, int s){

    /**
     * Initialization: visited? distance? precessor?
     * */
    int visited[n]; // 0 - not visited; 1 - visited; 2 - visited, also visited all neighbors.
    int dist[n];
    int pre[n];
    for(int i = 0; i < n; i++){
        visited[n] = 0;
        dist[n] = INT_MAX;
        pre[i] = -1;
    }

    visited[s] = 1;
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && a[u][i]){
                visited[i] = 1;
                dist[i] = dist[u]+1;
                pre[i] = u;
                Q.push(i);
            }
            visited[u] = 2;
        }
    }

}

struct Node
{
    int k = -1;
    Node * next = NULL;
};


void BFS_L(int n, Node * E, int s){

    /**
     * Initialization: visited? distance? precessor?
     * */
    int visited[n]; // 0 - not visited; 1 - visited; 2 - visited, also visited all neighbors.
    int dist[n];
    int pre[n];
    for(int i = 0; i < n; i++){
        visited[n] = 0;
        dist[n] = INT_MAX;
        pre[i] = -1;
    }

    visited[s] = 1;
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);
    

    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        Node * head = &E[u];
        head = head->next;
        while (head){
            if(visited[head->k] == 0){
                    visited[head->k] = 1;
                    dist[head->k] = dist[u]+1;
                    pre[head->k] = u;
                    Q.push(head->k);
                }
                visited[u] = 2;
        }
    }
}