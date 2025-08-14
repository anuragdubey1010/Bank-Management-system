#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct details
    {
        char name [100];
        int accountno;
        int age;
        char phoneno[10];
        char sex;
        int balance;
    }details;
details d[5];
int txnc[]={0,0,0,0,0};
int c=0;
details d1[5];
int cc=0;
int txns[]={0,0,0,0,0};
int EXIT()
{
    printf("THANK YOU FOR VISITING TIWARI FINANCIAL SOLUTIONS\n");
}
void viewlist()
{
    if(c==0 && cc==0)
    {
        printf("there is no account opened till now in this bank,neither current nor savings\n");
    }
    else if(c==0 && cc!=0)
    {
    printf("This is no savings account opened in the bank\n");
    printf("the list of all current account is as follows");
    printf("CURRENT ACCOUNT\n");
    for(int i=0;i<cc;i++)
    {
        printf("****This is the detail of %d customer****",i+1);
        printf("Name:%s\n",d1[i].name);
        printf("Sex:%c\n",d1[i].sex);
        printf("Age:%d\n",d1[i].age);
        printf("Phoneno:%s\n",d1[i].phoneno);
        printf("accountno:%d\n",d1[i].accountno); 
        printf("balance:%d\n",d1[i].balance);
    }
    }
    else if(c!=0 && cc==0)
    {
        printf("there is no current account opened till now\n");
        printf("the list of all savings account is as follows\n");
        for(int i=0;i<c;i++)
        {
            printf("****This is the detail of %d customer****\n",i+1);     
            printf("Name:%s\n",d[i].name);
            printf("Sex:%c\n",d[i].sex);
            printf("Age:%d\n",d[i].age);
            printf("Phoneno:%s\n",d[i].phoneno);
            printf("accountno:%d\n",d[i].accountno); 
            printf("balance:%d\n",d[i].balance);
        }
    }
    else
    {
        printf("the list of all savings account is as follows %d  %d\n",c,cc);
        for(int i=0;i<c;i++)
        {
            printf("****This is the detail of %d customer****\n",i+1);
            printf("Name:%s\n",d[c].name);
            printf("Sex:%c\n",d[c].sex);
            printf("Age:%d\n",d[c].age);
            printf("Phoneno:%s\n",d[c].phoneno);
            printf("accountno:%d\n",d[c].accountno); 
            printf("balance:%d\n",d[c].balance);
        }
        printf("the list of all current account is as follows");
        printf("CURRENT ACCOUNT\n");
        for(int i=0;i<cc;i++)
        {
        printf("****This is the detail of %d customer****",i+1);
        printf("Name:%s\n",d1[cc].name);
        printf("Sex:%c\n",d1[cc].sex);
        printf("Age:%d\n",d1[cc].age);
        printf("Phoneno:%s\n",d1[cc].phoneno);
        printf("accountno:%d\n",d1[cc].accountno); 
        printf("balance:%d\n",d1[cc].balance);
        }
    }
    
}
int deposit()
{
    int accno,x=25,y=25;
    int dep;
    int i;
    acno :
    printf("Enter your account number to deposit balance\n");
    scanf("%d",&accno);
    for(i=0;i<=c;i++);
    {
        if(accno==d[i].accountno)
        {
            x=i;
        }
    }
    if(x==25)
    {
        for(i=0;i<=cc;i++)
        {
            if(accno==d1[i].accountno)
            {
                y=i;
            }
        }
        if(y==25)
        {
            printf("THE ENTERED ACCOUNT NUMBER DOES NOT EXIST\n");
            printf("YOU NEED TO ENTER ACCOUNT NUMBER AGAIN\n");
            goto acno;
        }
        else
        {
            if(txnc[y]<10)
            {
            printf("enter amount to be deposited\n");
            scanf("%d",&dep);
            d1[y].balance=d1[y].balance+dep;
            printf("the amount is deposited\n");
            printf("curerent balance of account is %d",d1[y].balance);
            txnc[y]++;
            }
            else
            {
                printf("SORRY AMOUNT CANNOT BE DEPOSITED\n");
                printf(" YOU HAVE REACHED MAX NUMBER OF TRANSSACTION FOR YOUR CURRENT ACCOUNT\n");
            }
        }
    }
    else
    {
        if(txns[x]<3)
        {
        printf("enter amount to be deposited\n");
        scanf("%d",&dep);
        d[x].balance=d[x].balance+dep;
        printf("the amount is deposited\n");
        printf("curerent balance of account is %d",d[x].balance);
        txns[x]++;
        }
        else
        {
            printf("SORRY AMOUNT CANNOT BE DEPOSITED\n");
            printf(" YOU HAVE REACHED MAX NUMBER OF TRANSSACTION FOR YOUR SAVINGS ACCOUNT\n");
        }
    }
}
int withdraw()  
{
    int accno,x=25,y=25,i;
    int wid;
    widt :
    printf("enter your account number to deposit balance\n");
    scanf("%d",&accno);
    for(i=0;i<=c;i++);
    {
        if(accno==d[i].accountno)
        {
            x=i;
        }
    }
    if(x==25)
    {
        for(i=0;i<=cc;i++)
        {
            if(accno==d1[i].accountno)
            {
                y=i;
            }
        }
        if(y==25)
        {
            printf("THE ENTERED ACCOUNT NUMBER DOES NOT EXIST\n");
            printf("YOU NEED TO ENTER ACCOUNT NUMBER AGAIN\n");
            goto widt;
        }
        else
        {
            if(txnc[y]<10)
            {
            wmo :
            printf("enter amount to be widthdrawn\n");
            scanf("%d",&wid);
            if(wid>d1[y].balance)
            {
                printf("SORRY !!\n");
                printf("your accounts current balance is only%d\n",d1[y].balance);
                printf("so money cannot be withdrawn \n");
                printf("enter an amount which is less than or equal to %d\n",d1[y].balance);
                goto wmo;
            }
            else if(wid==d1[y].balance)
            {
            int st=0;
            printf("if you withdraw this amount then your account will be empty\n");
            printf("if you still want to withdraw then enter 1\n");
            scanf("%d",&st);
            if(st==1)
            {
                d1[y].balance=d1[y].balance-wid;
                printf("the amount is withdrawn\n");
                printf("curerent balance of account is %d",d1[y].balance);
                txnc[y]++;
            }
            else 
            {
                goto wmo;
            }
            }
            else if(wid<0)
            {
                printf("INVALID INPUT\n");
                printf("withdraw amount can not be negative\n");
                printf("YOU NEED TO ENTER THE AMOUNT TO BE WITHDRAWN AGAIN\n");
                goto wmo;
            }
            else
            {
                d1[y].balance=d1[y].balance-wid;
                printf("the amount is withdrawn\n");
                printf("curerent balance of account is %d",d1[y].balance);
                txnc[y]++;
            }
            }
            else
            {
                printf("SORRY AMOUNT CANNOT BE DEPOSITED\n");
                printf(" YOU HAVE REACHED MAX NUMBER OF TRANSSACTION FOR YOUR CURRENT ACCOUNT\n");
            }
        }
    }
    else
    {
        if(txns[x]<3)
        {
        wmos :
        printf("enter amount to be widthdrawn\n");
        scanf("%d",&wid);
        if(wid>d[x].balance)
        {
            printf("SORRY !!\n");
            printf("your accounts current balance is only%d\n",d[x].balance);
            printf("so money cannot be withdrawn \n");
            printf("enter an amount which is less than r equal to %d\n",d[x].balance);
            goto wmos;
        }
        else if(wid==d[x].balance)
        {
            printf("INVALID INPUT\n");
            printf("if you withdraw this amount then your account will be empty\n");
            printf("AND FOR YOUR SAVINGS ACCOUNT A MINIMUM BALANCE OF RS 1000 SHOULD BE MAINTAINED\n");
            printf("YOU NEED TO ENTER THE AMOUNT TO BE WITHDRAWN AGAIN\n");
            goto wmos;
        }
        else if((d[x].balance-wid)<1000)
        {
            printf("INVALID INPUT\n");
            printf("if you withdraw this amount then your account balance will be %d\n",d[x].balance-wid);
            printf("AND FOR YOUR SAVINGS ACCOUNT A MINIMUM BALANCE OF RS 1000 SHOULD BE MAINTAINED\n");
            printf("YOU NEED TO ENTER THE AMOUNT TO BE WITHDRAWN AGAIN\n");
            goto wmos;
        }
        else if(wid<0)
        {
            printf("INVALID INPUT\n");
            printf("withdraw amount can not be negative\n");
        }
        else
        {
            d[x].balance=d[x].balance-wid;
            printf("the amount is withdrawn\n");
            printf("curerent balance of account is %d",d[x].balance);
            txns[x]++;
        }
        }
        else
        {
            printf("SORRY AMOUNT CANNOT BE DEPOSITED\n");
            printf(" YOU HAVE REACHED MAX NUMBER OF TRANSSACTION FOR YOUR SAVINGS ACCOUNT\n");
        }
    }
    }
int balance()
{
    int acno;
    int x=25,y=25,i;
    bal :
    printf("enter your account number to view balance\n");
    scanf("%d",&acno);
    for(i=0;i<=c;i++);
    {
        if(acno==d[i].accountno)
        {
            x=i;
        }
    }
    if(x==25)
    {
        for(i=0;i<=cc;i++)
        {
            if(acno==d1[i].accountno)
            {
                y=i;
            }
        }
        if(y==25)
        {
            printf("THE ENTERED ACCOUNT NUMBER DOES NOT EXIST\n");
            printf("YOU NEED TO ENTER ACCOUNT NUMBER AGAIN\n");
            goto bal;
        }
        else
        {
            printf("balance of your current account is %d\n",d1[y].balance);
        }
    }
    else
    {
        printf("balance of your savings account is %d\n",d[x].balance);
    }
}
int modify()
{
    int mdf;
    int x=25,i;
    mdfa :
    printf("enter your account number to view balance\n");
    scanf("%d",&mdf);
    for(i=0;i<=c;i++);
    {
        if(mdf==d[i].accountno)
        {
            x=i;
        }
    }
    if(x==25)
    {
        int y =25;
        for(i=0;i<cc;i++)
        {
            if(mdf==d1[i].accountno)
            {
                y=i;
            }
        }
        if(y==25)
        {
        printf("INVALID ACCOUNT NNUMBER OR YOUR account does not exist\n");
        printf("need to enter account number again\n");
        goto mdfa;
        }
        else
        {
        printf("*         CHOOSE WHAT WOULD YOU LIKE TO MODIFY                             *\n");
        printf("*                 1)ACCOUNT NUMBER                                         *\n");
        printf("*                 2)AGE                                                    *\n");
        printf("*                 3)SEX                                                    *\n");
        printf("*                 4)NAME                                                   *\n");
        printf("*                 5)PHONE NUMBER                                           *\n");
        int mdfcc;
        modcc :
        scanf("%d",&mdfcc);
        switch(mdfcc)
        {
            case 1:
            {
                int nacc;
                eacc :
                printf("enter new account number\n");
                printf("the account number must be of 4 digits");
                scanf("%d",&nacc);
                if(nacc>999 && nacc<10000)
                {
                    d1[y].accountno=nacc;
                    printf("your account number has been changed to %d",nacc);
                }
                else
                {
                    printf("invalid input\n");
                    printf("enter account number again");
                    goto eacc;
                }
                break;
            }
            case 2:
            {
                int nagec;
                ngec :
                printf("enter the age to be updated\n");
                scanf("%d",&nagec);
                if(nagec>=18)
                {
                    d1[y].age=nagec;
                    printf("your age has been updated to %d\n",nagec);
                }
                else
                {
                    printf("invalid input\n");
                    printf("please enter age greator than 18\n");
                    goto ngec;
                }
                break;
            }
            case 3:
            {
                char genc;
                sxc :
                printf("enter the gender to be updated\n");
                scanf("%c",&genc);
                if(genc =='M' || genc =='F' == genc =='T' || genc =='m' || genc =='f' || genc =='t')
                {
                    d1[y].sex=genc;
                    printf("your gender is updated to %c",genc);
                }
                else
                {
                    printf("invalid input\n");
                    printf("please enter 'm','f','t','M','F','T'\n");
                    goto sxc;
                }
                break;
            }
            case 4:
            {
                char nmc[100];
                int kc=0;
                nmu :
                printf("enter the name to be updated\n");
                scanf("%[^\n]s",nmc);
                for(int i=0;i<strlen(nmc);i++)
                {
                    if((nmc[i]<65) || ((nmc[i]>90) && (nmc[i]<97)) || (nmc[i]>122))
                    {
                        if(nmc[i]!=' ')
                        {
                        kc++;
                        }
                    }
                }
                if(kc==0)
                {
                    strcpy(d1[y].name,nmc);
                }
                else
                {
                    printf("invalid input\n");
                    printf("please enter a valid name\n");
                    goto nmu;
                }
                break;
            }
            case 5:
            {
                char numc[10];
                int pkc=0;
                pk1c :
                printf("Enter the phone number:");
                scanf("%s",&numc);
                for(int i=0;i<10;i++)
                {
                    if(((int)numc[i]<48) || ((int)numc[i]>57))
                     {
                        pkc++;
                    }
                }
                if(pkc>0)
                {
                    printf("invalid input\n");
                    printf("please enter a valid number\n");
                    goto pk1c;
                }
                else
                {
                    strcpy(d1[y].phoneno,numc);
                    printf("your phone number has been updated to %s\n",numc);
                }
                break;
            }
            default :
            {
                printf("invaid choice for modification\n");
                printf("please enter your choice again\n");
                goto modcc;
                break;
            }
        }
        }
    }
    else
         {
        printf("*         CHOOSE WHAT WOULD YOU LIKE TO MODIFY                             *\n");
        printf("*                 1)ACCOUNT NUMBER                                         *\n");
        printf("*                 2)AGE                                                    *\n");
        printf("*                 3)SEX                                                    *\n");
        printf("*                 4)NAME                                                   *\n");
        printf("*                 5)PHONE NUMBER                                           *\n");
        int mdfa;
        modc :
        scanf("%d",&mdfa);
        switch(mdfa)
        {
            case 1:
            {
                int nac;
                eac :
                printf("enter new account number\n");
                printf("the account number must be of 4 digits");
                scanf("%d",&nac);
                if(nac>999 && nac<10000)
                {
                    d[x].accountno=nac;
                    printf("your account number has been changed to %d",nac);
                }
                else
                {
                    printf("invalid input\n");
                    printf("enter account number again");
                    goto eac;
                }
                break;
            }
            case 2:
            {
                int nage;
                nge :
                printf("enter the age to be updated\n");
                scanf("%d",&nage);
                if(nage>=18)
                {
                    d[x].age=nage;
                    printf("your age has been updated to %d\n",nage);
                }
                else
                {
                    printf("invalid input\n");
                    printf("please enter age greator than 18\n");
                    goto nge;
                }
                break;
            }
            case 3:
            {
                char gen;
                sx :
                printf("enter the gender to be updated\n");
                scanf("%c",&gen);
                if(gen == 'M' || gen =='F' || gen =='T' || gen =='m' || gen =='f' || gen =='t')
                {
                    d[x].sex=gen;
                    printf("your gender is updated to %c",gen);
                }
                else
                {
                    printf("invalid input\n");
                    printf("please enter 'm','f','t','M','F','T'\n");
                    goto sx;
                }
                break;
            }
            case 4:
            {
                char nm[100];
                int k=0;
                nmur :
                printf("enter the name to be updated\n");
                scanf("%[^\n]s",nm);
                for(int i=0;i<strlen(nm);i++)
                {
                    if((nm[i]<65) || ((nm[i]>90) && (nm[i]<97)) || (nm[i]>122))
                    {
                         if(nm[i]!=' ')
                        {
                        k++;
                        }
                    }
                }
                if(k==0)
                {
                    strcpy(d[x].name,nm);
                }
                else
                {
                    printf("invalid input\n");
                    printf("please enter a valid name\n");
                    goto nmur;
                }
                break;
            }
            case 5:
            {
                char num[10];
                int pk=0;
                pk1 :
                printf("Enter the phone number:");
                scanf("%s",&num);
                for(int i=0;i<10;i++)
                {
                    if(((int)num[i]<48) || ((int)num[i]>57))
                     {
                        pk++;
                    }
                }
                if(pk>0)
                {
                    printf("invalid input\n");
                    printf("please enter a valid number\n");
                    goto pk1;
                }
                else
                {
                    strcpy(d[x].phoneno,num);
                    printf("your phone number has been updated to %s\n",num);
                }
                break;
            }
            default :
            {
                printf("invaid choice for modification\n");
                printf("please enter your choice again\n");
                goto modc;
                break;
            }
        }
        }
}
void createaccc()
{
    if(cc<4)
    {
    int k=0,i;
    accw :
    k=0;
    printf("ENTER THE NAME OF THE ACCOUNT HOLDER\n");
    scanf("%[^\n]s",&d1[cc].name);
    fflush(stdin);
    for(i=0;i<strlen(d1[cc].name);i++)
    {
        if((d1[cc].name[i]<65) || ((d1[cc].name[i]>90) && (d1[cc].name[i]<97)) || (d1[cc].name[i]>122) )
        {
            if(d1[cc].name[i]!=' ')
            {
           k++;
            }
        }
    }
    if(k>0)
    {
        printf("invalid name\n");
        printf("enter a valid name\n");
        goto accw;
    }
    genw :
    printf("Enter your sex as[M,F,T]:");
    scanf("%c",&d1[cc].sex);
    fflush(stdin);
    if(d1[cc].sex!='M' && d1[cc].sex!='F' && d1[cc].sex!='T' && d1[cc].sex!='m' && d1[cc].sex!='f' && d1[cc].sex!='t')
    {
        printf("Invalid gender");
        printf("YOU NEED TO ENTER YOUR GENDER AGAIN");
        goto genw;
    }
    int acnoc;
    int anr=0,anrc=0;
    acnc :
    printf("Enter the Account number\n");
    printf("account  umber must be of 4 digits");
    scanf("%d",&acnoc);
    fflush(stdin);
    if(acnoc<1000 || acnoc>9999)
    {
        printf("invalid account number\n");
        printf("YOU NEED TO ENTER A 4 DIGIT INTEGER");
        printf("please enter account number again\n");
        goto acnc;
    }
    anr=0;
    anrc=0;
    for(i=0;i<cc;i++)
    {
        if(acnoc==d1[i].accountno)
        {
            anr++;
        }
    }
    if(anr>0)
    {
        printf("THE ENTERED ACCOUNT UMBER ALREADY EXISTS\n");
        printf("TRY ANOTHER ACCOUNT NUMBER\n");
        goto acnc;
    }
    else
    {
        for(i=0;i<c;i++)
        {
        if(acnoc==d[i].accountno)
        {
            anrc++;
        }
        }
        if(anrc>0)
        {
            printf("THE ENTERED ACCOUNT nUMBER ALREADY EXISTS\n");
            printf("TRY ANOTHER ACCOUNT NUMBER\n");
            goto acnc;
        }
        else
        {
            d1[cc].accountno=acnoc;
        }
    }
    agec:
    printf("Enter the age of the account holder:");
    scanf("%d",&d1[cc].age);
    fflush(stdin);
    if(d1[cc].age<18)
    {
        printf("Invalid age!!!!");
        printf("TO OPEN AN ACCOUNT ,YOU NEED TO BE ABOVE 18 YEARS OF AGE");
        goto agec;
    }
    int kpn=0;
    pnc:
    kpn=0;
    printf("Enter the phone number:");
    scanf("%[^\n]s",&d1[cc].phoneno);
    fflush(stdin);
    for(int i=0;i<10;i++)
    {
        if(((d1[cc].phoneno[i]<48) || (d1[cc].phoneno[i]>57)))
        {
            kpn++;
        }
    }
    if(kpn>0)
    {
        printf("invalid phone number entered\n");
        printf("you need to enter phone number again\n");
        goto pnc;
    }
    printf("enter the initial amount you need to deposit\n");
    printf("*                 1)DEPOSIT                           *\n");
    printf("*                 2)DONT DEPOSIT ANY AMOUNT           *\n");
    int cma;
    scanf("%d",&cma);
    switch(cma)
    {
        case 1:
        {
            printf("enter amount to be deposited\n");
            scanf("%d",&d1[cc].balance);
            fflush(stdin);
             printf("the amount is deposited\n");
             break;
        }
        case 2:
        {
            d1[cc].balance=0;
            printf("your account is created with zero balance\n");
            break;
        }
    }
    printf("your account is created\n ");
    printf("YOUR ACCOUNT HAS BEEN CREATED WITH THE FOLLOWING ATTRIBUTES :-\n");
    printf("Name:%s\n",d1[cc].name);
    printf("Sex:%c\n",d1[cc].sex);
    printf("Age:%d\n",d1[cc].age);
    printf("Phoneno:%s\n",d1[cc].phoneno);
    printf("accountno:%d\n",d1[cc].accountno);
    printf("balance:%d\n",d1[cc].balance);
    printf("THANK YOU FOR CREATING ACCOUNT IN TIWARI FINANCE SOLUTIONS\n");
    printf("YOU WILL BE PROVIDED WITH THE BEST SERVICES HERE\n");
    cc++;
    }
    else
    {
        printf("SORRY!!\n");
        printf("the maximum count for account holders reached\n");
        printf("we will not be able to create an account for you in our bank\n");
        printf("BUT IF YOU ALREADY HAVE AN ACCOUNT IN TIWARI FINANCE SOLUTIONS, YOU ARE WELCOME FOR ALL OHETR SERVICES\n");
    }
}
void createaccs()
{ 
    if(c<4)
    {
        int k=0,i;
        printf("THIS IS CREATE ACCOUNT FUNCTION\n");
    x1:
    k=0;
    printf("Enter the name of the Account holder:\n");
    scanf("%[^\n]s",&d[c].name);
    fflush(stdin);
    for(i=0;i<strlen(d[c].name);i++)
    {
        if((d[c].name[i]<65) || ((d[c].name[i]>90) && (d[c].name[i]<97)) || (d[c].name[i]>122) )
        {
        if(d[c].name[i]!=' ')
        {
           k++;
        }
        }
    }
    if(k>0)
    {
        printf("invalid name\n");
        printf("enter a valid name\n");
        goto x1;
    }
    x2:
    printf("Enter your sex as[M,F,T]:\n");
    scanf("%c",&d[c].sex);
    fflush(stdin);
    if(d[c].sex!='M' && d[c].sex!='F' && d[c].sex!='T' && d[c].sex!='m' && d[c].sex!='f' && d[c].sex!='t')
    {
        printf("Invalid!!");
        goto x2;
    }
    int anr=0,anrc=0;
    int acnoc;
    acn :
    anr=0;
    anrc=0;
    printf("Enter the Account number\n");
    printf("account  umber must be of 4 digits\n");
    scanf("%d",&acnoc);
    fflush(stdin);
    if(acnoc<1000 || acnoc>9999)
    {
        printf("invalid account number\n");
        printf("YOU NEED TO ENTER A 4 DIGIT INTEGER\n");
        printf("please enter account number again\n");
        goto acn;
    }
    for(i=0;i<c;i++)
    {
        if(acnoc==d[i].accountno)
        {
            anr++;
        }
    }
    if(anr>0)
    {
        printf("account number already used\n");
        printf("try another account number\n");
        goto acn;
    }
    else
    {
        for(i=0;i<cc;i++)
        {
        if(acnoc==d1[i].accountno)
        {
            anrc++;
        }
        }
        if(anrc>0)
        {
            printf("THE ENTERED ACCOUNT UMBER ALREADY EXISTS\n");
            printf("TRY ANOTHER ACCOUNT NUMBER\n");
            goto acn;
        }
        else
        {
            d[c].accountno=acnoc;
        }
    }
    x3:
    printf("Enter the age of the account holder:\n");
    scanf("%d",&d[c].age);
    fflush(stdin);
    if(d[c].age<18)
    {
        printf("Invalid age!!!!\n");
        goto x3;
    }
    int phns=0;
    x4:
    phns=0;
    printf("Enter the phone number:\n");
    scanf("%d",&d[c].phoneno);
    fflush(stdin);
    for(int i=0;i<10;i++)
    {
        if(((d[c].phoneno[i]<48) && (d[c].phoneno[i]>57)))
        {
            phns++;
        }
    }
    if(phns>0)
    {
        printf("INVALID INPUT\n");
        printf("YOU NEED TO ENTER ACCOUNT NUMBER AGAIN\n");
        goto x4;
    }
    amtd :
    printf("enter the initial amount you need to deposit\n");
    printf("*                 1)DEPOSIT                           *\n");
    printf("*                 2)DONT DEPOSIT ANY AMOUNT           *\n");
    int balamt;
    int cma;
    scanf("%d",&cma);
    fflush(stdin);
    switch(cma)
    {
        case 1:
        {
            printf("enter amount to be deposited\n");
            scanf("%d",&balamt);
            fflush(stdin);
            if(balamt<1000)
            {
                printf("INVALID AMOUNT ENTERED\n");
                printf("MIN BALANCE TO BE MAINTAINED IS RS 1000\n");
                printf("PLEASE ENTER AN AMOUNT WHICH IS GREATOR THAN OR EQUAL TO RS 1000\n");
                goto amtd;
            }
            else
            {
                d1[cc].balance=balamt;
             printf("the amount is deposited\n");
             printf("your account has been created with initial balance of RS %d\n :-",d1[cc].balance);
            }
            break;
            }
        case 2:
        {
            printf("SORRY!!!\n");
            printf("TO CREATE A SAVINGS ACCOUNT YOU NEED TO MAINTAIN A MINIMUM BALANCE OF RS 1000\n");
            goto amtd;
            break;
        }
    }
    printf("your account is created\n ");
    printf("your account is created\n ");
    printf("YOUR ACCOUNT HAS BEEN CREATED WITH THE FOLLOWING ATTRIBUTES :-\n");
    printf("Name:%s\n",d[c].name);
    printf("Sex:%c\n",d[c].sex);
    printf("Age:%d\n",d[c].age);
    printf("Phoneno:%s\n",d[c].phoneno);
    printf("accountno:%d\n",d[c].accountno);
    printf("balance:%d\n",d[c].balance);
    printf("THANK YOU FOR CREATING ACCOUNT IN TIWARI FINANCE SOLUTIONS\n");
    printf("YOU WILL BE PROVIDED WITH THE BEST SSERVICES HERE\n");
    c++;
    }
    else
    {
        printf("SORRY!!\n");
        printf("the maximum count for account holders reaches\n");
        printf("we will not be able to create an account for you in our bank\n");
        printf("BUT IF YOU ALREADY HAVE AN ACCOUNT IN TIWARI FINANCE SOLUTIONS, YOU ARE WELCOME FOR ALL OHETR SERVICES\n");
    }
}

int interface5()
{
    int n5;
    printf("*                 PLEASE SELECT AN OPTION TO CONTINUE                  *\n");
    printf("*                                                                      *\n");
    printf("*                 1)TO DEPOSIT AMOUNT                                  *\n");
    printf("*                 2)TO WITHDRAW AN AMOUNT                              *\n");
    printf("*                 3)TO ENQUIRE THE BALANCE AMOUNT                      *\n");
    printf("*                 4)TO MODIFY AN ACCOUNT                               *\n");
    scanf("%d",&n5);
    fflush(stdin);
    return n5;

}
int interface4()
{
    int n4;
    printf("*                    CHOOSE ONE OF THE FOLLOWING                       *\n");
    printf("*                                                                      *\n");
    printf("*                  1)VIEW THE LIST OF ALL ACCOUNT HOLDERS              *\n");
    printf("*                  2)EXIT                                              *\n");
    scanf("%d",&n4);
    fflush(stdin);
    return n4;
}
int interface1()
{
    int n;
    printf("*-----------------WELCOME TO TIWARI FINANCE SOLUTIONS------------------*\n");
    printf("*                                                                      *\n");
    printf("*                 PLEASE SELECT YOUR DESIGNATION                       *\n");
    printf("*                                                                      *\n");
    printf("*                 1)NEW CUSTOMER                                       *\n");
    printf("*                 2)BANK EMPLOYEE                                      *\n");
    printf("*                 3)EXISTING USER                                      *\n");
    printf("*                 4)EXIT                                               *\n");
    scanf("%d",&n);
    fflush(stdin);
    return n;
}
int interface6()
{
    int ch;
    printf("     TIWARI FINANCE SOLUTIONS PROVIDES THE FOLLOWING TWO TYPES OF BANK ACCOUNTS       *\n");
    printf("*              PLEASE SELECT THE TYPE OF ACCOUNT YOU NEED TO OPEN                     *\n");
    printf("*                               1)CURRENT ACCOUNT                                     *\n");
    printf("*                               2)SAVINGS ACCOUNT                                     *\n");
    printf("*    3)PRESS 3 TO VIEW THE DIFFERENCE IN SERVICES FOR THE TWO TYPES OF BANK ACCOUNT   *\n");
    scanf("%d",&ch);
    fflush(stdin);
    return ch;
}
int interface7()
{
    printf("*                   1)SAVINGS ACCOUNT :-                                                    *\n");
    printf("*                                                                                           *\n");
    printf("*       -YOU WILL BE ALLOWED TO MAKE ONLY THREE TRANSACTIONS                                *\n");
    printf("*       -MAX BALANCE YOU WILL BE ALLOWED TO STORE WILL BE RS 500000                         *\n");
    printf("*       -YOU WILL HAVE TO MAINTAIN A MINIMUM BALANCE OF RS 1000                             *\n");
    printf("*                                                                                           *\n");
    printf("*                    2)CURRENT ACCOUNT                                                      *\n");
    printf("*       -YOU WILL BE ALLOWED TO MAKE A TOTAL OF 10 TRANSACTIONS                             *\n");
    printf("*       -MAX BALANCE YOU ARE ALLOWED TO STORE IS 100000                                     *\n");
    printf("*       -NO MINIMUM BALANCE MAINTAINANCE REQUIRED                                           *\n");
    printf("*                                                                                           *\n");
    printf("*  NOTE :- THE COUNT OF TRANSACTIONS IS INCLUSIVE OF DEPOSIT AS WELL AS WITHDRAWL           *\n");
    printf("*                  ENTER ANY INTEGER TO CONTINUE                                            *\n");
}
int requirements()
{
    printf("*                           YOU NEED TO HAVE THE FOLLOWING DETAILS IN ORDER TO OPEN A BANK ACCOUNT              *\n");
    printf("*                                                                                                               *\n");
    printf("*                                 NAME OF THE ACCOUNT HOLDER                                                    *\n");
    printf("*                                 PHONE NUMBER OF THE ACCOUNT HOLDER                                            *\n");
    printf("*                                 GENDER OF THE ACCOUNT HOLDER                                                  *\n");
    printf("*                                 AGE OF THE ACCOUNT HOLDER                                                     *\n");
    printf("*                                                                                                               *\n");
    printf("*   IF YOU ARE MISSING WITH ANY ONE OF THE ABOVE MENTIONED DETAILS , PLEASE COLLECT THEM AND THEN PROCEED       *\n");
}
int interface3()
{
    int n3;
    printf("*                 -ADD A NEW ACCOUNT                                  *\n");
    printf("*                 -TO DEPOSIT AMOUNT                                  *\n");
    printf("*                 -TO WITHDRAW AN AMOUNT                              *\n");
    printf("*                 -TO ENQUIRE THE BALANCE AMOUNT                      *\n");
    printf("*                 -TO VIEW ALL ACCOUNT HOLDER LIST                    *\n");
    printf("*                 -TO MODIFY AN ACCOUNT                               *\n");
    printf("*                 PRESS 1 TO CREATE A NEW ACCOUNT                     *\n");
    printf("*                 PRESS 2 TO EXIT                                     *\n");
    scanf("%d",&n3);
    fflush(stdin);
    return n3;
}
int interface2()
{
    int n1;
    printf("*           CHOOSE DESIRED OPTION                                *\n"); 
    printf("*           1)CREATE ACCOUNT                                     *\n");  
    printf("*           2)VIEW SERVICES OF TIWARI BANKING SOLUTIONS          *\n");
    scanf("%d",&n1);
    fflush(stdin);
    return n1;
}
int main()
{
    int n1,exitwh=0;
    while (exitwh==0)
    {
    n1=interface1();
    switch(n1)
    {
        case 1:
        {
          int n2;
          W2 :
          n2=interface2();
          switch(n2)
          {
            case 1:
            {
                int acct;
                int6 :
                acct=interface6();
                switch(acct)
                {
                    case 1:
                    {
                        requirements();
                        createaccs();
                        break ;
                    }
                    case 2:
                    {
                        requirements();
                        createaccc();
                        break ;
                    }
                    case 3:
                    {
                        interface7();
                        break ;
                    }
                    default :
                    {
                        printf("INVALID CHOICE\n");
                        printf("PLEASE ENTER A VALID CHOICE \n");
                        goto int6;
                        break ;
                    }
                }
                break ;
            }
            case 2:
            {
                int n3;
                W1 :
                n3=interface3();
                switch(n3)
                {
                    case 1:
                    {
                        int act;
                        act1 :
                        act=interface6();
                        switch(act)
                        {
                            case 1:
                            {
                                requirements();
                                createaccs();
                                break ;
                            }
                            case 2:
                            {
                                requirements();
                                createaccc();
                                break ;
                            }
                            case 3:
                            {
                                interface7();
                                break ;
                            }
                            default :
                            {
                                printf("INVALID CHOICE\n");
                                printf("PLEASE ENTER A VALID CHOICE \n");
                                goto act1;
                                break ;
                            }
                        }
                        break ;
                    }
                    case 2:
                    {
                        EXIT();
                        exitwh=1;
                        break ;
                    }
                    default :
                    {
                        printf("WRONG CHOICE \n");
                        printf("*BEING A NEW UDER YOU CAN EITHER CREATE A NEW ACCOUNT OR EXIT THE BANK*\n");
                        printf("ENTER CHOICE AGAIN\n");
                        goto W1;
                        break ;
                    }
                }
                break ;
            }
            default :
            {
                printf("WRONG INPUT\n");
                printf("PLEASE RE-ENTER YOUR CHOICE\n"); 
                goto W2;
                break ;
            }
            break ;
         }
         break;
        }
        case 2:
        {
            int n4;
            W3 :
            n4=interface4();
            switch(n4)
            {
            case 1:
            {
                viewlist();
                break ;
            }
            case 2:
            {
                EXIT();
                exitwh=1;
                break ;
            }
            default :
            {
                printf("WRONG INPUT\n");
                printf("PLEASE RE-ENTER YOUR CHOICE\n"); 
                goto W3;
                break ;
            }
            }
            break ;
        }
        case 3:
        {
            int n5;
            W4 :
            n5=interface5();
            switch(n5)
            {
               case 1:
               {
                  deposit();
                  break ;
               }
               case 2:
               {
                  withdraw();
                  break ;
               }
               case 3:
               {
                  balance();
                  break ;
               }
               case 4:
               {
                  modify();
                  break ;
               }
               case 5:
               {
                EXIT();
                exitwh=1;
                break ;
               }
               default :
               {
                printf("WRONG INPUT\n");
                printf("PLEASE RE-ENTER YOUR CHOICE\n"); 
                goto W4;
                break ;
               }
            }
            break ;
        }
        case 4:
        {
            EXIT();
            exitwh=1;
            break ;
        }
    }
 }
    return 0;
}
