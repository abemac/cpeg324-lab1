#include <stdio.h>
#include <stdlib.h>
#define ADD 0
#define SUB 1
#define LI 2
#define CMP 3
#define PRINT 4

FILE* f;
char i[10];

int next_i();
int func();
void bad_i();

void add();
void sub();
void li();
void cmp();
void print();

//**registers
char reg[4];

void main(int argc, char *argv[]){
	//opens file of instructions for reading
	if(argc!=2){
		printf("Need to specify file\n");
		return;
	}
	f = fopen(argv[1],"r");
	//-------------------------------------
	
	
	//initializes registers
	for(int i=0;i<4;i++){
		reg[i]=0;
	}
	//-------------------------------------
	
	//runs each instruction
	while(next_i()){
		switch (func()){
			case ADD:
				add();
				break;
			case SUB:
				sub();
				break;
			case LI: 
				li();
				break;
			case CMP:
				cmp();
				break;
			case PRINT:
				print();
				break;
		}
	}
	
	printf("\nEnd of program\n");
	

	 	
}

void add(){
	int r1;
	if(i[2]=='0' && i[3]=='0'){
		r1=0;
	}
	else if(i[2]=='0' && i[3]=='1'){
		r1=1;
	}
	else if(i[2]=='1' && i[3]=='0'){
		r1=2;
	}
	else if(i[2]=='1' && i[3]=='1'){
		r1=3;
	}else{
		bad_i();
	}
	
	int r2;
	if(i[4]=='0' && i[5]=='0'){
		r2=0;
	}
	else if(i[4]=='0' && i[5]=='1'){
		r2=1;
	}
	else if(i[4]=='1' && i[5]=='0'){
		r2=2;
	}
	else if(i[4]=='1' && i[5]=='1'){
		r2=3;
	}else{
		bad_i();
	}
	
	int r3;
	if(i[6]=='0' && i[7]=='0'){
		r3=0;
	}
	else if(i[6]=='0' && i[7]=='1'){
		r3=1;
	}
	else if(i[6]=='1' && i[7]=='0'){
		r3=2;
	}
	else if(i[6]=='1' && i[7]=='1'){
		r3=3;
	}else{
		bad_i();
	}
	
	reg[r1] = reg[r2]+reg[r3];
	
	
}
void sub(){
	int r1;
	if(i[2]=='0' && i[3]=='0'){
		r1=0;
	}
	else if(i[2]=='0' && i[3]=='1'){
		r1=1;
	}
	else if(i[2]=='1' && i[3]=='0'){
		r1=2;
	}
	else if(i[2]=='1' && i[3]=='1'){
		r1=3;
	}else{
		bad_i();
	}
	
	int r2;
	if(i[4]=='0' && i[5]=='0'){
		r2=0;
	}
	else if(i[4]=='0' && i[5]=='1'){
		r2=1;
	}
	else if(i[4]=='1' && i[5]=='0'){
		r2=2;
	}
	else if(i[4]=='1' && i[5]=='1'){
		r2=3;
	}else{
		bad_i();
	}
	
	int r3;
	if(i[6]=='0' && i[7]=='0'){
		r3=0;
	}
	else if(i[6]=='0' && i[7]=='1'){
		r3=1;
	}
	else if(i[6]=='1' && i[7]=='0'){
		r3=2;
	}
	else if(i[6]=='1' && i[7]=='1'){
		r3=3;
	}else{
		bad_i();
	}
	
	reg[r1] = reg[r2]-reg[r3];
	
	
}

void li(){
	int r1;
	if(i[2]=='0' && i[3]=='0'){
		r1=0;
	}
	else if(i[2]=='0' && i[3]=='1'){
		r1=1;
	}
	else if(i[2]=='1' && i[3]=='0'){
		r1=2;
	}
	else if(i[2]=='1' && i[3]=='1'){
		r1=3;
	}else{
		bad_i();
	}
	
	char imm=0;
	if(i[7]=='1'){
		imm|=1;
	}else if(i[7]!='0'){
		bad_i();
	}
	if(i[6]=='1'){
		imm|=2;
	}
	else if(i[6]!='0'){
		bad_i();
	}
	if(i[5]=='1'){
		imm|=4;
	}
	else if(i[5]!='0'){
		bad_i();
	}
	if(i[4]=='1'){
		imm|=0xF8;
	}
	else if(i[4]!='0'){
		bad_i();
	}
	reg[r1]= imm;
}

void cmp(){
	int r2;
	if(i[4]=='0' && i[5]=='0'){
		r2=0;
	}
	else if(i[4]=='0' && i[5]=='1'){
		r2=1;
	}
	else if(i[4]=='1' && i[5]=='0'){
		r2=2;
	}
	else if(i[4]=='1' && i[5]=='1'){
		r2=3;
	}else{
		bad_i();
	}
	
	int r3;
	if(i[6]=='0' && i[7]=='0'){
		r3=0;
	}
	else if(i[6]=='0' && i[7]=='1'){
		r3=1;
	}
	else if(i[6]=='1' && i[7]=='0'){
		r3=2;
	}
	else if(i[6]=='1' && i[7]=='1'){
		r3=3;
	}else{
		bad_i();
	}
	
	int skip;
	if(i[3]=='0'){
		skip=1;
	}else if(i[3]=='1'){
		skip=2;
	}else{
		bad_i();
	}
	//printf("%i\n",skip);
	
	if(reg[r2]==reg[r3]){
		while(skip>0){
			if(next_i()==0){
				printf("End of program\n");
				exit(0);
			}
			--skip;
		}
	}
}

void print(){
	int r1;
	if(i[3]=='0' && i[4]=='0'){
		r1=0;
	}
	else if(i[3]=='0' && i[4]=='1'){
		r1=1;
	}
	else if(i[3]=='1' && i[4]=='0'){
		r1=2;
	}
	else if(i[3]=='1' && i[4]=='1'){
		r1=3;
	}else{
		bad_i();
	}	
	if(i[5]=='1'){
		printf("Integer value of register %i: %i\n",r1,reg[r1]);
		
	}
	if(i[6]=='1'){
		printf("Hex value of register %i: 0x%x\n",r1,reg[r1]&0xff);
	}
	if(i[7]=='1'){
		printf("ASCII value of register %i: %c\n",r1,(unsigned char)(reg[r1]));
	}
	
}

int func(){
	if(i[0]=='0' && i[1]=='1'){
		return ADD;
	}
	else if(i[0]=='1' && i[1]=='0'){
		return SUB;
	}
	else if(i[0]=='1' && i[1]=='1'){
		return LI;
	}else if(i[0]=='0' && i[1]=='0'){
		if(i[2]=='1'){
			return CMP;
		}
		else if(i[2]=='0'){
			return PRINT;
		}
	}
	else{
		bad_i();
	}
}

int next_i(){
	if(fgets(i,9,f)!=NULL){
		if(i[0]=='\n'){
			return next_i();
		}
		//printf("Executing: %s\n",i);
		return 1;
	}
	else return 0;
}

void bad_i(){
	printf("**ERROR**: Incorrect instruction format encountered\n");
	exit(0);
}
