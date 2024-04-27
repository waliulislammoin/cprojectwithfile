#include<stdio.h>
#include<conio.h>
#include<string.h>
char insert();
char ibp();
int menu();
int sid();
int scg();
char edit();
char del();
char show();
char ser();
struct stu
{
    int id;
    char name[20],dept[5];
    float cg;
} tem1,ob[50];
int i,j,nn,ga,go,c,x,sn;
char y;
FILE *f1,*f2,*f3,*f4;
int main()
{
    f3=fopen("sn.txt","r");
    fflush(stdin);
    fscanf(f3,"%d",&sn);
    fflush(stdin);
f1=fopen("sdetails.txt","r");
    for(i=0; i<=sn; i++)
    {
        fflush(stdin);
        fscanf(f1,"%d",&ob[i].id);
        fflush(stdin);
        fscanf(f1,"%d",&ga);
        fflush(stdin);
        fscanf(f1,"%[^\t]",ob[i].name);
        fflush(stdin);
        fscanf(f1,"%d",&go);
         fflush(stdin);
        fscanf(f1,"%[^\t]",ob[i].dept);
        fflush(stdin);
        fscanf(f1,"%f",&ob[i].cg);
    }


      c=sn+1;

    menu();
}
char insert()
{
    for(i=c; i<=c; i++)
    {
        printf("\t\tEnter ID:- ");
        scanf("%d",&ob[i].id);
        fflush(stdin);
        printf("\t\tEnter NAME:- ");
        scanf("%[^\n]",ob[i].name);
        printf("\t\tEnter DEPT. NAME:- ");
        scanf("%s",ob[i].dept);
        printf("\t\tEnter CGPA:- ");
        scanf("%f",&ob[i].cg);
    }
    sn=c;
    f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f2);
    fclose(f4);
    printf("\t\tDo you want to add another student details?(y/n)");
    fflush(stdin);
    scanf("%c",&y);
    if(y=='y'||y=='Y')
    {
        c++;
        system("cls");
        insert();
    }
    else
    {

        c++;
        system("cls");
        menu();
    }
}
int menu()
{
    system("color 0E");
    int m;
    printf("   \t\tSTUDENT MANAGEMENT SYSTEM\n\t   ***********************************\n\t\tPlease select an option :\n\n");
    printf("\t\t[1]:Insert student details\n\t\t[2]:Edit student details\n\t\t[3]:Delete student details\n\t\t[4]:Show student details\n\t\t[5]:Sort Data (By ID)\n\t\t[6]:Sort Data (By CGPA)\n\t\t[7]:Insert Any Position\n\t\t[8]:Search Student Details\n\t\t[9]:Exit\n\t\t");
    scanf("%d",&m);
    if(m>0&&m<=9)
    {
    switch (m)
    {
    case 1:
    {
insert();
    }
    break;
    case 2:
    {
        edit();
    }
    break;
    case 3:
    {
        del();
    }
    break;
    case 4:
    {
        show();
    }
    break;
    case 5:
    {
        sid();
    }
    break;
    case 6:
    {
        scg();
    }
    break;
    case 7:
    {
        ibp();
    }
    break;
    case 8:
    {
        ser();
    }
    break;
    case 9:
    {
      f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    return 0;
    }
    break;
    }
}
else
{
    system("cls");
        printf("\t\tWrong Option!!!\n\n");
        menu();
}
}
char edit()
{
    int d,gg,co,ec=0;
    gg=sn;
    printf("\t\tEnter Student ID to edit student details:-\n");
    scanf("%d",&nn);
    for(co=0; co<=gg; co++)
    {
        if(nn==ob[co].id)
        {
            d=co;
            gg=0;
            ec=0;
        }
        else
        {
            ec++;
        }
    }
    {
            printf("\t\t%-9d    |  \t%-19s |  \t%-4s   |\t%.2f\n",ob[d].id,ob[d].name,ob[d].dept,ob[d].cg);
        }
    if(ec==0)
    {
        printf("\t\tEnter ID:- ");
        scanf("%d",&ob[d].id);
        fflush(stdin);
        printf("\t\tEnter NAME:- ");
        scanf("%[^\n]",ob[d].name);
        printf("\t\tEnter DEPT. NAME:- ");
        scanf("%s",ob[d].dept);
        printf("\t\tEnter CGPA:- ");
        scanf("%.2f",&ob[d].cg);
    }
    else
    {
        printf("\t\tNo Match Found\n");
    }
    f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f2);
    fclose(f4);
    printf("\t\tDo you want EDIT another student details?(y/n)");
    fflush(stdin);

    scanf("%c",&y);
    if(y=='y'||y=='Y')
    {
        system("cls");
        edit();
    }
    else
    {
        system("cls");
        menu();
    }
}
char del()
{
    int de,hh,ic,lc,lm;
    printf("\t\tEnter ID of the student to delete his/her details:- ");
    scanf("%d",&de);
    lc=sn;
    for(x=0; x<=lc; x++)
    {
        if(de==ob[x].id)
        {
            ic=x;
            lc=0;
            lm=0;
        }
        else
        {
            lm=1;
        }
    }
    if(lm==0)
    {
        for(hh=ic; hh<=sn; hh++)
        {
            ob[hh]=ob[hh+1];
        }
        sn--;
        f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f2);
    fclose(f4);
        c=sn;
        ++c;
        printf("\t\tDeleted Successfully! \n");
    }
    else{printf("\t\tNo Match Found!\n");}
    fflush(stdin);
    printf("\t\tDo you wants to delete another one?(y/n)");
    scanf("%c",&y);
    if(y=='y'||y=='Y')
    {
        system("cls");
        del();
    }
    else
    {
        system("cls");
        menu();
    }
}
char show()
{
        printf("\t\tID\t\t\tNAME\t\t\tDEPT\t\tCGPA\n\t    ************************************************************************************\n");
        for(i=0; i<=sn; i++)
        {
            printf("\t\t%-9d    |  \t%-19s |  \t%-4s   |\t%.2f\n",ob[i].id,ob[i].name,ob[i].dept,ob[i].cg);
        }
        fflush(stdin);
        scanf("%c",&y);
        system("cls");
        menu();
        }
int sid()
{

    for(i=0;i<sn;i++)
    {
        for(j=0;j<sn-i;j++)
        {

            if(ob[j].id>ob[j+1].id)
            {
             tem1=ob[j];
             ob[j]=ob[j+1];
             ob[j+1]=tem1;

            }
        }
        f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f2);
    fclose(f4);

    show();
}
}
int scg()
{

    for(i=0;i<sn;i++)
    {
        for(j=0;j<sn-i;j++)
        {

            if(ob[j].cg>ob[j+1].cg)
            {
             tem1=ob[j];
             ob[j]=ob[j+1];
             ob[j+1]=tem1;

            }
        }
f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f2);
    fclose(f4);
    show();
}
}
char ibp()
{
    int pos;
    printf("\nEnter The Position Of New Data  \n");
    scanf("%d",&pos);
    printf("\t\tEnter ID:- ");
        scanf("%d",&tem1.id);
        fflush(stdin);
        printf("\t\tEnter NAME:- ");
        scanf("%[^\n]",tem1.name);
        printf("\t\tEnter DEPT. NAME:- ");
        scanf("%s",tem1.dept);
        printf("\t\tEnter CGPA:- ");
        scanf("%f",&tem1.cg);

        for(i=sn;i>=pos-1;i--)
        {
            ob[i+1]=ob[i];

        }
        ob[pos-1]=tem1;
        ++sn;
        f2=fopen("sdetails.txt","w");
    f4=fopen("sn.txt","w");
    fprintf(f4,"%d\n",sn);
    for(i=0; i<=sn; i++)
    {
        fprintf(f2,"%d\t",ob[i].id);
        fflush(stdin);
        fputs(ob[i].name,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fputs(ob[i].dept,f2);
        fprintf(f2,"\t");
        fflush(stdin);
        fprintf(f2,"%.2f\n",ob[i].cg);
    }
    fclose(f2);
    fclose(f4);
        show();
}
char ser()
{
    int k1k=0;
    printf("Enter Student ID For Search DATA\n");
    scanf("%d",&i);

for(j=0;j<=sn;j++){

    if(i==ob[j].id)
    {
       printf("\t\tID\t\t\tNAME\t\t\tDEPT\t\tCGPA\n\t    ************************************************************************************\n");

            printf("\t\t%-9d    |  \t%-19s |  \t%-4s   |\t%.2f\n",ob[j].id,ob[j].name,ob[j].dept,ob[j].cg);
            k1k++;

            }}
            if(k1k==0)
            {
                printf("!!! No Match Found \n");
            }
        fflush(stdin);

       printf("Do You Want To Search Another One?  y/n");
        scanf("%c",&y);
       if(y=='y'||y=='Y')
    {
        system("cls");
        ser();
    }
    else
    {
        system("cls");
        menu();
    }


}
