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
	fscanf(Book, "%s %s %s %s %s %s %s",a,a,a,a,a,a,a);//���Ե�һ��
    int i=0;
    printf("���\t����\t���\t����\t������\t�ܿ��\t�ѳ������\n");
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
    //fscanf(Book, "%s %s %s %s %s %s %s", a, a, a, a, a, a, a);//���Ե�һ��
    int i=0;

    printf("����������\n");
    char str2[100];              //Ҫ���ҵ��ַ���
    scanf("%s", str2);
    char *res;
    int n;
    int count = 0; //������¼�ҵ��������Ŀ
    //int i=0;
    for (i = 0; i<121; i++)
    {

    res = (char *)memchr(book[i].shuming, str2[0], strlen(book[i].shuming));  //����Ҫ���ҵ��ַ�����һ���ַ����и�Դ�ַ���
    if (res == NULL)
    {
        continue;  //����Ȿ���Ҳ�������ֱ������һ��
    }
    while (1)
    {
        if (strlen(res) <= strlen(str2) - 1)
        break;
        n = memcmp(res, str2, strlen(str2) - 1); //�Ƚ�
        if (n != 0)
        {
            if (strlen(res) <= strlen(str2) - 1)  //�и�����ַ���С��Ҫ�����ַ����ĳ���
            {
                break;
               //printf("1ͼ����Ҳ����Ȿ��������Ϣ...\n");   //�Ȿ���Ҳ������������±����Ҳ���
            }
            else
            {
            //����Ҫ���ҵĵ�һ���ַ������и�
            res = (char *)memchr(res + 1, str2[0], strlen(res + 1));
            if (res == NULL)
            {
                break;
               //printf("3ͼ����Ҳ����Ȿ��������Ϣ...\n");  //ͬ��

            }

            }
        }
        else
        { //���n = 0���ҵ�
            printf("����ţ�%s��������%s�����%s�����ߣ�%s�������磩%s���ܿ�棩%d���ѽ����%d\n", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, book[i].zongkucun, book[i].yijiechu);
            count++;
            break;  //�ҵ��˾��˳���ѭ��ѽ��һֱѭ����ȥƥ��Ļ��Ǹ��ҵ��Ȿ��
        }
    }

    }
    if (count == 0) //��ʾ��ǰ����Ҳ����������
    printf("ͼ����Ҳ����Ȿ��������Ϣ...\n");
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
	fscanf(Book, "%s %s %s %s %s %s %s",a,a,a,a,a,a,a);//���Ե�һ��
    int i=0;
   // printf("���\t����\t���\t����\t������\t�ܿ��\t�ѳ������\n");
    for(i=0;i<120;i++)
    {
        fscanf(Book, "%s %s %s %s %s %d %d", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, &book[i].zongkucun, &book[i].yijiechu);
		//printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\n", book[i].shuhao, book[i].shuming, book[i].leibie, book[i].zuozhe, book[i].chubanshe, book[i].zongkucun, book[i].yijiechu);
    }
    printf("�������ѯ��ʽ��\n");
    printf("1�������\n2��������\n3�������\n4��������\n");

    int t;
    int k=0;
    scanf("%d",&t);
    char find[100];
    switch(t)
    {
        case 1 :
                {
                    printf("���������\n");
                    scanf("%s",find);
                    for(i=0;i<121;i++)
                    {
                        if(strcmp(find,book[i].shuhao)==0)
                        {
                            printf("����ţ�%s��������%s�����%s�����ߣ�%s�������磩%s���ܿ�棩%d���ѽ����%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                            k=1;
                        }
                    }
                    if(k==0)
                    printf("�Ҳ����Ȿ�������Ϣ��\n");
                }
                break;
        case 2 :
                {
                   mohushuming();
                }
                break;
        case 3 :
                {
                    printf("���������\n");
                    scanf("%s",find);
                    for(i=0;i<121;i++)
                    {
                        if(strcmp(find,book[i].leibie)==0)
                        {
                            printf("����ţ�%s��������%s�����%s�����ߣ�%s�������磩%s���ܿ�棩%d���ѽ����%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                            k=1;
                        }
                    }
                    if(k==0)
                    printf("�Ҳ����Ȿ�������Ϣ��\n");
                }
                break;
         case 4 :
                {
                    printf("����������\n");
                    scanf("%s",find);
                    for(i=0;i<121;i++)
                    {
                        if(strcmp(find,book[i].zuozhe)==0)
                        {
                            printf("����ţ�%s��������%s�����%s�����ߣ�%s�������磩%s���ܿ�棩%d���ѽ����%d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
                            k=1;
                        }
                    }
                    if(k==0)
                    printf("�Ҳ����Ȿ�������Ϣ��\n");
                }
                break;
         default :printf("error!\n");break;
    }
}
void QueryBook()//��ѯ������Ϣ
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
    printf("����������ѧ��\n");
    char number[100];
    scanf("%s",number);
     for(i=0;i<121;i++)
                    {
                        if(strcmp(number,borrow[i].xuehao)==0)
                        {
                             printf("ѧ��Ϊ%s��ͬѧ���������Ϊ%s������ʱ��Ϊ%s��Ӧ��ʱ��Ϊ��%s",borrow[i].xuehao,borrow[i].shuhao,borrow[i].jieday,borrow[i].huanday);
                             k=1;
                        }

                    }
                    if(k==0)
                    {
                        printf("����ѧ���Ƿ��������\n");
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

       printf("����������Ҫ������\n");

       scanf("%s",borrow[l].shuhao);

         for(i=0;i<122;i++)
            {
                if(strcmp(borrow[l].shuhao,book[i].shuhao)==0&&book[i].zongkucun>book[i].yijiechu)
                {
                    printf("����������ѧ��:");
                    scanf("%s",borrow[l].xuehao);
                   // printf("���:%s\n",borrow[l].shuhao);
                    printf("���ν���ʱ��:");
                    scanf("%s",borrow[l].jieday);
                    strcpy(borrow[l].huanday,borrow[l].jieday);
                    borrow[l].huanday[6]=borrow[l].jieday[6]+2;
                    printf("���ĳɹ�����Ӧ�����ʱ��Ϊ:%s\n",borrow[l].huanday);
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
         if(k==0)printf("���������Ƿ��������\n");

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
    printf("����������ѧ�ţ�\n");
    char xuehao[20];
    int k=0;
    int chao;
    scanf("%s",xuehao);
    float fakuan=0.0;//��ӡ������
    for(i=0;i<121;i++)
    {
                        if(strcmp(xuehao,borrow[i].xuehao)==0)
                        {
                             printf("ѧ��Ϊ%s��ͬѧ���������Ϊ%s������ʱ��Ϊ%s��Ӧ��ʱ��Ϊ��%s",borrow[i].xuehao,borrow[i].shuhao,borrow[i].jieday,borrow[i].huanday);
                             k=1;

                             printf("��ǰʱ����뻹��ʱ���Ѿ���");
                             scanf("%d",&chao);
                             printf("��");
                             if(chao>0)
                             {
                                 printf("\n����ɹ���\n");
                                 fakuan=(float)chao*0.2;
                                 printf("\n����%d�췣�%.2fԪ\n",chao,fakuan);
                                 book[i].yijiechu--;
                             }

                             else
                             {
                                 printf("\n�������ڹ黹��ͼ��\n");
                                 book[i].yijiechu--;
                             }


                          }
      }
                    if(k==0)
                    {
                        printf("����ѧ���Ƿ��������\n");
                    }
    for(i=0;i<120;i++)
    {
        fprintf(Book,"%s %s %s %s %s %d %d\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);
    }
    fclose(Book);
    fclose(Borrow);

}
void ruku()//��⣬�����鼮
{
    FILE *fp;
    fp=fopen("book.txt","w");
    int i=130;

printf("�����룺���  ����  ���  ����  ������  �ܿ��  �ѽ������\n");
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
void chuku()//���⣬ɾ���鼮
{
        FILE *fp;
        char str[10];
        int i,k=0;
        printf("��������Ҫɾ�������:");
        scanf("%s",str);
        fp=fopen("book.txt","r");
  for(i=0;i<120;i++)
    {fscanf(fp,"%s%s%s%s%s%d%d",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,&book[i].zongkucun,&book[i].yijiechu);
    //printf("%s%s%s%s%s%d%d",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,&book[i].zongkucun,&book[i].yijiechu);
      if(strcmp(str,book[i].shuhao)==0)
        { k=i;printf("���:%s\n����:%s\n���:%s\n����:%s\n������:%s\n���:%d\n�ѽ������:%d\n\n",book[i].shuhao,book[i].shuming,book[i].leibie,book[i].zuozhe,book[i].chubanshe,book[i].zongkucun,book[i].yijiechu);}}
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
    printf("��ѡ��1����⣬2������\n");
    scanf("%d",&t);
    switch(t)
    {
        case 1 :ruku();break;
        case 2 :chuku();break;
        default:printf("�������");break;
    }

}

int main()
{
    printf("********************��ӭ����ͼ���ϵͳ****************\n\n");
    printf(" 1���鼮��Ϣ\n");
    printf(" 2��������Ϣ\n");
    printf(" 3����ѯ�鼮��������š�������ģ������������ߣ�\n");
    printf(" 4����ѯ������Ϣ������ѧ�ţ���ʾ������Ϣ��\n");
    printf(" 5������\n");
    printf(" 6������\n");
    printf(" 7��ͼ�������⡢���⣩\n");
    printf(" 8���˳��밴0\n");
    printf("----------------�����뽫���в���֮ǰ�����------------\n\n");




    int t;
    scanf("%d",&t);//ѡ�����
    switch(t)
    {
        case 1 :BookInformation();break;//�鼮��Ϣ
        case 2 :BorrowInformation();break;//������Ϣ
        case 3 :FindBook();break;//��ѯ�鼮
        case 4 :QueryBook();break;//��ѯ������Ϣ
        case 5 :BorrowBook();break;//����
        case 6 :ReturnBook();break;//����
        case 7 :ManageBook();break;//����ͼ��,��⡢����
        case 0 :printf("\n��ɽ��·��Ϊ����ѧ�����Ŀ����ۡ�ͼ��ݻ�ӭ���´ι���~\n");break;
        default  :printf("����������\n");break;

    }

    return 0;
}


