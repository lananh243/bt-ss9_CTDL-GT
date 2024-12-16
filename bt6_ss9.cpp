#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void addEdge(int matrix[MAX][MAX], int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1; 
}

void calculateDegrees(int matrix[MAX][MAX], int n) {
    int degree[MAX] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    int maxDegree = 0;
    int maxVertex = -1;
    for (int i = 0; i < n; i++) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
            maxVertex = i;
        }
    }

    printf("Dinh co bac cao nhat la: %d\n", maxVertex);
}

int main() {
    int n,m;
    int matrix[MAX][MAX] = {0}; 

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);
    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    printf("Nhap danh sach cac canh (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(matrix, u, v); 
    }

	calculateDegrees(matrix, n);

    return 0;
}
