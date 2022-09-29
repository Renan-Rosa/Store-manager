/*Um empresa de Suprimentos de Informática contratou uma equipe
de analista e desenvolvedor de sistemas para desenvolver um sistema 
de controle de clientes, funcionários, fornecedores e produtos.
 Deve apresentar as operações de Cadastrar, consultar(listar todos e
  Consultar por nome),alterar e excluir para todos os controles.
*/

// Renan Rosa Schlemper e Jeferson Buratto - 


#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<io.h>
#include<string.h>
#include<dos.h>


void menuPrinc();
void cadastraCli();
void consultaCli();
void consulta_nomeCli();
void alteraCli();
void excluiCli();
void exclui_arqCli();
void menuCli();
void cadastraForn();
void consultaForn();
void consulta_nomeForn();
void alteraForn();
void excluiForn();
void exclui_arqForn();
void menuForn();
void cadastraFunc();
void consultaFunc();
void consulta_nomeFunc();
void alteraFunc();
void excluiFunc();
void exclui_arqFunc();
void menuFunc();
void menuProd();
void cria_arqCli();


using namespace std;   //para usar comandos C++ junto com o C

//declaração das estruturas de registros das base de dados

 struct dadosCli // Dados cliente
       {
	       char nomeCli[20]; //cliente.nome
		   char CPF[20]; //333.444.555-77   
	       int idadeCli;        //cliente.idade
	       float sbaseCli;      //cliente.sbase
	       float vcomprasCli; //cliente.vcompras.
	}Cliente;//variável de registro com os campos
       
 struct dadosForn //Dados Fornecedor
      {
	 	char nomeForn[20];  //string nomeForn[];
	 	char endeForn[30]; //Endereço Fornecedor
	 	char emailForn[30];
	 	char cnpj[20]; 	//34.456.678/0001-67
    }Fornecedor;
	        
 struct dadosProd
      {
      	char codProd[20];
      	char nomeProd[30];
      	float valorUniProd;
      	char modeloProd[20];
      	int estoqueProd;
     } Produto; 
       
  struct dadosFunc
      {
	 	char nomeFunc[20];  //string nomeForn[];
	 	char endeFunc[30];
	 	char emailFunc[30];
	 	char CPFF[20]; //333.444.555-77
		float salario;  	
    }Funcionario;     
       
        //declaração de variáveis Global   
       //declarar os Arquivos(FILE) e seus auxiliares

       FILE *fClientes;    // file  - Arquivo    * - Ponteiro dinÂmico
       FILE *fFornecedores;
       FILE *fProdutos;
       FILE *fFuncionarios;
       FILE *fAuxCli;
       FILE *fAuxForn;
       FILE *fAuxProd;
       FILE *fAuxFunc;
       int opc;//variável opção global para no programa principal e na rotina menu optarmos pela função a ser executada conforme seleção pelo usuário
//criar as funções de criação dos arquivos

//modularizar as funções - 
void cria_arqCli() //função que vai criar o arquivo fClientes
	{//inicia o escopo da rotina cria arquivo de clientes
	     if ((fClientes = fopen("clientes.dat","a"))==NULL) //criando e abrindo o arquivo Clientes
	     {
		printf("\n Erro de criação do arquivo Clientes");
		return;
	     }
	     printf("\n Arquivo Clientes Criado");
	     fclose(fClientes); //Fechando o arquivo Clientes
}//finaliza o escopo da rotina cria arquivo de clientes

void cria_arqAuxCli(){
	 if((fAuxCli=fopen("auxcli.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de criação de arquivo AuxCli");  //cout<<"Erro de criacao de arquivo";
	return;
	}printf("\n Arquivo AuxCli Criado");
	fclose(fAuxCli);
}


void cria_arqForn()
{
     if ((fFornecedores = fopen("fornecedores.dat","a"))==NULL) //criando e abrindo o arquivo Fornecedores
     {
	printf("\n Erro de criação do arquivo Fornecedores");
	return;
     }
     printf("\n Arquivo Fornecedores Criado");
     fclose(fFornecedores); //Fechando o arquivo Fornecedores
}

void cria_arqAuxForn(){ // cria o arquivo auxiliar Fornecedor
	 if((fAuxForn=fopen("auxforn.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de criação de arquivo AuxForn");  //cout<<"Erro de criacao de arquivo";
	return;
	}
	fclose(fAuxForn);
}


void cria_arqFunc() //função que vai criar o arquivo fFuncionarios
{//inicia o escopo da rotina cria arquivo de funcionarios
     if ((fFuncionarios = fopen("funcionarios.dat","a"))==NULL) //criando e abrindo o arquivo Funcionario
     {
	printf("\n Erro de criação do arquivo Funcionarios");
	return;
     }
     printf("\n Arquivo Funcionarios Criado");
     fclose(fFuncionarios); //Fechando o arquivo funcioanrio
}//finaliza o escopo da rotina cria arquivo de funcionario

void cria_arqAuxFunc(){
	 if((fAuxFunc=fopen("auxfunc.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de criação de arquivo AuxFunc");  //cout<<"Erro de criacao de arquivo";
	return;
	}printf("\n Arquivo AuxFunc Criado");
	fclose(fAuxFunc);
}


void cria_arqProd() //função que vai criar o arquivo produto
{
     if ((fProdutos = fopen("produtos.dat","a"))==NULL) //criando e abrindo o arquivo Produto
     {
	printf("\n Erro de criação do arquivo Produto");
	return;
     }
     printf("\n Arquivo s Criado");
     fclose(fProdutos);//Fechando o arquivo Produto
}//finaliza o escopo da rotina cria arquivo de clientes

void cria_arqAuxProd(){
	 if((fAuxProd=fopen("auxprod.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de criação de arquivo AuxProd");  //cout<<"Erro de criacao de arquivo";
	return;
	}printf("\n Arquivo AuxProd Criado");
	fclose(fAuxProd);
}



//Iniciar as operações com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Operações do arquivo Clientes

void cadastraCli(){ //cadastro do arquivo clientes
  char op; //variável opção
  system("cls");  //limpa tela
  int tamanho=0; // declaração da variáveltamanho para capturar a qtdide de registros cadastrdas
  fClientes = fopen("clientes.dat","r+");//abre o arquivo clientes para leitura e escrita 
  rewind(fClientes);  //joga para o primeiro registro do arquivo - posição 0
  do{ //laço de repetição para contar a qtidade de registros do arquivo
  fread(&Cliente,sizeof(Cliente),1,fClientes);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fClientes)); //faça até o final do arquivo

  fseek(fClientes,sizeof(Cliente),tamanho); //aponta para a posição do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     //printf("\n Digite o nome do cliente:");// mostra na tela
     fflush(stdin);
     printf("\n Digite o nome do cliente: ");//cout - comando output - printf
	 gets(Cliente.nomeCli); //cin  C - comando in  - input  - Comando de entrada - scanf
	 fflush(stdin);
	 printf("\n Digite o CPF do cliente: ");
	 cin>>Cliente.CPF;
	 fflush(stdin);
     printf("\n Digite a idade: ");
     cin>>Cliente.idadeCli;
     printf("\n Digite o salario base: ");
     cin>>Cliente.sbaseCli;
     printf("\n Digite o valor da compra: ");
     cin>>Cliente.vcomprasCli;
     tamanho=tamanho+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o próximo registro.
     printf("\n Continuar cadastrando <S> ou <N>: ");
     cin>>op;//ler a opção 
     op = toupper(op); //comando que coloca o caracter em maíusculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fClientes);// fecha o arquivo clientes
     menuCli();
}


void consultaCli() //lista todos os registros do arquivo cliente
{
     system("cls");//limpa a tela
     fClientes=fopen("clientes.dat","r"); //Abrir o arquivo clientes para leitura - Consulta
     fseek(fClientes,sizeof(struct dadosCli),0);//aponta para o registro 0 do arquivo de Clientes

     while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1)
      {
	 system("cls");//limpa a tela
	 printf("Nome Cliente  :        %s\n",Cliente.nomeCli);
	 printf("CPF do(a) cliente:     %s\n",Cliente.CPF);
	 printf("Idade Cliente :        %d\n",Cliente.idadeCli);
	 printf("Salario Ciente:        %.2f\n",Cliente.sbaseCli);
	 printf("Valor Compr Cliente:   %.2f\n",Cliente.vcomprasCli);
	 printf("\n Digite <enter> para continuar\n");
	 getch();//pedi para teclar algo  - enter
      }
     printf("\n fim do arquivo");
     //fclose(fClientes); //fecha arquivo clientes
     getch(); //espera ser teclado algo para continuar
     menuCli();
}

void consulta_nomeCli(){  // Consulta cliente pelo nome cadastrado.
	 char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;  //variável com sinlizador(flag) para indicar que achou o cliente e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//variável que localizou o cliente desejado
     char op; //variável opção	 
	system("cls"); //limpa a tela
	fClientes=fopen("clientes.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome para Procura : "); //Pergunta ao usuário qual cliente deseja buscar na consulta
	gets(nom_pro);//Usário Digita o nome do cliente a ser procurado
	       while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o cliente desejado
		    achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
			 if(achou==0)
			 { //nomes são iguais então achou o cliente desejado
		       printf("\n O Nome:               %s",Cliente.nomeCli);
		       printf("\n O CPF:                %s",Cliente.CPF);
		       printf("\n A Idade:              %d",Cliente.idadeCli);
		       printf("\n O Salário Bruto:      %0.2f",Cliente.sbaseCli);
		       printf("\n O Valor da Compra:    %0.2f",Cliente.vcomprasCli);
		       printf("\n====================================================\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;}}
		if(localizou == 1){ //varreu todo o arquivo e não encontrou o nome do cliente para ser consultado
		    printf("\n Cliente não Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Cliente <S> ou <N>:");//lista na tela para pedir se o usuário deseja cadastrar este cliente não encontrado
		    cin>>op;//lê a opção do usuário em cadastrar ou não
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
		    if (op=='S'){ //compara o valor da variável op para cadastrar ou não o novo cliente
		    cadastraCli();} //chama a função para cadstrar o novo cliente
			else {fclose(fClientes);} //fecha arquivo clientes
			printf("\n Digite <ENTER> para voltar ao Menu Clientes");
			getch();}
			menuCli();
}


void alteraCli(){
     char nom_pro[20]; 
     int achou;
     int pos=0;
     
	system("cls");//limpa a tela
	fClientes=fopen("clientes.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
	
	fflush(stdin);
	printf("\n Digite o Nome para Procura : ");
	gets(nom_pro);//Usário Digita o nome do cliente a ser procurado
	
	       while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o cliente desejado
		     achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
		    pos++;//incrementa a variável pos 1 a 1 para posicionar o próximo registro dentro do arquivo cliente
		    
		   if(achou==0){ //nomes são iguais então achou o cliente desejado
		   printf("\n O Nome:               %s",Cliente.nomeCli); 
		   printf("\n O CPF:                %s",Cliente.CPF);
		   printf("\n A Idade:              %d",Cliente.idadeCli);
		   printf("\n O Salário Bruto:      %0.2f",Cliente.sbaseCli);
		   printf("\n O Valor da Compra:    %0.2f",Cliente.vcomprasCli);
		   //printf("_____________________________________________\n");
		   printf("\n Digite <enter> para continuar e alterar \n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Começa a pedir para o usuário os novos dados a ser alterados
		   
		   	fflush(stdin);
		     printf("\n Digite a alterção do nome do(a) cliente de %s para ->",Cliente.nomeCli);//Apresenta na tela o que o usuário deve alterar
		     gets(Cliente.nomeCli);
		     fflush(stdin);
		     printf("\n Digite o CPF do(a) cliente:");
		     cin>>Cliente.CPF;
		     printf("\n Digite a idade: ");
		     cin>>Cliente.idadeCli;
		     printf("\n Digite o salario base: ");
		     cin>>Cliente.sbaseCli;
		     printf("\n Digite o valor da compra:");
		     cin>>Cliente.vcomprasCli;
		     fseek(fClientes,pos*sizeof(struct dadosCli),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posição pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fClientes,sizeof(struct dadosCli),SEEK_END);}
		     printf("\n Alteração realizada digite <enter> para continuar\n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    //fclose(fClientes);//fecha o arquivo Clientes e sai da função altera
		    menuCli();} // volta para o menu 


void excluiCli(){ //Procura o registro selecionado pelo usuário do arquivo cliente para exclusão

	char nom_pro[20];//variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
	int achou=1;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclusão e parar a pesquisa no arquivo
	int tamanhoaux=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de clientes
	int tamanhocli=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo de clientes 
	
	system("cls");//linpa tela 
	fClientes=fopen("Clientes.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxCli();//chama a função para criar o arquivo auxiliar de clientes
	fAuxCli=fopen("auxcli.dat","r+");//abre o arquivo auxiliar de clientes para leitura e escrita
	fseek(fAuxCli,sizeof(struct dadosCli),0);//aponta por seguração ao registro 0(inicial) do arquivo auxiliar de clientes
    fflush(stdin);
	printf("\n Digite o Nome do cliente p/ Procura : ");//Pergunta ao usuário qual cliente deseja buscar na consulta para ser excluído
	gets(nom_pro);//Usário Digita o nome do cliente a ser procurado para exclusão
	      while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//laço de repetição para ler registro a registro do arquivo clientes até encontrar o desejado
		     achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
	         if(achou==0){ //nomes são iguais então achou o cliente desejado
		      printf("\n O Nome:                 %s",Cliente.nomeCli);
		      printf("\n O CPF:                  %s",Cliente.CPF);
		      printf("\n A Idade:                %d",Cliente.idadeCli);
		      printf("\n O Salário Bruto:        %0.2f",Cliente.sbaseCli);
		      printf("\n O Valor da Compra:      %0.2f",Cliente.vcomprasCli);
		      printf("\n======================================================\n");
		      getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{
	         tamanhoaux=tamanhoaux+fwrite(&Cliente,sizeof(struct dadosCli),1,fAuxCli);}}
	        fclose(fAuxCli);//fecha arquivo AuxCli
	        fclose(fClientes);//fecha arquivo Clientes
	        remove("clientes.dat");//remove o arquivo inicial de Clientes totalmente pois já trasnferimos aqueles registros com excessão do a ser excluído
	        cria_arqCli();//chama a função para criar novamente o arquivo Clientes zerado
	        fClientes=fopen("clientes.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
	        fseek(fClientes,sizeof(struct dadosCli),0);//Aponta por segurança para o registro 0(inicial) do arquivo clientes
	        
	        fAuxCli=fopen("auxcli.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que não eram para ser excluídos
	        fseek(fAuxCli,sizeof(struct dadosCli),0);//Aponta por segurança para o registro 0(inicial) do arquivo AuxCli
	while(fread(&Cliente,sizeof(Cliente),1,fAuxCli)==1) {//laço de repetição para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
	  tamanhocli=tamanhocli+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
             //cada registro gravado no Clinetes a função fwrite gera 1 que é incerementado na variável tamanhocli para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	fclose(fAuxCli);//fecha arquivo auxcli
	remove("auxcli.dat");//remove completamente o arquivo auxcli pois já trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi excluído
	fclose(fClientes);//fecha aqruivo Clientes
	printf("\n Para excluir o Cliente, basta digitar <enter> para continuar\n");
	getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
	printf("\n Cliente Excluído !");
	menuCli();}
//fecha a função de exclusão de registro de clientes
	
	
void excl_arqCli(){//função para excluir completamente todo o arquivo de clientes de uma vez só
    char op;//variável de segurança para optar em excluir mesmo ou não o arquivo de clientes
    printf("\n Deleta Arquivo <S> ou <N>? ");//informação na tela para o usuário 
    cin>>op;//leitura da opção de deletar S ou não N o arquivo Clientes inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
	if (op=='S')//compara o valor da variável op para cadastrar ou não o novo cliente  
    {
      remove("clientes.dat");//remove completamente o arquivo inteiro de Clientes
      printf("arquivo deletado");}//informa na tela para o usuário que deletou o arquivo
	  
   else{//senão optou por Não - N
      printf("\n Arquivo não foi deletado por sua opção");//informa na tela para o usuário que naõ deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a função de exclusão total do arquivo Clientes
	cria_arqCli();
	menuCli();
}


void menuCli(){//criação da função Menu de opções 

  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usuários as opções de Menu
  printf("\n");//pula linha
  printf("\n 1 - Cadastrar Clientes");
  printf("\n 2 - Consultar Listar todos Clintes");
  printf("\n 3 - Consultar Por Nome de Cliente");
  printf("\n 4 - Alterar Registro de Cliente");
  printf("\n 5 - Excluir Registro de Clientes");
  printf("\n 6 - Exclui Arquivo total de Clientes");
  printf("\n 7 - Voltar ao Menu principal");
  printf("\n Digite uma opcao: ");//pede a opção via teclado do usuário
  cin>>opc;//lê a variável global opção do menu para chamar a funçao 
  switch(opc)//estrutura de composição de vários if
  {
  case 1:cadastraCli();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaCli();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeCli();break;
  case 4:alteraCli();break;
  case 5:excluiCli();break;
  case 6:excl_arqCli();break;
  case 7:menuPrinc();//função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu

//Operações do arquivo Fornecedores

void cadastraForn(){ //cadastro do arquivo clientes
  char op; //variável opção
  system("cls");  //limpa tela
  int tamanho=0; // declaração da variáveltamanho para capturar a qtdide de registros cadastrdas
  fFornecedores = fopen("fornecedores.dat","r+");//abre o arquivo clientes para leitura e escrita 
  rewind(fFornecedores);  //joga para o primeiro registro do arquivo - posição 0
  do{ //laço de repetição para contar a qtidade de registros do arquivo
  fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fFornecedores)); //faça até o final do arquivo

  fseek(fFornecedores,sizeof(Fornecedor),tamanho); //aponta para a posição do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     //printf("\n Digite o nome do cliente:");// mostra na tela
     fflush(stdin);
     printf("\n Digite o nome do fornecedor: ");//cout - comando output - printf
	 gets(Fornecedor.nomeForn); //cin  C - comando in  - input  - Comando de entrada - scanf
	 fflush(stdin);
	 printf("\n Digite o endereço do fornecedor: ");
	 gets(Fornecedor.endeForn);
	 fflush(stdin);
     printf("\n Digite o e-mail do fornecedor: ");
     gets(Fornecedor.emailForn);
     printf("\n Digite o CNPJ do fornecedor: ");
     cin>>Fornecedor.cnpj;
     tamanho=tamanho+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores); 
     printf("\n Continuar cadastrando <S> ou <N>: ");
     cin>>op;//ler a opção 
     op = toupper(op); //comando que coloca o caracter em maíusculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fFornecedores);// fecha o arquivo clientes
     menuForn();
}


void consultaForn() //lista todos os registros do arquivo fornecedores
{
     system("cls");//limpa a tela
     fFornecedores=fopen("fornecedores.dat","r"); //Abrir o arquivo clientes para leitura - Consulta
     fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta para o registro 0 do arquivo de fornecedores

     while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1)
      {
	 system("cls");//limpa a tela
	 printf("\n Nome:     %s",Fornecedor.nomeForn);// mostra na tela o campo nome do registro do cliente
	 printf("\n Endereço: %s",Fornecedor.endeForn);
	 printf("\n E-mail:   %s",Fornecedor.emailForn);
	 printf("\n CNPJ:     %s",Fornecedor.cnpj);
	 printf("\n - Digite enter para continuar - \n");
	 getch();//pedi para teclar algo  - enter
      }
      
     printf("\n fim do arquivo");
     printf("\n Digite <ENTER> para voltar ao Menu de Fornecedores");
     fclose(fFornecedores); //fecha arquivo fornecedores
     getch(); //espera ser teclado algo para continuar
     menuForn();}


void consulta_nomeForn()
{  //lista o registro selecionado pelo usuário do arquivo fornecedores
     //variáveis locais - somente enxergadas aqui
	 char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;  //variável com sinlizador(flag) para indicar que achou o fornecedor e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//variável que localizou o fornecedor desejado
     char op; //variável opção	 
	system("cls"); //limpa a tela
	fFornecedores=fopen("fornecedores.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome p/ Procura : "); //Pergunta ao usuário qual fornevedor deseja buscar na consulta
	gets(nom_pro);//Usário Digita o nome do fornecedor a ser procurado
	       while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o fornecedor desejado
		    achou=strcmp(Fornecedor.nomeForn,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do fornecedor do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
			 if(achou==0)
			 { //nomes são iguais então achou o fornecedor desejado
		       printf("\n O Nome:        %s",Fornecedor.nomeForn);//lista o nome do fornecedor na tela
		       printf("\n O Endereço:    %s",Fornecedor.endeForn);//lista o endereço do fornecedor na tela
		       printf("\n O E-mail:      %s",Fornecedor.emailForn);
		       printf("\n O CNPJ:        %s",Fornecedor.cnpj);
		       printf("\n________________________________________\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }}

		if(localizou == 1){ //varreu todo o arquivo e não encontrou o nome do fornecedor para ser consultado
		    printf("\n Fornecedor não Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Fornecedor <S> ou <N>:");//lista na tela para pedir se o usuário deseja cadastrar este fornecedor não encontrado
		    cin>>op;//lê a opção do usuário em cadastrar ou não
		    op = toupper(op);//pega o caracter S ou N digitado pelo usuário e coloca em letra maíuscula
		    if (op=='S'){ //compara o valor da variável op para cadastrar ou não o novo fornecedor
		    cadastraForn();} //chama a função para cadstrar o novo fornecedor
			else {fclose(fFornecedores);} //fecha arquivo fornecedores
			getch();}//espera algo a ser teclado e saia da função de consulta fornecedor pelo nome
			menuForn();} //volta ao menu de fornecedores

			
void alteraForn(){ //Procura o registro selecionado pelo usuário do arquivo fornecedor para alteração
     char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou;//variável com sinalizador(flag) para indicar que achou o fornecedor e pode listar os dados para fazer a alteração e parar a pesquisa no arquivo
     int pos=0;//variável para incrementar a posição do registro dentro do arquivo cliente
	system("cls");//limpa a tela
	fFornecedores=fopen("fornecedores.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome p/ Procura : ");//Pergunta ao usuário qual fornecedor deseja buscar na consulta
	gets(nom_pro);//Usário Digita o nome do fornecedor a ser procurado
	       while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o fornecedores desejado
		     achou=strcmp(Fornecedor.nomeForn,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do fornecedor para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
		    pos++;//incrementa a variável pos 1 a 1 para posicionar o próximo registro dentro do arquivo cliente
		   if(achou==0){ //nomes são iguais então achou o fornecedor desejado
		   printf("\n O Nome:         %s",Fornecedor.nomeForn);//lista o nome do fornecedor na tela
		   printf("\n O Endereço:     %s",Fornecedor.endeForn);//lista o endereço do fornecedor na tela
		   printf("\n O E-mail:       %s",Fornecedor.emailForn);
		   printf("\n O CNPJ:         %s",Fornecedor.cnpj);
		   printf("\n__________________________________________\n");
		   printf("Digite <enter> para continuar e alterar\n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Começa a pedir para o usuário os novos dados a ser alterados
		   	 fflush(stdin);
		     printf("\n Digite a alterção do nome do fornecedor(a) de %s para -> ",Fornecedor.nomeForn);//Apresenta na tela o que o usuário deve alterar
		     gets(Fornecedor.nomeForn);//Lê o novo valor de alteração do nome do fornecedor
		     fflush(stdin);
		     printf("\n Digite o endereço: ");//Apresenta na tela o que o usuário deve alterar
		     gets(Fornecedor.endeForn);//Lê o novo valor de alteração do endereço do fornecedor
		     fflush(stdin);
		     printf("\n Digite o e-mail: ");
		     gets(Fornecedor.emailForn);
		     fflush(stdin);
		     printf("\n Digite o CNPJ: ");
		     cin>>Fornecedor.cnpj;
		     fseek(fFornecedores,pos*sizeof(struct dadosForn),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posição pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fFornecedores,sizeof(struct dadosForn),SEEK_END);}
			 printf("\n Dados alterados com sucesso! ");
		     printf("Digite <enter> para continuar \n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    //fclose(fFornecedores);//fecha o arquivo fornecedores e sai da função altera
		    menuForn();
}


void excluiForn() //Procura o registro selecionado pelo usuário do arquivo fornecedores para exclusão
{
     char nom_pro[20];//variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclusão e parar a pesquisa no arquivo
	 int tamanhoaux=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de fornecedores
	 int tamanhoForn=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo de fornecedores 
	
	system("cls");//linpa tela 
	fFornecedores=fopen("fornecedores.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxForn();//chama a função para criar o arquivo auxiliar de fornecedores
	fAuxForn=fopen("auxforn.dat","r+");//abre o arquivo auxiliar de fornecedores para leitura e escrita
	fseek(fAuxForn,sizeof(struct dadosForn),0);//aponta por seguração ao registro 0(inicial) do arquivo auxiliar de fornecedores
    //começa a procura do registro a ser excluído no arquivo fornecedores
    fflush(stdin);
	printf("\n Digite o Nome do fornecedor p/ Procura: ");//Pergunta ao usuário qual fornecedor deseja buscar na consulta para ser excluído
	gets(nom_pro);//Usário Digita o nome do fornecedor a ser procurado para exclusão
	      while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){//laço de repetição para ler registro a registro do arquivo fornecedores até encontrar o desejado
		     achou=strcmp(Fornecedor.nomeForn,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do fornecedor do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do fornecedor para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
	         if(achou==0){ //nomes são iguais então achou o fornecedor desejado
		      printf("\n O Nome:          %s",Fornecedor.nomeForn);//lista o nome do fornecedor na tela
		   	  printf("\n O Endereço:      %s",Fornecedor.endeForn);//lista o endereço do fornecedor na tela
		   	  printf("\n O E-mail:        %s",Fornecedor.emailForn);
		   	  printf("\n O CNPJ:          %s",Fornecedor.cnpj);
		      printf("\n____________________________________________\n");
		      getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{ //caso não entre no achou==0 então vai para esta parte do senão para transferir uma cópia do registro que não é o desejado a excluir 
		    //do arquivo fornecedores para o arquivo auxiliar do fornecedor
	         tamanhoaux=tamanhoaux+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fAuxForn);}}//grava o registro do arquivo fornecedor no arquivo aux fornecedor um a um
             //cada registro gravado no aux a função fwrite gera 1 que é incerementado na variável tamanhoaux para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	        fclose(fAuxForn);//fecha arquivo AuxForn
	        fclose(fFornecedores);//fecha arquivo Fornecedores
	        remove("fornecedores.dat");//remove o arquivo inicial de Fornecedores totalmente pois já trasnferimos aqueles registros com excessão do a ser excluído
	        cria_arqForn();//chama a função para criar novamente o arquivo Fornecedores zerado
	        fFornecedores=fopen("fornecedores.dat","r+");//Abre o novo arquivo fornecedores para ler e gravar dados
	        fseek(fFornecedores,sizeof(struct dadosForn),0);//Aponta por segurança para o registro 0(inicial) do arquivo fornecedores
	        
	        fAuxForn=fopen("auxforn.dat","r+");//abre o arquivi AuxForn para transferir de volta os registros dos fornecedores que não eram para ser excluídos
	        fseek(fAuxForn,sizeof(struct dadosForn),0);//Aponta por segurança para o registro 0(inicial) do arquivo AuxForn
	while(fread(&Fornecedor,sizeof(Fornecedor),1,fAuxForn)==1) {//laço de repetição para trasnferir registros 1 a 1 do arquivo AuxForn para o arquivo Fornecedores
	  
	tamanhoForn=tamanhoForn+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);}//grava o registro do arquivo AucForn no arquivo Fornecedores um a um
             //cada registro gravado no fornecedores a função fwrite gera 1 que é incerementado na variável tamanhoforn para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	fclose(fAuxForn);//fecha arquivo auxforn
	remove("auxForn.dat");//remove completamente o arquivo auxforn pois já trensferimos os registros para o novo arquivo Fornecedores agora sem o registro que foi excluído
	fclose(fFornecedores);//fecha aqruivo Fornecedores
	printf("\n Fornecedor(a) Excluído - Digite <enter> para continuar\n");
	getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
	menuForn();
}//fecha a função de exclusão de registro de fornecedores
	
	
void excl_arqForn(){//função para excluir completamente todo o arquivo de Fornecedores de uma vez só
    char op;//variável de segurança para optar em excluir mesmo ou não o arquivo de fornecedores
    printf("\n Deseja Deletar Todos Os Arquivos de Fornecedores? <S> ou <N>? ");//informação na tela para o usuário 
    cin>>op;//leitura da opção de deletar S ou não N o arquivo Fornecedores inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
	if (op=='S')//compara o valor da variável op para cadastrar ou não o novo fornecedor
    {
      remove("fornecedores.dat");//remove completamente o arquivo inteiro de Fornecedores
      printf("Todos os arquivos de Fornecedores foi deletado!");}//informa na tela para o usuário que deletou o arquivo
	  
   else{//senão optou por Não - N
      printf("\n Arquivo não foi deletado por sua opção");//informa na tela para o usuário que naõ deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a função de exclusão total do arquivo Clientes
	cria_arqForn();//cria arquivo para uso futuro
	menuForn();
}


void menuForn()//criação da função Menu de opções 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usuários as opções de Menu
  printf("\n");//pula linha
  printf("1 - Cadastrar Fornecedores  \n");
  printf("2 - Consultar Listar todos os Fornecedores   \n");
  printf("3 - Consultar Por Nome de Fornecedor \n");
  printf("4 - Alterar Registro do Fornecedor \n");
  printf("5 - Excluir Registro de Fornecedores \n");
  printf("6 - Exclui Arquivo total de Fornecedores\n");
  printf("7 - Voltar ao Menu principal \n");
  printf("Digite uma opcao: ");//pede a opção via teclado do usuário
  cin>>opc;//lê a variável global opção do menu para chamar a funçao 
  switch(opc)//estrutura de composição de vários if
  {
  case 1:cadastraForn();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaForn();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeForn();break;
  case 4:alteraForn();break;
  case 5:excluiForn();break;
  case 6:excl_arqForn();break;
  case 7:menuPrinc();//função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu Fornecedores

//Operações do arquivo Funcionario

void cadastraFunc() //cadastro do arquivo funcionario
{ char op; //variável opção
  system("cls");  //limpa tela
  int tamanho=0; // declaração da variáveltamanho para capturar a qtdide de registros cadastrdas
  fFuncionarios = fopen("funcionarios.dat","r+");//abre o arquivo funcionarios para leitura e escrita 
  rewind(fFuncionarios);  //joga para o primeiro registro do arquivo - posição 0
  do{ //laço de repetição para contar a qtidade de registros do arquivo
  fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fFuncionarios)); //faça até o final do arquivo

  fseek(fFuncionarios,sizeof(Funcionario),tamanho); //aponta para a posição do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     //printf("\n Digite o nome do cliente:");// mostra na tela
     fflush(stdin);
	 cout<<"\n Digite o nome do Funcionario: ";//cout - comando output - printf
	 gets(Funcionario.nomeFunc); //cin  C - comando in  - input  - Comando de entrada - scanf
	 fflush(stdin);
     printf("\n Digite o Endereco: ");
      fflush(stdin);
     gets(Funcionario.endeFunc);
     printf("\n Digite o Email: ");
      fflush(stdin);
     gets(Funcionario.emailFunc);
     printf("\n Digite o CPF do Funcionario: ");
      fflush(stdin);
     gets(Funcionario.CPFF);
     printf("\n Digite o valor do salario do Funcionario: ");
     cin>>Funcionario.salario;
     
     tamanho=tamanho+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o próximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a opção 
     op = toupper(op); //comando que coloca o caracter em maíusculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fFuncionarios);
	 menuFunc();
}

void consultaFunc() //lista todos os registros do arquivo funcionario
{
     system("cls");//limpa a tela
     fFuncionarios=fopen("funcionarios.dat","r"); //Abrir o arquivo funcionario para leitura - Consulta
     fseek(fFuncionarios,sizeof(struct dadosFunc),0);//aponta para o registro 0 do arquivo de funcionario

     while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1)
      {
	 system("cls");//limpa a tela
	 printf("Nome Funcionario  :        %s\n",Funcionario.nomeFunc);// mostra na tela o campo nome do registro do funcionario
	 printf("Enderco Funcionario :      %s\n",Funcionario.endeFunc);
	 printf("Email Funcionario:         %s\n",Funcionario.emailFunc);
	 printf("CPF Funcionario:           %s\n",Funcionario.CPFF);
	 printf("\n Digite <enter> para continuar\n");
	 getch();//pedi para teclar algo  - enter
      }
     printf("\n fim do arquivo");
     fclose(fFuncionarios); //fecha arquivo funcionario
     getch(); 
	 menuFunc();
}

void consulta_nomeFunc(){  //lista o registro selecionado pelo usuário do arquivo funcionario
     //variáveis locais - somente enxergadas aqui
	 char nom_pro[20]; //variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;  //variável com sinlizador(flag) para indicar que achou o funcionario e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//variável que localizou o funcionario desejado
     char op; //variável opção
	 	 
	system("cls"); //limpa a tela
	fFuncionarios=fopen("funcionarios.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fFuncionarios,sizeof(struct dadosFunc),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome para Procura : "); //Pergunta ao usuário qual funcionario deseja buscar na consulta
	gets(nom_pro);//Usário Digita o nome do cliente a ser procurado
	       while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o cliente desejado
		    achou=strcmp(Funcionario.nomeFunc,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do funcionario do registro (Funcionario.nomeFunc)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
			 if(achou==0)
			 { //nomes são iguais então achou o funcionario desejado
		       printf("\n O Nome:                  %s",Funcionario.nomeFunc);//lista o nome do funcionario na tela
		       printf("\n O Endereco:              %s",Funcionario.endeFunc);//listar o endereço do funcionario na tela
		       printf("\n O Email:                 %s",Funcionario.emailFunc); //listar email funcionario
		       printf("\n O CPF do Funcionario:    %s",Funcionario.CPFF); //listar cpf funcionario 
		       
		       printf("\n=====================================================\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }

		if(localizou == 1){ //varreu todo o arquivo e não encontrou o nome do funcionario para ser consultado
		    printf("\n Funcionario não cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Funcionario <S> ou <N>:");//lista na tela para pedir se o usuário deseja cadastrar este funcionario não encontrado
		    cin>>op;//lê a opção do usuário em cadastrar ou não
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
		    if (op=='S'){ //compara o valor da variável op para cadastrar ou não o novo funcionario
		    cadastraFunc();} //chama a função para cadstrar o novo funcionario
			else {fclose(fFuncionarios);} //fecha arquivo funcionario
			getch();}}
			menuFunc();
}

void alteraFunc(){ 
     char nom_pro[20]; 
     int achou;
     int pos=0;
	system("cls");
	fFuncionarios=fopen("funcionarios.dat","r+");
	fseek(fFuncionarios,sizeof(struct dadosFunc),0);
	fflush(stdin);
	printf("\n Digite o Nome para Procura : ");//Pergunta ao usuário qual fornecedor deseja buscar na consulta
	gets(nom_pro);//Usário Digita o nome do fornecedor a ser procurado
	       while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o fornecedores desejado
		     achou=strcmp(Funcionario.nomeFunc,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do fornecedor para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
		    pos++;//incrementa a variável pos 1 a 1 para posicionar o próximo registro dentro do arquivo cliente
		   if(achou==0){ //nomes são iguais então achou o fornecedor desejado
		   printf("\n O Nome:                     %s",Funcionario.nomeFunc);//lista o nome do fornecedor na tela
		   printf("\n O Endereço:                 %s",Funcionario.endeFunc);//lista o endereço do fornecedor na tela
		   printf("\n O E-mail:                   %s",Funcionario.emailFunc);
		   printf("\n O CNPJ:                     %f",Funcionario.CPFF);
		   printf("\n O Salário:                  %f",Funcionario.salario);
		   printf("\n========================================================\n");
		   printf("\n Digite <enter> para continuar e alterar\n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Começa a pedir para o usuário os novos dados a ser alterados
		   	 fflush(stdin);
		     printf("\n Digite a alterção do nome do funcionário(a): %s para -> ",Funcionario.nomeFunc);//Apresenta na tela o que o usuário deve alterar
		     gets(Funcionario.nomeFunc);//Lê o novo valor de alteração do nome do fornecedor
		     fflush(stdin);
		     printf("\n Digite o endereço: ");//Apresenta na tela o que o usuário deve alterar
		     gets(Funcionario.endeFunc);//Lê o novo valor de alteração do endereço do fornecedor
		     fflush(stdin);
		     printf("\n Digite o e-mail: ");
		     gets(Funcionario.emailFunc);
		     fflush(stdin);
		     printf("\n Digite o CPF: ");
		     cin>>Funcionario.CPFF;
		     printf("\n Digite o salário do funcionário: ");
		     cin>>Funcionario.salario;
		     fseek(fFuncionarios,pos*sizeof(struct dadosFunc),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posição pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fFuncionarios,sizeof(struct dadosFunc),SEEK_END);}
		     printf("Dados alterados! Digite <enter> para continuar \n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    menuFunc();
}


void excluiFunc() //Procura o registro selecionado pelo usuário do arquivo funcionario para exclusão
{
     char nom_pro[20];//variável para o usuário digitar o nome do usuário a ser pesquisado no arquivo
     int achou=1;//variável com sinalizador(flag) para indicar que achou o funcionario e pode listar os dados para fazer a exclusão e parar a pesquisa no arquivo
	 int tamanhoaux=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de funcioanario
	 int tamanhofunc=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo de funcionario 
	
	system("cls");//limpa tela 
	fFuncionarios=fopen("funcionarios.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fFuncionarios,sizeof(struct dadosFunc),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxFunc();//chama a função para criar o arquivo auxiliar de funcionario
	fAuxFunc=fopen("auxfunc.dat","r+");//abre o arquivo auxiliar de funcionario para leitura e escrita
	fseek(fAuxFunc,sizeof(struct dadosFunc),0);//aponta por seguração ao registro 0(inicial) do arquivo auxiliar de funcionario
    //começa a procura do registro a ser excluído no arquivo funcionario
    fflush(stdin);
	printf("\n Digite o Nome do funcionario p/ Procura : ");//Pergunta ao usuário qual funcionario deseja buscar na consulta para ser excluído
	gets(nom_pro);//Usário Digita o nome do cliente a ser procurado para exclusão
	      while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){//laço de repetição para ler registro a registro do arquivo clientes até encontrar o desejado
		     achou=strcmp(Funcionario.nomeFunc,nom_pro);//comando que compara as nome digitado pelo usuário com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado é zero e é alocado para a variável achou, caso contrário vai 1 para a varíavel
	         if(achou==0){ //nomes são iguais então achou o cliente desejado
		      printf("\n O Nome:                %s",Funcionario.nomeFunc);//lista o nome do cliente encontrado na tela
		      printf("\n O CPF:                 %s",Funcionario.CPFF);
		      printf("\n O Salário:             %0.2f",Funcionario.salario);
		      printf("\n O Email:               %s",Funcionario.emailFunc);
		      printf("................................................\n");
		      getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{ //caso não entre no achou==0 então vai para esta parte do senão para transferir uma cópia do registro que não é o desejado a excluir 
		    //do arquivo clientes para o arquivo auxiliar do cliente
	         tamanhoaux=tamanhoaux+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fAuxFunc);}}//grava o registro do arquivo cliente no arquivo aux cliente um a um
             //cada registro gravado no aux a função fwrite gera 1 que é incerementado na variável tamanhoaux para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	        fclose(fAuxFunc);//fecha arquivo AuxCli
	        fclose(fFuncionarios);//fecha arquivo Clientes
	        remove("funcionarios.dat");//remove o arquivo inicial de Clientes totalmente pois já trasnferimos aqueles registros com excessão do a ser excluído
	        cria_arqFunc();//chama a função para criar novamente o arquivo Clientes zerado
	        fFuncionarios=fopen("funcionarios.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
	        fseek(fFuncionarios,sizeof(struct dadosFunc),0);//Aponta por segurança para o registro 0(inicial) do arquivo clientes
	        
	        fAuxFunc=fopen("auxfunc.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que não eram para ser excluídos
	        fseek(fAuxFunc,sizeof(struct dadosFunc),0);//Aponta por segurança para o registro 0(inicial) do arquivo AuxCli
	while(fread(&Funcionario,sizeof(Funcionario),1,fAuxFunc)==1) {//laço de repetição para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
	  tamanhofunc=tamanhofunc+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
             //cada registro gravado no Clinetes a função fwrite gera 1 que é incerementado na variável tamanhocli para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	fclose(fAuxFunc);//fecha arquivo auxcli
	remove("auxfunc.dat");//remove completamente o arquivo auxcli pois já trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi excluído
	fclose(fFuncionarios);//fecha aqruivo Clientes
	printf("\n Funcionário Excluído - Digite <enter> para continuar :");
	getch();
	menuFunc();
}//fecha a função de exclusão de registro de clientes
	
	
void excl_arqFunc(){//função para excluir completamente todo o arquivo de clientes de uma vez só
    char op;//variável de segurança para optar em excluir mesmo ou não o arquivo de clientes
    printf("\n Deletar Arquivo <S> ou <N>? ");//informação na tela para o usuário 
    cin>>op;//leitura da opção de deletar S ou não N o arquivo Clientes inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
	if (op=='S')//compara o valor da variável op para cadastrar ou não o novo cliente  
    {
      remove("funcionarios.dat");//remove completamente o arquivo inteiro de Clientes
      printf("arquivo deletado");}//informa na tela para o usuário que deletou o arquivo
	  
   else{//senão optou por Não - N
      printf("\n Arquivo não foi deletado por sua opção");//informa na tela para o usuário que naõ deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a função de exclusão total do arquivo Clientes
	cria_arqFunc();
	menuFunc();
}//cria arquivo para uso futuro


void menuFunc()//criação da função Menu de opções 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usuários as opções de Menu
  printf("\n");//pula linha
  printf("1 - Cadastrar Funcionário\n");
  printf("2 - Consultar Listar todos os Funcionários  \n");
  printf("3 - Consultar Por Nome de Funcionário \n");
  printf("4 - Alterar Registro de Funcionário \n");
  printf("5 - Excluir Registro de Funcionário \n");
  printf("6 - Excluir Arquivo total de Funcionários\n");
  printf("7 - Voltar ao Menu principal \n");
  printf("\n Digite uma opção: ");//pede a opção via teclado do usuário
  cin>>opc;//lê a variável global opção do menu para chamar a funçao 
  switch(opc)//estrutura de composição de vários if
  {
  case 1:cadastraFunc();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaFunc();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeFunc();break;
  case 4:alteraFunc();break;
  case 5:excluiFunc();break;
  case 6:excl_arqFunc();break;
  case 7:menuPrinc();//função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu funcionário 

// inicia menu produto

//Iniciar as operações com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Operações do arquivo Clientes

void cadastraProd(){ //cadastro do arquivo Produto
 char op; //variável opção
  system("cls");  //limpa tela
  int tamanho=0; // declaração da variáveltamanho para capturar a quantidade de registros cadastrados
  fProdutos = fopen("produtos.dat","r+");//abre o arquivo Prouto para leitura e escrita 
  rewind(fProdutos);  //joga para o primeiro registro do arquivo - posição 0
  do{ //laço de repetição para contar a quantidade de registros do arquivo
  fread(&Produto,sizeof(Produto),1,fProdutos);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fProdutos)); //faça até o final do arquivo

  fseek(fProdutos,sizeof(Produto),tamanho); //aponta para a posição do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     fflush(stdin);
     cout<<"\n Digite o nome do Produto:";
	 gets(Produto.nomeProd);
     fflush(stdin);
	 printf("\n Digite o código do Produto:");
     gets(Produto.codProd);
     fflush(stdin);
	 printf("\n Digite o modelo, (obs : Em caso de não houver colocar <Padrao>):");
     gets(Produto.modeloProd);
     fflush(stdin);
     printf("\n Digite a quantidade em estoque: ");
	 cin>>Produto.estoqueProd;
	 printf("\n Digite o valor por unidade: ");
	 fflush(stdin);
     cin>>Produto.valorUniProd;
     tamanho=tamanho+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o próximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a opção 
     op = toupper(op); //comando que coloca o caracter em maíusculo 
	 }while(op =='S'); // enquanto op igual S
     fclose(fProdutos);
     menuProd();
}

void consultaProd(){ //lista todos os registros do arquivo Produto

     system("cls");//limpa a tela
     fProdutos=fopen("produtos.dat","r"); //Abrir o arquivo produtos para leitura - Consulta
     fseek(fProdutos,sizeof(struct dadosProd),0);//aponta para o registro 0 do arquivo de Produtos

     while(fread(&Produto,sizeof(Produto),1,fProdutos)==1)
    {
	 system("cls");
	 printf("\n Nome Produto: %s",Produto.nomeProd);// mostra na tela o campo nome do registro do Produto
	 printf("\n Código Produto: %s",Produto.codProd);
	 printf("\n Modelo: %s",Produto.modeloProd);
	 printf("\n Quantidade em estoque: %d",Produto.estoqueProd);
	 printf("\n Valor unitário :%.2f",Produto.valorUniProd);
	 printf("\n Digite enter para continuar ");
	 getch();//pedi para teclar algo  - enter
      }
     printf("\n fim do arquivo");
     fclose(fProdutos); //fecha arquivo cadastrar produto
     getch(); 
     menuProd();
}

void consulta_codProd(){  //lista o registro selecionado pelo usuário do arquivo Produto
     //variáveis locais - somente enxergadas aqui
	 char cod_pro[20]; //variável para o usuário digitar o código do Produto a ser pesquisado no arquivo
     int achou=1;  //variável com sinlizador(flag) para indicar que achou o produto e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//variável que localizou o produto desejado
     char op; //variável opção
	 	 
	system("cls"); //limpa a tela
	fProdutos=fopen("produtos.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fProdutos,sizeof(struct dadosProd),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Nome do Produto p/ Procura : "); //Pergunta ao usuário qual produto deseja buscar na consulta
	cin>>cod_pro;//Usário Digita o código do produto a ser procurado
	       while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
		    achou=strcmp(Produto.nomeProd,cod_pro);
			 if(achou==0)
			 { //nomes são iguais então achou o Produto desejado
		       printf("\n O Nome             :%s",Produto.nomeProd);
		       printf("\n Código             :%s",Produto.codProd);
		       printf("\n Modelo             :%s",Produto.modeloProd);
		       printf("\n Quantidade Estoque :%d",Produto.estoqueProd);
		       printf("\n Preco unidade      :%0.2f",Produto.valorUniProd);
		       printf("\n_____________________________________________\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }}

		if(localizou == 1){ //varreu todo o arquivo e não encontrou o código do Produto para ser consultado
		    printf("\n Produto não Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Produto <S> ou <N>:");//lista na tela para pedir se o usuário deseja cadastrar este Produto não encontrado
		    cin>>op;//lê a opção do usuário em cadastrar ou não
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usuário e coloca em letra maíuscula
		    if (op=='S'){ //compara o valor da variável op para cadastrar ou não o novo Produto
		    cadastraProd();} //chama a função para cadstrar o novo Produto
			else {fclose(fProdutos);}
			getch();}
			menuProd();
}

void alteraProd(){ //Procura o registro selecionado pelo usuário do arquivo cliente para alteração
     char cod_pro[20]; //variável para o usuário digitar o código do produto a ser pesquisado no arquivo
     int achou;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a alteração e parar a pesquisa no arquivo
     int pos=0;//variável para incrementar a posição do registro dentro do arquivo cliente
	system("cls");//limpa a tela
	fProdutos=fopen("produtos.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fProdutos,sizeof(struct dadosProd),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Nome p/ Procura : ");//Pergunta ao usuário qual Produto deseja buscar na consulta
	cin>>cod_pro;//Usário Digita o código do produto a ser procurado
	       while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){//laço de repetição para percorrer registro a registro no arquivo até localizar o produto desejado
		     achou=strcmp(Produto.nomeProd,cod_pro);//comando que compara as nome digitado pelo usuário com o código do produto do registro do arquivo 
		    pos++;//incrementa a variável pos 1 a 1 para posicionar o próximo registro dentro do arquivo produto
		   if(achou==0){ //nomes são iguais então achou o cliente desejado
		   printf("\n O Nome:                  %s",Produto.nomeProd); //lista o nome do cliente encontrado na tela
		   printf("\n Código:                  %s",Produto.codProd);
		   printf("\n Modelo:                  %s",Produto.modeloProd);
		   printf("\n Quantidade Estoque:      %d",Produto.estoqueProd);
		   printf("\n Preco Unidade:           %0.2f",Produto.valorUniProd);
		   printf("\n ______________________________________________\n");
		   printf("Digite <enter> para continuar e alterar : \n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Começa a pedir para o usuário os novos dados a ser alterados
			 fflush(stdin);
		     printf("\n Digite a alteração do nome do Produto: %s",Produto.nomeProd);
		     gets(Produto.nomeProd);
		     printf("\n Digite o código: %s",Produto.codProd);
		     gets(Produto.codProd);
		     fflush(stdin);
		     printf("\n Digite o Modelo: %s",Produto.modeloProd);
		     gets(Produto.modeloProd);
		     printf("\n Digite a quantidade do Produto em estoque: %d",Produto.estoqueProd);
		     fflush(stdin);
		     cin>>Produto.estoqueProd;
		     printf("\n Digite o preço unitário R$: %0.2f",Produto.valorUniProd);
		     cin>>Produto.valorUniProd;
		     fseek(fProdutos,pos*sizeof(struct dadosProd),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posição pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fProdutos,sizeof(struct dadosProd),SEEK_END);}
		     printf("Digite <enter> para continuar :\n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    fclose(fProdutos);
		    menuProd();
}//fecha o arquivo Produto e sai da função altera


void excluiProd() //Procura o registro selecionado pelo usuário do arquivo Produto para exclusão
{
     char cod_pro[20];//variável para o usuário digitar o código do usuário a ser pesquisado no arquivo
     int achou=1;//variável com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclusão e parar a pesquisa no arquivo
	 int tamanhoaux=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de produtos
	 int tamanhoprod=0;//varíaveis para ter o controle de registro a registro do tamanho do arquivo de produtos
	
	system("cls");//linpa tela 
	fProdutos=fopen("produtos.dat","r+");
	fseek(fProdutos,sizeof(struct dadosProd),0);
	cria_arqAuxProd();
	fAuxProd=fopen("auxprod.dat","r+");
	fseek(fAuxProd,sizeof(struct dadosProd),0);//aponta por seguração ao registro 0(inicial) do arquivo auxiliar de produtos
    //começa a procura do registro a ser excluído no arquivo produto
	printf("\n Digite o Nome do Produto p/ Procura : ");//Pergunta ao usuário qual produto deseja buscar na consulta para ser excluído
	cin>>cod_pro;
	      while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
		     achou=strcmp(Produto.nomeProd,cod_pro);
	         if(achou==0){ //nomes são iguais então achou o cliente desejado
		      printf("\n Nome :               %s",Produto.nomeProd);
		      printf("\n Código :             %s",Produto.codProd);
		      printf("\n Modelo :             %s",Produto.modeloProd);
		      printf("\n Quantidade Estoque : %d",Produto.estoqueProd);
		      printf("\n Valor Unidade :      %0.2f",Produto.valorUniProd);
		      printf("\n_____________________________________________\n");
		      getch();
		    }
		    else{  
	         tamanhoaux=tamanhoaux+fwrite(&Produto,sizeof(struct dadosProd),1,fAuxProd);}}//grava o registro do arquivo cliente no arquivo aux cliente um a um
             //cada registro gravado no aux a função fwrite gera 1 que é incerementado na variável tamanhoaux para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	        fclose(fAuxProd);//fecha arquivo AuxProd
	        fclose(fProdutos);//fecha arquivo Produtos
	        remove("produtos.dat");//remove o arquivo inicial de Produtos totalmente pois já transferimos aqueles registros com excessão do a ser excluído
	        cria_arqProd();//chama a função para criar novamente o arquivo Clientes zerado
	        fProdutos=fopen("produtos.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
	        fseek(fProdutos,sizeof(struct dadosProd),0);//Aponta por segurança para o registro 0(inicial) do arquivo clientes
	        
	        fAuxProd=fopen("auxprod.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que não eram para ser excluídos
	        fseek(fAuxProd,sizeof(struct dadosProd),0);//Aponta por segurança para o registro 0(inicial) do arquivo AuxCli
	while(fread(&Produto,sizeof(Produto),1,fAuxProd)==1) {//laço de repetição para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
	  tamanhoprod=tamanhoprod+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
             //cada registro gravado no Clinetes a função fwrite gera 1 que é incerementado na variável tamanhocli para gravar 
             //no próximo registro livre no arquivo e não sobrepor resgistros.
	fclose(fAuxProd);//fecha arquivo auxcli
	remove("auxprod.dat");//remove completamente o arquivo auxcli pois já trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi excluído
	fclose(fProdutos);//fecha aqruivo Clientes
	printf("\n Produto Excluído - Digite <enter> para continuar : \n");
	getch();
	menuProd();
	}
	
	
void excl_arqProd(){//função para excluir completamente todo o arquivo de produtos de uma vez só
    char op;
    printf("\n Deletar Todos os Arquivos, (ATENÇÃO ESSA ROTINA NÃO HÁ COMO DESFAZER!):  <S> ou <N>? ");//informação na tela para o usuário 
    cin>>op;
  	op = toupper(op);
	if (op=='S')
    {
      remove("produtos.dat");//remove completamente o arquivo inteiro de Clientes
      printf("- Arquivos deletados com sucesso -");}//informa na tela para o usuário que deletou o arquivo
	  
   else{//optou por Não - N
      printf("\n O usuário optou pela opção <N> - (Arquivos NÃO deletados)");//informa na tela para o usuário que naõ deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a função de exclusão total do arquivo Produtos
	cria_arqProd();
	menuProd();
}//cria arquivo para uso futuro


void menuProd()//criação da função Menu de opções 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usuários as opções de Menu
  printf("\n");
  printf("1 - Cadastrar Produtos\n");
  printf("2 - Consultar Lista de todos os Produtos \n");
  printf("3 - Consultar Por Código do Produto \n");
  printf("4 - Alterar Registro de Produto \n");
  printf("5 - Excluir Registro do Produto \n");
  printf("6 - Exclui Arquivo total ds Produtos\n");
  printf("7 - Voltar ao Menu principal \n");
  printf("Digite uma opcao \n");//pede a opção via teclado do usuário
  cin>>opc; 
  switch(opc)
  {
  case 1:cadastraProd();break; 
  case 2:consultaProd();break;
  case 3:consulta_codProd();break;
  case 4:alteraProd();break;
  case 5:excluiProd();break;
  case 6:excl_arqProd();break;
  case 7:menuPrinc();//função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu


//Inicia a rotina de Menu Principal
void menuPrinc(){
	 system("cls");//limpa a tela
  printf("Menu Principal de opcoes");//mostra na tela para o usuários as opções de Menu
  printf("\n");//pula linha
  printf("\n 1 - Acessar Menu Clientes");
  printf("\n 2 - Acessar Menu Fornecedores  ");
  printf("\n 3 - Acessar Menu Funcionários ");
  printf("\n 4 - Acessar Menu Produtos ");
  printf("\n 5 - Sair do Sistema \n");
  printf("Digite uma opcao: ");//pede a opção via teclado do usuário
  cin>>opc;//lê a variável global opção do menu para chamar a funçao 
  switch(opc)//estrutura de composição de vários if
  {
  case 1:menuCli();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:menuForn();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:menuFunc();break;
  case 4:menuProd();break;
  case 5:exit(0);//função para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu Principal


void criarArq(){
	cria_arqCli();//chama a rotina de criação de arquivo Clientes para iniciar o programa
	cria_arqForn();
	cria_arqFunc();
	cria_arqProd();
}


main()//programa prinipal para a chamada de inicial da rotina menu que chama todas as demais
{//inicia o escopo do programa

 setlocale(LC_ALL,"portuguese");
system("cls");//limpa tela
criarArq();
menuPrinc();//chama a rotina Menu Principal
  }
//finaliza o escopo do programa


