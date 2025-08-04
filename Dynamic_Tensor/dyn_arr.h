# include <iostream>
# include <new>
# include <cstdlib>

class Dyn_arr {

	private:
		
		long double *arr;
		
		size_t arr_size;
		
		unsigned int i;
		
		void create_arr (void);
		
		void destroy_arr (void); 
	
	public:
		
		void alloc_arr (size_t);
		
		void dealloc_arr (void);
		
		void fill_arr (void);
		
		void print_arr (void);
	
};



