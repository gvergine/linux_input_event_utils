#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <sys/time.h>

void write_input_event(struct input_event * ie) {
    ssize_t bytes_written = 0;
    int offset = 0;

    do {
        bytes_written += write(STDOUT_FILENO,ie+offset,sizeof(struct input_event)-offset);
        if (bytes_written <= 0) {
            perror("write");
            break;
        }
        offset = bytes_written;
    } while (bytes_written < (ssize_t)sizeof(struct input_event));

    return;
}

int main(void) {
    int ret;

    struct input_event ie;

    do {
        ret = fscanf(stdin,"type=%hu code=%hu value=%d\n", &ie.type, &ie.code, &ie.value);
        if (ret == EOF) break;
        if (ret < 3) {
            perror("fscanf");
            continue;
        }
        if(gettimeofday(&ie.time,0)) {
            perror("gettimeofday");
            continue;
        }
        write_input_event(&ie);

    } while (ret);

    return ret;
}
