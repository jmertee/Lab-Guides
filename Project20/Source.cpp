#include <stdio.h>
#define MAX 11

void findLowest(int num[], int *position, int size)
{

	int mins = num[0], u;
	*position = 0;
	for (u = 1; u < size; u++)
	{
		if (num[u] < mins)
		{
			mins = num[u];
			*position = u;
		}
		
	}
	
}

void findHighest(int num[], int *position, int size)
{

	int maxs = num[0], p;
	*position = 0;
	for (p = 1; p < size; p++)
	{
		if (num[p] > maxs)
		{
			maxs = num[p];
			*position = p;
		}
		
		}

}

void takeoneFromAll(int group[], int max, int size, int *final1)
{
	int y, cnt=0;

	for (y = 0; y < size; y++)
	{
		if (group[y] > 0)
		{
			group[y] = group[y] - 1;
			cnt++;
		}
	}

	*final1 = group[max] + cnt;

}

void takeOneFromOne(int group2[], int group3[], int min, int max, int *final2, int *final3)
	 {


	*final2 = group2[min] + 1;
	*final3 = group3[max] - 1;
	  
	}

int main (void)
{

	int id[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int ada1[MAX], ada2[MAX], ada3[MAX], status, i=0, j, lowpos, final1, final2, final3, highpos, highpos3;


	FILE *inp1;
	FILE *inp2;
	FILE *inp3;
	FILE *out;

	inp1 = fopen("island1.txt", "r");
	inp2 = fopen("island2.txt", "r");
	inp3 = fopen("island3.txt", "r");
	out = fopen("output.txt", "w");

	if ((inp1 == NULL) || (inp2 == NULL) || (inp3 == NULL))
		printf("Error!");

	else
	{

		status = fscanf(inp1, "%d", &ada1[i]);
		status = fscanf(inp2, "%d", &ada2[i]);
		status = fscanf(inp3, "%d", &ada3[i]);

		while (status != EOF)
		{
			i++;
				
			status = fscanf(inp1, "%d", &ada1[i]);
			status = fscanf(inp2, "%d", &ada2[i]);
			status = fscanf(inp3, "%d", &ada3[i]);
					   
		}
			
		findLowest(ada2, &lowpos, i);
		findHighest(ada1, &highpos, i);
		findHighest(ada3, &highpos3, i);
		takeoneFromAll(ada1, highpos, i, &final1);
		takeOneFromOne(ada2, ada3, lowpos, highpos3, &final2, &final3);
				

		ada1[highpos] = final1;
		ada2[lowpos] = final2;
		ada3[highpos3] = final3;


		printf("Arrays after operations:\n");
		printf("ID\tIsland-1\tIsland-2\tIsland-3\n");
		for (j = 0; j < i; j++)
		{
			printf("%d\t    %d\t      \t   %d\t  \t   %d\n", id[j]+1, ada1[j], ada2[j], ada3[j]);

		}
		
		fprintf(out, "Arrays after operations:\n");
		fprintf(out, "ID\tIsland-1\tIsland-2\tIsland-3\n");
		for (j = 0; j < i; j++)
		{
			fprintf(out, "%d\t    %d\t      \t   %d\t  \t   %d\n", id[j]+1, ada1[j], ada2[j], ada3[j]);
		}
	
	} //else

	fclose(inp1);
	fclose(inp2);
	fclose(inp3);
	fclose(out);



	return 0;

}