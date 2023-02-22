#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(){
system("color 8F");
int pin=123456,option, enteredPin, count=0,amount=1;
float balance=100000;
int continueTransaction=1;

time_t now;
time(&now);
printf("\n");
printf("\t\t\t\t\t    %s",ctime(&now));
printf("\n\t\t\t ==================*Welcome to  Global IME Bank Ltd. ATM*===============");

while(pin!=enteredPin){
    printf("\nPlease enter you pin: ");
    scanf("%d",&enteredPin);
    if(enteredPin!=pin){
        Beep(610,500);
        printf("Invalid pin!!!");
    }
    count++;
    if(count==3&& pin!=enteredPin){
        exit(0);
    }

}

char cont='y' ;
	

	if(cont=='y'){
while(continueTransaction!=0){
    printf("\n\t\t\t======================*Available Transaction*===================");
    printf("\n\t\t. Withdrawl");
    printf("\n\t\t. Deposite");
    printf("\n\t\t. Check Balance");
printf("\n\n\t Please select the option: ");
scanf("%d",&option);
switch(option){
case 1:
    while(amount%500!=0){
        printf("\n\t\tEnter the amount: ");
        scanf("%d",&amount);
        if(amount%500!=0)
        printf("\n\t The amount should be multiple of 500.");
    }
if(balance<amount){
    printf("\n\t Sorry Insufficient Balance");
    amount=1;
    break;
}
else{
    balance-=amount;
    printf("\n\t\tYou have withdrawn Rs%d. Your New Balance Rs%.2f",amount,balance);
    printf("\n\t\t==============Thank You for Banking with Global IME Bank Ltd.============");
    printf("\n\t\tFor Any Queries \n\t\t Please Contact Card Center");
    printf("\n\t\t Phone No: 4568756, 4568235,4678345");
    amount=1;
    Beep(500,500);
    Beep(500,450);
    Beep(500,450);
    break;
}
case 2:
printf("\n\t\t Please Enter the amount: ");
scanf("%d",&amount);
balance+=amount;

printf("\n\t\tYou have deposited Rs %d.Your new balance is Rs%.2f",amount,balance);
printf("\n\t\t==============Thank You for Banking with Global IME Bank Ltd.============");
printf("\n\t\tFor Any Queries \n\t\t Please Contact Card Center");
    printf("\n\t\t Phone No: 4568756, 4568235,4678345");
amount=1;
break;
case 3:
    printf("\n\t\tYour balance is Rs%.2f",balance);
    printf("\n\n\t\tFor Any Queries \n\t\t Please Contact Card Center");
    printf("\n\t\t Phone No: 4568756, 4568235,4678345");
	
	Beep(400,250);
	Beep(400,250);
	break;
default:
    Beep(610,500);
    printf("\n\t\t Invalid option!!!");
printf("\n\t\tFor Any Queries \n\t\t Please Contact Card Center");
    printf("\n\t\t Phone No: 4568756, 4568235,4678345");

}
printf("\n\t\t Do you wish to perform another transaction?\n\n\t\t Press 1[yes],0[no]: ");
scanf("%d",&continueTransaction);
}
}else{
	exit(0);
}


return 0;
}
