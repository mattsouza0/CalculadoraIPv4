#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>
#include <vector>

using namespace std;

bool ipValido(string ip) {  //Função q valida o ip
    vector<int> arrayOct;         // vetor de inteiro para guardar os valores de cada octeto
    stringstream ss(ip);        //guarda a string q contem oo ip com pontos
    string octeto;             // guarda cada conteudo entre os delimitadores
    while (getline(ss, octeto, '.')) {   //usa o getline para separa os octetos entre os delimitadores '.'
        int test = stoi(octeto);        //guarda o octeto separado
        if (test < 0 || test > 255) {  //verifica se o octeto esta entre 0 e 255
            return false;                //retorn false para indicar que o ip é invalido
        }
        arrayOct.push_back(test);       //armazena o octeto valido no vetor
    }
    
    if (arrayOct.size() != 4) {          //verifica se tem 4 octetos armazenados no vetor
        return false;                    //retorna false caso não tenha
    }
    
    return true;                         //retorna true se todos os octetos do ip informado forem validos
}

char getClasse(string dec){         //Funcao para determinar a classe do endereço ip
    stringstream ss(dec);           //guarda a string q contem o ip com pontos
    string octeto;                  // guarda cada conteudo entre os pontos
    getline(ss, octeto, '.');       // usa o getline para separa o octeto pelo delimitador
    int priOcteto = stoi(octeto);   //so vou usar o primeiro octeto para determinar a classe
    //Determina a classe
    char classe;
    if(priOcteto < 128){
        classe = 'A';
    }else if(priOcteto < 192){
        classe = 'B';
    }else if(priOcteto < 224){
        classe = 'C';
    }else if(priOcteto < 240){
        classe = 'D';
    }else{
        classe = 'E';
    }
    return classe;
}

string getEnderecoRedeOuBroadcast(string ip, string end){
    string endRede="";
    vector<int> arrayOct;        
    stringstream ss(ip);      
    string octeto, oct1,oct2,oct3,oct4;
    int control, b[32], ipv4[32], dec=0;  
    
    while (getline(ss, octeto, '.')) {  
        arrayOct.push_back(stoi(octeto));     
    }

    //bloco de codigo abaixo converte o primeiro octeto da base 10 para 2
    for(int j = 0 ; j <= 3; j++){
        if(j == 0){
            control = 0;
        }else if(j == 1){
            control = 8;
        }else if(j == 2){
            control = 16;
        }else{
            control = 24;
        }
        for(int i = 0; i <= 7 ; i++){     
            if(arrayOct[j] >= 1){  
                b[i + control] = (arrayOct[j]%2);
                arrayOct[j] /= 2;
            }else {
                b[i + control] = 0;
            }
        }
    }

    for(int k = 0 ; k <= 7 ; k++){  // primeiro octeto
        ipv4[k] = b[7-k];
        //oct1 += to_string(ipv4[k]);
    }
    for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
        ipv4[k] = b[15-(k-8)];
        //oct2 += to_string(ipv4[k]);
    }
    for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
        ipv4[k] = b[23-(k-16)];
        //oct3 += to_string(ipv4[k]);
    }
    for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
        ipv4[k] = b[31-(k-24)];  
        //oct4 += to_string(ipv4[k]);
    }


    if(end == "rede"){
        if(getClasse(ip) == 'A'){
            for(int i=8;i<=31;i++){ 
                ipv4[i] = 0;
            }
            for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec);
        }else if(getClasse(ip) == 'B'){
            for(int i=16;i<=31;i++){
                ipv4[i] = 0;
            }
            for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec);
        }else if(getClasse(ip) == 'C'){
            for(int i=24;i<=31;i++){
                ipv4[i] = 0;
            }
            for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec);
        }
    }else {
        if(getClasse(ip) == 'A'){
            for(int i=8;i<=31;i++){ 
                ipv4[i] = 1;
            }
            //stoi(oct1);
            for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec);
        }else if(getClasse(ip) == 'B'){
            for(int i=16;i<=31;i++){
                ipv4[i] = 1;
            }
            for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec);
        }else if(getClasse(ip) == 'C'){
            for(int i=24;i<=31;i++){
                ipv4[i] = 1;
            }
            for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec) + ".";
            dec=0;
            for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
                dec = dec*2 + ipv4[k];
            }
            endRede += to_string(dec);
        }
    }
    return endRede;
}

string getIPInicialOuFinalUsavel(string ip,string tipo){
    if(tipo == "inicial"){
        stringstream ss(getEnderecoRedeOuBroadcast(ip,"rede"));
        vector<int> arrayOct;          
        string octeto,fend="";          
        while (getline(ss, octeto, '.')) {  
            arrayOct.push_back(stoi(octeto));     
        }
        arrayOct[3] += 1;
        for(int i=0;i<=3;i++){
            fend += to_string(arrayOct[i]);
            if(i!=3){
                fend += ".";
            }
        }
        return fend;
    }else {
        stringstream ss(getEnderecoRedeOuBroadcast(ip,"broadcast"));
        vector<int> arrayOct;          
        string octeto, fend="";         
        while (getline(ss, octeto, '.')) {  
            arrayOct.push_back(stoi(octeto));     
        }
        arrayOct[3] -= 1;
        for(int i=0;i<=3;i++){
            fend += to_string(arrayOct[i]);
            if(i!=3){
                fend += ".";
            }
        }
        return fend;
    }
}


int getCIDR(string ip){
    stringstream ss(ip);
    vector<int> array; 
    string cidr;
    while (getline(ss, cidr, '/')) {  
        array.push_back(stoi(cidr));     
    } 
    return array[1];
}

int numHosts(string ip){
    return pow(2,(32-getCIDR(ip)))-2;
}

int numBitDireita(string ip){
    return 32-getCIDR(ip);
}

string mask(string ip){
    string endRede;
    int dec,masc[32] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    for(int i=32-numBitDireita(ip);i<=31;i++){
        masc[i] = 0;
    }
    //Converte p decimal
    dec=0;
    for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
        dec = dec*2 + masc[k];
    }
    endRede += to_string(dec) + ".";
    dec=0;
    for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
        dec = dec*2 + masc[k];
    }
    endRede += to_string(dec) + ".";
    dec=0;
    for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
        dec = dec*2 + masc[k];
    }
    endRede += to_string(dec) + ".";
    dec=0;
    for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
        dec = dec*2 + masc[k];
    }
    endRede += to_string(dec);

    return endRede;
}

string endRede(string ip, string op){

    string endRede="";
    vector<int> arrayOct;        
    stringstream ss(ip);      
    string octeto;
    int control, b[32], ipv4[32], dec=0;  
    
    while (getline(ss, octeto, '.')) {  
        arrayOct.push_back(stoi(octeto));     
    }

    //bloco de codigo abaixo converte o primeiro octeto da base 10 para 2    191.10.95.30/18
    for(int j = 0 ; j <= 3; j++){
        if(j == 0){
            control = 0;
        }else if(j == 1){
            control = 8;
        }else if(j == 2){
            control = 16;
        }else{
            control = 24;
        }
        for(int i = 0; i <= 7 ; i++){     
            if(arrayOct[j] >= 1){  
                b[i + control] = (arrayOct[j]%2);
                arrayOct[j] /= 2;
            }else {
                b[i + control] = 0;
            }
        }
    }

    //manda ordenado para outro vetor
    for(int k = 0 ; k <= 7 ; k++){  // primeiro octeto
        ipv4[k] = b[7-k];
    }
    for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
        ipv4[k] = b[15-(k-8)];
    }  
    for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
        ipv4[k] = b[23-(k-16)];
    }   
    for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
        ipv4[k] = b[31-(k-24)];
    }

    if(op == "rede"){
        for(int i = 32 - numBitDireita(ip);i<=31;i++){
            ipv4[i] = 0;
        }
    }else {
        for(int i = 32 - numBitDireita(ip);i<=31;i++){
            ipv4[i] = 1;
        }
    }

    //Converte p decimal
    for(int k = 0 ; k <= 7 ; k++){// primeiro octeto
        dec = dec*2 + ipv4[k];
    }
    endRede += to_string(dec) + ".";
    dec=0;
    for(int k = 8 ; k <= 15 ; k++){ //segundo octeto
        dec = dec*2 + ipv4[k];
    }
    endRede += to_string(dec) + ".";
    dec=0;
    for(int k = 16 ; k <= 23 ; k++){ // terceiro octeto
        dec = dec*2 + ipv4[k];
    }
    endRede += to_string(dec) + ".";
    dec=0;
    for(int k = 24 ; k <= 31 ; k++){ //quarto octeto
        dec = dec*2 + ipv4[k];
    }
    endRede += to_string(dec);

    return endRede;
}

string endRedeUsavel(string ip,string tipo){
    if(tipo == "inicial"){
        stringstream ss(endRede(ip,"rede"));
        vector<int> arrayOct;          
        string octeto,fend="";          
        while (getline(ss, octeto, '.')) {  
            arrayOct.push_back(stoi(octeto));     
        }
        arrayOct[3] += 1;
        for(int i=0;i<=3;i++){
            fend += to_string(arrayOct[i]);
            if(i!=3){
                fend += ".";
            }
        }
        return fend;
    }else {
        stringstream ss(endRede(ip,"broadcast"));
        vector<int> arrayOct;          
        string octeto, fend="";         
        while (getline(ss, octeto, '.')) {  
            arrayOct.push_back(stoi(octeto));     
        }
        arrayOct[3] -= 1;
        for(int i=0;i<=3;i++){
            fend += to_string(arrayOct[i]);
            if(i!=3){
                fend += ".";
            }
        }
        return fend;
    }
}


int menu(){
    int opcao;
    cout<<"---------------------------------------------------\n";
    cout<<"         PUC-GO - Redes de Computadores 2"<<endl;
    cout<<"         Aluno: Mateus de Souza Almeida"<<endl;
    cout<<"---------------------------------------------------\n";
    cout<<" Opcoes Possiveis: "<<endl;
    cout<<" 1 - Calcular IP com classe"<<endl;
    cout<<" 2 - Calcular IP sem classe e notacao CIDR"<<endl;
    cout<<" 3 - Calcular IP sem classe e notacao decimal"<<endl;
    cout<<" 0 - Sair"<<endl;
    cout<<"\n OPCAO ESCOLHIDA --> ";
    cin>>opcao;
    return opcao;
}

int main(){
    int opcao=menu();
    string endereco;
    char flag;

    while (opcao!=0) {
        switch (opcao) {
            case 1:
                try {
                    cout<<"\n****CALCULAR IP COM CLASSE****";
                    cout<<"\nDigite um IP efetuar o calculo: "<<endl;
                    cin >> endereco;
                    if(ipValido(endereco)){
                        cout<<"-----------------------Resultado-----------------------\n";
                        cout<<"Endereco IP .......................... : " << endereco << endl;
                        cout<<"Classe ............................... : " << getClasse(endereco) << endl;
                        switch(getClasse(endereco)){
                            case 'A':
                            cout<<"Mascara Decimal ...................... : " << "255.0.0.0" << endl;
                            cout<<"Mascara CIDR ......................... : " << "/8" << endl;
                            cout<<"Numero de Hosts ...................... : " << "16777214" << endl;
                            cout<<"Endereco de rede ..................... : " << getEnderecoRedeOuBroadcast(endereco,"rede") << endl;
                            cout<<"Endereco de Broadcast ................ : " << getEnderecoRedeOuBroadcast(endereco,"broadcast") << endl;
                            cout<<"Endereco IPv4 inicial usavel ......... : " << getIPInicialOuFinalUsavel(endereco,"inicial") << endl;
                            cout<<"Endereco IPv4 final usavel ........... : " << getIPInicialOuFinalUsavel(endereco,"final") << endl;
                            break;
                            case 'B':
                            cout<<"Mascara Decimal ...................... : " << "255.255.0.0" << endl;
                            cout<<"Mascara CIDR ......................... : " << "/16" << endl;    
                            cout<<"Numero de Hosts ...................... : " << pow(2,(32-16)) - 2 << endl; 
                            cout<<"Endereco de rede ..................... : " << getEnderecoRedeOuBroadcast(endereco,"rede") << endl;
                            cout<<"Endereco de Broadcast ................ : " << getEnderecoRedeOuBroadcast(endereco,"broadcast") << endl;
                            cout<<"Endereco IPv4 inicial usavel ......... : " << getIPInicialOuFinalUsavel(endereco,"inicial") << endl;
                            cout<<"Endereco IPv4 final usavel ........... : " << getIPInicialOuFinalUsavel(endereco,"final") << endl;
                            break; 
                            case 'C':
                            cout<<"Mascara Decimal ...................... : " << "255.255.255.0" << endl;
                            cout<<"Mascara CIDR ......................... : " << "/24" << endl;  
                            cout<<"Numero de Hosts ...................... : " << pow(2,(32-24)) - 2 << endl;
                            cout<<"Endereco de rede ..................... : " << getEnderecoRedeOuBroadcast(endereco,"rede") << endl;
                            cout<<"Endereco de Broadcast ................ : " << getEnderecoRedeOuBroadcast(endereco,"broadcast") << endl;
                            cout<<"Endereco IPv4 inicial usavel ......... : " << getIPInicialOuFinalUsavel(endereco,"inicial") << endl;
                            cout<<"Endereco IPv4 final usavel ........... : " << getIPInicialOuFinalUsavel(endereco,"final") << endl;
                            break;      	  
                        } 
                        cout<<"-------------------------------------------------------\n";
                    }else{
                        cout<<"ERRO: O ENDERECO IPv4 INFORMADO Eh INVALIDO"<<endl;
                    }
                    
                } catch (const char* erro) {
                    cout<<erro<<endl;
                }
                break;
            case 2:
                cout<<"\n****CALCULAR IP SEM CLASSE E NOTACAO CIDR****";
                    cout<<"\nDigite um IP efetuar o calculo: "<<endl;
                    cin >> endereco;
                    if(ipValido(endereco)){
                        cout<<"-------------------------Resultado-------------------------\n";
                        cout<<"Endereco IP .......................... : " << endereco << endl;
                        cout<<"Mascara Decimal ...................... : " << mask(endereco)<< endl;
                        cout<<"Mascara CIDR ......................... : " << "/" << getCIDR(endereco)<< endl;
                        cout<<"Numero de Hosts ...................... : " << numHosts(endereco)<< endl;
                        cout<<"Endereco de rede ..................... : " << endRede(endereco,"rede") << endl;
                        cout<<"Endereco de Broadcast ................ : " << endRede(endereco,"broadcast") << endl;
                        cout<<"Endereco IPv4 inicial usavel ......... : " << endRedeUsavel(endereco,"inicial") << endl;
                        cout<<"Endereco IPv4 final usavel ........... : " << endRedeUsavel(endereco,"final") << endl;
                        cout<<"-----------------------------------------------------------\n";
                    }
                break;
            case 3:
                break;
            default:
                cout<<"\n Opcao invalida\nEscolha uma das opcoes acima"<<endl;
            break;
        }
        cout <<"\nDeseja calcular um novo IP? \n[S/N]";
        cin >> flag;
        cout<<endl;
        if(flag == 'S' or flag == 's'){
            system("cls");
            opcao = menu();
        }else{
            opcao = 0;
        }
        
    }
    cout << "\n PROGRAMA FINALIZADO\n" << endl;
    return 0;
}