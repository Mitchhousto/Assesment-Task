/* Assesment-Task workspace contains a c file "Testing.c". This can be used to encript and decript a message using two different ceaser cipher 
methods of "Rotation" and "Substitution". A message can be wirtten into the "input.txt" file in the workspace, then usinng the terminal will 
prompt a meanu. So in terminal first input "cd Assesment-Task" then (enter key) next line input "gcc Testing" then (enter key), next line
input "./a.out" then (enter key). A meau will be displayed along with the message printed. Input number of which option suitable. Rotation
enription and decription will further prompt you with a key selection for the rotation cipher.
*/

#include <stdio.h>
#include <string.h>
//included <string.h> as we use strcpy and strlen 


void *RotationEncription(char [],int k);
// This function prototype initialises the encription message with char string and int k is the key
void *RotationDecription(char [],int k);
// This function prototype initialises the decription message with char string and int k is the key
void *SubstitutionEncription(char []);
// This function prototype initialises the encription message with the char string written in input
void *SubstitutionDecryption(char []);
// This function prototype intitialises the decription message with the char string written in input
char alpha[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";

int main()
    {
        FILE *input;
        FILE *output;
	
	
	static char msg[250];
	int choice,k;
	input = fopen("input.txt","r");
	output = fopen("Output.txt","w");
        
        printf("Enter message: ");
      
        fscanf(input,"%[^\n]",msg);
        
        printf("%s",msg);
    
        
        //fprintf(output,"%d",e);


        do
        {
        printf("\nPress 1 for Rotation encription \nPress 2 for Rotation decription\nPress 3 for substitution encription\nPress 4 for substitution decription\nPress 5 for Rotation cipher attack\nPress 6 for substituion cipher attack\nPress 0 for exit\n");
        scanf("%d",&choice);
    
            switch(choice)
            {
                case 1:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    RotationEncription(msg,k);
                        break;
                    
                case 2:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    RotationDecription(msg,k);
                        break;
                    
                case 3:
                    SubstitutionEncription(msg);
                        break;
                    
                case 4:
                    SubstitutionDecryption(msg);
                        break;
                case 5:
                    printf("Under construction");
                    break;
                case 6:
                    printf("Under construction");
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


 
void *RotationEncription(char str[],int k)	

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
    
void *RotationDecription(char str[],int k)
    
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

void *SubstitutionEncription(char cipher_text[])

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
    
 void *SubstitutionDecryption(char cipher_text [])
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
                return cipher_text;
    }
