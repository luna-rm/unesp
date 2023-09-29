#include<stdio.h>
#include<windows.h>  
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} var_para_tirar_erro;

typedef struct musica {
    char nome[30];
    char artista[30];
    char album[30];
    int tempo;
    boolean status;
    struct data lancamento;
} var_para_tirar_erro_2;

void ajuda(){
    FILE * help = fopen("help.txt", "rt");
    char caracter;
    system("cls");
    while (!feof(help)) {
    caracter = getc(help);
    printf ("%c",caracter);
    }
    printf("\n\n\nPressione qualquer tecla para voltar...");
    getch();
    return 0;
  fclose(help);
}

void sair(){
    
    excluir();
    exit(1);
    
    
}


void final(FILE *arquivo){
    printf("\n\nPressione qualquer tecla para voltar ao menu");
    getch();
    fclose(arquivo);
    system("cls");
}

void gotoxy(int x, int y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor(int aux) {
    CONSOLE_CURSOR_INFO cursor = {1, aux};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void menu(){
    gotoxy(3,2);
    printf("  Cadastrar arquivo");
    gotoxy(3,3);
    printf("  Alterar arquivo");
    gotoxy(3,4);
    printf("  Apagar musica");
    gotoxy(3,5);
    printf("  Consultar arquivo");
    gotoxy(3,6);
    printf("  Ver todas as musicas cadastradas");


    printf("\n\n     (Aperte F1 para ajuda)");
    printf("\n\n     (Aperte ESC para sair)");

}

int setinha(){
    char seta;
    int aux = 2;
    gotoxy(1,2);
    printf("->");

    do{
        seta = getch();

        if(seta<=0){
            seta = getch();
            if(seta == 59){
                ajuda();
            }
        }
        switch(seta) {
            case 72:
                if(aux!=2) {
                    gotoxy(1,aux);
                    printf("  ");
                    aux--;
                    gotoxy(1,aux);
                    printf("->");
                } else {
                    gotoxy(1,aux);
                    printf("  ");
                    aux=6;
                    gotoxy(1,aux);
                    printf("->");
                }
                break;

            case 80:
                if(aux!=6) {
                    gotoxy(1,aux);
                    printf("  ");
                    aux++;
                    gotoxy(1,aux);
                    printf("->");
                } else {
                    gotoxy(1,aux);
                    printf("  ");
                    aux = 2;
                    gotoxy(1,aux);
                    printf("->");
                }
                break;

            case 13:
                if(aux>=2 && aux<=6) {
                    system("cls");
                    gotoxy(0,0);
                }
                break;
            
            case 27:
                system("cls");
                sair();
                break;

            
        }
    } while(seta!=13);

    return aux;
}

void cadastra(){
    fflush(stdin);
    cursor(1);

    FILE * arquivo = fopen("arq.dat" , "a+b");
    
    if(!arquivo){
        printf("\nNao possivel abrir o arquivo :(");
        printf("\nPressione qualquer tecla para voltar ao menu");
        getch();
        system("cls");
        return;
    }

    struct musica music;
    music.status=TRUE;

    printf("\nNome da Musica: ");
    gets(music.nome);

    fclose(arquivo);
    arquivo = fopen("arq.dat", "r+b");
    
    struct musica music_aux;
    while(fread(&music_aux, sizeof(music_aux), 1, arquivo)){
        if(!strcmp(music.nome, music_aux.nome)){
            if(!music_aux.status){
                char resp;
                printf("\nMusica ja existente porem desativada\n");
                printf("Deseja reativa-la? (s/n) ");
                resp = getchar();

                if(toupper(resp) == 'S'){                    
                    music_aux.status = TRUE;
                    fseek(arquivo, -sizeof(music_aux), SEEK_CUR);
                    fwrite(&music_aux, sizeof(music_aux), 1, arquivo);
                    system("cls");
                    printf("\nMusica reativada com sucesso");
                    final(arquivo);
                    return;
                }
                else {
                    system("cls");
                    return;
                }
            }
            printf("\nMusica ja Existente");
            final(arquivo);
            return;
        }
    }

    fclose(arquivo);
    arquivo = fopen("arq.dat", "a+b");
    
    if(!arquivo){
        printf("\nNao possivel abrir o arquivo :(");
        printf("\nPressione qualquer tecla para voltar ao menu");
        getch();
        system("cls");
        return;
    }

    printf("\nArtista: ");
    gets(music.artista);
        
    printf("\nAlbum: ");
    gets(music.album);
        
    printf("\nDuracao: ");
    scanf("%d", &music.tempo);
    
    printf("\nData de Lancamento (dd/mm/aa): ");
    scanf("%d/%d/%d", &music.lancamento.dia, &music.lancamento.mes, &music.lancamento.ano);

    fwrite(&music, sizeof(music), 1, arquivo);
    fflush(stdin);

    char resp;
    printf("\n\nAdicionar outra musica (s/n)?: ");
    resp=toupper(getchar());
    system("cls");

    if(resp == 'S'){
        cadastra();
    }

    fclose(arquivo);
}

void ver_todas(){
    fflush(stdin);
    struct musica music;
    int aux=0;
    char opp;
 
    FILE *arquivo = fopen("arq.dat", "rb");

    if(!arquivo){
        printf("\nNao possivel abrir o arquivo :(");
        printf("\nPressione qualquer tecla para voltar ao menu");
        getch();
        system("cls");
        return;
    }

    while(fread(&music, sizeof(music), 1, arquivo)){
        if(!music.status){
            continue;
        }
        printf("Nome da Musica: %s", music.nome);
        printf("\nArtista: %s", music.artista);
        printf("\nAlbum: %s", music.album);
        printf("\nDuracao: %d", music.tempo);
        printf("\nData de lancamento: %d/%d/%d", music.lancamento.dia, music.lancamento.mes, music.lancamento.ano);
        printf("\n\n");
        aux ++;
    }

    if(aux==0){
        system("cls");
        printf("Nenhuma musica cadastrada ate o momento :(\n");
        printf("\nAperte C para cadastrar uma musica ou ENTER para voltar ao menu\n\n");
        opp = getch();
        system("cls");
        if(opp=='C' || opp=='c'){
            cadastra();
        }
        else
            system("cls");
            return;
    }

    final(arquivo);
}

void consultar(){
    fflush(stdin);
    struct musica music;
    char busca[30], op;
 
    FILE *arquivo = fopen("arq.dat", "rb");

    if(!arquivo){
        printf("\nNao possivel abrir o arquivo :(");
        printf("\nPressione qualquer tecla para voltar ao menu");
        getch();
        system("cls");
        return;
    }

    printf("Consultar por:\n");
    printf("\n1-Nome da Musica");
    printf("\n2-Artista");
    printf("\n3-Album");
    printf("\n\nOpcao escolhida: ");
    op=getch();
    fflush(stdin);

    system("cls");

    if(op=='1'){
        printf("\nDigite o nome: ");
    }
    else if(op=='2'){
        printf("\nDigite o artista: ");
    }
    else if(op=='3'){
        printf("\nDigite o album: ");
    }
    
    gets(busca);

    int aux=0;

    while(fread(&music, sizeof(music), 1, arquivo)){
        if(!music.status){
            continue;
        }
        if(op=='1'){
            if(strcmp(busca,music.nome)){
                continue;
            }
        }
        if(op=='2'){
            if(strcmp(busca,music.artista)){
                continue;
            }
        }
        if(op=='3'){
            if(strcmp(busca,music.album)){
                continue;
            }
        }
        
        aux++;
        printf("\nNome da Musica: %s", music.nome);
        printf("\nArtista: %s", music.artista);
        printf("\nAlbum: %s", music.album);
        printf("\nDuracao: %d", music.tempo);
        printf("\nData de lancamento: %d/%d/%d", music.lancamento.dia, music.lancamento.mes, music.lancamento.ano);
        printf("\n");
    }
    
    if(aux==0){
        printf("Musica nao Encontrada");
    }

    final(arquivo);
}

void excluir(){
    fflush(stdin);
    struct musica music;

    FILE *arquivo = fopen("arq.dat", "ab" );
    FILE *temp = fopen("aux.dat", "w" );
    
    while(fread(&music, sizeof(music), 1, arquivo)){
        if(!music.status==FALSE){
            fwrite(&music, sizeof(music), 1, temp);
        }
    }
    fclose(temp);
    fclose(arquivo);
    remove("arq.dat");
    rename("aux.dat", "arq.dat");
    
    
}

void apagar_musica(){
    fflush(stdin);
    struct musica music;
    char nome[30];
    FILE * arquivo = fopen("arq.dat", "r+b");

    if(!arquivo){
        printf("\nNao possivel abrir o arquivo :(");
        printf("\nPressione qualquer tecla para voltar ao menu");
        getch();
        system("cls");
        return;
    }

    printf("Digite o nome da musica que deseja excluir: ");
    gets(nome);

    int aux=1;
    while(fread(&music, sizeof(music), 1, arquivo)){
        if(strcmp(nome, music.nome)){
            continue;
        }
        aux=0;
        music.status = FALSE;
        break;
    }
    if(aux!=0){
        printf ("\nNao foi possivel excluir a musica.");
        final(arquivo);
        return;
    }
    fseek(arquivo, -sizeof(music), SEEK_CUR);
    fwrite(&music, sizeof(music), 1, arquivo);

    printf ("\nMusica foi excluida com sucesso.");
    final(arquivo);
}

void alterar(){
    fflush(stdin);
    struct musica music;

    char op, name[30], resp;
    FILE *arquivo = fopen("arq.dat", "r+b");

    system("cls");
    printf("Qual musica precisa ser alterada?");
    printf("\nDigite o nome da musica: ");
    gets(name);

    int aux=1;
    while(fread(&music, sizeof(music), 1, arquivo)){
        if(!strcmp(name, music.nome)){
            aux=0;
            break;
        }
    }
    if(aux==1){
        printf("Musica nao encontrada");
        final(arquivo);
        return;
    }

    system("cls");
    
    printf("Qual informacao precisa ser alterada?\n");
    printf("\n1-Nome da Musica");
    printf("\n2-Artista");
    printf("\n3-Album");
    printf("\n4-Duracao");
    printf("\n5-Data de Lancamento");
    printf("\n\nOpcao escolhida: ");
    op=getch();
    fflush(stdin);

    system("cls");

    if(op=='1'){
        printf("Nome atual: %s", music.nome);
        printf("\nNovo nome: ");
        gets(music.nome);
    }
    else if(op=='2'){
        printf("Artista atual: %s", music.artista);
        printf("\nNovo artista: ");
        gets(music.artista);
    }
    else if(op=='3'){
        printf("Album atual: %s", music.album);
        printf("\nNovo album: ");
        gets(music.album);
    }
    else if(op=='4'){
        printf("Duracao atual: %d", music.tempo);
        printf("\nNova duracao: ");
        scanf("%d", &music.tempo);
        fflush(stdin);
    }
    else if(op=='5'){
        printf("Data de lancamento atual: %d/%d/%d", music.lancamento.dia, music.lancamento.mes, music.lancamento.ano);
        printf("\nNova data (dd/mm/aa): ");
        scanf("%d/%d/%d", &music.lancamento.dia, &music.lancamento.mes, &music.lancamento.ano);
        fflush(stdin);
    }
    
    fseek(arquivo, -sizeof(music), SEEK_CUR);
    fwrite(&music, sizeof(music), 1, arquivo);
    printf("\nDeseja alterar mais dados? (s/n) ");

    resp=toupper(getchar());
    if(resp == 'S'){
        alterar();
    }
    final(arquivo);
}

int main() {    
    while(1) {
        cursor(0);
        printf("Cosmofy BD");

        int what;
        menu();
        what = setinha();
        
        if(what == 2) {
            cadastra();
        }
        else if(what == 3) { 
            alterar();
        }
        else if(what == 4) { 
            apagar_musica();
        }
        else if(what == 5) { 
            consultar();
        }
        else if(what == 6) { 
            ver_todas();
        }

    }

    return 0;
}