# include "dyn_arr.h"



int main (void) {
	
	srand (time (0));
	
	Dyn_arr arr;
	
	size_t arr_size = 10;
	
	arr.alloc_arr (arr_size);
	
	arr.fill_arr ();
	
	arr.print_arr ();
	
	arr.dealloc_arr ();
	
	return 0;
}
