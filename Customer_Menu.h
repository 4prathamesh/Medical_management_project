#include<stdio.h>
#include<string.h>
struct customer
{
    int cust_id;
    char cust_name[50],cust_city[50];
    char mod_no[50];
    char email[50];
};
struct customer c;
int flag=1;
//********************* case 1...add information of customer using thes function
void cust_entry()
{
    FILE *f;
    f=fopen("C_info.txt","a");
    printf("enter the data:\n");
    printf("enter customer id:\n");
    scanf("%d",&c.cust_id);
     _flushall();
    printf("enter customer name\n");
    gets(c.cust_name);
    //scanf("%s",&c.cust_name);
    printf("enter the customer city\n");
    scanf("%s",&c.cust_city);
    printf("enter the customer mod_no\n");
    scanf("%s",&c.mod_no);
    printf("enter the customer Email\n");
    scanf("%s",&c.email);
    fprintf(f,"%d %s %s %s %s\n",c.cust_id,c.cust_name,c.cust_city,c.mod_no,c.email);
    fclose(f);
}
//**********************sub CASE 1...SEARCH BY CUSTOMER ID
void search_cid()
{
    FILE *f;
    f=fopen("C_info.txt","r");
    int uid;
    printf("enter the data for serch id\n");
    scanf("%d",&uid);
    int flag=1;
    while(fscanf(f,"%d%s%s%s%s",&c.cust_id,&c.cust_name,&c.cust_city,&c.mod_no,&c.email)!=-1)
    { 

      //  printf("%d",c.cust_id);
        if(c.cust_id==uid)
        {
            printf("%d %s %s %s %s\n",c.cust_id,c.cust_name,c.cust_city,c.mod_no,c.email);
            flag=0;
        }
    }
    if(flag)
    {
   
        printf("not");
    }
    fclose(f);
}
//******************* sub CASE 2.. SEARCH BY NAME
void search_cname()
{
    FILE *f;
    f=fopen("C_info.txt","r");
    char uname[10];
    printf("enter the data for serch by name\n");
    _flushall();
    gets(uname);
    int flag=1;
    while(fscanf(f,"%d%s%s%s%s",&c.cust_id,&c.cust_name,&c.cust_city,&c.mod_no,&c.email)!=-1)
    { 

      //  printf("%d",c.cust_id);
        if(strcmp(c.cust_name,uname)==0)
        {
            printf("%d %s %s %s %s\n",c.cust_id,c.cust_name,c.cust_city,c.mod_no,c.email);
            flag=0;
        }
    }
    if(flag)
    {
   
        printf("not");
    }
    fclose(f);
}
// *******************CASE 2....serch information by id and name
void cust_serch()
{
    int choice;
    do{
        printf("1. serch customer by id\n");
        printf("2. serch customer by name\n");
        printf("3. Exit!!\n");
        
        printf("\nenter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            search_cid();
            break;
            case 2:
            search_cname();
            break;
            case 3:
            printf("Exit!!!!!!!! from serching\n");
        }
    }while(choice!=3);
}

//*********** CASE 3.... display customer information**************
void cust_list()
{
    FILE *f;
    f=fopen("C_info.txt","r");
    printf("ID\tName  \tCity\tMod_no\t\tEmail\n");
    while(fscanf(f,"%d%s%s%s%s",&c.cust_id,&c.cust_name,&c.cust_city,&c.mod_no,&c.email)!=-1)
    {
        printf("%d\t%s \t%s\t%s\t%s\n",c.cust_id,c.cust_name,c.cust_city,c.mod_no,c.email);
    }
    fclose(f);
}

//************ CASE 4....updeate info
void cust_updeate()
{
    int ID;
    FILE *fp1,*fp2;
    fp1=fopen("C_info.txt","r");
    fp2=fopen("tempF.txt","w");
    
    printf("\n\npleas enter id for update data:\n");
    scanf("%d",&ID);

    while(fscanf(fp1,"%d%s%s%s%s",&c.cust_id,&c.cust_name,&c.cust_city,&c.mod_no,&c.email)!=EOF)
    {
        if(c.cust_id==ID)
        {
                printf("enter customer id:\n");
                scanf("%d",&c.cust_id);
                fflush(stdin);
                printf("enter customer name\n");
                gets(c.cust_name);
                //scanf("%s",c.cust_name);
                printf("enter the customer city\n");
                scanf("%s",&c.cust_city);
                printf("enter the customer mod_no\n");
                scanf("%s",&c.mod_no);
                printf("enter the customer Email\n");
                scanf("%s",&c.email);
                flag=0;
            fprintf(fp2,"%d %s %s %s %s\n",c.cust_id,c.cust_name,c.cust_city,c.mod_no,c.email);
        }
        else{
            fprintf(fp2,"%d %s %s %s %s\n",c.cust_id,c.cust_name,c.cust_city,c.mod_no,c.email);
        }
        
    }
    fclose(fp1);
    fclose(fp2);
    if(flag)
    {
        printf("\n\nId is not found !!!!\n\n");
    }
    remove("C_info.txt");
    rename("tempF.txt","C_info.txt");
}

// ******************** -----     MAIN FUNCTION OF CUSTOMER  ---------- ****************

void customer()
{
    int Cchoice;
    do{
        printf("\n\t1. Enter customer info\n");
        printf("\t2. Search the customer\n");
        printf("\t3. Customer list\n");
        printf("\t4. Update customer info\n");
        printf("\t5. Exit the customer menu!!!\n\n");

        printf("enter the choice\n");
        scanf("%d",&Cchoice);

        switch(Cchoice)
        {
            case 1:
            cust_entry();
            break;
            case 2:
            cust_serch();
            break;
            case 3:
            cust_list();
            break;
            case 4:
            cust_updeate();
            break;
            case 5:
            printf("Exit\n");
            break;
        }
    }while(Cchoice!=5);
}
