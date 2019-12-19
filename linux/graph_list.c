#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MVNum 100
#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int info;
} Acnd, *PAcnd;

typedef struct Vnode {
    char data;
    struct ArcNode *first_edge;
} Vnd, AdjList[MVNum]; 
typedef struct ALGraph{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph, *PALGraph;


int get_position(PALGraph g,char p){
    int i;
    for(i=0;i<g->vexnum;i++){
        if(g->vertices[i].data == p){
            return i;
        }
    }

    return -1;
}

int link_last(PAcnd list, PAcnd node){
    PAcnd p = list;
    while(p->nextarc)
        p = p->nextarc;
    p->nextarc = node;
}


int main(){
    char vexs[] = {'A', 'B', 'C','D', 'E', 'F', 'G'};
    char edge[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}
    };

    int vexnum = LENGTH(vexs);
    int arcnum = sizeof(edge);
    printf("%d\n", vexnum);
    printf("%d\n", arcnum);


    PALGraph grap; 
    grap = (ALGraph*)malloc(sizeof(ALGraph));
    memset(grap,0,sizeof(grap));
    grap->vexnum = vexnum;
    grap->arcnum = arcnum;
    for(int i= 0; i< vexnum; i++){
        grap->vertices[i].data = vexs[i];
        grap->vertices[i].first_edge = NULL;
    }

    char c1,c2;
    int p1,p2;
    PAcnd node1, node2;
    
    for(int i=0;i<vexnum; i++){
        c1 = edge[i][0];
        c2 = edge[i][1];

        printf("%c,%c\n", c1, c2);
        p1 = get_position(grap, c1);
        p2 = get_position(grap, c2);
        node1 = (PAcnd)malloc(sizeof(Acnd));
        node1->adjvex = p2;
        if(grap->vertices[p1].first_edge == NULL)
            grap->vertices[p1].first_edge = node1;
        else
            link_last(grap->vertices[p1].first_edge, node1);
        //printf("=============\n");
        //printf("---3333--- %d %d\n", p1, p2);

        node2 = (PAcnd)malloc(sizeof(Acnd));
        node2->adjvex = p1;
        if(grap->vertices[p2].first_edge == NULL)
            grap->vertices[p2].first_edge = node2;
        else
            link_last(grap->vertices[p2].first_edge, node2);
    }


    printf("000000--------0000000\n");
    PAcnd pnode;

    for(int i=0 ;i<grap->vexnum; i++){
        printf("%c\n", grap->vertices[i].data);
        pnode  = grap->vertices[i].first_edge;
        while (pnode != NULL){
            printf("----%d  %c\n", pnode->adjvex, grap->vertices[pnode->adjvex].data);
            pnode = pnode->nextarc;
        }
    }

    return 0;
}
