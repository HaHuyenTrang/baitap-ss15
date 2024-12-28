#include<stdio.h>
#define V 5 // Dinh co so luong toi da la 5 (co the thay doi tuy theo yeu cau)

// Mang danh dau cac dinh da duoc tham
int visited[V];

// Ma tran ke cua do thi
int graph[V][V];

// Ham duyet theo chieu sau DFS
void DFS(int v, int n) {
    // In ra dinh hien tai dang duyet
    printf("%d ", v);

    // Danh dau dinh hien tai la da tham
    visited[v] = 1;

    // Duyet tat ca cac dinh ke voi dinh hien tai
    for (int i = 0; i < n; i++) {
        // Neu dinh chua duoc tham va co canh noi tu v den i
        if (visited[i] == 0 && graph[v][i] == 1) {
            DFS(i, n); // Goi ham de quy de tiep tuc duyet
        }
    }
}

int main() {
    int n, u, v, start, edges;

    // Nhap vao so dinh cua do thi
    printf("Nhap vao so dinh: ");
    scanf("%d", &n);

    // Nhap vao so canh cua do thi
    printf("Nhap vao so canh: ");
    scanf("%d", &edges);

    // Khoi tao ma tran ke voi cac gia tri ban dau bang 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Nhap cac canh cua do thi
    printf("Nhap cac canh (dinh u, v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        // Cap nhat ma tran ke (do thi vo huong)
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Nhap dinh bat dau duyet DFS
    printf("Nhap vao dinh bat dau duyet: ");
    scanf("%d", &start);

    // Khoi tao mang visited (tat ca dinh chua duoc tham)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Goi ham DFS de bat dau duyet tu dinh start
    printf("Thu tu cac dinh duoc duyet: ");
    DFS(start, n);

    return 0; // Ket thuc chuong trinh
}

