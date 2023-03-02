#include "dominios.h"

// daniel
void Horario::validar(string horario){//202042829
    if(horario.find(":") == posMeio && horario.length() == caracteresNecessarios){
        try{
            stoi(horario.substr(0,2) + horario.substr(posMeio + 1));
        }
        catch(invalid_argument erro){
            throw invalid_argument("insira horario no formato HH:MM");
        }
    }
    else{
        throw invalid_argument("insira horario no formato HH:MM");
    }
    int horas = stoi(horario.substr(0,2));
    int minutos = stoi(horario.substr(3));
    if (horas < minTempo || horas > maxHoras)
        throw invalid_argument("horas devem ser de 00 a 23");
    else if (minutos < minTempo || minutos > maxMinutos)
        throw invalid_argument("minutos devem ser de 00 a 59");
}

void Horario::setHorario(string horario){//202042829
    validar(horario);
    this -> horario = horario;
}

const unordered_set<string> Idioma::idiomasValidos {
    "Ingles", "Chines Mandarim", "Hindi", "Espanhol", "Frances", "Arabe",
    "Bengali", "Russo", "Portugues", "Indonesio"
    };

void Idioma::validar(string idioma){//202042829
    if(idiomasValidos.count(idioma) == 0){
        throw invalid_argument("idioma invalido");
    }
}

void Idioma::setIdioma(string idioma){//202042829
    validar(idioma);
    this -> idioma = idioma;
}

void Nome::validar(string nome){//202042829
    if(nome.length() < minCaractere || nome.length() > maxCaractere){
        throw invalid_argument("quantidade de caracteres invalida");
    }
    bool anterior_letra = false;
    bool anterior_espaco = false;
    for(int i = 0; i < nome.length() ; i++){
        if(isalpha(nome[i]) > 0){
            if(!anterior_letra && isupper(nome[i]) == 0){
                throw invalid_argument("nomes devem comecar com maiusculas");
            }
            anterior_letra = true;
            anterior_espaco = false;
        }
        else if(nome[i] == '.'){
            if(!anterior_letra){
                throw invalid_argument("ponto deve ser precedido por letra");
            }
            if(isspace(nome[i + 1]) == 0 && i < nome.length() - 1){
                throw invalid_argument("ponto deve ser ultimo caractere ou seguido de espaco");
            }
            anterior_letra = false;
            anterior_espaco = false;
        }
        else if(isspace(nome[i])){
            if(anterior_espaco){
                throw invalid_argument("nao deve haver espacos em sequencia");
            }
            anterior_letra = false;
            anterior_espaco = true;
        }
        else{
            throw invalid_argument("nome pode conter apenas letras, pontos e espacos");
        }
    }
}

void Nome::setNome(string nome){//202042829
    validar(nome);
    this -> nome = nome;
}

void Nota::validar(float nota){//202042829
    if(nota < minNota || nota > maxNota){
        throw invalid_argument("nota invalida");
    }
}

void Nota::setNota(float nota){//202042829
    validar(nota);
    this -> nota = nota;
}

void Senha::validar(string senha){//202042829
    unordered_set<char> caracteres {};
    bool tem_minuscula = false;
    bool tem_maiuscula = false;
    bool tem_numero = false;
    if(senha.length() < tamanhoSenha){
        throw invalid_argument("senha deve ter pelo menos 6 caracteres");
    }
    for(int i = 0; i < senha.length() ; i++){
        if(!caracteres.insert(senha[i]).second){
            throw invalid_argument("senha nao deve conter caracteres repetidos");
        }
        if(isalnum(senha[i]) > 0){
            if(isupper(senha[i]) > 0){
                tem_maiuscula = true;
            }
            else if(islower(senha[i]) > 0){
                tem_minuscula = true;
            }
            else if(isdigit(senha[i]) > 0){
                tem_numero = true;
            }
        }
        else{
            throw invalid_argument("senha deve conter apenas caracteres alfanumericos");
        }
    }
    if(!tem_minuscula){
        throw invalid_argument("senha deve conter ao menos uma letra minuscula");
    }
    if(!tem_maiuscula){
        throw invalid_argument("senha deve conter ao menos uma letra maiuscula");
    }
    if(!tem_numero){
        throw invalid_argument("senha deve conter ao menos um numero");
    }
}

void Senha::setSenha(string senha){//202042829
    validar(senha);
    this -> senha = senha;
}

void Titulo::validar(string titulo){//202042829
    if(titulo.length() < minCaractere || titulo.length() > maxCaractere){
        throw invalid_argument("quantidade de caracteres invalida");
    }
    bool anterior_espaco = false;
    bool anterior_ponto = false;
    for(int i = 0; i < titulo.length() ; i++){
        if(titulo[i] == '.'){
            if(anterior_ponto){
                throw invalid_argument("nao deve haver pontos em sequencia");
            }
            anterior_ponto = true;
            anterior_espaco = false;
        }
        else if(isspace(titulo[i])){
            if(anterior_espaco){
                throw invalid_argument("nao deve haver espacos em sequencia");
            }
            anterior_ponto = false;
            anterior_espaco = true;
        }
        else if(isalpha(titulo[i]) == 0){
            throw invalid_argument("titulo deve conter apenas letras, pontos e espacos");
        }
        else{
            anterior_espaco = false;
            anterior_ponto = false;
        }
    }
}

void Titulo::setTitulo(string titulo){//202042829
    validar(titulo);
    this -> titulo = titulo;
}

unordered_set<string> Email::emailsEmUso {};

const unordered_set<char> Email::simbolosParteLocal {'!', '#', '$', '%', '&',
    '\'', '*', '+', '/', '=', '?', '^', '_', '`', '{', '|', '}', '~', '-'};

void Email::validar(string email){//202042829
    if(email.find("@") == string::npos){
        throw invalid_argument("email em formato invalido");
    }
    int posArroba = email.find("@");
    string parteLocal = email.substr(0, posArroba);
    string dominio = email.substr(posArroba + 1);
    if (parteLocal.length() > 0 && parteLocal.length() <= caracteresParteLocal){
        bool anterior_ponto = false;
        if(parteLocal[0] == '.' || parteLocal[parteLocal.length() - 1] == '.'){
            throw invalid_argument("ponto nao deve ser o primeiro ou ultimo caractere em parte-local");
        }
        for(int i = 0; i < parteLocal.length(); i++){
            if(isalnum(parteLocal[i]) || simbolosParteLocal.count(parteLocal[i]) == 1){
                anterior_ponto = false;
            }
            else if(parteLocal[i] == '.'){
                if(anterior_ponto){
                    throw invalid_argument("nao devem haver pontos em sequencia");
                }
                anterior_ponto = true;
            }
            else{
                throw invalid_argument("caractere invalido em parte-local");
            }
        }
    }
    else{
        throw invalid_argument("parte-local deve ter de 1 a 64 caracteres");
    }
    if(dominio.length() > 0 && dominio.length() <= caracteresDominio){
        bool anterior_ponto = false;
        if(dominio[0] == '.'){
            throw invalid_argument("ponto nao deve ser o primeiro caractere em dominio");
        }
        for(int i = 0; i < dominio.length(); i++){
            if(isalnum(dominio[i]) || dominio[i] == '-'){
                anterior_ponto = false;
            }
            else if(dominio[i] == '.'){
                if(anterior_ponto){
                    throw invalid_argument("nao devem haver pontos em sequencia");
                }
                anterior_ponto = true;
            }
            else{
                throw invalid_argument("caractere invalido em dominio");
            }
        }
    }
    else{
        throw invalid_argument("dominio deve ter de 1 a 253 caracteres");
    }
}

void Email::setEmail(string email){//202042829
    validar(email);
    if(emailsEmUso.count(email) == 1){
        throw invalid_argument("email em uso");
    }
    try{
        validar(this -> email);
        emailsEmUso.erase(this -> email);
        emailsEmUso.insert(email);
        this -> email = email;
    }
    catch(invalid_argument erro){
        emailsEmUso.insert(email);
        this -> email = email;
    }
}

const vector<string> Data::meses31 {"Jan", "Mar", "Mai", "Jul", "Ago", "Out", "Dez"};
const vector<string> Data::meses30 {"Abr", "Jun", "Set", "Nov"};

void Data::validar(string data){//202042829
    try{
        stoi(data.substr(0,2));
        stoi(data.substr(7));
    }
    catch(invalid_argument erro){
        throw invalid_argument("Argumento invalido.");
    }
    int dia = stoi(data.substr(0,2));
    string mes = data.substr(3, 3);
    int ano = stoi(data.substr(7));

    if(ano < 2000 or ano > 9999){
        throw invalid_argument("Argumento invalido.");
    }
    if (mes == "Fev"){
        if (ano%400 == 0){
            if (dia < 0 or dia > 29)
                throw invalid_argument("Argumento invalido.");
        }
        else if (ano%4 == 0 and ano%100 != 0){
            if (dia < 0 or dia > 29)
                throw invalid_argument("Argumento invalido.");
        }
        else{
            if (dia < 0 or dia > 28)
                throw invalid_argument("Argumento invalido.");
        }
    }
    else if (find(meses31.begin(), meses31.end(), mes) != meses31.end()){
        if (dia < 0 or dia > 31)
            throw invalid_argument("Argumento invalido.");
    }
    else if (find(meses30.begin(), meses30.end(), mes) != meses30.end()){
        if (dia < 0 or dia > 30)
            throw invalid_argument("Argumento invalido.");
    }
    else
        throw invalid_argument("Argumento invalido.");
}

void Data::setData(string data){ //202042829
    validar(data);
    this->data = data;
}
//daniel

void Cidade::validar(string cidade){ //202014280
    list<string> cidades = {"Hong Kong", "Bangkok", "Macau", "Singapura", "Londres", "Paris", "Dubai", "Delhi", "Istambul", "Kuala Lumpur", "Nova Iorque", "Antalya", "Mumbai", "Shenzhen", "Phuket"};
    bool achar = (find(cidades.begin(), cidades.end(), cidade) != cidades.end());
    if (achar == 0){
        throw invalid_argument("Argumento invalido.");
    }
}

void Cidade::setCidade(string cidade){ //202014280
    validar(cidade);
    this->cidade = cidade;
}

//
unordered_set<string> Codigo::codigosEmUso {};

void Codigo::validar(string codigo){ //202014280
    int algarismo = 0;
    int operando = 6;
    int operacao = 0;
    int verificador = 0;
    string codigo_sem_zero = codigo.substr(0, codigo.length() - 1);
    if (codigo_sem_zero == "000000")
        throw invalid_argument("Argumento invalido.");
    if (codigo.size() > 7 or codigo.size() < 7)
        throw invalid_argument("Argumento invalido.");
    for (int i=0; i < codigo.size() - 1; i++){
        algarismo = (int)codigo[i] - (int)'0';
        operacao += (algarismo * operando);
        operando -= 1;
    }
    verificador = (operacao*10)%11;
    if (verificador == 10)
        verificador = 9;
    string final = codigo.substr(6, codigo.length());


    if (stoi(final) != verificador)
        throw invalid_argument("Argumento invalido.");

}

void Codigo::setCodigo(string codigo){ //202014280
    validar(codigo);
    if(codigosEmUso.count(codigo) == 1){
        throw invalid_argument("codigo em uso");
    }
    try{
        validar(this -> codigo);
        codigosEmUso.erase(this -> codigo);
        codigosEmUso.insert(codigo);
        this -> codigo = codigo;
    }
    catch(invalid_argument erro){
        codigosEmUso.insert(codigo);
        this -> codigo = codigo;
    }
}

//
void Descricao::validar(string descricao){ //202014280
    if (descricao.size() > 30)
        throw invalid_argument("Argumento invalido.");
    int count_ponto_seq = 0;
    int count_espaco_seq = 0;
    for (int i=0; i < descricao.size(); i++){
        if (descricao[i] == '.')
            count_ponto_seq += 1;
        if (descricao[i] == ' ')
            count_espaco_seq += 1;
        if (descricao[i] != '.')
            count_ponto_seq = 0;
        if (descricao[i] != ' ')
            count_espaco_seq = 0;
        if (count_ponto_seq == 2 or count_espaco_seq == 2)
            throw invalid_argument("Argumento invalido.");
    }

}

void Descricao::setDescricao(string descricao){ //202014280
    validar(descricao);
    this->descricao = descricao;
}

//
void Duracao::validar(int duracao){ //202014280
    list<int> duracoes = {30, 60, 90, 120, 180};
    bool achar = (find(duracoes.begin(), duracoes.end(), duracao) != duracoes.end());
    if (achar == 0)
        throw invalid_argument("Argumento invalido.");
}

void Duracao::setDuracao(int duracao){
    validar(duracao);
    this->duracao = duracao;
}


//
void Endereco::validar(string endereco){ //202014280
    int count_ponto_seq = 0;
    int count_espaco_seq = 0;
    if (endereco.size() > 20)
        throw invalid_argument("Argumento invalido.");
    for (int i=0; i < endereco.size(); i++){
        if (endereco[i] == '.')
            count_ponto_seq += 1;
        if (endereco[i] == ' ')
            count_espaco_seq += 1;
        if (endereco[i] != '.')
            count_ponto_seq = 0;
        if (endereco[i] != ' ')
            count_espaco_seq = 0;
        if (count_ponto_seq == 2 or count_espaco_seq == 2)
            throw invalid_argument("Argumento invalido.");
    }
}

void Endereco::setEndereco(string endereco){ //202014280
    validar(endereco);
    this->endereco = endereco;
}

/*int main(){


    Codigo codigo;

    try{codigo.setCodigo("8474218");
    }catch(...){
        cout << "excecao" << endl;
    }


    return 0;

}*/
