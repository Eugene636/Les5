#include <iostream>
#include <stdarg.h>
#include <cstdlib>
#include <ctime>

namespace lt_tsk {
	int sum (int a, int b);
	int diff (int a, int b);
	int mul (int a, int b);
	double div (int& a, int& b);
}

void Task1 (int size, unsigned int* M) {
	for (int k = 0; k < size; k++)
    {	
	std::cout << *(M + k);
	*(M + k) ^= 1;
	std::cout << "   " << *(M + k)<<std::endl;
    }
}
void Task2 (int size, int* p)
{
	int i, k;
	for (i = 0, k = 1; i < size; i++, k += 3) *(p + i) = k;
}

bool Task3 (int size, int* M) {
    int l, r, i;
	for (int k = 1; k < size; k++)
	{  
		for (i = 0, l = 0; i < k; i++)
	    {
		   l += M[i];
	    }
        for ( i = (size - 1), r = 0; i >= k ; i--)
	    {
		   r += M[i];
	    }		
		if (l == r) return true;
	}
    return false;
}
void Task4 (int n, int* M, unsigned int size = 15) {
	int t[size];
	for (int i = 0; i < size; i++)
		t[i] = *(M + i);
	std::cout << n << std::endl;
	if (n >= 0) n %=size;
	else 
	{
		n = 0 - n;
		n %= size;
		n = size - n;
	}
	    for (int i = 0; i < size; i++)
		  (i - n) >= 0 ? M[i] = t[i - n]: M[i] = t[i - n + 15];

}
void Task5 (int count, ...){
	unsigned int* p[count];
    va_list m;
    va_start (m, count);
	for (int i = 0; i < count; i++)
	   p[i] = va_arg (m, unsigned int*);
    va_end(m);
	for (int i = 0; i < count; i++)	
       *p[i] ^= 1;
}
int main (void) {
{//Task 1
	unsigned int M[15];
    srand (time (NULL));
	for (int k = 0; k < 15; k++) *(M + k) = rand()&1U ;
    Task1 (15, M);
}
{//Task2
	int M[8];
	Task2 (8, M);
	for (int i = 0; i < 8; i++) std::cout << *(M + i) << std::endl;
}
{//Task3
   int M[5];
   for (int i = 0; i < 5; i++)
   {
	   std::cout <<"Enter a "<< i << " element of massive"<< std::endl;
	   std::cin >> M[i];
   }
  
   if (Task3(5, M)) std::cout << "Result is true" << std::endl;
   else  std::cout << "Result is false" << std::endl;
}
{//Task4
    int M[15];
	for (int i = 0; i < 15; i++)
		M[i] = rand()%10;
	for (int i = 0; i < 15; i++) std::cout << M[i] <<" ";
	std::cout << std::endl;
	std::cout<<"Print number for move: ";
    int n;
	std::cin >> n;
	Task4 (n, M);
	for (int i = 0; i < 15; i++) std::cout << M[i] <<" ";
	std::cout << std::endl;
}
{//Task5
    unsigned int const size = 10;
	unsigned int M[size];
    srand (time (NULL));
	for (int k = 0; k < size; k++) *(M + k) = rand()&1U;
	for (int k = 0; k < size; k++)
	   std::cout << *(M + k) <<" ";
    std::cout << std::endl;
	unsigned int* p = M; 
    Task5 (size, p, (p + 1), (p + 2), (p + 3), (p + 4), (p + 5), (p + 6), (p + 7), (p + 8), (p + 9));
    for (int k = 0; k < size; k++)
	   std::cout << *(M + k) <<" ";
    std::cout << std::endl;
}	
{//Task6
	using namespace lt_tsk;
	int (*f[3])(int, int);
	f[0] = sum;
	f[1] = diff;
	f[2] = mul;
    int a = 3, b = 4;
	for (int i = 0; i < 3; i++) std::cout << f[i](a, b) << std::endl;
	double (*d) (int&, int&) = div;
	std::cout << (*d)(a, b) << std::endl;
	
}
	
	

	return 0;

}