#ifndef CNTRSERVEXCURSAO_H_INCLUDED
#define CNTRSERVEXCURSAO_H_INCLUDED

#include "../../interfaces.h"
class CntrServExcursao: public IServicoExcursao{
    private:
        static unordered_map<Email, list<Excursao>> excursoesPorUsuario;
        static unordered_map<Codigo, Excursao> excursoesUnicas;
        static unordered_map<Codigo, Email> guiasExcursoes;
        static unordered_map<Email, list<Sessao>> sessoesPorUsuario;
        static unordered_map<Codigo, list<Sessao>> sessoesPorCodigo;
        static unordered_map<Email, list<Avaliacao>> avaliacoesPorUsuario;
        static unordered_map<Codigo, list<Avaliacao>> avaliacoesPorCodigo;
        bool compararExcursoes(Excursao, Excursao);
        bool compararSessoes(Sessao, Sessao);
        bool compararAvaliacoes(Avaliacao, Avaliacao);

    public:
        string gerarCodigo();

        void cadastrarAtividadesUsuario(Email);
        void descadastrarAtividadesUsuario(Email);

        bool cadastrarExcursao(Excursao, Email);
        bool editarExcursao(Excursao, Email);
        Excursao obterExcursao(Codigo);
        float obterNotaExcursao(Codigo);
        list<Excursao> reunirExcursoes();
        list<Excursao> reunirExcursoes(Email);
        Email obterGuiaExcursao(Codigo);
        void deletarExcursao(Excursao, Email);

        bool cadastrarSessao(Sessao, Email, Codigo);
        bool editarSessao(Sessao, Email);
        Sessao obterSessao(Codigo);
        list<Sessao> reunirSessoes(Email);
        list<Sessao> reunirSessoes(Codigo);
        unordered_set<Codigo> reunirCodigosSessoes(Email);
        void deletarSessao(Sessao, Email);

        bool cadastrarAvaliacao(Avaliacao, Email, Codigo);
        bool editarAvaliacao(Avaliacao, Email);
        Avaliacao obterAvaliacao(Codigo);
        list<Avaliacao> reunirAvaliacoes(Codigo);
        list<Avaliacao> reunirAvaliacoes(Email);
        void deletarAvaliacao(Avaliacao, Email);
};

#endif // CNTRSERVEXCURSAO_H_INCLUDED