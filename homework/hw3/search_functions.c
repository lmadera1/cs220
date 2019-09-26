// search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//Luis Madera
//lmadera1


#include <stdio.h>
#include "search_functions.h"



/* 
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the actual grid dimension. 
 * If filename_to_read_from can't be opened, this function returns -1.
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(char grid[][MAX_SIZE], char filename_to_read_from[]){

  FILE* grid_file = fopen(filename_to_read_from,"r");

  //check if grid_file is readable
  if(grid_file == NULL){
    return -1;
  }

  //populate the grid
  char next_char;
  int rows;
  int i;
  int i_max;
  for(rows = 0; fscanf(grid_file,"%c",&next_char) == 1; rows++){
    if(next_char == '\n')
      break;
    grid[rows][0] = next_char;
    for(i = 1; fscanf(grid_file,"%c",&next_char) == 1; i++){

      if(next_char == '\n')
	break;
      
      grid[rows][i] = next_char;
      
      //make lower case
      grid[rows][i] = tolower(grid[rows][i]);
      
    }
      //make sure all rows are the same size
    if(rows == 0)
      i_max = i;
    if((rows > 0) && (i != i_max))
      return -2;
  }
  
  //check for other invalid grids    
  if((i != rows) || (rows > MAX_SIZE) || (rows == 0)) 
    return -2;
  
  return rows;

}


/* 
 * Given a word, the grid file, the grid dimension, and the word length, this 
 * function determines if the word is within the grid file when read from left
 * to right. The function prints the occurance to a file and returns the 
 * number of times the word was found.  
 */
int find_right(char grid[][MAX_SIZE], int n, int word_len, char word[],
	       FILE *write_to){
  
  int num_similar = 0;
  int answers = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(grid[i][j] == word[num_similar]){
        num_similar++;
      }else{
        num_similar = 0;
      }
      if(num_similar == word_len){
        fprintf(write_to,"%s %d %d R\n",word,i,j-word_len+1);
	answers++;
      }
	
    }
  }
  return answers;

}


/* 
 * Given a word, a grid file, the grid file dimension, and the length of the
 * word, this function finds where the word appears reading right to left. The
 * function prints the location of the word to a file and returns the number 
 * of times the word appeared. 
 */
int find_left (char grid[][MAX_SIZE], int n, int word_len, char word[],
	       FILE *write_to){
  int num_similar = 0;
  int answers = 0;
  
  //reverse order of word
  char temp[word_len];
  int k;
  for(k = 0; k < word_len/2; k++){
    temp[k] = word[word_len-k-1];
    temp[word_len-k-1] = word[k];
  }
  temp[k] = word[k];

  //find the word in the grid
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(grid[i][j] == temp[num_similar]){
	num_similar++;
      }else{
	num_similar = 0;
      }
      if(num_similar == word_len){
	fprintf(write_to,"%s %d %d L\n",word,i,j);
	answers++;
      }
    }
  }
  return answers;

}


/* 
 * Given a word, a grid file, the dimention of the grid, and the word lenght,
 * this function finds the word within the grid file while reading from the 
 * top down. The function prints the locations of the word to a file and 
 * returns the number of times the word appeared. 
 */
int find_down(char grid[][MAX_SIZE],int n,int word_len,char word[],
	      FILE *write_to){

  int num_similar = 0;
  int answers = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(grid[j][i] == word[num_similar]){
	num_similar++;
      }else{
	num_similar = 0;
      }
      if(num_similar == word_len){
	fprintf(write_to,"%s %d %d D\n",word,j-word_len+1,i);
	answers++;
      }
    }
  }
  
  return answers;
}


/* 
 * Given a word, a grid file, the dimension of the grid, and the word length
 * this function will print to a file the locations where the word appears in
 * the grid file when read from the bottom up. The function returns the number
 * of times the word appeared.
 */
int find_up   (char grid[][MAX_SIZE], int n, int word_len, char word[],
	       FILE *write_to){

  int num_similar = 0;
  int answers = 0;

  //revers order of word
  char temp[word_len];
  int k;
  for(k = 0; k < word_len/2; k++){
    temp[k] = word[word_len-k-1];
    temp[word_len-k-1] = word[k];
  }
  temp[k] = word[k];

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= n; j++){
      if(grid[j][i] == temp[num_similar]){
	num_similar++;
      }else{
	num_similar = 0;
      }
      if(num_similar == word_len){
	fprintf(write_to,"%s %d %d U\n",word,j,i);
	answers++;
      }
    }
  }
  
  return answers;

}


/* 
 * Given a word, a grid file, the dimension of the grid, and the length of the
 * word, this function determines if the word can be found in the grid when
 * read from the left, right, down, or up in that order. If the word does not
 * appear in the grid, the function prints Not Found.  
 */
int find_all  (char grid[][MAX_SIZE], int n, int word_len, char word[],
	       FILE *write_to) {
  
  int right =  find_right(grid,n,word_len,word,write_to);
  
  int left = find_left(grid,n,word_len,word,write_to);

  int down = find_down(grid,n,word_len,word,write_to);

  int up = find_up(grid,n,word_len,word,write_to);
  if (right + down + left + up == 0){
    fprintf(write_to,"%s - Not Found\n",word);
  }
  return 0;

} 


/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided 
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]) {
  FILE* lhs = fopen(lhs_name, "r");
  FILE* rhs = fopen(rhs_name, "r");

  // don't compare if we can't open the files
  if (lhs == NULL || rhs == NULL) return 0;

  int match = 1;
  // read until both of the files are done or there is a mismatch
  while (!feof(lhs) || !feof(rhs)) {
	if (feof(lhs) ||                      // lhs done first
		feof(rhs) ||                  // rhs done first
		(fgetc(lhs) != fgetc(rhs))) { // chars don't match
	  match = 0;
	  break;
	}
  }
  fclose(lhs);
  fclose(rhs);
  return match;
}

