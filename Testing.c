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
char library[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
// Sets the string location for the libary of characters to be converted by the key 
char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
// This is they key to align with the  location of the Libary 


int main()
    {
        FILE *input;
        // This declares the stream for input source
        //FILE *output;
	
	
	char msg[250];
	// Declaring a string of type char which can only be 250 characters in length
	int choice,k;
	//"choice" is the integer for declaring the menu option in the do while loop. "K" is the key number for the rotation cipher
	input = fopen("input.txt","r");
	//output = fopen("Output.txt","w");
        // A prototype which states the file name"input.txt" and mode (r for read) arguments.        
        printf("Enter message: ");
        //Prints out the message
        fscanf(input,"%[^\n]",msg);
        //Scans the message in the input file, the "%[^\n]" is a identifier that ignores white space, Passes the input file to msg.
        printf("%s",msg);
        // Prints the message written in the 
        
        //fprintf(output,"%s",msg);


        do
        {
        printf("\nPress 1 for Rotation encription \nPress 2 for Rotation decription\nPress 3 for substitution encription\nPress 4 for substitution decription\nPress 5 for Rotation cipher attack\nPress 6 for substituion cipher attack\nPress 0 for exit\n");
        scanf("%d",&choice);
        // a Do while loop so the meanu appears every exicution. Multiple choices with integer "choice" inputed in the menu.
            switch(choice)
            {
            //Switch flow control for the menu intitialed by integer "choice"
                case 1:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    RotationEncription(msg,k);
                        break;
                    // Rotaion encription prototype initialiser, promt for a key for the cipher when integer "choice" is inputed a 1
                    
                case 2:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    RotationDecription(msg,k);
                        break;
                    // Rotaion decription prototype initialiser, promt for a key for the cipher when integer "choice" is inputed a 2
                    
                case 3:
                    SubstitutionEncription(msg);
                        break;
                    // Substitution decription prototype initialiser, sets string msg
                case 4:
                    SubstitutionDecryption(msg);
                        break;
                    // Substitution decription prototype initialiser, sets string msg
                case 5:
                    printf("Under construction");
                    break;
                    // code unfinished so prints a "under construction" note
                case 6:
                    printf("Under construction");
                    break;
                    // code unfinished so prints a "under construction" note
                case 0:
                        break;
                    //When a '0' is initialised it quits the Do-while loop
                default:
                    printf("\nplease enter valid choice\n");
                        break;
                    //If a number between 7-infinity is chosen. Implimets a "please enter a valid choice" and re-prints the loop
            }
            
        }
        while(choice!=0 );
        //While loop conditons (choice not equal to 0)
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
                if(library[j]==cipher_text[i])
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
                            cipher[i]=library[j];
                            break;
                            
                        }    
                    }
                }
                printf("\nDecripted message: %s\n",cipher);
                return cipher_text;
    }
