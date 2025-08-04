# include "dyn_tens.h"

// Dyn_tens allocation functions

void Dyn_tens:: alloc_tens1 (void) {
	
	tens1 = new long double [n];
	
	if (tens1 == NULL) {
		
		std:: cout << "Memory allocation failed!" << '\n';
		
		exit (1);
	}
}

void Dyn_tens:: alloc_tens2 (void) {

	tens2 = new long double* [n];
	
	if (tens2 == NULL) {
		
		std:: cout << "Memory allocation failed!" << '\n';
		
		exit (1);
	}
	
	for (i = 0; i < n; i++) {
		
		* (tens2 + i) = new long double [m];
		
		if (* (tens2 + i) == NULL) {
		
			std:: cout << "Memory allocation failed!" << '\n';
			
			exit (1);
		}
	}
}


void Dyn_tens:: alloc_tens3 (void) {

	tens3 = new long double** [n];
	
	if (tens3 == NULL) {
		
		std:: cout << "Memory allocation failed!" << '\n';
		
		exit (1);
	}
	
	for (i = 0; i < n; i++) {
		
		* (tens3 + i) = new long double* [m];
		
		if (* (tens3 + i) == NULL) {
		
			std:: cout << "Memory allocation failed!" << '\n';
			
			exit (1);
		}
		
		for (j = 0; j < m; j++) {
		
			* ( * (tens3 + i) + j) = new long double [l];
			
			if (*( * (tens3 + i) + j) == NULL) {
		
				std:: cout << "Memory allocation failed!" << '\n';
				
				exit (1);
			}
		}
	}
}

// Dyn_tens deallocation functions

void Dyn_tens:: dealloc_tens1 (void) {

	delete [] tens1;
}

void Dyn_tens:: dealloc_tens2 (void) {
	
	for (i = 0; i < n; i++) {
	
		delete [] * (tens2 + i);
	}
	
	delete [] tens2;
}

void Dyn_tens:: dealloc_tens3 (void) {
	
	for (i = 0; i < n; i++) {
		
		for (j = 0; j < m; j++) {
			
			delete [] * (* (tens3 + i) + j);
		}
		
		delete [] * (tens3 + i);
	}
	
	delete [] tens3;
}

// This function creates a tensor and calls it based on its rank. The pointer *no_cmpts stores in an array (of dimension 3) the number of components for each index of the tensor, e.g., the first index of *no_cmpts stores the number of elements of the 1D tensor (array) *tens_1 and so on.

void Dyn_tens:: alloc_tens (size_t rank, size_t *tens_sizes) {
	
	n = *(tens_sizes + 0); 
	m = *(tens_sizes + 1); 
	l = * (tens_sizes + 2);          
	
	switch (rank) {
	
		case 1:
			
			alloc_tens1 ();
			
		case 2:
			
			alloc_tens2 ();
		
		case 3: 
		
			alloc_tens3 ();
	}
}

void Dyn_tens:: dealloc_tens (size_t rank) {

	switch (rank) {
	
		case 1:
			
			dealloc_tens1 ();
			
		case 2:
			
			dealloc_tens2 ();
		
		case 3: 
		
			dealloc_tens3 ();
	}
}

// Filling of allocated tensors

void Dyn_tens:: fill_tens1 (void) {
	
	for (i = 0; i < n; i ++) {
	
		* (tens1 + i) = (long double) rand () / RAND_MAX;
	}
}

void Dyn_tens:: fill_tens2 (void) {

	for (i = 0; i < n; i ++) {
		
		for (j = 0; j < m; j ++) {
		
			* (* (tens2 + i) + j) = (long double) rand () / RAND_MAX;
		}
	}
}

void Dyn_tens:: fill_tens3 (void) {

	for (i = 0; i < n; i ++) {
		
		for (j = 0; j < m; j ++) {
			
			for (k = 0; k < l; k ++) {
				
				* (* (* (tens3 + i) + j) + k) = (long double) rand () / RAND_MAX;
			}
		}
	}
}

void Dyn_tens:: fill_tens (size_t rank) {
	
	switch (rank) {
	
		case 1:
			
			fill_tens1 ();
			
		case 2:
			
			fill_tens2 ();
		
		case 3: 
		
			fill_tens3 ();
	}
	
}

// Printing tensor components to a text file

void Dyn_tens:: print_tens (size_t rank) {
	
	file.open ("tens_components.txt");
	
	switch (rank) {
	
		case 1:

			for (i = 0; i < n; i ++) {
			
				file << * (tens1 + i) << '\n';
			}
			
			break;
			
		case 2: 
			std:: cout << "a" << std:: endl;
			for (i = 0; i < n; i ++) {
			
				for (j = 0; j < m; j ++) {
			
					file << *( * (tens2 + i) + j) << ' ';
				}
				
				file << '\n';
			}
			
			break;
			
		case 3:
			
			for (i = 0; i < n; i ++) {
			
				for (j = 0; j < m; j ++) {
				
					for (k = 0; k < l; k ++) {
			
						file << *( *( * (tens3 + i) + j) + k) << ' ';
					}
					
					file << '\n';
				}
				
				file << '\n';
			}
			
			break;
	}
	
	file.close ();
}


