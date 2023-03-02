#include "CntrAprAutenticacao.h"

bool CntrAprAutenticacao::autenticar(Email *email){
    string emailInserido, senhaInserida;
    Senha senha;

    clear_screen;

    cout << "Digite o email: \n";
    getline(cin, emailInserido);
    cout << "Digite a senha: \n";
    getline(cin, senhaInserida);

    try{
        email -> setEmail(emailInserido);
        senha.setSenha(senhaInserida);
    }
    catch(invalid_argument &exp){
        clear_screen;
        return false;
    }
    return (cntr -> autenticar(*email, senha));
}