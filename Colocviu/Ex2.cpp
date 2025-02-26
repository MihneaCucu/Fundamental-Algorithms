#include <map>
#include <vector>
#include <set>
#include <string>
#include <exception>
#include <utility>
#include <sstream>
#include <algorithm>
#include <iostream>
#define INF 1000000

using namespace std;


// Clase de excepaii
class ExceptieVarf : public std::exception {
    std::string mesaj;
public:
    explicit ExceptieVarf(std::string mesaj) {
        this->mesaj = std::move(mesaj);
    }

    const char* what() const noexcept override {
        return this->mesaj.c_str();
    }
};

class ExceptieMuchie : public std::exception {
    std::string mesaj;
public:
    explicit ExceptieMuchie(std::string mesaj) {
        this->mesaj = std::move(mesaj);
    }

    const char* what() const noexcept override {
        return this->mesaj.c_str();
    }
};

class ExceptieFisier : public std::exception {
    std::string mesaj;
public:
    explicit ExceptieFisier(std::string mesaj) {
        this->mesaj = std::move(mesaj);
    }

    const char* what() const noexcept override {
        return this->mesaj.c_str();
    }
};

class ExceptieCicluNegativ : public std::exception {
    std::string mesaj;
public:
    explicit ExceptieCicluNegativ(std::string mesaj) {
        this->mesaj = std::move(mesaj);
    }

    const char* what() const noexcept override {
        return this->mesaj.c_str();
    }
};

class ExceptieDrumInexistent : public std::exception {
    std::string mesaj;
public:
    explicit ExceptieDrumInexistent(std::string mesaj) {
        this->mesaj = std::move(mesaj);
    }

    const char* what() const noexcept override {
        return this->mesaj.c_str();
    }
};

// Clasa Graf
class Graf {
private:
    std::set<int> varfuri{};
    std::map<int, std::set<int>> iesiri{};
    std::map<int, std::set<int>> intrari{}; // not needed when neorientat
    std::map<std::pair<int, int>, int> costuri{};
    bool neorientat = false;

public:
    // Constructori si destructor
    Graf() = default;
    explicit Graf(int n, bool neorientat = false);
    Graf(const Graf&) = default;
    Graf& operator=(const Graf&) = default;
    ~Graf() = default;

    // Funcaionalitaai de baza ale grafului
    void goleste();
    void adauga_varf(int varf_de_adaugat);
    void sterge_varf(int varf_de_sters);
    void adauga_muchie(int varf_de_la, int varf_la, int cost);
    void sterge_muchie(int varf_de_la, int varf_la);
    unsigned long numar_varfuri() const;
    unsigned long numar_muchii() const;
    std::vector<int> obtine_varfuri() const;
    std::vector<std::pair<int, int>> obtine_muchii() const;
    std::vector<int> obtine_varfuri_intrare(int varf) const;
    std::vector<int> obtine_varfuri_iesire(int varf) const;
    bool este_muchie(int varf_de_la, int varf_la) const;
    bool este_varf(int varf_de_verificat) const;
    unsigned long grad_intrare(int varf) const;
    unsigned long grad_iesire(int varf) const;
    void seteaza_cost(int varf_de_la, int varf_la, int cost_nou);
    long long obtine_cost(int varf_de_la, int varf_la) const;

    // Manipulare graf
    void genereaza_graf_aleator(int nr_varfuri, int nr_muchii, bool cu_costuri);
    void citeste_graf_din_fisier();
    void salveaza_graf_in_fisier(const std::string& fisier) const;
    std::pair<long long, std::vector<int>> cel_mai_ieftin_drum(int varf_start, int varf_sfarsit, bool cu_costuri) const;
    std::vector<std::pair<std::pair<int, int>, int>> sorteaza_muchii_dupa_cost() const;
    Graf algoritmul_kruskal() const;
    std::vector<int> bfs(int start) const;
    std::vector<int> dfs(int start) const;
    void dfs_util(int varf, std::set<int>& vizitat, std::vector<int>& rezultat) const;
    bool dfs_bool(int varf, std::vector<int>& parinte, std::vector<bool>& vizitat, std::vector<bool>& in_stiva, std::vector<int>& ciclu) const;
    std::vector<std::pair<int, int>> gaseste_ciclu_impar() const;
    std::vector<std::vector<int>> gaseste_toate_ciclurile() const;
    void dfs_cicluri(int varf, std::vector<bool>& vizitat, std::vector<int>& parinte, std::vector<int>& stiva, std::vector<std::vector<int>>& cicluri) const;
    int cost_arbore_partial_minim() const;
    std::pair<int, std::vector<int>> lant_minim_capacitate(int s) const;
    std::map<int, int> dijkstra(int start) const;
    Graf algoritmul_prim(int start) const;
    int ford_fulkerson(int source, int sink);
    bool bfs(int source, int sink, std::vector<int>& parent);
    bool bellman_ford(int start, std::map<int, long long>& distanta, std::map<int, int>& parinte) const;
    bool este_conex() const;
    bool este_eulerian() const;
    bool are_drum_eulerian() const;
    std::vector<int> gaseste_circuit_eulerian() const;
    bool este_hamltonian_util(int varf, std::vector<int>& drum, std::vector<bool>& vizitat, int& index) const;
    bool este_hamiltonian() const;
    bool este_bipartit() const;
    std::vector<int> kahn_topological_sort() const;
    void dfs_transpus(int varf, std::set<int>& vizitat, std::vector<int>& componenta) const;
    Graf obtine_transpus() const;
    std::vector<std::vector<int>> kosaraju() const;
    std::vector<std::vector<int>> roy_floyd() const;
    bool bfs_edmonds_karp(int source, int sink, std::vector<int>& parent) const;
    int edmonds_karp(int source, int sink) const;
    bool havel_hakimi(std::vector<int> degree_sequence) const;
    bool face_parte_din_traseu(int sursa, int dest, int k, bool cu_costuri) const;
};

// Implementarile metodelor din clasa Graf
Graf::Graf(int n, bool neorientat) {
    for (int i = 0; i < n; i++) {
        this->adauga_varf(i);
    }
    this->neorientat = neorientat;
}

void Graf::goleste() {
    varfuri.clear();
    iesiri.clear();
    intrari.clear();
    costuri.clear();
}

void Graf::adauga_varf(int varf_de_adaugat) {
    if (this->este_varf(varf_de_adaugat)) {
        throw ExceptieVarf("Varful este deja in graf!");
    }
    this->varfuri.insert(varf_de_adaugat);
    this->iesiri[varf_de_adaugat] = std::set<int>();
    this->intrari[varf_de_adaugat] = std::set<int>();
}

void Graf::sterge_varf(int varf_de_sters) {
    if (!this->este_varf(varf_de_sters)) {
        throw ExceptieVarf("Varful nu exista in graf!");
    }
    this->varfuri.erase(varf_de_sters);
    for (auto varf : this->iesiri[varf_de_sters]) {
        this->intrari[varf].erase(varf_de_sters);
        this->costuri.erase(std::make_pair(varf_de_sters, varf));
    }
    for (auto varf : this->intrari[varf_de_sters]) {
        this->iesiri[varf].erase(varf_de_sters);
        this->costuri.erase(std::make_pair(varf, varf_de_sters));
    }
    this->iesiri.erase(varf_de_sters);
    this->intrari.erase(varf_de_sters);
}

void Graf::adauga_muchie(int varf_de_la, int varf_la, int cost) {
    if (!this->este_varf(varf_de_la)) {
        throw ExceptieVarf("Varful de pornire nu exista in graf!");
    }
    if (!this->este_varf(varf_la)) {
        throw ExceptieVarf("Varful de destinaaie nu exista in graf!");
    }
    if (this->este_muchie(varf_de_la, varf_la)) {
        throw ExceptieMuchie("Muchia este deja in graf!");
    }

    this->iesiri[varf_de_la].insert(varf_la);
    this->intrari[varf_la].insert(varf_de_la);
    this->costuri[std::make_pair(varf_de_la, varf_la)] = cost;
    if (this->neorientat) {
        this->iesiri[varf_la].insert(varf_de_la);
        this->intrari[varf_de_la].insert(varf_la);
        this->costuri[std::make_pair(varf_la, varf_de_la)] = cost;
    }
}



void Graf::citeste_graf_din_fisier() {

    goleste();
    int orientat;
    // cout << "Introdu 0 pentru graf neorientat sau 1 pentru graf orientat: ";
    orientat = 0;
    this->neorientat = (orientat == 0);

    int nr_noduri, nr_muchii;
    // cout << "Introdu numarul de noduri si numarul de muchii: ";
    cin >> nr_noduri >> nr_muchii;
    while (nr_muchii != 0) {
        int u, v, c;
        //cout << "Introdu muchia (u, v, c): ";
        cin >> u >> v >> c;
        if (!este_varf(u)) adauga_varf(u);
        if (!este_varf(v)) adauga_varf(v);
        adauga_muchie(u, v, c);

        nr_muchii--;
    }
}



bool Graf::face_parte_din_traseu(int varf_start, int varf_sfarsit, int varf_k, bool cu_costuri=1) const {


    if (!este_varf(varf_start) || !este_varf(varf_sfarsit) || !este_varf(varf_k)) {
        return 0;
    }


    std::map<int, long long> distanta;
    std::map<int, int> parinte;
    for (int varf : varfuri) {
        distanta[varf] = INF;
        parinte[varf] = -1;
    }
    distanta[varf_start] = 0;

    std::set<std::pair<long long, int>> coada;
    coada.insert({0, varf_start});

    while (!coada.empty()) {
        int varf_curent = coada.begin()->second;
        coada.erase(coada.begin());

        for (int vecin : obtine_varfuri_iesire(varf_curent)) {
            long long cost = cu_costuri ? obtine_cost(varf_curent, vecin) : 1;
            if (distanta[varf_curent] + cost < distanta[vecin]) {
                coada.erase({distanta[vecin], vecin});
                distanta[vecin] = distanta[varf_curent] + cost;
                parinte[vecin] = varf_curent;
                coada.insert({distanta[vecin], vecin});
            }
        }
    }

    if (distanta[varf_sfarsit] == INF) {
        return 0;
    }

    std::vector<int> drum;
    for (int varf = varf_sfarsit; varf != -1; varf = parinte[varf]) {
        drum.push_back(varf);
        if (varf == varf_k) {
            return 1;
        }
    }
    std::reverse(drum.begin(), drum.end());

    return 0;
}
bool Graf::este_muchie(int varf_de_la, int varf_la) const {
    return costuri.find(std::make_pair(varf_de_la, varf_la)) != costuri.end();
}

bool Graf::este_varf(int varf) const {
    return varfuri.find(varf) != varfuri.end();
}
long long Graf::obtine_cost(int varf_de_la, int varf_la) const {
    if (!este_muchie(varf_de_la, varf_la)) {
        throw ExceptieMuchie("Muchia nu exista in graf!");
    }
    return costuri.at(std::make_pair(varf_de_la, varf_la));
}

std::vector<int> Graf::obtine_varfuri() const {
    return {varfuri.begin(), varfuri.end()};
}

std::vector<std::pair<int, int>> Graf::obtine_muchii() const {
    std::vector<std::pair<int, int>> muchii;
    for (const auto& muchie : costuri) {
        muchii.push_back(muchie.first);
    }
    return muchii;
}

std::vector<int> Graf::obtine_varfuri_intrare(int varf) const {
    if (!este_varf(varf)) {
        throw ExceptieVarf("Varful nu exista in graf!");
    }
    return {intrari.at(varf).begin(), intrari.at(varf).end()};
}

std::vector<int> Graf::obtine_varfuri_iesire(int varf) const {
    if (!este_varf(varf)) {
        throw ExceptieVarf("Varful nu exista in graf!");
    }
    return {iesiri.at(varf).begin(), iesiri.at(varf).end()};
}


int main()
{


    string nume_fisier;
    Graf graf;
    graf.goleste();
    graf.citeste_graf_din_fisier();
    // cout << "Graful a fost citit cu succes din fisier" << endl;

    int nr_linii,a,b,c,rez[101];
    //cout << "Introdu numarul de linii: ";
    cin >> nr_linii;
    for(int i=0;i<nr_linii;i++){
        // cout << "Introdu linia: ";
        cin>>a>>b>>c;
        if(graf.face_parte_din_traseu(a,b,c)){
            rez[i]=1;

        }
        else{
            rez[i]=0;
        }

    }
    for(int i=0;i<nr_linii;i++){
        cout<<rez[i];
    }
    cout << endl;

    return 0;
}