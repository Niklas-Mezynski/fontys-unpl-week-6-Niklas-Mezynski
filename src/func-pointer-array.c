#include <stdio.h>
#include <stdlib.h>

void fun_nl(void) {
  printf("Hallo wereld\n");
}

void fun_en(void) {
  printf("Hello world\n");
}

void fun_de(void) {
  printf("Hallo Welt\n");
}

int main(int argc, char* argv[]) {
  // void (* funptr[3])(void); //Declaration
  void (** funptr)(void); 
  funptr = malloc(sizeof(void *) * 3); //Declaration
  funptr[0] = fun_en;
  funptr[1] = fun_de;
  funptr[2] = fun_nl;
  if (argc != 2) {
    printf("run with one argument 1 for English, ");
    printf("2 for Dutch or 3 for German\n");
    return 0;
  }  

  int ilang = atoi(argv[1])-1;
  
  funptr[ilang]();
  return 0;
}