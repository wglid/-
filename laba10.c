#include<stdio.h> 
#include<conio.h> 
#include <malloc.h> 
#include <string.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAXLINE 1024 
void main() 
{ 
	FILE *fpin; 
	char line[MAXLINE]; 
	char *ptr, **a, x, *str, n; 
	int q = 1, w = 0, max = 0, j, i, m = 0, k = 0, f = 0; 
	fpin = fopen("id.txt", "rt"); 
	if (fpin == NULL) 
	return; 
	while (!feof(fpin)) 
	{ 
		ptr = fgets(line, MAXLINE, fpin); 
		if (ptr == NULL) 
		break; 
		while (*ptr != 'М') 
		{ 
			while (((*ptr != ' ') && (*ptr != '.') && (*ptr != ',') && (*ptr != '\t') && (*ptr != '\n') && (*ptr != 'М'))) 
			{ 
				ptr++; 
				q++; 

			} 
			if (max < q) max = q; 
			q = 0; 
			w++; 
			if ((*ptr == '\n')) 
			{ 
				ptr = fgets(line, MAXLINE, fpin); 
				if (ptr == NULL) 
				break; 
			} 
				while (((*ptr == ' ') || (*ptr == '.') || (*ptr == ',') || (*ptr == '\t'))) 
				{ 
					ptr++; 
				} 

		} 

	} 
	fclose(fpin); 
	fpin = fopen("id.txt", "rt"); 
	a = (char**)malloc(w * sizeof(char*)); 
	for (i = 0; i < w; i++) 
	{ 
		a[i] = (char*)malloc(max * sizeof(char)); 
	} 
	ptr = fgets(line, MAXLINE, fpin); 
	i = 0; 
	while (*ptr != 'М') //До конца файла 
	{ 
		if ((*ptr == '\n')) 
		{ 
			ptr = fgets(line, MAXLINE, fpin); 
			if (ptr == NULL) 
			break; 
		} 
		for (j = 0; j < max; j++) // цикл по столбцам 
		{ 
			if (*ptr == '\n') 
			{ 
				break; 
			} 
			if (*ptr == ' ' || *ptr == '.' || *ptr == ',') 
			{ 
				i++; 
				ptr++; 
				break; 
			} 
			a[i][j] = *ptr; 
			ptr++; 
		} 
	} 
	j = 0; 
	for (i = 0; i < w; i++) // цикл по строкам 
	{ 
		if ((a[i][j] - 91) < 0) 
		{ 
			a[i][j] += 32; 
		} 
	} 
	str = (char*)malloc(max * sizeof(char)); 
	for (i = 1; i < w; i++) 
	{ 
		for (j = 0; j < w - i; j++) 
		if (strcmp(a[j], a[j + 1]) > 0)		
		{ 
			strcpy(str, a[j]); 
			strcpy(a[j], a[j + 1]); 
			strcpy(a[j + 1], str); 
		} 
	} 
	for (i = 0; i < w; i++) // цикл по строкам 
	{ 
		for (j = 0; j < max; j++) // цикл по столбцам 
		{ 
			printf("%c ", a[i][j]); 
		} 
		printf("\n"); 
	} 
	for (i=0; i < w; i++) 
	{
	//for (j=0;j < max; j++) {

		free(a[i]);
	//}
	}
	fclose(fpin);
	free(a);
//for (j = 0; j < max; j++) {

	free(str);
//}

getchar(); getchar();
}
