// word_search.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//Luis Madera
//lmadera1


#include <stdio.h>
#include "search_functions.h"
#include <ctype.h>

/*
 * This is the HW3 main function that performs a word search.
 */
int main(int argc, char* argv[]) {

  //check if enough arguments are made
  //if (argc < 2){
  //printf("Please enter a command line argument\n");
  //return 1;
  //}
  
  
  char grid[MAX_SIZE][MAX_SIZE];
  //int grid_dim = populate_grid(grid,argv[1]);

  int grid_dim = populate_grid(grid,"grid.txt");

  //check if grid_file is readable
  if(grid_dim == -1){
    printf("Grid file failed to open\n");
    return -1;
  }

  //check if the grid is invalid
  if(grid_dim == -2){
    printf("Invalid grid\n");
    return -2;
  }
  
  //collect words from the user

  char chr;
  int i;
  char word[i];
  while(scanf("%c",&chr) == 1){
    if (chr == ' '){
      int word_length = i;
      i = 0;
      scanf("%c",&chr);
      printf("\n");
      find_all(grid,grid_dim,word_length,word,stdout);
    }
    word[i] = chr;
      
    //make all letters lowercase
    word[i] = tolower(word[i]);
      
    i++;
  }
  int word_length = i;
  printf("\n");
  find_all(grid,grid_dim,word_length,word,stdout);
  return 0;

}

