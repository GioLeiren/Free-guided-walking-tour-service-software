#ifndef CNTRAPRUSUARIO_H_INCLUDED
#define CNTRAPRUSUARIO_H_INCLUDED

#include "../../interfaces.h"

class CntrAprUsuario:public IApresentacaoUsuario{
    private:
        string flush;
        IServicoUsuario *cntr;
        void mostrarUsuario(Email);
        void editarUsuario(Email);
        bool excluirUsuario(Email);
    public:
        void cadastrar();
        bool executar(Email);
        void setCntrServUsuario(IServicoUsuario *cntr){
            this -> cntr = cntr;
        }
};

#endif //CNTRAPRUSUARIO_H_INCLUDED