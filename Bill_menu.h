#include<stdio.h>
#include<string.h>
int y;
struct bill_slip
{
    int bill_no,medi_qty,medi_rete,total,day,month,year;
    char cname[20],mediname[20];
};
struct bill_slip B;

struct temp_medi
{
    int id,rack,cabnit,quantity,sale,total,Unit,cost,profit;
    int bye,qty,bill_no;
    char medi_name[10],comp_name[10],supp_name[10];
    char pur_date[10],exp_date[10],manu_date[10];
};
struct temp_medi m;
void bill()
{
    do{
        int flag=0;
        FILE *fp1;
        printf("\nenter the bill number:\n");
        scanf("%d",&B.bill_no);
        fflush(stdin);
        printf("enter customer name:\n");
        gets(B.cname);
        printf("enter the medicine name\n");
        gets(B.mediname);
        fp1=fopen("medicine_info.txt","r");
        while(fscanf(fp1,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d",&m.id,m.medi_name,&m.rack,&m.cabnit,&m.quantity,&m.sale,&m.Unit,&m.cost,&m.bye,m.pur_date,m.exp_date,m.manu_date,&m.bill_no,m.comp_name,m.supp_name,&m.total)!=EOF)
        {
            if(strcmp(B.mediname,m.medi_name)==0)
            {
                printf("cost of medicine= %d\n",m.cost);
                flag=1;
                break;
            }
        }
        if(flag)
        {
            printf("enter the medicine quantity:\n");
            scanf("%d",&B.medi_qty);

            B.medi_rete=m.cost;
            B.total=B.medi_rete*B.medi_qty;

            printf("enter the date month and year\n");
            scanf("%d%d%d",&B.day,&B.month,&B.year);
        }
        else{
            printf("\nMedicine is not found!!!\n\n");
        }

        fclose(fp1);
        FILE *fp2;

        // store all info in bill slpie
        fp2=fopen("Bill info.txt","r");
        fprintf(fp2,"%d %s %s %d %d %d %d %d %d\n",B.bill_no,B.cname,B.mediname,B.medi_qty,B.medi_rete,B.total,B.day,B.month,B.year);
        printf("Bill_no\tCname  medi_name\tqut\trate\tTotal\tDay\tmonth\tYear\n");
        printf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",B.bill_no,B.cname,B.mediname,B.medi_qty,B.medi_rete,B.total,B.day,B.month,B.year);
        fclose(fp2);

        FILE *fp3,*fp4;
        fp3=fopen("medicine_info.txt","a");
        fp4=fopen("tp.txt","w");
        while(fscanf(fp3,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d",&m.id,m.medi_name,&m.rack,&m.cabnit,&m.quantity,&m.sale,&m.Unit,&m.cost,&m.bye,m.pur_date,m.exp_date,m.manu_date,&m.bill_no,m.comp_name,m.supp_name,&m.total)!=EOF)
        {
            if(strcmp(B.mediname,m.medi_name)==0)
            {
                m.quantity=m.quantity-B.medi_qty;
                m.sale=m.sale+B.medi_qty;
                fprintf(fp4,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d\n",m.id,m.medi_name,m.rack,m.cabnit,m.quantity,m.sale,m.Unit,m.cost,m.bye,m.pur_date,m.exp_date,m.manu_date,m.bill_no,m.comp_name,m.supp_name,m.total);
            }
            else{
                fprintf(fp4,"%d %s %d %d %d %d %d %d %d %s %s %s %d %s %s %d\n",m.id,m.medi_name,m.rack,m.cabnit,m.quantity,m.sale,m.Unit,m.cost,m.bye,m.pur_date,m.exp_date,m.manu_date,m.bill_no,m.comp_name,m.supp_name,m.total);
            }
        }
        fclose(fp3);
        fclose(fp4);
        remove("medicine_info.txt");
        rename("tp.txt","medicine_info.txt");

        int y;    
        printf("you want to more medicine yes=0 and no=1:\n");
        scanf("%d",&y);
        if(y)
        {
            break;
        }
        
    }while(1);
    
}