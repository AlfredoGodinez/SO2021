#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

// 0 = stdin
// 1 = stdout

int main(){
 int cont=0;
 char linea;
	while(read(0,&linea,1)){
		if(linea == '\n'){
			cont++;
		}
	}
	printf("El numero de lineas es: %d\n", cont);
	return 0;
}