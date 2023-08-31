#include <stdio.h>
#include <unistd.h>
#define LEN 50
int main(int argc, char * argv[]) {
	int fds[2];
	char buffer[LEN];
	char buffer_out[LEN];
	int ret = pipe(fds);
	
	char * str = fgets(buffer, LEN, stdin);
	write(fds[1], buffer, LEN);
	read(fds[0], buffer_out, LEN);
	
	printf("%s", buffer_out);
	return 0;
}
