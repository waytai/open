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
    return 0;
}

