#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
//============================================================================================================================================================
//                                                                           LOGIN
//============================================================================================================================================================
     user:
     system("mode con:cols=80");
     system("cls");
     char user[4],senha[4];
     printf("\n\n\n\n\n\n\n                               ______LOGIN______"
            "\n\n                               USUARIO: ");
     scanf("%s", &user);
      if(strcmp(user, "admin") == 0){ goto senha; }
        else{  system("color 4f", "cls");
               printf("\n\n\n\n\n\n\n\n\n                               SENHA INCORRETA");
               sleep(1);
               goto user; }
     senha:
     printf("\n                               SENHA: ");
     scanf("%i", &senha);
      if(strcmp(senha, "12345")){ goto menu; }
       else{  system("cls", "color 4f");
              printf("\n\n\n\n\n\n\n\n\n                               SENHA INCORRETA");
              sleep(1);
              goto user;}
//============================================================================================================================================================
//                                                                          MENU
//============================================================================================================================================================
    menu:
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
//============================================================================================================================================================
//                                                                 SISTEMA DE CADASTRO
//============================================================================================================================================================
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
       case 1: goto cadastro; break;
       case 2: goto busca; break;
       case 3: goto excluird; break;
       case 4: goto menu; break;
       default: printf("\n                            INVALIDO");
                sleep(2);
                goto submenu; break; }
    //CADASTRO
    cadastro:
    system("cls");
    FILE *file;
    char n[100], cpf[12], cell[20], email[100], end[100], bus[100], f[100];

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
       goto submenu;

       //BUSCA
       busca:
       system("cls");
       printf("\n\n_____________________________________BUSCA______________________________________");
       printf("\n\n              AGENDAMENTO - NOME  E DATA ");
       printf("\n              CADASTRO - APENAS O NOME ");
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
    printf("\n\n________________________________________________________________________________");
        printf("\n               DIGITE 1 PARA VOLTAR OU 2 PARA NOVA BUSCA ");
        scanf("%i", &opbusca);
         switch(opbusca){
            case 1: goto menu; break;
            case 2: goto busca; break;
            default: goto menu; break; }

        fclose(file);
      //EXCLUIR CADASTRO
      excluird:
      system("cls");
      int del;
      FILE *fp;
      char nome[100];
        printf("\n\n________________________________EXCLUIR DADOS____________________________________"
        "\n              AGENDAMENTO - NOME  E DATA
        "\n              CADASTRO - APENAS O NOME "
        "\n              RELATORIO - NOME + 'R'"
        "\n\n              DIGITE O NOME PARA DELETAR: ");
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
           case 1: goto menu; break;
           default: goto menu; break; }
//============================================================================================================================================================
//                                                                       AGENDAMENTO
//============================================================================================================================================================
    subagen:
    system("cls");
    int opagen;
    printf("\n\n\n\n\n                            _______AGENDAMENTO_______ "
    "\n\n                            1 - AGENDAR"
    "\n                            2 - BUSCA"
    "\n                            3 - CANCELAR AGENDAMENTO"
    "\n                            4 - VOLTAR"
    "\n                            _________________________"
    "\n\n                             DIGITE UMA OPÇÃO: ");
    scanf("%i", &opagen);
     switch(opagen){
        case 1: goto agendar; break;
        case 2: goto busca; break;
        case 3: goto excluird; break;
        case 4: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OPÇÃO VALIDA");
          goto subagen; break; }

    //AGENDAMENTO
    agendar:
    system("cls");
    FILE *a;
    char nd[100], hr[12];
    printf("\n\n___________________________________AGENDAR______________________________________");
       //NOME E DATA
       printf("\n\n                  NOME E DATA: ");
       scanf("%s", &nd);
       a = fopen(nd, "wb");

       fprintf(a,"\n               NOME E DATA: ");
       fprintf(a, nd);
       //HORARIO
       printf("\n                  HORARIO: ");
       scanf("%s", &hr);
       fprintf(a,"\n               HORARIO: ");
       fprintf(a, hr);

       fclose(a);
       sleep(1);
       goto submenu;

//============================================================================================================================================================
//                                                                    RELATORIO MEDICOS
//============================================================================================================================================================
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
        case 1: goto relatorios; break;
        case 2: goto busca; break;
        case 3: goto excluird; break;
        case 4: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OPÇÃO VALIDA");
          goto subrela; break; }

    relatorios:
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
       goto menu;
//============================================================================================================================================================
//                                                                    FUNCIONARIOS
//============================================================================================================================================================


}

