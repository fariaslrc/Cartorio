#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar();
int consultar();
int deletar();

int main() {
	// Declara��o das vari�veis
	int opcao;

	// Ajustar idioma para pt-br
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

	do {
        // In�cio do menu
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n \n");
		printf("Op��o: ");

        // Recebendo informa��o do usu�rio
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		system("cls");

		// L�gica para entrada do usu�rio
		switch(opcao)
		{ //inicio da sele��o
			case 1:
			    registrar();
            break;
			case 2:
			    consultar();
            break;
			case 3:
			    deletar();
            break;
			case 4:
			    printf("obrigado por usar o sistema.\n");
			    return 0;
            break;
			default: 
				printf("Essa op��o n�o est� dispon�vel!\n");
		} //fim da sele��o
		system("pause");
		system("cls");
	} while(opcao != 4);

	return 0;
}

int registrar()
{
    // Declara��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
    FILE *file; // cria o arquivo

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);

	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
}

int consultar()
{
    // Declara��o das vari�veis
	char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
    }

    while(fgets(conteudo, 100, file) != NULL)
    {
        printf("\nEssas s�o as informa��es do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
	
	FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL){
    	printf("O usu�rio n�o se encontra no sistema!.\n");
	}
}
