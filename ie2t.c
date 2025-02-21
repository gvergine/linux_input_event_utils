#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>

int read_input_event(struct input_event * ie) {
    ssize_t bytes_read = 0;
    int offset = 0;

    do {
        bytes_read += read(STDIN_FILENO,ie+offset,sizeof(struct input_event)-offset);
        if (bytes_read <= 0) {
            perror("read");
            break;
        }
        offset = bytes_read;
    } while (bytes_read < (ssize_t)sizeof(struct input_event));

    return bytes_read == sizeof(struct input_event);
}

int main(void) {
    int ret;

    struct input_event ie;

    do {
        ret = read_input_event(&ie);
        if (!ret) break;

        printf("time=%ld.%06lu type=%hu code=%hu value=%d\n",
            ie.time.tv_sec,
            ie.time.tv_usec,
            ie.type,
            ie.code,
            ie.value);
    } while (ret);

    return ret;
}
