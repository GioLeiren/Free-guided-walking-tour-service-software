#ifndef CNTRSERVUSUARIO_H_INCLUDED
#define CNTRSERVUSUARIO_H_INCLUDED

#include "../../interfaces.h"

class CntrServUsuario:public IServicoUsuario{
    private:
        IServicoExcursao *cntr;
        static unordered_map<Email, Usuario> usuariosCadastrados;
    public:
        bool cadastrar(Usuario);
        bool descadastrar(Email);
        bool alterar(Usuario);
        Usuario obter(Email);
        void setCntrServExcursao(IServicoExcursao *cntr){
                this -> cntr = cntr;
        }
};

#endif //CNTRSERVUSUARIO_H_INCLUDED