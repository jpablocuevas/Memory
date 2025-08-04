# include <iostream>
# include <iomanip>
# include <new>
# include <fstream>
# include <cstdlib>
# include <ctime>

class Dyn_tens {

	private:
		
		long double *tens1;
		long double **tens2;
		long double ***tens3;
		
		std:: ofstream file;
		
		size_t n, m, l;
		
		unsigned int i, j, k;
		
		void alloc_tens1 (void);
		
		void alloc_tens2 (void);
		
		void alloc_tens3 (void);
		
		void dealloc_tens1 (void);
		
		void dealloc_tens2 (void);
		
		void dealloc_tens3 (void);
		
		void fill_tens1 (void);
		
		void fill_tens2 (void);
		
		void fill_tens3 (void);
		
	public:	
	
		void alloc_tens (size_t, size_t *); 
		
		void dealloc_tens (size_t);
		
		void fill_tens (size_t);
		
		void print_tens (size_t);

};




