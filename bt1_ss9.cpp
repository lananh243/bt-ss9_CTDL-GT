#include<stdio.h>
#include<stdlib.h> 
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

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void addEdgeDirectionless(Node* arr[], int i, int j){
	Node* newNode = createNode(j);
	newNode->next = arr[i];
	arr[i] = newNode;
	
	newNode = createNode(i);
	newNode->next = arr[j];
	arr[j] = newNode; 
}

//In ra
void printList(Node* arr[]){
	for(int i = 0; i<V; i++){
		printf("%d : \t",i);
		Node* temp = arr[i];
		while(temp != NULL){
			printf("%d -> \t", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}


int main() {
	int matrix[V][V] = {0}; 
	
	addEdge(matrix,0,1);
	addEdge(matrix,0,2);
	addEdge(matrix,1,2);
	addEdge(matrix,1,3);
	printf("Ma tran ke : \n");
	printMatrix(matrix);
	
	
	// tao 1 do thi co 4 dinh ko canh
	Node* adj[V];
	for(int i=0; i<V; i++){
		adj[i] = NULL;
	}
	//Them canh
	addEdgeDirectionless(adj,0,1);
	addEdgeDirectionless(adj,0,2);
	addEdgeDirectionless(adj,1,2);
	addEdgeDirectionless(adj,1,3);
	//in ra 
	printf("Danh sach ke : \n");
	printList(adj);
	
	return 0; 
}

