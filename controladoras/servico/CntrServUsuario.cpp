#include "CntrServUsuario.h"

unordered_map<Email, Usuario> CntrServUsuario::usuariosCadastrados = {};

bool CntrServUsuario::cadastrar(Usuario usuario){
    pair<Email, Usuario> aCadastrar {usuario.getEmail(), usuario};
    cntr -> cadastrarAtividadesUsuario(usuario.getEmail());
    return (usuariosCadastrados.insert(aCadastrar)).second;
}

bool CntrServUsuario::descadastrar(Email email){
    cntr -> descadastrarAtividadesUsuario(email);
    return usuariosCadastrados.erase(email);
}

bool CntrServUsuario::alterar(Usuario usuario){
    usuariosCadastrados[usuario.getEmail()] = usuario;
    return true;
}

Usuario CntrServUsuario::obter(Email email){
    return usuariosCadastrados.at(email);
}