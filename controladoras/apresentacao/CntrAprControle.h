#ifndef CNTRAPRCONTROLE_H_INCLUDED
#define CNTRAPRCONTROLE_H_INCLUDED

#include "../../interfaces.h"

class CntrAprControle{
    private:
        string flush;

        Email email;
        IApresentacaoAutenticacao *cntrAprAutenticacao;
        IApresentacaoUsuario *cntrAprUsuario;
        IApresentacaoExcursao *cntrAprExcursao;
    public:
        void executar();
        void setCntrAprAutenticacao(IApresentacaoAutenticacao *cntr){
            cntrAprAutenticacao = cntr;
        }
        void setCntrAprUsuario(IApresentacaoUsuario *cntr){
            cntrAprUsuario = cntr;
        }
        void setCntrAprExcursao(IApresentacaoExcursao *cntr){
            cntrAprExcursao = cntr;
        }
};

#endif //CNTRAPRCONTROLE_H_INCLUDED