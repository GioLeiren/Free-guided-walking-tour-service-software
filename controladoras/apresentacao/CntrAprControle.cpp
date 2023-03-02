#include "CntrAprControle.h"

void CntrAprControle::executar(){
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;

        cout << "Selecione o servico desejado:\n";
        cout << "1 - Entrar no sistema.\n";
        cout << "2 - Cadastrar-se no sistema.\n";
        cout << "3 - Acessar dados de excursoes.\n";
        cout << "4 - Encerrar execucao do sistema.\n";

        opcao = getchar() - 48;
        getline(cin, flush);

        switch(opcao){
            case 1:
                if (cntrAprAutenticacao -> autenticar(&email)){
                    bool sessaoAutenticada = true;

                    while(sessaoAutenticada){
                        clear_screen;
                        cout << "Selecione o servico desejado:\n";
                        cout << "1 - Atividades de usuario.\n";
                        cout << "2 - Atividades de excursao.\n";
                        cout << "3 - Encerrar sessao.\n";

                        opcao = getchar() - 48;
                        getline(cin, flush);

                        switch(opcao){
                            case 1:
                                if(!cntrAprUsuario -> executar(email)){
                                    sessaoAutenticada = false;
                                    clear_screen;
                                    cout << "Voce foi desconectado. Tecle enter para retornar a tela inicial.";
                                    getline(cin, flush);
                                }
                                break;
                            case 2:
                                cntrAprExcursao -> executar(email);
                                break;
                            case 3:
                                sessaoAutenticada = false;
                                break;
                        }
                    }
                }
                else{
                    clear_screen;
                    cout << "Email nao cadastrado, ou email ou senha invalidos. Tecle enter para tentar novamente.\n";
                    getline(cin, flush);
                }
                break;
            case 2:
                cntrAprUsuario -> cadastrar();
                break;
            case 3:
                cntrAprExcursao -> executar();
                break;
            case 4:
                clear_screen;
                continuar = false;
                break;
        }
    }
    return;
}