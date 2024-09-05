

	#include "gfx.h"
	#include <stdio.h>	/* printf */
	#include <unistd.h> /* sleep  */

	void ERRO()
	{
		printf("ERRO VALOR INVALIDO ESCOLHA QUADRADO OU CIRCULO DE ATE 10 DE RECURSAO\n");
	}

	void elipise(int const valor_recursao)
	{
		gfx_init(600, 600, "elipise"); // inicia janela grafica

	
			gfx_ellipse(300, 300, 250, 250);
		

		gfx_quit();

		sleep(30);
	}

	// void quadrado(int valor_recursao){}

	void menu()
	{
		printf("TRABALHO 1:\n");
		int forma = 0;
		int quant_recur = 0;
		printf("MENU DO USUARIO:\n");

		do
		{

			printf("Qual forma deseja : (1-circulo // 2-quadrado)\n");
			scanf("%d", &forma);
			printf("Qual a quantidade de recursao?\n");
			scanf("%d", &quant_recur);

			if ((forma =!2) || (forma != 1) || (quant_recur > 10))
			{
				system("clear");
				ERRO();
				system("pause");
				system("clear");
			}
		} while (forma == 1 || forma == 2);

		if (forma == 1) // escolha circulo
		{
			elipise(quant_recur);
		}
		else if (forma == 2) // quadrado
		{
			printf("NUM\n");
		}
	}
	int main()
	{
		menu();
		return 0;
	}