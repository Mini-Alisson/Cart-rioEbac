#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //fun��o responsalvel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
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
	fprintf(file,","); //a fun��o "," serve para separar 
	fclose(file); //fecha o arquivo 
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf("%s",sobrenome); //%s refere a salvar a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //a fun��o "," serve para seprar
	fclose(file); //fecha o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o
	scanf("%s",cargo); //%s refere a salvar a string
	
	file = fopen(arquivo, "a"); //cria o arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause");	
	
}
	
int consulta() //fun��o responsavel por consultar o usu�rio
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//inicio da cria��o de variaveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da cria��o de variaveis
	
	printf ("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a salvar as variaves/strings
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r"); //abre o arquivo e o "r" para ler o arquivo
	
	if(file == NULL) //analise de usu�rio inexistente
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}
	
int deletar() //fun��o responsavel por deletar o usu�rio
{
	//inicio da cria��o de variaveis/strings
	char cpf[40];
	//fim da cria��o de variaveis/strings
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a salvar as variaveis/strings
	
	remove(cpf); //responsavel por remo��o
	
	FILE *file; //criando o arquivo
	file = fopen(cpf,"r"); //abrindo o arquivo e o "r" para ler o arquivo
	
	if(file=NULL) //essa fun��o serve como mensagem caso o usu�rio n�o exista
	{
		printf("O usu�rio n�o existe!\n"); 
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
	int opcao=0; //definindos vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); //responsavel para limpar a tela
	
	
	   setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
	   printf("###Cart�rio da EBAC###\n\n"); //inicio do menu
	   printf("Escolha a op��o desejada do menu:\n\n");
   	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
	   printf("\t3 - Deletar nomes\n\n"); 
	   printf("\t4 - Sair do sistema\n\n");
	   printf("Op��o: "); //fim do menu
	   
	
	   scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	   system("cls"); //responsavel por limpar a tela
	   
	   
	   switch(opcao)
	   {
	   	 case 1:
	   	 registro(); //chamada da fun��o de registro     
		 break;
	    
	     case 2:
	     consulta(); //chamada da fun��o consultar
         break;
         
         case 3:
         deletar(); //chamda da fun��o deletar
		break;
		 
		 case 4:
		printf("Obrigado por utilizar o sistema");
		return 0;
		break;
		 
		
		default:
		printf("Essa op��o n�o est� disponivel!\n"); // mensagem!!
		system("pause");
		break;
         
	   } //fim da sele��o
	
    }
}
