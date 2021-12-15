// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 6

void Dijkstra(int Graph[MAX][MAX], int n, int start, int destinasi);

void Dijkstra(int Graph[MAX][MAX], int n, int start, int destinasi) {
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
    if (destinasi != start) 
    {
      printf("\nJarak Destinasi Pengiriman ke toko %d: %d meter", destinasi, distance[destinasi-1]);
    }
}

int main() 
{
  int node, start, destinasi;
  node = 6;

  int Graph[MAX][MAX] = 
  {
    {0 ,400, 250, 0, 0, 0},
    {400, 0, 150, 300, 0, 0},
    {250, 150, 0, 380, 600, 0},
    {0, 300, 380, 0, 200, 430},
    {0, 0, 600, 200, 0, 100},
    {0, 0, 0, 430, 100, 0}
  };

  start = 0;
  printf("Masukkan Destinasi Pengiriman: ");
  scanf("%d", &destinasi);
  sleep(1);
  printf(".");
  sleep(1);
  printf(".");
  sleep(1);
  printf(".\n");
  Dijkstra(Graph, node, start, destinasi);
  getch();
  return 0;
}