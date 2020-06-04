#include <stdio.h>
#include <string.h>
#include <binheap.h>

#include "common/test_time.h"

#define MAX_SIZE 30

void int_printer(const void *value)
{
  printf("%d", *((const int *)value));
}

int main(int argc, char *argv[])
{	
  float *maxA=(float *)malloc(sizeof(int)*MAX_SIZE);
  binheap_type *maxH=build_heap(maxA,0,MAX_SIZE,sizeof(int),geq_int);//build maxheap

  float *minA=(float *)malloc(sizeof(int)*MAX_SIZE);
  binheap_type *minH=build_heap(minA,0,MAX_SIZE,sizeof(int),leq_int);//build minheap
  
  printf("Keep inserting and removing the minimum from the (min/max)heaps ");
  printf("until they are\nnot empty.\n\n");
  int value;
  do {
    printf("Insert an integer number (0 to extract the min): ");
    scanf("%d", &value);
    if (value != 0) {
      insert_value(maxH, &value);
      insert_value(minH, &value);
    } else {
      
      void *result = extract_min(maxH);
      printf("maxheap extracted min: ");
      int_printer(result);

      result = extract_min(minH);
      printf("\nmin-heap extracted min: ");
      int_printer(result);
      printf("\n");
    }

    printf("Max Heap\n");
    print_heap(maxH, int_printer);

    printf("\nMin Heap\n");
    print_heap(minH, int_printer);
    printf("\n");
    
  } while (!is_heap_empty(minH));
  
  delete_heap(minH);
  delete_heap(maxH);

  free(minA);
  free(maxA);
  
  return 0;
}

