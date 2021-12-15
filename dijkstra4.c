/*code by depiyo (biar kece)
NOTE : - INPUT MATRIKS MASIH STATIS
       - BELUM BISA PRINT NODE YANG DILEWATI
       - BELUM DISESUAIN DENGAN BRANCH MAIN*/

#include <stdio.h>
#include <stdbool.h>
#define INFINITE 9999
#define MAX 6

int graf[MAX][MAX];

int dijkstra(int start, int finish){
    int distance[MAX];
    bool visited[MAX];
    int j, i, v;

    //inisialisasi jaraknya infinite
    for(i=1;i<=MAX;i++){
        distance[i]=INFINITE;
    }

    //inisialisasi belum ada node yang divisit, visited=false
    for(i=1;i<=MAX;i++){
        visited[i]=false;
    }

    distance[start]=0; //tidak ada jarak pada saat memulai

    while(true){
        int u=-1;
        int minDistance=INFINITE;

        //mencari node dengan distance terkecil
        for(i=1;i<=MAX;i++){
            if((visited[i]==false)&&(distance[i]<minDistance)){
                u=i;
                minDistance=distance[i];//ganti nilai mindistance yang awalnya infinite
            }
        }

        //Break perualangan while
        if(u==-1||distance[u]==INFINITE){
            break;
        }

        visited[u]=true;
        //melakukan relaksasi
        for(v=1;v<=MAX;v++){
            if(graf[u][v]!=0){
                if(distance[v]>distance[u]+graf[u][v]){
                    distance[v]=distance[u]+graf[u][v];
                }
            }
        }
    }
    return distance[finish];
}

int main (){
    int start, finish, dist;
    int i, j;

    printf("Masuka matriks: \n");

    for(i=1;i<=MAX;i++){
        for(j=1;j<=MAX;j++){
            scanf("%d", &graf[i][j]);
        }
    }

    start = 1; //dari PT. Anugrah Frozen

    printf("Masukan tujuan : ");
    scanf("%d", &finish);

    dist = dijkstra(start, finish);

    printf("shotest path : %d meter", dist);
}
