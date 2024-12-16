#include<stdio.h>
#define MAX 100
//Khai bao danh sach ke
int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1;
int rear = -1;

//Ham them vao hang doi
void enqueue(int value){
	if(rear == MAX - 1){
		return;
	}
	if(front == -1){
		front = 0;
	}
	queue[++rear] = value;
}

//Lay phan tu khoi hnag doi
int dequeue(){
	if(front == -1 || front > rear){
		return -1;
	}
	return queue[front++];
}

//Thuan toan tim kiem theo chieu rong
void BFSFunction(int start, int n){
	for(int i = 0; i<n;i++){
		visited[i] = 0;
	}
	enqueue(start);
	visited[start] = 1;
	while(front <= rear){
		int current = dequeue();
		printf("%d", current);
		for(int i = 0; i<n; i++){
			if(graph[current][i] == 1 && !visited[i]){
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
}


int main() {
	int n,m;
	printf("Nhap so luong dinh : ");
	scanf("%d",&n);
	printf("Nhap so luong canh : ");
	scanf("%d",&m);
	 
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0; 
        }
    }
    
    printf("Nhap danh sach cac dinh : \n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; 
        graph[v][u] = 1; 
    }
    
    int start;
    printf("Nhap dinh bat dau de thuc hien duyet BFS: ");
    scanf("%d", &start);
	BFSFunction(start, n);
	
	return 0;
}

