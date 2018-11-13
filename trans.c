#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	int i;
	// check syntax 
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");
	
	while(args[i] != NULL){
		if(args[i] == ','){
			if(args[0] == '%' && args[i+1] == '%')
				mcode = "89";
			else if(args[i-1] == ')' && args[i+1] == '%')
				mcode = "8b";
			else if(args[0] == '0' && args[i+1] == '%')
				mcode = "a1";
			else if(args[0] == '%' && args[i+1] == '0')
				mcode = "a3";
			else(args[0] == '$' && args[i+1] == '%'){
				if(args[i+3] == 'a')
					mcode = "b8";
				else if(args[i+3] == 'c')
					mcode = "b9";
				else(args[i+3] == 'd')
					mcode = "ba";
			}
		}
	}

	/********************************/
    /*  							*/
	/*    generate machine code     */
    /*  							*/
	/********************************/
	
	return 1;	
}
