#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

int opindex = 0;
int opchar = 0;
bool plus1 = true;
bool plus2 = true;
struct option dev[]{
	{"query", 			required_argument,	0, 'q'},
	{"version", 			no_argument, 		0, 'v'},
	{"longinformationrequest",	no_argument,		0, 'i'},
	{0,				0,			0,  0 },
};

int main(int ac, char *av[])
{
	while(-1 != (opchar = getopt_long(ac, av, "q:vi", opts, &opindex)) ){
		switch(opchar){
		case 'q':
			if(oparg == NULL)
				plus1 = false;
			break;
		case 'v':
			plus2 = true;
			break;
		case 'i':
			plus2 = true;
			break;
		}
	}
	if(plus)
		printf("+\n");
	else
		printf("-\n");
	return 0;
}

