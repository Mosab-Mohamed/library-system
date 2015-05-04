#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

struct {
   char title[60];
   char auther[40];
   char publisher[60];
   char ISBN[20];
   char day_of_pub[10];
   char month_of_pub[10];
   char year_of_pub[10];
   char n_OF_copies[10];
   int C_A_N_Of_Copies;
   char category[40];
   }book;

   struct BooksList{
   char title[60];
   char auther[40];
   char publisher[60];
   char ISBN[30];
   char Date_Of_Publication[20];
   char n_OF_copies[10];
   char C_A_N_Of_Copies[10];
   char category[40];
   char state[5];
   char borrow_state[5];
   }BookSearch[2000];

   struct members {
    char ID[5];
    char FirstName[20];
    char LastName[20];
    char adress[80];
    char street[80];
    char state[5];
    char city[30];
    char phone[20];
    char age[5];
    char e_mail[40];
    char book_state[5];
    }Members_list[2000];

    struct{
    int ID;
    char FirstName[20];
    char LastName[20];
    char adress[80];
    char street[80];
    int state;
    char city[30];
    char phone[20];
    char age[5];
    char e_mail[40];
    }member;

    struct borrowing{
    char id[10];
    char ISBN[20];
    char year[10];
    char month[10];
    char day[10];
    char b_year[10];
    char b_month[10];
    char b_day[10];
    char return_year[10];
    char return_month[10];
    char return_day[10];
    char state[10];
    }borrowin_list[1000];

    struct {
    char id[10];
    char ISBN[20];
    char year[10];
    char month[10];
    char day[10];
    char b_year[10];
    char b_month[10];
    char b_day[10];
    int state;
    }borrow;

        struct SYSTEMTIME {
		WORD wYear;
		WORD wMonth;
		WORD wDayOfWeek;
		WORD wDay;
		WORD wHour;
		WORD wMinute;
		WORD wSecond;
		WORD wMilliseconds;
	} _SYSTEMTIME;

	int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


    void load_books();
    void load_members();
    void load_borrow();
    void add_book();
    void search_book();
    void add_new_copies();
    void delete_book();
    void add_member();
    void borrow_book();
    void book_back();
    void delete_member();
    void overdue_books();
    void most_popular();
    void admin();
    int quit();
    int isbn_val(char []);
    int phone_val(char []);
    int age_val(char []);
    int email_val(char []);
    int name_val(char []);
    int choice_val(char []);
    int number_val(char []);
    int choice_val1(char []);
    int choice_val2(char []);
    int match_val(char [],char []);
    int count_chars(char []);
    int february_val(char []);
    int year_val(char []);
    int month_val(char []);
    int day_val(char [],char []);
    int choice_val3(char []);
    void save_books();
    void save_members();
    void save_borrow();
    int year_val1(char []);
    int day_val1(char [],char []);
    int adress_val(char []);
    int isbn_uniqe_val(char []);

    FILE * BooksInformation;
    FILE * MembersInformation;
    FILE * borrow_file;



int main ()
{
    load_books();
    load_borrow();
    load_members();
    int i,ent_choice;
    char choice[5];
    printf("\t\t\t<<< welcome in my liberary system ^_^ >>>\n\n");
    do
    {
        printf("what's your action :- \n\
           \n\
0. add book\n\
1. search for book\n\
2. add new copies\n\
3. delete book\n\
4. add member\n\
5. delete member\n\
6. borrow book\n\
7. back a book\n\
8. admin\n\
9. exit \n\n");
        printf("enter your choice : ");
        gets(choice);
        while(choice_val(choice)==0)
        {
            printf("INVALID CHOICE !!!!\n");
            printf("REENTER YOUR CHOICE : ");
            gets(choice);
        }
        ent_choice=atoi(choice);
        printf("     ..____________________________________________..\n\n");
        switch(ent_choice)
        {
        case 0 : add_book();break;
        case 1 : search_book();break;
        case 2 : add_new_copies();break;
        case 3 : delete_book();break;
        case 4 : add_member();break;
        case 5 : delete_member();break;
        case 6 : borrow_book();break;
        case 7 : book_back();break;
        case 8 : admin();break;
        case 9 : return 0;
        default :printf("incorrect entry !!\n\n"); break;
        }
    }while(ent_choice!=9);
}

void add_book()
{
    int i,choice=1;
    char B_information[200],finish[5];
    while(choice!=0)
    {
        printf("enter your book title : ");
        gets (book.title);
        while(adress_val(book.title)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter the book's title : ");
                gets(book.title);
        }
        printf("enter the name of the auther : ");
        gets (book.auther);
        while(adress_val(book.auther)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter the book's auther : ");
                gets(book.auther);
        }
        printf("enter publisher name : ");
        gets (book.publisher);
        while(adress_val(book.publisher)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter publisher : ");
                gets(book.publisher);
        }
        printf("enter the book's ISBN (It should have 13 num , 4 dashes <not followed> ): ");
        gets(book.ISBN);
        while(isbn_uniqe_val(book.ISBN)==0)
        {
                printf("Repeated or Invalid ISBN !!!\n");
                printf("reenter the book's ISBN (It should have 13 num , 4 dashes <not followed> ): ");
                gets(book.ISBN);
        }
        printf("enter year Of Publication : ");
        gets (book.year_of_pub);
        while(year_val(book.year_of_pub)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter year : ");
                gets(book.year_of_pub);
        }
        printf("enter month Of Publication : ");
        gets (book.month_of_pub);
        while(month_val(book.month_of_pub)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter months : ");
                gets(book.month_of_pub);
        }
            printf("enter day Of Publication : ");
            gets (book.day_of_pub);
            while(day_val(book.day_of_pub,book.month_of_pub)==0)
            {
                    printf("Invalid entry !!!\n");
                    printf("reenter day : ");
                    gets(book.day_of_pub);
            }
        printf("enter the number of copies : ");
        gets(book.n_OF_copies);
        while(number_val(book.n_OF_copies)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter the number of copies : ");
                gets(book.n_OF_copies);
        }
        book.C_A_N_Of_Copies=atoi(book.n_OF_copies);
        printf("enter the category of the book : ");
        gets (book.category);
        while( adress_val(book.category)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter category : ");
                gets(book.category);
        }
        sprintf(B_information,"%s,%s,%s,%s,%s-%s-%s,%s,%d,%s,1,0,\n",book.title,book.auther,book.publisher,book.ISBN,book.day_of_pub,book.month_of_pub,book.year_of_pub,book.n_OF_copies,book.C_A_N_Of_Copies,book.category);
        BooksInformation = fopen ("book information.txt","r");
        if(BooksInformation==NULL)
        {
            BooksInformation = fopen ("book information.txt","w");
            fputs (B_information,BooksInformation);
            fclose (BooksInformation);
        }else
        {
            BooksInformation = fopen ("book information.txt","a");
            fputs (B_information,BooksInformation);
            fclose (BooksInformation);
        }
        fclose (BooksInformation);
        load_books();
        printf("NEW BOOK HAS ADDED SUCCESSFULY....\n\n");
        printf("Do you want to add more books ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        choice=atoi(finish);
        printf("     ..____________________________________________..\n\n");
    }
    return;
}

void search_book()
{
    load_books();
    int i,Found=0,search_choice,current_num=0,counter=0,one=1,i_ISBN;
    char B_name[40],AUTH_name[40],B_category[40],B_ISBN[30],choice[5],* pch;
    printf("Which method do you want to search by ???\n");
    printf("1_ By book title.\n");
    printf("2_ By book ISBN.\n");
    printf("3_ By book Auther.\n");
    printf("4_ By book category.\n");
    printf("5_ Back.\n");
    printf("enter your choice : ");
    gets(choice);
    while(choice_val1(choice)==0)
        {
            printf("INVALID CHOICE !!!!\n");
            printf("REENTER YOUR CHOICE : ");
            gets(choice);
        }
        search_choice=atoi(choice);
        printf("     ..____________________________________________..\n\n");
        switch(search_choice)
        {
        case 1 :    printf("enter the name of the book you want to search : ");
                    gets (B_name);
                    while( adress_val(B_name)==0 )
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter the book's name : ");
                        gets (B_name);
                    }
                    for(i=0 ; i<2000 ;i++)
                    {
                        Found=0;
                        pch = strstr (BookSearch[i].title,B_name);
                        if(!(pch==NULL))
                        {
                            counter++;
                            Found=1;
                            current_num=atoi(BookSearch[i].C_A_N_Of_Copies);
                            if(Found && current_num)
                            {
                                if(one==1)
                                {
                                    printf("\nThis is a list of match books :-\n\n");
                                    one--;
                                }
                                printf("_ %s\n",BookSearch[i].title);
                            }
                        }
                    }
                    if(counter==0)
                        {
                            printf("the book is unavailable ( not in liberary or all copies are borrowed )....\n\n");
                        }
                    printf("     ..____________________________________________..\n\n");
                    break;
        case 3 : printf("enter the book authers's name : ");
                    gets(AUTH_name);
                    while( adress_val(AUTH_name)==0 )
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter the book's auther : ");
                        gets (AUTH_name);
                    }
                    for(i=0 ; i<2000 ;i++)
                    {
                        if(strcmp(AUTH_name,BookSearch[i].auther)==0)
                            printf("_ %s\n",BookSearch[i].title);
                    }
                    printf("<this is avalable books for this auther>\n");
                    printf("     ..____________________________________________..\n\n");
                    break;
        case 4 : printf("enter the category of the book : ");
                    gets(B_category);
                    while( adress_val(B_category)==0 )
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter the book's category : ");
                        gets (B_category);
                    }
                    for(i=0 ; i<2000 ;i++)
                    {
                        if(strcmp(B_category,BookSearch[i].category)==0)
                            printf("_ %s\n",BookSearch[i].title);
                    }
                    printf("<this is avalable books for this category>\n");
                    printf("     ..____________________________________________..\n\n");
                    break;
        case 2 : printf("enter ISBN of the book : ");
                    gets(B_ISBN);
                    while( isbn_val(B_ISBN)==0 )
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter the book's ISBN : ");
                        gets (B_ISBN);
                    }
                    for(i=0 ; i<2000 ;i++)
                    {
                        if(strcmp(B_ISBN,BookSearch[i].ISBN)==0)
                        {
                            Found=1;
                            current_num=atoi(BookSearch[i].C_A_N_Of_Copies);
                            i_ISBN=i;
                            break;
                        }
                    }
                    if(Found && current_num)
                        {
                            printf("the book you look for is availabl  < IT'S NAME : %s >...\n\n",BookSearch[i_ISBN].title);
                            printf("     ..____________________________________________..\n\n");
                        }
                        else
                        {
                            printf("the book is unavailable....\n\n");
                            printf("     ..____________________________________________..\n\n");
                        }
                    break;
        case 5 : return;
        default :printf("incorrect entry !!\n\n"); break;
        }
}

void add_new_copies()
{
    load_books();
    char ISBN[20],new_copies[20];
    int curren_copies,new_cpies,num_of_copies,i,found=0;
    printf("enter ISBN of the book : ");
    gets(ISBN);
    while(isbn_val(ISBN)==0)
        {
                printf("Invalid ISBN !!!\n");
                printf("reenter the book's ISBN (It should have 13 num only): ");
                gets(ISBN);
        }
    printf("enter the number of copies you want to add : ");
    gets(new_copies);
    while(number_val(new_copies)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter the number of copies you want to add : ");
            gets(new_copies);
        }
    for(i=0 ; i<2000 ;i++)
    {
        if(strcmp(ISBN,BookSearch[i].ISBN)==0)
        {
            found=1;
            new_cpies=atoi(new_copies);
            curren_copies=atoi(BookSearch[i].C_A_N_Of_Copies);
            num_of_copies=atoi(BookSearch[i].n_OF_copies);
            curren_copies=curren_copies+new_cpies;
            num_of_copies=num_of_copies+new_cpies;
            itoa(curren_copies,BookSearch[i].C_A_N_Of_Copies,10);
            itoa(num_of_copies,BookSearch[i].n_OF_copies,10);
            save_books();
            printf("The copies added successfuly....\n");
            printf("     ..____________________________________________..\n\n");
            break;
        }
    }
    if(found!=1)
    {
        printf("the book not found !!!\n\n");
        printf("     ..____________________________________________..\n\n");
    }
}

void delete_book()
{
    int i,state=0,choice=1,current_num_of_books;
    char ISBN[20],finish[10];
    while(choice==1)
    {
    int found=0;
    load_books();
    printf("enter the book's ISBN : ");
    gets(ISBN);
    while(isbn_val(ISBN)==0)
    {
        printf("Invalid ISBN !!!\n");
        printf("reenter the book's ISBN (It should have 13 num only): ");
        gets(ISBN);
    }
    for(i=0 ; i<2000 ; i++)
    {
        current_num_of_books=atoi(BookSearch[i].n_OF_copies)-atoi(BookSearch[i].C_A_N_Of_Copies);
        if(strcmp(BookSearch[i].ISBN,ISBN)==0 && current_num_of_books==0)
        {

            found=1;
            state=0;
            itoa(state,BookSearch[i].state,10);
            break;
        }
    }
    if(found==1)
    {
        save_books();
    }
    else
        printf("The book isn't in the liberary or it can't be deleted because it is borrowed !!!\n\n");
    printf("Do you want to delete more books ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        choice=atoi(finish);
        printf("     ..____________________________________________..\n\n");
    }
    return;
}

void add_member()
{
    int i,k=1;
    char m_information[300],finish[5],line[150];
    while(k!=0)
    {
        printf("enter your first name : ");
        gets(member.FirstName);
        while(name_val(member.FirstName)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter first name : ");
                gets(member.FirstName);
        }
        printf("enter your last name : ");
        gets(member.LastName);
        while(name_val(member.LastName)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter last name : ");
                gets(member.LastName);
        }
        printf("enter your adress : ");
        gets(member.adress);
        while(adress_val(member.adress)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter your adress : ");
                gets(member.adress);
        }
        printf("enter your street : ");
        gets(member.street);
        while(adress_val(member.street)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter your street : ");
                gets(member.street);
        }
        printf("enter your city : ");
        gets(member.city);
        while(adress_val(member.city)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter city : ");
                gets(member.city);
        }
        printf("enter your phone number < number & dashes only > : ");
        gets(member.phone);
        while(phone_val(member.phone)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter phone number : ");
                gets(member.phone);
        }
        printf("enter your age : ");
        gets(member.age);
        while(age_val(member.age)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter age : ");
                gets(member.age);
        }
        printf("enter your E_mail : ");
        gets(member.e_mail);
        while(email_val(member.e_mail)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter E_mail : ");
                gets(member.e_mail);
        }
        MembersInformation=fopen("members information.txt","r");
        for(i=0 ; fgets(line,100,MembersInformation)!= NULL ; i++);
        if(i==0)
        {
            member.ID=i+1;
        }
        else
            member.ID=i+1;
        fclose (MembersInformation);
        member.state=1;
        sprintf(m_information,"%d,%s,%s,%s,%s,%s,%s,%s,%s,%d,0,\n",member.ID,member.FirstName,member.LastName,member.adress,member.street,member.city,member.phone,member.e_mail,member.age,member.state);
        MembersInformation = fopen ("members information.txt","r");
        if(MembersInformation==NULL)
        {
        MembersInformation = fopen ("members information.txt","w");
        fputs (m_information,MembersInformation);
        fclose (MembersInformation);
        }
        else
        {
            MembersInformation = fopen ("members information.txt","a");
            fputs (m_information,MembersInformation);
            fclose (MembersInformation);
        }
        fclose (MembersInformation);
        load_members();
        printf("Do you want to add new members ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        k=atoi(finish);
        printf("     ..____________________________________________..\n\n");
    }


}

void delete_member()
{
    int i,k=1,borrow_state=0;
    char finish[10],mem_ID[10];
    while(k==1)
    {
        int found=0;
        printf("enter the ID of the member you want to delete : ");
        gets(mem_ID);
        while(number_val(mem_ID)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter id : ");
                gets(mem_ID);
        }
        for(i=0 ; i<2000 ; i++)
        {
            if(strcmp(mem_ID,Members_list[i].ID)==0)
            {
                found=1;
                borrow_state=atoi(Members_list[i].book_state);
                break;
            }
        }
        if(!(found))
        {
            printf("you entered wrong ID !!\n\n");
        }
        else
        {
           if(borrow_state)
            {
                printf("can't delete this member because still has a book !!!\n\n");
            }
            else
            {
                itoa(0,Members_list[i].state,10);
                save_members();
            }
        }

        printf("Do you want to delete more members ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        k=atoi(finish);
        printf("     ..____________________________________________..\n\n");
    }

}

void borrow_book()
{
    int i,k=1,year,month,day,reduce,hour,minute,second,increase,i_ID,i_ISBN;
    char Borrow_information[300],finish[5],*token,b_inf[300];
    while(k==1)
    {
        int ISBN_found=0,id_found=0;
        printf("enter the ID of the member : ");
        gets(borrow.id);
        while(number_val(borrow.id)==0)
        {
                printf("Invalid entry !!!\n");
                printf("reenter id : ");
                gets(borrow.id);
        }
        for(i=0 ; i<2000 ; i++)
        {
            if(strcmp(borrow.id,Members_list[i].ID)==0)
            {
                id_found=1;
                i_ID=i;
                break;
            }
        }
        if(id_found==1)
        {
            if(!(atoi(Members_list[i].book_state)>=3))
            {
            printf("enter the borrowing book ISBN : ");
            gets(borrow.ISBN);
            while(isbn_val(borrow.ISBN)==0)
            {
                    printf("Invalid entry !!!\n");
                    printf("reenter ISBN : ");
                    gets(borrow.ISBN);
            }
            for(i=0 ; i<2000 ; i++)
            {
                if(strcmp(borrow.ISBN,BookSearch[i].ISBN)==0)
                {
                    ISBN_found=1;
                    i_ISBN=i;
                    break;
                }
            }
            if(ISBN_found==1)
            {
                SYSTEMTIME str_t;
                GetSystemTime(&str_t);
                year=str_t.wYear;
                itoa(year,b_inf,10);
                sprintf(borrow.year,"%s",b_inf);
                month=str_t.wMonth;
                itoa(month,b_inf,10);
                sprintf(borrow.month,"%s",b_inf);
                day=str_t.wDay;
                itoa(day,b_inf,10);
                sprintf(borrow.day,"%s",b_inf);

                printf("enter year that you will return book : ");
                gets (borrow.b_year);
                while(year_val1(borrow.b_year)==0)
                {
                    printf("Invalid entry !!!\n");
                    printf("reenter year : ");
                    gets(borrow.b_year);
                }
                if(atoi(borrow.b_year)==year)
                {
                    printf("enter month that you will return book : ");
                    gets (borrow.b_month);
                    while(month_val(borrow.b_month)==0)
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter month : ");
                        gets(borrow.b_month);
                    }
                    while(month>atoi(borrow.b_month))
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter month : ");
                        gets(borrow.b_month);
                    }
                        printf("enter day that you will return book : ");
                        gets (borrow.b_day);
                        while(day_val1(borrow.b_day,borrow.b_month)==0)
                        {
                        printf("Invalid entry !!!\n");
                        printf("reenter day : ");
                        gets(borrow.b_day);
                        }
                }
                else
                {
                    printf("enter month that you will return book : ");
                    gets (borrow.b_month);
                    while(month_val(borrow.b_month)==0)
                    {
                        printf("Invalid entry !!!\n");
                        printf("reenter month : ");
                        gets(borrow.b_month);
                    }
                        printf("enter day that you will return book : ");
                        gets (borrow.b_day);
                        while(day_val(borrow.b_day,borrow.b_month)==0)
                        {
                        printf("Invalid entry !!!\n");
                        printf("reenter day : ");
                        gets(borrow.b_day);
                        }
                }
                {
                    increase=atoi(Members_list[i_ID].book_state);
                    increase++;
                    itoa(increase,Members_list[i_ID].book_state,10);
                    increase=atoi(BookSearch[i].borrow_state);
                    increase++;
                    itoa(increase,BookSearch[i].borrow_state,10);
                    reduce=atoi(BookSearch[i].C_A_N_Of_Copies);
                    reduce--;
                    itoa(reduce,BookSearch[i].C_A_N_Of_Copies,10);
                    save_books();
                    save_members();
                    sprintf(b_inf,"%s,%s,%s,%s,%s,%s,%s,%s,0,0,0,\n",borrow.id,borrow.ISBN,borrow.day,borrow.month,borrow.year,borrow.b_day,borrow.b_month,borrow.b_year);
                    borrow_file= fopen ("borrow book.txt","r");
                    if(borrow_file==NULL)
                    {
                        borrow_file= fopen ("borrow book.txt","w");
                        fputs (b_inf,borrow_file);
                        fclose (borrow_file);
                    }
                    else
                    {
                        borrow_file= fopen ("borrow book.txt","a");
                        fputs (b_inf,borrow_file);
                        fclose (borrow_file);
                    }
                    fclose (borrow_file);
                }
            }
            else
                printf("the ISBN you entered isn't in the liberary !!!\n");
            }
            else
                printf("this member borrowed 3 books and it is the maximum number for borrowed books !!!\n");
        }
        else
            printf("you entered wrong ID !!!\n");
        load_borrow();
        printf("Do you want to borrow book again ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        k=atoi(finish);
        printf("     ..____________________________________________..\n\n");

    }
}

void book_back()
{
    int i,increase,decrease,k=1,year,month,day,i_book,i_member,i_borrow;
    char mem_ID[10],ISBN[20],finish[10];
    while(k==1)
    {
        int found_isbn=0,found_id=0,found_date=0;
        printf("enter the book's ISBN you want to return : ");
        gets(ISBN);
        while(isbn_val(ISBN)==0)
        {
                printf("Invalid ISBN !!!\n");
                printf("reenter the book's ISBN (It should have 13 num only): ");
                gets(ISBN);
        }
        for(i=0 ; i<2000 ; i++)
        {
            if(strcmp(BookSearch[i].ISBN,ISBN)==0)
            {
                found_isbn=1;
                i_book=i;
                break;
            }
        }
        printf("enter the member's ID : ");
        gets(mem_ID);
        while(number_val(mem_ID)==0)
        {
                printf("Invalid ID !!!\n");
                printf("reenter ID: ");
                gets(mem_ID);
        }
        for(i=0 ; i<2000 ; i++)
        {
            if(strcmp(Members_list[i].ID,mem_ID)==0)
            {
                found_id=1;
                i_member=i;
                break;
            }
        }
        if(found_id && found_isbn)
        {
            SYSTEMTIME str_t;
                GetSystemTime(&str_t);
                year=str_t.wYear;
                month=str_t.wMonth;
                day=str_t.wDay;
            for(i=0 ; i<2000 ; i++)
            {
                if(strcmp(borrowin_list[i].id,mem_ID)==0 && strcmp(borrowin_list[i].ISBN,ISBN)==0)
                {
                    i_borrow=i;
                    if(year<atoi(borrowin_list[i].b_year))
                        found_date=1;
                    else if(year==atoi(borrowin_list[i].b_year) && month<atoi(borrowin_list[i].b_month))
                        found_date=1;
                    else if(year==atoi(borrowin_list[i].b_year) && month==atoi(borrowin_list[i].b_month) && day<=atoi(borrowin_list[i].b_day))
                        found_date=1;
                    else
                        found_date=2;
                    break;
                }
            }
        }
        else
        {
            printf("the ISBN or Id is invalid !!!\n");
        }
        if(found_date==1 && atoi(borrowin_list[i_borrow].return_year)==0)
        {
            increase=atoi(BookSearch[i_book].C_A_N_Of_Copies);
            increase++;
            itoa(increase,BookSearch[i_book].C_A_N_Of_Copies,10);
            decrease=atoi(Members_list[i_member].book_state);
            decrease--;
            itoa(decrease,Members_list[i_member].book_state,10);
            itoa(year,borrowin_list[i_borrow].return_year,10);
            itoa(month,borrowin_list[i_borrow].return_month,10);
            itoa(day,borrowin_list[i_borrow].return_day,10);
            save_books();
            save_members();
            save_borrow();
            load_books();
            load_borrow();
            load_members();
        }
        else if(found_date==2 && atoi(borrowin_list[i_borrow].return_year)==0)
        {
            printf("this book is late !!!\n");
            increase=atoi(BookSearch[i_book].C_A_N_Of_Copies);
            increase++;
            itoa(increase,BookSearch[i_book].C_A_N_Of_Copies,10);
            decrease=atoi(Members_list[i_member].book_state);
            decrease--;
            itoa(decrease,Members_list[i_member].book_state,10);
            itoa(year,borrowin_list[i_borrow].return_year,10);
            itoa(month,borrowin_list[i_borrow].return_month,10);
            itoa(day,borrowin_list[i_borrow].return_day,10);
            save_books();
            save_members();
            save_borrow();
            load_books();
            load_borrow();
            load_members();
        }
        else
            {
                printf("the book isn't in the borrow list or the member don't borrow this book !!!\n");
            }
        printf("Do you want to return more books ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        k=atoi(finish);
        printf("     ..____________________________________________..\n\n");
    }
    return;
}

void admin()
{
    int k=1,choice;
    char finish[10];
    while(k==1)
    {
        printf("what's your choice :-\n");
        printf("_____________________\n\n");
        printf("0. overdue books\n");
        printf("1. most popular books\n");
        printf("2. back\n\n");
        printf("enter your choice :");
        gets(finish);
        while(choice_val3(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        choice=atoi(finish);
        switch(choice)
        {
            case 0 : overdue_books(); break;
            case 1 : most_popular(); break;
            case 2 : break;
            default :printf("incorrect entry !!\n\n"); break;
        }
        printf("Do you want to still on admin ?? <yes=1> <no=0>\n");
        gets(finish);
        while(choice_val2(finish)==0)
        {
            printf("Invalid entry !!!\n");
            printf("reenter your choice : ");
            gets(finish);
        }
        k=atoi(finish);
        printf("     ..____________________________________________..\n\n");
    }
}

void overdue_books()
{
    int found[2000],year,month,day,b_year,b_month,b_day,i,found_date=0,j=0,num;
    char line[300];
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);
    year=str_t.wYear;
    month=str_t.wMonth;
    day=str_t.wDay;

    for(i=0 ; i<2000 ; i++)
    {
        b_year=atoi(borrowin_list[i].b_year);
        b_month=atoi(borrowin_list[i].b_month);
        b_day=atoi(borrowin_list[i].b_day);
        if(year<b_year);
        else if(year==b_year && month<b_month);
        else if(year==b_year && month==b_month && day<b_day);
        else if(year==b_year && month==b_month && day>b_day && atoi(borrowin_list[i].return_day)==0 && atoi(borrowin_list[i].return_year)==0 && atoi(borrowin_list[i].return_month)==0 )
        {
            found_date=2;
            found[j]=i;
            j++;
        }

    }
    if(found_date==2)
    {
        printf("\nthis is the list of late books :-\n");
        printf("___________________________________\n\n");
        for(i=0 ; i<j ; i++)
        {
            num=found[i];
            printf("< the ISBN of the late book is : ( %s ) and member ID is : ( %s ) >\n",borrowin_list[num].ISBN,borrowin_list[num].id);
            printf("     ..____________________________________________..\n\n");
        }
    }
    else
    {
        printf("NO BOOKS ARE LATE !!!\n");
        printf("     ..____________________________________________..\n\n");
    }

}

void most_popular()
{
    int i,j=0,num_of_borrowed_books[2000],borrowed_num,k,stop,repeat[10];
    for(i=0 ; i<2000 ;i++)
    {
            borrowed_num=atoi(BookSearch[i].borrow_state);
            if(borrowed_num!=0)
            {
                num_of_borrowed_books[j]=borrowed_num;
                j++;
            }

    }
    i=0;
     while(i<10)
    {
        for(j=0 ; j<2000 ; j++)
        {
            if(num_of_borrowed_books[j]<num_of_borrowed_books[i])
            {
                k=num_of_borrowed_books[i];
                num_of_borrowed_books[i]=num_of_borrowed_books[j];
                num_of_borrowed_books[j]=k;
            }
        }
        i++;
    }
    printf("This is a list of most popular book :\n\n");
    k=0;
    for (j=0 ; j<10 ; j++)
    {
        for(i=0 ; i<2000 ; i++)
        {
            borrowed_num=atoi(BookSearch[i].borrow_state);
            if(borrowed_num==num_of_borrowed_books[j] && num_of_borrowed_books[j]!=0 && i!=repeat[0]  && i!=repeat[1] && i!=repeat[2] && i!=repeat[3] && i!=repeat[4] && i!=repeat[5] && i!=repeat[6] && i!=repeat[7] && i!=repeat[8] && i!=repeat[9])
            {
                repeat[k]=i;
                k++;
                printf("_ %s\n",BookSearch[i].title);
                break;
            }

        }

    }
    printf("\n");
}

int quit()
{
    return 0;
}

void load_books()
{
    int i;
    char line[300],*token;
    BooksInformation=fopen("book information.txt","r");
    for(i=0 ; fgets(line,300,BooksInformation)!= NULL ; i++)
    {
        token=strtok(line,",");
        sprintf(BookSearch[i].title,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].auther,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].publisher,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].ISBN,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].Date_Of_Publication,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].n_OF_copies,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].C_A_N_Of_Copies,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].category,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].state,"%s",token);
        token=strtok(NULL,",");
        sprintf(BookSearch[i].borrow_state,"%s",token);
    }
    fclose(BooksInformation);
    return;
}

void load_members()
{
    int i;
    char line[300],*token,str[200];
    MembersInformation=fopen("members information.txt","r");
    for(i=0 ; fgets(line,300,MembersInformation)!= NULL ; i++)
    {
        token=strtok(line,",");
        sprintf(Members_list[i].ID,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].FirstName,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].LastName,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].adress,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].street,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].city,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].phone,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].e_mail,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].age,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].state,"%s",token);
        token=strtok(NULL,",");
        sprintf(Members_list[i].book_state,"%s",token);
    }
    fclose(MembersInformation);
    return;
}

void load_borrow()
{
    int i;
    char line[300],*token;
    borrow_file=fopen("borrow book.txt","r");
    for(i=0 ; fgets(line,300,borrow_file)!= NULL ; i++)
    {
        token=strtok(line,",");
        sprintf(borrowin_list[i].id,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].ISBN,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].day,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].month,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].year,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].b_day,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].b_month,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].b_year,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].return_day,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].return_month,"%s",token);
        token=strtok(NULL,",");
        sprintf(borrowin_list[i].return_year,"%s",token);
    }
    fclose(borrow_file);
    return;
}

int isbn_uniqe_val(char isbn[])
{
    int counter1=0,i,counter2=0,dash_pos;
    for(i=0 ; i<2000 ; i++)
    {
        if(strcmp(isbn,BookSearch[i].ISBN)==0)
            return 0;
    }
    for(i=0 ; isbn[i]!='\0' ; i++)
    {
        if(isbn[i]>=48 && isbn[i]<=57)
            counter1++;
        else if(isbn[i]==45)
        {
            counter2++;
            dash_pos=i;
            if(isbn[i+1]==45)
                return 0;
            else if(dash_pos==0)
                return 0;
        }
        else
            return 0;
    }
    if(!(counter1==13 && counter2==4))
        return 0;
    else if(dash_pos==i-1)
        return 0;
}

int isbn_val(char isbn[])
{
    int counter1=0,i,counter2=0,dash_pos;
    for(i=0 ; isbn[i]!='\0' ; i++)
    {
        if(isbn[i]>=48 && isbn[i]<=57)
            counter1++;
        else if(isbn[i]==45)
        {
            counter2++;
            dash_pos=i;
            if(isbn[i+1]==45)
                return 0;
            else if(dash_pos==0)
                return 0;
        }
        else
            return 0;
    }
    if(!(counter1==13 && counter2==4))
        return 0;
    else if(dash_pos==i-1)
        return 0;
}

int phone_val(char phone[])
{
    int counter1=0,i,counter2=0,dash_pos;
    for(i=0 ; phone[i]!='\0' ; i++)
    {
        if(phone[i]>=48 && phone[i]<=57)
            counter1++;
        else if(phone[i]==45)
        {
            counter2++;
            dash_pos=i;
            if(phone[i+1]==45)
                return 0;
            else if(dash_pos==0)
                return 0;
        }
        else
            return 0;
    }
    if(!(counter1>=7 && counter1<=11 && counter2==2))
        return 0;
    else if(dash_pos==i-1)
        return 0;
}

int age_val(char age[])
{
    int counter=0,i,ages;
    ages=atoi(age);
    if(!(ages>=10 && ages<=110))
        return 0;
}

int email_val(char E_mail[])
{
    int counter=0,i,att,dott,end_char,counter1,counter2;
    for(i=0 ; i<2000 ;i++)
    {
        if(strcmp(E_mail,Members_list[i].e_mail)==0)
            return 0;
    }
    if(E_mail[0]==64 || E_mail[0]==46)
        return 0;
    for(i=0 ; E_mail[i]!='\0' ; i++)
    {
        if(E_mail[i]==64)
        {
            att=i;
            counter++;
        }
        else if(E_mail[i]==46)
            dott=i;
        else if(E_mail[i]==44 || E_mail[i]==' ')
            return 0;

    }
    end_char=i-1;
    if(!(dott>=att+2 && end_char!=dott))
    {
        return 0;
    }
    else if(counter!=1)
        return 0;
    else
        return 1;

}


int name_val(char name[])
{
    int i;
    for(i=0 ; name[i]!='\0' ; i++)
    {
        if(name[i]>=65 && name[i]<=90)
            name[i]=name[i]+32;
    }
    if((name[0]==' ' || name[0]=='\0') || name[0]=='\t')
        return 0;
    for(i=0 ; name[i]!='\0' ; i++)
    {
        if(!(  (name[i]>=97 && name[i]<=122)  || ( name[i]=='\t' || name[i]==' ' ) ) )
        {
            return 0;
        }
    }
    return 1;
}

int adress_val(char name[])
{
    int i;
    if((name[0]==' ' || name[0]=='\0') || name[0]=='\t')
        return 0;

    for(i=0 ; name[i]!='\0' ; i++)
    {
        if(name[i]>=65 && name[i]<=90)
            name[i]=name[i]+32;
    }
    for(i=0 ; name[i]!='\0' ; i++)
    {
        if(!( ( (name[i]>=97 && name[i]<=122)  || (name[i]=='\t' || name[i]==' ') ) || (name[i]>=48 && name[i]<=57) || (name[i]=='.') ) )
        {
            return 0;
        }
    }
    return 1;
}

int choice_val(char choice[])
{
    int i,counter=0;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]>=48 && choice[i]<=57)
            counter++;
        else
            return 0;
    }
    if(!(counter>1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int number_val(char num[])
{
    int counter=0,i;
    if(num[0]=='\0')
        return 0;
    for(i=0 ; num[i]!='\0' ; i++)
    {
        if(num[i]>=48 && num[i]<=57)
        {
            counter++;
        }
        else
            return 0;
    }
    if(counter>5)
    {
        return 0;
    }
    else
        return 1;
}

int choice_val1(char choice[])
{
    int i,counter=0;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]>=49 && choice[i]<=53)
            counter++;
        else
            return 0;
    }
    if(!(counter>1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int match_val(char word1[],char word2[])
{
    int j,i,word1_len,word2_len;
    word1_len=count_chars(word1);
    word2_len=count_chars(word2);
    if(word1_len==word2_len)
    {
    for(i=0 ; word1[i]!='\0' ; i++ )
    {
        if(!(word1[i]==word2[i]))
            return 0;
        else
            j++;
    }
    return 1;
    }
    else
        return 0;
}

int count_chars(char str[])
{
    int i,counter=0;
    for(i=0 ; str[i]!='\0' ; i++)
    {
        counter++;
    }
    return counter;
}

int choice_val2(char choice[])
{
    int i,counter=0;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]<=49 && choice[i]>=48)
            counter++;
        else
            return 0;
    }
    if(!(counter>1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int choice_val3(char choice[])
{
    int i,counter=0;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]<=50 && choice[i]>=48)
            counter++;
        else
            return 0;
    }
    if(!(counter>1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int year_val(char choice[])
{
    int i,counter=0,year;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]<=57 && choice[i]>=48)
            counter++;
        else
            return 0;
    }
    if(counter<=4)
    {
        year=atoi(choice);
        if(year>=1900 && year<=2200)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int year_val1(char choice[])
{
    int i,counter=0,year,this_year;

                SYSTEMTIME str_t;
                GetSystemTime(&str_t);
                this_year=str_t.wYear;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]<=57 && choice[i]>=48)
            counter++;
        else
            return 0;
    }
    if(counter=4)
    {
        year=atoi(choice);
        if(year>this_year-1 && year<=(this_year+1))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int month_val(char choice[])
{
    int i,counter=0,month;
    if(choice[0]=='\0')
        return 0;
    for(i=0 ; choice[i]!='\0' ; i++)
    {
        if(choice[i]<=57 && choice[i]>=48)
            counter++;
        else
            return 0;
    }
    if(counter<=2)
    {
        month=atoi(choice);
        if(month<=12 && month>0)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int day_val(char day[],char month[])
{
    int months,days;
    months=atoi(month);

    if((months==11 || months==9) || (months==6 || months==4))
    {
        days=atoi(day);
        if(!(days>=1 && days<=30))
            return 0;
    }
    else if(months==2)
    {
        days=atoi(day);
        if(!(days>=1 && days<=28))
            return 0;
    }
    else if(!((months==11 || months==9) || (months==6 || months==4)))
    {
        days=atoi(day);
        if(!(days>=1 && days<=31))
            return 0;
    }
    else if(day[0]=='\0' || month[0]=='\0')
        return 0;

}

int day_val1(char day[],char month[])
{
    int months,days,today,ThisMonth;
    SYSTEMTIME str_t;
                GetSystemTime(&str_t);
                today=str_t.wDay;
                ThisMonth=str_t.wMonth;
    months=atoi(month);

    if(months==ThisMonth && atoi(day)<today)
    {
        return 0;
    }
    else if((months==11 || months==9) || (months==6 || months==4))
    {
        days=atoi(day);
        if(!(days>=1 && days<=30))
            return 0;
    }
    else if(months==2)
    {
        days=atoi(day);
        if(!(days>=1 && days<=28))
            return 0;
    }
    else if(!((months==11 || months==9) || (months==6 || months==4)))
    {
        days=atoi(day);
        if(!(days>=1 && days<=31))
            return 0;
    }
    else if(day[0]=='\0' || month[0]=='\0')
        return 0;


}

void save_books()
{
    int i,state=0;
    char b_inf[300];
    BooksInformation = fopen ("book information.txt","w");
    for(i=0 ; i<2000 ; i++)
    {
        state=atoi(BookSearch[i].state);
        if(state==1)
        {
            sprintf(b_inf,"%s,%s,%s,%s,%s,%s,%s,%s,1,%s,\n",BookSearch[i].title,BookSearch[i].auther,BookSearch[i].publisher,BookSearch[i].ISBN,BookSearch[i].Date_Of_Publication,BookSearch[i].n_OF_copies,BookSearch[i].C_A_N_Of_Copies,BookSearch[i].category,BookSearch[i].borrow_state);
            fputs (b_inf,BooksInformation);
        }
    }
    fclose (BooksInformation);
    load_books();
}

void save_members()
{
    int i,state=0;
    char mem_inf[300];
    MembersInformation = fopen ("members information.txt","w");
    for(i=0 ; i<2000 ; i++)
    {
        state=atoi(Members_list[i].state);
        if(state==1)
        {
            sprintf(mem_inf,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,\n",Members_list[i].ID,Members_list[i].FirstName,Members_list[i].LastName,Members_list[i].adress,Members_list[i].street,Members_list[i].city,Members_list[i].phone,Members_list[i].e_mail,Members_list[i].age,Members_list[i].state,Members_list[i].book_state);
            fputs (mem_inf,MembersInformation);
        }
    }
    fclose (MembersInformation);
    load_members();
}

void save_borrow()
{
    int i;
    char borrow_inf[300];
    borrow_file = fopen ("borrow book.txt","w");
    for(i=0 ; i<2000 ; i++)
    {
        if(atoi(borrowin_list[i].id) && atoi(borrowin_list[i].b_day) && atoi(borrowin_list[i].b_month) && atoi(borrowin_list[i].b_year) && atoi(borrowin_list[i].day) && atoi(borrowin_list[i].month) && atoi(borrowin_list[i].year) )
        {
            sprintf(borrow_inf,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,\n",borrowin_list[i].id,borrowin_list[i].ISBN,borrowin_list[i].day,borrowin_list[i].month,borrowin_list[i].year,borrowin_list[i].b_day,borrowin_list[i].b_month,borrowin_list[i].b_year,borrowin_list[i].return_day,borrowin_list[i].return_month,borrowin_list[i].return_year);
            fputs (borrow_inf,borrow_file);
        }

    }
    fclose (borrow_file);
    load_borrow();
}

