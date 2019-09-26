// test_search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//Luis Madera
//lmadera1



#include <stdio.h>
#include <assert.h>
#include "search_functions.h"


/* 
 * Declarations for tester functions whose definitions appear below.
 * (You will need to fill in the function definition details, at the
 * end of this file, and add comments to each one.) 
 * Additionally, for each helper function you elect to add to the 
 * provided search_functions.h, you will need to supply a corresponding
 * tester function in this file.  Add a declaration for it here, its
 * definition below, and a call to it where indicated in main.
 */
void test_file_eq();      // This one is already fully defined below.
void test_populate_grid();
void test_find_right();
void test_find_left();
void test_find_down();
void test_find_up();
void test_find_all();


/*
 * Main method which calls all test functions.
 */
int main() {
  printf("Testing file_eq...\n");
  test_file_eq();
  printf("Passed file_eq test.\n\n");

  printf("Running search_functions tests...\n");
  test_populate_grid();
  test_find_right();
  test_find_left();
  test_find_down();
  test_find_up();
  test_find_all();

  /* You may add calls to additional test functions here. */

  printf("Passed search_functions tests!!!\n");
}



/*
 * Test file_eq on same file, files with same contents, files with
 * different contents and a file that doesn't exist.
 * Relies on files test1.txt, test2.txt, test3.txt being present.
 */
void test_file_eq() {
  FILE* fptr = fopen("test1.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  fptr = fopen("test2.txt", "w");
  fprintf(fptr, "this\nis\na different test\n");
  fclose(fptr);

  fptr = fopen("test3.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  assert( file_eq("test1.txt", "test1.txt"));
  assert( file_eq("test2.txt", "test2.txt"));
  assert(!file_eq("test2.txt", "test1.txt"));
  assert(!file_eq("test1.txt", "test2.txt"));
  assert( file_eq("test3.txt", "test3.txt"));
  assert( file_eq("test1.txt", "test3.txt"));
  assert( file_eq("test3.txt", "test1.txt"));
  assert(!file_eq("test2.txt", "test3.txt"));
  assert(!file_eq("test3.txt", "test2.txt"));
  assert(!file_eq("", ""));  // can't open file
}



void test_populate_grid(){
  
  char grid[MAX_SIZE][MAX_SIZE];
    
  assert(populate_grid(grid,",") == -1);
  assert(populate_grid(grid,"test4.txt") == -2);
  assert(populate_grid(grid,"test5.txt") == -2);
  assert(populate_grid(grid,"grid.txt") == 4);
  
}


void test_find_right(){
  
  char grid[MAX_SIZE][MAX_SIZE];
  int grid_dim = populate_grid(grid,"grid.txt");
  FILE *ptfr = fopen("input.txt","w");
  
  assert(find_right(grid,grid_dim,3,"pit",ptfr) == 1);
  
  assert(find_right(grid,grid_dim,3,"tip",ptfr) == 0);
  fclose(ptfr);

}


void test_find_left(){
  char grid[MAX_SIZE][MAX_SIZE];
  int grid_dim = populate_grid(grid,"grid.txt");

  FILE *ptfr = fopen("input.txt","w");
  
  assert(find_left(grid,grid_dim,3,"tip",ptfr) == 1);

  assert(find_left(grid,grid_dim,3,"pit",ptfr) == 0);

  fclose(ptfr);
}


void test_find_down(){
  char grid[MAX_SIZE][MAX_SIZE];
  int grid_dim = populate_grid(grid,"grid.txt");

  FILE *ptfr = fopen("input.txt","w");

  assert(find_down(grid,grid_dim,3,"pop",ptfr) == 1);

  assert(find_down(grid,grid_dim,3,"top",ptfr) == 0);

  fclose(ptfr);

}


void test_find_up(){
  char grid[MAX_SIZE][MAX_SIZE];
  int grid_dim = populate_grid(grid,"grid.txt");

  FILE *ptfr = fopen("input.txt","w");
  
  assert(find_up(grid,grid_dim,3,"pop",ptfr) == 1);

  assert(find_up(grid,grid_dim,3,"key",ptfr) == 0);

  fclose(ptfr);

}


void test_find_all(){
  char grid[MAX_SIZE][MAX_SIZE];
  int grid_dim = populate_grid(grid,"grid.txt");

  FILE *ptfr = fopen("input.txt","w");

  find_all(grid,grid_dim,3,"nope",ptfr);
  fclose(ptfr);
  assert(file_eq("input.txt","output.txt"));

}

