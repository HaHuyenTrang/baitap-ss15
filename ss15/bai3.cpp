#include<stdio.h>
#define V 5 // Dinh toi da cua do thi la 5 (co the thay doi tuy theo bai toan)

// Mang danh dau cac dinh da tham
int visited[V];

// Ma tran ke bieu dien do thi
int graph[V][V];

// Ham duyet theo chieu sau DFS
void DFS(int v, int n) {
    // Danh dau dinh hien tai da tham va in ra
    visited[v] = 1;
    printf("%d ", v);

    // Duyet tat ca cac dinh ke voi dinh hien tai
    for (int i = 0; i < n; i++) {
        // Neu dinh chua duoc tham va co canh noi giua v va i
        if (visited[i] == 0 && graph[v][i] == 1) {
            DFS(i, n); // Goi ham de quy de tiep tuc duyet
        }
    }
}

int main() {
    int n, u, v, edges;

    // Nhap vao so dinh cua do thi
    printf("Nhap vao so dinh: ");
    scanf("%d", &n);

    // Nhap vao so canh cua do thi
    printf("Nhap vao so canh: ");
    scanf("%d", &edges);

    // Khoi tao ma tran ke (tat ca gia tri ban dau la 0)
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

    // Khoi tao mang visited (tat ca dinh chua duoc tham)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Goi ham DFS bat dau tu dinh 0
    printf("Duyet cac dinh (DFS bat dau tu dinh 0): ");
    DFS(0, n);
    printf("\n");

    // Kiem tra tinh lien thong
    int isConnected = 1; // Gia su do thi lien thong
    for (int i = 0; i < n; i++) {
        // Neu co dinh chua duoc tham thi do thi khong lien thong
        if (visited[i] == 0) {
            isConnected = 0;
            break;
        }
    }

    // In ket qua
    if (isConnected) {
        printf("Do thi lien thong\n");
    } else {
        printf("Do thi khong lien thong\n");
    }

    return 0; // Ket thuc chuong trinh
}

