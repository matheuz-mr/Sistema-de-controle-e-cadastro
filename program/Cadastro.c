#include <stdio.h>
#include <locale.h>

//FUNÇÃO LOGIN
char login(){
   setlocale(LC_ALL, "");
   inicio:
     system("cls");
     system("color 0f");
     system("mode con:cols=80 lines=30");

     char user[4], s[4];

     printf("\n\n\n\n\n\n\n                               ______LOGIN______"
            "\n\n                               USUARIO: ");
     scanf("%s", &user);



     if(strcmp(user, "admin") == 0){
         goto senha;
         }
     else{  system("color 4f");
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n                           USUARIO OU SENHA INCORRETO");
            sleep(1);
            goto inicio; }
   senha:
      printf("\n                               SENHA: ");
     scanf("%s", &s);
     if(strcmp(s, "12345") == 0){
         return 0;
         }
     else{  system("color 4f");
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n                           USUARIO OU SENHA INCORRETO");
            sleep(1);
            goto inicio; }

}

//FUNÇÃO CADASTRO
cadastro(){
   setlocale(LC_ALL, "");
   system("cls");
    FILE *file;
    char n[100], cpf[12], cell[20], email[100], end[100];

    printf("\n\n___________________________________CADASTRAR____________________________________");
       //NOME
       printf("\n\n                  NOME: ");
       scanf("%s", &n);
       file = fopen(n, "wb");

       fprintf(file,"\n               NOME: ");
       fprintf(file, n);
       //CPF
       printf("\n                  CPF: ");
       scanf("%s", &cpf);
       fprintf(file,"\n               CPF: ");
       fprintf(file, cpf);
       //TELEFONE
       printf("\n                  TELEFONE: ");
       scanf("%s", &cell);
       fprintf(file,"\n               TELEFONE: ");
       fprintf(file, cell);
       //EMAIL
       printf("\n                  EMAIL: ");
       scanf("%s", &email);
       fprintf(file,"\n               EMAIL: ");
       fprintf(file, email);
       //ENDEREÇO
       printf("\n                  ENDEREÇO: ");
       scanf("%s", &end);
       fprintf(file,"\n               ENDEREÇO: ");
       fprintf(file, end);
       fclose(file);
       sleep(1);
       return 0;
}

//FUNÇÃO BUSCA
busca(){
   setlocale(LC_ALL, "");
   busca:
   system("mode con:cols=80 lines=200");
       system("cls");
       FILE *file;
       char bus[100], f[100];
       printf("\n\n_____________________________________BUSCA______________________________________"
       "\n\n              AGENDAMENTO - MES REFERENTE "
       "\n              CADASTRO - APENAS O NOME "
       "\n________________________________________________________________________________");
       printf("\n\n              BUSCA: ");
       scanf("%s", &bus);
       file = fopen(bus, "r");
        //LEITURA DO ARQUIVO
        int opbusca;
        if (file == NULL){
        printf("\n\n               NÃO ENCONTRADO");

    }
        while(fgets(f, 100, file) != NULL){
        printf("%s", f);
    }
        printf("\n\n________________________________________________________________________________"
        "\n               DIGITE 1 PARA NOVA BUSCA OU 2 PARA VOLTAR ");
        scanf("%i", &opbusca);
         switch(opbusca){

            case 1: goto busca; break;
            default: fclose(file);
                     return 0;; break; }


}

//FUNÇÃO EXCLUIR
excluir(){
      setlocale(LC_ALL, "");
      system("cls");
      int del;
      FILE *fp;
      char nome[100];
        printf("\n\n________________________________EXCLUIR DADOS____________________________________"
        "\n              AGENDAMENTO - MES"
        "\n              CADASTRO - APENAS O NOME "
        "\n              RELATORIO - NOME + 'R'"
        "\n\n              DIGITE O NOME PARA DELETAR: "
        "\n________________________________________________________________________________");
        scanf("%s", &nome);

      fp = fopen(nome, "w");

      fprintf(fp, "%s", " ");
      fclose(fp);

      del = remove(nome);

      if(del == NULL) { printf("\n              DADOS DELETADOS COM SUCESSO");}
       else { printf("\n              ERRO, DADOS NAO EXISTENTE"); }

      int opdel;
       printf("\n\n________________________________________________________________________________"
              "\n\n               DIGITE 1 PARA VOLTAR: ");

       scanf(" %c", &opdel);
        switch(opdel){
           case 1: return 0; break;
           default: return 0; break; }
}

//FUNÇÃO AGENDAR
agendar(){
   setlocale(LC_ALL, "");
   system("cls");
    char nm[100], dia[100], horario[100], mes[100];
    FILE *p;
    printf("\n\n___________________________________AGENDAR______________________________________"
    "\n\n     -EM CASO DE REMARCAÇAO DE AGENDAMENTO DIGITE REMARCADO JUNTO DO HORARIO"
    "\n________________________________________________________________________________\n\n     MES: ");
    scanf("%s", &mes);

      p = fopen(mes, "a");
      printf("\n     NOME: ");
      scanf("%s", &nm);
      printf("\n     DIA: ");
      scanf("%s", &dia);
      printf("\n     HORARIO: ");
      scanf("%s", &horario);

      fprintf(p,"\n     NOME: ");
      fprintf(p, nm);
      fprintf(p,"          DIA: ");
      fprintf(p,     dia);
      fprintf(p,"          HORARIO: ");
      fprintf(p,     horario);
      fprintf(p, "\n");

      fclose(p);
      sleep(1);
      return 0;
}

//FUNÇÃO RELATORIOS
relatorios(){
   setlocale(LC_ALL, "");
   system("cls");
    FILE *rel;
    char r[50], re[10000];
    printf("\n\n______________________________RELATORIOS MEDICOS________________________________");
       //NOME
       printf("\n\n  NOME COM UM 'R' NO FINAL: ");
       scanf("%s", &r);
       rel = fopen(r, "wb");

       fprintf(rel,"\n               NOME: ");
       fprintf(rel, r);
       //RELATORIO
       printf("\n  - ");
       scanf("%s", &re);
       fprintf(rel,"\n               - ");
       fprintf(rel, re);

       fclose(rel);
       sleep(1);
       return 0;
}

int main(){
    setlocale(LC_ALL, "");
//==========================================================================LOGIN=============================================================================
  log:

  if (login() == 0){
   goto menu;
  }
  else{
   goto log;
  }

//=========================================================================MENU===============================================================================
menu:
    system("mode con:cols=80 lines=30");
    system("cls");
    int menuop;
    printf("\n\n\n\n\n                            __________MENU__________ "
    "\n\n                            1 - CADASTRO DE CLIENTES"
    "\n                            2 - AGENDAMENTO"
    "\n                            3 - RELATORIOS MEDICOS"
    "\n                            4 - FUNCIONARIOS"
    "\n                            5 - FATURAMENTO"
    "\n                            6 - FEEDBACK"
    "\n                            ________________________"
    "\n\n                            DIGITE UMA OPÇÃO: ");
    scanf("%i", &menuop);
    switch(menuop){
       case 1: goto submenu; break;
       case 2: goto subagen; break;
       case 3: goto subrela; break;
       case 4: break;
       case 5: break;
       case 6: break;
       default: goto menu; break; }
//=================================================================SISTEMA DE CADASTRO========================================================================
submenu:
    system("cls");
    int opcad;
    printf("\n\n\n\n\n                            _______CADASTRO_______ "
    "\n\n                            1 - CADASTRAR"
    "\n                            2 - BUSCA"
    "\n                            3 - EXCLUIR CADASTRO"
    "\n                            4 - VOLTAR"
    "\n                            ______________________"
    "\n\n                            DIGITE UMA OPÇÃO: ");
    scanf("%i", &opcad);
    switch(opcad){
       case 1: if (cadastro() == 0){
               goto submenu; };
               break;
       case 2: if (busca() == 0){
               goto submenu; };
               break;
       case 3: if (excluir() == 0){
               goto submenu; };
               break;;
       case 4: goto menu; break;
       default: printf("\n                            INVALIDO");
                sleep(2);
                goto submenu; break; }
//=======================================================================AGENDAMENTO==========================================================================
subagen:
    system("cls");
    int opagen;
    printf("\n\n\n\n\n                            _______AGENDAMENTO_______ "
    "\n\n                            1 - AGENDAR"
    "\n                            2 - LISTAR AGENDAMENTO"
    "\n                            3 - VOLTAR"
    "\n                            _________________________"
    "\n\n                             DIGITE UMA OPÇÃO: ");
    scanf("%i", &opagen);
     switch(opagen){
        case 1: if (agendar() == 0){
                goto submenu; };
                break;
        case 2: if (busca() == 0){
                goto submenu; };
                break;
        case 3: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OPÇÃO VALIDA");
          goto subagen; break; }
//=====================================================================RELATORIO MEDICO=======================================================================
//SUBMENU RELATORIOS
subrela:
    system("cls");
    int oprela;
    printf("\n\n\n\n\n                            _________________________ "
    "\n\n                            1 - CRIAR RELATORIO"
    "\n                            2 - BUSCA"
    "\n                            3 - EXCLUIR RELATORIO"
    "\n                            4 - VOLTAR"
    "\n                            _________________________"
    "\n\n                             DIGITE UMA OPÇÃO: ");
    scanf("%i", &oprela);
     switch(oprela){
        case 1: if (relatorios() == 0){
                goto submenu; };
                break;
        case 2: if (busca() == 0){
                goto submenu; };
                break;
        case 3: if (excluir() == 0){
                goto submenu; };
                break;;
        case 4: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OPÇÃO VALIDA");
          goto subrela; break; }
//====================================================================FUNCIONARIOS============================================================================

}

