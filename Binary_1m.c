#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//b=bottom t=top m=middle
int Binary(int, int, int, int[]);

int main(void) {
  int array[1000000];
  int b, t, m, x, y, n;
  long cpu_time;
  n = 0;
  for (int i = 0; i < 1000000; i++) {
    n = rand() % 10 + 1 + n;
    // printf("%d", n);
    array[i] = n;
  }
  b = 0;
  t = (sizeof array / sizeof array[0]) - 1;
  printf("調べたい数は？：");
  scanf ("%d",&x);
  y = Binary(b,t,x,array);
  if(y == -1){
    printf("Not Found\n");
  }
  else {
    printf("%d番目にあります\n", y + 1);
  }

  cpu_time = clock();
  printf("CPU時間： %ld\n", cpu_time);

  return 0;
}


int  Binary(int b, int t, int x ,int array[]) {
  int m;

  while(b <= t){
    m = (b + t) / 2;
    if(x < array[m]){
      t = m - 1;
    }
    else if(x > array[m]){
      b = m + 1;
    }
    else if(x == array[m]){
      return m;
    }
  }
  return -1;
}
