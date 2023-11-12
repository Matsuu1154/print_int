#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int print_int(int *i, int size, char *name, const char *func_name);
#define PRINT_INT(i, size, name, func_name) print_int((i), (size), (name), (func_name))

int print_int(int *i, int size, char *name, const char *func_name){
    for(int j=0; j<size; j++){
        printf("[%s]%s[%d] = %d\n", func_name, name, j, *(i+j));
    }
    return 0;
}

void print_now_time(){
    //struct timeval myTime;
    struct timespec myTime;
    clock_gettime(CLOCK_REALTIME, &myTime);
    //time_t t = (time_t)(myTime.tv_sec);

    struct tm *local = localtime(&myTime.tv_sec);

    printf("%04d/", local->tm_year + 1900);
    printf("%02d/", local->tm_mon + 1);
    printf("%02d", local->tm_mday);
    printf(" %02d:%02d:%02d.%06d\n", 
                local->tm_hour,
                local->tm_min,
                local->tm_sec,
                myTime.tv_nsec);
}

int main(){
    int i[5]={0, 1, 2, 3, 4};
    printf("[start_time] ");
    print_now_time();

    //printf("\t\t\t\t\t\t\t%d\t\t\t\t\t\t\t\t\t\t\t\t\t\t|1111\n", i);
    PRINT_INT(i, sizeof(i)/sizeof(i[0]), "iso", __func__);
    printf("[end_time] ");
    print_now_time();
    return 0;
}

