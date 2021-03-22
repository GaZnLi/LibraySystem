#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct
{
    char shuhao[100];
    char shuming[100];
    char leibie[20];
    char zuozhe[100];
    char chubanshe[100];
    int zongkucun;
    int yijiechu;

}book[122];
struct
{
    char xuehao[10];
    char shuhao[6];
    char jieday[11];
    char huanday[11];


}borrow[100];


void BookInformation()
{
    FILE *Book;
    if((Book=fopen("book.txt","r"))==NULL)
       {
           printf("can not open \n");
           exit(0);
       }

    char a[20];
	//int dd=0;
	fscanf(Book, "%s %s %s %s %s %s %s",a,a,a,a,a,a,a);//忽略第一行
    int i=0;
    printf("书号\t书名\t类别\t作者\t出版社\t总库存\t已出借册数\n");
    for(i=0;i<120;i++)
    {
        fscanf(Book, "%s %s %s %s %s %d %d", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, &book[i].zongkucun, &book[i].yijiechu);
		printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, book[i].zongkucun, book[i].yijiechu);
    }
    fclose(Book);
}
void BorrowInformation()
{
    FILE *Borrow;
    if((Borrow=fopen("borrow.txt","r"))==NULL)
       {
           printf("can not open \n");
           exit(0);
       }
    int i=0;
    for(i=0;i<100;i++)
    {
        fscanf(Borrow, "%s%s%s%s", borrow[i].xuehao, borrow[i].shuhao, borrow[i].jieday, borrow[i].huanday);
		printf("%s	%s	%s	%s\n", borrow[i].xuehao, borrow[i].shuhao, borrow[i].jieday, borrow[i].huanday);
    }
    fclose(Borrow);
}
void mohushuming()
{
    FILE *Book;
    if ((Book = fopen("book.txt", "r")) == NULL)
    {
        printf("can not open \n");
        exit(0);
    }

    char a[20];
    //int dd=0;
    //fscanf(Book, "%s %s %s %s %s %s %s", a, a, a, a, a, a, a);//忽略第一行
    int i=0;

    printf("请输入书名\n");
    char str2[100];              //要查找的字符串
    scanf("%s", str2);
    char *res;
    int n;
    int count = 0; //用来记录找到的书的数目
    //int i=0;
    for (i = 0; i<121; i++)
    {

    res = (char *)memchr(book[i].shuming, str2[0], strlen(book[i].shuming));  //根据要查找的字符串第一个字符，切割源字符串
    if (res == NULL)
    {
        continue;  //如果这本书找不到，就直接找下一本
    }
    while (1)
    {
        if (strlen(res) <= strlen(str2) - 1)
        break;
        n = memcmp(res, str2, strlen(str2) - 1); //比较
        if (n != 0)
        {
            if (strlen(res) <= strlen(str2) - 1)  //切割出的字符串小于要查找字符串的长度
            {
                break;
               //printf("1图书馆找不到这本书的相关信息...\n");   //这本书找不到，不代表下本书找不到
            }
            else
            {
            //根据要查找的第一个字符继续切割
            res = (char *)memchr(res + 1, str2[0], strlen(res + 1));
            if (res == NULL)
            {
                break;
               //printf("3图书馆找不到这本书的相关信息...\n");  //同上

            }

            }
        }
        else
        { //如果n = 0，找到
            printf("（书号）%s（书名）%s（类别）%s（作者）%s（出版社）%s（总库存）%d（已借出）%d\n", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, book[i].zongkucun, book[i].yijiechu);
            count++;
            break;  //找到了就退出死循环呀，一直循环下去匹配的还是刚找的这本书
        }
    }

    }
    if (count == 0) //表示当前书库找不到这个书名
    printf("图书馆找不到这本书的相关信息...\n");
    return;
}
void FindBook()
{

    FILE *Book;
    if((Book=fopen("book.txt","r"))==NULL)
       {
           printf("can not open \n");
           exit(0);
       }

    char a[20];
	//int dd=0;
	fscanf(Book, "%s %s %s %s %s %s %s",a,a,a,a,a,a,a);//忽略第一行
    int i=0;
   // printf("书号\t书名\t类别\t作者\t出版社\t总库存\t已出借册数\n");
    for(i=0;i<120;i++)
    {
        fscanf(Book, "%s %s %s %s %s %d %d", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, &book[i].zongkucun, &book[i].yijiechu);
		//printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, book[i].zongkucun, book[i].yijiechu);
    }
    printf("请输入查询方式：\n");
    printf("1、按书号\n2、按书名\n3、按类别\n4、按作者\n");

    int t;
    int k=0;
    scanf("%d",&t);
    char find[100];
    switch(t)
    {
        case 1 :
                {
                    printf("请输入书号\n");
                    scanf("%s",find);
                    for(i=0;i<121;i++)
                    {
                        if(strcmp(find,book[i].shuhao)==0)
                        {
                            printf("（书号）%s（书名）%s（类别）%s（作者）%s（出版社）%s（总库存）%d（已借出）%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                            k=1;
                        }
                    }
                    if(k==0)
                    printf("找不到这本书相关信息！\n");
                }
                break;
        case 2 :
                {
                   mohushuming();
                }
                break;
        case 3 :
                {
                    printf("请输入类别\n");
                    scanf("%s",find);
                    for(i=0;i<121;i++)
                    {
                        if(strcmp(find,book[i].leibie)==0)
                        {
                            printf("（书号）%s（书名）%s（类别）%s（作者）%s（出版社）%s（总库存）%d（已借出）%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                            k=1;
                        }
                    }
                    if(k==0)
                    printf("找不到这本书相关信息！\n");
                }
                break;
         case 4 :
                {
                    printf("请输入作者\n");
                    scanf("%s",find);
                    for(i=0;i<121;i++)
                    {
                        if(strcmp(find,book[i].zuozhe)==0)
                        {
                            printf("（书号）%s（书名）%s（类别）%s（作者）%s（出版社）%s（总库存）%d（已借出）%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                            k=1;
                        }
                    }
                    if(k==0)
                    printf("找不到这本书相关信息！\n");
                }
                break;
         default :printf("error!\n");break;
    }
}
void QueryBook()//查询借阅信息
{
     FILE *Borrow;
    if((Borrow=fopen("borrow.txt","r"))==NULL)
       {
           printf("can not open \n");
           exit(0);
       }
    int i=0,k=0;
    for(i=0;i<100;i++)
    {
        fscanf(Borrow, "%s%s%s%s", borrow[i].xuehao, borrow[i].shuhao, borrow[i].jieday, borrow[i].huanday);
		//printf("%s	%s	%s	%s\n", borrow[i].xuehao, borrow[i].shuhao, borrow[i].jieday, borrow[i].huanday);
    }
    printf("请输入您的学号\n");
    char number[100];
    scanf("%s",number);
     for(i=0;i<121;i++)
                    {
                        if(strcmp(number,borrow[i].xuehao)==0)
                        {
                             printf("学号为%s的同学：所借书号为%s，借阅时间为%s，应还时间为：%s",borrow[i].xuehao,borrow[i].shuhao,borrow[i].jieday,borrow[i].huanday);
                             k=1;
                        }

                    }
                    if(k==0)
                    {
                        printf("请检查学号是否输入错误\n");
                    }


}



void BorrowBook()
{

        FILE *Book,*Borrow;
        Borrow=fopen("borrow.txt","a+");
        Book=fopen("book.txt","r");
        int i,n=0,m=120,l=0,k=0;

    for(i=0;i<120;i++)
    {
        fscanf(Book, "%s %s %s %s %s %d %d", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, &book[i].zongkucun, &book[i].yijiechu);

    }

       printf("请输入您所要借的书号\n");

       scanf("%s",borrow[l].shuhao);

         for(i=0;i<122;i++)
            {
                if(strcmp(borrow[l].shuhao,book[i].shuhao)==0&&book[i].zongkucun>book[i].yijiechu)
                {
                    printf("请输入您的学号:");
                    scanf("%s",borrow[l].xuehao);
                   // printf("书号:%s\n",borrow[l].shuhao);
                    printf("本次借书时间:");
                    scanf("%s",borrow[l].jieday);
                    strcpy(borrow[l].huanday,borrow[l].jieday);
                    borrow[l].huanday[6]=borrow[l].jieday[6]+2;
                    printf("借阅成功！您应还书的时间为:%s\n",borrow[l].huanday);
                   // printf("%s %s %s %s\n\n",borrow[l].xuehao,borrow[l].shuhao,borrow[l].jieday,borrow[l].huanday);
                    fprintf(Borrow,"%s %s %s %s\n\n",borrow[l].xuehao,borrow[l].shuhao,borrow[l].jieday,borrow[l].huanday);
                   // k=i;
                    book[i].yijiechu++;
                    Book=fopen("book.txt","w");
                    for(i=0;i<122;i++)
                    {
                        fprintf(Book,"\n%s\t%s\t%s\t%s\t%s\t%d\t%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                     //printf("%s %s %s %s  %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);}
                    }
                    k=1;
                }

            }
         if(k==0)printf("请检查书名是否输入错误\n");

  fclose(Borrow);
  fclose(Book);
}


void ReturnBook()
{
    FILE *Book,*Borrow;
    Borrow=fopen("borrow.txt","r");
    Book=fopen("book.txt","w");
    int i=0;
    for(i=0;i<120;i++)
    {
        fscanf(Book, "%s %s %s %s %s %d %d", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, &book[i].zongkucun, &book[i].yijiechu);
		//printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, book[i].zongkucun, book[i].yijiechu);
    }
    for(i=0;i<100;i++)
    {
        fscanf(Borrow, "%s%s%s%s", borrow[i].xuehao, borrow[i].shuhao, borrow[i].jieday, borrow[i].huanday);
		//printf("%s	%s	%s	%s\n", borrow[i].xuehao, borrow[i].shuhao, borrow[i].jieday, borrow[i].huanday);
    }
    printf("请输入您的学号：\n");
    char xuehao[20];
    int k=0;
    int chao;
    scanf("%s",xuehao);
    float fakuan=0.0;//打印罚款金额
    for(i=0;i<121;i++)
    {
                        if(strcmp(xuehao,borrow[i].xuehao)==0)
                        {
                             printf("学号为%s的同学：所借书号为%s，借阅时间为%s，应还时间为：%s",borrow[i].xuehao,borrow[i].shuhao,borrow[i].jieday,borrow[i].huanday);
                             k=1;

                             printf("当前时间距离还书时间已经：");
                             scanf("%d",&chao);
                             printf("天");
                             if(chao>0)
                             {
                                 printf("\n还书成功！\n");
                                 fakuan=(float)chao*0.2;
                                 printf("\n超期%d天罚款：%.2f元\n",chao,fakuan);
                                 book[i].yijiechu--;
                             }

                             else
                             {
                                 printf("\n您已如期归还此图书\n");
                                 book[i].yijiechu--;
                             }


                          }
      }
                    if(k==0)
                    {
                        printf("请检查学号是否输入错误\n");
                    }
    for(i=0;i<120;i++)
    {
        fprintf(Book,"%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
    }
    fclose(Book);
    fclose(Borrow);

}
void ruku()//入库，新增书籍
{
    FILE *fp;
    fp=fopen("book.txt","w");
    int i=130;

printf("请输入：书号  书名  类别  作者  出版社  总库存  已借出本书\n");
scanf("%s%s%s%s%s%d%d",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,&book[i].zongkucun,&book[i].yijiechu);

    fp=fopen("book.txt","r");
    for(i=0;i<120;i++)
    {fscanf(fp,"%s%s%s%s%s%d%d",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,&book[i].zongkucun,&book[i].yijiechu);
       // printf("%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
}
fp=fopen("book.txt","a+");
fprintf(fp,"%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);

    fp=fopen("book.txt","w");
for(i=0;i<122;i++)
{
    fprintf(fp,"%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
}
fclose(fp);
}
void chuku()//出库，删除书籍
{
        FILE *fp;
        char str[10];
        int i,k=0;
        printf("请输入想要删除的书号:");
        scanf("%s",str);
        fp=fopen("book.txt","r");
  for(i=0;i<120;i++)
    {fscanf(fp,"%s%s%s%s%s%d%d",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,&book[i].zongkucun,&book[i].yijiechu);
    //printf("%s%s%s%s%s%d%d",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,&book[i].zongkucun,&book[i].yijiechu);
      if(strcmp(str,book[i].shuhao)==0)
        { k=i;printf("书号:%s\n书名:%s\n类别:%s\n作者:%s\n出版社:%s\n库存:%d\n已借出册数:%d\n\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);}}
         for(i=0;i<k;i++)
         {
            printf("%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
         }
         for(i=k+1;i<122;i++)
         {
             printf("%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
         }
          fp=fopen("book.txt","w");
          for(i=0;i<k;i++)
         {
            fprintf(fp,"%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
         }
         for(i=k+1;i<122;i++)
         {
             fprintf(fp,"%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
         }
        fclose(fp);
}
void ManageBook()
{
    int t;
    printf("请选择：1、入库，2、出库\n");
    scanf("%d",&t);
    switch(t)
    {
        case 1 :ruku();break;
        case 2 :chuku();break;
        default:printf("输入错误！");break;
    }

}

int main()
{
    printf("********************欢迎来到图书馆系统****************\n\n");
    printf(" 1、书籍信息\n");
    printf(" 2、借阅信息\n");
    printf(" 3、查询书籍（根据书号、书名（模糊）、类别、作者）\n");
    printf(" 4、查询借阅信息（根据学号，显示借阅信息）\n");
    printf(" 5、借书\n");
    printf(" 6、还书\n");
    printf(" 7、图书管理（入库、出库）\n");
    printf(" 8、退出请按0\n");
    printf("----------------请输入将进行操作之前的序号------------\n\n");




    int t;
    scanf("%d",&t);//选择大功能
    switch(t)
    {
        case 1 :BookInformation();break;//书籍信息
        case 2 :BorrowInformation();break;//借阅信息
        case 3 :FindBook();break;//查询书籍
        case 4 :QueryBook();break;//查询借阅信息
        case 5 :BorrowBook();break;//借书
        case 6 :ReturnBook();break;//还书
        case 7 :ManageBook();break;//管理图书,入库、出库
        case 0 :printf("\n书山有路勤为径，学海无涯苦作舟。图书馆欢迎您下次光临~\n");break;
        default  :printf("操作不存在\n");break;

    }

    return 0;
}


