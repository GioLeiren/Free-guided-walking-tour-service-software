#include "CntrServAutenticacao.h"

bool CntrServAutenticacao::autenticar(Email email, Senha senha){
    try{
        Usuario usuario = cntr -> obter(email);
        if (usuario.getSenha().getSenha() == senha.getSenha())
            return true;
        return false;
    }
    catch(out_of_range &exp){
        return false;
    }
}