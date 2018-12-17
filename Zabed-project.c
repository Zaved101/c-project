#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

int a;

struct doctor
{
    char d_name[100];
    char d_des[100];
    char d_phn_n[50];
    char d_avl_t[100];
}D,D1;

struct patient
{
  char p_name[100];
  char p_age[100];
  char p_sex[10];
  char p_cn[100];
  char p_addate[100];
}p,p1;

struct employee
{
    char e_name[100];
    char e_des[100];
    char e_cn[100];
}e,e1;

struct staff
{
    char s_name[100];
    char s_pos[100];
    char s_cn[100];
}s,s1;



int main(void)
{
    system("cls");
    system("COLOR 30");
    printf("\n\t\t||::::::::::::::::::::::::::::::::::::::::::||");
    printf("\t\t\t\t\t||:::::[HOSPITAL MANAGEMENT SYSTEM]:::::::::||\n");
    printf("\t\t||::::::::::::::::::::::::::::::::::::::::::||\n");
    Sleep(500);
    while(main_home()){}
    return 0;
}

int main_home()
{
    int go;
    printf("\n\t\t  1.DOCTOR INFO");
    printf("\n\t\t  2.PATIENT INFO");
    printf("\n\t\t  3.BILLING");
    printf("\n\t\t  4.EMPLOYEE INFO");
    printf("\n\t\t  5.STAFF INFO");
    printf("\n\n\t\t  [SELECT AN OPTION OR PRESS [0] TO EXIT] :");
    fflush(stdin);
    while(scanf("%d",&go))
    {
        if(go==1 || go==2 || go==3 || go==4 || go==5 || go==0)
        {
         if(go==1)
         {
             D_home();
             break;
         }
         if(go==2)
         {
             p_home();
             break;
         }
         if(go==3)
         {
             billing();
             break;
         }
         if(go==4)
         {
             e_home();
             break;
         }
         if(go==5)
         {
           s_home();
         }
         if(go==0)
         {
             ext();
             break;
         }
        }
        printf("\n  **Invalid Input, You Press Wrong Input, Read Option's Carefully :");
        printf(">:");
        fflush(stdin);
    }
    return 0;
}





int D_home()
{
    system("cls");
    int go;
    printf("\n  [DOCTOR HOME PAGE]\n");
    printf("\n  !![PRESS [1] TO STORE DOCTOR INFORMATION]");
    printf("\n  !![PRESS [2] TO VIEW ALL DOCTOR INFORMATION]");
    printf("\n  !![PRESS [3] TO DELETE INFO]");
    printf("\n  !![PRESS [4] TO SEARCH DOCTOR INFORMATION]");
    printf("\n  !![PRESS [0] TO EXIT]");
    printf("\n  ##SELECT A OPTION:>:");
    while(scanf("%d",&go))
    {
        if(go==1 || go==2 || go==3 || go==4 || go==0)
        {
         if(go==1)
         {
             save_d();
             break;
         }
         if(go==2)
         {
             show_d();
             break;
         }
         if(go==3)
         {
             d_delete();
             break;
         }
         if(go==4)
         {
            d_search();
            break;
         }
         if(go==0)
         {
             ext();
             break;
         }
        }
        printf("\n  **Invalid Input, You Press Wrong Input, Read Option's Carefully :");
        printf(">:");
        fflush(stdin);
    }
    return 0;
}

int save_d()
{
    system("cls");
    printf("\n  [SAVE DOCTOR INFO PAGE]\n");
    FILE *fp_d;
    fp_d=fopen("Doctor info.txt","a");
    if(fp_d==NULL)
    {
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    printf("  Enter Doctor Name:");
    gets(D.d_name);
    printf("  Enter Doctor Designation:");
    gets(D.d_des);
    printf("  Enter Doctor Phone Number:");
    gets(D.d_phn_n);
    printf("  Enter Doctor Available Time:");
    gets(D.d_avl_t);

    fwrite(&D, sizeof(D), 1, fp_d);
    printf("\n\n  [!!! SAVE SUCCESSFUL !!!]\n");
    fclose(fp_d);
printf("Press [1] for Doctor Home Page\nPress [2] for Homepage\n");


while(scanf("%d",&a))
{
    if(a==1)
    {
        D_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int show_d()
{
    system("cls");
    printf("\n  [ALL DOCTOR INFORMATION]\n");
    FILE *fp_d_s;
    fp_d_s=fopen("Doctor info.txt","r");
    while(fread(&D, sizeof(D), 1, fp_d_s))
    {
        printf("\n  Doctor Name: %s\n  Doctor Designation: %s\n  Doctor Phone Number: %s\n  Doctor Available Time: %s\n",D.d_name,D.d_des,D.d_phn_n,D.d_avl_t);
    }
    fclose(fp_d_s);
    printf("Press [1] for Doctor Home Page\nPress [2] for Homepage\n");
    while(scanf("%d",&a))
{
    if(a==1)
    {
        D_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}


int d_delete()
{
    FILE *dlt,*dlt1;
    struct doctor D,D1;
    int found=0;
    char nm[30];
    dlt=fopen("Doctor info.txt","r");
    dlt1=fopen("Delete.txt","w");
    fflush(stdin);
    printf("ENTER THE NAME YOU WANT TO DELETE:");
    gets(nm);
    while( fread(&D1, sizeof(D1), 1, dlt))
    {
        if(feof(dlt))
        {
            break;
        }
        if(strcmp(nm,D1.d_name)==0)
        {
            found=1;
            printf("\nDelete Successfully\n");
        }
        else
        {
            fwrite(&D1, sizeof(D1), 1, dlt1);
        }
    }
    fclose(dlt);
    fclose(dlt1);
    if(found==0)
    {
        printf("Sorry not Found\n\n");
    }
    else
    {
        dlt=fopen("Doctor info.txt","w");
        dlt1=fopen("Delete.txt","r");
        while(1)
        {
            fread(&D1,sizeof(D1), 1, dlt1);
            if(feof(dlt1))
            {
                break;
            }
            fwrite(&D1, sizeof(D1), 1, dlt);
        }
    }
    fclose(dlt);
    fclose(dlt1);
    printf("Press [1] for Doctor Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        D_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}


int d_search()
{
    FILE *d_srch;
    d_srch=fopen("Doctor info.txt","r");
    char b[20];
    printf("Write the File Name You Want To Show:\n");
    printf("==>");
    scanf("%s",b);
    while(fread(&D, sizeof(D), 1, d_srch))
    {
        if(strcmp(b,D.d_name)==0)
            printf("\n  Doctor Name: %s\n  Doctor Designation: %s\n  Doctor Phone Number: %s\n  Doctor Available Time: %s\n",D.d_name,D.d_des,D.d_phn_n,D.d_avl_t);
    }
    fclose(d_srch);
    printf("Press [1] for Doctor Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        D_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}



int p_home()
{
    int go;
    system("cls");
    printf("\n  [PATIENT HOME PAGE]\n");
    printf("\n  !![PRESS [1] TO STORE PATIENT INFORMATION]");
    printf("\n  !![PRESS [2] TO VIEW ALL PATIENT INFORMATION]");
    printf("\n  !![PRESS [3] TO DELETE PATIENT INFO]");
    printf("\n  !![PRESS [4] TO SEARCH PATIENT INFO");
    printf("\n  !![PRESS [0] TO EXIT]");
    printf("\n  ##SELECT A OPTION:>:");
    while(scanf("%d",&go))
    {
        if(go==1 || go==2 || go==3 || go==4 || go==0)
        {
         if(go==1)
         {
             save_p();
             break;
         }
         if(go==2)
         {
             show_p();
             break;
         }
         if(go==3)
         {
             p_delete();
             break;
         }
         if(go==4)
         {
             p_search();
             break;
         }
         if(go==0)
         {
             ext();
             break;
         }
        }
        printf("\n  **Invalid Input, You Press Wrong Input, Read Option's Carefully :");
        printf(">:");
        fflush(stdin);
    }
    return 0;
}

int save_p()
{
    system("cls");
    printf("\n  [SAVE PATIENT INFO PAGE]\n");
    FILE *fp_p;
    fp_p=fopen("PATIENT info.txt","a");
    if(fp_p==NULL)
    {
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    printf("  Enter Patient Name:");
    gets(p.p_name);
    printf("  Enter Patient Age:");
    gets(p.p_age);
    printf("  Enter Patient Sex:");
    gets(p.p_sex);
    printf("  Enter Patient Phone Number:");
    gets(p.p_cn);
    printf("Enter Patient Admission Date:");
    gets(p.p_addate);
    fwrite(&p, sizeof(p), 1, fp_p);
    printf("\n\n  [!!! SAVE SUCCESSFUL !!!]\n");
    fclose(fp_p);
    printf("Press [1] for Patient Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        p_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}


int show_p()
{
    system("cls");
    printf("\n  [ALL PATIENT INFORMATION]\n");
    FILE *fp_p_s;
    fp_p_s=fopen("PATIENT info.txt","r");
    while(fread(&p, sizeof(p), 1, fp_p_s))
    {
        printf("\n  Patient Name: %s\n  Patient age: %s\n Patient Sex: %s\n Patient Phone Number: %s\n  Patient Admission Date: %s ",p.p_name,p.p_age,p.p_sex,p.p_cn,p.p_addate);
    }
    fclose(fp_p_s);

    printf("Press [1] for Patient Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        p_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int p_delete()
{
    FILE *p_dlt,*p_dlt1;
    struct patient p,p1;
    int found=0;
    char p_nm[30];
    p_dlt=fopen("Patient info.txt","r");
    p_dlt1=fopen("Delete.txt","w");
    fflush(stdin);
    printf("ENTER THE NAME YOU WANT TO DELETE:");
    gets(p_nm);
    while( fread(&p1, sizeof(p1), 1, p_dlt))
    {
        if(feof(p_dlt))
        {
            break;
        }
        if(strcmp(p_nm,p1.p_name)==0)
        {
            found=1;
            printf("\nDelete Successfully\n");
        }
        else
        {
            fwrite(&p1, sizeof(p1), 1, p_dlt1);
        }
    }
    fclose(p_dlt);
    fclose(p_dlt1);
    if(found==0)
    {
        printf("Sorry not Found\n\n");
    }
    else
    {
        p_dlt=fopen("Patient info.txt","w");
        p_dlt1=fopen("Delete.txt","r");
        while(1)
        {
            fread(&p1,sizeof(p1), 1, p_dlt1);
            if(feof(p_dlt1))
            {
                break;
            }
            fwrite(&p1, sizeof(p1), 1, p_dlt);
        }
    }
    fclose(p_dlt);
    fclose(p_dlt1);

    printf("Press [1] for Patient Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        p_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}


int p_search()
{
    FILE *p_srch;
    p_srch=fopen("Patient info.txt","r");
    char p_s[20];
    printf("Write the File Name You Want To Show:\n");
    printf("==>");
    scanf("%s",p_s);
    while(fread(&p, sizeof(p), 1, p_srch))
    {
        if(strcmp(p_s,p.p_name)==0)
            printf("\n  Patient Name: %s\n  Patient age: %s\n Patient Sex: %s\n Patient Phone Number: %s\n  Patient Admission Date: %s ",p.p_name,p.p_age,p.p_sex,p.p_cn,p.p_addate);
    }
    fclose(p_srch);

    printf("Press [1] for Patient Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        p_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int e_home()
{
    int go;
    system("cls");
    printf("\n  [EMPLOYEE HOME PAGE]\n");
    printf("\n  !![PRESS [1] TO STORE EMPLOYEE INFORMATION]");
    printf("\n  !![PRESS [2] TO VIEW ALL EMPLOYEE INFORMATION]");
    printf("\n  !!PRESS  [3] TO DELETE INFO");
    printf("\n  !!PRESS  [4] TO SEARCH EMPLOYEE INFO");
    printf("\n  !![PRESS [0] TO EXIT]");
    printf("\n  ##SELECT A OPTION:>:");
    while(scanf("%d",&go))
    {
        if(go==1 || go==2 || go==3 || go==4 || go==0)
        {
         if(go==1)
         {
             save_e();
             break;
         }
         if(go==2)
         {
             show_e();
             break;
         }
         if(go==3)
         {
             e_delete();
             break;
         }
         if(go==4)
         {
            e_search();
             break;
         }
         if(go==0)
         {
             ext();
             break;
         }
        }
        printf("\n  **Invalid Input, You Press Wrong Input, Read Option's Carefully :");
        printf(">:");
        fflush(stdin);
    }
    return 0;
}

int save_e()
{
    system("cls");
    printf("\n  [SAVE EMPLOYEE INFO PAGE]\n");
    FILE *em;
    em=fopen("employee info.txt","a");
    if(em==NULL)
    {
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    printf("  Enter Employee Name:");
    gets(e.e_name);
    printf("  Enter Employee Designation:");
    gets(e.e_des);
    printf("  Enter Employee Phone Number:");
    gets(e.e_cn);
    fwrite(&e, sizeof(e), 1,em);
    printf("\n\n  [!!! SAVE SUCCESSFUL !!!]\n");
    fclose(em);
    printf("Press [1] for Employee Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        e_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int e_delete()
{
    FILE *e_dlt,*e_dlt1;
    struct employee e,e1;
    int found=0;
    char e_nm[30];
    e_dlt=fopen("EMployee info.txt","r");
    e_dlt1=fopen("Delete.txt","w");
    fflush(stdin);
    printf("ENTER THE NAME YOU WANT TO DELETE:");
    gets(e_nm);
    while( fread(&e1, sizeof(e1), 1, e_dlt))
    {
        if(feof(e_dlt))
        {
            break;
        }
        if(strcmp(e_nm,e1.e_name)==0)
        {
            found=1;
            printf("\nDelete Successfully\n");
        }
        else
        {
            fwrite(&e1, sizeof(e1), 1, e_dlt1);
        }
    }
    fclose(e_dlt);
    fclose(e_dlt1);
    if(found==0)
    {
        printf("Sorry not Found\n\n");
    }
    else
    {
        e_dlt=fopen("Employee info.txt","w");
        e_dlt1=fopen("Delete.txt","r");
        while(1)
        {
            fread(&e1,sizeof(e1), 1, e_dlt1);
            if(feof(e_dlt1))
            {
                break;
            }
            fwrite(&e1, sizeof(e1), 1, e_dlt);
        }
    }
    fclose(e_dlt);
    fclose(e_dlt1);
    printf("Press [1] for Employee Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        e_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int show_e()
{
    system("cls");
    printf("\n  [ALL EMPLOYEE INFORMATION]\n");
    FILE *em2;
    em2=fopen("employee info.txt","r");
    while(fread(&e, sizeof(e), 1,em2))
    {
        printf("\n  Employee Name: %s\n  Employee Designation: %s\n Employee Phone Number: %s\n ",e.e_name,e.e_des,e.e_cn);
    }
    fclose(em2);
    printf("Press [1] for Employee Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        e_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int e_search()
{
    FILE *e_srch;
    e_srch=fopen("Employee info.txt","r");
    char e_s[20];
    printf("Write the File Name You Want To Show:\n");
    printf("==>");
    scanf("%s",e_s);
    while(fread(&e, sizeof(e), 1, e_srch))
    {
        if(strcmp(e_s,e.e_name)==0)
         printf("\n  Employee Name: %s\n  Employee Designation: %s\n Employee Phone Number: %s\n ",e.e_name,e.e_des,e.e_cn);
    }
    fclose(e_srch);

    printf("Press [1] for Employee Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        e_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int s_home()
{
    int go;
    system("cls");
    printf("\n  [STAFF HOME PAGE]\n");
    printf("\n  !![PRESS [1] TO STORE STAFF INFORMATION]");
    printf("\n  !![PRESS [2] TO VIEW ALL STAFF INFORMATION]");
    printf("\n  !![PRESS [3] TO DELETE INFO]");
    printf("\n  !![PRESS [4] TO SEARCH INFO]");
    printf("\n  !![PRESS [0] TO EXIT]");
    printf("\n  ##SELECT A OPTION:>:");
    fflush(stdin);
    while(scanf("%d",&go))
    {
        if(go==1 || go==2 || go==3 || go==4 || go==0)
        {
         if(go==1)
         {
             save_s();
             break;
         }
         if(go==2)
         {
             show_s();
             break;
         }
         if(go==3)
         {
             s_delete();
             break;
         }
         if(go==4)
         {
             s_search();
             break;
         }
         if(go==0)
         {
             ext();
             break;
         }
        }
        printf("\n  **Invalid Input, You Press Wrong Input, Read Option's Carefully :");
        printf(">:");
        fflush(stdin);
    }
    return 0;
}

int save_s()
{
    system("cls");
    printf("\n  [SAVE STAFF INFO PAGE]\n");
    FILE *st;
    st=fopen("staff info.txt","a");
    if(st==NULL)
    {
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    printf("  Enter Staff Name:");
    gets(s.s_name);
    printf("  Enter Staff Position:");
    gets(s.s_pos);
    printf("  Enter Staff Phone Number:");
    gets(s.s_cn);
    fwrite(&s, sizeof(s), 1,st);
    printf("\n\n  [!!! SAVE SUCCESSFUL !!!]\n");
    fclose(st);

    printf("Press [1] for Staff Home Page\nPress [2] for Homepage\n");
    while(scanf("%d",&a))
{
    if(a==1)
    {
        s_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int show_s()
{
    system("cls");
    printf("\n  [ALL STAFF INFORMATION]\n");
    FILE *st2;
    st2=fopen("staff info.txt","r");
    while(fread(&s, sizeof(s), 1,st2))
    {
        printf("\n  Staff Name: %s\n  Staff Position: %s\n Staff Phone Number: %s\n ",s.s_name,s.s_pos,s.s_cn);
    }
    fclose(st2);
    printf("Press [1] for Staff Home Page\nPress [2] for Homepage\n");
    while(scanf("%d",&a))
{
    if(a==1)
    {
        s_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int s_delete()
{
    FILE *s_dlt,*s_dlt1;
    struct staff s,s1;
    int found=0;
    char s_nm[30];
    s_dlt=fopen("Staff info.txt","r");
    s_dlt1=fopen("Delete.txt","w");
    fflush(stdin);
    printf("ENTER THE NAME YOU WANT TO DELETE:");
    gets(s_nm);
    while( fread(&s1, sizeof(s1), 1, s_dlt))
    {
        if(feof(s_dlt))
        {
            break;
        }
        if(strcmp(s_nm,s1.s_name)==0)
        {
            found=1;
            printf("\nDelete Successfully\n");
        }
        else
        {
            fwrite(&s1, sizeof(s1), 1, s_dlt1);
        }
    }
    fclose(s_dlt);
    fclose(s_dlt1);
    if(found==0)
    {
        printf("Sorry not Found\n\n");
    }
    else
    {
        s_dlt=fopen("Staff info.txt","w");
        s_dlt1=fopen("Delete.txt","r");
        while(1)
        {
            fread(&s1,sizeof(s1), 1, s_dlt1);
            if(feof(s_dlt1))
            {
                break;
            }
            fwrite(&s1, sizeof(s1), 1, s_dlt);
        }
    }
    fclose(s_dlt);
    fclose(s_dlt1);
    printf("Press [1] for Staff Home Page\nPress [2] for Homepage\n");

    while(scanf("%d",&a))
{
    if(a==1)
    {
        s_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}

int s_search()
{
    FILE *s_srch;
    s_srch=fopen("Staff info.txt","r");
    char s_s[20];
    printf("Write the File Name You Want To Show:\n");
    printf("==>");
    scanf("%s",s_s);
    while(fread(&s, sizeof(s), 1, s_srch))
    {
        if(strcmp(s_s,s.s_name)==0)
        printf("\n  Staff Name: %s\n  Staff Position: %s\n Staff Phone Number: %s\n ",s.s_name,s.s_pos,s.s_cn);
    }
    fclose(s_srch);
    printf("Press [1] for Staff Home Page\nPress [2] for Homepage\n");
    while(scanf("%d",&a))
{
    if(a==1)
    {
        s_home();
        break;
    }
    if(a==2)
    {
        main_home();
        break;
    }
    else
    {
        printf("Invalid Keyword!!! Please choose 1 or 2 for Option.");
    }
}

    return 0;
}


int ext()
{
    system("cls");
    printf("\n  [EXIT PAGE]\n");
    int c_exit;
    fflush(stdin);
    printf("\n  ::[Press [1 AND ENTER] To Cancel Exit]:::::");
    printf("\n  ::[Press [0 AND ENTER] To Exit SUCCESS]:::");
    printf("\n  **What Is Your Choice:>:");
    while(scanf("%d",&c_exit))
    {
        if(c_exit==1 || c_exit==0)
        {
        if(c_exit==1)
        {
         main();
         break;
        }
        if(c_exit==0)
        {

            printf("\n  ::[THANKS FOR USING]::");
            printf("\n  ::[Press Any Key To Exit Success]::\n");
            exit(EXIT_SUCCESS);
        }
        }
        printf("\n  **Invalid Input, You Press Wrong Input, Read Option's Carefully :");
        printf(">:");
        fflush(stdin);
    }
    return 0;
}

int billing()
{
    printf("\n\t\tCount Total Bill Here");
    int sum;
    int Radiology,xray=5000,MRI=1200,cs=5000;
    int h_p_d=1000,day,Total;
    printf("How Much Days Patient stays ?:\n");
    scanf("%d",&day);
   sum=h_p_d*day;
   printf("Total Hospital Seat Rent: %d\n",sum);
   Total=xray+MRI+cs+sum;
   printf("Total Bill %d\n",Total);

}
