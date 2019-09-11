//Luis Madera
//lmadera1
#include <stdio.h>

int main(void) {
  char ch;
  float answer;
  printf("Please enter an arithmetic expression using * and / only: \n");
  scanf("%f",&answer);
  while(scanf("%c",&ch) == 1){
    if (ch == '/'){
      float next_num;
      scanf("%f",&next_num);
      answer  = answer / next_num;
    }
    if (ch == '*'){
      float next_num;
      scanf("%f",&next_num);
      answer = answer * next_num;
    }
  }
  printf("\n%f\n",answer);
  
  return 0;
  
}
