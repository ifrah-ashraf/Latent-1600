#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/stat.h>

int main()
{
    DIR *d;
    struct dirent *de;
    struct stat buf;
    int i, j;
    char P[10] = "rwxrwxrwx", AP[10];
    struct passwd *p;
    struct group *g;
    struct tm *t;
    char time[26];
    d = opendir(".");

    while ((de = readdir(d)) != NULL)
    {
        stat(de->d_name, &buf);
        // file type
        if (S_ISDIR(buf.st_mode))
            printf("d");
        else if (S_ISREG(buf.st_mode))
            printf("_");
        else if (S_ISCHR(buf.st_mode))
            printf("c");
        else if (S_ISBLK(buf.st_mode))
            printf("b");
        else if (S_ISLNK(buf.st_mode))
            printf("l");
        else if (S_ISFIFO(buf.st_mode))
            printf("p");
        else if (S_ISSOCK(buf.st_mode))
            printf("s");

        //file permissions 
        for(i=0 , j = (1<<8); i<9 ; i++ , j>>1)
        AP[i]=(buf.st_mode & j) ? P[i] : '-';
        printf("%s", AP);

        //No. of hard links 
        printf("%5ld\t", buf.st_nlink);

        //user name
        p=getpwuid(buf.st_uid);
        printf("%.8s\t",p->pw_name);

        //group name
        g=getgrgid(buf.st_gid);
        printf("%s\t", g->gr_name);

        //file size
        printf("%8ld\t", buf.st_size);

        //Date and time of modification
        t=localtime(&buf.st_mtime);
        strftime(time , sizeof(time), "%b %d %H:%M", t);
        printf("%s\t", time);

        //File name 
        printf("%s\n", de->d_name);
    }
}