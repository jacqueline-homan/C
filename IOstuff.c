#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	FILE *fp = fopen("/Users/jacquelinehoman/C/test.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);

	return 0;
}