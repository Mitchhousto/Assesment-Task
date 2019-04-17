/* Assesment-Task workspace contains a c file "Testing.c". This can be used to encript and decript a message using two different ceaser cipher 
methods of "Rotation" and "Substitution". A message can be wirtten into the "input.txt" file in the workspace, then usinng the terminal will 
prompt a meanu. So in terminal first input "cd Assesment-Task" then (enter key) next line input "gcc Testing" then (enter key), next line
input "./a.out" then (enter key). A meau will be displayed along with the message printed. Input number of which option suitable. Rotation
enription and decription will further prompt you with a key selection for the rotation cipher.
*/

#include <stdio.h>
#include <string.h>
//included <string.h> as we use strcpy and strlen 


char *RotationEncription(char [],int k);
// This function prototype initialises the encription message with char string and int k is the key
char *RotationDecription(char [],int k);
// This function prototype initialises the decription message with char string and int k is the key
void RDBF(char arr[],int key);
//
char *SubstitutionEncription(char []);
// This function prototype initialises the encription message with the char string written in input
char *SubstitutionDecryption(char []);
// This function prototype intitialises the decription message with the char string written in input
char library[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
// Sets the string location for the libary of characters to be converted by the key 
char key[]="QWERTYUIOPASDFGHJKLZXCVBNM";
// This is they key to align with the  location of the Libary 


int main()
    {
        FILE *input;
        // This declares the stream for input source
        FILE *output;
	char copy[100];
	int b;
	
	char msg[250];
	// Declaring a string of type char which can only be 250 characters in length
	int choice,k;
	//"choice" is the integer for declaring the menu option in the do while loop. "K" is the key number for the rotation cipher
	input = fopen("input.txt","r");
	output = fopen("Output.txt","w");
        // A prototype which states the file name"input.txt" and mode (r for read) arguments.        
        printf("Enter message: ");
        //Prints out the message
        fscanf(input,"%[^\n]",msg);
        //Scans the message in the input file, the "%[^\n]" is a identifier that ignores white space, Passes the input file to msg.
        printf("%s",msg);
        // Prints the message written in the 
         
       


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
                    printf("\nEncripted message: %s\n", msg);
                    fprintf(output,"%s\n",msg);
                        break;
                    // Rotaion encription prototype initialiser, promt for a key for the cipher when integer "choice" is inputed a 1
                    
                case 2:
                    printf("Enter a key:");
                    scanf("%d",&k);
                    RotationDecription(msg,k);
                    printf("\nDecripted message: %s\n", msg);
                    fprintf(output,"%s\n",msg);
                        break;
                    // Rotaion decription prototype initialiser, promt for a key for the cipher when integer "choice" is inputed a 2
                    
                case 3:
                    SubstitutionEncription(msg);
                    printf("\nEncripted message: %s\n",msg);
                    fprintf(output,"%s\n",msg);
                    
                        break;
                    // Substitution decription prototype initialiser, sets string msg
                case 4:
                    SubstitutionDecryption(msg);
                    printf("\nDecripted message: %s\n",msg);
                    fprintf(output,"%s\n",msg);
                        break;
                    // Substitution decription prototype initialiser, sets string msg
                case 5:
                    
                    
                    strcpy(copy,msg);
                    for(b=1;b<=26;b++){
                    RDBF(msg,b);
                    printf("Bute Force key : %d ---> %s\n",b,msg);
                    fprintf(output,"%s\n",msg);
                    strcpy(msg,copy);
                    
                }

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


 
char *RotationEncription(char str[],int k)	

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
        
            return str;
    }
    
char *RotationDecription(char str[],int k)
    
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
        
            return str;
    }

char *SubstitutionEncription(char msg[])

    {
        int i,j;
        
        for(i=0; i<strlen(msg); i++)
        //To loop each character of the msg string, strlen quits when the strnig length og msg is reached
        {
            for(j=0; j<strlen(library); j++)
            //To loop each character of the libary at equal time to the msg string
            {
                if(library[j]==msg[i])
                //if statement to find characters in msg   libary e.g A in message to A in libary          
                {
                    msg[i]=key[j];
                    //This intiiates the same location in the msg to the key
                    break;
                }
            } 
        }
    
    
        return msg;
    
    }
    
char *SubstitutionDecryption(char msg[])
    {
        int i,j;
        char cipher[strlen(msg)];
        strcpy(cipher,msg);
            
                for(i=0; i<strlen(msg); i++)
                {
                    for(j=0; j<strlen(library); j++)
                    {
                        if(cipher[i]==key[j])
                        {
                            cipher[i]=library[j];
                            strcpy(msg,cipher);
                            
                            break;
                           
                        }    
                    }
                }
                
            return msg;    
    }
void RDBF(char arr[],int key)
{
int i,j;
for(i=0;i<strlen(arr);i++){
    if(arr[i]==' ')
        continue;
    for(j=0;j<key;j++){
        arr[i]--;
        if(arr[i]<97 && arr[i] > 90)
            arr[i] = 122;
        if(arr[i] < 65)
            arr[i] = 90;

}}}










