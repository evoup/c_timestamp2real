/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */

/* 这份源代码文件已被未注册的SourceFormatX格式化过 */
/* 如果您想不再添加此类信息，请您注册这个共享软件  */
/* 更多相关信息请访问网站: http://cn.textrush.com  */
/*
Name: 系统时间转UNIX时间戳工具
Copyright:上海大学成教2007计算机专生本
Author:殷嘉
Date: 16-06-07 14:23
Description: 没有完成Unix时间戳转时间,只能算1970-2038年的
既然CTime只是简单地计算从1970年1月1日之后经过的秒数，所以到了2 0 3 7年它将达到4 2 9 4 9 6 7 2 9 5，从而不能再使用。

 */

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "1970.h"

int main(int argc, char *argv)
{
  int y, m, d, h, n, s, timezone, tempstr;

  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  //printf("%s", timeinfo);

  extern struct tm y1970; //纯粹多写
  extern time_t t1970;
  y1970.tm_sec = y1970.tm_min = 0;
  y1970.tm_hour = 0;
  y1970.tm_mday = 1;
  y1970.tm_mon = 0;
  y1970.tm_year = 1970-1900;
  y1970.tm_isdst = 0;

  t1970 = mktime(&y1970);
  wrline();
  printf("The current date/time is: %s", asctime(timeinfo));
  printf(
    "系统时间转UNIX时间戳工具      作者：殷嘉\n(只能处理1970-2038年的时间段,因为ctime的限制。)\n");

  wrline();

  printf("请输入年：");
  scanf("%d", &y);
  // checkdate(1,y);
  printf("请输入月：");
  scanf("%d", &m);
  printf("请输入日：");
  scanf("%d", &d);
  printf("请输入时：");
  scanf("%d", &h);
  printf("请输入分：");
  scanf("%d", &n);
  printf("请输入秒：");
  scanf("%d", &s);
  printf("请输入时区：");
  scanf("%d", &timezone);
  getunixtimestamp(&y, &m, &d, &h, &n, &s, &timezone);
  system("pause");
  exit(0);
}

getunixtimestamp(int *y, int *m, int *d, int *h, int *n, int *s, int *timezone)
{
  int tzone;
  tzone =  *timezone;
  double dif;
  //printf("%d/%d/%d",*y,*m,*d);
  struct tm timeinfo;
  time_t tget;
  timeinfo.tm_year =  *y - 1900;
  timeinfo.tm_mon =  *m - 1;
  timeinfo.tm_mday =  *d;
  timeinfo.tm_hour =  *h;
  timeinfo.tm_min =  *n;
  timeinfo.tm_sec =  *s;
  timeinfo.tm_isdst = 0; //关闭夏令时
  tget = mktime(&timeinfo);

  dif = difftime(tget, t1970);
  //printf("%f\n",tget);
  //printf ("UNIX时间戳为 %.2lf \n", dif-*timezone*3600);
  //这里是大于等于1970年1月1日的算法
  printf("UNIX时间戳为 %.f \n", dif + (8- *timezone) *3600-1);
  //这是系统时区(编译器是正8区的)算出来的结果,自然要加8*3600秒
  //下面少个小于1970年1月1日的算法
  if ((*y - 1970) < 0)
  {
    printf("UNIX时间戳为 %.f \n",  - dif - (8- *timezone) *3600-1);
  }
}

wrline()
{
  int i;
  //gcc 默认 gnu-9x 标准，C89 搭配 GNU 扩展。 如果写成for ( int i = 0; ; )编译连接的时候多加一个 --std=c99 试试
  for (i = 0; i < 60; i++)
  {
    i < 59 ? printf("*"): printf("\n");
  }
}
