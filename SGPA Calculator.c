
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float thirdsem();
float sgpa1,sgpa2,a,b,Student[100];
char string[100][8];
char name1[7],name2[7];



 main()
{

    int temp1[70][20],temp2[70][20],count=0,step;float temp;
    char cha;
     FILE *minipro,*usefull;
    minipro=fopen("OMKAROHIT.txt","rb+");
   usefull=fopen("RANK LIST.txt","w");


    printf("\n----------WEL-COME---------\n\n");
    printf("PLEASE CHECK 'RANK LIST.txt' FILE TO SEE PREVIOUS RANKLIST\n\n");

    printf("Enter First student Name(only first name):\n");
    scanf("%s",&name1);

    printf("Enter Second student Name(only first name):\n");
    scanf("%s",&name2);
    strcpy(string[0],name1);
    strcpy(string[1],name2);

printf("----SGPA CALCULATOR FOR 3rd SEMESTER CSE BRANCH----\n");
printf("Enter the marks of %s\n",name1);
Student[0]=thirdsem();
printf("SGPA of %s :%.2f\n\n",name1,Student[0]);
printf("Enter the marks of %s\n",name2);
Student[1]=thirdsem();
printf("SGPA of %s :%.2f\n\n",name2,Student[1]);
//Student[0]=sgpa1;
//Student[1]=sgpa2;

int i=2;
while((fgets(temp1[i],100,minipro))!=NULL)
{


    temp1[i][strlen(temp1[i])-1]!='\0';
  int number=sscanf(temp1[i],"%s%f",&string[i],&Student[i]);

  i++;

}
fseek(minipro,0,SEEK_SET);
cha=fgetc(minipro);
while(cha!=EOF)
{
    if(cha=='\n')
    {
        count=count+1;
    }
  cha=fgetc(minipro);
}
fflush(stdin);
printf("%d\n",count);
 fputs(string[0],minipro);
fprintf(minipro,"\t");
fprintf(minipro,"%.2f",Student[0]);
fprintf(minipro,"\n");
fputs(string[1],minipro);
fprintf(minipro,"\t");
fprintf(minipro,"%.2f",Student[1]);
fprintf(minipro,"\n");
rewind(minipro);


for(step=0;step<count+1;++step)

   for(i=0;i<count-step+1;++i)
   {

       if(Student[i]>Student[i+1])
       {
           temp=Student[i];
           Student[i]=Student[i+1];
           Student[i+1]=temp;
          strcpy(temp2[i],string[i]);
          strcpy(string[i],string[i+1]);
           strcpy(string[i+1],temp2[i]);

       }
   }


int j=1;
for(i=count+1;i>=0;--i,++j)
{
    printf("Rank %d:%s :%.2f\n",j,string[i],Student[i]);
    fprintf(usefull,"Rank %d:%s :%.2f\n",j,string[i],Student[i]);

}

fclose(minipro);
fclose(usefull);

}

float thirdsem()
{
    int a[9],g[9],i; float total,perc,sgpa;
     char s[9][7]={"18MAT31","18CS32","18CS33","18CS34","18CS35","18CS36","18CSL37","18CSL38","18CPC39"};

   printf("1.Enter the marks obtained in 18MAT31 : ");
    scanf("%d",&a[0]);
   printf("2.Enter the marks obtained in 18CS32 : ");
   scanf("%d",&a[1]);

     printf("3.Enter the marks obtained in 18CS33 : ");
   scanf("%d",&a[2]);

    printf("4.Enter the marks obtained in 18CS34 : ");
   scanf("%d",&a[3]);

    printf("5.Enter the marks obtained in 18CS35 : ");
   scanf("%d",&a[4]);

    printf("6.Enter the marks obtained in 18CS36 : ");
   scanf("%d",&a[5]);

 printf("7.Enter the marks obtained in 18CSL37 : ");
   scanf("%d",&a[6]);

    printf("8.Enter the marks obtained in 18CSL38 : ");
   scanf("%d",&a[7]);

    printf("9.Enter the marks obtained in 18CPC39 : ");
   scanf("%d",&a[8]);

   for(i=0;i<9;i++)
   {
       if(a[i]<40)
       {
           printf("\nYou are failed in %s \n",s[i]);break;
       }
      if(a[i]>100)
      {
        printf("\nPlease enter valid marks in %s\n",s[i]);
        exit(0);
      }
   }

   for(i=0;i<9;i++)
   {
       g[i]=grade(a[i]);
   }

total=(3*g[0])+ (4*g[1])+ (3*g[2])+ (3*g[3])+ (3*g[4])+ (3*g[5])+ (2*g[6])+ (2*g[7])+ (1*g[8]);
sgpa=total/24;

perc=(sgpa-.75)*10;

return sgpa;



}


int grade(int b)
{

      if( b>=90 &&  b<=100)
      {
              return(10);
      }
      else if(  b>=80 &&  b<90)
      {
             return(9);
      }
       else if(  b>=70 &&  b<80)
      {
              return(8);
       }
       else if(  b>=60 && b<70)
      {
             return(7);
       }
       else if(b=45 && b<60)
      {
             return(6);
       }
      else if( b>=40 && b<45)
      {
             return(4);
       }

      else if( b<40)
      {
            return(0);

       }
      else
      {
           printf("Invalid marks");
      }

}





