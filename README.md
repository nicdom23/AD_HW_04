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
