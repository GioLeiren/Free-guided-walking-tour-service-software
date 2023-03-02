#ifndef CNTRSERVAUTENTICACAO_H_INCLUDED
#define CNTRSERVAUTENTICACAO_H_INCLUDED

#include "../../interfaces.h"

class CntrServAutenticacao:public IServicoAutenticacao{
    private:
        IServicoUsuario *cntr;
    public:
        bool autenticar(Email, Senha);
        void setCntrServUsuario(IServicoUsuario *cntr){
            this -> cntr = cntr;
        }
};

#endif //CNTRSERVAUTENTICACAO_H_INCLUDED