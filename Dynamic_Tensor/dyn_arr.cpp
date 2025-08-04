# include "dyn_arr.h"

void Dyn_arr:: create_arr (void) {

	arr = new long double [arr_size];
}

void Dyn_arr:: destroy_arr (void) {

	delete [] arr;
}

void Dyn_arr:: fill_arr (void) {

	for (i = 0; i < arr_size; i ++) {
		
		* (arr + i) =  (long double) rand () / RAND_MAX;
	}
}
	
void Dyn_arr:: print_arr (void) {
	
	for (i = 0; i < arr_size; i ++) {
		
		std:: cout << "arr[" << i << "] = " << * (arr + i) << '\n';
	}
}
void Dyn_arr:: alloc_arr (size_t n) {

	arr_size = n;
	
	create_arr ();
}

void Dyn_arr:: dealloc_arr (void) {
	
	destroy_arr ();
}
	

