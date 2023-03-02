#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <random>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <initializer_list>

using namespace std;

/** @brief Para validação e armazenamento de horários. */
class Horario {//202042829
    private:
        static const int posMeio = 2;
        static const int caracteresNecessarios = 5;
        static const int maxHoras = 23;
        static const int maxMinutos = 59;
        static const int minTempo = 0;
        string horario;
        /**
        * @brief Confere se horário inserido é válido. Lança exceção caso contrário.
        *
        * @param horario String a ser validada.
        */
        void validar(string horario);
    public:
        /**
        * @brief Caso horário inserido seja válido, o atribui.
        *
        * @param horario String a ser atribuída.
        */
        void setHorario(string horario);
        /**
         * @brief Retorna horario armazenado.
         *
         * @return String armazenada em atributo horario.
         */
        string getHorario(){
            return horario;
        }
};

/** @brief Para validação e armazenamento de idiomas. */
class Idioma {//202042829
    private:
        /**
        * @brief Conjunto com todos os idomas válidos, para comparar com o inserido.
        *
        */
        static const unordered_set<string> idiomasValidos;
        string idioma;
        /**
        * @brief Confere se idioma inserido é válido. Lança exceção caso contrário.
        *
        * @param idioma String a ser validada.
        */
        void validar(string idioma);
    public:
        /**
        * @brief Caso idioma inserido seja válido, o atribui.
        *
        * @param idioma String a ser atribuída.
        */
        void setIdioma(string idoma);
        /**
        * @brief Retorna idioma armazenado.
        *
        * @return String armazenada em atributo idioma.
        */
        string getIdioma(){
            return idioma;
        }

};

/** @brief Para validação e armazenamento de nomes. */
class Nome {//202042829
    private:
        static const int maxCaractere = 20;
        static const int minCaractere = 5;
        string nome;
        /**
        * @brief Confere se nome inserido é válido. Lança exceção caso contrário.
        *
        * @param nome String a ser validada.
        */
        void validar(string nome);
    public:
        /**
        * @brief Caso nome inserido seja válido, o atribui.
        *
        * @param nome String a ser atribuída.
        */
        void setNome(string nome);
        /**
         * @brief Retorna nome armazenado.
         *
         * @return String armazenada em atributo nome.
         */
        string getNome(){
            return nome;
        }

};

/** @brief Para validação e armazenamento de notas. */
class Nota {//202042829
    private:
        static constexpr float maxNota = 5.0f;
        static constexpr float minNota = 0.0f;
        float nota;
        /**
        * @brief Confere se nota inserida é válida. Lança exceção caso contrário.
        *
        * @param nota String a ser validada.
        */
        void validar(float nota);
    public:
        /**
        * @brief Caso nota inserida seja válida, a atribui.
        *
        * @param nota String a ser atribuída.
        */
        void setNota(float nota);
        /**
         * @brief Retorna nota armazenada.
         *
         * @return Inteiro armazenado em atributo nota.
         */
        int getNota(){
            return nota;
        }
};

/** @brief Para validação e armazenamento de senhas.*/
class Senha {//202042829
    private:
        static const int tamanhoSenha = 6;
        string senha;
        /**
        * @brief Confere se senha inserida é válida. Lança exceção caso contrário.
        *
        * @param senha String a ser validada.
        */
        void validar(string senha);
    public:
        /**
        * @brief Caso senha inserida seja válida, a atribui.
        *
        * @param senha String a ser atribuída.
        */
        void setSenha(string senha);
        /**
         * @brief Retorna senha armazenada.
         *
         * @return String armazenada em atributo senha.
         */
        string getSenha(){
            return senha;
        }

};

/** @brief Para validação e armazenamento de títulos.*/
class Titulo {//202042829
    private:
        static const int maxCaractere = 20;
        static const int minCaractere = 5;
        string titulo;
        /**
        * @brief Confere se título inserido é válido. Lança exceção caso contrário.
        *
        * @param titulo String a ser validada.
        */
        void validar(string titulo);
    public:
        /**
         * @brief Caso título inserido seja válido, o atribui.
         *
         * @param titulo String a ser atribuída.
         */
        void setTitulo(string titulo);
        /**
         * @brief Retorna título armazenado.
         *
         * @return String armazenada em atributo titulo.
         */
        string getTitulo(){
            return titulo;
        }

};

/** @brief Para validação e armazenamento de emails. */
class Email {//202042829
    private:
        static const int caracteresParteLocal = 64;
        static const int caracteresDominio = 253;
        static const unordered_set<char> simbolosParteLocal;
        static unordered_set<string> emailsEmUso;
        string email;
        /**
         * @brief Confere se email inserido é válido. Lança exceção caso contrário.
         *
         * @param email String a ser validada.
         */
        void validar(string email);
    public:
        /** @brief Construtor. Não inicializa atributo, usado apenas como par do destrutor. */
        Email(){};
        /** @brief Destrutor. Remove o email do objeto do conjunto dos emails em uso, para evitar conflitos. */
        ~Email(){
            emailsEmUso.erase(email);
        }
        /**
         * @brief Caso email inserido seja válido, o atribui.
         *
         * @param email String a ser atribuída.
         */
        void setEmail(string email);
        /**
         * @brief Retorna email armazenado.
         *
         * @return String armazenada em atributo email.
         */
        string getEmail() const{
            return email;
        }
};

inline bool operator == (const Email &leftEmail, const Email &rightEmail){
    return leftEmail.getEmail() == rightEmail.getEmail();
}

template<> struct std::hash<Email>{
    std::size_t operator() (Email const &email) const noexcept{
        return std::hash<std::string>{}(email.getEmail());
    }
};

/** @brief Para validação e armazenamento de datas. */
class Data { //202042829
    private:
        static const vector<string> meses31;
        static const vector<string> meses30;
        string data;
        /**
         * @brief Confere se data inserida é válida. Lança exceção caso contrário.
         *
         * @param data String a ser validada.
         */
        void validar(string data);
    public:
        /**
         * @brief Caso data inserida seja válida, a atribui.
         *
         * @param data String a ser atribuída.
         */
        void setData(string data);
        /**
         * @brief Retorna data armazenada.
         *
         * @return String armazenada em atributo data.
         */
        string getData() const{
            return data;
        }
};

/** @brief Para validação e armazenamento de cidades. */
class Cidade { //202014280
    private:
        string cidade;
        /**
         * @brief Confere se a cidade inserida é válida. Lança exceção caso contrário.
         *
         * @param cidade String a ser validada.
         */
        void validar(string cidade);
    public:
        /**
         * @brief Caso cidade inserida seja válida, a atribui.
         *
         * @param data String a ser atribuída.
         */
        void setCidade(string cidade);
        /**
         * @brief Retorna cidade armazenada.
         *
         * @return String armazenada em atributo cidade.
         */
        string getCidade() const{
            return cidade;
        }
};

/** @brief Para validação e armazenamento de códigos. */
class Codigo { //202014280
    private:
        static unordered_set<string> codigosEmUso;
        string codigo;
        /**
         * @brief Confere se o código inserido é válido. Lança exceção caso contrário.
         *
         * @param cidade String a ser validada.
         */
        void validar(string codigo);
    public:
        /** @brief Construtor. Não inicializa atributo, usado apenas como par do destrutor. */
        Codigo(){};
        /** @brief Destrutor. Remove o código do objeto do conjunto dos códigos em uso, para evitar conflitos. */
        ~Codigo(){
            codigosEmUso.erase(codigo);
        }
        /**
         * @brief Caso código inserido seja válido, o atribui.
         *
         * @param data String a ser atribuída.
         */
        void setCodigo(string codigo);
        /**
         * @brief Retorna código armazenada.
         *
         * @return String armazenada em atributo código.
         */
        string getCodigo() const{
            return codigo;
        }
};

inline bool operator == (const Codigo &leftCodigo, const Codigo &rightCodigo){
    return leftCodigo.getCodigo() == rightCodigo.getCodigo();
}

template<> struct std::hash<Codigo>{
    std::size_t operator() (Codigo const &codigo) const noexcept{
        return std::hash<std::string>{}(codigo.getCodigo());
    }
};

/** @brief Para validação e armazenamento de descrições. */
class Descricao { //202014280
    private:
        string descricao;
        /**
         * @brief Confere se a descrição inserida é válida. Lança exceção caso contrário.
         *
         * @param cidade String a ser validada.
         */
        void validar(string descricao);
    public:
        /**
         * @brief Caso descrição inserida seja válida, a atribui.
         *
         * @param data String a ser atribuída.
         */
        void setDescricao(string descricao);
        /**
         * @brief Retorna descrição armazenada.
         *
         * @return String armazenada em atributo descrição.
         */
        string getDescricao() const{
            return descricao;
        }
};

/** @brief Para validação e armazenamento de durações. */
class Duracao { //202014280
    private:
        int duracao;
        /**
         * @brief Confere se a duração inserida é válida. Lança exceção caso contrário.
         *
         * @param cidade String a ser validada.
         */
        void validar(int duracao);
    public:
        /**
         * @brief Caso duração inserida seja válida, a atribui.
         *
         * @param data String a ser atribuída.
         */
        void setDuracao(int duracao);
        /**
         * @brief Retorna duração armazenada.
         *
         * @return String armazenada em atributo duração.
         */
        int getDuracao() const{
            return duracao;
        }
};

/** @brief Para validação e armazenamento de endereços. */
class Endereco { //202014280
    private:
        string endereco;
        /**
         * @brief Confere se o endereço inserido é válido. Lança exceção caso contrário.
         *
         * @param cidade String a ser validada.
         */
        void validar(string);
    public:
        /**
         * @brief Caso endereço inserido seja válido, o atribui.
         *
         * @param data String a ser atribuída.
         */
        void setEndereco(string);
        /**
         * @brief Retorna endereço armazenado.
         *
         * @return String armazenada em atributo endereço.
         */
        string getEndereco() const{
            return endereco;
        }
};

#endif // DOMINIOS_H_INCLUDED