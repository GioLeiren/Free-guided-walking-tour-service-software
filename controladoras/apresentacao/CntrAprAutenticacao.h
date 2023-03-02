#ifndef CNTRAPRAUTENTICACAO_H_INCLUDED
#define CNTRAPRAUTENTICACAO_H_INCLUDED

#include "../../interfaces.h"


class CntrAprAutenticacao:public IApresentacaoAutenticacao{
    private:
        IServicoAutenticacao *cntr;
        IServicoUsuario *cntrU;
    public:
        bool autenticar(Email*);
        void setCntrServAutenticacao(IServicoAutenticacao *cntr){
            this -> cntr = cntr;
        }
        void setCntrServUsuario(IServicoUsuario *cntr){
            this -> cntrU = cntr;
        }
};

#endif //CNTRAPRAUTENTICACAO_H_INCLUDED