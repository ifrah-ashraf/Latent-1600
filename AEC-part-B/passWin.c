#include<stdio.h>
#include<string.h>
int main(){
        char buff[15];
        int pass=0;
        printf("\n Enter the password:\n");
        gets(buff);
        if(strcmp(buff,"thegeeksstuff")){
            printf("\n wrong password\n");
        }
        else{
            printf("\n correct password\n");
            pass=1;
        }
        if(strlen(buff)>sizeof(buff))
            printf("buffer overflow\n");
        if(pass==1){
            printf("\n root privileges given to the user\n");
        }
        return 0;
}