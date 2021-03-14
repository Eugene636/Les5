#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>


void Task1 (void){
	std::ofstream t1 ("t1.txt");
	std::ofstream t2 ("t2.txt");
	std::string M[12] = {"abcde", "efg", "jkl", "mno", "pqr", "sty", "kl", "mno", "pqrst", "uv", "w", "XYZ"};
	srand (time (NULL));
	std::cout << M[0] << std::endl;
    for (int j = 0, k = 0; j < 5; j++)
	{
	for (int i = 0; i < 12; i++){
        k  = rand()%12;
		t1 << M[k] << " ";
	}
		t1 << std::endl;
	}
    for (int j = 0, k = 0; j < 6; j++)
	{
	for (int i = 0; i < 12; i++){
        k  = rand()%12;
		t2 << M[k] << " ";
	}
		t2 << std::endl;
	}
	t1.close ();
	t2.close ();
}
void Task2 (void){
	std::ifstream t1 ("t1.txt");
	std::ifstream t2 ("t2.txt");
	std::ofstream t3 ("t3.txt");
	std::string l;
	std::string* M1 = new std::string[100];
	std::string* M2 = new std::string[100];
	int i1, i2;
	for (i1 = 0; t1 >> M1[i1]; i1++);
	for (i2 = 0; t2 >> M2[i2]; i2++);
	for (int i = 0; i < i1; i++)
	{
	     t3 << M1[i] << " ";
		 if (!((i + 1)%12)) t3 << std::endl;
	}
	for (int i = 0; i < i2; i++)
	{
	     t3 << M2[i] << " ";
		 if (!((i + 1)%12)) t3 << std::endl;
	}
	delete M1;
	delete M2;
	t1.close ();
	t2.close ();
	t3.close ();
}
void Task3 (void){
	std::string name;
	std::cout << "Enter filename:"<< std::endl;
	std::cin >> name;
	std::ifstream t1 (name);
	std::cout << "Enter a word:"<< std::endl;
	std::string l, k;
	bool flag = false;
	std::cin >> l;
	while  (t1 >> k)
	{
		if  (l == k){
            flag = true;
			
			break; 
		}
	std::cout << k <<std::endl;
	}
	t1.close();
	std::cout << flag << std::endl;
}
int main (int argc, char** argv) {
	Task1();
	Task2();
	Task3();
	return 0;
}