#include <stdio.h>
#include <locale.h>

//FUN��O LOGIN __________________________________________________________________________________
login(){
   setlocale(LC_ALL, "");
   inicio:
     system("cls");
     system("color 0f");
     system("mode con:cols=80 lines=30");

     char user[4], senha[4], s, u;

     printf("\n\n\n\n\n\n\n                               ______LOGIN______"
            "\n\n                               USUARIO: ");
     scanf("%s", &user);
     printf("\n                               SENHA: ");
     scanf("%s", &senha);
     u = strcmp(user, "admin" );
     s = strcmp(senha, "12345");
     if(u && s == 0){
         return 0; }
     else{  system("color 4f");
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n                           USUARIO OU SENHA INCORRETO");
            sleep(1);
            goto inicio; }
}
//FUN��O CADASTRO _______________________________________________________________________________
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
       //ENDERE�O
       printf("\n                  ENDERE�O: ");
       scanf("%s", &end);
       fprintf(file,"\n               ENDERE�O: ");
       fprintf(file, end);
       fclose(file);
       sleep(1);
       return 0;
}
//FUN��O BUSCA __________________________________________________________________________________
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
        printf("\n\n               N�O ENCONTRADO");

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
//FUN��O EXCLUIR __________________________________________________________________________________
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
        "\n________________________________________________________________________________"
        "\n              ");
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

//FUN��O AGENDAR __________________________________________________________________________________
agendar(){
   setlocale(LC_ALL, "");
   system("cls");
    char nm[100], dia[100], horario[100], mes[100];
    FILE *p;
    printf("\n\n___________________________________AGENDAR______________________________________"
    "\n\n     -EM CASO DE REMARCA�AO DE AGENDAMENTO DIGITE REMARCADO JUNTO DO HORARIO"
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
      return 0;
}
//FUN��O VALOR DA CONSULTA __________________________________________________________________________________
valor(){
    setlocale(LC_ALL, "");
    system("cls");
     char mss[100], val;
    FILE *v;
    printf("\n\n__________________________________PAGAMENTO_____________________________________"
    "\n\n     DIGITE O MES EM SEGUIDA UM F\n     ex: janeirof"
    "\n________________________________________________________________________________"
    "\n\n     MES: ");
    scanf("%s", &mss);
    v = fopen(mss, "a");

    printf("\n     VALOR DA CONSULTA: ");
    scanf("%s", &val);

    fprintf(v, &val);
    fprintf(v, "\n");
    fclose(v);
    return 0;
}
//FUN��O RELATORIOS __________________________________________________________________________________
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
//FUN��O FUNCIONARIO __________________________________________________________________________________
funcionarios(){
   setlocale(LC_ALL, "");
    system("cls");
    char fun[100], dat[100], sal[100], nm[100], cpf[100];
    FILE *p;
    printf("\n\n_________________________________FUNCIONARIOS___________________________________"
           "\n\n     NOME: ");
    scanf("%s", &nm);

    p = fopen(nm, "a");
    printf("\n     FUN��O: ");
    scanf("%s", &fun);
    printf("\n     DATA DE INICIO: ");
    scanf("%s", &dat);
    printf("\n     SALARIO: ");
    scanf("%s", &sal);
    printf("\n     CPF: ");
    scanf("%s", &cpf);

    fprintf(p,"\n    NOME: ");
    fprintf(p, nm);
    fprintf(p,"\n    FUN��O: ");
    fprintf(p, fun);
    fprintf(p,"         DATA DE INICIO: ");
    fprintf(p, dat);
    fprintf(p,"         SALARIO: ");
    fprintf(p, sal);
    fprintf(p,"         CPF: ");
    fprintf(p, cpf);

    fprintf(p, "\n");

    fclose(p);
    sleep(1);
    return 0;
}
//FUN��O FATURAMENTO __________________________________________________________________________________
faturamento(){
  setlocale(LC_ALL, "");
  system("cls");
  char n[100];
   printf("\n\n_________________________________FATURAMENTO____________________________________"
   "\n\n     DIGITE O MES EM SEGUIDA UM F\n     ex: janeirof"
   "\n________________________________________________________________________________"
   "\n\n    Didite o mes: ");
   scanf("%s", &n);
   FILE *v;
   v = fopen (n, "r");
   if (v == NULL) {
      printf ("\n     NAO ENCONTRADO O ARQUIVO!\n");
   }
   float soma = 0;
   while (!feof( stdin )) {
      int x;

      if (fscanf (v, "%i", &x) != 1) break;
      soma += x;
   }
   fclose (v);
   printf ("\n     O FATURAMENTO DO MES REFERENTE FOI DE R$ %.2f\n", soma);
   int a;
   printf("\n     DIGITE ALGO PARA SAIR: ");
   scanf("%i", &a);
   return 0;
}
//FUN��O FEEDBACK __________________________________________________________________________________
feedback(){
      setlocale(LC_ALL, "");
   system("cls");
    char nm[100], dia[100], coment[100], ava[100];
    FILE *p;
    printf("\n\n___________________________________FEEDBACK_____________________________________"
    "\n\n     1 - MUITO BOM \n     2 - BOM \n     3 - REGULAR \n     4 - RUIM \n     5 - PESSIMO "
    "\n________________________________________________________________________________"
    "\n\n     AVALIA��O: ");
    scanf("%s", &ava);

      p = fopen(ava, "a");
      printf("\n     NOME: ");
      scanf("%s", &nm);
      printf("\n     DIA: ");
      scanf("%s", &dia);
      printf("\n     COMENTARIOS: ");
      scanf("%s", &coment);

      fprintf(p,"          AVALIA��O: ");
      fprintf(p,     ava);
      fprintf(p,"\n     NOME: ");
      fprintf(p, nm);
      fprintf(p,"          DIA: ");
      fprintf(p,     dia);
      fprintf(p,"          HORARIO: ");
      fprintf(p,     coment);
      fprintf(p, "\n");

      fclose(p);
      sleep(1);
      return 0;
}

int main(){
    setlocale(LC_ALL, "");
//CHAMANDO LOGIN __________________________________________________________________________________
   if (login() == 0){ goto menu; }
//MENU PRINCIPAL__________________________________________________________________________________
menu:
    system("mode con:cols=80 lines=30");
    system("cls");
    int menuop;
    printf("\n\n\n\n\n                            __________MENU___________ "
    "\n\n                            [1]-CADASTRAR FUNCIONARIO"
    "\n                            [2]-CADASTRO DE CLIENTES"
    "\n                            [3]-RELATORIOS MEDICOS"
    "\n                            [4]-AGENDAMENTO"
    "\n                            [5]-FATURAMENTO"
    "\n                            [6]-FEEDBACK"
    "\n                            [7]-BUSCA"
    "\n                            _________________________"
    "\n\n                            DIGITE UMA OP��O: ");
    scanf("%i", &menuop);
    switch(menuop){
       case 1: if (funcionarios() == 0){
               goto menu; };break;
       case 2: goto submenu; break;
       case 3: goto subrela; break;
       case 4: goto subagen; break;
       case 5: if (faturamento() == 0){
               goto menu; };break;
       case 6: if (feedback() == 0){
               goto menu; };  break;
       case 7: if (busca() == 0){
               goto menu; };  break;
       default: goto menu; break; }
//SUBMENU CADASTRO __________________________________________________________________________________
submenu:
    system("mode con:cols=80 lines=30");
    system("cls");
    int opcad;
    printf("\n\n\n\n\n                            _______CADASTRO_______ "
    "\n\n                            [1]-CADASTRAR"
    "\n                            [2]-BUSCA"
    "\n                            [3]-EXCLUIR CADASTRO"
    "\n                            [4]-VOLTAR"
    "\n                            ______________________"
    "\n\n                            DIGITE UMA OP��O: ");
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
//SUBMENU AGENDAMENTO __________________________________________________________________________________
subagen:
    system("mode con:cols=80 lines=30");
    system("cls");
    int opagen;
    printf("\n\n\n\n\n                            _______AGENDAMENTO_______ "
    "\n\n                            [1]-AGENDAR"
    "\n                            [2]-LISTAR AGENDAMENTO"
    "\n                            [3]-VOLTAR"
    "\n                            _________________________"
    "\n\n                             DIGITE UMA OP��O: ");
    scanf("%i", &opagen);
     switch(opagen){
        case 1: if (agendar() == 0){
                if (valor() == 0){
                goto subagen;}}
                break;
        case 2: if (busca() == 0){
                goto subagen; };
                break;
        case 3: goto menu; break;
        default:
          printf("\n               ESCOLHA UMA OP��O VALIDA");
          goto subagen; break; }
//SUBMENU RELATORIOS __________________________________________________________________________________
subrela:
    system("mode con:cols=80 lines=30");
    system("cls");
    int oprela;
    printf("\n\n\n\n\n                            _________________________ "
    "\n\n                            [1]-CRIAR RELATORIO"
    "\n                            [2]-BUSCA"
    "\n                            [3]-EXCLUIR RELATORIO"
    "\n                            [4]-VOLTAR"
    "\n                            _________________________"
    "\n\n                             DIGITE UMA OP��O: ");
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
          printf("\n               ESCOLHA UMA OP��O VALIDA");
          goto subrela; break; }
}


