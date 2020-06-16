// C program for Dijkstra's single  
// source shortest path algorithm. 
// The program is for adjacency matrix 
// representation of the graph. 
#include <stdio.h> 
#include <limits.h> 

// Number of vertices  
// in the graph 
#define V 9 

// A utility function to find the  
// vertex with minimum distance 
// value, from the set of vertices 
// not yet included in shortest 
// path tree 

/*
현재 노드에서 갈 수 있는 가장 작은 가중치를 가진 노드의 인덱스를 반환하는 함수
*/

int minDistance(int dist[], int sptSet[]) {
    // Initialize min value 
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 &&
            dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest 
// path from source to j 
// using parent array 
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    /*
    재귀로 다 들어가고 마지막에 더이상 들어갈 게 없을 때 -1을 리턴해서 나오고
    출력하기 시작하므로 parent 배열에 저장된 경로의 역순으로 출력한다.
    */
    printf("%d ", j);
}


// A utility function to print  
// the constructed distance 
// array 
int printSolution(int dist[], int n, int parent[]) {
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < n; i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ",
            src, i, dist[i], src);
        printPath(parent, i);
    }
}


// dist는 최단 경로를 저장할 배열
// sptSet은 해당 경로를 갔는지에 대한 체크용 배열
// parent 는 움직인 노드의 경로를 저장하는 배열

void dijkstra(int graph[V][V], int src) {
    //재료 초기화
    
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++){
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    
    
    //
    //노드 0~8까지 움직이면서 해당 노드에서 갈 수 있는 제일 가까운 노드의 거리를 추가한다.

    for (int count = 0; count < V - 1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;  // 지나온 경로
                dist[v] = dist[u] + graph[u][v];
            }
    }
    /*
    현재 저장된 거리 가중치 값에 새로운 최소 거리값을 더했을 때 기존에 저장되었던 최솟값보다 작으면
    새로운 값으로 최단 거리를 업데이트 한다.
    */



    // 그래프 출력문
    printSolution(dist, V, parent);
}


// Driver Code 
int main()
{
    //  Let us create the example 
    // graph discussed above 
    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 0, 10, 0, 2, 0, 0},
                        {0, 0, 0, 14, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
