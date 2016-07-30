#include <dlfcn.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int (*func)( int);
bool init_library(char *libName, char *funcName){
	void *hdl = dlopen(libName, RTLD_LAZY);
	if(NULL == hdl)
		return false;

	func = (int (*) (int))dlsym(hdl, funcName);
	if (NULL == func)
		return false;

	return true;
}

int main(int argc, char *argv[])
{
	int q, r = 0;
	if(argc != 4){
		printf("a few or many parameters! argc = %i\n", argc);
		return 1;
	}
	q = atoi(argv[3]);	
	printf("%s - %s - %s\n", argv[1], argv[2], argv[3]);
	printf("%i\n", q);
	if(init_library(argv[1], argv[2]))
		r = func(q);
	printf("%i\n", r);
	return 0;
}
