/*
 * form-adder.c - a minimal CGI program that adds two numbers together
 */
#include "../csapp.h"

int main(void) {
  char *buf, *p;
  char arg1[MAXLINE],arg2[MAXLINE], content[MAXLINE];
  int n1= 0, n2=0;

  if((buf = getenv("QUERY_STRING")) != NULL){//QUERY_STRING은 웹 서버로부터 전달된 쿼리 문자열 저장
    p = strchr(buf,'&'); //& 글자 위치 포인팅
    *p = '\0'; //문장 끝 삽입
    sscanf(buf,"first=%d", &n1); // 첫번 째 문자열 n1에 저장
    sscanf(p+1,"second=%d",&n2); // 두번 째 문자열 n2에 저장
  }

  sprintf(content,"welcome to add.com: ");
  sprintf(content,"%sTHE Internet addition portal.\r\n<p>",content);
  sprintf(content,"%sThe answer is: %d + %d = %d \r\n<p>",content,n1,n2,n1+n2);
  sprintf(content,"%sThanks for visiting!\r\n",content);

  printf("Connection: close\r\n");
  printf("Content-length:%d\r\n",(int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");
  printf("%s",content);
  fflush(stdout);

  exit(0);
}
