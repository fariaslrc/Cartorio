#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar();
int consultar();
int deletar();

int main() {
	// Declaração das variáveis
	int opcao;

	// Ajustar idioma para pt-br
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

	do {
        // Início do menu
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n \n");
		printf("Opção: ");

        // Recebendo informação do usuário
		scanf("%d", &opcao); //armazenando a escolha do usuário
		system("cls");

		// Lógica para entrada do usuário
		switch(opcao)
		{ //inicio da seleção
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
				printf("Essa opção não está disponível!\n");
		} //fim da seleção
		system("pause");
		system("cls");
	} while(opcao != 4);

	return 0;
}

int registrar()
{
    // Declaração das variáveis
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
    // Declaração das variáveis
	char cpf[40];
    char conteudo[100];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

    while(fgets(conteudo, 100, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
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
    	printf("O usuário não se encontra no sistema!.\n");
	}
}
