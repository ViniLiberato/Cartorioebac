#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca reponsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários do sistema
{
	//Inicio da ciração de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da ciração de variáveis/string
	
	printf("Digite o CPF a se cadastrado: "); //Colentando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); // responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados(computador)
	file = fopen(arquivo, "w"); //cria o arquivo onde foi salvo o sistema
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //
	fprintf(file,","); //
	fclose(file); //
	
	printf("Digite o nome a ser cadastrado: "); //Colentando informação do usuário
	scanf("%s",nome); //
	
	file = fopen(arquivo, "a"); //
	fprintf(file,nome); //
	fclose(file); //
	
	file = fopen(arquivo, "a"); //
	fprintf(file,","); //
	fclose(file); //
	
	printf("Digite o sobrenome a ser cadastrado: "); //Colentando informação do usuário
	scanf("%s",sobrenome);
	
	file =  fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); //
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Colentando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
		
}

int consulta() //Função responsável por consultar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file==NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{printf("\nEssas são informações do usuário: ");
	printf("%s",conteudo);
	printf("\n\n");
	
	}

system("pause");


}

int deletar() //Função responsável por deletar os usuários do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}

}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");
				
		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
		
		
		switch(opcao) //Inicio da seleção
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			
								
			default:
			printf("Essa opcao não esta disponível!\n");
			system("pause");
			break;		
		//Inicio da seleção
		}
		
	
	}	
}
