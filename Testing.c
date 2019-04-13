#include <stdio.h>
#include <string.h>

void *Encription(char [],int k);	
void *Decription(char [],int k);
void *encription(char []);
void *decryption(char []);
char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";

int main()
    {
        FILE *input;
	char *c_text,msg[250];
	int choice,k;
        printf("Enter message: ");
        scanf("%[^\n]",msg);
    
    
        do
        {
        printf("\nPress 1 for Rotation encription \nPress 2 for Rotation decription\nPress 3 for substitution encription\nPress 4 for substitution decription\nPress 0 for exit\n");
        scanf("%d",&choice);
    
            switch(choice)
            {
                case 1:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    c_text=Encription(msg,k);
                        break;
                    
                case 2:
                    printf("Enter a key:");
                    scanf("%d",&k);
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
            
        }
        while(choice!=0 );
    }
    
 
void *Encription(char str[],int k)	

    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)
        //For loop including an int i that will indicate the location. '\0' is white space indicator
        {
            if (str[i] >= 65 && str[i]<= 90) 
            //if statment concluding if it is bwtewwn letter 'A' and letter 'Z' all in capitals
            {
                char ex = str[i]- 65 + 26; 
                // So for example A is configured to number 26 as it is letter Ascii code 65
                ex = (ex+k) % 26;
                // ex = 26 then add the key (FOR EXAMPLE -1) this will create the number 25 then modulas(remiamder) of 26 = 25
                str[i] = ex + 65;
                // then 25 +65 = 90 which is ascii number for Z
            }
        }
        printf("\nEncripted message: %s\n", str);
            return str;
    }
    
void *Decription(char str[],int k)
    
    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)
        //For loop including an int i that will indicate the location. '\0' is white space indicator
        {
            if (str[i] >= 65 && str[i]<= 90) 
            //if statment concluding if it is bwtewwn letter 'A' and letter 'Z' all in capitals
            {
                char ex = str[i]- 65 + 26; 
                // So for example A is configured to number 26 as it is letter Ascii code 65
                ex = (ex-k) % 26;
                // ex = 26 then add the key (FOR EXAMPLE -1) this will create the number 25 then modulas(remiamder) of 26 = 25
                str[i] = ex + 65;
                // then 25 +65 = 90 which is ascii number for Z
            }
        }
        printf("\nDecripted message: %s\n", str);
            return str;
    }

void *encription(char cipher_text[])

    {
        int i,j;
        
        for(i=0; i<strlen(cipher_text); i++)
        //
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
    printf("\nEncripted message: %s\n",cipher_text);
    
        return cipher_text;
    
    }
    
void *decryption(char cipher_text [])
    {
        int i,j;
        char cipher[strlen(cipher_text)];
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
                printf("\nDecripted message: %s\n",cipher);
    }
