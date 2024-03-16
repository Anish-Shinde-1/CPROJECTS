#include<stdio.h>

int options(int opt);
double arithmetic(double result, double a, double sum, double sub, double prod, double div);

int main()
{
	int opt;
	double a, result, input, sum, sub, prod, div;

	opt=options(opt);

	// printf("%d",opt);

	switch(opt)
	{
	case 1 : 
		result = arithmetic(a, result, sum, sub, prod, div);
		printf("END RESULT : %lf\n", result);
		break;
	}

return 0;
}

int options(int opt)
{
	printf("|=========== CALCULATOR ==========|\n");
	printf("|                                 |\n");
	printf("| 1. Arithmetic                   |\n");
	printf("| 2. Exponential                  |\n");
	printf("| 3. Factorial                    |\n");
	printf("| 4. Trigonometric                |\n");
	printf("| 5. Unit Converter               |\n");
	printf("|                                 |\n");

	printf("Which operation do you want to execute?\nAns : ");
	scanf("%d", &opt);

	return opt;
}

double arithmetic(double result, double a, double sum, double sub, double prod, double div)
{
	char operator = 'n';

	printf("\n");
	
	for(int i = 1; operator != 'q'; i++) 
	{
		if (i==1)
		{
			printf("Input : ");
			scanf("%lf",&a);
			result = a;
			continue;
		}

		getchar();

		printf("Operator : ");
		scanf("%c",&operator);

		if(operator == 'q') 
		{ 
			break; 
		}
		else if(operator!='+' && operator!='-' && operator!='*' && operator!='/')
		{
			 printf("INVALID INPUT\n");
			 i--;
			 continue;
		}
		
		getchar(); // consumes the whitespace character in input buffer, when scanning a character after scanning any other input, the whitespace character in the input buffer is scanned and compiler skips ahead //

		printf("Input : ");
		scanf("%lf",&a);

		switch(operator)
		{
		
			case '+' : 
				result = result + a; 
				break;

			case '-' :
				result = result - a; 
				break;

			case '*' : 
				result = result * a; 
				break;

			case '/' : 
				if(a==0) {
					printf("INVALID INPUT!!\n");
					i--;
				}
				else { 
					result = result / a; 
				}
				break;

			case 'p' : 
				break;
		}
	
	}

	printf("\n");
	
	return result;
}