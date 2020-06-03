#ifndef __TOTAL_ORDERS__
#define __TOTAL_ORDERS__
//the new type I define is a pointer to a function returning an int value and having two parameters that are constant void values
typedef int (*total_order_type)(const void *a, const void *b);
//comparing results in 1 if a smaller or equal wrt total order, 0 otherwise

//typedef int new_type; is normal definition
//I use the new type as a type for a parameter


int leq_float(const void *a, const void *b);
//build minheap of floats

int leq_int(const void *a, const void *b);
//build minheaps of integers


int geq_int(const void *a, const void *b);
//build maxheap of integers
#endif