/* In the "Assessment-Task" workspace it contains a c file "Program.c". This can be used to encrypt and decrypt a message.
The decryption and encryption is calculated through two different Caesar cipher methods of "Rotation" and "Substitution". 
A message can be written into the "input.txt" file in the workspace, then using the terminal will display a menu. 
How to operate code -> In the terminal first input "cd Assessment-Task" then (enter key) 
next line input "gcc Program.c" then (enter key), next line input "./a.out" then (enter key). 
A menu will be displayed along with the message printed.
Input a number from option menu then (enter key).
Rotation encryption and Rotation decryption will further prompt you with a key selection for the rotation cipher.
Results will print to the terminal interface and "Output txt" file when program is exited.

*/

#include <stdio.h>

#include <string.h>
//included <string.h> as we use strcpy and strlen 


char RotationEncryption(char [],int k);
// This function prototype initialises the encryption message with char string and int k is the key.
char RotationDecryption(char [],int k);
// This function prototype initialises the decryption message with char string and int k is the key.
char SubstitutionEncryption(char []);
// This function prototype initialises the encryption message with the char string written in input.
char SubstitutionDecryption(char []);
// This function prototype initialises the decryption message with the char string written in input.
char library[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
// Sets the string location for the library of characters to be converted by the key 
char key[]="QWERTYUIOPASDFGHJKLZXCVBNMQWERTYUIOPASDFGHJKLZXCVBNM";
// This is they key string to align with the  location of the Library 


int main()
    {
        
	char message[250],copy[250];
	   // msg is string of type char which is passed from the input message. which can only be 250 characters in length
	   // copy is string of type char which is created as a copy of the return string of msg, for the purpose of the brute force attack.
	int choice,k,y;
	    //"choice" is the integer for declaring the menu option in the do while loop. 
            //"k" is the key number for the rotation cipher
	    //"y" is an integer for the "for"  loop of the brute force attack for rotation cipher
	FILE *input,*output;
            // These are a pointer to two streams. "input" a stream where the message being read. "output" a stream for the message to be written. 
	input = fopen("input.txt","r");
	   // A prototype which opens the file "fopen"then "input.txt" and mode (r for read) arguments of to which the data is being used and accsessed.6
	   
	output = fopen("Output.txt","w");
            // A prototype which states the file name "output.txt" and mode (w for write) arguments.        
        fscanf(input,"%[^\n]",message);
            //Scans the message in the input file, the "%[^\n]" is a identifier that ignores white space, Passes the input file to msg.
        printf("\nMessage: %s\n",message);
            //Prints out the message from input file
        

        do
        {
        printf("\nPress 1 --> ROTATION ENCRYPTION \nPress 2 --> ROTATION DECRYPTION\nPress 3 --> SUBSTITUTION ENCRYPTION\nPress 4 --> SUBSTITUTION DECRYPTION\nPress 5 --> ROTATION CIPHER ATTACK\nPress 6 --> SUBSTITUION CIPHER ATTACK\nPress 0 --> EXIT\n");
        scanf("%d",&choice);
        // a Do while loop so the meau appears every exicution. Multiple choices with integer "choice" inputed in the menu.
            switch(choice)
            {
            //Switch flow control for the menu intitialed by user inputing a integer "choice"
                case 1:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    //User inputs integer "1" case 1 is executed, following a message for user to enter a key for the rotation cipher
                    RotationEncryption(message,k);
                    printf("\nKEY --- %d Encripted message: %s\n", k, message);
                    fprintf(output,"%s\n",message);
                    //The string and integer from the function "RotationEncryption" are printed to both the screen and the "Output.text file"
                        break;
                  
                    
                case 2:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    ////User inputs integer "2" case 1 is executed, following a message for user to enter a key for the rotation cipher
                    RotationDecryption(message,k);
                    printf("\nDecripted message: %s\n", message);
                    fprintf(output,"%s\n",message);
                        break;
                    //The string and integer from the function "RotationDecryption" are printed to both the screen and the "Output.text file"
                    
                case 3:
                    SubstitutionEncryption(message);
                    printf("\nEncripted message: %s\n",message);
                    fprintf(output,"%s\n",message);
                    //The string and integer from the function "SubstitutionEncryption" are printed to both the screen and the "Output.text file"
                        break;
                    
                case 4:
                    SubstitutionDecryption(message);
                    printf("\nDecripted message: %s\n",message);
                    fprintf(output,"%s\n",message);
                        break;
                    //The string and integer from the function "SubstitutionDecryption" are printed to both the screen and the "Output.text file"
                case 5:
                    
                    strcpy(copy,message);
                    for(y=1;y<=26;y++)
                    {
                        RotationDecryption(message,y);
                        printf("Key : %d ---> %s\n",y,message);
                        fprintf(output,"Key : %d ---> %s\n",y,message);
                        strcpy(message,copy);
                        //Implementing a brute force attack on a rotation cipher, first by copying the message to a string called copy.
                        //This copy is essential as it creates a new string every cycle of the for loop.
                        //The "RotationDecryption" function is used to initialise the rotation for a decrypted message.
                        //A string copy is used to pass the new encrypted message in "copy" to "message" to re-enter the cycle for the next key shift.
                        //The for loop has only 26 results for 26 letters in the alphabet.
                    }

                    break;
                    // code unfinished so prints a "under construction" note
                case 6:
                    printf("UNDER CONSTRUCTION");
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


 
char RotationEncryption(char str[],int k)	

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
        
            return str[i],k;
    }
    
char RotationDecryption(char str[],int k)
    
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
        
            return str[i],k;
    }

char SubstitutionEncryption(char message[])

    {
        int i,j;
        
        for(i=0; i<strlen(message); i++)
        //To loop each character of the msg string, strlen quits when the string length or msg is reached
        {
            for(j=0; j<strlen(library); j++)
            //To loop each character of the libary at equal time to the msg string
            {
                if(library[j]==message[i])
                //if statement to find characters in msg   libary e.g A in message to A in libary          
                {
                    message[i]=key[j];
                    //This intiiates the same location in the msg to the key
                    break;
                }
            } 
        }
    
    return message[i];
    
    }
    
char SubstitutionDecryption(char message[])
    {
        int i,j;
    
        for(i=0; i<strlen(message); i++)
        // "for" loop to allocate a character location of msg
        {
                for(j=0; j<strlen(library); j++)
                // "for" loop to allocate a location in the key equal to the msg
                {
                      
                    if(key[j]==message[i]) 
                    // This "if" statement executes when a character in the message is  the same location as the key       
                    {
                        message[i]=library[j];
                        // Character location in the key is then passed to the character location of the Libary.
                        // This location assigns a letter in the libary and  passed to msg as a decripted message.
                        break;
                           
                    }    
                }
        }               
        return message[i];    
    }










