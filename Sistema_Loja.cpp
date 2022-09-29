/*Um empresa de Suprimentos de Inform�tica contratou uma equipe
de analista e desenvolvedor de sistemas para desenvolver um sistema 
de controle de clientes, funcion�rios, fornecedores e produtos.
 Deve apresentar as opera��es de Cadastrar, consultar(listar todos e
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

//declara��o das estruturas de registros das base de dados

 struct dadosCli // Dados cliente
       {
	       char nomeCli[20]; //cliente.nome
		   char CPF[20]; //333.444.555-77   
	       int idadeCli;        //cliente.idade
	       float sbaseCli;      //cliente.sbase
	       float vcomprasCli; //cliente.vcompras.
	}Cliente;//vari�vel de registro com os campos
       
 struct dadosForn //Dados Fornecedor
      {
	 	char nomeForn[20];  //string nomeForn[];
	 	char endeForn[30]; //Endere�o Fornecedor
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
       
        //declara��o de vari�veis Global   
       //declarar os Arquivos(FILE) e seus auxiliares

       FILE *fClientes;    // file  - Arquivo    * - Ponteiro din�mico
       FILE *fFornecedores;
       FILE *fProdutos;
       FILE *fFuncionarios;
       FILE *fAuxCli;
       FILE *fAuxForn;
       FILE *fAuxProd;
       FILE *fAuxFunc;
       int opc;//vari�vel op��o global para no programa principal e na rotina menu optarmos pela fun��o a ser executada conforme sele��o pelo usu�rio
//criar as fun��es de cria��o dos arquivos

//modularizar as fun��es - 
void cria_arqCli() //fun��o que vai criar o arquivo fClientes
	{//inicia o escopo da rotina cria arquivo de clientes
	     if ((fClientes = fopen("clientes.dat","a"))==NULL) //criando e abrindo o arquivo Clientes
	     {
		printf("\n Erro de cria��o do arquivo Clientes");
		return;
	     }
	     printf("\n Arquivo Clientes Criado");
	     fclose(fClientes); //Fechando o arquivo Clientes
}//finaliza o escopo da rotina cria arquivo de clientes

void cria_arqAuxCli(){
	 if((fAuxCli=fopen("auxcli.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de cria��o de arquivo AuxCli");  //cout<<"Erro de criacao de arquivo";
	return;
	}printf("\n Arquivo AuxCli Criado");
	fclose(fAuxCli);
}


void cria_arqForn()
{
     if ((fFornecedores = fopen("fornecedores.dat","a"))==NULL) //criando e abrindo o arquivo Fornecedores
     {
	printf("\n Erro de cria��o do arquivo Fornecedores");
	return;
     }
     printf("\n Arquivo Fornecedores Criado");
     fclose(fFornecedores); //Fechando o arquivo Fornecedores
}

void cria_arqAuxForn(){ // cria o arquivo auxiliar Fornecedor
	 if((fAuxForn=fopen("auxforn.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de cria��o de arquivo AuxForn");  //cout<<"Erro de criacao de arquivo";
	return;
	}
	fclose(fAuxForn);
}


void cria_arqFunc() //fun��o que vai criar o arquivo fFuncionarios
{//inicia o escopo da rotina cria arquivo de funcionarios
     if ((fFuncionarios = fopen("funcionarios.dat","a"))==NULL) //criando e abrindo o arquivo Funcionario
     {
	printf("\n Erro de cria��o do arquivo Funcionarios");
	return;
     }
     printf("\n Arquivo Funcionarios Criado");
     fclose(fFuncionarios); //Fechando o arquivo funcioanrio
}//finaliza o escopo da rotina cria arquivo de funcionario

void cria_arqAuxFunc(){
	 if((fAuxFunc=fopen("auxfunc.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de cria��o de arquivo AuxFunc");  //cout<<"Erro de criacao de arquivo";
	return;
	}printf("\n Arquivo AuxFunc Criado");
	fclose(fAuxFunc);
}


void cria_arqProd() //fun��o que vai criar o arquivo produto
{
     if ((fProdutos = fopen("produtos.dat","a"))==NULL) //criando e abrindo o arquivo Produto
     {
	printf("\n Erro de cria��o do arquivo Produto");
	return;
     }
     printf("\n Arquivo s Criado");
     fclose(fProdutos);//Fechando o arquivo Produto
}//finaliza o escopo da rotina cria arquivo de clientes

void cria_arqAuxProd(){
	 if((fAuxProd=fopen("auxprod.dat","a"))==NULL){
	system("cls");//system clear screen  - Limpa tela
	printf("\n Erro de cria��o de arquivo AuxProd");  //cout<<"Erro de criacao de arquivo";
	return;
	}printf("\n Arquivo AuxProd Criado");
	fclose(fAuxProd);
}



//Iniciar as opera��es com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Opera��es do arquivo Clientes

void cadastraCli(){ //cadastro do arquivo clientes
  char op; //vari�vel op��o
  system("cls");  //limpa tela
  int tamanho=0; // declara��o da vari�veltamanho para capturar a qtdide de registros cadastrdas
  fClientes = fopen("clientes.dat","r+");//abre o arquivo clientes para leitura e escrita 
  rewind(fClientes);  //joga para o primeiro registro do arquivo - posi��o 0
  do{ //la�o de repeti��o para contar a qtidade de registros do arquivo
  fread(&Cliente,sizeof(Cliente),1,fClientes);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fClientes)); //fa�a at� o final do arquivo

  fseek(fClientes,sizeof(Cliente),tamanho); //aponta para a posi��o do arquivo correspondente ao tamanho
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
     //tamanho recebe incremento para gravar o pr�ximo registro.
     printf("\n Continuar cadastrando <S> ou <N>: ");
     cin>>op;//ler a op��o 
     op = toupper(op); //comando que coloca o caracter em ma�usculo 
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
	 char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou=1;  //vari�vel com sinlizador(flag) para indicar que achou o cliente e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//vari�vel que localizou o cliente desejado
     char op; //vari�vel op��o	 
	system("cls"); //limpa a tela
	fClientes=fopen("clientes.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome para Procura : "); //Pergunta ao usu�rio qual cliente deseja buscar na consulta
	gets(nom_pro);//Us�rio Digita o nome do cliente a ser procurado
	       while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o cliente desejado
		    achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
			 if(achou==0)
			 { //nomes s�o iguais ent�o achou o cliente desejado
		       printf("\n O Nome:               %s",Cliente.nomeCli);
		       printf("\n O CPF:                %s",Cliente.CPF);
		       printf("\n A Idade:              %d",Cliente.idadeCli);
		       printf("\n O Sal�rio Bruto:      %0.2f",Cliente.sbaseCli);
		       printf("\n O Valor da Compra:    %0.2f",Cliente.vcomprasCli);
		       printf("\n====================================================\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;}}
		if(localizou == 1){ //varreu todo o arquivo e n�o encontrou o nome do cliente para ser consultado
		    printf("\n Cliente n�o Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Cliente <S> ou <N>:");//lista na tela para pedir se o usu�rio deseja cadastrar este cliente n�o encontrado
		    cin>>op;//l� a op��o do usu�rio em cadastrar ou n�o
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
		    if (op=='S'){ //compara o valor da vari�vel op para cadastrar ou n�o o novo cliente
		    cadastraCli();} //chama a fun��o para cadstrar o novo cliente
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
	gets(nom_pro);//Us�rio Digita o nome do cliente a ser procurado
	
	       while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o cliente desejado
		     achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
		    pos++;//incrementa a vari�vel pos 1 a 1 para posicionar o pr�ximo registro dentro do arquivo cliente
		    
		   if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
		   printf("\n O Nome:               %s",Cliente.nomeCli); 
		   printf("\n O CPF:                %s",Cliente.CPF);
		   printf("\n A Idade:              %d",Cliente.idadeCli);
		   printf("\n O Sal�rio Bruto:      %0.2f",Cliente.sbaseCli);
		   printf("\n O Valor da Compra:    %0.2f",Cliente.vcomprasCli);
		   //printf("_____________________________________________\n");
		   printf("\n Digite <enter> para continuar e alterar \n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Come�a a pedir para o usu�rio os novos dados a ser alterados
		   
		   	fflush(stdin);
		     printf("\n Digite a alter��o do nome do(a) cliente de %s para ->",Cliente.nomeCli);//Apresenta na tela o que o usu�rio deve alterar
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
		     fseek(fClientes,pos*sizeof(struct dadosCli),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posi��o pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fClientes,sizeof(struct dadosCli),SEEK_END);}
		     printf("\n Altera��o realizada digite <enter> para continuar\n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    //fclose(fClientes);//fecha o arquivo Clientes e sai da fun��o altera
		    menuCli();} // volta para o menu 


void excluiCli(){ //Procura o registro selecionado pelo usu�rio do arquivo cliente para exclus�o

	char nom_pro[20];//vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
	int achou=1;//vari�vel com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclus�o e parar a pesquisa no arquivo
	int tamanhoaux=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de clientes
	int tamanhocli=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo de clientes 
	
	system("cls");//linpa tela 
	fClientes=fopen("Clientes.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fClientes,sizeof(struct dadosCli),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxCli();//chama a fun��o para criar o arquivo auxiliar de clientes
	fAuxCli=fopen("auxcli.dat","r+");//abre o arquivo auxiliar de clientes para leitura e escrita
	fseek(fAuxCli,sizeof(struct dadosCli),0);//aponta por segura��o ao registro 0(inicial) do arquivo auxiliar de clientes
    fflush(stdin);
	printf("\n Digite o Nome do cliente p/ Procura : ");//Pergunta ao usu�rio qual cliente deseja buscar na consulta para ser exclu�do
	gets(nom_pro);//Us�rio Digita o nome do cliente a ser procurado para exclus�o
	      while(fread(&Cliente,sizeof(Cliente),1,fClientes)==1){//la�o de repeti��o para ler registro a registro do arquivo clientes at� encontrar o desejado
		     achou=strcmp(Cliente.nomeCli,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
	         if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
		      printf("\n O Nome:                 %s",Cliente.nomeCli);
		      printf("\n O CPF:                  %s",Cliente.CPF);
		      printf("\n A Idade:                %d",Cliente.idadeCli);
		      printf("\n O Sal�rio Bruto:        %0.2f",Cliente.sbaseCli);
		      printf("\n O Valor da Compra:      %0.2f",Cliente.vcomprasCli);
		      printf("\n======================================================\n");
		      getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{
	         tamanhoaux=tamanhoaux+fwrite(&Cliente,sizeof(struct dadosCli),1,fAuxCli);}}
	        fclose(fAuxCli);//fecha arquivo AuxCli
	        fclose(fClientes);//fecha arquivo Clientes
	        remove("clientes.dat");//remove o arquivo inicial de Clientes totalmente pois j� trasnferimos aqueles registros com excess�o do a ser exclu�do
	        cria_arqCli();//chama a fun��o para criar novamente o arquivo Clientes zerado
	        fClientes=fopen("clientes.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
	        fseek(fClientes,sizeof(struct dadosCli),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo clientes
	        
	        fAuxCli=fopen("auxcli.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que n�o eram para ser exclu�dos
	        fseek(fAuxCli,sizeof(struct dadosCli),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo AuxCli
	while(fread(&Cliente,sizeof(Cliente),1,fAuxCli)==1) {//la�o de repeti��o para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
	  tamanhocli=tamanhocli+fwrite(&Cliente,sizeof(struct dadosCli),1,fClientes);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
             //cada registro gravado no Clinetes a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhocli para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	fclose(fAuxCli);//fecha arquivo auxcli
	remove("auxcli.dat");//remove completamente o arquivo auxcli pois j� trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi exclu�do
	fclose(fClientes);//fecha aqruivo Clientes
	printf("\n Para excluir o Cliente, basta digitar <enter> para continuar\n");
	getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
	printf("\n Cliente Exclu�do !");
	menuCli();}
//fecha a fun��o de exclus�o de registro de clientes
	
	
void excl_arqCli(){//fun��o para excluir completamente todo o arquivo de clientes de uma vez s�
    char op;//vari�vel de seguran�a para optar em excluir mesmo ou n�o o arquivo de clientes
    printf("\n Deleta Arquivo <S> ou <N>? ");//informa��o na tela para o usu�rio 
    cin>>op;//leitura da op��o de deletar S ou n�o N o arquivo Clientes inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
	if (op=='S')//compara o valor da vari�vel op para cadastrar ou n�o o novo cliente  
    {
      remove("clientes.dat");//remove completamente o arquivo inteiro de Clientes
      printf("arquivo deletado");}//informa na tela para o usu�rio que deletou o arquivo
	  
   else{//sen�o optou por N�o - N
      printf("\n Arquivo n�o foi deletado por sua op��o");//informa na tela para o usu�rio que na� deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a fun��o de exclus�o total do arquivo Clientes
	cria_arqCli();
	menuCli();
}


void menuCli(){//cria��o da fun��o Menu de op��es 

  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usu�rios as op��es de Menu
  printf("\n");//pula linha
  printf("\n 1 - Cadastrar Clientes");
  printf("\n 2 - Consultar Listar todos Clintes");
  printf("\n 3 - Consultar Por Nome de Cliente");
  printf("\n 4 - Alterar Registro de Cliente");
  printf("\n 5 - Excluir Registro de Clientes");
  printf("\n 6 - Exclui Arquivo total de Clientes");
  printf("\n 7 - Voltar ao Menu principal");
  printf("\n Digite uma opcao: ");//pede a op��o via teclado do usu�rio
  cin>>opc;//l� a vari�vel global op��o do menu para chamar a fun�ao 
  switch(opc)//estrutura de composi��o de v�rios if
  {
  case 1:cadastraCli();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaCli();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeCli();break;
  case 4:alteraCli();break;
  case 5:excluiCli();break;
  case 6:excl_arqCli();break;
  case 7:menuPrinc();//fun��o para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu

//Opera��es do arquivo Fornecedores

void cadastraForn(){ //cadastro do arquivo clientes
  char op; //vari�vel op��o
  system("cls");  //limpa tela
  int tamanho=0; // declara��o da vari�veltamanho para capturar a qtdide de registros cadastrdas
  fFornecedores = fopen("fornecedores.dat","r+");//abre o arquivo clientes para leitura e escrita 
  rewind(fFornecedores);  //joga para o primeiro registro do arquivo - posi��o 0
  do{ //la�o de repeti��o para contar a qtidade de registros do arquivo
  fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fFornecedores)); //fa�a at� o final do arquivo

  fseek(fFornecedores,sizeof(Fornecedor),tamanho); //aponta para a posi��o do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     //printf("\n Digite o nome do cliente:");// mostra na tela
     fflush(stdin);
     printf("\n Digite o nome do fornecedor: ");//cout - comando output - printf
	 gets(Fornecedor.nomeForn); //cin  C - comando in  - input  - Comando de entrada - scanf
	 fflush(stdin);
	 printf("\n Digite o endere�o do fornecedor: ");
	 gets(Fornecedor.endeForn);
	 fflush(stdin);
     printf("\n Digite o e-mail do fornecedor: ");
     gets(Fornecedor.emailForn);
     printf("\n Digite o CNPJ do fornecedor: ");
     cin>>Fornecedor.cnpj;
     tamanho=tamanho+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores); 
     printf("\n Continuar cadastrando <S> ou <N>: ");
     cin>>op;//ler a op��o 
     op = toupper(op); //comando que coloca o caracter em ma�usculo 
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
	 printf("\n Endere�o: %s",Fornecedor.endeForn);
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
{  //lista o registro selecionado pelo usu�rio do arquivo fornecedores
     //vari�veis locais - somente enxergadas aqui
	 char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou=1;  //vari�vel com sinlizador(flag) para indicar que achou o fornecedor e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//vari�vel que localizou o fornecedor desejado
     char op; //vari�vel op��o	 
	system("cls"); //limpa a tela
	fFornecedores=fopen("fornecedores.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome p/ Procura : "); //Pergunta ao usu�rio qual fornevedor deseja buscar na consulta
	gets(nom_pro);//Us�rio Digita o nome do fornecedor a ser procurado
	       while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o fornecedor desejado
		    achou=strcmp(Fornecedor.nomeForn,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do fornecedor do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
			 if(achou==0)
			 { //nomes s�o iguais ent�o achou o fornecedor desejado
		       printf("\n O Nome:        %s",Fornecedor.nomeForn);//lista o nome do fornecedor na tela
		       printf("\n O Endere�o:    %s",Fornecedor.endeForn);//lista o endere�o do fornecedor na tela
		       printf("\n O E-mail:      %s",Fornecedor.emailForn);
		       printf("\n O CNPJ:        %s",Fornecedor.cnpj);
		       printf("\n________________________________________\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }}

		if(localizou == 1){ //varreu todo o arquivo e n�o encontrou o nome do fornecedor para ser consultado
		    printf("\n Fornecedor n�o Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Fornecedor <S> ou <N>:");//lista na tela para pedir se o usu�rio deseja cadastrar este fornecedor n�o encontrado
		    cin>>op;//l� a op��o do usu�rio em cadastrar ou n�o
		    op = toupper(op);//pega o caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
		    if (op=='S'){ //compara o valor da vari�vel op para cadastrar ou n�o o novo fornecedor
		    cadastraForn();} //chama a fun��o para cadstrar o novo fornecedor
			else {fclose(fFornecedores);} //fecha arquivo fornecedores
			getch();}//espera algo a ser teclado e saia da fun��o de consulta fornecedor pelo nome
			menuForn();} //volta ao menu de fornecedores

			
void alteraForn(){ //Procura o registro selecionado pelo usu�rio do arquivo fornecedor para altera��o
     char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou;//vari�vel com sinalizador(flag) para indicar que achou o fornecedor e pode listar os dados para fazer a altera��o e parar a pesquisa no arquivo
     int pos=0;//vari�vel para incrementar a posi��o do registro dentro do arquivo cliente
	system("cls");//limpa a tela
	fFornecedores=fopen("fornecedores.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome p/ Procura : ");//Pergunta ao usu�rio qual fornecedor deseja buscar na consulta
	gets(nom_pro);//Us�rio Digita o nome do fornecedor a ser procurado
	       while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o fornecedores desejado
		     achou=strcmp(Fornecedor.nomeForn,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do fornecedor para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
		    pos++;//incrementa a vari�vel pos 1 a 1 para posicionar o pr�ximo registro dentro do arquivo cliente
		   if(achou==0){ //nomes s�o iguais ent�o achou o fornecedor desejado
		   printf("\n O Nome:         %s",Fornecedor.nomeForn);//lista o nome do fornecedor na tela
		   printf("\n O Endere�o:     %s",Fornecedor.endeForn);//lista o endere�o do fornecedor na tela
		   printf("\n O E-mail:       %s",Fornecedor.emailForn);
		   printf("\n O CNPJ:         %s",Fornecedor.cnpj);
		   printf("\n__________________________________________\n");
		   printf("Digite <enter> para continuar e alterar\n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Come�a a pedir para o usu�rio os novos dados a ser alterados
		   	 fflush(stdin);
		     printf("\n Digite a alter��o do nome do fornecedor(a) de %s para -> ",Fornecedor.nomeForn);//Apresenta na tela o que o usu�rio deve alterar
		     gets(Fornecedor.nomeForn);//L� o novo valor de altera��o do nome do fornecedor
		     fflush(stdin);
		     printf("\n Digite o endere�o: ");//Apresenta na tela o que o usu�rio deve alterar
		     gets(Fornecedor.endeForn);//L� o novo valor de altera��o do endere�o do fornecedor
		     fflush(stdin);
		     printf("\n Digite o e-mail: ");
		     gets(Fornecedor.emailForn);
		     fflush(stdin);
		     printf("\n Digite o CNPJ: ");
		     cin>>Fornecedor.cnpj;
		     fseek(fFornecedores,pos*sizeof(struct dadosForn),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posi��o pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fFornecedores,sizeof(struct dadosForn),SEEK_END);}
			 printf("\n Dados alterados com sucesso! ");
		     printf("Digite <enter> para continuar \n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    //fclose(fFornecedores);//fecha o arquivo fornecedores e sai da fun��o altera
		    menuForn();
}


void excluiForn() //Procura o registro selecionado pelo usu�rio do arquivo fornecedores para exclus�o
{
     char nom_pro[20];//vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou=1;//vari�vel com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclus�o e parar a pesquisa no arquivo
	 int tamanhoaux=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de fornecedores
	 int tamanhoForn=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo de fornecedores 
	
	system("cls");//linpa tela 
	fFornecedores=fopen("fornecedores.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fFornecedores,sizeof(struct dadosForn),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxForn();//chama a fun��o para criar o arquivo auxiliar de fornecedores
	fAuxForn=fopen("auxforn.dat","r+");//abre o arquivo auxiliar de fornecedores para leitura e escrita
	fseek(fAuxForn,sizeof(struct dadosForn),0);//aponta por segura��o ao registro 0(inicial) do arquivo auxiliar de fornecedores
    //come�a a procura do registro a ser exclu�do no arquivo fornecedores
    fflush(stdin);
	printf("\n Digite o Nome do fornecedor p/ Procura: ");//Pergunta ao usu�rio qual fornecedor deseja buscar na consulta para ser exclu�do
	gets(nom_pro);//Us�rio Digita o nome do fornecedor a ser procurado para exclus�o
	      while(fread(&Fornecedor,sizeof(Fornecedor),1,fFornecedores)==1){//la�o de repeti��o para ler registro a registro do arquivo fornecedores at� encontrar o desejado
		     achou=strcmp(Fornecedor.nomeForn,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do fornecedor do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do fornecedor para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
	         if(achou==0){ //nomes s�o iguais ent�o achou o fornecedor desejado
		      printf("\n O Nome:          %s",Fornecedor.nomeForn);//lista o nome do fornecedor na tela
		   	  printf("\n O Endere�o:      %s",Fornecedor.endeForn);//lista o endere�o do fornecedor na tela
		   	  printf("\n O E-mail:        %s",Fornecedor.emailForn);
		   	  printf("\n O CNPJ:          %s",Fornecedor.cnpj);
		      printf("\n____________________________________________\n");
		      getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{ //caso n�o entre no achou==0 ent�o vai para esta parte do sen�o para transferir uma c�pia do registro que n�o � o desejado a excluir 
		    //do arquivo fornecedores para o arquivo auxiliar do fornecedor
	         tamanhoaux=tamanhoaux+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fAuxForn);}}//grava o registro do arquivo fornecedor no arquivo aux fornecedor um a um
             //cada registro gravado no aux a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhoaux para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	        fclose(fAuxForn);//fecha arquivo AuxForn
	        fclose(fFornecedores);//fecha arquivo Fornecedores
	        remove("fornecedores.dat");//remove o arquivo inicial de Fornecedores totalmente pois j� trasnferimos aqueles registros com excess�o do a ser exclu�do
	        cria_arqForn();//chama a fun��o para criar novamente o arquivo Fornecedores zerado
	        fFornecedores=fopen("fornecedores.dat","r+");//Abre o novo arquivo fornecedores para ler e gravar dados
	        fseek(fFornecedores,sizeof(struct dadosForn),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo fornecedores
	        
	        fAuxForn=fopen("auxforn.dat","r+");//abre o arquivi AuxForn para transferir de volta os registros dos fornecedores que n�o eram para ser exclu�dos
	        fseek(fAuxForn,sizeof(struct dadosForn),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo AuxForn
	while(fread(&Fornecedor,sizeof(Fornecedor),1,fAuxForn)==1) {//la�o de repeti��o para trasnferir registros 1 a 1 do arquivo AuxForn para o arquivo Fornecedores
	  
	tamanhoForn=tamanhoForn+fwrite(&Fornecedor,sizeof(struct dadosForn),1,fFornecedores);}//grava o registro do arquivo AucForn no arquivo Fornecedores um a um
             //cada registro gravado no fornecedores a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhoforn para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	fclose(fAuxForn);//fecha arquivo auxforn
	remove("auxForn.dat");//remove completamente o arquivo auxforn pois j� trensferimos os registros para o novo arquivo Fornecedores agora sem o registro que foi exclu�do
	fclose(fFornecedores);//fecha aqruivo Fornecedores
	printf("\n Fornecedor(a) Exclu�do - Digite <enter> para continuar\n");
	getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
	menuForn();
}//fecha a fun��o de exclus�o de registro de fornecedores
	
	
void excl_arqForn(){//fun��o para excluir completamente todo o arquivo de Fornecedores de uma vez s�
    char op;//vari�vel de seguran�a para optar em excluir mesmo ou n�o o arquivo de fornecedores
    printf("\n Deseja Deletar Todos Os Arquivos de Fornecedores? <S> ou <N>? ");//informa��o na tela para o usu�rio 
    cin>>op;//leitura da op��o de deletar S ou n�o N o arquivo Fornecedores inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
	if (op=='S')//compara o valor da vari�vel op para cadastrar ou n�o o novo fornecedor
    {
      remove("fornecedores.dat");//remove completamente o arquivo inteiro de Fornecedores
      printf("Todos os arquivos de Fornecedores foi deletado!");}//informa na tela para o usu�rio que deletou o arquivo
	  
   else{//sen�o optou por N�o - N
      printf("\n Arquivo n�o foi deletado por sua op��o");//informa na tela para o usu�rio que na� deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a fun��o de exclus�o total do arquivo Clientes
	cria_arqForn();//cria arquivo para uso futuro
	menuForn();
}


void menuForn()//cria��o da fun��o Menu de op��es 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usu�rios as op��es de Menu
  printf("\n");//pula linha
  printf("1 - Cadastrar Fornecedores  \n");
  printf("2 - Consultar Listar todos os Fornecedores   \n");
  printf("3 - Consultar Por Nome de Fornecedor \n");
  printf("4 - Alterar Registro do Fornecedor \n");
  printf("5 - Excluir Registro de Fornecedores \n");
  printf("6 - Exclui Arquivo total de Fornecedores\n");
  printf("7 - Voltar ao Menu principal \n");
  printf("Digite uma opcao: ");//pede a op��o via teclado do usu�rio
  cin>>opc;//l� a vari�vel global op��o do menu para chamar a fun�ao 
  switch(opc)//estrutura de composi��o de v�rios if
  {
  case 1:cadastraForn();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaForn();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeForn();break;
  case 4:alteraForn();break;
  case 5:excluiForn();break;
  case 6:excl_arqForn();break;
  case 7:menuPrinc();//fun��o para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu Fornecedores

//Opera��es do arquivo Funcionario

void cadastraFunc() //cadastro do arquivo funcionario
{ char op; //vari�vel op��o
  system("cls");  //limpa tela
  int tamanho=0; // declara��o da vari�veltamanho para capturar a qtdide de registros cadastrdas
  fFuncionarios = fopen("funcionarios.dat","r+");//abre o arquivo funcionarios para leitura e escrita 
  rewind(fFuncionarios);  //joga para o primeiro registro do arquivo - posi��o 0
  do{ //la�o de repeti��o para contar a qtidade de registros do arquivo
  fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fFuncionarios)); //fa�a at� o final do arquivo

  fseek(fFuncionarios,sizeof(Funcionario),tamanho); //aponta para a posi��o do arquivo correspondente ao tamanho
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
     //tamanho recebe incremento para gravar o pr�ximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a op��o 
     op = toupper(op); //comando que coloca o caracter em ma�usculo 
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

void consulta_nomeFunc(){  //lista o registro selecionado pelo usu�rio do arquivo funcionario
     //vari�veis locais - somente enxergadas aqui
	 char nom_pro[20]; //vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou=1;  //vari�vel com sinlizador(flag) para indicar que achou o funcionario e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//vari�vel que localizou o funcionario desejado
     char op; //vari�vel op��o
	 	 
	system("cls"); //limpa a tela
	fFuncionarios=fopen("funcionarios.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fFuncionarios,sizeof(struct dadosFunc),0);//aponta pora o Registro 0(inicial) do arquivo
	fflush(stdin);
	printf("\n Digite o Nome para Procura : "); //Pergunta ao usu�rio qual funcionario deseja buscar na consulta
	gets(nom_pro);//Us�rio Digita o nome do cliente a ser procurado
	       while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o cliente desejado
		    achou=strcmp(Funcionario.nomeFunc,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do funcionario do registro (Funcionario.nomeFunc)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
			 if(achou==0)
			 { //nomes s�o iguais ent�o achou o funcionario desejado
		       printf("\n O Nome:                  %s",Funcionario.nomeFunc);//lista o nome do funcionario na tela
		       printf("\n O Endereco:              %s",Funcionario.endeFunc);//listar o endere�o do funcionario na tela
		       printf("\n O Email:                 %s",Funcionario.emailFunc); //listar email funcionario
		       printf("\n O CPF do Funcionario:    %s",Funcionario.CPFF); //listar cpf funcionario 
		       
		       printf("\n=====================================================\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }

		if(localizou == 1){ //varreu todo o arquivo e n�o encontrou o nome do funcionario para ser consultado
		    printf("\n Funcionario n�o cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Funcionario <S> ou <N>:");//lista na tela para pedir se o usu�rio deseja cadastrar este funcionario n�o encontrado
		    cin>>op;//l� a op��o do usu�rio em cadastrar ou n�o
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
		    if (op=='S'){ //compara o valor da vari�vel op para cadastrar ou n�o o novo funcionario
		    cadastraFunc();} //chama a fun��o para cadstrar o novo funcionario
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
	printf("\n Digite o Nome para Procura : ");//Pergunta ao usu�rio qual fornecedor deseja buscar na consulta
	gets(nom_pro);//Us�rio Digita o nome do fornecedor a ser procurado
	       while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o fornecedores desejado
		     achou=strcmp(Funcionario.nomeFunc,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do fornecedor do registro (Fornecedor.nomeForn)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do fornecedor para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
		    pos++;//incrementa a vari�vel pos 1 a 1 para posicionar o pr�ximo registro dentro do arquivo cliente
		   if(achou==0){ //nomes s�o iguais ent�o achou o fornecedor desejado
		   printf("\n O Nome:                     %s",Funcionario.nomeFunc);//lista o nome do fornecedor na tela
		   printf("\n O Endere�o:                 %s",Funcionario.endeFunc);//lista o endere�o do fornecedor na tela
		   printf("\n O E-mail:                   %s",Funcionario.emailFunc);
		   printf("\n O CNPJ:                     %f",Funcionario.CPFF);
		   printf("\n O Sal�rio:                  %f",Funcionario.salario);
		   printf("\n========================================================\n");
		   printf("\n Digite <enter> para continuar e alterar\n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Come�a a pedir para o usu�rio os novos dados a ser alterados
		   	 fflush(stdin);
		     printf("\n Digite a alter��o do nome do funcion�rio(a): %s para -> ",Funcionario.nomeFunc);//Apresenta na tela o que o usu�rio deve alterar
		     gets(Funcionario.nomeFunc);//L� o novo valor de altera��o do nome do fornecedor
		     fflush(stdin);
		     printf("\n Digite o endere�o: ");//Apresenta na tela o que o usu�rio deve alterar
		     gets(Funcionario.endeFunc);//L� o novo valor de altera��o do endere�o do fornecedor
		     fflush(stdin);
		     printf("\n Digite o e-mail: ");
		     gets(Funcionario.emailFunc);
		     fflush(stdin);
		     printf("\n Digite o CPF: ");
		     cin>>Funcionario.CPFF;
		     printf("\n Digite o sal�rio do funcion�rio: ");
		     cin>>Funcionario.salario;
		     fseek(fFuncionarios,pos*sizeof(struct dadosFunc),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posi��o pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fFuncionarios,sizeof(struct dadosFunc),SEEK_END);}
		     printf("Dados alterados! Digite <enter> para continuar \n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    menuFunc();
}


void excluiFunc() //Procura o registro selecionado pelo usu�rio do arquivo funcionario para exclus�o
{
     char nom_pro[20];//vari�vel para o usu�rio digitar o nome do usu�rio a ser pesquisado no arquivo
     int achou=1;//vari�vel com sinalizador(flag) para indicar que achou o funcionario e pode listar os dados para fazer a exclus�o e parar a pesquisa no arquivo
	 int tamanhoaux=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de funcioanario
	 int tamanhofunc=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo de funcionario 
	
	system("cls");//limpa tela 
	fFuncionarios=fopen("funcionarios.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fFuncionarios,sizeof(struct dadosFunc),0);//aponta pora o Registro 0(inicial) do arquivo
	cria_arqAuxFunc();//chama a fun��o para criar o arquivo auxiliar de funcionario
	fAuxFunc=fopen("auxfunc.dat","r+");//abre o arquivo auxiliar de funcionario para leitura e escrita
	fseek(fAuxFunc,sizeof(struct dadosFunc),0);//aponta por segura��o ao registro 0(inicial) do arquivo auxiliar de funcionario
    //come�a a procura do registro a ser exclu�do no arquivo funcionario
    fflush(stdin);
	printf("\n Digite o Nome do funcionario p/ Procura : ");//Pergunta ao usu�rio qual funcionario deseja buscar na consulta para ser exclu�do
	gets(nom_pro);//Us�rio Digita o nome do cliente a ser procurado para exclus�o
	      while(fread(&Funcionario,sizeof(Funcionario),1,fFuncionarios)==1){//la�o de repeti��o para ler registro a registro do arquivo clientes at� encontrar o desejado
		     achou=strcmp(Funcionario.nomeFunc,nom_pro);//comando que compara as nome digitado pelo usu�rio com o nome do cliente do registro do arquivo
		    //comando strcmp pega o valor hexadecimal dos caracteres da string nome do cliente do registro (Cliente.nomeCli)
		    //e subtrai do valor hexadecimal dos caracteres da string nome do cliente para ser procurado (nome_pro)
		    //se forem iguais o resultado � zero e � alocado para a vari�vel achou, caso contr�rio vai 1 para a var�avel
	         if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
		      printf("\n O Nome:                %s",Funcionario.nomeFunc);//lista o nome do cliente encontrado na tela
		      printf("\n O CPF:                 %s",Funcionario.CPFF);
		      printf("\n O Sal�rio:             %0.2f",Funcionario.salario);
		      printf("\n O Email:               %s",Funcionario.emailFunc);
		      printf("................................................\n");
		      getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    }
		    else{ //caso n�o entre no achou==0 ent�o vai para esta parte do sen�o para transferir uma c�pia do registro que n�o � o desejado a excluir 
		    //do arquivo clientes para o arquivo auxiliar do cliente
	         tamanhoaux=tamanhoaux+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fAuxFunc);}}//grava o registro do arquivo cliente no arquivo aux cliente um a um
             //cada registro gravado no aux a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhoaux para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	        fclose(fAuxFunc);//fecha arquivo AuxCli
	        fclose(fFuncionarios);//fecha arquivo Clientes
	        remove("funcionarios.dat");//remove o arquivo inicial de Clientes totalmente pois j� trasnferimos aqueles registros com excess�o do a ser exclu�do
	        cria_arqFunc();//chama a fun��o para criar novamente o arquivo Clientes zerado
	        fFuncionarios=fopen("funcionarios.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
	        fseek(fFuncionarios,sizeof(struct dadosFunc),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo clientes
	        
	        fAuxFunc=fopen("auxfunc.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que n�o eram para ser exclu�dos
	        fseek(fAuxFunc,sizeof(struct dadosFunc),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo AuxCli
	while(fread(&Funcionario,sizeof(Funcionario),1,fAuxFunc)==1) {//la�o de repeti��o para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
	  tamanhofunc=tamanhofunc+fwrite(&Funcionario,sizeof(struct dadosFunc),1,fFuncionarios);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
             //cada registro gravado no Clinetes a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhocli para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	fclose(fAuxFunc);//fecha arquivo auxcli
	remove("auxfunc.dat");//remove completamente o arquivo auxcli pois j� trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi exclu�do
	fclose(fFuncionarios);//fecha aqruivo Clientes
	printf("\n Funcion�rio Exclu�do - Digite <enter> para continuar :");
	getch();
	menuFunc();
}//fecha a fun��o de exclus�o de registro de clientes
	
	
void excl_arqFunc(){//fun��o para excluir completamente todo o arquivo de clientes de uma vez s�
    char op;//vari�vel de seguran�a para optar em excluir mesmo ou n�o o arquivo de clientes
    printf("\n Deletar Arquivo <S> ou <N>? ");//informa��o na tela para o usu�rio 
    cin>>op;//leitura da op��o de deletar S ou n�o N o arquivo Clientes inteiro
  	op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
	if (op=='S')//compara o valor da vari�vel op para cadastrar ou n�o o novo cliente  
    {
      remove("funcionarios.dat");//remove completamente o arquivo inteiro de Clientes
      printf("arquivo deletado");}//informa na tela para o usu�rio que deletou o arquivo
	  
   else{//sen�o optou por N�o - N
      printf("\n Arquivo n�o foi deletado por sua op��o");//informa na tela para o usu�rio que na� deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a fun��o de exclus�o total do arquivo Clientes
	cria_arqFunc();
	menuFunc();
}//cria arquivo para uso futuro


void menuFunc()//cria��o da fun��o Menu de op��es 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usu�rios as op��es de Menu
  printf("\n");//pula linha
  printf("1 - Cadastrar Funcion�rio\n");
  printf("2 - Consultar Listar todos os Funcion�rios  \n");
  printf("3 - Consultar Por Nome de Funcion�rio \n");
  printf("4 - Alterar Registro de Funcion�rio \n");
  printf("5 - Excluir Registro de Funcion�rio \n");
  printf("6 - Excluir Arquivo total de Funcion�rios\n");
  printf("7 - Voltar ao Menu principal \n");
  printf("\n Digite uma op��o: ");//pede a op��o via teclado do usu�rio
  cin>>opc;//l� a vari�vel global op��o do menu para chamar a fun�ao 
  switch(opc)//estrutura de composi��o de v�rios if
  {
  case 1:cadastraFunc();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:consultaFunc();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:consulta_nomeFunc();break;
  case 4:alteraFunc();break;
  case 5:excluiFunc();break;
  case 6:excl_arqFunc();break;
  case 7:menuPrinc();//fun��o para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu funcion�rio 

// inicia menu produto

//Iniciar as opera��es com arquivo - Cadastrar, Consultar, Alterar, Excluir
//Opera��es do arquivo Clientes

void cadastraProd(){ //cadastro do arquivo Produto
 char op; //vari�vel op��o
  system("cls");  //limpa tela
  int tamanho=0; // declara��o da vari�veltamanho para capturar a quantidade de registros cadastrados
  fProdutos = fopen("produtos.dat","r+");//abre o arquivo Prouto para leitura e escrita 
  rewind(fProdutos);  //joga para o primeiro registro do arquivo - posi��o 0
  do{ //la�o de repeti��o para contar a quantidade de registros do arquivo
  fread(&Produto,sizeof(Produto),1,fProdutos);//leitura do registro no arquivo
  tamanho++;} //tamanho = tamanho + 1 - Contar qtos registros
  while(!feof(fProdutos)); //fa�a at� o final do arquivo

  fseek(fProdutos,sizeof(Produto),tamanho); //aponta para a posi��o do arquivo correspondente ao tamanho
  do
  {
     system("cls");//limpa tela
     fflush(stdin);
     cout<<"\n Digite o nome do Produto:";
	 gets(Produto.nomeProd);
     fflush(stdin);
	 printf("\n Digite o c�digo do Produto:");
     gets(Produto.codProd);
     fflush(stdin);
	 printf("\n Digite o modelo, (obs : Em caso de n�o houver colocar <Padrao>):");
     gets(Produto.modeloProd);
     fflush(stdin);
     printf("\n Digite a quantidade em estoque: ");
	 cin>>Produto.estoqueProd;
	 printf("\n Digite o valor por unidade: ");
	 fflush(stdin);
     cin>>Produto.valorUniProd;
     tamanho=tamanho+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos); //gravando o registro no arquivo
     //tamanho recebe incremento para gravar o pr�ximo registro.
     printf("\n Continuar cadastrando <S> ou <N>:");
     cin>>op;//ler a op��o 
     op = toupper(op); //comando que coloca o caracter em ma�usculo 
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
	 printf("\n C�digo Produto: %s",Produto.codProd);
	 printf("\n Modelo: %s",Produto.modeloProd);
	 printf("\n Quantidade em estoque: %d",Produto.estoqueProd);
	 printf("\n Valor unit�rio :%.2f",Produto.valorUniProd);
	 printf("\n Digite enter para continuar ");
	 getch();//pedi para teclar algo  - enter
      }
     printf("\n fim do arquivo");
     fclose(fProdutos); //fecha arquivo cadastrar produto
     getch(); 
     menuProd();
}

void consulta_codProd(){  //lista o registro selecionado pelo usu�rio do arquivo Produto
     //vari�veis locais - somente enxergadas aqui
	 char cod_pro[20]; //vari�vel para o usu�rio digitar o c�digo do Produto a ser pesquisado no arquivo
     int achou=1;  //vari�vel com sinlizador(flag) para indicar que achou o produto e pode listar os dados e parar a pesquisa no arquivo
     int localizou=1;//vari�vel que localizou o produto desejado
     char op; //vari�vel op��o
	 	 
	system("cls"); //limpa a tela
	fProdutos=fopen("produtos.dat","r+"); // abre o arquivo para leitura e escrita
	fseek(fProdutos,sizeof(struct dadosProd),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Nome do Produto p/ Procura : "); //Pergunta ao usu�rio qual produto deseja buscar na consulta
	cin>>cod_pro;//Us�rio Digita o c�digo do produto a ser procurado
	       while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
		    achou=strcmp(Produto.nomeProd,cod_pro);
			 if(achou==0)
			 { //nomes s�o iguais ent�o achou o Produto desejado
		       printf("\n O Nome             :%s",Produto.nomeProd);
		       printf("\n C�digo             :%s",Produto.codProd);
		       printf("\n Modelo             :%s",Produto.modeloProd);
		       printf("\n Quantidade Estoque :%d",Produto.estoqueProd);
		       printf("\n Preco unidade      :%0.2f",Produto.valorUniProd);
		       printf("\n_____________________________________________\n");
		       getch();//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		       localizou=0;
		       }}

		if(localizou == 1){ //varreu todo o arquivo e n�o encontrou o c�digo do Produto para ser consultado
		    printf("\n Produto n�o Cadastrado\n"); //lista na tela
		    printf("\n Cadastrar Produto <S> ou <N>:");//lista na tela para pedir se o usu�rio deseja cadastrar este Produto n�o encontrado
		    cin>>op;//l� a op��o do usu�rio em cadastrar ou n�o
		    op = toupper(op);//pega o a caracter S ou N digitado pelo usu�rio e coloca em letra ma�uscula
		    if (op=='S'){ //compara o valor da vari�vel op para cadastrar ou n�o o novo Produto
		    cadastraProd();} //chama a fun��o para cadstrar o novo Produto
			else {fclose(fProdutos);}
			getch();}
			menuProd();
}

void alteraProd(){ //Procura o registro selecionado pelo usu�rio do arquivo cliente para altera��o
     char cod_pro[20]; //vari�vel para o usu�rio digitar o c�digo do produto a ser pesquisado no arquivo
     int achou;//vari�vel com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a altera��o e parar a pesquisa no arquivo
     int pos=0;//vari�vel para incrementar a posi��o do registro dentro do arquivo cliente
	system("cls");//limpa a tela
	fProdutos=fopen("produtos.dat","r+");// abre o arquivo para leitura e escrita
	fseek(fProdutos,sizeof(struct dadosProd),0);//aponta pora o Registro 0(inicial) do arquivo
	printf("\n Digite o Nome p/ Procura : ");//Pergunta ao usu�rio qual Produto deseja buscar na consulta
	cin>>cod_pro;//Us�rio Digita o c�digo do produto a ser procurado
	       while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){//la�o de repeti��o para percorrer registro a registro no arquivo at� localizar o produto desejado
		     achou=strcmp(Produto.nomeProd,cod_pro);//comando que compara as nome digitado pelo usu�rio com o c�digo do produto do registro do arquivo 
		    pos++;//incrementa a vari�vel pos 1 a 1 para posicionar o pr�ximo registro dentro do arquivo produto
		   if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
		   printf("\n O Nome:                  %s",Produto.nomeProd); //lista o nome do cliente encontrado na tela
		   printf("\n C�digo:                  %s",Produto.codProd);
		   printf("\n Modelo:                  %s",Produto.modeloProd);
		   printf("\n Quantidade Estoque:      %d",Produto.estoqueProd);
		   printf("\n Preco Unidade:           %0.2f",Produto.valorUniProd);
		   printf("\n ______________________________________________\n");
		   printf("Digite <enter> para continuar e alterar : \n");
		   getch(); //espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		   //Come�a a pedir para o usu�rio os novos dados a ser alterados
			 fflush(stdin);
		     printf("\n Digite a altera��o do nome do Produto: %s",Produto.nomeProd);
		     gets(Produto.nomeProd);
		     printf("\n Digite o c�digo: %s",Produto.codProd);
		     gets(Produto.codProd);
		     fflush(stdin);
		     printf("\n Digite o Modelo: %s",Produto.modeloProd);
		     gets(Produto.modeloProd);
		     printf("\n Digite a quantidade do Produto em estoque: %d",Produto.estoqueProd);
		     fflush(stdin);
		     cin>>Produto.estoqueProd;
		     printf("\n Digite o pre�o unit�rio R$: %0.2f",Produto.valorUniProd);
		     cin>>Produto.valorUniProd;
		     fseek(fProdutos,pos*sizeof(struct dadosProd),SEEK_SET);//posiciona o ponteiro de registro do arquivo na posi��o pos registrada para alterar o registro certo dentro do arquivo
		     fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);//Grava os dados alterados no registro certo dentro do arquivo
			 fseek(fProdutos,sizeof(struct dadosProd),SEEK_END);}
		     printf("Digite <enter> para continuar :\n");
		     getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela
		    fclose(fProdutos);
		    menuProd();
}//fecha o arquivo Produto e sai da fun��o altera


void excluiProd() //Procura o registro selecionado pelo usu�rio do arquivo Produto para exclus�o
{
     char cod_pro[20];//vari�vel para o usu�rio digitar o c�digo do usu�rio a ser pesquisado no arquivo
     int achou=1;//vari�vel com sinalizador(flag) para indicar que achou o cliente e pode listar os dados para fazer a exclus�o e parar a pesquisa no arquivo
	 int tamanhoaux=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo auxiliar de produtos
	 int tamanhoprod=0;//var�aveis para ter o controle de registro a registro do tamanho do arquivo de produtos
	
	system("cls");//linpa tela 
	fProdutos=fopen("produtos.dat","r+");
	fseek(fProdutos,sizeof(struct dadosProd),0);
	cria_arqAuxProd();
	fAuxProd=fopen("auxprod.dat","r+");
	fseek(fAuxProd,sizeof(struct dadosProd),0);//aponta por segura��o ao registro 0(inicial) do arquivo auxiliar de produtos
    //come�a a procura do registro a ser exclu�do no arquivo produto
	printf("\n Digite o Nome do Produto p/ Procura : ");//Pergunta ao usu�rio qual produto deseja buscar na consulta para ser exclu�do
	cin>>cod_pro;
	      while(fread(&Produto,sizeof(Produto),1,fProdutos)==1){
		     achou=strcmp(Produto.nomeProd,cod_pro);
	         if(achou==0){ //nomes s�o iguais ent�o achou o cliente desejado
		      printf("\n Nome :               %s",Produto.nomeProd);
		      printf("\n C�digo :             %s",Produto.codProd);
		      printf("\n Modelo :             %s",Produto.modeloProd);
		      printf("\n Quantidade Estoque : %d",Produto.estoqueProd);
		      printf("\n Valor Unidade :      %0.2f",Produto.valorUniProd);
		      printf("\n_____________________________________________\n");
		      getch();
		    }
		    else{  
	         tamanhoaux=tamanhoaux+fwrite(&Produto,sizeof(struct dadosProd),1,fAuxProd);}}//grava o registro do arquivo cliente no arquivo aux cliente um a um
             //cada registro gravado no aux a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhoaux para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	        fclose(fAuxProd);//fecha arquivo AuxProd
	        fclose(fProdutos);//fecha arquivo Produtos
	        remove("produtos.dat");//remove o arquivo inicial de Produtos totalmente pois j� transferimos aqueles registros com excess�o do a ser exclu�do
	        cria_arqProd();//chama a fun��o para criar novamente o arquivo Clientes zerado
	        fProdutos=fopen("produtos.dat","r+");//Abre o novo arquivo Clientes para ler e gravar dados
	        fseek(fProdutos,sizeof(struct dadosProd),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo clientes
	        
	        fAuxProd=fopen("auxprod.dat","r+");//abre o arquivi AuxCli para transferir de volta os registros dos clientes que n�o eram para ser exclu�dos
	        fseek(fAuxProd,sizeof(struct dadosProd),0);//Aponta por seguran�a para o registro 0(inicial) do arquivo AuxCli
	while(fread(&Produto,sizeof(Produto),1,fAuxProd)==1) {//la�o de repeti��o para trasnferir registros 1 a 1 do arquivo AuxCli para o arquivo Clientes
	  tamanhoprod=tamanhoprod+fwrite(&Produto,sizeof(struct dadosProd),1,fProdutos);}//grava o registro do arquivo AucCLi no arquivo Clientes um a um
             //cada registro gravado no Clinetes a fun��o fwrite gera 1 que � incerementado na vari�vel tamanhocli para gravar 
             //no pr�ximo registro livre no arquivo e n�o sobrepor resgistros.
	fclose(fAuxProd);//fecha arquivo auxcli
	remove("auxprod.dat");//remove completamente o arquivo auxcli pois j� trensferimos os registros para o novo arquivo Clientes agora sem o registro que foi exclu�do
	fclose(fProdutos);//fecha aqruivo Clientes
	printf("\n Produto Exclu�do - Digite <enter> para continuar : \n");
	getch();
	menuProd();
	}
	
	
void excl_arqProd(){//fun��o para excluir completamente todo o arquivo de produtos de uma vez s�
    char op;
    printf("\n Deletar Todos os Arquivos, (ATEN��O ESSA ROTINA N�O H� COMO DESFAZER!):  <S> ou <N>? ");//informa��o na tela para o usu�rio 
    cin>>op;
  	op = toupper(op);
	if (op=='S')
    {
      remove("produtos.dat");//remove completamente o arquivo inteiro de Clientes
      printf("- Arquivos deletados com sucesso -");}//informa na tela para o usu�rio que deletou o arquivo
	  
   else{//optou por N�o - N
      printf("\n O usu�rio optou pela op��o <N> - (Arquivos N�O deletados)");//informa na tela para o usu�rio que na� deletou o arquivo
    getch();}//espera algoa ser teclado para continuar, permite que vejamos os dados na tela e fecha a fun��o de exclus�o total do arquivo Produtos
	cria_arqProd();
	menuProd();
}//cria arquivo para uso futuro


void menuProd()//cria��o da fun��o Menu de op��es 
{ //inicia o escopo da rotina Menu
  system("cls");//limpa a tela
  printf("Menu de opcoes");//mostra na tela para o usu�rios as op��es de Menu
  printf("\n");
  printf("1 - Cadastrar Produtos\n");
  printf("2 - Consultar Lista de todos os Produtos \n");
  printf("3 - Consultar Por C�digo do Produto \n");
  printf("4 - Alterar Registro de Produto \n");
  printf("5 - Excluir Registro do Produto \n");
  printf("6 - Exclui Arquivo total ds Produtos\n");
  printf("7 - Voltar ao Menu principal \n");
  printf("Digite uma opcao \n");//pede a op��o via teclado do usu�rio
  cin>>opc; 
  switch(opc)
  {
  case 1:cadastraProd();break; 
  case 2:consultaProd();break;
  case 3:consulta_codProd();break;
  case 4:alteraProd();break;
  case 5:excluiProd();break;
  case 6:excl_arqProd();break;
  case 7:menuPrinc();//fun��o para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu


//Inicia a rotina de Menu Principal
void menuPrinc(){
	 system("cls");//limpa a tela
  printf("Menu Principal de opcoes");//mostra na tela para o usu�rios as op��es de Menu
  printf("\n");//pula linha
  printf("\n 1 - Acessar Menu Clientes");
  printf("\n 2 - Acessar Menu Fornecedores  ");
  printf("\n 3 - Acessar Menu Funcion�rios ");
  printf("\n 4 - Acessar Menu Produtos ");
  printf("\n 5 - Sair do Sistema \n");
  printf("Digite uma opcao: ");//pede a op��o via teclado do usu�rio
  cin>>opc;//l� a vari�vel global op��o do menu para chamar a fun�ao 
  switch(opc)//estrutura de composi��o de v�rios if
  {
  case 1:menuCli();break; //caso a opc igual 1 chamada rotina cadastra executando-a retornando para o menu 
  case 2:menuForn();break;//caso a opc igual 2 chamada rotina consulta Cliente Listar executando-a retornando para o menu 
  case 3:menuFunc();break;
  case 4:menuProd();break;
  case 5:exit(0);//fun��o para sair totalmente do programa
  }
}//finaliza o escopo da rotina Menu Principal


void criarArq(){
	cria_arqCli();//chama a rotina de cria��o de arquivo Clientes para iniciar o programa
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


