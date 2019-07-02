#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
COORD coord={0,0};
void sign_up();
void sign_in();
void administrate();
void stu();
void sel_col();
void allot();
void college();
typedef struct
{
  int no;
  char college[30];
  char branch[30];
}college1;
college1 coll;
int code=1;
void gotoxy(int x,int y)      //for using gotoxy func.
 {

   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
typedef struct
{
  int stu_rank;
  int col_code;
}pref;
pref pref1;
  typedef  struct
    {
        int rank;
    char name[30];
    int rollno;
    int password;
  }student;
  student s,d;
  FILE *fptr,*fpt;
  void main()
  {
    system("cls");
    int ch2;
    printf("\n\n\t1.Administrator");
    printf("\n\n\t2. Student");
    printf("\nYour Choice   :   ");
    scanf("%d",&ch2);
    switch(ch2)
    {
      case 1:
      administrate();
      break;
      case 2:
      stu();
      break;
      default:
      printf("\nWrong input!!!");
      main();
      break;
    }
    getch();
  }
  void administrate()
  {
    system("cls");
    int ch3,ch4;
    printf("\n\n\n\t1. add college");
    printf("\n\n\t2. allotment");
    scanf("%d",&ch3);
    switch(ch3)
    {
      case 1:
      college();
      break;
      case 2:
      allot();
      break;
      default:
      printf("\nWrong input!!!");
      administrate();
      break;
    }
    printf("\n Do you want to continue??  \n1. yes        2. no");
    scanf("%d",&ch4);
    if(ch4==1)
    {
      administrate();
    }
    else
    {
      exit(0);
    }
    getch();
  }
  void stu()
  {
    system("cls");
    int ch;
    printf("\n\n\t\t1. Sign In");
    printf("\n\n\t\t2.Sign Up (New Registration)");
    printf("\n\tYour Choice  :  ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
      sign_in();
      break;
      case 2:
      sign_up();
      break;
      default:
      printf("\nWrong Input!!!");
      stu();
      break;
    }
    getch();
  }
void sign_up()
 {
     system("cls");
    int r;
    int roll,pass;
    char temp[30];
    printf("\n\n");
    fptr=fopen("students.bin","r");
    go3: printf("Rank            :   ");
    scanf("%d",&r);
    while(fread(&s, sizeof(s),1,fptr))
    {
        if(r==s.rank)
        {
            printf("Already Exists!!!\n");
            goto go3;
        }
    }
    fclose(fptr);
    fpt = fopen("students.bin","a");
    d.rank=r;
    printf("\tRoll No. accepted\n");
    printf("\tName         :  ");
    scanf("%s",d.name);
    printf("\n\tRoll No              :   ");
    scanf("%d",&d.rollno);
    printf("\n\tPassword                    :  ");
    scanf("%d",&d.password);
    fwrite(&d, sizeof(d),1,fpt);
    fclose(fpt);
    printf("\nPress any key to sign in...");
    getch();
    main();
 }
void sign_in()
{
  FILE *f,*fpqw;
  int rs,var;
  var=0;
  f=fopen("students.bin","r");
  student s1;
  printf("\n\n\tRank   :   ");
  scanf("%d",&rs);
  while(fread(&s1, sizeof(s1),1,f))
  {
    if(rs==s1.rank)
    {
      sel_col(rs);
      break;
    }
    else
    {
      var=1;
    }
  }
  if(var==1)
  {
    printf("\n\n Not Exists!!!!\nPress any key to sign up");
    getch();
    stu();
  }
}
void college()
{
  FILE *fpc;
  coll.no=code;
  fpc=fopen("college.bin","a");
  if(fpc=NULL)
  {
    printf("you have not entered anything");
  }
printf("\ncollege name :  ");
scanf("%s",coll.college);
printf("\nbranch    :  ");
scanf("%s",coll.branch);
fwrite(&coll, sizeof(coll),1,fpc);
fclose(fpc);
code++;
}
void sel_col(int ra)
{
  FILE *fpsc;
  int ch5,ch6;
  printf("\n\nColleges are :  \n");
  fpsc=fopen("college.bin","r");
  while(fread(&coll, sizeof (coll),1,fpsc))
  {
    printf("\t%d\t%s\t%s\n",coll.no,coll.college,coll.branch);
  }
  fclose(fpsc);
  lb2:printf("\nYour Choice    :   ");
  scanf("%d",&ch5);
  printf("\n    1.   Confirm             2.   edit");
  if(ch6==2)
  {
  goto lb2;
  }
  FILE *fppr;
  fppr=fopen("prefer.txt","a");
  pref1.stu_rank=ra;
  pref1.col_code=ch5;
  fwrite(&pref1, sizeof(pref1),1,fppr);
  fclose(fppr);
  printf("\n");
}
void allot()
{
  printf("jhdv");
}
