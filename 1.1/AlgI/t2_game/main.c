/*  
    > Camila Cristina Silva
    > Pedro Ricieri Marchi 
    <3 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAX 4444
#define ENTER 13
#define UP 72
#define DOWN 80

void rand_sleep(int min, int max) {
    int aux = (rand()%(max-min))+min;
    Sleep(aux);
}

void cursor(int aux) {
    CONSOLE_CURSOR_INFO cursor = {1, aux};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void bold(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[!!status]);
}

void italic(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[3m"};
    printf("%s", seq[!!status]);
}

void press_any(){
    italic(1);
    printf("\n\naperte qualquer tecla...");
    getch();
    italic(0);
}

void printf_text(char text[4444], int anim) { 
    int aux = strlen(text) - 1;
	float time = 25;

    if(anim) {
        cursor(1);
        int len_word = 0;
        int c_at = 0;

        for(int j = 0; j < aux; j++){
            len_word++;
            if(text[j] == ' ') {
                break;
            }
        }
        
        for(int i = 0; i < aux; i++){	
            printf("%c", text[i]);
            c_at++;
            
            if(text[i] == ' ') {
                len_word = 0;
                c_at = 0;
                for(int j = i+1; j < aux; j++){
                    len_word++;
                    if(text[j] == ' ') {
                        break;
                    }
                }
                time = 25;
            }
            
            if (text[i] == '\n'){
                PlaySound("sound/space.wav", NULL, SND_FILENAME | SND_ASYNC);
                printf("    ");
                rand_sleep(1000, 1500);
            } else if(i > aux*0.9){
                if(text[i] == ' '){
                    PlaySound("sound/space.wav", NULL, SND_FILENAME | SND_ASYNC);
                    rand_sleep(250, 500);
                } else {
                    if(c_at <= len_word/2){
                        time *= (6./len_word + 1);
                    } else {
                        time /= (6./len_word + 1);
                    }
                    char name_sound[104] = "sound/ktX.wav";
                    name_sound[8] = rand()%7 + '0';

                    PlaySound(name_sound, NULL, SND_FILENAME | SND_ASYNC);
                    rand_sleep((int) (time*0.75), (int) (time*0.75*1.25));
                }
            }		
        }
    } else {
        cursor(0);
        for(int i = 0; i < aux; i++){	
            printf("%c", text[i]);
            
            if (text[i] == '\n'){
                printf("    ");
                rand_sleep(50, 100);
            }
        }
    }

    printf("\n");
}

int read_input(){

    int aux = getch();

    if(aux <= 0 || aux == 224){
        aux = getch();

        if(aux == UP){
            return 1;
        }

        if(aux == DOWN){
            return 2;
        }
    }

    if(aux == ENTER){
        return 3;
    }

    return -1;
}

int choice_point(char text[MAX], int how_many, char opt[10][MAX]) {
    int position = 0;
    
    int aux_input_start = 0;
    while(aux_input_start < 1 || aux_input_start > 3){
        aux_input_start = read_input();
    }

    if(aux_input_start == 3) {
        return position;
    }

    if(aux_input_start == 2) {
        position++;
    }

    while(1) {
        system("cls");

        rand_sleep(100, 200);

        printf_text(text, 0);
        for(int i = 0; i < how_many; i++){
            if(position == i){
                printf("      > ");
            } else {
                printf("        ");
            }
            printf_text(opt[i], 0);
        }

        int aux_input = 0;
        while(aux_input < 1 || aux_input > 3){
            aux_input = read_input();
        }

        if(aux_input == 3){
            return position;
        }

        if(aux_input == 1 && position != 0){
            position--;
        } else if(aux_input == 2 && position != how_many-1) {
            position++;
        }
    }
}

void end(int num) {
    italic(1);

    system("cls");

    bold(1);

    printf("\n");

    if(num == 546) {
        printf_text("FINAL 546 - todos os documentos foram confiscados e voce perdeu a chance de investigar o caso. Voce perdeu o emprego, ja que, sem um mentor, voce naso consegue trabalhar. O detetive continua desaparecido. ", 1);
    } else if(num == 873){
        printf_text("FINAL 873: voce chega a conclusao de que seu mentor estava completamente fora de si e decide parar de se afundar na loucura deixada por ele. Voce tranca o escritorio e vai embora. O detetive continua desaparecido.", 1);
    } else if(num == 667) {
        printf_text("FINAL 667: voce se entrega a #######. Toda sanidade restante em voce se perde e vai para longe juntamente com as palavras sussurradas. Voce entra na lista de desaparecidos, mas ele te encontrou. ", 1);

        press_any();

        rand_sleep(2000, 3000);

        system("cls");

        char date[MAX] = "\?\?/\?\?/\?\? (\?\?:\?\?) ";
        char text[MAX] = "\nAbro os olhos. A sala esta muito escura, demora para meus olhos se adaptarem. Reconheco o escritorio do meu mentor. \n  - 'Eu disse pra deixar os olhos abertos...' \0";

        printf_text(date, 1);
        printf_text(text, 1);

    } else if(num == 972) {
        printf_text("FINAL 972: voce conseguiu um mandado de busca para a casa do sujeito. Nada de suspeito ou incriminador foi encontrado. Voce perdeu a credibilidade no departamento. O detetive continua desaparecido. ", 1);
    } else if(num == 731){
        printf_text("FINAL 731: voce foge. Por algum motivo, os sussurros que voce ouviu naquele lugar te assombram sempre que voce fecha os olhos. Voce nao consegue falar sobre aquilo com ninguem e se isola em sua casa. Os dias passam e voce nao para de pensar se fez a escolha certa ao fugir... O detetive continua desaparecido. ", 1);
    } else if(num == 8){
        printf_text("FINAL 008:\n\nJornal Diario\n\n22/09/92\n\nMais um na lista de desaparecidos.\n\nRaphael Santos, 25 anos, foi oficialmente declarado como desaparecido.\nO jovem, que trabalhava como investigador, foi visto por ultimo saindo de sua residencia no dia 19/09. Cameras de seguranca indicam que ele foi para leste. Seu carro foi encontrado abandonado em um terreno baldio no interior da cidade.\nNao se tem mais noticias do paradeiro do jovem.\n", 1);
        
        press_any();
        system("cls");
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        printf("\n\n\n\n");
        printf("\n                      ........");
        printf("\n                  ....        ....");
        printf("\n               ...       __       ...");
        printf("\n           . ..        __  __        .. .");
        printf("\n               ...       __       ...");
        printf("\n                  ....        ....");
        printf("\n                      ........");

        Sleep(1000);

        exit(0);
    }

    bold(0);

    press_any();

    exit(0);

    italic(0);
}

void eye3(){
    system("cls");
    rand_sleep(100, 200);

    char date[MAX] = "20/09/92 (00:54) ";
    char text[MAX] = "\neh lindo. todos estao aqui. ajoelhados. sussurrando. mascarados.\neu achei. eu finalmente achei.\nele me guiou. un diavolo guida l'altro.\0";

    printf_text(date, 1);
    printf_text(text, 1);

    press_any();
    end(667);
}

void eye2(){
    Sleep(5000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    system("cls");

    char text[MAX] = "\nHoras se passaram. Sinto o olho me observando atentamente. Ele não quer que eu pare...\nEu o vejo sempre que fecho os olhos. Uma caverna? Eu ja vi isso antes...\nPRECISO IR!\0";

    printf_text(text, 1);

    press_any();
    eye3();
}

void eye() {
    system("cls");

    rand_sleep(2000, 3500);
    
    PlaySound("sound/eye.wav", NULL, SND_FILENAME | SND_ASYNC);

    printf("\n\n\n\n");
    printf("\n          ");
    printf("\n          ");
    printf("\n          ");
    printf("\n           . ......................... .");
    printf("\n          ");
    printf("\n          ");
    printf("\n          ");

    Sleep(4000);
    system("cls");

    printf("\n\n\n\n");
    printf("\n          ");
    printf("\n                      .......");
    printf("\n               .......       .......");
    printf("\n           . ..                     .. .");
    printf("\n               .......       .......");
    printf("\n                      .......");
    printf("\n          ");

    Sleep(4000);
    system("cls");

    printf("\n\n\n\n");
    printf("\n          ");
    printf("\n                      .......");
    printf("\n               .......       .......");
    printf("\n           . ..        ______       .. .");
    printf("\n               .......       .......");
    printf("\n                      .......");
    printf("\n          ");

    Sleep(4000);
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

    printf("\n\n\n\n");
    printf("\n                      ........");
    printf("\n                  ....        ....");
    printf("\n               ...       __       ...");
    printf("\n           . ..        __  __        .. .");
    printf("\n               ...       __       ...");
    printf("\n                  ....        ....");
    printf("\n                      ........");

    Sleep(4000);

    Sleep(800);
    printf("                        E");
    Sleep(800);
    printf("U");
    Sleep(800);
    printf(" ");
    Sleep(800);
    printf("T");
    Sleep(800);
    printf("E");
    Sleep(800);
    printf(" ");
    Sleep(800);
    printf("V");
    Sleep(800);
    printf("E");
    Sleep(800);
    printf("J");
    Sleep(800);
    printf("O");
    Sleep(800);
    printf("\n                                                                   N");
    Sleep(800);
    printf("A");
    Sleep(800);
    printf("O");
    Sleep(800);
    printf(" ");
    Sleep(800);
    printf("T");
    Sleep(800);
    printf("E");
    Sleep(800);
    printf("M");
    Sleep(800);
    printf("A");

    for(int i = 0; i < 10; i++) {
        Sleep(10);
        printf("                      ........\n                  ....        ....\n               ...       __       ...\n           . ..        __  __        .. .\n               ...       __       ...\n                  ....        ....\n                      ........                        EU TE VEJO\n                                                                   NAO TEMA");
    }

    Sleep(1333);

    eye2();    
}

void t002() {
    system("cls");
    rand_sleep(200, 500);

    char text[MAX] = "\nVOcE tEM cERteZa?\0";

    char opt[2][MAX] = {"nao ",
                        "sIM "};

    for(int i = 0; i < strlen(text); i++){
        printf("%c", text[i]);
        rand_sleep(100, 300);
    }

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    int ansr = choice_point(text, 2, opt);
    
    system("cls");

    if(ansr == 1) {
        eye();
    } else {
        end(873);
    }
}

void t001() {
    system("cls");
    rand_sleep(200, 500);

    char text[MAX] = "\npor favor nn\0";

    char opt[5][MAX] = {"parar de ler ",
                        "continuar lendo "};

    printf_text(text, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    int position = 0;
    int how_many = 3;
    int aux_input_start = 0;
    while(aux_input_start < 1 || aux_input_start > 3){
        aux_input_start = read_input();
    }

    if(aux_input_start == 3) {
        end(873);
    }

    if(aux_input_start == 2) {
        position++;
        strcpy(opt[position], "parar de ler ");
        strcpy(opt[position+1], "continuar lendo ");
    }

    while(1) {
        system("cls");

        rand_sleep(100, 200);

        printf_text(text, 0);
        for(int i = 0; i < how_many; i++){
            if(position == i){
                printf("      > ");
            } else {
                printf("        ");
            }
            printf_text(opt[i], 0);
        }

        int aux_input = 0;
        while(aux_input < 1 || aux_input > 3){
            aux_input = read_input();
        }

        if(aux_input == 3){
            if(position == 4) {
                t002();
            } else {
                end(873);
            }
        }

        if(aux_input == 1 && position != 0){
            position--;
        } else if(aux_input == 2 && position != how_many-1) {
            position++;
            if(how_many != 5){
                strcpy(opt[position], "parar de ler ");
                strcpy(opt[position+1], "continuar lendo ");
                how_many++;
            }
        }
    }
}

void t000() {
    system("cls");
    rand_sleep(200, 500);

    char date[MAX] = "19/09/92 (16:02) ";
    char text[MAX] = "\nAs proximas paginas estao repletas de rabiscos. Um olho? Um olho com um 'X' em seu centro. Essa imagem me da arrepios que nunca senti antes... nao estou gostando nem um pouco disso, mas uma parte muito forte de mim nao quer parar...\0";

    char opt[2][MAX] = {"Continuar lendo ",
                        "Parar de ler "};

    printf_text(date, 1);
    printf_text(text, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    strcat(date, text);

    int ansr = choice_point(date, 2, opt);
    
    system("cls");

    if(ansr == 0) {
        t001();
    } else {
        end(873);
    }
}

void t00_() {
    system("cls");
    rand_sleep(200, 500);

    char date0[MAX] = "19/09/92 (08:32) ";
    char text0[MAX] = "\nVerifiquei as coordenadas que achei no computador de Carlos. Elas sao de uma casa literalmente no meio do nada. Nao sei se devo segui-las; ou se sequer tenho coragem para isso... \0";

    printf_text(date0, 1);
    printf_text(text0, 1);

    press_any();

    system("cls");
    rand_sleep(200, 500);

    char date1[MAX] = "19/09/92 (13:43) ";
    char text1[MAX] = "\nRefleti um pouco e cheguei a conclusao de que sou um covarde. Ele nao pensaria duas vezes antes de investigar e ca estou eu ha mais de 5 horas lutando para tomar uma decisao.\nEu vou. Preciso entender o que esta acontecendo.\0";

    printf_text(date1, 1);
    printf_text(text1, 1);

    press_any();

    system("cls");
    rand_sleep(200, 500);

    char date2[MAX] = "19/09/92 (15:38) ";
    char text2[MAX] = "\nAcabei de chegar ao endereco; eh um escritorio. Surpreendentemente, ele conseguiu deixar esse lugar ainda mais baguncado do que sua sala. Ha uma quantidade enorme de pedacos de jornais com noticias dos desaparecimentos colados nas paredes e linhas vermelhas que conectam todos eles.\nHa tambem muitos textos. Frases em... italiano? Escrituras antigas e desenhos formam um grande acumulado de poeira em cima da mesa principal. Lendo isso, talvez eu consiga alguma pista de onde ele esta...\0";

    printf_text(date2, 1);
    printf_text(text2, 1);

    press_any();

    system("cls");
    rand_sleep(200, 500);

    char date3[MAX] = "19/09/92 (15:45) ";
    char text3[MAX] = "\nOkay... as primeiras paginas nao fazem sentido algum. As paginas estao escritas em uma linguagem muito antiga e sou obrigado a ler atraves das anotacoes deixadas pelo mentor.\nAs palavras que ele escreveu nao se conectam...\n\nAcho melhor:\0";

    char opt[2][MAX] = {"Continuar lendo ",
                        "Parar de ler "};

    printf_text(date3, 1);
    printf_text(text3, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    strcat(date3, text3);

    int ansr = choice_point(date3, 2, opt);
    
    system("cls");

    if(ansr == 0) {
        t000();
    } else {
        end(873);
    }
}

void cave1(){
    system("cls");
    rand_sleep(200, 500);

    char text[MAX] = "\nDei um passo para dentro daquela escuridao. Me arrependo no segundo seguinte, mas decido nao deixar a covardia tomar conta de mim. Ouco os sussurros ficando mais altos. Um cheiro forte me deixa enjoado; sinto meu estomago revirar. Uma luz ao longe chama minha atencao. Ela crepita, entao assumo ser uma fogueira. Chego mais perto.\nQuando meus olhos se acostumam com a luz, sinto meu corpo estremecer. Corpos ajoelhados em frente a uma parede sao a fonte daquele sussurro lento. Nao consigo identifica-los; tem algo cobrindo suas cabecas... \nPercebo que a parede esta coberta de rabiscos. Sao... olhos? Olhos riscados em vermelho cobrindo praticamente toda sua superficie.\nDou um grito de forma inconsciente. Eles nao movem um musculo; nao parecem notar a minha presenca. \0";
    printf_text(text, 1);
    press_any();

    system("cls");

    char new_text[MAX] = "\nNao sei ao certo o que fazer agora. Me sinto observado... Checo os corpos e eles permanecem na mesma posicao. Olho novamente para a parede e...\n\n...\n\nEles...\nOs olhos...\nOs olhos estao olhando em minha direcao.\n\nMeu instinto me implora para fugir. Corro em direcao a saida, mas ela nao esta mais la. Sinto que estou entrando cada vez mais fundo na caverna. Nao consigo parar de correr e me sinto cada vez mais vigiado. Os desenhos vao ficando maiores e de um vermelho mais intenso.\nUma porta. Eh tudo que consigo enxergar nesse momento. Qualquer resquicio de claridade foi engolido pela escuridao.\nNao tenho escolha. Nao tenho saida.\nEntro. ";
    printf_text(new_text, 1);

    press_any();

    end(8);
}

void cave0(){
    system("cls");
    rand_sleep(200, 500);

    char date[MAX] = "19/09/92 (15:34) ";
    char text[MAX] = "\nConsegui identificar as coordenadas que consegui pelo telefone e cheguei a um lugar que so posso descrever como misterioso. Eh uma... caverna? \nUm arrepio percorre a minha espinha instantaneamente. Posso ouvir algo vindo de dentro. Sao sussurros...\nSinto cada parte do meu corpo implorando para sair de la.\nTenho que tomar uma decisao \0";

    printf_text(date, 1);
    printf_text(text, 1);

    press_any();
    system("cls");

    char new_text[MAX] = "                                  /\n                          _ /\n                       /                  _ _ _\n                  __ /               _  /       /\n             __ /               _  /           /\n           /                  /                   /\n       _/                  /                     /\n     /                    /                         /\n_ __ __ __ ___ _______________________________________\n\0";

    char opt[2][MAX] = {"ir embora ",
                        "entrar na caverna "};

    printf_text(new_text, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    int ansr = choice_point(new_text, 2, opt);
    
    system("cls");

    if(ansr == 0) {
        printf_text("Nao consigo continuar nesse lugar. Eu... eu sinto muito... ", 1);
        press_any();
        end(731);
    } else {
        cave1();
    }
}

void search() {
    system("cls");
    rand_sleep(200, 500);

    char text[MAX] = "Droga... ele desligou. MERDA! Eu estava finalmente chegando perto de conseguir alguma informacao. Talvez eu consiga um mandado de busca se eu explicar a situacao para o departamento... vou rastrear a ligacao e conseguir um endereco. \0";

    printf_text(text, 1);

    cursor(0);

    press_any();

    system("cls");

    end(972);
}

void t010() {
    system("cls");
    rand_sleep(200, 500);

    char text[MAX] = "\nExpliquei tudo o que tinha ate agora o melhor que pude. Contei sobre o arquivo que encontrei no computador do mentor e sobre como ele estava desaparecido. Torci para que ele simpatizasse com a situacao.\nDepois de alguns minutos de monologo da minha parte, o telefone fica em silencio por longos 5 segundos.\n'Senha', escuto do outro lado da linha. Por sorte, eu havia anotado a senha que encontrei descriptografando o arquivo das vitimas (sabia que gastar minha noite de sexta decifrando aquele arquivo valeria a pena).\nTorci para que aquilo fosse o que ele queria. \0";

    printf_text(text, 1);

    cursor(1);

    char new_text[MAX] = "\nRespirei fundo e disse: ";
    for(int i = 0; i < strlen(new_text); i++){
        printf("%c", new_text[i]);
    }

    char ansr[MAX];
    gets(ansr);
    if(stricmp(ansr, "lcbrlgj\0") == 0 || stricmp(ansr, "l c b r l g j\0") == 0){
        system("cls");
        printf_text("\nEle nao disse uma palavra sobre a senha, apenas comecou a falar numeros. Anotei o mais rapido que pude. Mal tive tempo de agradecer antes que ele desligasse na minha cara.\nTive o primeira pensamento que qualquer detetive de filme de acao teria: coordenadas. ", 1);
        press_any();
        cave0();
    } else {
        search();
    }

    cursor(0);

    press_any();

    system("cls");

    end(972);
}

void terror() {
    system("cls");
    rand_sleep(200, 500);

    char date[MAX] = "19/09/92 (02:43) ";
    char text[MAX] = "\nDepois de descriptografar o arquivo, decidi ligar para o numero de telefone. Estava suando frio, com medo do que encontraria do outro lado da linha...\n'Alo', disse a voz extremamente grave ao atender o telefone. Congelei.\n\nDecidi: \0";

    char opt[2][MAX] = {"Ser sincero e explicar a situacao ",
                        "Usar um tom ameacador para tentar conseguir informacoes \0"};

    printf_text(date, 1);
    printf_text(text, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf("Usar um tom ameacador para tentar conseguir informacoes ");

    cursor(0);

    strcat(date, text);

    int ansr = choice_point(date, 2, opt);
    
    system("cls");

    if(ansr == 0) {
        t010();
    } else {
        search();
    }
}

void t0_() {
    rand_sleep(200, 500);

    char date[MAX] = "18/09/92 (21:34) ";
    char text[MAX] = "\nAchei algumas coisas interessantes no escritorio do mentor. Ele definitivamente era fa de comida japonesa, baseado na quantidade de embalagens com comida apodrecendo que encontrei jogadas pelo chao. Nao foi muito dificil acessar os arquivos em seu computador (impressionante como a senha eh sempre algo relacionado com animais de estimacao).\nNa area de trabalho, dois arquivos de texto chamaram minha atencao: 'forno.txt' e 'vitimas.txt'.\n\nDecidi comecar pelo: \0";

    char opt[2][MAX] = {"forno.txt ",
                        "vitimas.txt  "};

    printf_text(date, 1);
    printf_text(text, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    strcat(date, text);

    int ansr = choice_point(date, 2, opt);
    
    system("cls");

    if(ansr == 0) {
        italic(1);
        printf_text("forno.txt\n-22.417832, -49.119737 ", 1);
        italic(0);

        printf_text("\n\nHm... coordenadas. Bem que ele me avisou sobre 'abrir o forno' em sua mensagem...\nPor que isso esta parecendo um filme em que o protagonista vai direto para uma armadilha...\nEnfim, acho que nao tenho escolha dessa vez. ", 1);

        press_any();
        system("cls");

        printf("\n");
        printf_text("Agora para o proximo arquivo... ", 1);

        rand_sleep(1000, 1500);
        printf("Ah? ");
        rand_sleep(1000, 1500);
        printf("Corrompido?\n");
        rand_sleep(1000, 1500);
        
        printf_text("'Um bom detetive trabalha com o que tem'. Odeio como ele era brega ao usar essas frases de efeito. ", 1);        

        press_any();

        t00_();
    } else {
        italic(1);
        printf_text("vitimas.txt\n'Oh, Brutus...'\n\nMvob Sjdjfsj Nbsdij\nDbnjmb Dsjtujob Tjmwb\nCsvop Sbnbmip Obtdjnfoup\nSfobo Qjofeb Mfbm\nMvjt Hbcsjfm Ebnjbuuj\nHvmifsnf Npsbjt Bsbvkp\nKvmjb Dbseptp G.\n\nJojdjbm ebt 7 qsjnfjsbt wjujnbt\n(14) 943-2788 ", 1);
        italic(0);

        printf_text("\n\nAcho que isso esta criptogrado... Penso que so deveria ligar para esse numero quando entender o que esta escrito. ", 1);

        press_any();
        system("cls");

        printf_text("Agora para o proximo arquivo... ", 1);
        rand_sleep(1000, 1500);
        printf("Ah? ");
        rand_sleep(1000, 1500);
        printf("Corrompido?\n");
        rand_sleep(1000, 1500);
        
        printf_text("'Um bom detetive trabalha com o que tem'. Odeio como ele era brega ao usar essas frases de efeito. ", 1);        

        press_any();

        terror();
    }
}

void t1() {
    rand_sleep(200, 500);

    char date[MAX] = "19/09/92 (17:42)\n";
    char text[MAX] = "\nAcho que estraguei tudo. Mostrei a mensagem para a policia e eles decidiram colocar todos os documentos do escritorio do mentor como confidenciais. Eles sao os unicos que podem acessa-los agora. Me sinto completamente... impotente. \0";

    printf_text(date, 1);
    printf_text(text, 1);

    cursor(0);

    press_any();
    end(546);
}

void t_() {
    rand_sleep(200, 500);

    char date[MAX] = "16/09/92 (14:53)\n";
    char text[MAX] = "\nOkay... Oi. Meu nome eh Raphael Santos. Eu tenho 25 anos e trabalho como detetive na cidade de Piratininga ha mais ou menos 4 meses. Nas ultimas semanas, eu e meu mentor, detetive Carlos Almeida, temos investigado casos de desaparecimentos suspeitos na cidade... e acho que ele acabou de se tornar uma das vitimas.\nOntem recebi uma mensagem de voz dele. Nunca o vira daquela maneira: confuso, ansioso, com medo. Ele disse coisas que nao sei se compreendo completamente, mas preciso tentar. Comecei essa serie de entradas para deixar minhas descobertas registradas e ver se consigo decifrar o que esta por tras de tudo isso.\n\nNo momento, acho que tenho duas escolhas: \0";

    char opt[2][MAX] = {"Investigar por conta propria ",
                        "Ir a policia e mostrar a mensagem de voz "};

    printf_text(date, 1);
    printf_text(text, 1);

    printf("      > ");
    printf_text(opt[0], 1);

    printf("        ");
    printf_text(opt[1], 1);

    cursor(0);

    strcat(date, text);

    int ansr = choice_point(date, 2, opt);
    
    system("cls");

    if(ansr == 0) {
        t0_();
    } else {
        t1();
    }
}

void init_computer() {
    system("cls");

    PlaySound("sound/start_pc.wav", NULL, SND_FILENAME | SND_ASYNC);

    printf("\tLG G3, An Energy Star Ally.\n");
    Sleep(300);
    printf("\tCopyright (C) 1958-1992, LG Eletronics Inc.\n");
    Sleep(650);
    printf("\nKrait 400 CPU at 2500 MHz , 4 Processor(s)\n");
    Sleep(300);
    printf("Memory Test : ");
    Sleep(300);

    for(int i = 0; i < 1048576; i+=131072){
        system("cls");
        printf("\tLG G3, An Energy Star Ally.\n");
        printf("\tCopyright (C) 1958-1992, LG Eletronics Inc.\n");
        printf("\nKrait 400 CPU at 2500 MHz , 4 Processor(s)\n");
        printf("Memory Test : %7dK", i);
        Sleep(75);
    }

    printf(" 0K\n");
    Sleep(1000);

    printf("\nAndroid Plug and Play ROM Extension v5.0.2\n");
    Sleep(300);

    printf("Copyright (C) 2015, Google Inc.\n");
    Sleep(300);

    printf("\tDetecting Flash ROM       ");
    for(int i = 0; i < 3; i++){
        Sleep(150);
        printf(".");
    }
    Sleep(300);
    printf(" CyanogenMod 12\n");
    Sleep(300);

    printf("\tDetecting Flash Extension ");
    for(int i = 0; i < 3; i++){
        Sleep(150);
        printf(".");
    }
    Sleep(300);
    printf(" Generic microSD\n");
    Sleep(300);
    
    printf("\tDetecting Phone Storage   ");
    for(int i = 0; i < 3; i++){
        Sleep(150);
        printf(".");
    }
    Sleep(300);
    printf(" Generic SIM Card\n");
    Sleep(150);

    system("cls");

    Sleep(1000);

    printf("Initialization finished");
    for(int i = 0; i < 7; i++){
        Sleep(200);
        printf(".");
    }
    Sleep(750);
    
    for(int i = 0; i < 4; i++){
        system("cls");
        printf("Activating root access ");
        printf("\\");
        Sleep(100);

        system("cls");
        printf("Activating root access ");
        printf("|");
        Sleep(100);

        system("cls");
        printf("Activating root access ");
        printf("/");
        Sleep(100);

        system("cls");
        printf("Activating root access ");
        printf("-");
        Sleep(100);
    }

    Sleep(500);

    system("cls");
    
    Sleep(1000);

    t_();
}

void start() {

    printf("\n\n\n\n");
    printf("\n                      ........");
    printf("\n                  ....        ....");
    printf("\n               ...       __       ...");
    printf("\n           . ..        __  __        .. .");
    printf("\n               ...       __       ...");
    printf("\n                  ....        ....");
    printf("\n                      ........");

    printf("\n\n\n                olhos sempre abertos");

    PlaySound("sound/boss_run.wav", NULL, SND_FILENAME | SND_SYNC);

    rand_sleep(100, 200);
    init_computer();
}

int main() {
    srand(time(NULL));

    cursor(0);   

    start();

    return 0;
}
