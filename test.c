#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <lo/lo.h>
#include <time.h>

#define STRENGTH 64

int main(int argc, char *argv[]) {
    lo_address t = lo_address_new(NULL, "7771");
    int result;
    int i;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (argc <= 1) {
      printf("sample name?");
      exit(-1);
    }
    lo_send(t, "/play", "iis", tv.tv_sec, tv.tv_usec, argv[1]);
    
    /*    for(i = 0; i < STRENGTH; ++i) {
      tv.tv_usec += 8000 + 100 * i;

      while (tv.tv_usec > 1000000) {
        tv.tv_usec -= 1000000;
        tv.tv_sec++;
      }
      result = lo_send(t, "/play", "iis", tv.tv_sec, tv.tv_usec, "chin/0");
    }
    */
    printf("result: %d\n", result);

    return(0);
}
