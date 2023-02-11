#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

//FUNCTION DECLERATION //
void signup(user a);
void balancecheck(user usr);
FILE *deposit(char filenamee[]);
FILE *withdraw(char filenamee []);



// GLOBAL VARAIBLE //
FILE *fp;
char filename[50],phone[50],pword[50];
struct user usr,usr1;




//MAIN FUNVTION RUNNING 
int main(){
	
	
//    FILE *fp;
//    char filename[50],phone[50],pword[50];
    int opt,choice;
    char cont = 'y';

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register an account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\t");
    scanf("%d",&opt);

    if(opt == 1){
        system("cls");
        signup(usr);
    }
    if(opt == 2){
        system("cls");
        printf("\nPhone number:\t");
        scanf("%s",phone);
        printf("Password:\t");
        scanf("%s",pword);
        strcpy(filename,phone);
        fp = fopen(strcat(filename,".dat"),"r");
        if(fp == NULL){
            printf("\nAccount number not registered");
        }
        else {
        fread(&usr,sizeof(struct user),1,fp);
        fclose(fp);
        if(!strcmp(pword,usr.password)){
            printf("\n\t\tWelcome %s",usr.phone);;
            while(cont == 'y'){
                system("cls");
                printf("\n\nPress 1 for balance inquiry");
                printf("\nPress 2 for depositing cash");
                printf("\nPress 3 for cash withdrawl");
                printf("\n\nYour choice:\t");
                scanf("%d",&choice);

                switch(choice){
                    case 1:
                      balancecheck(usr);
                        break;
                    case 2:
                        deposit(filename);
                        break;
                    case 3:
                        withdraw(filename);
                        break;
                default:
                    printf("\nInvalid option");
                }


                printf("\nDo you want to continue the transaction [y/n]\t");
                scanf("%s",&cont);

            }
        }
        else {
            printf("\nInvalid password");
        }
        }

    }
    
    
    
    
   


    return 0;
}

//signup function

 void signup(user usr){
// 	    FILE *fp;
//        char filename[50],phone[50],pword[50];
    	system("cls");
        printf("Enter your account number:\t");
        scanf("%s",usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s",usr.phone);
        printf("Enter your new password:\t");
        scanf("%s",usr.password);
        usr.balance = 0;
        strcpy(filename,usr.phone);
        fp = fopen(strcat(filename,".dat"),"w");
        fwrite(&usr,sizeof(struct user),1,fp);
        if(fwrite != 0){
            printf("\n\nAccount succesfully registered");
        }else {
            printf("\n\nSomething went wrong please try again");
        }
        fclose(fp);
	}
	
	
	void balancecheck(user usr){
		
		  printf("\nYour current balance is Rs.%.2f",usr.balance);
		
	}
	
//deposit funtion

FILE *deposit(char filenamee []){
		
		 printf("\nEnter the amount:\t");
		                float amount;
                        scanf("%f",&amount);
                        usr.balance += amount;
                        fp = fopen(filenamee,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nSuccesfully deposited.");
                        fclose(fp);
                        return fp;
                    
		
	}
	
//withdraw function	
FILE *withdraw(char filenamee []){
		printf("\nEnter the amount:\t");
	                	float amount;
                        scanf("%f",&amount);
                        usr.balance -= amount;
                        fp = fopen(filenamee,"w");
                        fwrite(&usr,sizeof(struct user),1,fp);
                        if(fwrite != NULL) printf("\nYou have withdrawn Rs.%.2f",amount);
                        fclose(fp);
                        return fp;
	}
