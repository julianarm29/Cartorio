#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //alocação de espaço em memória
#include <locale.h> //alocação de texto por região
#include <string.h> //biblioteca que faz as strings funcionarem

int registro()
{ setlocale(LC_ALL, "Portuguese");
//char é pra criar uma variável
	char arquivo[40];
	char cpf[40]; 
	char nome[40]; 
	char sobrenome[40];
	char cargo[40]; //40 é o máximo que o usuário pode digitar, posso usar outro número

	printf("Digite o seu CPF: ");
	scanf("%s", cpf); //isso é pra salvar o cpf como string
	
	strcpy(arquivo, cpf); //copia os valores da string cpf para a variável arquivo
	
	FILE *file; //FILE é uma função já pronta no sistema
	file = fopen(arquivo, "w"); //file abre o arquivo 'arquivo', e o w é para escrever nesse arquivo
	fprintf(file,cpf); //é o print no arquivo, por isso dois f
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //a é para atualizar
	fprintf(file, ","); // colocar a virgula entre os dados
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //a é para atualizar
	fprintf(file, ","); // colocar a virgula entre os dados
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a"); //a é para atualizar
	fprintf(file, ","); // colocar a virgula entre os dados
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);

}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40]; //tem que criar a variavel de novo pois estamos em outro sistema
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //read
	
	if(file == NULL)
	{
		printf("CPF não cadastrado. \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //salvar dentro de conteudo os 200 caracteres dentro de file, enquanto o valor não for nulo 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n \n");
		
	}
	system("pause");

}

int deletar()
{	
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF não cadastrado. \n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao = 0; //definindo as variáveis
	int x = 1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC###\n\n");
	printf ("Digite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	//aqui garante que a senha digitada tem que ser admin senão vai dar senha incorreta
	
	if(comparacao == 0)
	{
		for(x=1; x=1;) 
		//o segundo x diz pro programa sair quando atingir o valor. 
		//no caso queremos que fique no 1 e continue quando for 1
		{
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
			printf("Cartório da EBAC \n\n"); //início do menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar nomes \n ");
			printf("\t2 - Consultar nomes \n");
			printf("\t3 - Deletar nomes \n");
			printf("\t4 - Sair do sistema"); 
			printf("Opção desejada: ");//fim do menu
	
			scanf("%d", &opcao ); //armazenamento da escolha do usuário
	
			system("cls");
		
			switch(opcao)
			{
				case 1:
					registro();
					break;
					
				case 2:
					consultar();
					break;
					
				case 3:
					deletar();
					break;
				
				case 4:
					printf("Obrigada por utilizar o sistema \n");
					return 0;
					break;
									
				default:
					printf("Digite uma opção válida\n");
					system("pause");
					break;
			}
		}	
	}	//fim da seleção da opção

	else
		printf("Senha incorreta");
} 

	
