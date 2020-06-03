# AD_HW_04
Homework exercises for the Algorithm design course at the University of Trieste(DSSC course)

30/05/2020

I looked at the Heap slides, it seems simple. The operations you can do are building the heap($\Theta(n)$), looking at the minimum ($\Theta(1)$), extracting the minimum ($\Theta(log(n))$),decreasing a key in the heap ($\Theta(log(n))$), and then inserting a key in the heap ($\Theta(log(n))$). The heap property is mantained thanks to the Heapify algorithm. It doesn't look so difficult to understand.


 ----------------------------------------
 31/05/2020

So I report here in this homework the array implementation of the binary heap that we implemented in class. It already has all the wanted functions. 

We see that the code already has the iterative heap implementation. There is no recursive call
A recurisve implementation would just be:

        void heapify(binheap_type *H, unsigned int node) 
	       unsigned int dst_node  = node, child; 

         

		      //find minimum among node and its children
		      child= RIGHT_CHILD(node);
		
		      if(VALID_NODE(H,child) && //doesn't hold if node is a leaf(if node is a leaf then child is not a valid node)
		      	H->leq(ADDR(H,child),ADDR(H, dst_node))){//comparison by adresses
		      	dst_node = child; //a children of the node I am dealing with satisfies to be the candidate to be swapped		
		      }

		      child= LEFT_CHILD(node);
		
		      if(VALID_NODE(H,child) && 
		      	H->leq(ADDR(H,child),ADDR(H, dst_node))){
		      	dst_node = child; 		
		      }
		
		      //if the minimum is not in node swap the keys
		      if(dst_node != node){
			     swap_keys(H, dst_node,node);		     

                 heapify(H,dst_node); // <--- here we add the recursive call instead of the while cycle


		      }
        }

-----------------------------------------------------------

For the third point of the exercise I could use c++'s timing function and create a useful output. 
I understood that decrease_key does not invoke heapify.
------------------------------------------------------
So after formatting and correcting the code I used three different type of arrays:

- Array $A = {0,1,2,3,4,...,n-1}$ which is a best possible array, because the heap propery is already satisfied.
- Array $A$ of size $n-1$ of random integers from 0 to 20 wich creates an average array.
- Array $A = {n,n-1,n-2,...,3,2,1}$ wich is a worst possible array, because the heap property is violated for all the subtrees at every level of the total tree. So Heapify makes the most iterations.

For each of these arrays I measured the time to build, find the min value, and the time to extract all the keys of the heap.

The output of the program 'test_binheap' is:


                    ordered array        ||       random array        ||     reverse order array
         n      build  find min  ext min ||  build  find min  ext min ||  build  find min  ext min        
          50   0.000002 0.000000 0.000026|| 0.000006 0.000000 0.000026|| 0.000007 0.000000 0.000027||
         100   0.000004 0.000000 0.000063|| 0.000011 0.000000 0.000062|| 0.000014 0.000000 0.000124||
         150   0.000006 0.000000 0.000104|| 0.000017 0.000000 0.000105|| 0.000021 0.000000 0.000123||
         200   0.000007 0.000000 0.000148|| 0.000024 0.000000 0.000149|| 0.000028 0.000000 0.000157||
         250   0.000009 0.000000 0.000195|| 0.000029 0.000000 0.000219|| 0.000034 0.000000 0.000204||
         300   0.000011 0.000000 0.000260|| 0.000035 0.000000 0.000246|| 0.000042 0.000000 0.000282||
         350   0.000011 0.000000 0.000263|| 0.000038 0.000000 0.000278|| 0.000043 0.000000 0.000272||
         400   0.000013 0.000000 0.000303|| 0.000042 0.000000 0.000542|| 0.000064 0.000000 0.000324||
         450   0.000014 0.000000 0.000343|| 0.000045 0.000000 0.000334|| 0.000052 0.000000 0.000376||
         500   0.000015 0.000000 0.000371|| 0.000050 0.000000 0.000400|| 0.000057 0.000000 0.000387||
         550   0.000017 0.000000 0.000417|| 0.000056 0.000000 0.000438|| 0.000064 0.000000 0.000467||
         600   0.000019 0.000000 0.000475|| 0.000061 0.000000 0.000467|| 0.000069 0.000000 0.000492||
         650   0.000020 0.000000 0.000509|| 0.000066 0.000000 0.000527|| 0.000075 0.000000 0.000533||
         700   0.000021 0.000000 0.000570|| 0.000159 0.000000 0.000646|| 0.000080 0.000000 0.000593||
         750   0.000023 0.000000 0.000613|| 0.000076 0.000000 0.000609|| 0.000086 0.000000 0.000637||
         800   0.000024 0.000000 0.000649|| 0.000081 0.000000 0.000668|| 0.000092 0.000000 0.000686||
         850   0.000025 0.000000 0.000715|| 0.000086 0.000000 0.013893|| 0.000098 0.000000 0.000749||
         900   0.000027 0.000000 0.000764|| 0.000092 0.000000 0.000760|| 0.000103 0.000000 0.000807||
         950   0.000029 0.000000 0.000808|| 0.000097 0.000000 0.000812|| 0.000109 0.000000 0.000831||
        1000   0.000030 0.000000 0.006396|| 0.000118 0.000000 0.000847|| 0.000124 0.000000 0.000874||
        1050   0.000031 0.000000 0.000899|| 0.000106 0.000000 0.000925|| 0.000120 0.000000 0.000933||
        1100   0.000033 0.000000 0.001054|| 0.000112 0.000000 0.000959|| 0.000126 0.000000 0.000987||
        1150   0.000035 0.000000 0.001027|| 0.000117 0.000000 0.001016|| 0.000142 0.000000 0.001041||
        1200   0.000036 0.000000 0.001146|| 0.000174 0.000000 0.003333|| 0.000139 0.000000 0.001099||
        1250   0.000037 0.000000 0.001108|| 0.000127 0.000000 0.001119|| 0.000143 0.000000 0.004016||
        1300   0.000039 0.000000 0.001155|| 0.000132 0.000000 0.001192|| 0.000176 0.000000 0.001263||
        1350   0.000041 0.000000 0.001227|| 0.000138 0.000000 0.001224|| 0.000155 0.000000 0.001260||
        1400   0.000042 0.000000 0.001258|| 0.000150 0.000000 0.001403|| 0.000160 0.000000 0.005252||
        1450   0.000043 0.000000 0.001381|| 0.000147 0.000000 0.001334|| 0.000166 0.000000 0.003281||
        1500   0.000045 0.000000 0.001486|| 0.000152 0.000000 0.007288|| 0.000197 0.000000 0.001427||
        1550   0.000046 0.000000 0.001444|| 0.000156 0.000000 0.001426|| 0.000179 0.000000 0.009423||
        1600   0.000048 0.000000 0.001481|| 0.000161 0.000000 0.002855|| 0.000184 0.000000 0.001524||
        1650   0.000049 0.000000 0.001530|| 0.000166 0.000000 0.001665|| 0.000189 0.000000 0.007451||   
        1700   0.000050 0.000000 0.001602|| 0.000171 0.000000 0.001624|| 0.000194 0.000000 0.001641||
        1750   0.000052 0.000000 0.001661|| 0.000190 0.000000 0.001646|| 0.000219 0.000000 0.001690||
        1800   0.000054 0.000000 0.001913|| 0.000181 0.000000 0.006139|| 0.000207 0.000000 0.001752||
        1850   0.000055 0.000000 0.001788|| 0.000186 0.000000 0.001792|| 0.000213 0.000000 0.004373||
        1900   0.000056 0.000000 0.001791|| 0.000198 0.000000 0.005235|| 0.000218 0.000000 0.001893||
        1950   0.000058 0.000000 0.004590|| 0.000195 0.000000 0.001865|| 0.000232 0.000000 0.006385||

So all the execution times grows with the dimension. The ordered array has the best performance for each value of n. The reverse ordered array has the worst performance for each value of n. The random array has a performance between the two.

This is all correct with the theory. Notice how as n doubles then the time to build the matrix doubles. Of course ext_min has a time $\Theta(1)$ so it is so small that it is not measured by the program. ext_min's performance does not depend on n.

----------------------------------------------------------------------

Now I want to prove that with the array representation, then the leaves of a binary heap that contains $n>0$ nodes are indexed by $\lfloor n/2 \rfloor+1,\lfloor n/2 \rfloor+2,\cdots,n$

We count the indexes starting from 1;

- Let's take the rightmost leaf of the last level: it has index $n$
- It's parent is then an internal node that has index $\lfloor n/2 \rfloor$
- Then the node of index $\lfloor n/2 \rfloor +1$ must be a leaf, because we have already picked the rightmost leaf of the last level and so there are no more.
- Since the heap is a nearly complete binary tree, by its topology then all the consecutive indexes from $\lfloor n/2 \rfloor +1$ to $n$ must be leaves and so we have our proof.

----------------------------------------------------------

Now I want to see that HEAPIFY applied on a binary heap H of size n has a worst case running time $\Omega(log n)$.

We just need to think about this case:

-We have swapped the root with the last element of the array, which is the rightmost leaf of the latest level of the heap. We have decreased the node count by 1. Now we need to apply HEAPIFY.

The worst-case scenario from the node i is when $H[left(i)]\preceq H[i]$ or $H[right(i)]\preceq H[i]$ because then the if-clause in the for-cycle of the algorithm is true at least once, a swap is made, and HEAPIFY is called recursively on one of the children. But the most important thing for the worst-case scenario is that one of the above must be recursively true for that children(so depending on the case $H[left(right(i))]\preceq H[right(i)]$ or $H[right(right(i))]\preceq H[right(i)]$ or either  $H[left(left(i))]\preceq H[left(i)]$ or $H[right(left(i))]\preceq H[left(i)]$), until we reach a leaf. 

- This can happen for example when after the swap to extract the minimum we have an array A of size n and keys ${a_1,a_2,\cdots,a_n}$where $a_i \preceq a_1 \forall i = 2,\cdots,n$

Heapify is then called a number of times equal to the number of nodes that connects the root to one leaf of the tree, which is of course the height of the tree h (or also could be h-1), because heap is a nearly complete binary tree.
Since $h = \lfloor n \rfloor$ then the worst-case HEAPIFY has a running time $\Omega(log n)$.

---------------------------------------------------

For the last exercise of the first paper we can see that for a heap H of n elements:

- $\lceil \frac{n}{2^{h+1}} \rceil = \lceil \frac{2^{log_2 (n)}}{2^{h+1}} \rceil \leq \lceil \frac{ 2^{\lceil log_2 (n)\rceil} }{2^{h+1}} \rceil  = \lceil  2^{\lceil log_2 (n)\rceil - h -1}  \rceil = \lceil  2^{\lfloor log_2 (n)\rfloor - h}  \rceil = 2^{\lfloor log_2 (n)\rfloor - h}=2^{height(H) - h}$ which is another, more direct and intuitive way of finding the maximum number of nodes at height h.

But this is just an upper bound, and is not enough. I need to think of something else, but I cannot find an inductive or direct proof that is sufficient.

-----------------------------------------------
There goes the first exercise of the second paper.
03/06/2020

After a lot of debugging I implemented the no-swap in A code. The functions insert_value and decrease_key work with pointers to key_pos. I know I need to fix them to work with pointers to A.

As for array handling I have choosen that insert_value adds the key to A, while extract_min does not remove the key from the array. So the array keeps growing as new keys are inserted and doesn't empty. Once num_of_elem_A == max_size a new insertion would make the code stop (as the program goes segfault because it tries to handle a NULL value). This is how I have choosen to handle the array.



-----------------------------------------------------
Now for the second exercise of the second paper. We see that it looks like a comparison between the sorting of an array by using SelectionSort and by using HeapSort. We consider that the array is full, so that $|A| = |D|$. The algorithm calls build once and then extract_min until D is empty.

- If build,is_empty$\in \Theta(1)$, extract_min$\in \Theta(|D|)$ then it is like if we are using SelectionSort

$T(|A|) = \Theta(1) + |D|\Theta(|D|) = \Theta(|A|^2)$

- If build$\in \Theta(|A|)$,is_empty$\in \Theta(1)$, extract_min$\in \Theta(log|D|)$ then it is like if we are using HeapSort

$T(|A|) = \Theta(|A|) + |D|\Theta(log|D|) = \Theta(|A|log|A|)$


This shows how using heaps is a good way to sort an array. Heapsort then changes the array in place at the opposite of the 