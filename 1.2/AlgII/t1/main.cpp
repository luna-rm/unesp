#include<bits/stdc++.h> 
#include<windows.h>

using namespace std;

//a senha é "euFacoProgramaXD"

vector<string> split(string str){
    vector<string> vec_string;
    char del = ',';
    string temp = "";

    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != '.'){
            if(str[i] != del){
                temp += str[i];
            } else {
                vec_string.push_back(temp);
                temp = "";
            }
        }
    } 
    vec_string.push_back(temp);
    return vec_string;
}

void bold(int status) {
    static const char *seq[] = {"\x1b[0m""\x1b[1m"};
    printf("%s", seq[!!status]);
}

void italic(int status) {
    static const char *seq[] = {"\x1b[0m""\x1b[3m"};
    printf("%s", seq[!!status]);
}

string v0xx(char c){
    vector<vector<string>> vec({{"1", "cento"}, {"2", "duzentos"}, {"3", "trezentos"}, {"4", "quatrocentos"}, {"5", "quinhentos"}, {"6", "seiscentos"}, {"7", "setecentos"}, {"8", "oitocentos"}, {"9", "novecentos"}});
    string aux;

    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i][0][0] == c){
            aux = vec[i][1];
        }
    }
    
    return aux;
} 

string vx0x(char c){
    vector<vector<string>> vec ({{"2", "vinte"}, {"3", "trinta"}, {"4", "quarenta"}, {"5", "cinquenta"}, {"6", "sessenta"}, {"7", "setenta"}, {"8", "oitenta"}, {"9", "noventa"}});
    string aux;

    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i][0][0] == c){
            aux = vec[i][1];
        }
    }

    return aux;
} 

string vx10(char c){
    vector<vector<string>> vec({{"0", "dez"}, {"1", "onze"}, {"2", "doze"}, {"3", "treze"}, {"4", "catorze"}, {"5", "quize"}, {"6", "dezesseis"}, {"7", "dezesete"}, {"8", "dezoito"}, {"9", "dezenove"}});
    string aux;

    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i][0][0] == c){
            aux = vec[i][1];
        }
    }

    return aux;
} 

string vxx0(char c){
    vector<vector<string>> vec({{"0", ""}, {"1", "um"}, {"2", "dois"}, {"3", "tres"}, {"4", "quatro"}, {"5", "cinco"}, {"6", "seis"}, {"7", "sete"}, {"8", "oito"}, {"9", "nove"}});
    string aux;

    for(unsigned int i = 0; i < vec.size(); i++){
        if(vec[i][0][0] == c){
            aux = vec[i][1];
        }
    }

    return aux;
} 


void start(){
    system("cls");
    
    string number;
    int cont = 1;   
    while(cont){
        cont = 0;
        cout << "Digite o numero a ser escrito no cheque: ";
        cin >> number;
        fflush(stdin);

        if(number[number.length()-3] != ',' && number[number.length()-2] != ','){
            cont = 1;
        } else {
            for(unsigned int i = 0; i < number.size(); i++){
                if(!isdigit(number[i]) && number[i] != ',' && number[i] != '.'){
                    cont = 1;
                    break;
                } 
            }
        }
        
        if(cont){
            cout << endl << "Numero INVALIDO" << endl << "precione qualquer tecla para tentar novamente!" << endl << endl;
            fflush(stdin);
            getchar();
            fflush(stdin);
            system("cls");
        }
    }

    vector<string> v_string = split(number);
    number = v_string[0];

    while(number.size()%3!=0){
        number = "0" + number;
    }

    cout << endl << "Valor: ";

    if(!(number[0] == '0' && number[1] == '0' && number[2] == '0')){
        for(unsigned int i = 0; i < number.size(); i+=3){ 
            cout << v0xx(number[i]);

            if(!(number[i]=='0' || number[i+1]=='0') || !(number[i]=='0' || number[i+2] =='0')){
                cout << " e ";
            }
                
            if(number[i+1] == '1'){
                cout << vx10(number[i+2]);
                cout << " ";
                continue;
            }            
            
            cout << vx0x(number[i+1]);

            if(!(number[i+1]=='0' || number[i+2]=='0')){
                cout << " e ";
            }

            cout << vxx0(number[i+2]);

            cout << " ";

            if(number.size()-i==6){
                cout << "mil";
            }

            if(number.size()-i==9){
                if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                    cout << "milhao";
                } else {
                    cout << "milhoes";
                }                    
            }

            if(number.size()-i==12){
                if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                    cout << "bilhao";
                } else {
                    cout << "bilhoes";
                }
            }

            if(number.size()-i==15){
                if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                    cout << "trilhao";
                } else {
                    cout << "trilhoes";
                }
            }

            if(number.size()-i==18){
                if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                    cout << "quatrilhao";
                } else {
                    cout << "quatrilhoes";
                    }
                }

                if(number.size()-i==21){
                    if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                        cout << "quintilhao";
                    } else {
                        cout << "quintilhoes";
                    }
                }

                if(number.size()-i==24){
                    if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                        cout << "sextilhao";
                    } else {
                        cout << "sextilhoes";
                    }
                }

                if(number.size()-i==27){
                    if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                        cout << "septilhao";
                    } else {
                        cout << "septilhoes";
                    }
                }

                if(number.size()-i==30){
                    if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                        cout << "octilhao ";
                    } else {
                        cout << "octilhoes ";
                    }
                }

                if(number.size()-i==33){
                    if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                        cout << "nonilhao";
                    } else {
                        cout << "nonilhoes";
                    }
                }

                if(number.size()-i==36){
                    if(number[i]==0 || number[i+1]==0 || number[i+2]==1){
                        cout << "decilhao";
                    } else {
                        cout << "decilhoes";
                    }
                }

                for(unsigned int m = i+3; m < number.size(); m++){
                    if(m > number.size()){
                        break;
                    }
                    if(number[m] != '0'){
                        cout << ", ";
                        break;
                    }
                }
            }
        if(number.back() == '1'){
            cout << "real ";
        } else {
            cout << "reais ";
        }
    } else {
        cout << "zero reais ";
    }
    
    string cents = v_string[1];

    cout << "e ";

    if(cents.size() != 2){
        cents = cents + '0';
    }
    
    if(cents[0] == '0' && cents[1] == '0'){
        cout << "zero centavos " << endl;
    } else {
        if(cents[0] == '1'){
            cout << vx10(cents[1]);
        } else {
            cout << vx0x(cents[0]);

            if(!(cents[0]=='0' || cents[1]=='0')){
                cout << " e ";
            }

            cout << vxx0(cents[1]);
        }
        cout << " centavo";

        if(cents.back() != '1'){
            cout << "s ";
        }

        cout << endl;
    }

    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    cout << "Data: " << put_time(&tm, "%d/%m/%Y") << endl << endl;
}

void end() {
    system("cls");

    cout << "Obrigada por usar o programa!!" << endl;
    cout << "Feito por:" << endl;
    cout << "- Bruno Ramalho Nascimento" << endl;
    cout << "- Camila Cristina Silva" << endl;
    if(rand()%14 == 4){
        cout << "- Luna Ricieri Marchi" << endl;
        Sleep(500);
        system("cls");
        cout << "Obrigada por usar o programa!!" << endl;
        cout << "Feito por:" << endl;
        cout << "- Bruno Ramalho Nascimento" << endl;
        cout << "- Camila Cristina Silva" << endl;
        cout << "- Pedro Ricieri Marchi" << endl;
    } else {
        cout << "- Pedro Ricieri Marchi" << endl;
    }

}

int restart(){
    int do_again;
    
    cout << "Deseja rodar novamente? (1-sim/0-nao)" << endl;
    cin >> do_again; 
    while(do_again!=1 && do_again!=0){
        bold(1);
        italic(1);
        system("cls");
        cout << "Resposta invalida. Digite novamente (1-sim/0-nao)" << endl;
        bold(0);
        italic(0);
        cin >> do_again;
    }
    
    return do_again; 
}

int main(){
    srand(time(NULL));
    string senha;

    cout << "Insira a senha: ";
    cin >> senha;

    while(senha != "euFacoProgramaXD"){
        system("cls");
        cout << "Senha incorreta" << endl << "Computador ira se auto destruir em 5 segundos" << endl << "Eh brincadeira. Por favor digite a senha novamente" << endl;
        cout << endl << "Insira a senha: ";
        cin >> senha;
        system("cls");
    }

    int do_again = 1;
    while(do_again){
        start();
        do_again = restart();
    }

    end();
    
    return 0;
}