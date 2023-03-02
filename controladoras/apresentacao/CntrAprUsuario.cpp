#include "CntrAprUsuario.h"

void CntrAprUsuario::cadastrar(){
    int opcao;
    bool continuar = true;
    string nomeInserido, emailInserido, senhaInserida;
    Nome nome;
    Email email;
    Senha senha;
    Usuario usuario;

    while(continuar){
        clear_screen;
        cout << "INSIRA OS DADOS DO USUARIO A SER CADASTRADO: \n\n";
        cout << "Insira um nome: ";
        getline(cin, nomeInserido);
        cout << "Insira um email: ";
        getline(cin, emailInserido);
        cout << "Insira uma senha: ";
        getline(cin, senhaInserida);

        try{
            nome.setNome(nomeInserido);
            email.setEmail(emailInserido);
            senha.setSenha(senhaInserida);

            continuar = false;
        }
        catch(invalid_argument &exp){
            cout << "Algum dado inserido e invalido. Insira: \n";
            cout << "1, para tentar novamente;\n";
            cout << "2, para retornar ao menu anterior.\n";
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);

    if (cntr -> cadastrar(usuario))
        cout << "Usuario cadastrado com sucesso. Tecle enter para retornar ao menu anterior.";
    else
    cout << "Falha ao cadastrar usuario. Tecle enter para retornar ao menu anterior.";
    getline(cin, flush);
    return;
}

bool CntrAprUsuario::executar(Email email){
    int opcao;

    while(true){
        clear_screen;

        cout << "Selecione o servico desejado: \n";
        cout << "1 - Consultar dados;\n";
        cout << "2 - Editar dados;\n";
        cout << "3 - Excluir seu usuario;\n";
        cout << "4 - Retornar ao menu anterior.\n";

        opcao = getchar() - 48;
        getline(cin, flush);
        switch(opcao){
            case 1:
                clear_screen;
                mostrarUsuario(email);
                cout << "Tecle enter para retornar ao menu anterior.\n";
                getline(cin, flush);
                break;
            case 2:
                editarUsuario(email);
                break;
            case 3:
                if (excluirUsuario(email)){
                    cout << "Usuario excluido com sucesso. Tecle enter para ser desconectado.";
                    getline(cin, flush);
                    return false;
                }
                break;
            case 4:
                return true;
        }
    }
}

void CntrAprUsuario::mostrarUsuario(Email email){
    Usuario usuario = cntr -> obter(email);
    cout << "Usuario de nome " << usuario.getNome().getNome() << '\n';
    cout << "Email: " << usuario.getEmail().getEmail() << '\n';
    cout << "Senha: " << usuario.getSenha().getSenha() << '\n';
    cout << "----------------------------------------------------------------------------\n";
}

void CntrAprUsuario::editarUsuario(Email email){
    int opcao;
    string nomeInserido, senhaInserida;
    bool continuar = true;
    Nome nome;
    Senha senha;
    Usuario usuario = cntr -> obter(email);

    while(continuar){
        try{
            clear_screen;
            cout << "USUARIO A EDITAR:\n\n";
            mostrarUsuario(email);
            cout << "Insira novo nome: ";
            getline(cin, nomeInserido);
            cout << "Insira nova senha: ";
            getline(cin, senhaInserida);

            nome.setNome(nomeInserido);
            senha.setSenha(senhaInserida);

            usuario.setNome(nome);
            usuario.setSenha(senha);

            continuar = false;
        }
        catch(invalid_argument &exp){
            cout << "Nome ou senha inseridos sao invalidos. Insira: \n";
            cout << "1, para tentar novamente;\n";
            cout << "2, para retornar ao menu anterior.\n";
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
    if (cntr -> alterar(usuario))
        cout << "Usuario modificado com sucesso.";
    else
        cout << "Falha ao modificar usuario.";
    cout << "Tecle enter para retornar ao menu anterior.";
    getline(cin, flush);
    return;
}

bool CntrAprUsuario::excluirUsuario(Email email){
    clear_screen;
    int opcao;
    cout << "Deseja realmente excluir seu usuario? Insira: \n";
    cout << "1 para confirmar;\n";
    cout << "2 para cancelar e voltar ao menu anterior.\n";
    opcao = getchar() - 48;
    getline(cin, flush);
    if (opcao == 2){
        cout << "Seu usuario nao foi excluido. Tecle enter para retornar ao menu anterior.\n";
        getline(cin, flush);
        return false;
    }
    if(cntr -> descadastrar(email))
        return true;
    
    cout << "Falha ao excluir usuario. Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
    return false;
}