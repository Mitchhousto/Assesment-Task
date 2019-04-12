

#include <stdio.h>
#include <string.h>
char *Encription(char [],int k);	
char *Decription(char [],int k);
char *encription(char []);
char *decryption(char []);
char alpha[52]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
char key[52]="QWERTYUIOPASDFGHJKLZXCVBNM";

int main()
{
	char *c_text,msg[200];
	int choice,k=-1;
    
    printf("Enter message:");
    scanf("%s",msg);
    
    do{
    printf("\nPress 1 for Rotation encription \nPress 2 for Rotation decription\nPress3 for substitution encription\nPress 4 for substitution decription\nPress 0 for exit\n");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
        c_text=Encription(msg,k);
        break;
        case 2:
        c_text=Decription(msg,k);
        break;
        case 3:
        c_text=encription(msg);
        break;
        case 4:
        c_text=decryption(msg);
        break;
        case 0:
        break;
        default:
        printf("\nplease enter valid choice\n");
        break;
    }
    }while(choice!=0);
    }
    
    

	
char *Encription(char str[],int k)	

    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)//For loop including an int i that will indicate the location. '\0' is white space indicator
        {
            if (str[i] >= 65 && str[i]<= 90) //if statment concluding if it is bwtewwn letter 'A' and letter 'Z' all in capitals
            {
                char ex = str[i]- 65 + 26; // So for example A is configured to number 26 as it is letter Ascii code 65
                ex = (ex+k) % 26;// ex = 26 then add the key (FOR EXAMPLE -1) this will create the number 25 then modulas(remiamder) of 26 = 25
                str[i] = ex + 65;// then 25 +65 = 90 which is ascii number for Z
            }
          
        
            
        }
    printf("%s\n", str);
return str;
    }
    
char *Decription(char str[],int k)
    
    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)//For loop including an int i that will indicate the location. '\0' is white space indicator
        {
            if (str[i] >= 65 && str[i]<= 90) //if statment concluding if it is bwtewwn letter 'A' and letter 'Z' all in capitals
            {
                char ex = str[i]- 65 + 26; // So for example A is configured to number 26 as it is letter Ascii code 65
                ex = (ex-k) % 26;// ex = 26 then add the key (FOR EXAMPLE -1) this will create the number 25 then modulas(remiamder) of 26 = 25
                str[i] = ex + 65;// then 25 +65 = 90 which is ascii number for Z
            }
          
        
            
        }
    printf("%s\n", str);

return str;
}

	char *encription(char cipher_text[])
    {
    int i,j;
        for(i=0; i<strlen(cipher_text); i++)
        {
            for(j=0; j<52; j++)
            {
                if(alpha[j]==cipher_text[i])
                {
                    cipher_text[i]=key[j];
                    break;
                }
            }
        }
    printf("Your encripted message: %s",cipher_text);
    
    return cipher_text;
    
    }
    
char *decryption(char cipher_text [])
    {
        int i,j;
        char cipher[200];
        strcpy(cipher,cipher_text);
            
                for(i=0; i<strlen(cipher_text); i++)
                {
                    for(j=0; j<52; j++)
                    {
                        if(cipher[i]==key[j])
                        {
                            cipher[i]=alpha[j];
                            break;
                            
                        }    
                    }
                }
                printf("\nEcripted Text %s",cipher);
    }
                printf("\n Decripted text %s",cipher);
    }
        
}