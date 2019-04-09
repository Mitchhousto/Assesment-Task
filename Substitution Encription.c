#include <stdio.h>

char *encription(char []);
char *decryption(char []);
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
        for(i=0; i</*strlen(cipher_text)*/26; i++)
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
    
char *decryption(char cipher_text [])
    {
        int i,j;
        char cipher[255];
        strcpy(cipher,cipher_text);
            
                for(i=0; i<255; i++)
                {
                    for(j=0; j<26; j++)
                    {
                        if(cipher[i]==key[j])
                        {
                            cipher[i]=alpha[j];
                            break;
                            
                        }    
                    }
                }
                printf("\n Decripted text %s",cipher);
    }
        