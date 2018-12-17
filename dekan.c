#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

#define number 30 //максимальное количество групп
#define dis 40 //макс количество учебных дисциплин


struct student //описание студента
{
	//	int pr;//если есть запись то 1, если нет - 0
	char surname[20];//фамилия
	char name[20];//имя
	int score[5];//5 оценок
	float av_score; //средний балл
	int verdict;//если 0 - нет долгов, 1-2 - допса, 3 и больше - отчислен
};

struct discipline //список дисциплин
{
	char name[40];
};

struct group //структура описания группы
{
	int pr;//если данные заполнены, то 1, в противном случае 0
	int num;//номер группы
	int count;//число студентов
	struct student stud[30];//массив "студентов" макс 30 человек в группе
	struct discipline disc[5];//список экзаменнационных дисциплин для конкретной группы
};


int count_group = 0, count_dis = 0;//количество групп, количество дисциплин
struct group spisok[number];
struct discipline predmet[dis];

void add();//добавление 
void mod_group();//добавить группу
void mod_gr_student(int i);//добавить студентов в новую групп
void mod_student();//добавить студента в существующую
void mod_disc();//добавить предмет
void delet();//удаление
void del_group();//удаление группы
void del_student();//удаление студента
void del_disc();//удаление дисциплины
void sort();//сортировка
void sort_group();//сортировка группы по алфавиту
void sort_ball();//сортировка по среднему баллу
void many();//сортировка по наличии стипендии


int main()
{
	int j, k, a, i;
	FILE *file = NULL;

	file = fopen("dekanat.txt", "a+");/*режим открытия файла, при котором данные записываются 
									  в конец файла, файл создается, если его не существует
									  если же файл есть, то данные в нем останутся нетронутыми*/
	fclose(file);

	file = fopen("dekanat.txt", "r");

	if (file != NULL)
	{
		for (i = 0; i<number; i++)
		{
			fscanf(file, "%i", &spisok[i].pr);
			if (spisok[i].pr != 0)
			{
				fscanf(file, "%i%i", &spisok[i].num, &spisok[i].count);
				for (j = 0; j<spisok[i].count; j++)
				{
					//fscanf(file, "%i", &spisok[i].stud[j].pr);
					//if(spisok[i].stud[j].pr != 0)
					//{
					fscanf(file, "%s%s", &spisok[i].stud[j].surname, &spisok[i].stud[j].name);
					for (k = 0; k<5; k++)
						fscanf(file, "%i", &spisok[i].stud[j].score[k]);
					fscanf(file, "%f%i", &spisok[i].stud[j].av_score, &spisok[i].stud[j].verdict);
					//	}
					//	else
					//	break;
				}
				for (k = 0; k<5; k++)
					fscanf(file, "%s", &spisok[i].disc[k].name);
				count_group++;
			}
			else
				break;
		}
	}
	fclose(file);


	file = fopen("predmet.txt", "a+");
	fclose(file);

	file = fopen("predmet.txt", "r");
	if (file != NULL)
	{
		fscanf(file, "%i", &count_dis);
		for (i = 0; i<count_dis; i++)
		{
			fscanf(file, "%s", &predmet[i]);
		}
	}
	fclose(file);
	if (count_dis == 0)
	{
		printf("Vvedite predmeti(vvod zapisi -> Disciplina)!\nPotom vvedite gruppu(vvod zapisi -> Gruppa)\n\n");
	}
	do{

		printf("\n Viberite deistvie:\n\n\n");
		printf("1. Vvod zapisi\n\n");
		printf("2. Udalenie zapisi\n\n");
		printf("3. Vivod\n\n");
		printf("4. Vivod stipendii\n\n");
		printf("5. Exit\n\n (1-5):");
		scanf("%d", &a);

		switch (a)
		{
		case 1: system("cls");
			add();
			break;
		case 2: system("cls");
			delet();
			break;
		case 3: system("cls");
			sort();
			break;
		case 4: system("cls");
			many();
			break;
		case 5: system("cls");
			break;
		default: printf("\n\nERROR!!! Please enter number 1-5...\n\n");
		}
	} while (a != 5);

	file = fopen("dekanat.txt", "w");

	if (file != NULL)
	{
		for (i = 0; i<number; i++)
		{
			fprintf(file, "%i ", spisok[i].pr);
			if (spisok[i].pr != 0)
			{
				fprintf(file, "%i %i ", spisok[i].num, spisok[i].count);
				for (j = 0; j<spisok[i].count; j++)
				{
					//	fprintf(file, "%i ", spisok[i].stud[j].pr);
					//	if(spisok[i].stud[j].pr != 0)
					//	{
					fprintf(file, "%s %s ", spisok[i].stud[j].surname, spisok[i].stud[j].name);
					for (k = 0; k<5; k++)
						fprintf(file, "%i ", spisok[i].stud[j].score[k]);
					fprintf(file, "%f %i ", spisok[i].stud[j].av_score, spisok[i].stud[j].verdict);
					//	}
					//	else
					//	break;
				}
				for (k = 0; k<5; k++)
					fprintf(file, "%s ", spisok[i].disc[k].name);
				fprintf(file, "\n\n");
			}
			else
				break;
		}
	}
	fclose(file);

	file = fopen("predmet.txt", "w");
	if (file != NULL)
	{
		fprintf(file, "%i\n", count_dis);
		for (i = 0; i<dis; i++)
		{
			fprintf(file, "%s \n", &predmet[i]);
		}
	}
	fclose(file);

	return 0;
}

void add()//выбор добавления
{
	int a;
	printf("1.Gruppa\n2.Student\n3.Disciplina\nVibor: ");
	scanf("%i", &a);
	switch (a)
	{
	case 1: mod_group();
		break;
	case 2: mod_student();
		break;
	case 3: mod_disc();
		break;
	default:
		printf("Vvedite 1-3!!");
		break;
	}
}

void mod_group()//добавление в группу
{
	printf("%i\n", count_group);
	int i, n, m;
	spisok[count_group].pr = 1;
	spisok[count_group].count = 0;
	printf("Nomer gruppi: ");
	scanf("%i", &spisok[count_group].num);
	printf("Kolichestvo studentov v gruppe(2 - 25): ");
	scanf("%i", &m);
	for (i = 0; i<m; i++)
		mod_gr_student(i);
	printf("predmeti\n\n");
	for (i = 0; i<count_dis; i++)
		printf("%i.%s\n", i + 1, predmet[i].name);
	printf("Viberite 5 predmetov(vvedite nomera): ");
	for (i = 0; i<5; i++)
	{
		scanf("%i", &n);
		n--;
		strncpy(spisok[count_group].disc[i].name, predmet[n].name, 40);
	}
	count_group++;
	printf("%i\n", count_group);
}

void mod_gr_student(int i)//при вводе новой группы;
{
	int j;
	spisok[count_group].stud[i].av_score = 0;
	spisok[count_group].stud[i].verdict = 0;
	printf("Name Familia: ");
	scanf("%s%s", &spisok[count_group].stud[i].name, &spisok[count_group].stud[i].surname);
	printf("Vvedite 5 ozenok: ");
	for (j = 0; j<5; j++)
	{
		scanf("%i", &spisok[count_group].stud[i].score[j]);
		spisok[count_group].stud[i].av_score += spisok[count_group].stud[i].score[j];
		if (spisok[count_group].stud[i].score[j] < 3)
			spisok[count_group].stud[i].verdict++;
	}
	spisok[count_group].stud[i].av_score /= 5;
	spisok[count_group].count++;
	printf("\n%i\n", spisok[count_group].count);
}

void mod_student()//при вводе нового студента добавляем его в введенную группу;
{
	int j, i, num_group;
	int end;
	printf("Vse gruppi\n\n");
	for (i = 0; i<count_group; i++)
		printf("%i \n", spisok[i].num);
	printf("Nomer gruppi: ");
	scanf("%i", &num_group);
	for (i = 0; i<count_group; i++)
		if (spisok[i].num == num_group)
		{
			end = spisok[i].count;
			spisok[i].stud[end].av_score = 0;
			spisok[i].stud[end].verdict = 0;
			printf("Name Familia: ");
			scanf("%s%s", &spisok[i].stud[end].name, &spisok[i].stud[end].surname);
			printf("Vvedite 5 ozenok: ");
			for (j = 0; j<5; j++)
			{
				scanf("%i", &spisok[i].stud[end].score[j]);
				spisok[i].stud[end].av_score += spisok[i].stud[end].score[j];
				if (spisok[i].stud[end].score[j] < 3)
					spisok[i].stud[end].verdict++;
			}
			spisok[i].stud[end].av_score /= 5;
			spisok[i].count++;
			break;
		}
		//else
			//printf("Nepravilnii nomer!");
	printf("\n%i\n", spisok[count_group].count);
}

void mod_disc()//добавление предмета
{
	printf("Vvedite predmet: ");
	scanf("%s", &predmet[count_dis]);
	count_dis++;
}

void delet()//выбор удаления
{
	int a;
	printf("1.Gruppa\n2.Student\n3.Disciplina\nVibor: ");
	scanf("%i", &a);
	switch (a)
	{
	case 1: del_group();
		break;
	case 2: del_student();
		break;
	case 3: del_disc();
	default:
		printf("Vvedite 1-3!!");
		break;
	}
}

void del_group()//удаление группы
{
	int i, num_group;
	struct group r;
	printf("Vse gruppi\n\n");
	for (i = 0; i<count_group; i++)
		printf("%i \n", spisok[i].num);
	printf("Nomer gruppi: ");
	scanf("%i", &num_group);
	for (i = 0; i<count_group; i++)
		if (spisok[i].num == num_group)
		{
			r = spisok[i];
			spisok[i] = spisok[count_group];
			spisok[count_group] = spisok[i];
			break;
		}
	count_group--;
}

void del_student()//удаление студента
{
	struct student r;
	int j, i, num_group, num_stud;
	printf("Vse gruppi\n\n");
	for (i = 0; i<count_group; i++)
		printf("%i \n", spisok[i].num);
	printf("Nomer gruppi: ");
	scanf("%i", &num_group);
	for (i = 0; i<count_group; i++)
		if (spisok[i].num == num_group)
		{
			printf("Studenti gruppi %i\n", num_group);
			for (j = 0; j<spisok[i].count; j++)
			{
				printf("%i.%s %s\n", j + 1, spisok[i].stud[j].surname, spisok[i].stud[j].name);
			}
			printf("Nomer dlya udalenia: ");
			scanf("%i", &num_stud);
			num_stud--;
			if (num_stud < j)
			{
				r = spisok[i].stud[num_stud];
				spisok[i].stud[num_stud] = spisok[i].stud[spisok[i].count - 1];
				spisok[i].stud[spisok[i].count - 1] = r;
				spisok[i].count--;
			}
			else
				printf("Nepravilnii nomer!!");
			break;
		}
}

void del_disc()//удаление предмета
{
	struct discipline r;
	int i, num_dis=0;
	printf("Predmeti\n\n");
	for (i = 0; i<count_dis; i++)
		printf("%i.%s\n", i + 1, predmet[i]);
	printf("Udalit': ");
	scanf("%i", num_dis);
	if (num_dis < count_dis)
	{
		r = predmet[num_dis];
		predmet[num_dis] = predmet[count_dis - 1];
		predmet[count_dis - 1] = r;
	}
	count_dis--;
}

void sort()//выбор сортировки
{
	int a;
	printf("1.Sortirovka gruppi\n2.Sortirovka po srednemu ballu\nVibor: ");
	scanf("%i", &a);
	switch (a)
	{
	case 1: sort_group();
		break;
	case 2: sort_ball();
		break;
	default:
		printf("Vvedite 1-2!!");
		break;
	}
}

void sort_group()//сортировка по алфавиту
{
	int i, j, num_group;
	struct student r;
	printf("Vse gruppi\n\n");
	for (i = 0; i<count_group; i++)
		printf("%i. %i \n", i + 1, spisok[i].num);
	printf("poryadkovii nomer gruppi: ");
	scanf("%i. %i", &num_group);
	num_group--;
	for (i = 0; i<spisok[num_group].count - 1; i++)
		for (j = i + 1; j<spisok[num_group].count; j++)
			if (strcmp(spisok[num_group].stud[i].surname, spisok[num_group].stud[j].surname) > 0)
			{
				r = spisok[num_group].stud[i];
				spisok[num_group].stud[i] = spisok[num_group].stud[j];
				spisok[num_group].stud[j] = r;
			}

	for (j = 0; j<spisok[num_group].count; j++)
		printf("%s %s\n", spisok[num_group].stud[j].surname, spisok[num_group].stud[j].name);
}

void sort_ball()//сортровка по среднему баллу
{
	int i, j, num_group;
	struct student r;
	printf("Vse gruppi\n\n");
	for (i = 0; i<count_group; i++)
		printf("%i. %i \n", i + 1, spisok[i].num);
	printf("poryadkovii nomer gruppi: ");
	scanf("%i", &num_group);
	num_group--;
	for (i = 0; i<spisok[num_group].count - 1; i++)
		for (j = i + 1; j<spisok[num_group].count; j++)
			if (spisok[num_group].stud[i].av_score < spisok[num_group].stud[j].av_score)
			{
				r = spisok[num_group].stud[i];
				spisok[num_group].stud[i] = spisok[num_group].stud[j];
				spisok[num_group].stud[j] = r;
			}

	for (j = 0; j<spisok[num_group].count; j++)
		printf("%s %s %.2f\n", spisok[num_group].stud[j].surname, spisok[num_group].stud[j].name, spisok[num_group].stud[j].av_score);
}

void many()//стипендия 
{
	int num_group, i, j;
	printf("Vse gruppi\n\n");
	for (i = 0; i<count_group; i++)
		printf("%i. %i \n", i + 1, spisok[i].num);
	printf("poryadkovii nomer gruppi: ");
	scanf("%i", &num_group);
	num_group--;
	for (i = 0; i<spisok[num_group].count; i++)
	{
		if (spisok[num_group].stud[i].verdict == 0)
			printf("%s %s - stipendia\n", spisok[num_group].stud[i].surname, spisok[num_group].stud[i].name);
		else if (spisok[num_group].stud[i].verdict == 1 || spisok[num_group].stud[i].verdict == 2)
		{
			printf("%s %s - dopsa\n", spisok[num_group].stud[i].surname, spisok[num_group].stud[i].name);
			for (j = 0; j<5; j++)
				if (spisok[num_group].stud[i].score[i] < 3)
					printf("persdat' %s\n", spisok[num_group].disc[i].name);
		}
		else if (spisok[num_group].stud[i].verdict > 2)
			printf("%s %s - otchislen\n", spisok[num_group].stud[i].surname, spisok[num_group].stud[i].name);
	}
}
