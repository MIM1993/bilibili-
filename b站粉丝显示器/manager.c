#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int main()
{
    //�ļ�ָ��
    FILE *fp;
    //˫���ȱ���  ˢ���ٶ�
    double speed = 1;
    int id, follow, whister, black, fans;
    char download[100] = "wget https://api.bilibili.com/x/relation/stat?vmid=";
    char filename[30] = "stat@vmid=";
    char delfile[30] = "del stat*";

    //������Ϣ
    char uid[11] = {0};
    printf("�������ѯUP��UID��\n");
    scanf("%10s", uid);
    printf("�������ѯѭ��ʱ�䣺\n");
    scanf("%lf", &speed);
    speed *= 6e8;          //����ת��Ϊ΢��
    strcat(download, uid); //��������
    strcat(download, ">nul 2>nul");
    strcat(filename, uid); //�ļ���

start:
    system(download);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("�ļ����ʴ��󣡰�������˳���\n");
        getch();
        exit(0);
    }
    fscanf(fp, "{\"code\":0,\"message\":\"0\",\"ttl\":1,\"data\":{\"mid\":%d,\"following\":%d,\"whisper\":%d,\"black\":%d,\"follower\":%d}}", &id, &follow, &whister, &black, &fans);
    printf("��ǰ��˿����%d\n", fans);
    fclose(fp);
    system(delfile);
    for (int i = 0; i < speed; i++);

    goto start;
}
