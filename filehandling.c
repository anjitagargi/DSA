#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct books{
    int book_no;
    char book_name[50];
    char author[50];
    int book_pages;
    char stud_name[30];
    char book_issuedate[50];
    char book_duedate[50];
};

int main(){
    struct books book[50];
    int choice,n,i;

    char temp[40];

    do{

        printf("MENU\n");
        printf("PRESS1: To add book details\n");
        printf("PRESS2: To display all the book details\n");
        printf("PRESS3: To display a given book\n");
        printf("PRESS4: to add/ drop record\n");
         printf("PRESS5:Caculation of fine if book deposited after due date\n");
        printf("PRESS6: To Exit\n");

        printf("Enter any choice number from 1-5:");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                    printf("number of records to be added?");
                    scanf("%d",&n);
                    printf("Enter the details of book:\n");
                    for(i=0; i<=n ;i++){

                        printf("enter book no:");
                        scanf("%d", &book[i].book_no);
                        printf("enter book name:");
                        scanf("%d", &book[i].book_name);
                        printf("enter book author:");
                        scanf("%d", &book[i].author);
                        printf("enter no: of pages");
                        scanf("%d", &book[i].book_pages);
                        printf("enter name of the student:");
                        scanf("%d", &book[i].stud_name);
                        printf("enter the date of issue of book");
                        scanf("%d", &book[i].book_issuedate);
                        printf("enter the date of due of book");
                        scanf("%d", &book[i].book_duedate);
                    }
                    break;
            case 2:
                printf("Details of all book:");
                printf("BOOK NO: \t BOOK NAME \t AUTHOR NAME \t BOOK PAGES \t STUDENT NAME \t ISSUE DATE \t DUE DATE\n");
                for(i=0 ; i<n ; i++){
                    printf("%d \t %s \t %s \t %d \t %s \t %s \t %s \n", book[i].book_no,book[i].book_name,book[i].author,book[i].book_pages,book[i].stud_name,book[i].book_issuedate,book[i].book_duedate );
                }
                break;
            case 3:
                printf("Enter Author Name:");
                scanf("%s",&temp);
                for(i=0 ; i<n ; i++){
                    if(strcmp(book[i].author,temp)==0){
                        printf("%s", book[i].book_name);
                    }
                }
                break;

            case 4:
                    printf("Enter Author Name:");
                scanf("%s",temp);
                for(i=0; i,n ; i++){
                    if(strcmp(book[i].author,temp)==0){
                        if(book[i].book_duedate - book[i].book_issuedate == 0)
                        printf("NO FINE");
                        else
                        printf("%d",book[i].book_duedate - book[i].book_issuedate);
                    }
                }
                    break;
            case 6:
                Exit(0);

        }

    }while(choice!=6);
        return 0;}
