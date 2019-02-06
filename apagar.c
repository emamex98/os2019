#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char ** argv){
	shutdown();
	// Esta no funcionsrá porque el kernel esta en kernel esta en modo protegido
	//outw(0xb004, 0x2000);
	exit();
}