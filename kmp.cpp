#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* create_part_array (const char *pattern, int len) {
	int i,j,k,m;
	int* s = (int*)malloc(sizeof(int)*len);
	s[0] = 0;
	for (i = 1; i < len; i++ ) { //total string compare
        for (j = 0; j < i; j ++) {
            m = 0;
            for ( int k = 0; k <= j; k++ ) { //substring compare
                if (pattern[k] == pattern[i-j+k]) //character compare
                    m++; 
                else {
                    m = 0;
                    break;
                }
            }
            if (m > s[i])
                s[i] = m;
        } 
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
                free(table);
                return i;
            }
            if (src[j] == pattern[k]) {
                k++;
            } else {
                if (table[k] > 0) {
                    k -= table[k];
                    j--;
                } else {
                    k = 0;
                    break;
                }

            }
		}
	}

}



int main()
{
	const char *src = "ababaa ababaabababaaabba";
	const char *pattern = "abababa";

	int pos = kmp(src, strlen(src), pattern, strlen(pattern));
	printf( "first pos is %d\n", pos);

}
