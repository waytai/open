#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>


#define MAX 100
typedef struct _graph{
    char verx[MAX];
    int vernum, arcnum;
    int matrix[MAX][MAX];
} Graph, *PGraph;


int get_position(PGraph pgrap,char eg){
    for(int i= 0; i<pgrap->vernum; i++){
        if(pgrap->verx[i] == eg){
            return i;
        }
    }
    return -1;
}

int main(){
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int edges[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}
    };
    int len_versnum = sizeof(vexs)/sizeof(vexs[0]);
    int len_edges = sizeof(edges)/sizeof(edges[0]);
    printf("%d\n", len_versnum);
    printf("%d\n", len_edges);

    PGraph grap;
    grap = (PGraph)malloc(sizeof(Graph));
    memset(grap, 0, sizeof(Graph));
    grap->vernum = len_versnum;
    grap->arcnum = len_edges;
    for(int i=0; i<len_versnum; i++){
        grap->verx[i] = vexs[i];
    }

    int p1, p2;
    for(int i=0;i<len_edges; i++){
        p1 = get_position(grap, edges[i][0]);
        p2= get_position(grap, edges[i][1]);
        printf("%d    %d\n", p1, p2);
        grap->matrix[p1][p2] = 1;
        grap->matrix[p2][p1] = 1;
    }

    for(int i=0; i<len_versnum; i++){
        printf("%c  ", grap->verx[i]);
    }
    printf("\n");

    printf("--------------\n");
    for(int i=0; i<len_versnum; i++){
        for(int j=0;j<len_versnum;j++){
            printf("%d ", grap->matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
