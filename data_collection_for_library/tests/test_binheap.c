#include <stdio.h>
#include <string.h>
#include <binheap.h>
#include <time.h>


int main(int argc, char *argv[])
{
  size_t max_size = 30;

//calculate time to create array
struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = 1;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t l = 0; l < rep; l++) {
      
	//create array(time)
  		float *minA=(float *)malloc(sizeof(int)*max_size);
	//initialize array;
  
    srand(125); 
    for (size_t j = 0; j < max_size; j++) {
      minA[j] =  (int)(rand() - RAND_MAX / 2) % 200;
    }

  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  time =  accum / rep;


  printf("\n make array: %f", time);
  
  
  

//create min binheap(time+add time of array creation)  

  
  struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = 1;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t l = 0; l < rep; l++) {
      
	binheap_type *minH=build_heap(minA,0,max_size,sizeof(int),leq_int);//build minheap
  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  time =  time + accum / rep;
 
  printf("\n make array + create heap: %f", time);
  

//finds the minimum
struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = max_size;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t l = 0; l < rep; l++) {
      
	 min_value(maxH);
      
  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  time =  accum / rep;
 
  printf("  find the minimum: %f", time);
      
      //empties the heap and gives the average extract min time
struct timespec requestStart, requestEnd;
  double accum;
  size_t rep = max_size;

  clock_gettime(CLOCK_REALTIME, &requestStart);
  for (size_t l = 0; l < rep; l++) {
      
	 extract_min(maxH);
      
  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec) +
          (requestEnd.tv_nsec - requestStart.tv_nsec) / 1E9;
  
  time =  accum / rep;
 
  printf("\n average extraction time: %f", time);
      

  delete_heap(minH);
  

  free(minA);
  
  
  return 0;
}



