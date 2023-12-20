#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double ***alloc_3D (int, int, int);

void dealloc_3D (double***,int, int);



double ***alloc_3D (int x, int y , int z){
	
	double ***f;
	
	f = (double***) calloc (x, sizeof(double**));
	
	int i, j;
	
	for (i = 0; i<x; i++){
	
	f[i] = (double**) calloc (y, sizeof (double*));
	
	for (j = 0; j< z; j++){
		f[i][j] = (double*) calloc (z, sizeof(double));
		}
			
	}
	
	return f;

}


void dealloc_3D (double ***f, int y, int z){

	int i, j;
	
	for (i = 0; i<y; i++){
	
		for (j = 0; j<z; j++){
		
		free (f[i][j]);
	
		
		}	
		
		free (f[i]);
		
	}
	
	free (f);
}


int main (void) {

	int x = 3, y = 3, z = 3;
	int i,j,k;
	
	double ***f;
	
	f = (double***) alloc_3D (x, y, z);
	
	
	for (i = 0; i<x; i++){
		for (j = 0; j<y; j++){
			for (k = 0; k<z; k++){
				
				printf("f[%d][%d][%d] = %lf \n", i, j, k, f[i][j][k]);
	
			}
	
		}	
	
	}
	
	dealloc_3D (f, y, z);


	return 0;
}


