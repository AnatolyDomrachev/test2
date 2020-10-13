#include "stdio.h"
#include <string.h>
#include <locale.h>

#define ASIZE 0x7f

int main()
{
	setlocale(0,"Russian");

	// 1. Описание переменных

	int count[ASIZE]; //- Массив (int)
	char fname[20]; // - Массив (char)
	//int count ;//- Счётчик (int)
	FILE* fin ;//- Переменные для работы с файлами
	char ch;
	int i;
	int close;

	char type[60];


	//Зануляем массив
	for(i=0; i<= ASIZE; i++)
		count[i] = 0;

	printf("Enter file name: ");
	scanf("%s", fname);

	//- Поле ошибок ввода-вывода данных - не ясно что это такое

	fin = fopen(fname, "r"); //- Функции для работы с файлами
	if(!fin) //2. Проверка ошибки открытия файла, если есть, то return 0
	{
		perror("File open error"); //- Ошибка открытия файла
		return 0;
	}

	//Пункты 3-6 находятся в цикле while, пока не eof/feof
	while(!feof(fin)) //3. Проверка eof(feof) - проверка, что файл не пуст
	{
		fscanf(fin, "%c",&ch); //4. Считывание из файла

	//6. Сравнение и т.д. операции изменения счётчиков и т.д.
		if(!ch)//5. Проверка ошибки чтения
			printf("read error");

		count[ch]++;
	}

	printf("element  code  count  type\n");

	for(i=0; i<= ASIZE; i++)
	{
//7. Анализ итогов
	if(i <= 0x1f)
		strcpy(type, "Управляющие символы");
	else
		if(i <= 0x2f)
			strcpy(type, "Специальные символы");
		else
			if(i <= 0x39)
				strcpy(type, "Число");
			else
				if(i <= 0x40)
					strcpy(type, "Специальные символы");
				else
					if(i <= 0x5a)
						strcpy(type, "Прописные буквы");
					else
						if(i <= 0x60)
							strcpy(type, "Специальные символы");
						else
							if(i <= 0x7a)
								strcpy(type, "Строчные буквы");
							else
								if(i <= 0x7e)
									strcpy(type, "Специальные символы");
								else
									strcpy(type, "Управляющие символы");

	//8. Запись итогов в таблицу
		if(count[i]>0)
			printf("'%c' \t %x \t %d \t %s \n",i,i, count[i], type);
	}

	//9. Закрытие файла
	close = fclose(fin);
	//10. Проверка закрытия файла
	if(close != 0)
		perror("File close error");

	//11. Return 0;}
	return 0;
}
