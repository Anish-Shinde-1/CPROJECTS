#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define PI 3.14159265358979323846

int options(int opt);
double arithmetic(double result, double a);
double exponent(double x, double result, double expo, double base, int opt2);

int main()
{
	int opt, opt2;
	double a, x, result, base, expo;

	opt=options(opt);

	// printf("%d",opt);

	switch(opt)
	{
	case 1 : 
		result = arithmetic(a, result);
		printf("END RESULT : %lf\n", result);
		break;

	case 2 : 
		result = exponent(x, result, base, expo, opt2); 
	}

return 0;
}

int options(int opt)
{
	system("clear");
	printf("|=========== CALCULATOR ==========|\n");
	printf("|                                 |\n");
	printf("| 1. Arithmetic                   |\n");
	printf("| 2. Exponent                     |\n");
	printf("| 3. Factorial                    |\n");
	printf("| 4. Trigonometric                |\n");
	printf("| 5. Unit Converter               |\n");
	printf("| 6. Matrix                       |\n");
	printf("| 7. Equations                    |\n");
	printf("|                                 |\n");

	printf("Which operation do you want to execute?\nAns : ");
	scanf("%d", &opt);

	return opt;
}

double arithmetic(double result, double a)
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

double exponent(double x, double result, double expo, double base, int opt2)
{

	system("clear");
	printf("|=========== CALCULATOR ==========|\n");
	printf("|                                 |\n");
	printf("| 1. Power                        |\n");
	printf("| 2. Exponential                  |\n");
	printf("| 3. Logarithmic                  |\n");
	printf("|                                 |\n");

	do
	{
		printf("\nEnter your choice : ");
		scanf("%d", &opt2);

		if(opt2<1 || opt2>3)
		{
			printf("INVALID OPTION\n");

		}

	} while(opt2<1 || opt2>3);

	if(opt2==1)
	{
		printf("Enter the base : ");
		scanf("%lf", &base);

		printf("Enter the exponent : ");
		scanf("%lf", & expo);

		result = pow(base,expo);

		printf("END RESULT : %lf\n", result);
	}
	else if(opt2==2)
	{
		printf("Enter the value : ");
		scanf("%lf", &x);

		result = exp(x);

		printf("END RESULT : %lf\n", result);
	}
	else if(opt2==3)
	{
		printf("Enter the value : ");
		scanf("%lf", &x);

		result = log(x);

		printf("END RESULT : %lf\n", result);
	}
	return result;
}