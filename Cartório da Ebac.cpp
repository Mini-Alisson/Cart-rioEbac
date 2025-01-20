#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //função responsalvel por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salva o valor da varivel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,",");  //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:"); //salva o valor da variavel
	scanf("%s",nome); //%s refere-se a salvar string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,","); //a função "," serve para separar 
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário 
	scanf("%s",sobrenome); //%s refere a salvar a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //a função "," serve para seprar
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação
	scanf("%s",cargo); //%s refere a salvar a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause");	
	
}
	
int consulta() //função responsavel por consultar o usuário
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//inicio da criação de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da criação de variaveis
	
	printf ("Digite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a salvar as variaves/strings
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o "r" para ler o arquivo
	
	if(file == NULL) //analise de usuário inexistente
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}
	
int deletar() //função responsavel por deletar o usuário
{
	//inicio da criação de variaveis/strings
	char cpf[40];
	//fim da criação de variaveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a salvar as variaveis/strings
	
	remove(cpf); //responsavel por remoção
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //abrindo o arquivo e o "r" para ler o arquivo
	
	if(file=NULL) //essa função serve como mensagem caso o usuário não exista
	{
		printf("O usuário não existe!\n"); 
		system("pause");
	}
	else 
	{
		fclose(file); //fecha o arquivo, pois ele existe
		remove(cpf); //agora pode remover o arquivo
		printf("CPF Deletado!\n");
		system("pause");
	}
}	


int main() //
{
	int opcao=0; //definindos variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); //responsavel para limpar a tela
	
	
	   setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
	   printf("###Cartório da EBAC###\n\n"); //inicio do menu
	   printf("Escolha a opção desejada do menu:\n\n");
   	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n"); 
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Opção: "); //fim do menu
	   
	
	   scanf("%d", &opcao); //armazenando a escolha do usuário
	
	   system("cls"); //responsavel por limpar a tela
	   
	   
	   switch(opcao)
	   {
	   	 case 1:
	   	 registro(); //chamada da função de registro     
		 break;
	    
	     case 2:
	     consulta(); //chamada da função consultar
         break;
         
         case 3:
         deletar(); //chamda da função deletar
		break;
		 
		 case 4:
		printf("Obrigado por utilizar o sistema");
		return 0;
		break;
		 
		
		default:
		printf("Essa opção não está disponivel!\n"); // mensagem!!
		system("pause");
		break;
         
	   } //fim da seleção
	
    }
}
