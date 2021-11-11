#include<iostream>
#include<queue>
#define NODE 10
using namespace std;
int komvoi;
typedef struct node{
   int val;
   int state; //status
}node;

// MEGETHOS 5 KOMVWN
int graph5[NODE][NODE] = {
   {0, 1, 0, 1, 1},
   {1, 0, 1, 0, 0},
   {0, 1, 0, 1, 0},
   {1, 0, 1, 0, 1},
   {1, 0, 0, 1, 0}
};

// MEGETHOS 10 KOMVWN
int graph10[NODE][NODE] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{0, 1, 0, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
};
//*/
void bfs(node *vert, node s){
	node u;
	int i, j;
	queue<node> que;
	for(i = 0; i<NODE; i++){
	  vert[i].state = 0; //not visited
	}
	vert[s.val].state = 1;//visited
	que.push(s); //insert starting node
	while(!que.empty()){
	  u = que.front(); //delete from queue and print
	  que.pop();
	  cout << char(u.val+'A') << " ";
	if(komvoi == 5)
	{
	  for(i = 0; i<NODE; i++){
	     if(graph5[i][u.val]){
	        //when the node is non-visited
	        if(vert[i].state == 0){
	           vert[i].state = 1;
	           que.push(vert[i]);
	        }
	     }
	  }
	  u.state = 2;//completed for node u
	}
	else if(komvoi == 10)
	{
		for(i = 0; i<NODE; i++){
	     if(graph10[i][u.val]){
	        //when the node is non-visited
	        if(vert[i].state == 0){
	           vert[i].state = 1;
	           que.push(vert[i]);
	        }
	     }
	  }
	  u.state = 2;//completed for node u
	  }
   }
}
int main(){
	
	int choice;
	printf("Epiloges :\n");
	printf("1 --> Paragwgi Komvwn Sthn Tyxh\n");
	printf("2 --> Fortwsi Etoimou Pinaka Geitniasis\n");
	printf("Epilogi : ");
	scanf("%d", &choice);
	
	if(choice == 2)
	{
	printf("\nEpilexte Plythos Komvwn (5)(10): ");
	scanf("%d", &komvoi);
	if(komvoi ==5)
	{
	printf("\n"
	"    A  B  C  D  E \n"
	"A  {0, 1, 0, 1, 1}\n"
	"B  {1, 0, 1, 0, 0}\n"
	"C  {0, 1, 0, 1, 0}\n"
	"D  {1, 0, 1, 0, 1}\n"
	"E  {1, 0, 0, 1, 0}\n\n");
	}
	else if(komvoi == 10)
	{
	printf("\n"
	"    A  B  C  D  E  F  G  H  I  J\n"
	"A  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}\n"
	"B  {0, 0, 1, 1, 0, 0, 0, 1, 0, 1}\n"
	"C  {0, 1, 0, 0, 1, 0, 0, 0, 1, 0}\n"
	"D  {0, 1, 0, 0, 1, 1, 0, 0, 0, 0}\n"
	"E  {0, 0, 1, 1, 0, 0, 0, 0, 0, 0}\n"
	"F  {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}\n"
	"G  {0, 0, 0, 0, 0, 1, 0, 1, 0, 0}\n"
	"H  {0, 1, 0, 0, 0, 0, 1, 0, 0, 0}\n"
	"I  {1, 0, 1, 0, 0, 0, 0, 0, 0, 1}\n"
	"J  {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}\n\n");
	}
    node vertices[NODE];
    node start;
	
    char s;
    for(int i = 0; i<NODE; i++){
      vertices[i].val = i;
    }
    s = 'B';//starting vertex B
    start.val = s-'A';
    cout << "BFS Traversal: ";
    bfs(vertices, start);
    cout << endl;
	}
	else{}
}
