int main()
{
	char str[]= "ABCDEF ABCDEF1234", ex;
	int k=-1;
    message(str,k);
	return 0;
}	
	
void message(char str[],int k)	

    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)
        {
            if (str[i] >= 65 && str[i]<= 90)
            {
                char ex = str[i]- 65 + 26;
                ex = (ex+k) % 26;
                str[i] = ex + 65;
           }
           else if (str[i] >= 48 && str[i] <= 57)
           {
                char ex = str[i] - 48 +10;
                ex = (ex +k) %10;
                str[i]= ex + 48;
            }
        
            
        }
    printf("%s\n", str);
    
	
    }