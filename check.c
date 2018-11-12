#include "myas.h"

int is_valid(char *op, char *args)
{
	int i = 0;
	while(args[i] != NULL) {
		if(args[i] == ',')
			break;
		i++;
	}
	
	if(args[0]=='0'||args[0]=='-'||args[0]=='(') {
		if(args[i+1]=='0'||args[i+1]=='(')
			return 0;
	}

	if(args[0]=='$') {
		if(args[i+1]=='$')
			return 0;
	}

	if(args[i+1]=='$')
		return 0;



	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	/********************************/
    /*  							*/
	/*         syntax check         */
    /*  							*/
	/********************************/
	
	return 1;
}
