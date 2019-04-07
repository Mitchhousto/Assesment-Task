#include <stdio.h>

char *encription(char []);
void *decryption(char []);
char alpha[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
char key[26]="QWERTYUIOPASDFGHJKLZXCVBNM";


void main()
    {
    char message[]="PLEASE GET MILK AT THE SHOPS";
    encription(message);
    decryption(message);
    } 
    
char *encription(char cipher_text[])
    {
    int i,j;
        for(i=0; i<strlen(cipher_text); i++)
        {
            for(j=0; j<26; j++)
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
    
void *decryption(char cipher_text [])
    {
        int i,j;
        //char cipher[255];
        //cipher=cipher_text;
            
                for(i=0; i<255; i++)
                {
                    for(j=0; j<26; j++)
                    {
                        if(cipher_text[i]==key[j])
                        {
                            cipher_text[i]=alpha[j];
                            break;
                            
                        }    
                    }
                }
                printf("\n Decripted text %s",cipher_text);
    }
        
    