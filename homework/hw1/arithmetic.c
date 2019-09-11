//Luis Madera
//lmadera1
#include <stdio.h>

int main(void) {
  char ch;
  float answer;
  printf("Please enter an arithmetic expression using * and / only: \n");
  scanf(" %f",&answer);
  while(scanf(" %c",&ch) == 1){
    if (ch == '/'){
      float next_num;
      scanf(" %f",&next_num);
      if (next_num == 0) {
	printf("\ndivision by zero\n");
	return 2;
      }
      answer  = answer / next_num;
    } else if (ch == '*') {
      float next_num;
      scanf(" %f",&next_num);
      answer = answer * next_num;
    } else {
      printf("\nmalformed expression\n");
      return 1;
    }
  }
  printf("\n%f\n",answer);
  
  return 0;
  
}
