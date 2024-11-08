#include "memalloc.h"

int main( int argc, char * argv[] )
{
  memalloc_init(1000000, NEXT_FIT);
  return 0;
}
