#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

int main()
{
    //文件指针
    FILE *fp;
    //双精度变量  刷新速度
    double speed = 1;
    int id, follow, whister, black, fans;
    char download[100] = "wget https://api.bilibili.com/x/relation/stat?vmid=";
    char filename[30] = "stat@vmid=";
    char delfile[30] = "del stat*";

    //输入信息
    char uid[11] = {0};
    printf("请输入查询UP主UID：\n");
    scanf("%10s", uid);
    printf("请输入查询循环时间：\n");
    scanf("%lf", &speed);
    speed *= 6e8;          //将秒转化为微秒
    strcat(download, uid); //下载命令
    strcat(download, ">nul 2>nul");
    strcat(filename, uid); //文件名

start:
    system(download);
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("文件访问错误！按任意键退出。\n");
        getch();
        exit(0);
    }
    fscanf(fp, "{\"code\":0,\"message\":\"0\",\"ttl\":1,\"data\":{\"mid\":%d,\"following\":%d,\"whisper\":%d,\"black\":%d,\"follower\":%d}}", &id, &follow, &whister, &black, &fans);
    printf("当前粉丝数：%d\n", fans);
    fclose(fp);
    system(delfile);
    for (int i = 0; i < speed; i++);

    goto start;
}
