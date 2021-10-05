#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
/*
Основой поток создает другой поток, передавая ему параметр. Параметр может принимать два
значения: 0 или 1. Если параметр равен 0, то поток организует задержку в 10 мс и завершает свое
выполнение. Если параметр равен 1, то второй поток создает третий поток, который содержит
единственную ассемблерную операцию NOP. Измерить время исполнения второго потока в обоих
случаях. Измерения повторить 10 раз.
*/

DWORD WINAPI thread3(LPVOID Null)
{
	__asm nop
	printf("Thread3\n");
	return 0;
}

DWORD WINAPI thread2(LPVOID flag)
{
	INT *flint = (int*)flag;
	if (*flint == 0)
	{
		Sleep(10);
		printf("Thread2: sleeping\n");
		return 0;
	}
	else if(*flint == 1) 
	{
		printf("Thread2: creating thread3\n");
		HANDLE thread_3 = CreateThread(NULL, 0, thread3, NULL, 0, NULL);
		if (thread_3 == NULL)
			return -1;
	}
}

int main()
{
	srand(10000);
	for (size_t i = 0; i < 10; i++)
	{
		DWORD rnum =(rand() + i) % 2 ;
		printf("%d step \n", i + 1);
		HANDLE thread = CreateThread(NULL, NULL, &thread2, &rnum, NULL, NULL);
		if (thread == NULL)
			return -1;	}
	return 0;
}

/*
http://shatalov.ghost17.ru/winapi/threads.html
*/
