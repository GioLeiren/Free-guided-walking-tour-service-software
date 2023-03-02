#ifndef CNTRAPREXCURSAO_H_INCLUDED
#define CNTRAPREXCURSAO_H_INCLUDED

#include "../../interfaces.h"

class CntrAprExcursao:public IApresentacaoExcursao{
    private:
        string flush;

        IServicoExcursao *cntr;

        void servicosSessoes(Email);
        void servicosAvaliacoes(Email);

        void listarExcursoes();
        void listarExcursao();
        void cadastrarExcursao(Email);
        void editarExcursao(Email);
        void descadastrarExcursao(Email);
        void listarExcursoes(Email);

        void listarSessoes(Email);
        void listarSessao(Email);
        void cadastrarSessao(Email);
        void editarSessao(Email);
        void descadastrarSessao(Email);
        void sessoesExcursoes(Email);
        void sessoesExcursao(Email);
        
        void listarAvaliacoesExcursao(Email);
        void listarAvaliacoesUsuario(Email);
        void cadastrarAvaliacao(Email);
        void editarAvaliacao(Email);
        void descadastrarAvaliacao(Email);

        void mostrarExcursao(Excursao);
        void mostrarSessao(Sessao);
        void mostrarAvaliacao(Avaliacao);
        
        string tentarNovamente = "1, para tentar novamente;\n";
        string retornarOpcao = "2, para voltar ao menu anterior.\n";
        string retornar = "Tecle enter para retornar ao menu anterior.\n";

    public:
        void executar();
        void executar(Email);
        void setCntrServExcursao(IServicoExcursao *cntr){
            this -> cntr = cntr;
        }
};

#endif //CNTRAPREXCURSAO_H_INCLUDED