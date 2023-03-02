#include "interfaces.h"
#include "./controladoras/apresentacao/CntrAprControle.h"
#include "./controladoras/apresentacao/CntrAprAutenticacao.h"
#include "./controladoras/apresentacao/CntrAprExcursao.h"
#include "./controladoras/apresentacao/CntrAprUsuario.h"
#include "./controladoras/servico/CntrServUsuario.h"
#include "./controladoras/servico/CntrServAutenticacao.h"
#include "./controladoras/servico/CntrServExcursao.h"


int main(){
    CntrAprControle *cntrAprControle;
    IApresentacaoAutenticacao *cntrAprAutenticacao;
    IApresentacaoUsuario *cntrAprUsuario;
    IApresentacaoExcursao *cntrAprExcursao;

    cntrAprControle = new CntrAprControle();
    cntrAprAutenticacao = new CntrAprAutenticacao();
    cntrAprUsuario = new CntrAprUsuario();
    cntrAprExcursao = new CntrAprExcursao();

    IServicoAutenticacao *cntrServAutenticacao;
    IServicoUsuario *cntrServUsuario;
    IServicoExcursao *cntrServExcursao;

    cntrServAutenticacao = new CntrServAutenticacao();
    cntrServUsuario = new CntrServUsuario();
    cntrServExcursao = new CntrServExcursao();

    cntrAprControle -> setCntrAprAutenticacao(cntrAprAutenticacao);
    cntrAprControle -> setCntrAprUsuario(cntrAprUsuario);
    cntrAprControle -> setCntrAprExcursao(cntrAprExcursao);

    cntrAprAutenticacao -> setCntrServAutenticacao(cntrServAutenticacao);
    cntrAprUsuario -> setCntrServUsuario(cntrServUsuario);
    cntrAprExcursao -> setCntrServExcursao(cntrServExcursao);

    cntrServAutenticacao -> setCntrServUsuario(cntrServUsuario);
    cntrServUsuario -> setCntrServExcursao(cntrServExcursao);

    cntrAprControle->executar();
}