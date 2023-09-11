#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    
    // Burada biraz bekleyebilirsiniz, işlem yapabilirsiniz veya başka bir şey yapabilirsiniz.
    sleep(1);
    
    gettimeofday(&end_time, NULL);
    
    long long elapsed_time = ((end_time.tv_sec - start_time.tv_sec) * 1000LL) + ((end_time.tv_usec - start_time.tv_usec) / 1000LL);
    
    // Milisaniyeyi saniyeye çevir
    double elapsed_seconds = (double)elapsed_time / 1000.0;
    
    printf("Geçen süre (saniye): %.3lf\n", elapsed_seconds);
    
    return 0;
}
