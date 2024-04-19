#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	int a;
	int i;
	int ans;
	char block ='#';
	char blank ='-';

	system("clear");


	printf("\n========= Loading bar animation =========\n");

	printf("\nDo you want to start the animation?\n(Press 1 for yes and 0 for no)\n");
	scanf("%d",&ans);

	system("clear");


	if(ans==1)
	{
		for(i=1;i<=10;i++)
		{
			switch (i)
			{
				case 1 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 10%%\n", block, blank, blank, blank, blank, blank, blank, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n"); 
					break;

				case 2 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 20%%\n", block, block, blank, blank, blank, blank, blank, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break;

				case 3 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 30%%\n", block, block, block, blank, blank, blank, blank, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break; 

				case 4 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 40%%\n", block, block, block, block, blank, blank, blank, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break;

				case 5 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 50%%\n", block, block, block, block, block, blank, blank, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break;

				case 6 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 60%%\n", block, block, block, block, block, block, blank, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break;

				case 7 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 70%%\n", block, block, block, block, block, block, block, blank, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break;

				case 8 :  printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 80%%\n", block, block, block, block, block, block, block, block, blank, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n");
					break;

				case 9 : printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 90%%\n", block, block, block, block, block, block, block, block, block, blank);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n"); 
					break;

				case 10 : printf("\n========= Loading bar animation =========\n");
						printf("\nProgress => [ %c %c %c %c %c %c %c %c %c %c ] 100%%\n", block, block, block, block, block, block, block, block, block, block);
						(i==10)? printf("\nLOAD COMPLETE\n") : printf("\nLOADING\n"); 
					break;

				default : printf("\n========= LOAD COMPLETE =========\n");

			}
			sleep(1);
			system("clear");
		}
	}
	else
	{
		printf("\nPROGRAM TERMINATED\n");
	}

}