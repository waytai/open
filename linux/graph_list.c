#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define VNODENUM  100

typedef struct arcnode{
    int vernum;
    struct arcnode *next_arc;
} ArcNode, *PArcNode;

typedef struct vnode{
    char data;
    struct arcnode *first_arc;
} Vnode, *PVnode;

typedef struct graph{
    int vernum, arcnum;
    struct vnode vnode_list[VNODENUM];
} Graph, *PGraph;


int get_position(PGraph pg, char c){
    for(int i =0; i< pg->vernum; i++){
        if(pg->vnode_list[i].data == c){
            return i;
        }
    }
    return -1;
}


void link_to_last(PArcNode list, PArcNode pnode){
   PArcNode p = list;
   while(p->next_arc) {
       p= p->next_arc;
   }
   p->next_arc = pnode;
}


void print_graph(PGraph pgraph){
     for(int i = 0; i<pgraph->vernum; i++){
        printf("%c ", pgraph->vnode_list[i].data);
        PArcNode p_arc;
        p_arc = pgraph->vnode_list[i].first_arc;
        while(p_arc != NULL){
            printf("%d %c  ", p_arc->vernum, pgraph->vnode_list[p_arc->vernum].data);
            p_arc = p_arc->next_arc;
        }
        printf("\n");
    }
}

void DFS(PGraph G, int i, int *visited)
{
    PArcNode node;

    visited[i] = 1;
    printf("%c ", G->vnode_list[i].data);
    node = G->vnode_list[i].first_arc;
    while (node != NULL)
    {
        if (!visited[node->vernum])
            DFS(G, node->vernum, visited);
        node = node->next_arc;
    }
}

void BFS(PGraph G){
    int head = 0;
    int rear = 0;
    int queue[VNODENUM];
    int visited[VNODENUM];
    int i,j,k;
    PArcNode parcnode;

    for(i=0; i<G->vernum; i++){
        visited[i] = 0;
    }

    printf("BFS:");
    for(i=0; i<G->vernum;i++){
        if(!visited[i]){
            visited[i] = 1;
            printf(" ---- %c 9 ", G->vnode_list[i].data);
            queue[rear++] = i;
        }
        while(head != rear){
            j = queue[head++];
            parcnode = G->vnode_list[j].first_arc;
            while(parcnode != NULL){
                k = parcnode->vernum;
                if(!visited[k]){
                    visited[k] = 1;
                    printf("%c ", G->vnode_list[k].data);
                    queue[rear++] = k;
                }
                parcnode = parcnode->next_arc;
            }
        }
    }

    printf("\n");
}

/*
 * 深度优先搜索遍历图
 */
void DFSTraverse(PGraph G)
{
    int i;
    int visited[VNODENUM];       // 顶点访问标记

    // 初始化所有顶点都没有被访问
    for (i = 0; i < G->vernum; i++)
        visited[i] = 0;

    printf("DFS: ");
    for (i = 0; i < G->vernum; i++)
    {
        if (!visited[i])
            DFS(G, i, visited);
    }
    printf("\n");
}




int main(){
    char A[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edge[][2] ={
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'G', 'F'}
    };

    PGraph pgraph;
    pgraph = (PGraph)malloc(sizeof(Graph));
    memset(pgraph, 0, sizeof(Graph));
    pgraph->vernum = sizeof(A)/sizeof(A[0]);
    pgraph->arcnum = sizeof(edge)/sizeof(edge[0]);
    printf("%d    %d\n", pgraph->vernum, pgraph->arcnum);

    for(int i=0; i< pgraph->vernum; i++){
        pgraph->vnode_list[i].data = A[i];
        pgraph->vnode_list[i].first_arc = NULL;
    }

    int p1, p2;
    char c1, c2;
    printf("-----%d\n", pgraph->arcnum);
    for(int i=0; i< pgraph->arcnum; i++){
        c1 = edge[i][0];
        c2 = edge[i][1];
        printf("%c  %c\n",c1, c2);
        p1 = get_position(pgraph, c1);
        p2 = get_position(pgraph, c2);
        printf("%d   %d\n", p1, p2);


        PArcNode arc_egde1, arc_egde2;
        arc_egde1 = (PArcNode)malloc(sizeof(ArcNode));
        arc_egde1->vernum = p2;

        if(pgraph->vnode_list[p1].first_arc == NULL)
        {
            pgraph->vnode_list[p1].first_arc = arc_egde1;
        }
        else
        {
            link_to_last(pgraph->vnode_list[p1].first_arc, arc_egde1);
        }

        arc_egde2 = (PArcNode)malloc(sizeof(ArcNode));
        arc_egde2->vernum = p1;
        if(pgraph->vnode_list[p2].first_arc == NULL)
            pgraph->vnode_list[p2].first_arc = arc_egde2;
        else
            link_to_last(pgraph->vnode_list[p2].first_arc, arc_egde2);
    }

    printf("the node is\n");
    for(int i=0;i<pgraph->vernum; i++){
        printf("%c ", pgraph->vnode_list[i].data);
    }
    printf("\n");

    print_graph(pgraph);

    printf("=========\n");
    //DFSTraverse(pgraph);
    BFS(pgraph);

    return 0;
}

