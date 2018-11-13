#include "myas.h"

int is_valid(char *op, char *args)
{
	int i = 0;
	
	if(args[i] == NULL)
		return 0;

	while(args[i] != NULL) {
		if(args[i] == ',')
			break;
		i++;
	}	

	if(args[0] == '0' || args[i-1] == ')'){
		if(args[i+1] == '0' || args[i+1] == '(')
			return 0;
	}

	if(args[i+1] == '$')
		return 0;

	return 1;
}
