#include<stdio.h>
#define V 4
void addEdge(int matrix[V][V], int i, int j){
	matrix[i][j] = 1;
	matrix[j][i] = 1;
	
} 

void printMatrix(int matrix[V][V]){
	for(int i = 0; i<V ; i++){
		for(int j = 0; j < V; j++ ){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

int isCyclicUtil(int v, int visited[], int parent, int matrix[V][V]) {
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (matrix[v][i]) { 
            if (!visited[i]) { 
                if (isCyclicUtil(i, visited, v, matrix)) {
                    return 1;
                }
            } else if (i != parent) {
                return 1; 
            }
        }
    }
    return 0; 
}

int isCyclic(int matrix[V][V]) {
    int visited[V] = {0}; 

    for (int i = 0; i < V; i++) {
        if (!visited[i]) { 
            if (isCyclicUtil(i, visited, -1, matrix)) {
                return 1; 
            }
        }
    }
    return 0; 
}

int main(){
	int matrix[V][V] = {0}; 
	addEdge(matrix,0,1);
	addEdge(matrix,1,2);
	addEdge(matrix,2,3);
	addEdge(matrix,3,0);
	printMatrix(matrix);
	
	 if (isCyclic(matrix)) {
        printf("Do thi co chu ki\n");
    } else {
        printf("Do thi khong co chu ki\n");
    }

	return 0;
}
