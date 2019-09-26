//Luis Madera
//lmadera1
#include <stdio.h>

int main(void) {
  char ch;
  float answer;
  printf("Please enter an arithmetic expression using * and / only: \n");
  if (scanf(" %f",&answer) != 1){
    printf("malformed expression\n");
    return 1;
  }
  int count = 1;
  while(scanf(" %c",&ch) == 1){
    count++;
    if ((ch == '/') && (count % 2 == 0)){
      float next_num;
      if(scanf(" %f",&next_num)!= 1){
	printf("malformed expression\n");
	return 1;
      }
      count++;
      if (next_num == 0){
	printf("division by zero\n");
	return 2;
      }
      answer  = answer / next_num;
    } else if ((ch == '*') && (count % 2 == 0)){
      float next_num;
      if(scanf(" %f",&next_num) != 1){
	printf("malformed expression\n");
	return 1;
      }
      count++;
      answer = answer * next_num;
    } else {
      printf("malformed expression\n");
      return 1;
    }
  }
  printf("%f\n",answer);
  
  return 0;
  
}
