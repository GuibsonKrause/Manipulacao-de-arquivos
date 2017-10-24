#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aviao
{
	int serie;
	int anoElab;
	int anoFabri;
	char modelo[15];
	char fabricante[20];

}Aviao;

typedef struct Fabricante
{
	char nome[20];
	char nacionalidade[20];
}Fabricante;

int lerFabricantes( Fabricante *listaFabricante)
{
	int i = 0;
	FILE *arqF = fopen("fabricantes.txt", "r"); // Abre o arquivo.
	if (!arqF) // Se n�o encontrar o arquivo, ira imprimir uma mensagem de erro.
	{
		printf("Erro na abertura do arquivo!");
	}
	else
	{

		while (!feof(arqF)) // feof (file end of file) enquanto n�o for o final do arquivo.
		{
			fscanf(arqF, "%s %s", listaFabricante[i].nome, listaFabricante[i].nacionalidade); // faz a leitura do arquivo.
			i++;
		}
	}
	fclose(arqF); // Fecha o arquivo.
	return i; // 'I' que sair� com a quantidade de fabricantes.
}

int lerAviao(Aviao *listaAviao)
{
	int i = 0;
	FILE *arqA = fopen("avioes.txt", "r"); // Abre o arquivo.
	if (!arqA) // Se n�o encontrar o arquivo, ira imprimir uma mensagem de erro.
	{
		printf("Erro na abertura do arquivo!");
	}
	else
	{
		while (!feof(arqA)) // feof (file end of file) enquanto n�o for o final do arquivo.
		{
			fscanf(arqA, "%d", &listaAviao[i].serie); // faz a leitura do arquivo.
			fscanf(arqA, "%i", &listaAviao[i].anoElab);
			fscanf(arqA, "%i", &listaAviao[i].anoFabri);
			fscanf(arqA, "%s", listaAviao[i].modelo);
			fscanf(arqA, "%s", listaAviao[i].fabricante);
			i++;
		}
	}
	fclose(arqA); // Fecha o arquivo.

	return i; // 'I' que sair� com a quantidade de avi�es.
}

int contAvioesFabricante(int qtdAviao, char *nomeFabricante, Aviao *listaAvioes) // Essa fun��o tem como fim contar quantos avi�es tem cada fabricante
{
	 int a = 0, contaAvioes = 0;
	//Fazer um loop que percorre a lista de avioes e verifica se o nome do fabricante armazenado no aviao � o mesmo nome do fabricante do primeiro loop
	while (a < qtdAviao)
	{
		
		if (strcmp(nomeFabricante, listaAvioes[a].fabricante) == 0) // Compara se a vari�vel 'nomeFabricante' � igual a vari�vel 'listaAvioes[a].fabricante.
		// A quantidade de vezes que essa fabricante 'nomeFabricante' for encontrada na minha lista quer dizer a quantidade de avi�es que eu tenho na lista � daquela mesma fabricante.
		{
			contaAvioes++; // Quantidade de avi�es.
		}
		a++;
	}
	return contaAvioes;
}

void listaAvioesFabricante(int qtdAviao, char *nomeFabricante, Aviao *listaAvioes)
{
	 int a = 0;
	//Fazer um loop que percorre a lista de avioes e verifica se o nome do fabricante armazenado no aviao � o mesmo nome do fabricante do primeiro loop
	while (a < qtdAviao)
	{
		if (strcmp(nomeFabricante, listaAvioes[a].fabricante) == 0) // Compara se a vari�vel 'nomeFabricante' � igual a vari�vel 'listaAvioes[a].fabricante.
		{
			printf("%d %d %d %s\n", listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo); // Imprime todos os dados do avi�o do fabricante que saiu do 'if' acima.
		}
		a++;
	}
}

void imprimeAvioesDosFabricantes(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int qtd, f = 0;
	
	
	while (f < qtdFabricante) //Fazer um loop que percorre a lista de fabricantes.
	{	
		qtd = contAvioesFabricante(qtdAviao, listaFabricante[f].nome, listaAvioes); // 'qtd' recebe a quantidade de avi�es do fabricante 'f'.
		
		if (qtd == 0) // Se 'qtd' for igual a zero � porque n�o existe avi�es desse fabricante.
		{
			printf("%s: Nao existem avioes desse fabricante.", listaFabricante[f].nome);
		}
		else if (qtd == 1) // Se 'qtd' for igual a um � porque tem s� um avi�o desse fabricante.
		{
			printf("%s: %d aviao:\n", listaFabricante[f].nome, qtd); // imprime o nome do fabricante no singular.
			
			
			listaAvioesFabricante(qtdAviao, listaFabricante[f].nome, listaAvioes); //chamar a fun��o que imprime a lista de avioes do fabricante
		}
		else
		{
			printf("%s: %d avioes:\n", listaFabricante[f].nome, qtd); // Se for mais que 1 ent�o vai imprimir no plural.
			
			
			listaAvioesFabricante(qtdAviao, listaFabricante[f].nome, listaAvioes); //chamar a fun��o que imprime a lista de avioes do fabricante
		}
		f++; // Anda na lista 'listaFabricante' na fun��o 'contAvioesFabricante'.
	}
}

void avioesItalianos(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int a = 0, f = 0, contaItaliano = 0;
	
	printf("Avioes italianos com ano de elaboracao igual ao ano de fabricacao:\n");
	
	while(a < qtdAviao) //Percorrer a lista de avio�es
	{
		f = 0;
	
		while(f < qtdFabricante) //Percorrer a lista de fabricante 
		{
			if(strcmp(listaAvioes[a].fabricante, listaFabricante[f].nome) == 0)	//Verificar se o nome do fabricante do avi�o � o mesmo nome do fabricante encontrado
			{
				if(strcmp("Italiana", listaFabricante[f].nacionalidade) == 0) //Verificar se a nacionalidade deste fabricante � Italiana
				{
					if(listaAvioes[a].anoElab == listaAvioes[a].anoFabri) //Verificar se o ano de elabora��o � igual ao ano de fabrica��o
					{
						printf("%d %d %d %s\n", listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo); // Imprime as informa��es do avi�o com fabricante italiano com o ano de elebora��o igual ao ano de fabrica��o.		
						contaItaliano ++; // Conta os avi�es Italianos com ano de elebora��o igual ao ano de fabrica��o.
						break; // Para o segundo 'while' pois j� encontrou o fabricante italiano.
					}
				}
			}
			f++; // Contador do segundo 'while'.
		}
		a++; // contador do primeiro 'while'
	}
	if(contaItaliano == 0) // Verifica se n�o tem avi�es italinos com o ano de elebora��o igual ao ano de fabrica��o.
	{
		printf("Nao existem avioes italianos com ano de elaboracao igual ao ano de fabricacao.\n");
	}
}

void avioesEuropeus(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int a = 0, f = 0, contaEuropeu = 0;
	
	printf("Avioes europeus com numero de serie inferior a 1000:\n");

	while(a < qtdAviao)	//Percorrer a lista de avio�es
	{
		f = 0;
		
		while(f < qtdFabricante) //Percorrer a lista de fabricante
		{
			
			if(strcmp(listaAvioes[a].fabricante, listaFabricante[f].nome) == 0) //Verificar se o nome do fabricante do avi�o � o mesmo nome do fabricante encontrado
			{
				
				if(strcmp("Europeu", listaFabricante[f].nacionalidade) == 0) //Verificar se a nacionalidade deste fabricante � Europeu
				{
					
					if(listaAvioes[a].serie < 1000) //Verificar se o aviao europeu tem o numero de serie inferior a 1000
					{
						printf("%d %d %d %s\n", listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo); // Imprime as informa��es do avi�o com fabricante europeu com o n�mero de s�rie inferior a 1000				
						contaEuropeu ++;
						break; // Para o segundo 'while' pois j� encontrou o fabricante italiano.
					}
				}
			}
			f++; // Contador do segundo 'while'.
		}
		a++; // contador do primeiro 'while'
	}
	if(contaEuropeu == 0) // Verifica se tem avi�es europeus com o n�mero de s�rio inferior a 1000.
	{
		printf("Nao existem avioes europeus com numero de serie inferior a 1000.\n");
	}
}

void avioesAeU(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int a = 0, f = 0, g = 0, contaFabricante = 0;

	while(f < qtdFabricante) // Percorre a lista de fabricante
	{

		while(a < qtdAviao) // Percorre a lista de avi�es para encontrar os avioes do fabricante do primeiro while
		{
			
			if(strcmp(listaFabricante[f].nome, listaAvioes[a].fabricante) == 0) //Se achar o avi�o do fabricante
			{
				
				int tam = 0;
				int letraA = 0, letraU = 0;
				while(tam < strlen(listaAvioes[a].modelo)) //Como achou o avi�o do fabricante, entao percorre o nome do modelo para saber se tem a letra 'a' e 'u'
				{
				
					if(listaAvioes[a].modelo[tam] == 'a') //Verifica cada letra para saber se � a letras 'a'.
					{
						letraA = 1; // Se encontrar a letra 'a' encrementa 1 em 'letraA'
					}
					if(listaAvioes[a].modelo[tam] == 'u') //Verifica cada letra para saber se � a letras 'u'.
					{
						letraU = 1; // Se encontrar a letra 'u' encrementa 1 em 'letraU'
					}
					tam++;
				}
				
			
				if(letraA == 1 && letraU == 1)	//Se achar as duas letras na mesma string do nome do Modelo do avi�o, ent�o imprime os dados do avi�o
				{
					printf("%s: %d %d %d %s\n", listaFabricante[f].nome ,listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo);
					contaFabricante++;
				}
			}
			a++; // Contador do segundo 'while'.
		}
		f++; // contador do primeiro 'while'
	}
	
	if(contaFabricante == 0) // Se n�o encontrar as letras 'a' e 'u' no modelo do avi�o
	{
		printf("Nao existem fabricantes que tenham avioes que possuam a letra �a� e a letra �u� no nome do seu modelo.");
	}
}

int main()
{
	Fabricante listaFabricante[10];
	Aviao listaAvioes[20];

	int qtdFabricante = lerFabricantes(listaFabricante);
	int qtdAviao = lerAviao(listaAvioes);
	int f = 0;

	printf("\n================ Questao 1 ================\n");
	imprimeAvioesDosFabricantes(qtdAviao, qtdFabricante,listaFabricante, listaAvioes);
	
	
	printf("\n\n================ Questao 2 ================\n");
	avioesItalianos(qtdAviao, qtdFabricante,listaFabricante, listaAvioes);
	
	printf("\n\n================ Questao 3 ================\n");
	avioesEuropeus(qtdAviao, qtdFabricante,listaFabricante, listaAvioes);
	
	printf("\n\n================ Questao 4 ================\n");
	avioesAeU(qtdAviao, qtdFabricante,listaFabricante, listaAvioes);

	getchar();
    return 0;
}


