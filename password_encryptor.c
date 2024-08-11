#include<stdio.h>
#include<stdlib.h>
void passwd_gen();

int main(){
	char passwd[100]; //char array for store user input (pasword)
	int error = 0, count = 0, num = 0, i = 0;
	
	printf("------------- Welcome to DWQ agency! -------------\n\n");
	printf("Your password must have\n\t> Text with numbers and should contain at least one number..\n\t> Length between 6 and 9 characters..\n\n");

	do{
		count = 0; //store the number of numaric charactoers in the password
	    num = 0; //store the number of all characters in the password
		i = 0; 
		error = 0; //if there is an invalid length error recordds it
		
		//gett user input
		printf("Enter your password : ");
    	for(i = 0; i < 100; i++){
    		scanf("%c", &passwd[i]);
    		num++;
    		if(passwd[i] == 10){
    			break; // breaks the loop if the user inputs an enter
    		}
    	}
    	
    	printf("\nValidation....\n");
    	
        //count numeric characters in the password 
        for(i = 0; i < num - 1; i++){
    		if(passwd[i] >= '0' && passwd[i] <= '9'){
    			count++;
    		}
    	}
	    
	    //check for only numbers or not
    	if(count == num-1){
    		printf("Error! : Your password doesn't contaion any text.\n");
    		exit(1);
    	}
    	//check for containing numbers and text
    	else if(count != 0){
    		printf("Valid : Your password contains %d numbers\n", count);
    	}
    	//if password doesn't contain any number
    	else{
    		printf("Error! : Your password doesn't contaion any number.\n");
    		exit(1);
    	}
	
	    //check for invalid length
    	if(num >= 7 && num <= 10){
    		printf("Valid : Your password contains %d characters\n", num - 1);
    	}
    	else{
    		printf("Invalid : Your password contains %d characters\nTry again...\n\n", num - 1);
    		error = 1;
    	}
	}while(error == 1);
	
	printf("\nYou enterd your password successfully!\n\n");
	//call password generator function
	passwd_gen(num - 1,passwd);
	
	return 0;

}

//function for encrypting
void passwd_gen(int n, char passwd[n]){
	char tmp;
	int i = 0;
	
	for(i = 0; i < n; i++){
		//add 4 to all numaric values
    	if(passwd[i] >= '0' && passwd[i] <= '9'){
    		if(passwd[i] < '6'){
    			passwd[i] = passwd[i] + 4;
			}
    		else{
    			passwd[i] = (passwd[i] + 4) - 10; //if the number is grater than 6, it insert [(n + 4) - 10 ]
			}
    	}
		//make all simple letters capital
		else if(passwd[i] >= 97 && passwd[i] <= 122){
			passwd[i] = passwd[i] - 32 ;
		}
    }
    
    //declare a new array
    char temp[n + 2];
    
    //transfer all element in passwd array to the new array starting from index 1
    for(i = 1; i < n + 1; i++){
    	temp[i] = passwd[i - 1];
	}
    
    //insert '*' to the final index of the new array
    temp[i] = '*';
    
    //insert the length of the password to the 0th index
    int lng = n + 48;
	temp[0] = lng;
	
	//reverse the order of the array
	for(i = 0; i <= ((n + 2) / 2) ; i++){
     	tmp = temp[i];
     	temp[i] = temp[(n + 2) - i];
     	temp[(n + 2) - i] = tmp;
	}
	
	//print the new array
	printf("The encrypted password : ");
	for(i = 1; i < (n + 3) ; i++){
     	printf("%c", temp[i]);
	}
}
