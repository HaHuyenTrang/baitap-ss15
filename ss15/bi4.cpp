#include<stdio.h>
#define V 5 // So dinh toi da cua do thi la 5 (co the thay doi tuy bai toan)

// Ma tran ke bieu dien do thi
int graph[V][V];

// Mang danh dau cac dinh da tham
int visited[V];

// Mang danh dau cac dinh dang trong ngan xep de quy
int recStack[V];

// Ham kiem tra chu trinh bang DFS
int hasCycleDFS(int v, int n) {
    // Danh dau dinh hien tai la da tham va dua vao ngan xep de quy
    visited[v] = 1;
    recStack[v] = 1;

    // Duyet tat ca cac dinh ke voi dinh hien tai
    for (int i = 0; i < n; i++) {
        // Neu co canh tu v den i
        if (graph[v][i] == 1) {
            // Neu dinh i chua duoc tham, goi de quy cho dinh i
            if (!visited[i] && hasCycleDFS(i, n)) {
                return 1; // Phat hien chu trinh
            }
            // Neu dinh i da nam trong ngan xep de quy, co chu trinh
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    // Xoa dinh hien tai khoi ngan xep de quy sau khi duyet xong
    recStack[v] = 0;
    return 0; // Khong phat hien chu trinh
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

    // Khoi tao mang visited va recStack (tat ca bang 0)
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Nhap cac canh cua do thi
    printf("Nhap cac canh (dinh u, v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);

        // Cap nhat ma tran ke (do thi co huong)
        graph[u][v] = 1;
    }

    // Kiem tra chu trinh
    int hasCycle = 0;
    for (int i = 0; i < n; i++) {
        // Goi ham DFS cho cac dinh chua duoc tham
        if (!visited[i]) {
            if (hasCycleDFS(i, n)) {
                hasCycle = 1; // Phat hien chu trinh
                break;
            }
        }
    }

    // In ket qua
    if (hasCycle) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0; // Ket thuc chuong trinh
}

