#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define si 5

void printbo(char[][5]);//�C�L

void prbu(char[][5], int, int);//����

int chk(char[][5]);//�L��

void py(int);

void pt(int);

void ptga(int);

void gack(int,float);

void ckwr(int);

int main() // �D�{��
{
    int nd,mo;
    printf("�Ҧ�0: ���}, �Ҧ�1: �C������, �Ҧ�2: �C���C��, �Ҧ�3: �C���a�A�]\n");
    printf("�п�ܼҦ�: ");
    scanf("%d",&mo);
    while (mo!=0)
    {
        switch (mo)
        {
        case 1:
            pt(mo);
            break;
        case 2:
            printf("\033[0m\033[1;31m***�u������5�i�H�N�C������,�����i�a�A�]��***\033[0m\n");
            printf("�п������(1~5): ");
            scanf("%d",&nd);
            py(nd);
            break;
        case 3:
            ptga(mo);
            break;
        case 111:
            printf("\033[0m\033[1;32m***�}�o�H���Ҧ�***\033[0m\n");
            py(115);
            break;
        default:
            break;
        }
        printf("-------------------------------------------------------------------\n");
        printf("�Ҧ�0: ���}, �Ҧ�1: �C������, �Ҧ�2: �C���C��, �Ҧ�3: �C���a�A�]\n");
        printf("�п�ܼҦ�: ");
        scanf("%d", &mo);
    }
    system("pause");
    return 0;
}

void pt(int pt)// �Ҧ�1 
{
    printf("-------------------------------------------------------------------\n");
    printf("�Q�r���O�C��,�C���W�h����\n");
    printf("5*5���O���A���U�����O�w�A�����O�w��P�C�����O�A�������O�w����G�O\n");
    printf("�Ҧp:��JA1�AA�C�O�w���A����A1��O�w���A����\n");
    printf("�@�@��J�e�@�@�@�@�@��J��\n");
    printf("�@�����������@�@�@����������\n");
    printf("�ϡ��ݢݢݢݡ@�@�Ϣݡ�������\n");
    printf("�С����������@�@�Тݡ�������\n");
    printf("�ѡ��ݢݢݢݡ@�@�Ѣݢݢݢݢ�\n");
    printf("�ҡ��ݢݢݢݡ@�@�Ңݢݢݢݢ�\n");
    printf("�ӡ��ݢݢݢݡ@�@�Ӣݢݢݢݢ�\n");
    printf("\n");
    printf("\033[0m\033[1;31mť���C�B���������̨θ�,���ɸ��ħ�W�r�d�b�a�A�]�a!!!\033[0m\n");
}

void py(int py)// �Ҧ�2
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
    printf("�w��C���A�Q�r���O�C��\n");
    printbo(bo);
    startTime = time(NULL);
    while (1) 
    {
        char ip[3];
        printf("�п�J�y��(�Ҧp:A1,b2):");
        scanf("%s", ip);
        ip[0] = toupper(ip[0]);
        int row = ip[0] - 'A';
        int col = ip[1] - '1';
        if (row < 0 || row >= si || col < 0 || col >= si) 
        {
            printf("��J�y�п��~�A�Э��s��J\n");
            continue;
        }
        prbu(bo, row, col);
        sp++;
        printf("��%d�B:\n", sp);
        printbo(bo);
        if (chk(bo)) 
        {
            endTime = time(NULL);
            double edt = difftime(endTime, startTime);
            printf("���߹L�� �`�� %d �B �`�Ӯ� %.2f ��\n", sp, edt);
            if (py == 5)
            {
               gack(sp,edt);
            }
            break;
        }
    }
}


void printbo(char bo[si][si]) // �Ҧ�2 �C�L
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



void prbu(char bo[si][si], int row, int col) // �Ҧ�2 ����
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



int chk(char bo[si][si]) // �Ҧ�2  �q��?
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

void ptga(int da)// �Ҧ�3 ���
{
        FILE* pfile;
        struct product ga[3];
        int i = 0, iNum = 0;
        if ((pfile = fopen("..\\41243232\\game.txt", "r")) == NULL) 
        {
            printf("game.txt �ɮ׵L�k�}��");
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
        printf("\033[0m\033[1;43m***���v�̨ά����T�W���a***\033[0m\n");
        for (i = 0;i < iNum;i++)
        {
            printf("��%d�W ���a�W��: %s  �ϥΨB��: %d  �ϥά��: %.2f\n", i+1,ga[i].gName, ga[i].sp, ga[i].et);
        }
        fclose(pfile);
}



void gack(int spck,float etck)// �Ҧ�2 �̨�?
{
    FILE* pfile;
    struct product gack[4];
    int i = 0, iNum = 0, t = 0, min = 0, amin = 0;
    float ft;
    char st[100] = " ";
    if ((pfile = fopen("..\\41243232\\game.txt", "r")) == NULL)
    {
        printf("game.txt �ɮ׵L�k�}��");
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
    printf("���a�W�٭Y���ťսХ�_�N��\n");
    printf("��J���a�W�� : ");
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
        t = gack[min].sp;
        gack[min].sp = gack[j].sp;
        gack[j].sp = t;

        ft = gack[min].et;
        gack[min].et = gack[j].et;
        gack[j].et = ft;

        strcpy(st, gack[min].gName);
        strcpy(gack[min].gName, gack[j].gName);
        strcpy(gack[j].gName, st);
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
        t = gack[min].sp;
        gack[min].sp = gack[j].sp;
        gack[j].sp = t;

        ft = gack[min].et;
        gack[min].et = gack[j].et;
        gack[j].et = ft;

        strcpy(st, gack[min].gName);
        strcpy(gack[min].gName, gack[j].gName);
        strcpy(gack[j].gName, st);
    }

    fclose(pfile);
    if ((pfile = fopen("..\\41243232\\game.txt", "w")) == NULL)
    {
        printf("game.txt �ɮ׵L�k�}��");
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
