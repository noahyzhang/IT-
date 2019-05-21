#include<iostream>
#include<stdio.h>
#include<stdlib.h>

unsigned maximum = 0;
#if 0
int main()
{
	unsigned blocksize[] = { 1024*1024*1024*1024,1024 * 1024 * 1024,1024 * 1024,1024,1 };
	int i, count;
	for (i = 0; i < 5; ++i)
	{
		for (count = 1;; count++)
		{
			void* block = malloc(maximum + blocksize[i] * count);
			if (block)
			{
				maximum += blocksize[i] * count;
				free(block);
			}
			else
				break;
		}
	}
	printf("maximum malloc size = %u bytes\n", maximum);
	system("pause");
	return 0;
}
#endif

