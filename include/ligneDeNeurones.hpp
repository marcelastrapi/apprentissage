#pragma once

#include <neurone.hpp>

class LigneDeNeurones
{
    private:
        using Neurones = std::vector<Neurone*>;

    public:
        using TblValeurs = std::vector<nbType>;
        using iterator = Neurones::iterator;
        using const_iterator = Neurones::const_iterator;

        // Ctor && Dtor
        LigneDeNeurones(const size_t nbNeurones);
        LigneDeNeurones(LigneDeNeurones& ligneÀCopier);
        ~LigneDeNeurones();

        // Pour pouvoir faire comme dans un vector (itérer)
        iterator begin() { return m_neurones.begin(); }
        iterator end() { return m_neurones.end(); }
        const_iterator begin() const { return m_neurones.begin(); }
        const_iterator end() const { return m_neurones.end(); }
        const_iterator cbegin() const { return m_neurones.cbegin(); }
        const_iterator cend() const { return m_neurones.cend(); }

        // setters
        void nbNeurones(const size_t nbNeurones);
        inline void poidsAléa(const nbType min , const nbType max )
        { for (Neurone* n: m_neurones) n->poidsAléa(min,max); }
        inline void poidsAléa(const nbType fourchetteAutourDuPoids)
        { for (Neurone* n: m_neurones) n->poidsAléa(fourchetteAutourDuPoids); }
        inline void seuil(const nbType _seuil)
        { for (Neurone* n: m_neurones) n->seuil(_seuil); }

        // getters
        inline size_t nbNeurones() const { return m_neurones.size(); }
        inline Neurone* at(const size_t i) { return m_neurones.at(i); }
        TblValeurs tableauxDesRésultats() const;


        // sub
        inline void ajouteUnNeurone() { m_neurones.push_back(new Neurone); }
        void connecteMoiÀUneAutreLigne(LigneDeNeurones& autreLigne);
        void calculeLesValeursDeToutMesNeurones();
        inline void effaceToutesLesConnections() { for (Neurone* n: m_neurones) n->effaceToutesLesConnections(); }


        void print() const;

    private:
        Neurones m_neurones;
};
