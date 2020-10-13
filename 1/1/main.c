#include "stdio.h"
#include <string.h>
#include <locale.h>

#define ASIZE 0x7f

int main()
{
	setlocale(0,"Russian");

	// 1. �������� ����������

	int count[ASIZE]; //- ������ (int)
	char fname[20]; // - ������ (char)
	//int count ;//- ������� (int)
	FILE* fin ;//- ���������� ��� ������ � �������
	char ch;
	int i;
	int close;

	char type[60];


	//�������� ������
	for(i=0; i<= ASIZE; i++)
		count[i] = 0;

	printf("Enter file name: ");
	scanf("%s", fname);

	//- ���� ������ �����-������ ������ - �� ���� ��� ��� �����

	fin = fopen(fname, "r"); //- ������� ��� ������ � �������
	if(!fin) //2. �������� ������ �������� �����, ���� ����, �� return 0
	{
		perror("File open error"); //- ������ �������� �����
		return 0;
	}

	//������ 3-6 ��������� � ����� while, ���� �� eof/feof
	while(!feof(fin)) //3. �������� eof(feof) - ��������, ��� ���� �� ����
	{
		fscanf(fin, "%c",&ch); //4. ���������� �� �����

	//6. ��������� � �.�. �������� ��������� ��������� � �.�.
		if(!ch)//5. �������� ������ ������
			printf("read error");

		count[ch]++;
	}

	printf("element  code  count  type\n");

	for(i=0; i<= ASIZE; i++)
	{
//7. ������ ������
	if(i <= 0x1f)
		strcpy(type, "����������� �������");
	else
		if(i <= 0x2f)
			strcpy(type, "����������� �������");
		else
			if(i <= 0x39)
				strcpy(type, "�����");
			else
				if(i <= 0x40)
					strcpy(type, "����������� �������");
				else
					if(i <= 0x5a)
						strcpy(type, "��������� �����");
					else
						if(i <= 0x60)
							strcpy(type, "����������� �������");
						else
							if(i <= 0x7a)
								strcpy(type, "�������� �����");
							else
								if(i <= 0x7e)
									strcpy(type, "����������� �������");
								else
									strcpy(type, "����������� �������");

	//8. ������ ������ � �������
		if(count[i]>0)
			printf("'%c' \t %x \t %d \t %s \n",i,i, count[i], type);
	}

	//9. �������� �����
	close = fclose(fin);
	//10. �������� �������� �����
	if(close != 0)
		perror("File close error");

	//11. Return 0;}
	return 0;
}
