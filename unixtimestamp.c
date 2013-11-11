/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */

/* ���Դ�����ļ��ѱ�δע���SourceFormatX��ʽ���� */
/* ������벻����Ӵ�����Ϣ������ע������������  */
/* ���������Ϣ�������վ: http://cn.textrush.com  */
/*
Name: ϵͳʱ��תUNIXʱ�������
Copyright:�Ϻ���ѧ�ɽ�2007�����ר����
Author:���
Date: 16-06-07 14:23
Description: û�����Unixʱ���תʱ��,ֻ����1970-2038���
��ȻCTimeֻ�Ǽ򵥵ؼ����1970��1��1��֮�󾭹������������Ե���2 0 3 7�������ﵽ4 2 9 4 9 6 7 2 9 5���Ӷ�������ʹ�á�

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

  extern struct tm y1970; //�����д
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
    "ϵͳʱ��תUNIXʱ�������      ���ߣ����\n(ֻ�ܴ���1970-2038���ʱ���,��Ϊctime�����ơ�)\n");

  wrline();

  printf("�������꣺");
  scanf("%d", &y);
  // checkdate(1,y);
  printf("�������£�");
  scanf("%d", &m);
  printf("�������գ�");
  scanf("%d", &d);
  printf("������ʱ��");
  scanf("%d", &h);
  printf("������֣�");
  scanf("%d", &n);
  printf("�������룺");
  scanf("%d", &s);
  printf("������ʱ����");
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
  timeinfo.tm_isdst = 0; //�ر�����ʱ
  tget = mktime(&timeinfo);

  dif = difftime(tget, t1970);
  //printf("%f\n",tget);
  //printf ("UNIXʱ���Ϊ %.2lf \n", dif-*timezone*3600);
  //�����Ǵ��ڵ���1970��1��1�յ��㷨
  printf("UNIXʱ���Ϊ %.f \n", dif + (8- *timezone) *3600-1);
  //����ϵͳʱ��(����������8����)������Ľ��,��ȻҪ��8*3600��
  //�����ٸ�С��1970��1��1�յ��㷨
  if ((*y - 1970) < 0)
  {
    printf("UNIXʱ���Ϊ %.f \n",  - dif - (8- *timezone) *3600-1);
  }
}

wrline()
{
  int i;
  //gcc Ĭ�� gnu-9x ��׼��C89 ���� GNU ��չ�� ���д��for ( int i = 0; ; )�������ӵ�ʱ����һ�� --std=c99 ����
  for (i = 0; i < 60; i++)
  {
    i < 59 ? printf("*"): printf("\n");
  }
}
