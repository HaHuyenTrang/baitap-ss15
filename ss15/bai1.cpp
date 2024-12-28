#include<stdio.h>
#define V 5 // Dinh da dinh san la 5, co the sua lai neu can

// Mang danh dau cac dinh da duoc tham
int visited[V];

// Ma tran ke cua do thi
int graph[V][V];

// Ham duyet theo chieu sau DFS
void DFS(int v, int n) {
    // In ra dinh dang duyet
    printf("%d", v);

    // Danh dau dinh v la da tham
    visited[v] = 1;

    // Duyet qua cac dinh ke voi v
    for (int i = 0; i < n; i++) {
        // Neu dinh chua tham va co canh ke noi tu v den i
        if (visited[i] == 0 && graph[v][i] == 1) {
            DFS(i, n); // Goi de quy de tham dinh ke
        }
    }
}

int main() {
    int n, u, v, start, edges;

    // Nhap vao so dinh cua do thi
    printf("Nhap vao so dinh : ");
    scanf("%d", &n);

    // Nhap vao so canh cua do thi
    printf("Nhap vao so canh : ");
    scanf("%d", &edges);

    // Nhap thong tin cac canh trong do thi
    printf("Nhap cac canh (dinh v) : ");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        // Danh dau canh trong ma tran ke (do thi vo huong)
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Nhap vao dinh bat dau duyet
    printf("Nhap vao dinh bat dau duyet : ");
    scanf("%d", &start);

    // Goi ham DFS de duyet do thi
    DFS(start, n);

    return 0; // Ket thuc chuong trinh
}

