#include<stdio.h>
#include<string.h>

struct supplier
{
    int supp_id;
    char temp1_mod_no[30],supp_name[30];
    char temp1_city[30];
    char temp1_email[30];
};
struct supplier s;

// ********************  Enter the supplier information ************

void supp_entry()
{
    FILE *f1;
    f1=fopen("supplier_info.txt","a");
    
    printf("\nenter the supplier data:\n");
    printf("enter supplier id:\n");
    scanf("%d",&s.supp_id);
    fflush(stdin);
    // gets(s.supp_id);
    //  _flushall();
    printf("enter supplier name\n");
    gets(s.supp_name);
    //scanf("%s",&c.cust_name);
    printf("enter the supplier mob_no\n");
    gets(s.temp1_mod_no);
    printf("enter the supplier city\n");
    gets(s.temp1_city);
    printf("enter the supplier Email\n");
    gets(s.temp1_email);
    fprintf(f1,"%d %s %s %s %s\n",s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email);
    fclose(f1);
}

// ********************  display the supplier information ************

void supp_list()
{
    FILE *f1;
    f1=fopen("supplier_info.txt","r");
    printf("ID\tName\tMo_Number\tCity\tEmail\n");
    while(fscanf(f1,"%d %s %s %s %s",&s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email)!=EOF)
    {
        printf("%d\t%s\t%s\t%s\t%s\n",s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email);
    }
    fclose(f1);
}

// ********************  Update Supplier informatin ************

void sup_update()
{
    FILE *fp1,*fp2;
    fp1=fopen("supplier_info.txt","r");
    fp2=fopen("tp.txt","w");

    int ID;
    printf("enter the id of supplier for update");
    scanf("%d",&ID);
    while(fscanf(fp1,"%d %s %s %s %s",&s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email)!=EOF)
    {
        if(s.supp_id==ID)
        {
            
            printf("\nenter the supplier data:\n");
            printf("enter supplier id:\n");
            scanf("%d",&s.supp_id);
            fflush(stdin);
            // gets(s.supp_id) ;
            printf("enter supplier name\n");
            gets(s.supp_name);
            printf("enter the supplier mob_no\n");
            gets(s.temp1_mod_no);
            printf("enter the supplier city\n");
            gets(s.temp1_city);
            printf("enter the supplier Email\n");
            gets(s.temp1_email);
            fprintf(fp2,"%d %s %s %s %s\n",s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email);
            
        }
        else{
            fprintf(fp2,"%d %s %s %s %s\n",s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("supplier_info.txt");
    rename("tp.txt","supplier_info.txt");
}

// ********************  search Supplier informatin by id menu ************

void search_id()
{
    FILE *f1;
    f1=fopen("supplier_info.txt","r");

    int ID,flag=1;
    printf("enter the id for search supplier info\n");
    scanf("%d",&ID);

    while(fscanf(f1,"%d %s %s %s %s",&s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email)!=EOF)
    {
        if(ID==s.supp_id)
        {
            flag=0;
            printf("%d %s %s %s %s\n",s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email);
        }
    }
    if(flag)
    {
        printf("\nid is not found!!!!\n");
    }
    fclose(f1);
}

// ********************  search Supplier informatin by NAME menu ************

void search_name()
{
    FILE *f;
    f=fopen("C_info.txt","r");
    char uname[10];
    printf("enter the data for serch by name\n");
    // _flushall();
    scanf("%s",uname);
    int flag=1;
    while(fscanf(f,"%d %s %s %s %s",&s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email)!=-1)
    { 
        if(strcmp(s.supp_name,uname)==0)
        {
            flag=0;
            printf("%d %s %s %s %s\n",s.supp_id,s.supp_name,s.temp1_mod_no,s.temp1_city,s.temp1_email);
        }
    }
    if(flag)
    {
        printf("\nname is not found !!!\n");
    }
    fclose(f);
}

// ********************  search Supplier informatin by name and id menu ************

void search()
{
    int choice;

    do
    {
        printf("\n1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Exit the search menu!!\n");

        printf("\n\nenter the choice :\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            search_id();
            break;
            case 2:
            search_name();
            break;
            case 3:
            printf("\nExit the supplier search menu!!!\n\n");
            break;
        }
    }while(choice!=3);
}

//******************** ------- MAIN SUPPLIER MENU ----------****

void supplier()
{
    int choice;


    do{
        printf("\t1. Add Supplier informatin:\n");
        printf("\t2. Display Supplier informatin:\n");
        printf("\t3. Update Supplier informatin:\n");
        printf("\t4. Search Supplier informatin:\n");
        printf("\t5. Exit from Supplier menu:\n");

        printf("\nenter the choice :\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            supp_entry();
            break;
            case 2:
            supp_list();
            break;
            case 3:
            sup_update();
            break;
            case 4:
            search();
            break;
            case 5:
            printf("\nExite from Supplier menu!!\n");
            break;
        }
    }while(choice!=5);
}