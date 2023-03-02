#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"


/** @brief Armazenamento de grupo de domínios que constituem Usuário. */
class Usuario{//202042829
    private:
        Nome nomeUsuario;
        Email emailUsuario;
        Senha senhaUsuario;
    public:
        /**
         * @brief Armazena no atributo um objeto Nome.
         * 
         * @param nomeUsuario Objeto Nome a ser armazenado.
         */
        void setNome(const Nome& nomeUsuario){
            this -> nomeUsuario = nomeUsuario;
        }
        /**
         * @brief Retorna objeto Nome armazenado.
         * 
         * @return Nome, objeto que contém string.
         */
        Nome getNome() const{
            return nomeUsuario;
        }
        /**
         * @brief Armazena no atributo um objeto Email.
         * 
         * @param emailUsuario Objeto Email a ser armazenado.
         */
        void setEmail(const Email& emailUsuario){
            this -> emailUsuario = emailUsuario;
        }
        /**
         * @brief Retorna objeto Email armazenado.
         * 
         * @return Email, objeto que contém string.
         */
        Email getEmail() const{
            return emailUsuario;
        }
        /**
         * @brief Armazena no atributo um objeto Senha.
         * 
         * @param senhaUsuario Objeto Senha a ser armazenado.
         */
        void setSenha(const Senha& senhaUsuario){
            this -> senhaUsuario = senhaUsuario;
        }
        /**
         * @brief Retorna objeto Senha armazenado.
         * 
         * @return Senha, objeto que contém string.
         */
        Senha getSenha() const{
            return senhaUsuario;
        }
};

/** @brief Armazenamento do grupo de domínios que constituem Sesaão. */
class Sessao{//202042829
    private:
        Codigo codigoSessao;
        Data dataSessao;
        Horario horarioSessao;
        Idioma idiomaSessao;
    public:
        /**
         * @brief Armazena no atributo um objeto Codigo.
         * 
         * @param codigoSessao Objeto Codigo a ser armazenado.
         */
        void setCodigo(const Codigo& codigoSessao){
            this -> codigoSessao = codigoSessao;
        }
        /**
         * @brief Retorna objeto Codigo armazenado.
         * 
         * @return Codigo, objeto que contém número inteiro.
         */
        Codigo getCodigo() const{
            return codigoSessao;
        }
        /**
         * @brief Armazena no atributo um objeto Data.
         * 
         * @param dataSessao Objeto Data a ser armazenado.
         */
        void setData(const Data& dataSessao){
            this -> dataSessao = dataSessao;
        }
        /**
         * @brief Retorna objeto Data armazenado.
         * 
         * @return Data, objeto que contém string.
         */
        Data getData() const{
            return dataSessao;
        }
        /**
         * @brief Armazena no atributo um objeto Horario.
         * 
         * @param horarioSessao Objeto Horario a ser armazenado.
         */
        void setHorario(const Horario& horarioSessao){
            this -> horarioSessao = horarioSessao;
        }
        /**
         * @brief Retorna objeto Horario armazenado.
         * 
         * @return Horario, objeto que contém string.
         */
        Horario getHorario() const{
            return horarioSessao;
        }
        /**
         * @brief Armazena no atributo um objeto Idioma.
         * 
         * @param idiomaSessao Objeto Idioma a ser armazenado.
         */
        void setIdioma(const Idioma& idiomaSessao){
            this -> idiomaSessao = idiomaSessao;
        }
        /**
         * @brief Retorna objeto Idioma armazenado.
         * 
         * @return Idioma, objeto que contém string.
         */
        Idioma getIdioma() const{
            return idiomaSessao;
        }
};

/** @brief Armazenamento de grupo de domínios que constituem Avaliacao. */
class Avaliacao{//202042829
    private:
        Codigo codigoAvaliacao;
        Nota notaAvaliacao;
        Descricao descricaoAvaliacao;
    public:
        /**
         * @brief Armazena no atributo um objeto Codigo.
         * 
         * @param codigoAvaliacao Objeto Codigo a ser armazenado.
         */
        void setCodigo(const Codigo& codigoAvaliacao){
            this -> codigoAvaliacao = codigoAvaliacao;
        }
        /**
         * @brief Retorna objeto Codigo armazenado.
         * 
         * @return Codigo, objeto que contém número inteiro.
         */
        Codigo getCodigo() const{
            return codigoAvaliacao;
        }
        /**
         * @brief Armazena no atributo um objeto Nota.
         * 
         * @param senhaUsuario Objeto Nota a ser armazenado.
         */
        void setNota(const Nota& notaAvaliacao){
            this -> notaAvaliacao = notaAvaliacao;
        }
        /**
         * @brief Retorna objeto Nota armazenado.
         * 
         * @return Nota, objeto que contém número inteiro.
         */
        Nota getNota() const{
            return notaAvaliacao;
        }
        /**
         * @brief Armazena no atributo um objeto Descricao.
         * 
         * @param senhaUsuario Objeto Descricao a ser armazenado.
         */
        void setDescricao(const Descricao& descricaoAvaliacao){
            this -> descricaoAvaliacao = descricaoAvaliacao;
        }
        /**
         * @brief Retorna objeto Descricao armazenado.
         * 
         * @return Descricao, objeto que contém string.
         */
        Descricao getDescricao() const{
            return descricaoAvaliacao;
        }
};


/** @brief Armazenamento de grupo de domínios que constituem Excursão. */
class Excursao { //202014280
    private:
            Codigo codigo;
            Titulo titulo; 
            Nota nota; 
            Cidade cidade; 
            Duracao duracao; 
            Descricao descricao; 
            Endereco endereco; 
    public:
            /**
            * @brief Armazena no atributo um objeto Codigo.
            * 
            * @param codigo Objeto Codigo a ser armazenado.
            */
            void setCodigo(const Codigo &codigo){
                this->codigo = codigo;
            }
            /**
            * @brief Retorna objeto Codigo armazenado.
            * 
            * @return Codigo, objeto que contém string.
            */
            Codigo getCodigo() const{
                return codigo;
            }
             /**
            * @brief Armazena no atributo um objeto Titulo.
            * 
            * @param titulo Objeto Titulo a ser armazenado.
            */
            void setTitulo(const Titulo &titulo){
                this->titulo = titulo;
            }
            /**
            * @brief Retorna objeto Titulo armazenado.
            * 
            * @return Titulo, objeto que contém string.
            */
            Titulo getTitulo() const{
                return titulo;
            }
            /**
            * @brief Armazena no atributo um objeto Nota.
            * 
            * @param Nota Objeto Nota a ser armazenado.
            */
            void setNota(const Nota &nota){
                this->nota = nota;
            }
            /**
            * @brief Retorna objeto Nota armazenado.
            * 
            * @return Nota, objeto que contém número inteiro.
            */
            Nota getNota() const{
                return nota;
            }
            /**
            * @brief Armazena no atributo um objeto Cidade.
            * 
            * @param senhaUsuario Objeto Cidade a ser armazenado.
            */
            void setCidade(const Cidade &cidade){
                this->cidade = cidade;
            }
            /**
            * @brief Retorna objeto Cidade armazenado.
            * 
            * @return Cidade, objeto que contém string.
            */
            Cidade getCidade() const{
                return cidade;
            }
            /**
            * @brief Armazena no atributo um objeto Duração.
            * 
            * @param senhaUsuario Objeto Duração a ser armazenado.
            */
            void setDuracao(const Duracao &duracao){
                this->duracao = duracao;
            }
            /**
            * @brief Retorna objeto Duração armazenado.
            * 
            * @return Duração, objeto que contém número inteiro.
            */
            Duracao getDuracao() const{
                return duracao;
            }
            /**
            * @brief Armazena no atributo um objeto Descrição.
            * 
            * @param senhaUsuario Objeto Descrição a ser armazenado.
            */
            void setDescricao(const Descricao &descricao){
                this->descricao = descricao;
            }
            /**
            * @brief Retorna objeto Descrição armazenado.
            * 
            * @return Descrição, objeto que contém string.
            */
            Descricao getDescricao() const{
                return descricao;
            }
            /**
            * @brief Armazena no atributo um objeto Endereço.
            * 
            * @param senhaUsuario Objeto Endereço a ser armazenado.
            */
            void setEndereco(const Endereco &endereco){
                this->endereco = endereco;
            }
            /**
            * @brief Retorna objeto Endereço armazenado.
            * 
            * @return Endereço, objeto que contém string.
            */
            Endereco getEndereco() const{
                return endereco;
            }
};


#endif // ENTIDADES_H_INCLUDED