#include<stdio.h>
#include<string.h>

struct medicine
{
    int id,rack,cabnit,quantity,sale,total,Unit,cost,profit;
    int bye,qty,bill_no;
    char medi_name[50],comp_name[50],supp_name[50];
    char pur_date[50],exp_date[50],manu_date[50];
};
struct medicine med;

// ******        updata of medicine info  **********
void update_stock()
{
    FILE *fp1,*fp2;
    fp1=fopen("medicine_info.txt","r");
    fp2=fopen("tp.txt","w");

    int pid;
    printf("\n\n Enter the id for updata medicine data\n\n");
    scanf("%d",&pid);

   while(fscanf(fp1,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s",&med.id,med.medi_name,&med.rack,&med.cabnit,&med.quantity,&med.sale,&med.Unit,&med.cost,&med.bye,med.pur_date,med.exp_date,med.manu_date,&med.bill_no,med.comp_name,med.supp_name)!=EOF)
    {
    if(pid==med.id)
        {
          printf("1.enter medicine id:\n");
            scanf("%d",&med.id);
            fflush(stdin);
            printf("2.enter Medicine name\n");
            gets(med.medi_name);
            printf("3.enter medicine rack:\n");
            scanf("%d",&med.rack);
            printf("4.enter medicine cabnit:\n");
            scanf("%d",&med.cabnit);
            printf("5.enter medicine quantity:\n");
            scanf("%d",&med.quantity);
            med.total=med.quantity;
            printf("6.medicine sale:\n");
            scanf("%d",&med.sale);
            // printf(".total of medicine:\n"); med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,
            // scanf("%d",&med.total);  med.Unit,med.cost,med.bye,med.pur_data,med.exp_data,med.manu_data,med.bill_no
            printf("7.unit of medicine:\n");
            scanf("%d",&med.Unit);
            printf("8. Medicine cost :\n");
            scanf("%d",&med.cost);
            printf("9.Medicine bye:\n");
            scanf("%d",&med.bye);

            printf("10.Medicne purchase data \n");
            scanf("%s",med.pur_date);
            printf("11.Medicne expiry data\n");
            scanf("%s",&med.exp_date);
            printf("12.Medicne manufcturing data\n");
            scanf("%s",&med.manu_date);
            printf("13.Medicne bill number\n");
            scanf("%d",&med.bill_no);
            printf("14.Medicne compony name\n");
            scanf("%s",&med.comp_name); 
            printf("15.Medicne supplary name\n");
            scanf("%s",&med.supp_name);
            fprintf(fp2,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d\n",med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,med.Unit,med.cost,med.bye,med.pur_date,med.exp_date,med.manu_date,med.bill_no,med.comp_name,med.supp_name,med.total);
        }
        else{
            fprintf(fp2,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d\n",med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,med.Unit,med.cost,med.bye,med.pur_date,med.exp_date,med.manu_date,med.bill_no,med.comp_name,med.supp_name,med.total);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("medicine_info.txt");
    rename("tp.txt","medicine_info.txt");
}

// ***********             entry of medicine inf    ***************
void medi_entry()
{
   FILE *f;
    f=fopen("medicine_info.txt","a");
    printf("enter the medicine data:\n");
    printf("1.enter medicine id:\n");
    scanf("%d",&med.id);
     _flushall();
    printf("2.enter Medicine name\n");
    gets(med.medi_name);
    printf("3.enter medicine rack:\n");
    scanf("%d",&med.rack);
    printf("4.enter medicine cabnit:\n");
    scanf("%d",&med.cabnit);
    printf("5.enter medicine quantity:\n");
    scanf("%d",&med.quantity);
    med.total=med.quantity;
    printf("6.medicine sale:\n");
    scanf("%d",&med.sale);

    printf("7.unit of medicine:\n");
    scanf("%d",&med.Unit);
    printf("8. Medicine cost :\n");
    scanf("%d",&med.cost);
    printf("9.Medicine bye:\n");
    scanf("%d",&med.bye);

    printf("10.Medicne purchase data \n");
    scanf("%s",med.pur_date);
    printf("11.Medicne expiry data\n");
    scanf("%s",&med.exp_date);
    printf("12.Medicne manufcturing data\n");
    scanf("%s",&med.manu_date);
    printf("13.Medicne bill number\n");
    scanf("%d",&med.bill_no);
    printf("14.Medicne compony name\n");
    scanf("%s",&med.comp_name); 
    printf("15.Medicne supplary name\n");
    scanf("%s",&med.supp_name);
    fprintf(f,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d\n",med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,med.Unit,med.cost,med.bye,med.pur_date,med.exp_date,med.manu_date,med.bill_no,med.comp_name,med.supp_name,med.total);
    
    fclose(f);
} 

// *************            sale of medicine            ******************

void medi_sale()
{
    FILE *f;
    f=fopen("medicine_info.txt","r");
    printf("Med_name\tQty_Mid\tSale\tTotal\n");
    while(fscanf(f,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d",&med.id,med.medi_name,&med.rack,&med.cabnit,&med.quantity,&med.sale,&med.Unit,&med.cost,&med.bye,med.pur_date,med.exp_date,med.manu_date,&med.bill_no,med.comp_name,med.supp_name,&med.total)!=EOF)
    {
        printf("%s\t\t%d\t%d\t%d\n",med.medi_name,med.quantity,med.sale,med.total);
    }
    fclose(f);
}

// ********************   search by medicine ID  *************
void medi_search()
{
    FILE *f;
    f=fopen("medicine_info.txt","r");

    int ID,flag=1;
    printf("enter the ID of medicine for search\n");
    scanf("%d",&ID);
    printf("ID\tName \tRack\tCaben\tQuy\tSale\tUnit\tCost\tbye\tP_date   Exp_date\tMfe_date\tbill_no\tC_name\tSup_name\tTotal\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    while(fscanf(f,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d",&med.id,med.medi_name,&med.rack,&med.cabnit,&med.quantity,&med.sale,&med.Unit,&med.cost,&med.bye,med.pur_date,med.exp_date,med.manu_date,&med.bill_no,med.comp_name,med.supp_name,&med.total)!=EOF)
    {
        //printf("%d %d",ID,med.id);
        //printf("%d \n%s \n%d \n%d \n%d \n%d \n%d \n%d \n%d %s\n %s %\ns %d \n%s \n%s\n",med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,med.Unit,med.cost,med.bye,med.pur_date,med.exp_date,med.manu_date,med.bill_no,med.comp_name,med.supp_name);
        if(med.id==ID)
        {
            printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d",med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,med.Unit,med.cost,med.bye);
            printf("\t%s",med.pur_date);
            printf(" %s",med.exp_date);
            printf("\t%s",med.manu_date);
            printf("\t%d",med.bill_no);
            printf("\t%s",med.comp_name);
            printf("\t%s\t%d\n",med.supp_name,med.total);
            flag=0;
            break;
        }
    }
    if(flag)
    {
        printf("\n\nID is not found!!!\n\n");
    }
    fclose(f);

}

// case 5: stock of medicine 

void stock()
{
    FILE *f;
    f=fopen("medicine_info.txt","r");
    printf("ID\tName \tRack\tCaben\tQuy\tSale\tUnit\tCost\tbye\tP_date   Exp_date\tMfe_date\tbill_no\tC_name\tSup_name\tTotal\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
    while(fscanf(f,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d",&med.id,&med.medi_name,&med.rack,&med.cabnit,&med.quantity,&med.sale,&med.Unit,&med.cost,&med.bye,&med.pur_date,&med.exp_date,&med.manu_date,&med.bill_no,&med.comp_name,&med.supp_name,&med.total)!=EOF)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d",med.id,med.medi_name,med.rack,med.cabnit,med.quantity,med.sale,med.Unit,med.cost,med.bye);
        printf("\t%s",med.pur_date);
        printf(" %s",med.exp_date);
        printf("\t%s",med.manu_date);
        printf("\t%d",med.bill_no);
        printf("\t%s",med.comp_name);
        printf("\t%s",med.supp_name);
        printf("\t\t%d\n\n",med.total);
    }
    fclose(f);
}

//*********** ----- MEDICINE main MENU ---- **************
void medicine()
{
    int Mchoice;
    do{
        printf("\t1. Update stock of medicine\n");
        printf("\t2. Enter medicine information\n");
        printf("\t3. sale of medicine\n");
        printf("\t4. search medicine\n");
        printf("\t5. stock of medicine\n");
        printf("\t6. Exite\n");

        printf("\nenter the choice\n");
        scanf("%d",&Mchoice);
        switch(Mchoice)
        {
            case 1:
            update_stock(); 
            break;
            case 2:
            medi_entry();
            break;
            case 3:
            medi_sale();
            break;
            case 4:
            medi_search();
            break;
            case 5:
            stock();
            break;
            case 6:
            printf("Exit!!! from medicine\n");
            break;
        }
    }while(Mchoice!=6);
}




