#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca alocação de espaços de memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string's

int registro()//função de cadastranebto de usuários
{
	//inicio da criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação das variaveis
	
	printf("Digite o CPF a ser cadastrado:");//coleta de valoes das strings
	scanf("%s", cpf);//%s armazenamento das string's
	
	strcpy(arquivo,cpf);//copia o valor das string
	
	FILE *file;//cria um banco de dados local
	file = fopen(arquivo, "w");//criar arquivo e a função "W" é escrever.
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);

	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo as ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	 
	 system("pause");
	
	
}

int consulta ()
{
	setlocale(LC_ALL,"portuguese"); //liguagem definida
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo,nao localizado!\n\n");
		
	}
	
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuario:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario:");
	scanf("%s",cpf);
	
	remove(cpf);
	FILE *file;
	file =fopen(cpf,"r");
			
	if(cpf == NULL);
	{
		printf("O usuario não se encontra no sistema!\n\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0;//Definindo variavel
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL,"portuguese"); //liguagem definida

		printf("###Cartório da EBAC### \n\n");
		printf("Escolha a opção desejada do menu: \n\n"); //inicio do menu
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - consultar  nomes \n");
		printf("\t3 - Deletar nomes \n");
		printf("\t4 - Sair do sistema\n\n");
	
		printf("Opção:");//fim do menu
	
		scanf("%d", &opcao);//escolha do usuário armazenada
	
		system("CLS");//responsavel por lipar a tela 
		
		
		switch(opcao)//inicio da seleção
		{
			case 1:
			registro();//chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
						
			case 4:
			printf("Obrigado por ultilizar nosso sistema!\n\n");
			return 0;
			break;
						
			default:
			printf("esta opção não esta disponivel!\n");
			system("pause");//fim da seleção
		}
	}
}
