#include <stdio.h>
#include<string.h>
int gcd( int a, int b ) {
    int result ;
    /* Compute Greatest Common Divisor using Euclid's Algorithm */
    __asm__ __volatile__ ( "movl %1, %%eax;"
                          "movl %2, %%ebx;"
                          "CONTD: cmpl $0, %%ebx;"
                          "je DONE;"
                          "xorl %%edx, %%edx;"
                          "idivl %%ebx;"
                          "movl %%ebx, %%eax;"
                          "movl %%edx, %%ebx;"
                          "jmp CONTD;"
                          "DONE: movl %%eax, %0;" : "=g" (result) : "g" (a), "g" (b)
    );

    return result ;
}


int sum(int a,int b)
{
	int result = 0;
	__asm__ __volatile (
		"movl %1, %%eax;"
		"addl %2, %%eax;"
		: "=g" (result) : "g" (a), "g" (b)		
	);
	return result;
}

int sub(int a,int b)
{
	int result = 0;
	__asm__ __volatile (
		"movl %1, %%eax;"
		"subl %2, %%eax;"
		: "=g" (result) : "g" (a), "g" (b)		
	);
	return result;
}

int mul(int a,int b)
{
	int result = 0;
	__asm__ __volatile (
		"movl %1, %%eax;"
		"imul %2, %%eax;"
		: "=g" (result) : "g" (a), "g" (b)		
	);
	return result;
}

int div(int a,int b)
{
	int result = 0;
	__asm__ __volatile (
		"movl %1, %%eax;"
		"movl $0, %%edx;"
		"idivl %2, %%eax;"
		: "=g" (result) : "g" (a), "g" (b)		
	);
	return result;
}

void swap(int * a, int * b)
{
//	//int temp = *a;
//	//*a = *b;
//	//*b = temp;
//	int temp= 0;
//	__asm__ __volatile (
//		"movl offset %1, %%esi;"
//		"movl $8, %%[%%esi];"
//		: "=g" (temp) : "g" (a), "g" (b)		
//	);
//	printf("\n temp = %d",*a);
}

int x(char ** str)
{
	int len = strlen(*str);
	int num =0;
	char ch = 'a';
	int result = 0;
	__asm__ __volatile (
		
		"lea %1,%%ebx;"
		"movb 1(%%ebx), %%eax;"
		: "=g" (ch) : "g" (*str), "g" (len)		
	);
	printf("\n%c",ch);
	printf("\nstring = %s",*str);
	return 0;
}

int main() 
{
	char * str = "hello world";
	x(&str);
	printf("\n%s",str);
	//printf("\n%d",sum(2,3));
	//printf("\n%d",sub(6,3));
	//printf("\n%d",mul(3,5));
	//printf("\n%d",div(10,5));	
    return 0 ;
}
