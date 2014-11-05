#include<iconv.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int utf8togb2312(char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen) {   
    iconv_t cd;   
    if( (cd = iconv_open("gb2312","utf-8")) ==0 )     
              return -1;  
    memset(destbuf,0,destlen);   
    char **source = &sourcebuf;   
    char **dest = &destbuf;
    if(-1 == iconv(cd,source,&sourcelen,dest,&destlen))     
             return -1;   
    iconv_close(cd);   
    return 0;   
}

int gb2312toutf8(char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen) {   
    iconv_t cd;   
    if( (cd = iconv_open("utf-8","gb2312")) ==0 )     
        return -1;
    memset(destbuf,0,destlen);   
    char **source = &sourcebuf;   
    char **dest = &destbuf;
    if(-1 == iconv(cd,source,&sourcelen,dest,&destlen))     
          return -1;   
    iconv_close(cd);   
    return 0;   
}

int main() {  
    char line[80];  
    char dest_gb2312[200];  
    char dest_utf8[200];  
    int ret ;  
    FILE *fp = fopen("a.txt","r");  
    if(fp == NULL)    
    {      
        printf("oh my dear,open fail...\n");      
        return 1;    
    }
    memset(line,0,80);  
    if( NULL == fgets(line,80,fp))    
    {      
        printf("oh fgets fail...\n");      
        return 2;    
    }
    printf( "----- :%s\n",line );
    //ret  = gb2312toutf8(line,strlen(line),dest_gb2312,200);  
    ret  = gb2312toutf8(dest_gb2312,strlen(dest_gb2312),dest_utf8,80);  
    printf( "ret=%d\n\n\n",ret);  
    printf( "gb2312:%s\n",line );  
    printf( " utf-8:%s\n\n\n\n\n\n", dest_gb2312 );
    ret  = utf8togb2312(dest_gb2312,strlen(dest_gb2312),dest_utf8,200);  
    printf( "ret=%d\n\n\n ",ret);  
    printf( "utf-8:%s\n ",dest_gb2312);  
    printf( "gb2312:%s\n ",dest_utf8);
    return 0;
}


