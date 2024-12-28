#include<stdio.h>
#define V 5
// Ham duyet theo chieu sau DFS

int visited[V];
int graph[V][V];
void DFS(int v, int n){
	printf("%d",v);
	visited[v] = 1;
	for(int i = 0; i < n; i++){
		if(visited[i] == 0 && graph[v][i] == 1){
			DFS(i, n);
		}
	}
} 
int main() {
	int n, u, v, start, edges;
	printf("Nhap vao so dinh : ");
	scanf("%d",&n);
	
	printf("Nhap vao so canh : ");
	scanf("%d",&edges);
	
	printf("Nhap cac canh (dinh v) : ");
	for(int i = 0; i < edges; i++){
		scanf("%d %d",&u, &v);
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	printf("Nhap vao dinh bat dau duyet : ");
	scanf("%d",&start);
	DFS(start, n);
	
	return 0;
}
