#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "");
    system("mode con:cols=80 lines=25");
//=============================================================================
//                                   LOGIN
//=============================================================================
     login:
     system("color 0f");
     system("cls");
     int a = 12345;
     printf("\n\n\n\n\n\n\n                               ______LOGIN______");
     printf("\n\n                               USUARIO:UNIDADE_1");
     printf("\n                               SENHA: ");
     scanf("%i", &a);

     if (a != 12345){
       system("cls");
       system("color 4f");
       printf("\n\n\n\n\n\n\n\n\n                               SENHA INCORRETA");
       sleep(1);
       goto login;
     }
     else{
       goto menu;
     }
//=============================================================================
//                                    MENU
//=============================================================================
    menu:
    system("color 70");
    system("cls");
    int menuop;
    printf("\n\n\n\n                            __________MENU__________ ");
    printf("\n\n                            1 - CADASTRO DE CLIENTES");
    printf("\n                            2 - AGENDAMENTO");
    printf("\n                            3 - RELATORIOS MEDICOS");
    printf("\n                            4 - FUNCIONARIOS");
    printf("\n                            5 - FATURAMENTO");
    printf("\n                            6 - FEEDBACK");
    printf("\n                            ________________________");
    printf("\n\n                            DIGITE UMA OP��O: ");
    scanf("%i", &menuop);
    switch(menuop){
     case 1:
       goto submenu;
       break;
     case 2:
       goto subagen;
       break;
     case 3:
       break;
     case 4:
       break;
     case 5:
       break;
     case 6:
       break;
    }
//=============================================================================
//                            SISTEMA DE CADASTRO
//=============================================================================
    //SUBMENU
    submenu:
    system("cls");
    int opcad;
    printf("\n\n\n\n                            _______CADASTRO_______ ");
    printf("\n\n                            1 - CADASTRAR");
    printf("\n                            2 - BUSCA");
    printf("\n                            3 - EXCLUIR CADASTRO");
    printf("\n                            3 - VOLTAR");
    printf("\n                            ______________________");
    printf("\n\n                            DIGITE UMA OP��O: ");
    scanf("%i", &opcad);
    switch(opcad){
       case 1:
         goto cadastro;
         break;
       case 2:
         goto busca;
         break;
       case 3:
         goto excluird;
         break;
       case 4:
         goto menu;
         break;
       default:
         printf("\n                            INVALIDO");
         sleep(2);
         goto submenu;
         break;
    }
    //CADASTRO
    cadastro:
    system("cls");
    FILE *file;
    char n[100], cpf[12], cell[20], email[100], end[100], bus[100], f[100];

    printf("\n\n___________________________________CADASTRAR____________________________________");
       //NOME
       printf("\n\n                  NOME: ");
       gets(n);
       gets(n);
       file = fopen(n, "wb");

       fprintf(file,"\n               NOME: ");
       fprintf(file, n);
       //CPF
       printf("\n                  CPF: ");
       gets(cpf);
       fprintf(file,"\n               CPF: ");
       fprintf(file, cpf);
       //TELEFONE
       printf("\n                  TELEFONE: ");
       gets(cell);
       fprintf(file,"\n               TELEFONE: ");
       fprintf(file, cell);
       //EMAIL
       printf("\n                  EMAIL: ");
       gets(email);
       fprintf(file,"\n               EMAIL: ");
       fprintf(file, email);
       //ENDERE�O
       printf("\n                  ENDERE�O: ");
       gets(end);
       fprintf(file,"\n               ENDERE�O: ");
       fprintf(file, end);
       fclose(file);
       sleep(1);
       goto submenu;

       //BUSCA
       busca:
       system("cls");
       printf("\n\n_____________________________________BUSCA______________________________________");
       printf("\n\n               DIGITE O NOME: ");
       gets(bus);
       gets(bus);
       file = fopen(bus, "r");
        //LEITURA DO ARQUIVO
        if (file == NULL){
        printf("\n\n               N�O ENCONTRADO\n");
        sleep(2);
        goto busca;
    }
        while(fgets(f, 100, file) != NULL){
        printf("%s", f);
    }
        fclose(file);
    //LOOP
    int opbus;
    printf("\n\n________________________________________________________________________________");
    printf("\n\n               DIGITE 1 PARA VOLTAR: ");
    scanf(" %c", &opbus);
    switch(opbus){
    case 1:
      goto menu;
      break;
    default:
      goto menu;
      break;
    }
      //EXCLUIR CADASTRO
      excluird:
      system("cls");
      int del;
      FILE *fp;
      char nome[100];
        printf("\n\n________________________________EXCLUIR DADOS____________________________________");
        printf("\n              -NOME  E DATA PARA CANCELAR AGENDAMENTO ");
        printf("\n              -APENAS O NOME PARA EXCLUIR CADASTRO ");
        printf("\n\n               DIGITE O NOME PARA DELETAR: ");
        gets(nome);
        gets(nome);

      fp = fopen(nome, "w");

      fprintf(fp, "%s", " ");
      fclose(fp);

      del = remove(nome);

      if(del == 0) {
      printf("                         DADOS DELETADOS COM SUCESSO");
      } else {
      printf("                         ERRO, DADOS NAO EXISTENTE");
      }
       //LOOP EXCLUIR
      int opdel;
       printf("\n\n________________________________________________________________________________");
       printf("\n\n               DIGITE 1 PARA VOLTAR: ");
       scanf(" %c", &opdel);
      switch(opdel){
      case 1:
        goto menu;
        break;
      default:
        goto menu;
        break;
    }
//=============================================================================
//                                 AGENDAMENTO
//=============================================================================
    subagen:
    system("cls");
    int opagen;
    printf("\n\n\n\n                            _______AGENDAMENTO_______ ");
    printf("\n\n                            1 - AGENDAR");
    printf("\n                            2 - BUSCA");
    printf("\n                            3 - CANCELAR AGENDAMENTO");
    printf("\n                            3 - VOLTAR");
    printf("\n                            _________________________");
    printf("\n\n                             DIGITE UMA OP��O: ");
    scanf("%i", &opagen);
    switch(opagen){
      case 1:
    //AGENDAMENTO
    system("cls");
    FILE *file;
    char nd[100], hr[12];

    printf("\n\n___________________________________AGENDAR______________________________________");
       //NOME E DATA
       printf("\n\n                  NOME E DATA: ");
       gets(nd);
       gets(nd);
       file = fopen(nd, "wb");

       fprintf(file,"\n               NOME E DATA: ");
       fprintf(file, nd);
       //HORARIO
       printf("\n                  HORARIO: ");
       gets(hr);
       fprintf(file,"\n               HORARIO: ");
       fprintf(file, hr);

       fclose(file);
       sleep(1);
       goto submenu;
        break;
      case 2:
        break;
      case 3:
        sleep(3);
        system("color f0");
        goto excluird;
        break;
      case 4:
        break;
      default:
        break;
    }


}

