#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void addEdge(int matrix[MAX][MAX], int u, int v) {
    matrix[u][v] = 1; 
    matrix[v][u] = 1; 
}

void printMatrix(int matrix[MAX][MAX], int n) {
    printf("Ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int checkSymmetry(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Không d?i x?ng
            }
        }
    }
    return 1; 
}

int main() {
    int n, m;
    int matrix[MAX][MAX] = {0}; 

    printf("Nhap so luong dinh: ");
    scanf("%d", &n);

    printf("Nhap so luong canh: ");
    scanf("%d", &m);

    printf("Nhap danh sach cac canh :\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Canh %d: ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(matrix, u, v);
    }

    printMatrix(matrix, n);

    if (checkSymmetry(matrix, n)) {
        printf("Ma tran ke la doi xung.\n");
    } else {
        printf("Ma tran ke khong la doi xung.\n");
    }

    return 0;
}

