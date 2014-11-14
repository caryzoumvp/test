#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* create_part_array (const char *pattern, int len) {
	int i = 0;
	int j = 0;
	int k = 0;
	int* s = (int*)malloc(sizeof(int)*len);
	s[0] = 0;
	for (i = 1; i < len; i++ ){
		k = 0;
		for ( j = 0; j < (i+1)/2; j ++) {
			if (pattern[j] == pattern[i-j]){
				k++;
			}	
		}
		s[i] = k;
	
	} 
	return s;
}

int kmp (const char *src, int srclen, const char *pattern, int patlen) {
	int i= 0,j = 0,k = 0;

	if (patlen > srclen)
		return 0;
	int *table = create_part_array(pattern, patlen);
	for (i = 0; i < srclen; i++ ) {
		for (j = i; j < srclen ; j ++) {
			if (k == patlen -1) {
				return i;
			}
			if (src[j] == pattern[k]) {
				k++;
			} else {
				k = table[k];
				j--;

			}
		}
	}

}



int main()
{
	const char *src = "aabb ddc c aabbaabbccddee";
	const char *pattern = "aabbaa";

	int pos = kmp(src, strlen(src), pattern, strlen(pattern));
	printf( "first pos is %d\n", pos);

}
