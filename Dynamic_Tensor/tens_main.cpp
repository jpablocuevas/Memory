# include "dyn_tens.h"

int main (void) {
	
	srand (time (NULL));
	
	Dyn_tens tensor;
	
	size_t no_cmpts [3] = {3, 3, 3};
	
	size_t rank = sizeof (no_cmpts) / sizeof (no_cmpts[0]);
	
	tensor.alloc_tens (rank, &no_cmpts[0]); // Passing by reference the number of elements for each index of the tensor. Since this code only deals with rank three tensors there is no need to pass the size of the array because it is already known. 
	
	tensor.fill_tens (rank);
	
	tensor.print_tens (rank);
	
	tensor.dealloc_tens (rank);
	
	
	return 0;
}
