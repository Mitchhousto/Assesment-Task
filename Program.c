/* 
About -> 
In the "Assessment-Task" workspace it contains a c file "Program.c". This can be used to encrypt and decrypt a message.
The decryption and encryption is calculated through two different Caesar cipher methods of "Rotation" and "Substitution". 
A message can be written into the "input.txt" file in the workspace, then using the terminal will display a menu.
This menu will prompt you to the different cipher options, then when option is selected the message will be exactued. 
The decrypted or encrypted message will be then printed on the terminal interface and "Output.txt" file.
 
How to operate code -> 
- Write a message into the "input.txt" file.
-In the terminal first input "cd Assessment-Task" then (enter key) 
-Next line input "gcc Program.c" then (enter key),
-Next line input "./a.out" then (enter key). 
-A menu will be displayed along with the message printed on terminal interface.
-Input a number from option menu then (enter key).
-Rotation encryption and Rotation decryption will further prompt you with a key selection for the rotation cipher.
-Results will print to the terminal interface and "Output.txt" file when program is exited.

*/

#include <stdio.h>
#include <string.h>
//included <string.h> as  strcpy and strlen is used


char RotationEncryption(char [],int k);
// This function prototype initialises the encryption message with char string and int k is the key.
// The message is generated from the input.txt file and key from terminal interface menu.
// If this function is selected the return value is printed to terminal interface and Output.txt file.
char RotationDecryption(char [],int k);
// This function prototype initialises the decryption message with char string and int k is the key.
// The message is generated from the input.txt file and key from terminal interface menu.
// If this function is selected the return value is printed to terminal interface and Output.txt file.
char SubstitutionEncryption(char []);
// This function prototype initialises the encryption message with the char string written in input.
// The message is generated from the input.txt file and key from terminal interface menu.
// If this function is selected the return value is printed to terminal interface and Output.txt file.
char SubstitutionDecryption(char []);
// This function prototype initialises the decryption message with the char string written in input.
// The message is generated from the input.txt file and key from terminal interface menu.
// If this function is selected the return value is printed to terminal interface and Output.txt file.
char library[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; 
//A char string that is for locating a character used in the message, this then gives that a location number in the library for that character.
char key[]="QWERTYUIOPASDFGHJKLZXCVBNMQWERTYUIOPASDFGHJKLZXCVBNM";
// This is they key string to align with the location of the Library. 


int main()
    {
        
	char message[1000],copy[1000];
	   // "message" is string of type char which is passed from the input message "input.txt" which can only be 1000 characters in length
	   // "copy" is string of type char which is created as a copy of the return string of message, for the purpose of the Rotation cipher attack.
	int choice,k,y;
	    //"choice" is the integer for declaring the menu option in the do while loop. 
            //"k" is the key number for the rotation cipher.
	    //"y" is an integer for the "for"  loop of the brute force attack for rotation cipher
	FILE *input,*output;
            // These are a pointer to two streams. "input" a stream where the message being read. "output" a stream for the message to be written. 
	input = fopen("input.txt","r");
	    // A prototype which opens the file "fopen"then "input.txt" and mode (r for read) arguments of to which the data is being used and accsessed.   
	output = fopen("Output.txt","w");
            // A prototype which opens the file "fopen"then "Output.txt" and mode (w for write) arguments of to which the data from the program will be printed.      
        fscanf(input,"%[^\n]",message);
            //Scans the message in the input file, the "%[^\n]" is a identifier that ignores white space, Passes the input file to message.
        printf("\nMessage: %s\n",message);
            //Prints out the message from input file on terminal interface.
        

        do
        {
        printf("\nPress 1 --> ROTATION ENCRYPTION \nPress 2 --> ROTATION DECRYPTION\nPress 3 --> SUBSTITUTION ENCRYPTION\nPress 4 --> SUBSTITUTION DECRYPTION\nPress 5 --> ROTATION CIPHER ATTACK\nPress 6 --> SUBSTITUION CIPHER ATTACK\nPress 0 --> EXIT\n");
        scanf("%d",&choice);
        // a Do while loop so the menu appears every execution. Multiple choices with integer "choice" inputed in the menu for your selected cipher.
            switch(choice)
            {
            //Switch flow control for the menu, intitialed by user inputing a integer "choice". This will activate the selected case and execute the commands.
                case 1:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    //User inputs integer "1" in to menu. That then activates case 1, followed by a message for user to enter a key for the rotation cipher
                    RotationEncryption(message,k);
                    //Message string from "Input.txt" and key is passed to the function "char RotationEncryption(char [],int k);"
                    printf("\nKEY : %d ---> Encripted message: %s\n", k, message);
                    fprintf(output,"%s\n",message);
                    //The string and integer from the function "RotationEncryption" are printed to both the screen and the "Output.text file"
                        break;
                  
                    
                case 2:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    //User inputs integer "2" in to menu. That then activates case 2, followed by a message for user to enter a key for the rotation cipher
                    RotationDecryption(message,k);
                    //Message string from "Input.txt" and key is passed to the function "char RotationDecryption(char [],int k);"
                    printf("\nKEY : %d ---> Decripted message: %s\n",k, message);
                    fprintf(output,"%s\n",message);
                    //The string and integer from the function "RotationDecryption" are printed to both the screen and the "Output.text file"
                    break;
                    
                    
                case 3:
                    SubstitutionEncryption(message);
                    //User inputs integer "3" in to menu. That then activates case 3. Message string from "Input.txt" and key is passed to the function "char SubstitutionEncryption(char []);"
                    printf("\nEncripted message: %s\n",message);
                    printf("\nKEY : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n      ||||||||||||||||||||||||||\n      QWERTYUIOPASDFGHJKLZXCVBNM\n ");         
                    fprintf(output,"%s\n",message);
                    //The string and integer from the function "SubstitutionEncryption" are printed to both the screen and the "Output.text file"
                        break;
                    
                case 4:
                    SubstitutionDecryption(message);
                    //User inputs integer "4" in to menu. That then activates case 4. Message string from "Input.txt" and key is passed to the function "char SubstitutionDecryption(char []);"
                    printf("\nDecripted message: %s\n",message);
                    printf("\nKEY : QWERTYUIOPASDFGHJKLZXCVBNM\n      ||||||||||||||||||||||||||\n      ABCDEFGHIJKLMNOPQRSTUVWXYZ\n "); 
                    fprintf(output,"%s\n",message);
                    //The string and integer from the function "SubstitutionDecryption" are printed to both the screen and the "Output.text file"
                        break;
                    
                case 5:
                    
                    strcpy(copy,message);
                    for(y=1;y<=26;++y)
                    {
                        RotationDecryption(message,y);
                        printf("\nKey : %d ---> %s\n",y,message);
                        fprintf(output,"Key : %d ---> %s\n",y,message);
                        strcpy(message,copy);
                        //Implementing a brute force attack on a rotation cipher, first by copying the message to a string called copy.
                        //This copy is essential as it writes a new temp string every cycle of the "for" loop being exicuted.
                        //The "RotationDecryption" function is used to initialise the rotation for a decrypted message.
                        //A "string copy(strcpy)" is used to pass the new encrypted message in "copy" to "message" to re-enter the cycle for the next key shift.
                        //The "for" loop has only 26 results for 26 letters in the alphabet.
                    }

                    break;
                    
                case 6:
                    printf("UNDER CONSTRUCTION");
                    break;
                    // code unfinished so prints a "UNDER CONSTRUCTION" note
                case 0:
                        break;
                    //When a '0' is initialised it quits the Do-while loop
                default:
                    printf("\nPLEASE ENTER A VALID CHOICE\n");
                        break;
                    //If a number between 7-infinity is chosen. Implimets a "please enter a valid choice" and re-prints the loop
            }
            
        }
        while(choice!=0 );
        //While loop conditons (choice not equal to 0). "0" being the exit number in menu.
       
   }


 
char RotationEncryption(char str[],int k)	

    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)
        //"For" loop including an integer "i" that will indicate character location in string. 
        //The argument is that at a white space "\0", the "for" loop will quit and move "i++" onto the next character in the string.       
        {
            if (str[i] >= 65 && str[i]<= 122) 
            //"if" statement searchs for letter characters 'A' and letter 'z' using Ascii index.
            {
                if(str[i] >= 97 && str[i]<= 122)
                //"if" statement to find all lowercase numbers.
                {                   
                    char ex = str[i]- 65 + 26 -32; 
                    //"-32" in formula is to modify lowercase to Uppercase.
                    // So "A" being Uppercase it is assigned a number of 26. Its Ascii code is assigned number 65, so minus 65 = 0 then + 26(characters in alphabet).
                    ex = (ex+k) % 26;
                    // Example for character "A". First ex = 26 then add the "key" (inputed in menu for example -1) this will create the number 25 then modulas(remainder) of 26 = "25"
                    str[i] = ex + 65;
                    // then 25 + 65 = 90 which is ascii number for Z
                }
                else
                //All other Uppercase characters are executed.
                { 
                    char ex = str[i]- 65 + 26; 
                  // So "A" being Uppercase it is assigned a number of 26. Its Ascii code it is assigned number 65, so minus 65 = 0 then + 26(characters in alphabet).
                    ex = (ex+k) % 26;
                    // Example for character "A". First ex = 26 then add the key (inputed in menu for example -1)) this will create the number 25 then modulas(remiamder) of 26 = "25"
                    str[i] = ex + 65;
                    // then 25 +65 = 90 which is ascii number for Z
                }

            }

           
        }
        
            return str[i],k;
            //The return of the function of the new string message and the key to be printed.
    }
    
char RotationDecryption(char str[],int k)
    
    {
        int i = 0;
        
        for(i=0;str[i] != '\0';i++)
        //"For" loop including an integer "i" that will indicate character location in string. 
        //The argument is that at a white space "\0", the "for" loop will quit and move "i++" onto the next character in the string.
        {
            if (str[i] >= 65 && str[i]<= 122) 
            //"if" statement search for letter characters 'A' and letter 'z' using Ascii index.
            {
                if(str[i] >= 97 && str[i]<= 122)
                //"if" statement to find all lowercase numbers.
                {
                char ex = str[i]- 65 + 26-32; 
                ///"-32" in formula is to modify lowercase to Uppercase.
                // // So for example "Z" is assigned to number "51" as it is Ascii code 90. Then 90 - 65 + 26 = "51"
                ex = (ex-k) % 26;
                 // ex =  51 then minus the key (FOR EXAMPLE -1) this will create the number 52 then modulas(remiamder) of 26 = 0
                str[i] = ex + 65;
                // then 0 + 65 = 65 which is Ascii number for "A"
                 }

                else
                //All other Uppercase characters are executed.
                {
                char ex = str[i]- 65 + 26; 
                // So for example "Z" is assigned to number "51" as it is Ascii code 90. Then 90 - 65 + 26 = "51"
                ex = (ex-k) % 26;
                // ex =  51 then minus the key (FOR EXAMPLE -1) this will create the number 52 then modulas(remiamder) of 26 = 0
                str[i] = ex + 65;
                // then 0 + 65 = 65 which is Ascii number for "A" 
                }
            }
        }
        
            return str[i],k;
             //The return of the function of the new string message and the key to be printed.
    }

char SubstitutionEncryption(char message[])

    {
        int i,j;
        
        for(i=0; i<strlen(message); i++)
        //"for" loop used to cycle through each character of the message string, loop quits when the string length of "message" is reached.
        {
            for(j=0; j<strlen(library); j++)
            //To loop each character of the library at equal time to the message string "for" loop.
            {
                if(library[j]==message[i])
                //"if" statement that locates same characters in  the "message" string and "library" string. 
                //This assigns a location number e.g  "A" in message to "A" in library  signed to location 1        
                {
                    message[i]=key[j];
                    // Character location in the "library" is then passed to the character location of the "key".
                    // This location assigns a letter in the "key" and  passed to new "message"  string as a encrypted message.
                    break;
                }
            } 
        }
    
    return message[i];
     //The return of the function of the new string message to be printed.
    }
    
char SubstitutionDecryption(char message[])
    {
        int i,j;
    
        for(i=0; i<strlen(message); i++)
        //"for" loop used to cycle through each character of the message string, loop quits when the string length of "message" is reached.
        {
                for(j=0; j<strlen(library); j++)
                //To loop each character of the library at equal time to the message string "for" loop.
                {
                      
                    if(key[j]==message[i]) 
                    // This "if" statement executes when a character in the "message" string is  the same location as the "key" string.
                    // The encryted "message" string has a "Q" this is then allocated a character position 1 in the "Key" string
                    {
                        message[i]=library[j];
                        // Character location in the key is then passed to the character location of the Libary.
                        // This character location assigns a character in the "library" and  passed to new "message" string as a decrypted message.
                        // The character location of "Q"= 1, the same character location in Library is "A".
                        break;
                           
                    }    
                }
        }               
        return message[i];
        //The return of the function of the new string message to be printed.
    }










