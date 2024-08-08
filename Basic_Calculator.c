#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void calInterface();
void inverseSub();
void divisSub();
double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double intDivis(double x, double y);
double normDivis(double x, double y);
double power(double x, double y);
double GCD(double x, double y);
double LCM(double x, double y);
double degCon(double x);
double degRev(double x);
double sine(double x);
double cosine(double x);
double tangent(double x);
double asine(double x);
double acosine(double x);
double atangent(double x);
double remainderx(double x, double y);
double oddEven(double x);
double percentagex(double x, double y);
void history(int ops[], double op1[], double op2[], double res[],int sub[], int count);

int main()
{
	int operation, subOp, count = 1, previous = -1;
	double opr1, opr2, temp;

	int ops[100], subx[100];
	double opr1s[100], opr2s[100], results[100];
	
	while(1)
	{
		operation = 0;
		subOp = 0;
		
		if(count != previous)
		{
			calInterface();
		}

		printf("Enter an operation : ");
		scanf("%d", &operation);

		if(operation < 1 || operation > 16)
		{
			printf("Invalid input! Please enter a number between 1 and 16.\n\n");
			continue;
		}

		printf("\n");

		ops[count] = operation;

		if(operation < 15)
		{
			printf("Enter Value 1 : ");
			scanf("%lf", &opr1);
		}

		opr1s[count] = opr1;

		if(operation >= 1 && operation < 8 || operation == 12 || operation == 14)
		{
			printf("Enter Value 2 : ");
			scanf("%lf", &opr2);

			opr2s[count] = opr2;
		}

		switch(operation)
		{
			case 1:
				temp = add(opr1, opr2);
				results[count] = temp;
				printf("\n%g + %g = %g\n\n", opr1, opr2, temp);
				break;

			case 2:
				temp = sub(opr1, opr2);
				results[count] = temp;
				printf("\n%g - %g = %g\n\n", opr1, opr2, temp);
				break;

			case 3:
				temp = mul(opr1, opr2);
				results[count] = temp;
				printf("\n%g * %g = %g\n\n", opr1, opr2, temp);
				break;
			
			case 4:
				divisSub();
				printf("Enter a sub-operation : ");
				scanf("%d", &subOp);
				subx[count] = subOp;

				switch(subOp)
				{
					case 1:
						temp = intDivis(opr1, opr2);
						results[count] = temp;
						printf("\n%g / %g = %g\n\n", opr1, opr2, temp);
						break;

					case 2:
						temp = normDivis(opr1, opr2);
						results[count] = temp;
						printf("\n%g / %g = %g\n\n", opr1, opr2, temp);
						break;
				}
				break;

			case 5:
				temp = power(opr1, opr2);
				results[count] = temp;
				printf("\n%g ^ %g = %g\n\n", opr1, opr2, temp);
				break;
			
			case 6:
				temp = LCM(opr1, opr2);
				results[count] = temp;
				printf("\nLCM of %g and %g is %g\n\n", opr1, opr2, temp);
				break;

			case 7:
				temp = GCD(opr1, opr2);
				results[count] = temp;
				printf("\nGCD of %g and %g is %g\n\n", opr1, opr2, temp);
				break;

			case 8:
				temp = sine(opr1);
				results[count] = temp;
				printf("\nSine value of %g degrees : %g\n\n", opr1, temp);
				break;
			
			case 9:
				temp = cosine(opr1);
				results[count] = temp;
				printf("\nCosine value of %g degrees : %g\n\n", opr1, temp);
				break;

			case 10:
				temp = tangent(opr1);
				results[count] = temp;
				printf("\nTangent value of %g degrees : %g\n\n", opr1, temp);
				break;

			case 11:
				inverseSub();
				printf("Enter a sub-operation : ");
				scanf("%d", &subOp);
				subx[count] = subOp;
				
				switch(subOp)
				{
					case 1:
						temp = degRev(asine(opr1));
						results[count] = temp;
						printf("\nArc sine value of %g : %g degrees\n\n", opr1, temp);
						break;

					case 2:
						temp = degRev(acosine(opr1));
						results[count] = temp;
						printf("\nArc cosine value of %g : %g degrees\n\n", opr1, temp);
						break;

					case 3:
						temp = degRev(atangent(opr1));
						results[count] = temp;
						printf("\nArc tangent value of %g : %g degrees\n\n", opr1, temp);
						break;
				}
				break;

			case 12:
				temp = remainderx(opr1, opr2);
				results[count] = temp;
				printf("\nRemainder of %g / %g = %g\n\n", opr1, opr2, temp);
				break;

			case 13:
				temp = oddEven(opr1);
				results[count] = temp;
				printf("\n%g is %s\n\n", opr1, temp == 0 ? "Even" : "Odd");
				break;

			case 14:
				temp = percentagex(opr1, opr2);
				results[count] = temp;
				printf("\nPercentage of %g / %g = %g%%\n\n", opr1, opr2, temp);
				break;

			case 16:
				history(ops, opr1s, opr2s, results, subx, count);
				break;
		}

		if(operation == 15)
		{
			break;
		}

		count++;

		printf("Press Enter to continue!\n");

		getchar();
		getchar();

		system("cls");
	}

	return 0;
}

void calInterface()
{
	printf("##########################################\n");
	printf("##   SCS 1301 - Scientific Calculator   ##\n");
	printf("##                  by                  ##\n");
	printf("##          Vimukthi Kaushalya          ##\n");
	printf("##########################################\n");
	printf("##########################################\n");
	printf("#   1.  Addition       8.  Sine          #\n");
	printf("#   2.  Substraction   9.  Cosine        #\n");
	printf("#   3.  Multiplication 10. Tangent       #\n");
	printf("#   4.  Devision       11. Inverse       #\n");
	printf("#   5.  Power          12. Remainder     #\n");
	printf("#   6.  LCM            13. Odd or Even   #\n");
	printf("#   7.  GCD            14. Percentage    #\n");
	printf("#                                        #\n");
	printf("#   15. Exit           16. History       #\n");
	printf("##########################################\n");
	printf("##########################################\n\n");
}

void inverseSub()
{
	printf("\n##########################\n");
	printf("##########################\n");
	printf("##  1. Sine Inverse     ##\n");
	printf("##  2. Cosine Inverse   ##\n");
	printf("##  3. Tangent Inverse  ##\n");
	printf("##########################\n");
	printf("##########################\n\n");
}

void divisSub()
{
	printf("\n##########################\n");
	printf("##########################\n");
	printf("##  1. Integer Division ##\n");
	printf("##  2. Normal Division  ##\n");
	printf("##########################\n");
	printf("##########################\n\n");
}

double add(double x, double y)
{
	return x + y;
}

double sub(double x, double y)
{
	return x - y;
}

double mul(double x, double y)
{
	return x * y;
}

double intDivis(double x, double y)
{
	return (int)x / (int)y;
}

double normDivis(double x, double y)
{
	return x / y;
}

double power(double x, double y)
{
	int term = abs((int)y);
	double result = 1;

	if(y >= 0)
	{
		for(int i = 1; i <= term; i++)
		{
			result *= x;
		}
	}
	else
	{
		for(int i = 1; i <= term; i++)
		{
			result /= x;
		}
	}

	return result;
}

double GCD(double x, double y)
{
	double result;

	for(int i = 1; i <= (x > y ? x : y); i++)
	{
		if((int)x % i == 0 && (int)y % i == 0)
		{
			result = i;
		}
	}

	return result;
}

double LCM(double x, double y)
{
	return (x * y) / GCD(x, y);
}

double degCon(double x)
{
	return x / 180 * M_PI;
}

double degRev(double x)
{
	return x / M_PI * 180;
}

double sine(double x)
{
	return sin(degCon(x));
}

double cosine(double x)
{
	return cos(degCon(x));
}

double tangent(double x)
{
	return tan(degCon(x));
}

double asine(double x)
{
	return asin(x);
}

double acosine(double x)
{
	return acos(x);
}

double atangent(double x)
{
	return atan(x);
}

double remainderx(double x, double y)
{
	return (int)x % (int)y;
}

double oddEven(double x)
{
	return (int)x % 2;
}

double percentagex(double x, double y)
{
	return x / y * 100;
}

void history(int ops[], double op1[], double op2[], double res[], int sub[], int count)
{
	char opsNames[15][20] = {" ", "Addition", "Subtraction", "Multiplication", "Division", "Power", "LCM", "GCD", "Sine", "Cosine", "Tangent", "Inverse", "Remaninder", "Odd or Even", "Persentage"};

	char subOpsNames[4][20] = {" ", "Sine", "Cosine", "Tangent"};

	char subOpsNames1[3][20] = {" ", "Integer", "Normal"};

	printf("History\n\n");
	
	printf("#  ->  Operation\t->  Sub Op.\t->  Value 1\t->  Value 2\t->  Result\n\n");

	for(int i = 1; i <= count - 1; i++)
	{
		if(ops[i] == 4)
		{
			printf("%d. ->  %-10s\t-> %-10s\t->  %-10g\t->  \t\t->  %g\n\n", i, opsNames[ops[i]], subOpsNames1[sub[i]], op1[i], res[i]);
		}
		else if(ops[i] == 11)
		{
			printf("%d. ->  %-10s\t-> %-10s\t->  %-10g\t->  \t\t->  %g\n\n", i, opsNames[ops[i]], subOpsNames[sub[i]], op1[i], res[i]);
		}
		else
		{
			printf("%d. ->  %-10s\t-> \t\t->  %-10g\t->  %-10g\t->  %g\n\n", i, opsNames[ops[i]],  op1[i], op2[i], res[i]);
		}
	}
}
