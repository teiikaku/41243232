#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define si 5

void printbo(char[][5]);//列印

void prbu(char[][5], int, int);//反轉

int chk(char[][5]);//過關

void py(int);

void pt(int);

void ptga(int);

void gack(int,float);

void ckwr(int);

int main() // 主程式
{
    int nd,mo;
    printf("模式0: 離開, 模式1: 遊戲介紹, 模式2: 遊戲遊玩, 模式3: 遊戲榮譽榜\n");
    printf("請選擇模式: ");
    scanf("%d",&mo);
    while (mo!=0)
    {
        switch (mo)
        {
        case 1:
            pt(mo);
            break;
        case 2:
            printf("\033[0m\033[1;31m***只有難度5可以將遊玩紀錄,紀錄進榮譽榜內***\033[0m\n");
            printf("請選擇難度(1~5): ");
            scanf("%d",&nd);
            py(nd);
            break;
        case 3:
            ptga(mo);
            break;
        case 111:
            printf("\033[0m\033[1;32m***開發人員模式***\033[0m\n");
            py(115);
            break;
        default:
            break;
        }
        printf("-------------------------------------------------------------------\n");
        printf("模式0: 離開, 模式1: 遊戲介紹, 模式2: 遊戲遊玩, 模式3: 遊戲榮譽榜\n");
        printf("請選擇模式: ");
        scanf("%d", &mo);
    }
    system("pause");
    return 0;
}

void pt(int pt)// 模式1 
{
    printf("-------------------------------------------------------------------\n");
    printf("十字滅燈遊戲,遊戲規則介紹\n");
    printf("5*5的燈中，按下該顆燈泡，該顆燈泡行與列都滅燈，但該顆燈泡持續亮燈\n");
    printf("例如:輸入A1，A列燈泡狀態反轉，1行燈泡狀態反轉\n");
    printf("　　輸入前　　　　　輸入後\n");
    printf("　１２３４５　　　１２３４５\n");
    printf("Ａ＊ＯＯＯＯ　　ＡＯ＊＊＊＊\n");
    printf("Ｂ＊＊＊＊＊　　ＢＯ＊＊＊＊\n");
    printf("Ｃ＊ＯＯＯＯ　　ＣＯＯＯＯＯ\n");
    printf("Ｄ＊ＯＯＯＯ　　ＤＯＯＯＯＯ\n");
    printf("Ｅ＊ＯＯＯＯ　　ＥＯＯＯＯＯ\n");
    printf("\n");
    printf("\033[0m\033[1;31m聽說七步之內必有最佳解,絞盡腦汁把名字留在榮譽榜吧!!!\033[0m\n");
}

void py(int py)// 模式2
{
    char bo[si][si];
    char name[100] = " ";
    int sp = 0;
    int r = 0, c = 0;
    srand((unsigned)time(NULL));
    time_t startTime, endTime;
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
        {
            bo[i][j] = 'O';
        }
    }
    for (int nd = 0;nd < (((py-1)%5)+1);nd++)
    {
        r = rand() % 5;
        c = rand() % 5;
        if (py == 115)
        {
            printf("%c %c\n", r + 'A', c + '1');
        }
        prbu(bo, r, c);
    }
    printf("-------------------------------------------------------------------\n");
    printf("歡迎遊玩，十字滅燈遊戲\n");
    printbo(bo);
    startTime = time(NULL);
    while (1) 
    {
        char ip[3];
        printf("請輸入座標(例如:A1,b2):");
        scanf("%s", ip);
        ip[0] = toupper(ip[0]);
        int row = ip[0] - 'A';
        int col = ip[1] - '1';
        if (row < 0 || row >= si || col < 0 || col >= si) 
        {
            printf("輸入座標錯誤，請重新輸入\n");
            continue;
        }
        prbu(bo, row, col);
        sp++;
        printf("第%d步:\n", sp);
        printbo(bo);
        if (chk(bo)) 
        {
            endTime = time(NULL);
            double edt = difftime(endTime, startTime);
            printf("恭喜過關 總耗 %d 步 總耗時 %.2f 秒\n", sp, edt);
            if (py == 5)
            {
               gack(sp,edt);
            }
            break;
        }
    }
}


void printbo(char bo[si][si]) // 模式2 列印
{
    printf("\n  1 2 3 4 5\n");
    for (int i = 0; i < si; i++) 
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < si; j++) 
        {
            printf("%c ", bo[i][j]);
        }
        printf("\n");
    }
}



void prbu(char bo[si][si], int row, int col) // 模式2 反轉
{
    bo[row][col] = (bo[row][col] == 'O') ? '*' : 'O';
    for (int i = 0; i < si; i++) 
    {
        if (i != col) 
        {
            bo[row][i] = (bo[row][i] == 'O') ? '*' : 'O';
        }
    }
    for (int j = 0; j < si; j++) 
    {
        if (j != row) 
        {
            bo[j][col] = (bo[j][col] == 'O') ? '*' : 'O';
        }
    }
}



int chk(char bo[si][si]) // 模式2  通關?
{
    for (int i = 0; i < si; i++) 
    {
        for (int j = 0; j < si; j++) 
        {
            if (bo[i][j] == 'O') 
            {
                return 0;
            }
        }
    }
    return 1;
}

struct product
{
    char gName[20];
    int sp;
    float et;
};

void ptga(int da)// 模式3 顯示
{
        FILE* pfile;
        struct product ga[3];
        int i = 0, iNum = 0;
        if ((pfile = fopen("..\\41243232\\game.txt", "r")) == NULL) 
        {
            printf("game.txt 檔案無法開啟");
            system("pause");
        }

        while (!feof(pfile))
        {
            if (fscanf(pfile, "%s" "%d" "%f", &ga[i].gName, &ga[i].sp, &ga[i].et) != EOF)
            {
                i++;
            }
        }
        iNum = i;
        printf("\033[0m\033[1;43m***歷史最佳紀錄三名玩家***\033[0m\n");
        for (i = 0;i < iNum;i++)
        {
            printf("第%d名 玩家名稱: %s  使用步數: %d  使用秒數: %.2f\n", i+1,ga[i].gName, ga[i].sp, ga[i].et);
        }
        fclose(pfile);
}



void gack(int spck,float etck)// 模式2 最佳?
{
    FILE* pfile;
    struct product gack[4];
    struct product tp;
    int i = 0, iNum = 0, t = 0, min = 0, amin = 0;
    float ft;
    char st[100] = " ";
    if ((pfile = fopen("..\\41243232\\game.txt", "r")) == NULL)
    {
        printf("game.txt 檔案無法開啟");
        system("pause");
    }
    while (!feof(pfile))
    {
        if (fscanf(pfile, "%s" "%d" "%f", &gack[i].gName, &gack[i].sp, &gack[i].et) != EOF)
        {
            i++;
        }
    }
    iNum = i;
    printf("玩家名稱若有空白請用_代替\n");
    printf("輸入玩家名稱 : ");
    scanf("%s", gack[3].gName);
    gack[3].sp = spck;
    gack[3].et = etck;

    for (int j = 0; j < 4; j++) {
        min = j;
        for (int k = j + 1; k < 4; k++)
        {
            amin = min;
            if (gack[min].et > gack[k].et)
            {
                min = k;
            }
        }
       tp = gack[min];
       gack[min] = gack[j];
       gack[j] = tp;
    }

    for (int j = 0; j < 4; j++) {
        min = j;
        for (int k = j + 1; k < 4; k++)
        {
            amin = min;
            if (gack[min].sp > gack[k].sp)
            {
                min = k;
            }
        }
       tp = gack[min];
       gack[min] = gack[j];
       gack[j] = tp;
    }

    fclose(pfile);
    if ((pfile = fopen("..\\41243232\\game.txt", "w")) == NULL)
    {
        printf("game.txt 檔案無法開啟");
        system("pause");
    }
    for (int i = 0;i <iNum;i++)
    {
        
        fprintf(pfile, "%s ", gack[i].gName);
       
        fprintf(pfile, "%d ", gack[i].sp);
        
        fprintf(pfile, "%.2f\n", gack[i].et);
    }
    fclose(pfile); 

}
