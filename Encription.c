#include <stdio.h>

void message(char str[],int k)
 
int main()
{
	char str[]= "ABCDEF", ex;
	k=-1;
	
	

	return 0;
}	
	
void message(char str[],int k)	

    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)
        {
            if (str[i] >= 'A' && str[i]<= 'Z'>);
            {
                char ex = str[i]-'A' + 26;
                ex = (ex+k) % 26;
                str[i] = ex + 'A';
           }
           else if (str[i] >= '0' && str[i] <= '9')
           {
                char ex = str[i] - '0'+10;
                ex = (ex +k) %10;
                str[i]= ex + '0';
            }
        }
    
    
	printf("%s\n", str[i]);
    }
	/*for(i = 0; str[i] != '\0' ; ++i){
		ex = str[i];
		
		if(ex>65  )
	    
	
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
			
			str[i] = ch;
		
	}
	
	printf("Encrypted messages: %s", str);
	
	return 0;*/
	
}  