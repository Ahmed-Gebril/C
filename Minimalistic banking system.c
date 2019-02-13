//This program is a simple banking system that performs basic transactions using structs.


#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include <string.h>


struct banking{

        char first_name[20];
        char last_name[30];
        int account_no;
        double first_deposit;
        double current_deposit;


        };



int transactions(struct banking s1);


int details(struct banking s1 );


int details(struct banking s1 )
{

                        printf("Account Holder's name %s %s \t \n",s1.first_name,s1.last_name);
                        printf("Account number  %d\n", s1.account_no);
                        printf("Current Credit %lf \n",s1.current_deposit);

                    //    printf("Last login time %s",s1.time_str);


}


int transactions(struct banking s1)

{

    printf("\nEnter 1 to withdraw or 2 to deposit");

    int selection;
    scanf("%d",&selection);
    if (selection == 1)
    {
        printf("\nDeclare the amount to withdraw");
        double amount;
        scanf("%lf",&amount);
        if(amount>s1.current_deposit)
        {
            printf("Sorry, the amount requested is less than your balance");
        }
        else
            {
                s1.current_deposit-=amount;
                printf("\nTransaction completed\n");
                printf("%lf",s1.current_deposit);

            }



    }


     else if(selection==2)
     {
         printf("\nEnter amount to be deposited\n");
         double deposit_amount;
         scanf("%lf",&deposit_amount);
         s1.current_deposit+=deposit_amount;
         printf("\nTransaction Completed\n");
         printf("%\nlf",s1.current_deposit);


     }

}


int main()
{


    struct banking s1;
    printf("Enter 1 for an existing account or 2 for a new account");
    int choice;
    int c;


    scanf("%d",&choice);

    if (choice==2)
    {

    FILE*file=fopen("text.txt","w");

    if (file == NULL)

        {
            printf("Error in writing to the file!");

            return 1;

        }



    while(1)
    {

        printf("Enter the first name\n");
        scanf("%s",s1.first_name);
        printf("Enter last last name\n");
        scanf("%s",s1.last_name);
        printf("Enter the account number name\n");
        scanf("%d",&s1.account_no);
        printf("Declare the first deposit\n");
        scanf("%lf",&s1.first_deposit);


        fprintf(file,"%s\t %s \t%d \t %f \t \n",s1.first_name,s1.last_name,s1.account_no,s1.first_deposit);


        printf("Add Another Account(Y/N)\n");
        char ch=getch();
        if(ch=='N' || ch=='n')
        break;


    }
    fclose(file);

    }


     else if(choice==1)
     {

         FILE*file=fopen("text.txt","r");
         if (file == NULL)

         {
                printf("Error in reading the file");
                return 1;

         }


            int number;
            printf("Declare your account number");
            scanf("%d",&number);

            while (1)
        {


            fscanf(file,"%s\t %s \t %d \t %lf  \n",s1.first_name,s1.last_name,&s1.account_no,&s1.current_deposit);

            if(number==s1.account_no)
            {


                printf("\nEnter 1 for account details or 2 to perform a transaction\n");

                int choices;
                scanf("%d",&choices);

                if (choices==1)
                {

                        details(s1);
                }

                if(choices==2)

                {
                     transactions(s1);
                     fscanf(file," %lf \n",&s1.current_deposit);

                }


                    break;


            }
       //     details(s1.first_name, s1.last_name, s1.account_no,s1.current_deposit



         }
         fclose(file);


     }


    return 0;
}
