#include <stdio.h>
#include <stdlib.h>

char* get();
int main(int argc, char ** argv)
{
    printf("%s",get());
}


char* get() {
  return "Hello World!";
}
