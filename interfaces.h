#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"

#define clear_screen system("cls");

class IServicoAutenticacao;
class IServicoUsuario;
class IServicoExcursao;

class IApresentacaoAutenticacao{
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServAutenticacao(IServicoAutenticacao*) = 0;
        virtual void setCntrServUsuario(IServicoUsuario*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoUsuario{
    public:
        virtual void cadastrar() = 0;
        virtual bool executar(Email) = 0;
        virtual void setCntrServUsuario(IServicoUsuario*) = 0;
        virtual ~IApresentacaoUsuario(){}
};

class IApresentacaoExcursao{
    public:
        virtual void executar() = 0;
        virtual void executar(Email) = 0;
        virtual void setCntrServExcursao(IServicoExcursao*) = 0;
        virtual ~IApresentacaoExcursao(){}
};

////////////////////////////////////////////////////////////////////////

class IServicoAutenticacao{
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual void setCntrServUsuario(IServicoUsuario*) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoExcursao{
    public:
        virtual string gerarCodigo() = 0;

        virtual void cadastrarAtividadesUsuario(Email) = 0;
        virtual void descadastrarAtividadesUsuario(Email) = 0;

        virtual bool cadastrarExcursao(Excursao, Email) = 0;
        virtual bool editarExcursao(Excursao, Email) = 0;
        virtual Excursao obterExcursao(Codigo) = 0;
        virtual float obterNotaExcursao(Codigo) = 0;
        virtual list<Excursao> reunirExcursoes() = 0;
        virtual list<Excursao> reunirExcursoes(Email) = 0;
        virtual Email obterGuiaExcursao(Codigo) = 0;
        virtual void deletarExcursao(Excursao, Email) = 0;

        virtual bool cadastrarSessao(Sessao, Email, Codigo) = 0;
        virtual bool editarSessao(Sessao, Email) = 0;
        virtual Sessao obterSessao(Codigo) = 0;
        virtual list<Sessao> reunirSessoes(Email) = 0;
        virtual list<Sessao> reunirSessoes(Codigo) = 0;
        virtual unordered_set<Codigo> reunirCodigosSessoes(Email) = 0;
        virtual void deletarSessao(Sessao, Email) = 0;

        virtual bool cadastrarAvaliacao(Avaliacao, Email, Codigo) = 0;
        virtual bool editarAvaliacao(Avaliacao, Email) = 0;
        virtual Avaliacao obterAvaliacao(Codigo) = 0;
        virtual list<Avaliacao> reunirAvaliacoes(Codigo) = 0;
        virtual list<Avaliacao> reunirAvaliacoes(Email) = 0;
        virtual void deletarAvaliacao(Avaliacao, Email) = 0;

        virtual ~IServicoExcursao(){}
};

class IServicoUsuario{
    public:
        virtual bool cadastrar(Usuario) = 0;
        virtual bool descadastrar(Email) = 0;
        virtual bool alterar(Usuario) = 0;
        virtual Usuario obter(Email) = 0;
        virtual void setCntrServExcursao(IServicoExcursao*) = 0;
        virtual ~IServicoUsuario(){};
};

#endif //INTERFACES_H_INCLUDED