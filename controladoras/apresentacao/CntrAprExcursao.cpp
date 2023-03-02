#include "CntrAprExcursao.h"

void CntrAprExcursao::executar(){
    int opcao;
    while(true){
        clear_screen;

        cout << "Escolha o servico desejado:\n";
        cout << "1 - Listar todas as excursoes;\n";;
        cout << "2 - Pesqusar excursao por codigo;\n";;
        cout << "3 - Retornar para a tela inicial.\n";

        opcao = getchar() - 48;
        getline(cin, flush);

        switch(opcao){
            case 1:
                listarExcursoes();
                break;
            case 2:
                listarExcursao();
                break;
            case 3:
                return;
        }
    }
}

void CntrAprExcursao::executar(Email email){
    int opcao;
    while(true){
        clear_screen;

        cout << "Escolha o servico desejado:\n";
        cout << "1 - Listar todas as excursoes;\n";
        cout << "2 - Pesquisar excursao pelo codigo;\n";
        cout << "3 - Cadastrar excursao;\n";
        cout << "4 - Editar excursao;\n";
        cout << "5 - Descadastrar excursao;\n";
        cout << "6 - Listar minhas excursoes;\n";
        cout << "7 - Acessar servicos de sessoes;\n";
        cout << "8 - Acessar servicos de avaliacoes;\n";
        cout << "9 - Retornar para o menu anterior.\n";

        opcao = getchar() - 48;
        getline(cin, flush);

        switch(opcao){
            case 1:
                listarExcursoes();
                break;
            case 2:
                listarExcursao();
                break;
            case 3:
                cadastrarExcursao(email);
                break;
            case 4:
                editarExcursao(email);
                break;
            case 5:
                descadastrarExcursao(email);
                break;
            case 6:
                listarExcursoes(email);
                break;
            case 7:
                servicosSessoes(email);
                break;
            case 8:
                servicosAvaliacoes(email);
                break;
            case 9:
                return;
        }
    }
}

void CntrAprExcursao::servicosSessoes(Email email){
    bool continuar = true;
    int opcao;

    while(continuar){
        clear_screen;
        cout << "SERVICOS RELACIONADOS A SESSOES: \n";
        cout << "1 - Listar suas sessoes;\n";
        cout << "2 - Visualizar sessao por codigo;\n";
        cout << "3 - Cadastrar sessao;\n";
        cout << "4 - Editar sessao;\n";
        cout << "5 - Descadastrar sessao;\n";
        cout << "6 - Visualizar todas as sessoes cadastradas;\n";
        cout << "7 - Visualizar as sessoes de uma excursao;\n";
        cout << "8 - Retornar ao menu anterior.\n";

        opcao = getchar() - 48;
        getline(cin, flush);

        switch(opcao){
            case 1:
                listarSessoes(email);
                break;
            case 2:
                listarSessao(email);
                break;
            case 3:
                cadastrarSessao(email);
                break;
            case 4:
                editarSessao(email);
                break;
            case 5:
                descadastrarSessao(email);
                break;
            case 6:
                sessoesExcursoes(email);
                break;
            case 7:
                sessoesExcursao(email);
                break;
            case 8:
                continuar = false;
                break;
        }
    }
}

void CntrAprExcursao::servicosAvaliacoes(Email email){
    bool continuar = true;
    int opcao;

    while(continuar){
        clear_screen;
        cout << "SERVICOS RELACIONADOS A AVALIACOES: \n";
        cout << "1 - Listar avalicoes feitas por voce;\n";
        cout << "2 - Listar avaliacoes feitas em uma de suas excursoes;\n";
        cout << "3 - Cadastrar avaliacao;\n";
        cout << "4 - Editar avaliacao;\n";
        cout << "5 - Descadastrar avaliacao;\n";
        cout << "6 - Retornar ao menu anterior.\n";

        opcao = getchar() - 48;
        getline(cin, flush);

        switch(opcao){
            case 1:
                listarAvaliacoesUsuario(email);
                break;
            case 2:
                listarAvaliacoesExcursao(email);
                break;
            case 3:
                cadastrarAvaliacao(email);
                break;
            case 4:
                editarAvaliacao(email);
                break;
            case 5:
                descadastrarAvaliacao(email);
                break;
            case 6:
                continuar = false;
                break;
        }
    }
}

void CntrAprExcursao::listarExcursoes(){
    clear_screen;
    list<Excursao> excursoes = cntr -> reunirExcursoes();
    list<Excursao> :: iterator excursao;
    if(!excursoes.empty()){
        cout << "TODAS AS EXCURSOES: \n\n";
        for(excursao = excursoes.begin(); excursao != excursoes.end(); ++excursao){
            mostrarExcursao(*excursao);
        }
    }
    else
        cout << "Nao ha excursao cadastrada.\n";
    cout << retornar;
    getline(cin, flush);
    return;
}

void CntrAprExcursao::listarExcursao(){
    Excursao excursao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da excursao a ser apresentada: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            excursao = cntr -> obterExcursao(codigo);
            continuar = false;
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido, ou a excursao desejada nao esta cadastrada. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
    cout << "\nEXCURSAO " << codigo.getCodigo() << ":\n";
    mostrarExcursao(excursao);
    cout << retornar;
    getline(cin, flush);
    return;
}

void CntrAprExcursao::cadastrarExcursao(Email email){
    int opcao;
    string tituloInserido, cidadeInserida, duracaoInserida, descricaoInserida, enderecoInserido;
    Codigo codigo;
    Titulo titulo;
    Nota nota;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;
    Excursao excursao;

    bool continuar = true;

    while(continuar){
        clear_screen;

        cout << "INSIRA OS DADOS DA EXCURSAO A SER CADASTRADA:\n\n";
        cout << "Insira um titulo: ";
        getline(cin, tituloInserido);
        cout << "Insira uma cidade: ";
        getline(cin, cidadeInserida);
        cout << "Insira uma duracao: ";
        getline(cin, duracaoInserida);
        cout << "Insira uma descricao: ";
        getline(cin, descricaoInserida);
        cout << "Insira um endereco: ";
        getline(cin, enderecoInserido);

        try{
            codigo.setCodigo(cntr -> gerarCodigo());
            titulo.setTitulo(tituloInserido);
            nota.setNota(0);
            cidade.setCidade(cidadeInserida);
            duracao.setDuracao(stoi(duracaoInserida));
            descricao.setDescricao(descricaoInserida);
            endereco.setEndereco(enderecoInserido);

            continuar = false;
        }
        catch(invalid_argument &exp){
            cout << "Algum dado inserido e invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
    excursao.setCodigo(codigo);
    excursao.setTitulo(titulo);
    excursao.setNota(nota);
    excursao.setCidade(cidade);
    excursao.setDuracao(duracao);
    excursao.setDescricao(descricao);
    excursao.setEndereco(endereco);

    if (cntr -> cadastrarExcursao(excursao, email)){
        cout << "Excursao cadastrada com sucesso.\n";
        cout << "Codigo da excursao: " << excursao.getCodigo().getCodigo() << '\n';
        cout << "Tecle enter para retornar ao menu anterior.\n";
        getline(cin, flush);
        return;
    }
    cout << "Falha ao cadastrar excursao. Tente novamente.\n";
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
    return;
}

void CntrAprExcursao::editarExcursao(Email email){
    Codigo codigo;
    Titulo titulo;
    Cidade cidade;
    Duracao duracao;
    Descricao descricao;
    Endereco endereco;
    Excursao excursao;
    Email guiaExcursao;
    int opcao;
    string codigoInserido;
    bool continuar = true;

    while(continuar){
        try{
            clear_screen;
            cout << "EDITAR DADOS DE EXCURSAO\n";
            cout << "Insira o codigo da excursao a ser editada: \n";
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            excursao = cntr -> obterExcursao(codigo);
            guiaExcursao = cntr -> obterGuiaExcursao(codigo);
            if (email.getEmail() != guiaExcursao.getEmail())
                throw invalid_argument("usuario logado nao e o guia da excursao");
            
            while(true){
                clear_screen;
                cout << "\n EXCURSAO A EDITAR:\n";
                mostrarExcursao(excursao);

                string tituloInserido, cidadeInserida, duracaoInserida, descricaoInserida, enderecoInserido;

                cout << "Insira novo titulo: ";
                getline(cin, tituloInserido);
                cout << "Insira nova cidade: ";
                getline(cin, cidadeInserida);
                cout << "Insira nova duracao: ";
                getline(cin, duracaoInserida);
                cout << "Insira nova descricao: ";
                getline(cin, descricaoInserida);
                cout << "Insira novo endereco: ";
                getline(cin, enderecoInserido);

                try{
                    titulo.setTitulo(tituloInserido);
                    cidade.setCidade(cidadeInserida);
                    duracao.setDuracao(stoi(duracaoInserida));
                    descricao.setDescricao(descricaoInserida);
                    endereco.setEndereco(enderecoInserido);
                    
                    excursao.setTitulo(titulo);
                    excursao.setCidade(cidade);
                    excursao.setDuracao(duracao);
                    excursao.setDescricao(descricao);
                    excursao.setEndereco(endereco);
                    
                    continuar = false;
                    break;
                }
                catch(invalid_argument &exp){
                    cout << "Algum dado inserido e invalido. Insira: \n";
                    cout << tentarNovamente;
                    cout << "2, para voltar a escolha de excursao." << '\n';
                    opcao = getchar() - 48;
                    getline(cin, flush);
                    if (opcao == 2)
                        break;
                }
            }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido, ou a excursao desejada nao foi cadastrada por voce. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }

    if(cntr -> editarExcursao(excursao, email))
        cout << "Dados editados com sucesso.";
    else
        cout << "Falha ao editar dados.";
    cout << retornar;
    getline(cin, flush);
    return;
}

void CntrAprExcursao::descadastrarExcursao(Email email){
    list<Excursao> excursoes = cntr -> reunirExcursoes(email);
    list<Excursao> :: iterator excursao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da excursao a ser descadastrada: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            for(excursao = excursoes.begin(); excursao != excursoes.end(); ++excursao){
                if ((*excursao).getCodigo().getCodigo() == codigo.getCodigo()){
                    cntr -> deletarExcursao(*excursao, email);
                    continuar = false;
                    cout << "Excursao descadastrada com sucesso!\n";
                    cout << retornar;
                    getline(cin, flush);
                    return;
                }
            }
            if (excursao == excursoes.end()){
                cout << "Excursao nao encontrada. Insira: \n";
                cout << tentarNovamente;
                cout << retornarOpcao;
                opcao = getchar() - 48;
                getline(cin, flush);
                if (opcao == 2)
                    return;
            }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
}

void CntrAprExcursao::listarExcursoes(Email email){
    clear_screen;
    list<Excursao> excursoes = cntr -> reunirExcursoes(email);
    list<Excursao> :: iterator excursao;
    cout << "TODAS AS SUAS EXCURSOES: \n\n";
    for(excursao = excursoes.begin(); excursao != excursoes.end(); ++excursao){
        mostrarExcursao(*excursao);
    }
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
}

void CntrAprExcursao::listarSessoes(Email email){
    clear_screen;
    list<Sessao> sessoes = cntr -> reunirSessoes(email);
    list<Sessao> :: iterator sessao;

    cout << "TODAS AS SUAS SESSOES: \n\n";
    for(sessao = sessoes.begin(); sessao!= sessoes.end(); ++sessao){
        mostrarSessao(*sessao);
    }
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
} 

void CntrAprExcursao::listarSessao(Email email){
    list<Sessao> sessoes = cntr -> reunirSessoes(email);
    list<Sessao> :: iterator sessao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da sessao que deseja visualizar: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            for(sessao = sessoes.begin(); sessao != sessoes.end(); ++sessao){
                if((*sessao).getCodigo().getCodigo() == codigo.getCodigo()){
                    cout << "SESSAO SELECIONADA: \n\n";
                    mostrarSessao(*sessao);
                    continuar = false;
                    cout << retornar;
                    getline(cin, flush);
                    return;
                }
            }
            if(sessao == sessoes.end()){
                cout << "Nao ha sessao cadastrada por voce com codigo inserido. Insira: \n";
                cout << tentarNovamente;
                cout << retornarOpcao;
                opcao = getchar() - 48;
                getline(cin, flush);
                if (opcao == 2)
                    return;
            }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
}

void CntrAprExcursao::cadastrarSessao(Email email){
    int opcao;
    string codigoInserido, dataInserida, horarioInserido, idiomaInserido;
    Codigo codigoExcursao, codigoSessao;
    Data data;
    Horario horario;
    Idioma idioma;
    Sessao sessao;

    unordered_set<Codigo> codigosCadastrados = cntr -> reunirCodigosSessoes(email);
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "INSIRA OS DADOS DA SESSAO A SER CADASTRADA: \n\n";
        cout << "Insira o codigo da excursao: ";
        getline(cin, codigoInserido);
        cout << "Insira a data da sessao: ";
        getline(cin, dataInserida);
        cout << "Insira o horario da sessao: ";
        getline(cin, horarioInserido);
        cout << "Insira o idioma da sessao: ";
        getline(cin, idiomaInserido);

        try{
            codigoExcursao.setCodigo(codigoInserido);

            if (codigosCadastrados.count(codigoExcursao) == 1){
                cout << "Voce ja possui uma sessao cadastrada para essa excursao. Insira: \n";
                cout << tentarNovamente;
                cout << retornarOpcao;
                opcao = getchar() - 48;
                getline(cin, flush);
                if (opcao == 2)
                    return;
            }

            data.setData(dataInserida);
            horario.setHorario(horarioInserido);
            idioma.setIdioma(idiomaInserido);

            continuar = false;
            codigoSessao.setCodigo(cntr -> gerarCodigo());
        }
        catch(invalid_argument &exp){
            cout << "Algum dado inserido para a sessao e invalido, ou a excursao desejada nao existe.\n";
            cout << "Lembre-se do formato correto para os dados. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
    sessao.setCodigo(codigoSessao);
    sessao.setData(data);
    sessao.setHorario(horario);
    sessao.setIdioma(idioma);

    if (cntr -> cadastrarSessao(sessao, email, codigoExcursao)){
        cout << "Sessao cadastrada com sucesso.\n";
        cout << "Codigo da sessao: " << sessao.getCodigo().getCodigo() << '\n';
        cout << "Tecle enter para retornar ao menu anterior.\n";
        getline(cin, flush);
        return;
    }
    cout << "Falha ao cadastrar sessao. Tente novamente.\n";
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
    return;
}

void CntrAprExcursao::editarSessao(Email email){
    Codigo codigo;
    Data data;
    Horario horario;
    Idioma idioma;
    Sessao sessao, aCadastrar;
    int opcao;
    string codigoInserido;
    bool continuar = true;

    while(continuar){
        try{
            clear_screen;
            cout << "EDITAR DADOS DE SESSAO\n";
            cout << "Insira o codigo da sessao a ser editada: \n";
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            
            sessao = cntr -> obterSessao(codigo);
                clear_screen;
                cout << "\nSESSAO A EDITAR:\n";
                mostrarSessao(sessao);

                string dataInserida, horarioInserido, idiomaInserido;

                cout << "Insira nova data: ";
                getline(cin, dataInserida);
                cout << "Insira novo horario: ";
                getline(cin, horarioInserido);
                cout << "Insira novo idioma: ";
                getline(cin, idiomaInserido);

                try{
                    data.setData(dataInserida);
                    horario.setHorario(horarioInserido);
                    idioma.setIdioma(idiomaInserido);
                    
                    aCadastrar.setCodigo((sessao).getCodigo());
                    aCadastrar.setData(data);
                    aCadastrar.setHorario(horario);
                    aCadastrar.setIdioma(idioma);

                    continuar = false;
                }
                catch(invalid_argument &exp){
                    cout << "Algum dado inserido e invalido. Insira: \n";
                    cout << tentarNovamente;
                    cout << "2, para voltar a escolha de sessao." << '\n';
                    opcao = getchar() - 48;
                    getline(cin, flush);
                    if (opcao == 2)
                        return;
                }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido, ou a sessao desejada nao foi cadastrada. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }

    if(cntr -> editarSessao(aCadastrar, email))
        cout << "Dados editados com sucesso.";
    else
        cout << "Falha ao editar dados.";
    cout << retornar;
    getline(cin, flush);
    return;
}

void CntrAprExcursao::descadastrarSessao(Email email){
    list<Sessao> sessoes = cntr -> reunirSessoes(email);
    list<Sessao> :: iterator sessao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da sessao a ser descadastrada: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            for(sessao = sessoes.begin(); sessao != sessoes.end(); ++sessao){
                if ((*sessao).getCodigo().getCodigo() == codigo.getCodigo()){
                    cntr -> deletarSessao(*sessao,email);
                    continuar = false;
                    cout << "Sessao descadastrada com sucesso!\n";
                    cout << retornar;
                    getline(cin, flush);
                    return;
                }
            }
            if (sessao == sessoes.end()){
                cout << "Sessao nao encontrada. Insira: \n";
                cout << tentarNovamente;
                cout << retornarOpcao;
                opcao = getchar() - 48;
                getline(cin, flush);
                if (opcao == 2)
                    return;
            }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
}

void CntrAprExcursao::sessoesExcursoes(Email email){
    list<Excursao> excursoes = cntr -> reunirExcursoes(email);
    list<Excursao> :: iterator excursao;
    Codigo codigo;

    clear_screen;
    if (!excursoes.empty()){
        cout << "SESSOES ENCONTRADAS:\n\n";
        for(excursao = excursoes.begin(); excursao != excursoes.end(); ++excursao){
            codigo = (*excursao).getCodigo();
            cout << "Sessoes da excursao " << codigo.getCodigo() << ":\n";
            list<Sessao> sessoes = cntr -> reunirSessoes(codigo);
            list<Sessao> :: iterator sessao;
            
            if (!sessoes.empty()){
                for(sessao = sessoes.begin(); sessao != sessoes.end(); ++sessao){
                    mostrarSessao(*sessao);
                }
            }
            else{
                cout << "Nao ha sessao cadastrada para essa excursao.\n";
            }

            cout << "############################################################################\n";
        }
        cout << "Tecle enter para retornar ao menu anterior.\n";
        getline(cin, flush);
        return;
    }

    cout << "Voce nao possui excursoes cadastradas.\n";
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
    return;
}

void CntrAprExcursao::sessoesExcursao(Email email){
    list<Excursao> excursoes = cntr -> reunirExcursoes(email);
    list<Excursao> :: iterator excursao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da excursao a qual deseja visualizar as sessoes: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            for(excursao = excursoes.begin(); excursao != excursoes.end(); ++excursao){
                if((*excursao).getCodigo().getCodigo() == codigo.getCodigo()){
                    cout << "SESSOES ENCONTRADAS:\n\n";
                    list<Sessao> sessoes = cntr -> reunirSessoes(codigo);
                    list<Sessao> :: iterator sessao;
                    
                    if (!sessoes.empty()){
                        for(sessao = sessoes.begin(); sessao != sessoes.end(); ++sessao){
                            mostrarSessao(*sessao);
                        }
                    }
                    else{
                        cout << "Nao ha sessao cadastrada para essa excursao.\n";
                    }
                    cout << "############################################################################\n";
                    cout << "Tecle enter para retornar ao menu anterior.\n";
                    getline(cin, flush);
                    return;
                }
            }
            cout << "A excursao desejada nao foi cadastrada por voce, ou nao existe. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
}

void CntrAprExcursao::listarAvaliacoesUsuario(Email email){
    list<Avaliacao> avaliacoes = cntr -> reunirAvaliacoes(email);
    list<Avaliacao> :: iterator avaliacao;
    Codigo codigo;

    clear_screen;
    if (!avaliacoes.empty()){
        cout << "SUAS AVALIACOES:\n\n";
        for(avaliacao = avaliacoes.begin(); avaliacao != avaliacoes.end(); ++avaliacao){
            mostrarAvaliacao(*avaliacao);
        }
        cout << "Tecle enter para retornar ao menu anterior.\n";
        getline(cin, flush);
        return;
    }

    cout << "Voce nao possui avaliacoes cadastradas.\n";
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
    return;
}

void CntrAprExcursao::listarAvaliacoesExcursao(Email email){
    list<Excursao> excursoes = cntr -> reunirExcursoes(email);
    list<Excursao> :: iterator excursao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da excursao que deseja visualizar as avaliacoes: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            for(excursao = excursoes.begin(); excursao != excursoes.end(); ++excursao){
                if((*excursao).getCodigo().getCodigo() == codigo.getCodigo()){
                    cout << "EXCURSAO SELECIONADA: \n\n";
                    mostrarExcursao(*excursao);

                    list<Avaliacao> avaliacoes = cntr -> reunirAvaliacoes(codigo);
                    list<Avaliacao> :: iterator avaliacao;
                    if (!avaliacoes.empty()){
                        cout << "AVALIACOES:\n\n";
                        for(avaliacao = avaliacoes.begin(); avaliacao != avaliacoes.end(); ++avaliacao){
                            mostrarAvaliacao(*avaliacao);
                        }
                    }
                    cout << "A excursao selecionada nao possui avaliacoes. Insira:\n";
                    cout << tentarNovamente;
                    cout << retornarOpcao;
                    opcao = getchar() - 48;
                    getline(cin, flush);
                    if (opcao == 2)
                        return;
                }
            }
            if(excursao == excursoes.end()){
            cout << "Nao ha excursao cadastrada por voce com codigo inserido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
            }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
}

void CntrAprExcursao::cadastrarAvaliacao(Email email){
    int opcao;
    string codigoInserido, notaInserida, descricaoInserida;
    Codigo codigoA, codigoE;
    Nota nota;
    Descricao descricao;
    Avaliacao avaliacao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "INSIRA OS DADOS DA AVALIACAO A SER CADASTRADA: \n\n";
        cout << "Insira o codigo da excursao: ";
        getline(cin, codigoInserido);
        cout << "Insira a nota para a excursao: ";
        getline(cin, notaInserida);
        cout << "Insira a descricao da avaliacao: ";
        getline(cin, descricaoInserida);

        try{
            codigoE.setCodigo(codigoInserido);
            cntr -> obterExcursao(codigoE);
            nota.setNota(stoi(notaInserida));
            descricao.setDescricao(descricaoInserida);

            continuar = false;
        }
        catch(invalid_argument &exp){
            cout << "Algum dado inserido para a avaliacao e invalido, ou a excursao desejada nao existe.\n";
            cout << "Lembre-se do formato correto para os dados. Insira: ";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
    codigoA.setCodigo(cntr -> gerarCodigo());

    avaliacao.setCodigo(codigoA);
    avaliacao.setDescricao(descricao);
    avaliacao.setNota(nota);

    if (cntr -> cadastrarAvaliacao(avaliacao, email, codigoE)){
        cout << "Avaliacao cadastrada com sucesso.\n";
        cout << "Tecle enter para retornar ao menu anterior.\n";
        getline(cin, flush);
        return;
    }
    cout << "Falha ao cadastrar avaliacao. Tente novamente.\n";
    cout << "Tecle enter para retornar ao menu anterior.\n";
    getline(cin, flush);
    return;
}

void CntrAprExcursao::editarAvaliacao(Email email){
    Codigo codigo;
    Nota nota;
    Descricao descricao;
    Avaliacao avaliacao, aCadastrar;
    int opcao;
    string codigoInserido;
    bool continuar = true;
    bool encontrada = false;

    while(continuar){
        try{
            clear_screen;
            cout << "EDITAR DADOS DE SESSAO\n";
            cout << "Insira o codigo da sessao a ser editada: \n";
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            
            avaliacao = cntr -> obterAvaliacao(codigo);
                clear_screen;
                cout << "\nSESSAO A EDITAR:\n";
                mostrarAvaliacao(avaliacao);

                string notaInserida, descricaoInserida;

                cout << "Insira nova data: ";
                getline(cin, notaInserida);
                cout << "Insira novo horario: ";
                getline(cin, descricaoInserida);

                try{
                    nota.setNota(stoi(notaInserida));
                    descricao.setDescricao(descricaoInserida);
                    
                    aCadastrar.setCodigo((avaliacao).getCodigo());
                    aCadastrar.setNota(nota);
                    aCadastrar.setDescricao(descricao);

                    continuar = false;
                }
                catch(invalid_argument &exp){
                    cout << "Algum dado inserido e invalido. Insira: \n";
                    cout << tentarNovamente;
                    cout << "2, para voltar a escolha de sessao." << '\n';
                    opcao = getchar() - 48;
                    getline(cin, flush);
                    if (opcao == 2)
                        return;
                }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido, ou a sessao desejada nao foi cadastrada. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }

    if(cntr -> editarAvaliacao(aCadastrar, email))
        cout << "Dados editados com sucesso.";
    else
        cout << "Falha ao editar dados.";
    cout << retornar;
    getline(cin, flush);
    return;
}

void CntrAprExcursao::descadastrarAvaliacao(Email email){
    list<Avaliacao> avaliacoes = cntr -> reunirAvaliacoes(email);
    list<Avaliacao> :: iterator avaliacao;
    Codigo codigo;
    string codigoInserido;
    int opcao;
    bool continuar = true;

    while(continuar){
        clear_screen;
        cout << "Insira o codigo da avaliacao a ser descadastrada: ";
        try{
            getline(cin, codigoInserido);
            codigo.setCodigo(codigoInserido);
            for(avaliacao = avaliacoes.begin(); avaliacao != avaliacoes.end(); ++avaliacao){
                if ((*avaliacao).getCodigo().getCodigo() == codigo.getCodigo()){
                    cntr -> deletarAvaliacao(*avaliacao, email);
                    continuar = false;
                    cout << "Avaliacao descadastrada com sucesso!\n";
                    cout << retornar;
                    getline(cin, flush);
                    return;
                }
            }
            if (avaliacao == avaliacoes.end()){
                cout << "Avaliacao nao encontrada. Insira: \n";
                cout << tentarNovamente;
                cout << retornarOpcao;
                opcao = getchar() - 48;
                getline(cin, flush);
                if (opcao == 2)
                    return;
            }
        }
        catch(invalid_argument &exp){
            cout << "Codigo invalido. Insira: \n";
            cout << tentarNovamente;
            cout << retornarOpcao;
            opcao = getchar() - 48;
            getline(cin, flush);
            if (opcao == 2)
                return;
        }
    }
}

void CntrAprExcursao::mostrarExcursao(Excursao excursao){
    cout << "Excursao codigo: " << excursao.getCodigo().getCodigo() << '\n';
    cout << "Titulo: " << excursao.getTitulo().getTitulo() << '\n';
    cout << "Nota: " << cntr -> obterNotaExcursao(excursao.getCodigo()) << '\n';
    cout << "Cidade: " << excursao.getCidade().getCidade() << '\n';
    cout << "Duracao: " << excursao.getDuracao().getDuracao() << '\n';
    cout << "Descricao: " << excursao.getDescricao().getDescricao() << '\n';
    cout << "Endereco: " << excursao.getEndereco().getEndereco() << '\n';
    cout << "----------------------------------------------------------------------------\n";
}

void CntrAprExcursao::mostrarSessao(Sessao sessao){
    cout << "Sessao codigo : " << sessao.getCodigo().getCodigo() << '\n';
    cout << "Data   : " << sessao.getData().getData() << '\n';
    cout << "Horario: " << sessao.getHorario().getHorario() << '\n';
    cout << "Idioma : " << sessao.getIdioma().getIdioma() << '\n';
    cout << "----------------------------------------------------------------------------\n";
}

void CntrAprExcursao::mostrarAvaliacao(Avaliacao avaliacao){
    cout << "Avaliacao de codigo : " << avaliacao.getCodigo().getCodigo() << '\n';
    cout << "Nota   : " << avaliacao.getNota().getNota() << '\n';
    cout << "Descricao : " << avaliacao.getDescricao().getDescricao() << '\n';
    cout << "----------------------------------------------------------------------------\n";
}