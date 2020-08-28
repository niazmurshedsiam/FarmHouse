#include<stdio.h>
#include<string.h>
struct farmhouse
{
 int itemno;
 char name[30];
 float amount;

}stud;
   admin()
    {
int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   emp = empty();
   if (emp == 0)
    printf("\n The file is EMPTY\n");
   else
    sort();
   break;
  case 7:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);


}

 user()

{
 int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   emp = empty();
   if (emp == 0)
    printf("\n The file is EMPTY\n");
   else
    sort();
   break;
  case 7:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);


}

//    FUNCTION TO INSERT RECORDS TO THE FILE
insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Item no   :");
 scanf("%d", &stud.itemno);
 printf("Enter the Name      :");
 scanf("%s", &stud.name);
 printf("Enter the amount      :");
 scanf("%f", &stud.amount);
 fwrite(&stud, sizeof(stud), 1, fp);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nItem Number\tName\tAmount\n\n");
 while (fread(&stud, sizeof(stud), 1, fp1))
 printf("  %d\t\t%s\t%.2f\n", stud.itemno, stud.name, stud.amount);
 fclose(fp1);
}
//    FUNCTION TO SEARCH THE GIVEN RECORD
search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Item no you want to search  :");
 scanf("%d", &r);
 avl = avlitemno(r);
 if (avl == 0)
  printf("Item No %d is not available in the file\n",r);
 else
 {
  fp2 = fopen("Record", "r");
  while (fread(&stud, sizeof(stud), 1, fp2))
  {
   s = stud.itemno;
   if (s == r)
   {
    printf("\nItem no = %d", stud.itemno);
    printf("\nName    = %s", stud.name);
    printf("\nAmount   = %.2f\n", stud.amount);
   }
  }
  fclose(fp2);
 }
}
//    FUNCTION TO DELETE A RECORD


 deletefile()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Item no you want to delete :");
 scanf("%d", &r);
 if (avlitemno(r) == 0)
  printf("Item no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.itemno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }

}
//    FUNCTION TO UPDATE THE RECORD
update()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter Item number to update:");
 scanf("%d", &r);
 avl = avlitemno(r);
 if (avl == 0)
 {
  printf("Item number %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.itemno;
   if (s != r)
    fwrite(&stud, sizeof(stud), 1, fpt);
   else
   {
    printf("\n\t1. Update Name of Item Number %d", r);
    printf("\n\t2. Update Amount of Item Number %d", r);
    printf("\n\t3. Update both Name and Amount of Item Number %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s", &stud.name);
     break;
    case 2:
     printf("Enter Amount : ");
     scanf("%f", &stud.amount);
     break;
    case 3:
     printf("Enter Name: ");
     scanf("%s", &stud.name);
     printf("Enter Amount: ");
     scanf("%f", &stud.amount);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&stud, sizeof(stud), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
  {
   fwrite(&stud, sizeof(stud), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}
/* FUNCTION TO SORT THE RECORD */
sort()
{
 int a[20], count = 0, i, j, t, c;
 FILE *fpo;
 fpo = fopen("Record", "r");
 while (fread(&stud, sizeof(stud), 1, fpo))
 {
  a[count] = stud.itemno;
  count++;
 }
 c = count;
 for (i = 0; i<count - 1; i++)
 {
  for (j = i + 1; j<count; j++)
  {
   if (a[i]>a[j])
   {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
   }
  }
 }
 printf("Item No.\tName\t\tAmount\n\n");
 count = c;
 for (i = 0; i<count; i++)
 {
  rewind(fpo);
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   if (a[i] == stud.itemno)
    printf("\n %d\t\t %s \t\t %2f",stud.itemno, stud.name, stud.amount);
  }

 }
}
//    FUNCTION TO CHECK GIVEN ROLL NO IS AVAILABLE //
int avlitemno(int rno)
{
 FILE *fp;
 int c = 0;
 fp = fopen("Record", "r");
 while (!feof(fp))
 {
  fread(&stud, sizeof(stud), 1, fp);

  if (rno == stud.itemno)
  {
   fclose(fp);
   return 1;
  }
 }
 fclose(fp);
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&stud, sizeof(stud), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}

struct login
{
    char fname[100];
    char lname[50];
    char username[20];
    char password[20];

};

registe()

{

    FILE*log;
    log=fopen("loginfarm.txt","a+");
    struct login l;

    printf("enter the first name : ");
    scanf("%s",l.fname);

    printf("enter the last name : ");
    scanf("%s",l.lname);

    printf("enter the user name : ");
    scanf("%s",l.username);
    printf("enter the password : ");
    scanf("%s",l.password);

    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\n\nyour user name is userid");
    printf("\nnow login with userid and password\n");
    printf("\npress any key to continue....");
    getch();
    system("CLS");
    login();

}

login()
{
    char username[200],password[20];
    FILE*log;
    log=fopen("loginfarm.txt","r");
    struct login l;
    printf("userid : ");
    scanf("%s",username);
    printf("password : ");
    scanf("%s",password);

    while(fread(&l,sizeof(l),1,log))

    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

        {
            system("CLS");
            printf("\n\t\twelcome......\n");
            printf("\t\tlogin successful\n");
            user();
            break;
        }

        else

        {
            printf("\n\t\tplease enter correct userid and password");
        }
    }

    fclose(log);
}
ownerlogin()
{
    char username[200],password[20];
    FILE*log;
    log=fopen("loginfarm.txt","r");
    struct login l;
    printf("userid : ");
    scanf("%s",username);
    printf("password : ");
    scanf("%s",password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

        {
            system("CLS");
            printf("\n\t\twelcome......\n");
            printf("\t\tlogin successful\n");
            owner();
            break;
        }

        else

        {
            printf("\n\t\tplease enter correct userid and password");
        }
    }

    fclose(log);
}
managerlogin()
{
    char username[200],password[20];
    FILE*log;
    log=fopen("loginfarm.txt","r");
    struct login l;
    printf("userid : ");
    scanf("%s",username);
    printf("password : ");
    scanf("%s",password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

        {
            system("CLS");
            printf("\n\t\twelcome......\n");
            printf("\t\tlogin successful\n");
            owner();
            break;
        }

        else

        {
            printf("\n\t\tplease enter correct userid and password");
        }
    }

    fclose(log);
}
customerlogin()

{
    char username[200],password[20];
    FILE*log;
    log=fopen("loginfarm.txt","r");
    struct login l;
    printf("userid : ");
    scanf("%s",username);
    printf("password : ");
    scanf("%s",password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

        {
            system("CLS");
            printf("\n\t\twelcome......\n");
            printf("\t\tlogin successful\n");
            owner();
            break;
        }

        else

        {
            printf("\n\t\tplease enter correct userid and password");
        }
    }

    fclose(log);
}

int main()

{
    int n;
    int cho, cho1;

    printf("select Mood\n");
    printf("1.owner\n");
    printf("2.manager\n");
    printf("3.customer\n");
    printf("Please select one :");
    scanf("%d",&n);
        switch ( n)
    {
    case 1:

        system("CLS");
        printf("press '1' for register \npress '2' for login\n\n");
        scanf("%d",&cho);

        if(cho==1)
        {
            system("CLS");
            registe();
        }
        else if(cho==2)
        {
            system("CLS");
            ownerlogin();
        }
        break;
        case 2:

        system("CLS");
        printf("press '1' for register \npress '2' for login\n\n");
        scanf("%d",&cho);

        if(cho==1)
        {
            system("CLS");
            registe();
        }
        else if(cho==2)
        {
            system("CLS");
            managerlogin();
        }
        break;

    case 3:

        system("CLS");
        printf("press '1' for register \npress '2' for login\n\n");
        scanf("%d",&cho1);

        if(cho1==1)
        {
            system("CLS");
            registe();
        }
        else if(cho1==2)
        {
            system("CLS");
            login();
        }

        break;

    default:
        printf("wrong entry\n");
        break;
    }


}
// MAIN PROGRAM
    owner()
    {
int c, emp;
 do
 {
  printf("\n\t---Select your choice---------\n");
  printf("\n\t1. INSERT\n\t2. DISPLAY\n\t3. SEARCH");
  printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
  printf("\n\t7. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   search();
   break;
  case 4:
   deletefile();
   break;
  case 5:
   update();
   break;
  case 6:
   emp = empty();
   if (emp == 0)
    printf("\n The file is EMPTY\n");
   else
    sort();
   break;
  case 7:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);


}
