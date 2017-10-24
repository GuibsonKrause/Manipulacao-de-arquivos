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
	if (!arqF) // Se não encontrar o arquivo, ira imprimir uma mensagem de erro.
	{
		printf("Erro na abertura do arquivo!");
	}
	else
	{

		while (!feof(arqF)) // feof (file end of file) enquanto não for o final do arquivo.
		{
			fscanf(arqF, "%s %s", listaFabricante[i].nome, listaFabricante[i].nacionalidade); // faz a leitura do arquivo.
			i++;
		}
	}
	fclose(arqF); // Fecha o arquivo.
	return i; // 'I' que sairá com a quantidade de fabricantes.
}

int lerAviao(Aviao *listaAviao)
{
	int i = 0;
	FILE *arqA = fopen("avioes.txt", "r"); // Abre o arquivo.
	if (!arqA) // Se não encontrar o arquivo, ira imprimir uma mensagem de erro.
	{
		printf("Erro na abertura do arquivo!");
	}
	else
	{
		while (!feof(arqA)) // feof (file end of file) enquanto não for o final do arquivo.
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

	return i; // 'I' que sairá com a quantidade de aviões.
}

int contAvioesFabricante(int qtdAviao, char *nomeFabricante, Aviao *listaAvioes) // Essa função tem como fim contar quantos aviões tem cada fabricante
{
	 int a = 0, contaAvioes = 0;
	//Fazer um loop que percorre a lista de avioes e verifica se o nome do fabricante armazenado no aviao é o mesmo nome do fabricante do primeiro loop
	while (a < qtdAviao)
	{
		
		if (strcmp(nomeFabricante, listaAvioes[a].fabricante) == 0) // Compara se a variável 'nomeFabricante' é igual a variável 'listaAvioes[a].fabricante.
		// A quantidade de vezes que essa fabricante 'nomeFabricante' for encontrada na minha lista quer dizer a quantidade de aviões que eu tenho na lista é daquela mesma fabricante.
		{
			contaAvioes++; // Quantidade de aviões.
		}
		a++;
	}
	return contaAvioes;
}

void listaAvioesFabricante(int qtdAviao, char *nomeFabricante, Aviao *listaAvioes)
{
	 int a = 0;
	//Fazer um loop que percorre a lista de avioes e verifica se o nome do fabricante armazenado no aviao é o mesmo nome do fabricante do primeiro loop
	while (a < qtdAviao)
	{
		if (strcmp(nomeFabricante, listaAvioes[a].fabricante) == 0) // Compara se a variável 'nomeFabricante' é igual a variável 'listaAvioes[a].fabricante.
		{
			printf("%d %d %d %s\n", listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo); // Imprime todos os dados do avião do fabricante que saiu do 'if' acima.
		}
		a++;
	}
}

void imprimeAvioesDosFabricantes(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int qtd, f = 0;
	
	
	while (f < qtdFabricante) //Fazer um loop que percorre a lista de fabricantes.
	{	
		qtd = contAvioesFabricante(qtdAviao, listaFabricante[f].nome, listaAvioes); // 'qtd' recebe a quantidade de aviões do fabricante 'f'.
		
		if (qtd == 0) // Se 'qtd' for igual a zero é porque não existe aviões desse fabricante.
		{
			printf("%s: Nao existem avioes desse fabricante.", listaFabricante[f].nome);
		}
		else if (qtd == 1) // Se 'qtd' for igual a um é porque tem só um avião desse fabricante.
		{
			printf("%s: %d aviao:\n", listaFabricante[f].nome, qtd); // imprime o nome do fabricante no singular.
			
			
			listaAvioesFabricante(qtdAviao, listaFabricante[f].nome, listaAvioes); //chamar a função que imprime a lista de avioes do fabricante
		}
		else
		{
			printf("%s: %d avioes:\n", listaFabricante[f].nome, qtd); // Se for mais que 1 então vai imprimir no plural.
			
			
			listaAvioesFabricante(qtdAviao, listaFabricante[f].nome, listaAvioes); //chamar a função que imprime a lista de avioes do fabricante
		}
		f++; // Anda na lista 'listaFabricante' na função 'contAvioesFabricante'.
	}
}

void avioesItalianos(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int a = 0, f = 0, contaItaliano = 0;
	
	printf("Avioes italianos com ano de elaboracao igual ao ano de fabricacao:\n");
	
	while(a < qtdAviao) //Percorrer a lista de avioões
	{
		f = 0;
	
		while(f < qtdFabricante) //Percorrer a lista de fabricante 
		{
			if(strcmp(listaAvioes[a].fabricante, listaFabricante[f].nome) == 0)	//Verificar se o nome do fabricante do avião é o mesmo nome do fabricante encontrado
			{
				if(strcmp("Italiana", listaFabricante[f].nacionalidade) == 0) //Verificar se a nacionalidade deste fabricante é Italiana
				{
					if(listaAvioes[a].anoElab == listaAvioes[a].anoFabri) //Verificar se o ano de elaboração é igual ao ano de fabricação
					{
						printf("%d %d %d %s\n", listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo); // Imprime as informações do avião com fabricante italiano com o ano de eleboração igual ao ano de fabricação.		
						contaItaliano ++; // Conta os aviões Italianos com ano de eleboração igual ao ano de fabricação.
						break; // Para o segundo 'while' pois já encontrou o fabricante italiano.
					}
				}
			}
			f++; // Contador do segundo 'while'.
		}
		a++; // contador do primeiro 'while'
	}
	if(contaItaliano == 0) // Verifica se não tem aviões italinos com o ano de eleboração igual ao ano de fabricação.
	{
		printf("Nao existem avioes italianos com ano de elaboracao igual ao ano de fabricacao.\n");
	}
}

void avioesEuropeus(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int a = 0, f = 0, contaEuropeu = 0;
	
	printf("Avioes europeus com numero de serie inferior a 1000:\n");

	while(a < qtdAviao)	//Percorrer a lista de avioões
	{
		f = 0;
		
		while(f < qtdFabricante) //Percorrer a lista de fabricante
		{
			
			if(strcmp(listaAvioes[a].fabricante, listaFabricante[f].nome) == 0) //Verificar se o nome do fabricante do avião é o mesmo nome do fabricante encontrado
			{
				
				if(strcmp("Europeu", listaFabricante[f].nacionalidade) == 0) //Verificar se a nacionalidade deste fabricante é Europeu
				{
					
					if(listaAvioes[a].serie < 1000) //Verificar se o aviao europeu tem o numero de serie inferior a 1000
					{
						printf("%d %d %d %s\n", listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo); // Imprime as informações do avião com fabricante europeu com o número de série inferior a 1000				
						contaEuropeu ++;
						break; // Para o segundo 'while' pois já encontrou o fabricante italiano.
					}
				}
			}
			f++; // Contador do segundo 'while'.
		}
		a++; // contador do primeiro 'while'
	}
	if(contaEuropeu == 0) // Verifica se tem aviões europeus com o número de sério inferior a 1000.
	{
		printf("Nao existem avioes europeus com numero de serie inferior a 1000.\n");
	}
}

void avioesAeU(int qtdAviao, int qtdFabricante, Fabricante *listaFabricante, Aviao *listaAvioes)
{
	int a = 0, f = 0, g = 0, contaFabricante = 0;

	while(f < qtdFabricante) // Percorre a lista de fabricante
	{

		while(a < qtdAviao) // Percorre a lista de aviões para encontrar os avioes do fabricante do primeiro while
		{
			
			if(strcmp(listaFabricante[f].nome, listaAvioes[a].fabricante) == 0) //Se achar o avião do fabricante
			{
				
				int tam = 0;
				int letraA = 0, letraU = 0;
				while(tam < strlen(listaAvioes[a].modelo)) //Como achou o avião do fabricante, entao percorre o nome do modelo para saber se tem a letra 'a' e 'u'
				{
				
					if(listaAvioes[a].modelo[tam] == 'a') //Verifica cada letra para saber se é a letras 'a'.
					{
						letraA = 1; // Se encontrar a letra 'a' encrementa 1 em 'letraA'
					}
					if(listaAvioes[a].modelo[tam] == 'u') //Verifica cada letra para saber se é a letras 'u'.
					{
						letraU = 1; // Se encontrar a letra 'u' encrementa 1 em 'letraU'
					}
					tam++;
				}
				
			
				if(letraA == 1 && letraU == 1)	//Se achar as duas letras na mesma string do nome do Modelo do avião, então imprime os dados do avião
				{
					printf("%s: %d %d %d %s\n", listaFabricante[f].nome ,listaAvioes[a].serie,listaAvioes[a].anoElab, listaAvioes[a].anoFabri, listaAvioes[a].modelo);
					contaFabricante++;
				}
			}
			a++; // Contador do segundo 'while'.
		}
		f++; // contador do primeiro 'while'
	}
	
	if(contaFabricante == 0) // Se não encontrar as letras 'a' e 'u' no modelo do avião
	{
		printf("Nao existem fabricantes que tenham avioes que possuam a letra ‘a’ e a letra ‘u’ no nome do seu modelo.");
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


