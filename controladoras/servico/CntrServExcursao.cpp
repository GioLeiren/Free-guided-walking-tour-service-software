#include "CntrServExcursao.h"

void CntrServExcursao::cadastrarAtividadesUsuario(Email email){
    pair<Email, list<Excursao>> excursoes {email, {}};
    pair<Email, list<Sessao>> sessoes {email, {}};
    pair<Email, list<Avaliacao>> avaliacoes {email, {}};

    excursoesPorUsuario.insert(excursoes);
    sessoesPorUsuario.insert(sessoes);
    avaliacoesPorUsuario.insert(avaliacoes);
}

void CntrServExcursao::descadastrarAtividadesUsuario(Email email){
    for (Excursao const &excursao : reunirExcursoes(email)){
        deletarExcursao(excursao, email);
    }
    excursoesPorUsuario.erase(email);
    sessoesPorUsuario.erase(email);
    avaliacoesPorUsuario.erase(email);
}

string CntrServExcursao::gerarCodigo(){
    while(true){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, 999999);
        int num = distr(gen);
        string codigo = to_string(num);
        codigo = (string(6 - codigo.size(), '0')) + codigo;
        Codigo aValidar;
        int i;
        for(i = 0; i != 10; ++i){
            try{
                aValidar.setCodigo(codigo + to_string(i));
                return codigo + to_string(i);
            }
            catch(invalid_argument &exp){}
        }
    }
}

unordered_map<Email, list<Excursao>> CntrServExcursao::excursoesPorUsuario = {};
unordered_map<Codigo, Excursao> CntrServExcursao::excursoesUnicas = {};
unordered_map<Codigo, Email> CntrServExcursao::guiasExcursoes = {};

bool CntrServExcursao:: cadastrarExcursao(Excursao excursao, Email email){
    pair<Codigo, Excursao> cCadastrar {excursao.getCodigo(), excursao};
    if ((excursoesUnicas.insert(cCadastrar)).second){

        pair<Codigo, list<Sessao>> sessoes {excursao.getCodigo(), {}};
        pair<Codigo, list<Avaliacao>> avaliacoes {excursao.getCodigo(), {}};
        sessoesPorCodigo.insert(sessoes);
        avaliacoesPorCodigo.insert(avaliacoes);

        pair<Codigo, Email> gCadastrar {excursao.getCodigo(), email};
        guiasExcursoes.insert(gCadastrar);
        list<Excursao> listaE = excursoesPorUsuario.at(email);
        listaE.push_back(excursao);
        excursoesPorUsuario[email] = listaE;
        return true;
    }
    return false;
}

bool CntrServExcursao:: editarExcursao(Excursao excursao, Email email){
    excursoesUnicas.erase(excursao.getCodigo());
    excursoesUnicas[excursao.getCodigo()] = excursao;

    list<Excursao> listaE = excursoesPorUsuario.at(email);
    listaE.remove_if([this, excursao](const Excursao &excursaoEmLista){return compararExcursoes(excursao, excursaoEmLista);});
    listaE.push_back(excursao);
    excursoesPorUsuario[email] = listaE;
    return true;
}

Excursao CntrServExcursao:: obterExcursao(Codigo codigo){
    try{
        return excursoesUnicas.at(codigo);
    }
    catch(out_of_range &exp){
        throw invalid_argument("codigo invalido");
    }
}

float CntrServExcursao:: obterNotaExcursao(Codigo codigo){
    int quant = 0;
    float soma = 0;
    for(auto const &[key, val]: avaliacoesPorCodigo){
        for(Avaliacao const &avaliacao: val){
            quant += 1;
            soma += avaliacao.getNota().getNota();
        }
    }
    return soma/quant;
}

list<Excursao> CntrServExcursao::reunirExcursoes(){
    list<Excursao> lista {};
    for(auto const &[key, val] : excursoesUnicas){
        lista.push_back(val);
    }
    return lista;
}

list<Excursao> CntrServExcursao:: reunirExcursoes(Email email){
    return excursoesPorUsuario.at(email);
}

Email CntrServExcursao:: obterGuiaExcursao(Codigo codigo){
    return guiasExcursoes.at(codigo);
}

bool CntrServExcursao:: compararExcursoes(Excursao excursao1, Excursao excursao2){
    return excursao1.getCodigo() == excursao2.getCodigo();
}

void CntrServExcursao:: deletarExcursao(Excursao excursao, Email email){
    excursoesUnicas.erase(excursao.getCodigo());
    list<Excursao> listaE = excursoesPorUsuario.at(email);
    listaE.remove_if([this, excursao](const Excursao &excursaoEmLista){return compararExcursoes(excursao, excursaoEmLista);});
    excursoesPorUsuario[email] = listaE;
    guiasExcursoes.erase(excursao.getCodigo());
    sessoesPorCodigo.erase(excursao.getCodigo());
    avaliacoesPorCodigo.erase(excursao.getCodigo());
}

unordered_map<Email, list<Sessao>> CntrServExcursao::sessoesPorUsuario = {};
unordered_map<Codigo, list<Sessao>> CntrServExcursao::sessoesPorCodigo = {};

bool CntrServExcursao:: cadastrarSessao(Sessao sessao, Email email, Codigo codigo){
    list<Sessao> listaSC = sessoesPorCodigo.at(codigo);
    listaSC.push_back(sessao);
    sessoesPorCodigo[codigo] = listaSC;
    list<Sessao> listaS = sessoesPorUsuario.at(email);
    listaS.push_back(sessao);
    sessoesPorUsuario[email] = listaS;
    return true;
}

bool CntrServExcursao:: editarSessao(Sessao sessao, Email email){
    for(auto const &[key, val]: sessoesPorCodigo){
        for(auto const &elemento: val){
            if (sessao.getCodigo() == elemento.getCodigo()){
                deletarSessao(sessao, email);
                return cadastrarSessao(sessao, email, key);
            }
        }
    }
    return false;
}

Sessao CntrServExcursao::obterSessao(Codigo codigo){
    Sessao s;
    for(auto const &[key, val] : sessoesPorCodigo){
        for(Sessao const &sessao : val){
            if (codigo == sessao.getCodigo()){
                return sessao;
            }
        }
    }
    return s;
}

list<Sessao> CntrServExcursao:: reunirSessoes(Email email){
    return sessoesPorUsuario.at(email);
}

list<Sessao> CntrServExcursao:: reunirSessoes(Codigo codigo){
    return sessoesPorCodigo.at(codigo);

}

unordered_set<Codigo> CntrServExcursao:: reunirCodigosSessoes(Email email){
    unordered_set<Codigo> codigosDeExcursoes;
    list<Sessao> sessoesDoUsuario = sessoesPorUsuario.at(email);
    for(Sessao const &sessao: sessoesDoUsuario){
        for(auto const &[key, val]: sessoesPorCodigo){
            for(auto const &elemento: val){
                if (sessao.getCodigo() == elemento.getCodigo()){
                    codigosDeExcursoes.insert(key);
                }
            }
        }
    }
    return codigosDeExcursoes;
}

bool CntrServExcursao:: compararSessoes(Sessao sessao1, Sessao sessao2){
    return sessao1.getCodigo() == sessao2.getCodigo();
}

void CntrServExcursao:: deletarSessao(Sessao sessao, Email email){
    list<Sessao> listaS = sessoesPorUsuario.at(email);
    listaS.remove_if([this, sessao](const Sessao &sessaoEmLista){return compararSessoes(sessao, sessaoEmLista);});
    sessoesPorUsuario[email] = listaS;
    for(auto &[key, val]: sessoesPorCodigo){
        val.remove_if([this, sessao](const Sessao &sessaoEmLista){return compararSessoes(sessao, sessaoEmLista);});
        sessoesPorCodigo[key] = val;
    }
}




unordered_map<Email, list<Avaliacao>> CntrServExcursao::avaliacoesPorUsuario = {};
unordered_map<Codigo, list<Avaliacao>> CntrServExcursao::avaliacoesPorCodigo = {};

bool CntrServExcursao:: cadastrarAvaliacao(Avaliacao avaliacao, Email email, Codigo codigo){
    list<Avaliacao> listaAC = avaliacoesPorCodigo.at(codigo);
    listaAC.push_back(avaliacao);
    avaliacoesPorCodigo[codigo] = listaAC;
    list<Avaliacao> listaS = avaliacoesPorUsuario.at(email);
    listaS.push_back(avaliacao);
    avaliacoesPorUsuario[email] = listaS;
    return true;
}

bool CntrServExcursao:: editarAvaliacao(Avaliacao avaliacao, Email email){
    for(auto const &[key, val]: avaliacoesPorCodigo){
        for(auto const &elemento: val){
            if (avaliacao.getCodigo() == elemento.getCodigo()){
                deletarAvaliacao(avaliacao, email);
                return cadastrarAvaliacao(avaliacao, email, key);
            }
        }
    }
    return false;
}

Avaliacao CntrServExcursao::obterAvaliacao(Codigo codigo){
    Avaliacao a;
    for(auto const &[key, val] : avaliacoesPorCodigo){
        for(Avaliacao const &avaliacao : val){
            if (codigo == avaliacao.getCodigo()){
                return avaliacao;
            }
        }
    }
    return a;
}

list<Avaliacao> CntrServExcursao:: reunirAvaliacoes(Codigo codigo){
    return avaliacoesPorCodigo.at(codigo);
}

list<Avaliacao> CntrServExcursao:: reunirAvaliacoes(Email email){
    return avaliacoesPorUsuario.at(email);
}

bool CntrServExcursao:: compararAvaliacoes(Avaliacao avaliacao1, Avaliacao avaliacao2){
    return avaliacao1.getCodigo() == avaliacao2.getCodigo();
}

void CntrServExcursao:: deletarAvaliacao(Avaliacao avaliacao, Email email){
    list<Avaliacao> listaS = avaliacoesPorUsuario.at(email);
    listaS.remove_if([this, avaliacao](const Avaliacao &avaliacaoEmLista){return compararAvaliacoes(avaliacao, avaliacaoEmLista);});
    avaliacoesPorUsuario[email] = listaS;
    for(auto &[key, val]: avaliacoesPorCodigo){
        val.remove_if([this, avaliacao](const Avaliacao &avaliacaoEmLista){return compararAvaliacoes(avaliacao, avaliacaoEmLista);});
        avaliacoesPorCodigo[key] = val;
    }
}