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
	
	if(args[i] == NULL)
		return 0;

	else{
		while(args[i] != NULL){
			if(args[i] == ','){
				// 1. reg to reg
				if(args[0] == '%' && args[i+1] == '%')
					strcpy(mcode, "89");
				// 2,3. mem to reg
				else if(args[i-1] == ')' && args[i+1] == '%')
					strcpy(mcode, "8b");
				// 4. mem to reg(eax)
				else if(args[0] == '0' && args[i+1] == '%')
					strcpy(mcode, "a1");
				// 5. reg(eax) to mem
				else if(args[0] == '%' && args[i+1] == '0')
					strcpy(mcode, "a3");
				// 6. immediate to reg
				else if(args[0] == '$' && args[i+1] == '%'){
					if(args[i+3] == 'a')
						strcpy(mcode, "b8");
					else if(args[i+3] == 'b')
						strcpy(mcode, "bb");
					else if(args[i+3] == 'c')
						strcpy(mcode, "b9");
					else if(args[i+3] == 'd')
						strcpy(mcode, "ba");
				}
			}
		}
	}

	return 1;	
}
