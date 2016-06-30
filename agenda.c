#include <stdlib.h>
#include <stdio.h>

FILE * abrir_arquivo(char modo, char caminho[30]){
    FILE * arquivo;
    if (modo == 'g'){
        arquivo = fopen(caminho,"wt");
    }
    if (modo == 'l'){
        arquivo = fopen(caminho,"rt");
    }
    if (modo == 'a'){
        arquivo = fopen(caminho,"a");
    }
    if(arquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
        exit(0);
    }
    return arquivo;
}

void fechar_arquivo(FILE *arquivo){
    fclose(arquivo);
}

void incluir_aluno(char nome[100], int p1, int p2, int t1, int t2, int t3, int pt1, int pt2, int pt3){
    FILE * arquivo;
    arquivo = abrir_arquivo('a', "agenda.txt");
    fprintf(arquivo, "%s %d %d %d %d %d %d %d %d\n", nome, p1, p2, t1, t2, t3, pt1, pt2, pt3);
}

void listar_alunos(){
    FILE * arquivo;
    int p1, p2, t1, t2, t3, pt1, pt2, pt3, contador = 1;
    char nome[100];
    arquivo = abrir_arquivo('l', "agenda.txt");
    while (!feof(arquivo)){
        fscanf(arquivo, "%s %d %d %d %d %d %d %d %d ", &nome, &p1, &p2, &t1, &t2, &t3, &pt1, &pt2, &pt3);
        printf("ALUNO %d\n", contador);
        printf("Nome: %s\n", nome);
        printf("Nota na P1: %d\n", p1);
        printf("Nota na P2: %d\n", p2);
        printf("Nota no Trabalho 1: %d\n", t1*(11-pt1)/10);
        printf("Nota no Trabalho 2: %d\n", t2*(11-pt2)/10);
        printf("Nota no Trabalho 3: %d\n", t3*(11-pt3)/10);
        printf("Media das provas: %d\n", (p1+p2)/2);
        printf("Media dos trabalhos: %d\n\n", ((t1*(11-pt1)/10)+(t1*(11-pt1)/10)+t1*(11-pt1)/10)/3);
        printf("            -\\-           \n\n");
        contador++;
    }
    fechar_arquivo(arquivo);
}

void remover_aluno(int linha){

}

int main(){
    int opc, p1, p2, t1, t2, t3, pt1, pt2, pt3, linha;
    char nome[100];
    do{
        system("cls");
        printf("\t\t\t\tBEM VINDO(A) AO GERENCIADOR DE NOTAS!\n\n");
        printf("(1) - Incluir aluno\n(2) - Consultar aluno\n(3) - Remover aluno\n(4) - Sair\n");
        printf("\nDigite o que deseja fazer: ");
        scanf("%d", &opc);
        system("cls");
        if(opc == 1){
            printf("Nome: ");
            setbuf(stdin, NULL);
            gets(nome);
            printf("Nota P1: ");
            scanf("%d", &p1);
            printf("\n");
            printf("Nota P2: ");
            scanf("%d", &p2);
            printf("\n");
            printf("Trabalho 1: ");
            scanf("%d", &t1);
            printf("\n");
            printf("Lugar no grupo: ");
            scanf("%d", &pt1);
            printf("\n");
            printf("Trabalho 2: ");
            scanf("%d", &t2);
            printf("\n");
            printf("Lugar no grupo: ");
            scanf("%d", &pt2);
            printf("\n");
            printf("Trabalho 3: ");
            scanf("%d", &t3);
            printf("\n");
            printf("Lugar no grupo: ");
            scanf("%d", &pt3);
            printf("\n");
            incluir_aluno(nome, p1, p2, t1, t2, t3, pt1, pt2, pt3);
            system("pause");
        }
        if(opc == 2){
            listar_alunos();
            system("pause");
        }
        if(opc == 3){
            printf("Digite o numero do aluno que quer remover: ");
            scanf("%d", &linha);
            remover_aluno(linha);
            system("pause");
        }
    }while(opc != 4);
    return 0;
}
