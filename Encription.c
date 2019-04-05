#include <stdio.h>


 
int main()
{
	char str[]= "aaaaadefghijklmnopqrs", ex;
	int i, 
	k=-1;
	
	printf("Message %s\n",str);
	
	
	for(i = 0; str[i] != '\0' ; ++i){
		ex = str[i];
		
	    
	
		str[i]=ex+k;
		
		/*if(ex >= 'a' && ex <= 'z'){
			ex = ex + k;
			
			if(ex > 'z'){
				ex = ex - 'z' + 'a' ;
			}
			
			str[i] = ex;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			*/str[i] = ch;
		}
	}
	
	printf("Encrypted messages: %s", str);
	
	return 0;
}  