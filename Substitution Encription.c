#include <stdio.h>

char *encription(char []);
//void *decryption(char []);
char alpha[26]="abcdefghijklmnopqrstuvwxyz";  
char key[26]="qwertyuiopasdfghjklzxcvbnm";


void main()
    {
    char message[26]="abcdefghijklmnopqrstuvwxyz";
     encription(message);
    
    } 
    
char *encription(char cipher_text[])
    {
    int i,j;
        for(i=0; i<26; i++)
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
    
/*void *decryption(char []);
    {
        int i,val,j;
        char cipher[255];
        strcpy(cipher,cipher_text);
            printf("\n Decription Process\n");
                for(i=0; i<strlen(cipher);i++)
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
    }*/