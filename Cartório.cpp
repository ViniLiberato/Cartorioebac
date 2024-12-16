#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca repons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios do sistema
{
	//Inicio da cira��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cira��o de vari�veis/string
	
	printf("Digite o CPF a se cadastrado: "); //Colentando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); // respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo no banco de dados(computador)
	file = fopen(arquivo, "w"); //cria o arquivo onde foi salvo o sistema
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //
	fprintf(file,","); //
	fclose(file); //
	
	printf("Digite o nome a ser cadastrado: "); //Colentando informa��o do usu�rio
	scanf("%s",nome); //
	
	file = fopen(arquivo, "a"); //
	fprintf(file,nome); //
	fclose(file); //
	
	file = fopen(arquivo, "a"); //
	fprintf(file,","); //
	fclose(file); //
	
	printf("Digite o sobrenome a ser cadastrado: "); //Colentando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file =  fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); //
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //Colentando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");
		
}

int consulta() //Fun��o respons�vel por consultar os usu�rios do sistema
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{printf("\nEssas s�o informa��es do usu�rio: ");
	printf("%s",conteudo);
	printf("\n\n");
	
	}

system("pause");


}

int deletar() //Fun��o respons�vel por deletar os usu�rios do sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}

}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");
				
		setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		
		switch(opcao) //Inicio da sele��o
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
								
			default:
			printf("Essa opcao n�o esta dispon�vel!\n");
			system("pause");
			break;		
		//Inicio da sele��o
		}
		
	
	}	
}
