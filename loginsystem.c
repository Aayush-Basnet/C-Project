#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user{
char fullname[50];
char email[50];
char password[50];
char username[50];
char phone[50];

};
void takeinput(char ch[50]){
fgets(ch,50,stdin);
ch[strlen(ch)-1]=0;
}
/*
void generateUsername(char email[50],char username[50]){
//abc123@gmail.com
for(int i=0; i<strlen(email);i++){
    if(email[i]=='@') 
	break;
    else 
	username[i]=email[i];
}
*/
void generateUsername(char email[50], char username[50]) {
    //abc123@gmail.com
    int i;
    for (i = 0; email[i] != '@' && i < strlen(email); i++) {
        username[i] = email[i];
    }
    username[i] = '\0';
}



void takepassword(char pwd[50]){
int i=0;
char ch;
while(1){
    ch = getch();
    if(ch==ENTER || ch==TAB){
        pwd[i]='\0';
        break;
    }else if(ch==BCKSPC){
    if(i>0){
        i--;
        printf("\b \b"); //abc
    }
    }else {
    pwd[i++]=ch;
    printf("* \b");
    }

}
}

int main(){
    system("color 0B");
    FILE*fp;

int opt,usrFound=0;
struct user user;
char password2[50];
struct user usr;
 char username[50],pword[50];

printf("\n\t\t\t\t----------Welcome to authentication system----------");
printf("\nPlease choose your operation");
printf("\n1.Signup");
printf("\n2.Login");
printf("\n3.Exit");

printf("\n\n Your choice: \t");
scanf("%d",&opt);
fgetc(stdin);

switch(opt)
{
    case 1:
        system("cls");
        printf("\nEnter your full name: \t");
        takeinput(user.fullname);
        printf("Enter your email: \t");
        takeinput(user.email);
        printf("Enter your contact number: \t");
        takeinput(user.phone);
        printf("Enter your password: ");
        takepassword(user.password);
        //printf("%s",user.password);
        printf("\nConfirm your password: \t");
        takepassword(password2);

      /*  if(!strcmp(user.password,password2)){
           generateUsername(user.email,user.username);
           fp=fopen("Users.dat","a+");
           fwrite(&user,sizeof(struct user),1,fp);
           if(fwrite!=0) printf("\n\n User registration success, Your username is %s",user.username);
           else printf("\n\n Sorry! Something went wrong :(");
        fclose(fp);
        }else {
        printf("\n\nPassword Incorrect");
        Beep(450,300);
        }
      */  
      if (!strcmp(user.password, password2)) {
	  
    generateUsername(user.email, user.username);
    fp = fopen("Users.dat", "a+");
    if (fp == NULL) {
        printf("\n\n Failed to open file :(");
        return 1;
    }
    if (fwrite(&user, sizeof(struct user), 1, fp) < 1) {
        printf("\n\n Failed to write to file :(");
}
fclose(fp);
   printf("\n\n User registration success, Your username is %s",user.username);
            } else {
                printf("\n\nPassword Incorrect");
                Beep(450,300);
            }
        break;

case 2:
   
   
        printf("\nEnter your username: \t");
        takeinput(username);
        printf("Enter your password: \t");
        takepassword(pword);
        system("cls");

        fp=fopen("Users.dat","r");
        while(fread(&usr,sizeof(struct user),1,fp)){
            if(!strcmp(usr.username,username)){
                if(!strcmp(usr.password,pword)){
                    printf("\n\t\t\t\t\t\t\t\tWelcome %s",usr.fullname);
                    printf("\n\n Full Name: \t%s",usr.fullname);
                    printf("\n Email: \t%s",usr.email);
                    printf("\n Username: \t%s",usr.username);
                    printf("\n Contact No.: \t%s",usr.phone);
                }else{
                    printf("\n\n Invalid Password!");
        Beep(800,350);
                }
                usrFound=1;
            }
        }
        if(!usrFound){
            printf("\n\n User is not registered!");
        Beep(800,350);
        }
        fclose(fp);
        break;

case 3:
    printf("\t\t\t Bye Bye :)");

}

return 0;

}

