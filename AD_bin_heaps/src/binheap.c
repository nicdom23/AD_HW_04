#include <binheap.h>
#include <string.h>
#include <stdio.h>

//index of the parent is defined by math relations (parent of 1 is 0)
//this is an integer division
#define PARENT(node) ((node-1)/2) 

#define LEFT_CHILD(node) (2*(node)+1)
#define RIGHT_CHILD(node) (2*(node+1))

#define VALID_NODE(H,node) ((H)->num_of_elem>(node))

#define ADDR(H,node) ((H)->A+(node)*(H)->key_size) //adress to the value stored in the node node(pointer algebra)

#define INDEX_OF(H,addr) (((addr)-((H)->A))/(H)->key_size)//index of node stored in that adress


int is_heap_empty(const binheap_type *H)
{
	//we can accurately use the objects of the struct binheap_type

    return H->num_of_elem == 0;
}

const void *min_value(const binheap_type *H)//we want to return a pointer to a value of the array
{
    if(is_heap_empty(H)){
	return NULL;
    }
	//minimum is stored in the root that is A[0]
    return ADDR(H,0);//returns a pointer to an element inside a node of our array
		//here we return an adress to the root(we do nothing to the min!)
}

void swap_keys(binheap_type *H, unsigned int n_a, unsigned int n_b){
//two possible ways, the simplest is to swap element in the array, but we need to copy a number of elemenets which depend on key size
//otherwise we could store an array of integers which store a pointer to the real key, this array will deal with all the swapping, A remains the same
//we go on the first case here(you need to handle an unknown number of bytes, while you write the library, but you save pointers)
	void *p_a = ADDR(H, n_a);
	void *p_b = ADDR(H, n_b);
	void *tmp = malloc(H->key_size); //create temporary space in heap of the wanted size of key

	memcpy(tmp, p_a, H->key_size);//copies memory of the given bit size
	memcpy(p_a, p_b, H->key_size);
	memcpy(p_b, tmp, H->key_size);

	free(tmp);
	//a simple swapping function
}



void heapify(binheap_type *H, unsigned int node) //nodes are integers(fixes heap property on the current node,and its children)
{
	unsigned int dst_node  = node, child; //dst node contains the minimum among node and its children
				//dst_node is initialzed and defined here, child is just defined
	do{

		node= dst_node;//useful for iteration, sets the new node to choose(updates the node from the second_iteartion onwards)

		//we need to find the smallest node (w.r.t total order) between a parent and its two children


		//find minimum among node and its children
		child= RIGHT_CHILD(node);
		
		if(VALID_NODE(H,child) && //doesn't hold if child is a leaf
			H->leq(ADDR(H,child),ADDR(H, dst_node))){//comparison by adresses
			dst_node = child; //a children of the node I am dealing with satisfied to be the candidate to be swapped??		
		}

		child= LEFT_CHILD(node);
		
		if(VALID_NODE(H,child) && 
			H->leq(ADDR(H,child),ADDR(H, dst_node))){
			dst_node = child; 		
		}
		
		//if the minimum is not in node swap the keys
		if(dst_node != node){
			swap_keys(H, dst_node,node);
		}

	}while (dst_node !=node);

}



const void *extract_min(binheap_type *H)//we do not save a space in memory for this min( we just have to save it by copying
{
    // This function is a bit more complex
    if(is_heap_empty(H)){//this case is easy
	return NULL;
    }
    //NEED TO IMPLEMENT IT
    swap_keys(H,0,H->num_of_elem-1);
	//swap key of the root with 
	//the last element of the array(of the heap)(which is the right-most leaf of the last level)
    
	//deleting the right-most leaf of the last level
    H->num_of_elem--;//
    
    //now I need to restore heap property
    heapify(H,0);//call heapify on root(it fixes the heap property thst pushes down the problem)

    return ADDR(H,H->num_of_elem);//return the address of the last element, which is the minimum now
							//I do not get this +1, try and test it later
}


const void *find_the_max(void *A, 
                         const unsigned int num_of_elem, 
                         const size_t key_size, 
                         total_order_type leq){

	if (num_of_elem == 0) {
		return NULL;
	}

	//for all the values in A
	const void *max_value = A;//select first cell in array
	for(const void *addr = A+key_size; 
			addr!=A+num_of_elem*key_size;addr+=key_size)//we use pointer arithmetics
	{
		//if addr>max_value
		if(!leq(addr,max_value)){//comparison between adresses
			max_value = addr;
		}
	}
	return max_value;//we have operated on adresses and now we return an adress
}



binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
	binheap_type *H = (binheap_type *) malloc(sizeof(binheap_type));//saves space for the variables
	H->A =A;
	H->num_of_elem = num_of_elem;
	H->max_size = max_size;
	H->key_size = key_size;
	H->leq = leq;
	H->max_order_value = malloc(key_size);//no casting on pointer type because it's a pointer to void, i need to allocate new space for it because the array is not safe for them, because it can be cancelled

	if(num_of_elem==0){
		return H; //everithing is done as it is
	}
	
							//key size is needed because A is an array of void						
	const void * value = find_the_max(A, num_of_elem, key_size, leq);//takes A and finds the maximum

	memcpy(H->max_order_value,value, key_size);//place the maximum in it's position of the stuct

//Now we have saved the biggest element of the array

//now we need to establish the heap property by calling heapify
//start from the bottom(second last level, for the last level, only leafs, heap property is already valid) to the top
	
	for(unsigned int i = num_of_elem/2; i>0; i--){//num_of_elem/2 identifies a good starting point, beacause it identifies the parent of the last leaf of the tree, which is of course always an internal node
		heapify(H,i);
	}
	heapify(H,0);
	


    return H;
}

void delete_heap(binheap_type *H) //free the memory allocated by build_heap
{
    free(H->max_order_value);
    free(H);
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    unsigned int node_idx = INDEX_OF(H,node);//we return the node index of the pointer

	//if node does not belong to H or *value is > *node
	//the operation cannot be done(we cannot decrease node to value), return NULL
	if(!VALID_NODE(H,node_idx) || !(H->leq(value, node))){//again a comparison by address
		return NULL;
	}

	memcpy(node,value, H->key_size);//change the value of the node

	//now we need to restore heap property

	unsigned int parent_idx = PARENT(node_idx);
	void *parent = ADDR(H, parent_idx);
	
	//if not the root and  *parent greater than *node
	while((node_idx != 0) && (!H->leq(parent,node))){
		
		//swap parent and node keys		
		swap_keys(H,parent_idx, node_idx);

		
		//focusing up on the node's parent
		//moving up the check
		node_idx = parent_idx;
		node =parent;//we need the adress in order to compare under leq
		
		parent_idx = PARENT(node_idx);
		parent = ADDR(H,parent_idx);
	}

    return node;
}





const void *insert_value(binheap_type *H, const void *value)
{
    if(H->max_size == H ->num_of_elem){
		return NULL;
	}//we do not want to allocate new memory, so this is the only possible behaviour of the code(maximum number of elements contained? we do nothing)
		//case of empty array, vs case of new maximum value to insert	
	if(H->num_of_elem == 0 || !H->leq(value, H->max_order_value)) {
		memcpy(H->max_order_value,value, H->key_size);
	}

	//we have the adress of a new node
	void *new_node_addr = ADDR(H,H->num_of_elem);//this is the position defined  below
	
	//insert a new left-most node in the last level of the heap, so it is the last element of the array 
				//copy the max value of the array
	memcpy(new_node_addr, H->max_order_value, H->key_size);

	//increase the size of the heap
	H->num_of_elem ++;

	//decrease the key of the new node(restores heap property
	return decrease_key(H,new_node_addr, value);
}

void print_heap(const binheap_type *H, 
                void (*key_printer)(const void *value))
{
	unsigned int next_level_node = 1;//stores the index of the leftmost node of the next level
	for(unsigned int node = 0;node<H->num_of_elem; node++){//stores the node I am dealing with
		if (node == next_level_node){
			printf("\n");		
			next_level_node = LEFT_CHILD(node);		
		}else{
			printf("\t");		

		}

	key_printer(ADDR(H,node));//printss the key using the custom printing function

	}

	printf("\n");

}
		//parent_idx = PARENT(node_idx);??

		//parent = ADDR(H, parent_idx);??

