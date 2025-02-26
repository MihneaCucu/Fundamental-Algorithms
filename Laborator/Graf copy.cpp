#include <map>
#include <vector>
#include <set>
#include <string>
#include <exception>
#include <utility>
#include <random>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#define INF 1000000


// Clase de excepții
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
    // Constructori și destructor
    Graf() = default;
    explicit Graf(int n, bool neorientat = false);
    Graf(const Graf&) = default;
    Graf& operator=(const Graf&) = default;
    ~Graf() = default;

    // Funcționalități de bază ale grafului
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
    void citeste_graf_din_fisier(const std::string& fisier);
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
    void dfs_kosaraju(int varf, std::set<int>& vizitat, std::stack<int>& stiva) const;
    void dfs_transpus(int varf, std::set<int>& vizitat, std::vector<int>& componenta) const;
    Graf obtine_transpus() const;
    std::vector<std::vector<int>> kosaraju() const;
    void tarjan_dfs(int varf, int& index, std::vector<int>& indexuri, std::vector<int>& lowlink, std::stack<int>& stiva, std::vector<bool>& in_stiva, std::vector<std::vector<int>>& componente) const;
    std::vector<std::vector<int>> tarjan() const;
    std::vector<std::vector<int>> roy_floyd() const;
    bool bfs_edmonds_karp(int source, int sink, std::vector<int>& parent) const;
    int edmonds_karp(int source, int sink) const;
    std::vector<int> a_star(int start, int goal, const std::function<int(int, int)>& heuristic) const;
    bool havel_hakimi(std::vector<int> degree_sequence) const;
};

// Implementările metodelor din clasa Graf
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
        throw ExceptieVarf("Varful este deja în graf!");
    }
    this->varfuri.insert(varf_de_adaugat);
    this->iesiri[varf_de_adaugat] = std::set<int>();
    this->intrari[varf_de_adaugat] = std::set<int>();
}

void Graf::sterge_varf(int varf_de_sters) {
    if (!this->este_varf(varf_de_sters)) {
        throw ExceptieVarf("Varful nu există în graf!");
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
        throw ExceptieVarf("Varful de pornire nu există în graf!");
    }
    if (!this->este_varf(varf_la)) {
        throw ExceptieVarf("Varful de destinație nu există în graf!");
    }
    if (this->este_muchie(varf_de_la, varf_la)) {
        throw ExceptieMuchie("Muchia este deja în graf!");
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

void Graf::sterge_muchie(int varf_de_la, int varf_la) {
    if (!this->este_muchie(varf_de_la, varf_la)) {
        throw ExceptieMuchie("Muchia nu există în graf!");
    }
    this->iesiri[varf_de_la].erase(varf_la);
    this->intrari[varf_la].erase(varf_de_la);
    this->costuri.erase(std::make_pair(varf_de_la, varf_la));
    if (this->neorientat) {
        this->iesiri[varf_la].erase(varf_de_la);
        this->intrari[varf_de_la].erase(varf_la);
        this->costuri.erase(std::make_pair(varf_la, varf_de_la));
    }
}

unsigned long Graf::numar_varfuri() const {
    return varfuri.size();
}

unsigned long Graf::numar_muchii() const {
    return costuri.size();
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
        throw ExceptieVarf("Varful nu există în graf!");
    }
    return {intrari.at(varf).begin(), intrari.at(varf).end()};
}

std::vector<int> Graf::obtine_varfuri_iesire(int varf) const {
    if (!este_varf(varf)) {
        throw ExceptieVarf("Varful nu există în graf!");
    }
    return {iesiri.at(varf).begin(), iesiri.at(varf).end()};
}

bool Graf::este_muchie(int varf_de_la, int varf_la) const {
    return costuri.find(std::make_pair(varf_de_la, varf_la)) != costuri.end();
}

bool Graf::este_varf(int varf) const {
    return varfuri.find(varf) != varfuri.end();
}

unsigned long Graf::grad_intrare(int varf) const {
    if (!este_varf(varf)) {
        throw ExceptieVarf("Varful nu există în graf!");
    }
    return intrari.at(varf).size();
}

unsigned long Graf::grad_iesire(int varf) const {
    if (!este_varf(varf)) {
        throw ExceptieVarf("Varful nu există în graf!");
    }
    return iesiri.at(varf).size();
}

void Graf::seteaza_cost(int varf_de_la, int varf_la, int cost_nou) {
    if (!este_muchie(varf_de_la, varf_la)) {
        throw ExceptieMuchie("Muchia nu există în graf!");
    }
    costuri[std::make_pair(varf_de_la, varf_la)] = cost_nou;
}

long long Graf::obtine_cost(int varf_de_la, int varf_la) const {
    if (!este_muchie(varf_de_la, varf_la)) {
        throw ExceptieMuchie("Muchia nu există în graf!");
    }
    return costuri.at(std::make_pair(varf_de_la, varf_la));
}

void Graf::genereaza_graf_aleator(int nr_varfuri, int nr_muchii, bool cu_costuri= true) {
    if (nr_muchii > nr_varfuri * nr_varfuri) {
        throw ExceptieMuchie("Prea multe muchii!");
    }
    goleste();
    for (int i = 0; i < nr_varfuri; i++) {
        adauga_varf(i);
    }
    std::vector<std::pair<int, int>> toate_muchiile;
    for (int i = 0; i < nr_varfuri; i++) {
        for (int j = 0; j < nr_varfuri; j++) {
            toate_muchiile.emplace_back(i, j);
        }
    }
    std::shuffle(toate_muchiile.begin(), toate_muchiile.end(), std::mt19937(std::random_device()()));
    for (int i = 0; i < nr_muchii; i++) {
        int cost = cu_costuri ? rand() % 1000 : 1;
        adauga_muchie(toate_muchiile[i].first, toate_muchiile[i].second, cost);
    }
}

void Graf::citeste_graf_din_fisier(const std::string& fisier) {
    std::ifstream fisier_in(fisier);
    if (!fisier_in.is_open()) {
        throw ExceptieFisier("Nu se poate deschide fișierul!");
    }
    goleste();
    int orientat;
    fisier_in >> orientat;
    this->neorientat = (orientat == 0);

    std::string linie;
    while (std::getline(fisier_in, linie)) {
        if (linie.empty() || linie[0] == '#') continue;
        std::istringstream iss(linie);
        int u, v, c;
        if (iss >> u >> v >> c) {
            if (!este_varf(u)) adauga_varf(u);
            if (!este_varf(v)) adauga_varf(v);
            adauga_muchie(u, v, c);

        } else {
            iss.clear();
            iss.str(linie);
            if (iss >> u) {
                if (!este_varf(u)) adauga_varf(u);
            }
        }
    }
}

void Graf::salveaza_graf_in_fisier(const std::string& fisier) const {
    std::ofstream fisier_out(fisier);
    if (!fisier_out.is_open()) {
        throw ExceptieFisier("Nu se poate deschide fișierul!");
    }
    for (auto v : varfuri) {
        if (grad_iesire(v) == 0 && grad_intrare(v) == 0) {
            fisier_out << v << "\n";
        }
        for (auto u : iesiri.at(v)) {
            fisier_out << v << " " << u << " " << obtine_cost(v, u) << "\n";
        }
    }
}

std::pair<long long, std::vector<int>> Graf::cel_mai_ieftin_drum(int varf_start, int varf_sfarsit, bool cu_costuri) const {
    if (!este_varf(varf_start) || !este_varf(varf_sfarsit)) {
        throw ExceptieVarf("Unul dintre vârfuri nu există în graf!");
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
        throw ExceptieDrumInexistent("Nu există drum între vârfurile specificate!");
    }

    std::vector<int> drum;
    for (int varf = varf_sfarsit; varf != -1; varf = parinte[varf]) {
        drum.push_back(varf);
    }
    std::reverse(drum.begin(), drum.end());

    return {distanta[varf_sfarsit], drum};
}

std::vector<std::pair<std::pair<int, int>, int>> Graf::sorteaza_muchii_dupa_cost() const {
    std::vector<std::pair<std::pair<int, int>, int>> muchii_sortate;
    for (auto &muchie : costuri) {
        muchii_sortate.push_back({muchie.first, muchie.second});
    }
    std::sort(muchii_sortate.begin(), muchii_sortate.end(),
              [](const std::pair<std::pair<int, int>, int> &a, const std::pair<std::pair<int, int>, int> &b) {
                  return a.second < b.second;
              });
    return muchii_sortate;
}

Graf Graf::algoritmul_kruskal() const {
    Graf arbore_minim;

    // Inițializare arbore minim
    for (int varf : obtine_varfuri()) {
        arbore_minim.adauga_varf(varf);
    }

    // Obține muchiile sortate după cost
    auto muchii_sortate = sorteaza_muchii_dupa_cost();

    // Inițializare componente (fiecare vârf e într-o componentă separată)
    std::map<int, int> componenta;
    for (int varf : obtine_varfuri()) {
        componenta[varf] = varf;
    }

    auto gaseste_componenta = [&componenta](int varf) {
        while (componenta[varf] != varf) {
            varf = componenta[varf];
        }
        return varf;
    };

    auto uneste_componentele = [&componenta, gaseste_componenta](int varf1, int varf2) {
        int rad1 = gaseste_componenta(varf1);
        int rad2 = gaseste_componenta(varf2);
        componenta[rad2] = rad1;
    };

    // Construirea arborelui minim
    for (auto &muchie : muchii_sortate) {
        int varf1 = muchie.first.first;
        int varf2 = muchie.first.second;
        int cost = muchie.second;

        if (gaseste_componenta(varf1) != gaseste_componenta(varf2)) {
            arbore_minim.adauga_muchie(varf1, varf2, cost);
            uneste_componentele(varf1, varf2);
        }
    }

    return arbore_minim;
}

// BFS function
std::vector<int> Graf::bfs(int start) const {
    if (!este_varf(start)) {
        throw ExceptieVarf("Varful de start nu există în graf!");
    }

    std::vector<int> rezultat;
    std::set<int> vizitat;
    std::queue<int> coada;

    coada.push(start);
    vizitat.insert(start);

    while (!coada.empty()) {
        int varf = coada.front();
        coada.pop();
        rezultat.push_back(varf);

        for (int vecin : obtine_varfuri_iesire(varf)) {
            if (vizitat.find(vecin) == vizitat.end()) {
                coada.push(vecin);
                vizitat.insert(vecin);
            }
        }
    }

    return rezultat;
}


// DFS function
void Graf::dfs_util(int varf, std::set<int>& vizitat, std::vector<int>& rezultat) const {
    vizitat.insert(varf);
    rezultat.push_back(varf);

    for (int vecin : obtine_varfuri_iesire(varf)) {
        if (vizitat.find(vecin) == vizitat.end()) {
            dfs_util(vecin, vizitat, rezultat);
        }
    }
}

std::vector<int> Graf::dfs(int start) const {
    if (!este_varf(start)) {
        throw ExceptieVarf("Varful de start nu există în graf!");
    }

    std::vector<int> rezultat;
    std::set<int> vizitat;

    dfs_util(start, vizitat, rezultat);

    return rezultat;
}


void Graf::dfs_cicluri(int varf, std::vector<bool>& vizitat, std::vector<int>& parinte, std::vector<int>& stiva, std::vector<std::vector<int>>& cicluri) const {
    vizitat[varf] = true;
    stiva.push_back(varf);

    for (int vecin : iesiri.at(varf)) {
        if (!vizitat[vecin]) {
            parinte[vecin] = varf;
            dfs_cicluri(vecin, vizitat, parinte, stiva, cicluri);
        } else if (std::find(stiva.begin(), stiva.end(), vecin) != stiva.end()) {
            std::vector<int> ciclu;
            for (auto it = stiva.rbegin(); *it != vecin; ++it) {
                ciclu.push_back(*it);
            }
            ciclu.push_back(vecin);
            std::reverse(ciclu.begin(), ciclu.end());
            cicluri.push_back(ciclu);
        }
    }

    stiva.pop_back();
}

std::vector<std::vector<int>> Graf::gaseste_toate_ciclurile() const {
    std::vector<bool> vizitat(varfuri.size(), false);
    std::vector<int> parinte(varfuri.size(), -1);
    std::vector<int> stiva;
    std::vector<std::vector<int>> cicluri;

    for (int varf : varfuri) {
        if (!vizitat[varf]) {
            dfs_cicluri(varf, vizitat, parinte, stiva, cicluri);
        }
    }

    return cicluri;
}
int Graf::cost_arbore_partial_minim() const {
    // Get the sorted edges by cost
    auto muchii_sortate = sorteaza_muchii_dupa_cost();

    // Initialize Union-Find structures
    std::vector<int> parinte(varfuri.size());
    std::iota(parinte.begin(), parinte.end(), 0);
    std::vector<int> rang(varfuri.size(), 0);

    std::function<int(int)> gaseste_set = [&parinte, &gaseste_set](int varf) {
        if (parinte[varf] != varf) {
            parinte[varf] = gaseste_set(parinte[varf]);
        }
        return parinte[varf];
    };

    auto uneste_seturi = [&parinte, &rang](int set1, int set2) {
        if (rang[set1] < rang[set2]) {
            parinte[set1] = set2;
        } else if (rang[set1] > rang[set2]) {
            parinte[set2] = set1;
        } else {
            parinte[set2] = set1;
            rang[set1]++;
        }
    };

    int cost_total = 0;
    for (const auto& muchie : muchii_sortate) {
        int varf1 = muchie.first.first;
        int varf2 = muchie.first.second;
        int cost = muchie.second;

        int set1 = gaseste_set(varf1);
        int set2 = gaseste_set(varf2);

        if (set1 != set2) {
            cost_total += cost;
            uneste_seturi(set1, set2);
        }
    }

    return cost_total;
}


std::pair<int, std::vector<int>> Graf::lant_minim_capacitate(int s) const {
    if (!este_varf(s)) {
        throw ExceptieVarf("Varful de start nu există în graf!");
    }

    std::map<int, int> distanta;
    std::map<int, int> parinte;
    for (int varf : varfuri) {
        distanta[varf] = INF;
        parinte[varf] = -1;
    }
    distanta[s] = 0;

    std::set<std::pair<int, int>> coada;
    coada.insert({0, s});

    while (!coada.empty()) {
        int varf_curent = coada.begin()->second;
        coada.erase(coada.begin());

        for (int vecin : obtine_varfuri_iesire(varf_curent)) {
            int cost = obtine_cost(varf_curent, vecin);
            if (distanta[varf_curent] + cost < distanta[vecin]) {
                coada.erase({distanta[vecin], vecin});
                distanta[vecin] = distanta[varf_curent] + cost;
                parinte[vecin] = varf_curent;
                coada.insert({distanta[vecin], vecin});
            }
        }
    }

    int min_capacitate = INF;
    std::vector<int> lant;
    for (int varf : varfuri) {
        if (varf != s && parinte[varf] != -1 && parinte[parinte[varf]] != -1) {
            if (distanta[varf] < min_capacitate) {
                min_capacitate = distanta[varf];
                lant.clear();
                for (int v = varf; v != -1; v = parinte[v]) {
                    lant.push_back(v);
                }
                std::reverse(lant.begin(), lant.end());
            }
        }
    }

    if (lant.size() < 3) {
        throw ExceptieDrumInexistent("Nu există un lanț cu cel puțin 2 muchii!");
    }

    return {min_capacitate, lant};
}

std::map<int, int> Graf::dijkstra(int start) const {
    if (!este_varf(start)) {
        throw ExceptieVarf("Vârful de start nu există în graf!");
    }

    std::map<int, int> distanta;
    std::map<int, int> parinte;
    for (int varf : varfuri) {
        distanta[varf] = std::numeric_limits<int>::max();
        parinte[varf] = -1;
    }
    distanta[start] = 0;

    using Element = std::pair<int, int>; // (distanta, varf)
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist_curenta = pq.top().first;
        int varf_curent = pq.top().second;
        pq.pop();

        if (dist_curenta > distanta[varf_curent]) {
            continue;
        }

        for (int vecin : obtine_varfuri_iesire(varf_curent)) {
            int cost = obtine_cost(varf_curent, vecin);
            if (distanta[varf_curent] + cost < distanta[vecin]) {
                distanta[vecin] = distanta[varf_curent] + cost;
                parinte[vecin] = varf_curent;
                pq.push({distanta[vecin], vecin});
            }
        }
    }

    return distanta;
}


Graf Graf::algoritmul_prim(int start) const {
    if (!este_varf(start)) {
        throw ExceptieVarf("Vârful de start nu există în graf!");
    }

    Graf arbore_minim;
    for (int varf : obtine_varfuri()) {
        arbore_minim.adauga_varf(varf);
    }

    using Muchie = std::pair<int, std::pair<int, int>>; // (cost, (varf_de_la, varf_la))
    std::priority_queue<Muchie, std::vector<Muchie>, std::greater<Muchie>> pq;
    std::set<int> vizitat;

    auto adauga_muchii = [&](int varf) {
        vizitat.insert(varf);
        for (int vecin : obtine_varfuri_iesire(varf)) {
            if (vizitat.find(vecin) == vizitat.end()) {
                pq.push({obtine_cost(varf, vecin), {varf, vecin}});
            }
        }
    };

    adauga_muchii(start);

    while (!pq.empty()) {
        auto [cost, muchie] = pq.top();
        pq.pop();
        int varf_de_la = muchie.first;
        int varf_la = muchie.second;

        if (vizitat.find(varf_la) == vizitat.end()) {
            arbore_minim.adauga_muchie(varf_de_la, varf_la, cost);
            adauga_muchii(varf_la);
        }
    }

    return arbore_minim;
}

bool Graf::bfs(int source, int sink, std::vector<int>& parent) {
    std::vector<bool> visited(varfuri.size(), false);
    std::queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : obtine_varfuri_iesire(u)) {
            if (!visited[v] && obtine_cost(u, v) > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == sink) {
                    return true;
                }
            }
        }
    }
    return false;
}

int Graf::ford_fulkerson(int source, int sink) {
    int max_flow = 0;
    std::vector<int> parent(varfuri.size());

    while (bfs(source, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = std::min(path_flow, static_cast<int>(obtine_cost(u, v)));
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            seteaza_cost(u, v, obtine_cost(u, v) - path_flow);
            seteaza_cost(v, u, obtine_cost(v, u) + path_flow);
        }

        max_flow += path_flow;
    }

    return max_flow;
}

bool Graf::bellman_ford(int start, std::map<int, long long>& distanta, std::map<int, int>& parinte) const {
    if (!este_varf(start)) {
        throw ExceptieVarf("Vârful de start nu există în graf!");
    }

    // Initialize distances from start to all other vertices as infinite
    for (int varf : varfuri) {
        distanta[varf] = LLONG_MAX;
        parinte[varf] = -1;
    }
    distanta[start] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 1; i < varfuri.size(); ++i) {
        for (const auto& muchie : costuri) {
            int u = muchie.first.first;
            int v = muchie.first.second;
            int cost = muchie.second;
            if (distanta[u] != LLONG_MAX && distanta[u] + cost < distanta[v]) {
                distanta[v] = distanta[u] + cost;
                parinte[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& muchie : costuri) {
        int u = muchie.first.first;
        int v = muchie.first.second;
        int cost = muchie.second;
        if (distanta[u] != LLONG_MAX && distanta[u] + cost < distanta[v]) {
            throw ExceptieCicluNegativ("Graful conține un ciclu de cost negativ!");
        }
    }

    return true;
}

bool Graf::este_conex() const {
    if (varfuri.empty()) return true;

    std::set<int> vizitat;
    std::queue<int> coada;
    int start = *varfuri.begin();
    coada.push(start);
    vizitat.insert(start);

    while (!coada.empty()) {
        int varf = coada.front();
        coada.pop();

        for (int vecin : obtine_varfuri_iesire(varf)) {
            if (vizitat.find(vecin) == vizitat.end()) {
                coada.push(vecin);
                vizitat.insert(vecin);
            }
        }
    }

    for (int varf : varfuri) {
        if (grad_iesire(varf) > 0 && vizitat.find(varf) == vizitat.end()) {
            return false;
        }
    }

    return true;
}

bool Graf::este_eulerian() const {
    if (!este_conex()) return false;

    int odd_degree_count = 0;
    for (int varf : varfuri) {
        if (grad_iesire(varf) % 2 != 0) {
            odd_degree_count++;
        }
    }

    return odd_degree_count == 0;
}

bool Graf::are_drum_eulerian() const {
    if (!este_conex()) return false;

    int odd_degree_count = 0;
    for (int varf : varfuri) {
        if (grad_iesire(varf) % 2 != 0) {
            odd_degree_count++;
        }
    }

    return odd_degree_count == 0 || odd_degree_count == 2;
}

std::vector<int> Graf::gaseste_circuit_eulerian() const {
    if (!este_eulerian()) {
        throw ExceptieCicluNegativ("Graful nu este eulerian!");
    }

    std::vector<int> circuit;
    std::stack<int> stiva;
    std::map<std::pair<int, int>, int> costuri = this->costuri;

    int start = *varfuri.begin();
    stiva.push(start);

    while (!stiva.empty()) {
        int varf = stiva.top();
        if (grad_iesire(varf) == 0) {
            circuit.push_back(varf);
            stiva.pop();
        } else {
            int vecin = *obtine_varfuri_iesire(varf).begin();
            stiva.push(vecin);
            costuri[std::make_pair(varf, vecin)]--;
            costuri[std::make_pair(vecin, varf)]--;
        }
    }

    return circuit;
}

bool Graf::este_hamltonian_util(int varf, std::vector<int>& drum, std::vector<bool>& vizitat, int& index) const {
    vizitat[varf] = true;
    drum[index++] = varf;

    if (index == varfuri.size()) {
        return true;
    }

    for (int vecin : obtine_varfuri_iesire(varf)) {
        if (!vizitat[vecin] && este_hamltonian_util(vecin, drum, vizitat, index)) {
            return true;
        }
    }

    vizitat[varf] = false;
    index--;
    return false;
}

bool Graf::este_hamiltonian() const {
    if (!este_conex()) return false;

    std::vector<int> drum(varfuri.size(), -1);
    std::vector<bool> vizitat(varfuri.size(), false);
    int index = 0;

    return este_hamltonian_util(*varfuri.begin(), drum, vizitat, index);
}

bool Graf::este_bipartit() const {
    if (varfuri.empty()) return true;

    std::map<int, int> culori;
    for (int varf : varfuri) {
        culori[varf] = -1; // -1 means no color assigned
    }

    std::queue<int> coada;
    for (int start : varfuri) {
        if (culori[start] == -1) {
            culori[start] = 0;
            coada.push(start);

            while (!coada.empty()) {
                int varf = coada.front();
                coada.pop();

                for (int vecin : obtine_varfuri_iesire(varf)) {
                    if (culori[vecin] == -1) {
                        culori[vecin] = 1 - culori[varf];
                        coada.push(vecin);
                    } else if (culori[vecin] == culori[varf]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

std::vector<int> Graf::kahn_topological_sort() const {
    std::map<int, int> in_degree;
    for (int varf : varfuri) {
        in_degree[varf] = 0;
    }

    for (const auto& muchie : costuri) {
        in_degree[muchie.first.second]++;
    }

    std::queue<int> zero_in_degree;
    for (const auto& [varf, degree] : in_degree) {
        if (degree == 0) {
            zero_in_degree.push(varf);
        }
    }

    std::vector<int> topological_order;
    while (!zero_in_degree.empty()) {
        int varf = zero_in_degree.front();
        zero_in_degree.pop();
        topological_order.push_back(varf);

        for (int vecin : obtine_varfuri_iesire(varf)) {
            in_degree[vecin]--;
            if (in_degree[vecin] == 0) {
                zero_in_degree.push(vecin);
            }
        }
    }

    if (topological_order.size() != varfuri.size()) {
        throw std::runtime_error("Graful conține un ciclu și nu poate fi sortat topologic.");
    }

    return topological_order;
}

void Graf::dfs_kosaraju(int varf, std::set<int>& vizitat, std::stack<int>& stiva) const {
    vizitat.insert(varf);
    for (int vecin : obtine_varfuri_iesire(varf)) {
        if (vizitat.find(vecin) == vizitat.end()) {
            dfs_kosaraju(vecin, vizitat, stiva);
        }
    }
    stiva.push(varf);
}

void Graf::dfs_transpus(int varf, std::set<int>& vizitat, std::vector<int>& componenta) const {
    vizitat.insert(varf);
    componenta.push_back(varf);
    for (int vecin : obtine_varfuri_intrare(varf)) {
        if (vizitat.find(vecin) == vizitat.end()) {
            dfs_transpus(vecin, vizitat, componenta);
        }
    }
}

Graf Graf::obtine_transpus() const {
    Graf transpus(varfuri.size(), neorientat);
    for (const auto& muchie : costuri) {
        transpus.adauga_muchie(muchie.first.second, muchie.first.first, muchie.second);
    }
    return transpus;
}

void Graf::tarjan_dfs(int varf, int& index, std::vector<int>& indexuri, std::vector<int>& lowlink, std::stack<int>& stiva, std::vector<bool>& in_stiva, std::vector<std::vector<int>>& componente) const {
    indexuri[varf] = lowlink[varf] = index++;
    stiva.push(varf);
    in_stiva[varf] = true;

    for (int vecin : obtine_varfuri_iesire(varf)) {
        if (indexuri[vecin] == -1) {
            tarjan_dfs(vecin, index, indexuri, lowlink, stiva, in_stiva, componente);
            lowlink[varf] = std::min(lowlink[varf], lowlink[vecin]);
        } else if (in_stiva[vecin]) {
            lowlink[varf] = std::min(lowlink[varf], indexuri[vecin]);
        }
    }

    if (lowlink[varf] == indexuri[varf]) {
        std::vector<int> componenta;
        int v;
        do {
            v = stiva.top();
            stiva.pop();
            in_stiva[v] = false;
            componenta.push_back(v);
        } while (v != varf);
        componente.push_back(componenta);
    }
}

std::vector<std::vector<int>> Graf::tarjan() const {
    std::vector<std::vector<int>> componente;
    std::vector<int> indexuri(varfuri.size(), -1);
    std::vector<int> lowlink(varfuri.size(), -1);
    std::vector<bool> in_stiva(varfuri.size(), false);
    std::stack<int> stiva;
    int index = 0;

    for (int varf : varfuri) {
        if (indexuri[varf] == -1) {
            tarjan_dfs(varf, index, indexuri, lowlink, stiva, in_stiva, componente);
        }
    }

    return componente;
}



std::vector<std::vector<int>> Graf::kosaraju() const {
    std::stack<int> stiva;
    std::set<int> vizitat;

    for (int varf : varfuri) {
        if (vizitat.find(varf) == vizitat.end()) {
            dfs_kosaraju(varf, vizitat, stiva);
        }
    }

    Graf transpus = obtine_transpus();
    vizitat.clear();
    std::vector<std::vector<int>> componente;

    while (!stiva.empty()) {
        int varf = stiva.top();
        stiva.pop();
        if (vizitat.find(varf) == vizitat.end()) {
            std::vector<int> componenta;
            transpus.dfs_transpus(varf, vizitat, componenta);
            componente.push_back(componenta);
        }
    }

    return componente;
}

std::vector<std::vector<int>> Graf::roy_floyd() const {
    int n = varfuri.size();
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX));

    // Initialize distances with edge weights
    for (const auto& muchie : costuri) {
        dist[muchie.first.first][muchie.first.second] = muchie.second;
    }

    // Distance from a vertex to itself is 0
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}


bool Graf::bfs_edmonds_karp(int source, int sink, std::vector<int>& parent) const {
    std::fill(parent.begin(), parent.end(), -1);
    std::queue<int> q;
    q.push(source);
    parent[source] = source;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : obtine_varfuri_iesire(u)) {
            if (parent[v] == -1 && obtine_cost(u, v) > 0) {
                parent[v] = u;
                if (v == sink) {
                    return true;
                }
                q.push(v);
            }
        }
    }

    return false;
}

int Graf::edmonds_karp(int source, int sink) const {
    int max_flow = 0;
    std::vector<int> parent(varfuri.size());

    while (bfs_edmonds_karp(source, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = std::min(path_flow, static_cast<int>(obtine_cost(u, v)));
        }


        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            const_cast<Graf *>(this)->seteaza_cost(u, v, obtine_cost(u, v) - path_flow);
            const_cast<Graf *>(this)->seteaza_cost(v, u, obtine_cost(v, u) + path_flow);
        }

        max_flow += path_flow;
    }

    return max_flow;
}

std::vector<int> Graf::a_star(int start, int goal, const std::function<int(int, int)>& heuristic) const {
    if (!este_varf(start) || !este_varf(goal)) {
        throw ExceptieVarf("Unul dintre vârfuri nu există în graf!");
    }

    std::map<int, int> g_score;
    std::map<int, int> f_score;
    std::map<int, int> parinte;
    for (int varf : varfuri) {
        g_score[varf] = INF;
        f_score[varf] = INF;
        parinte[varf] = -1;
    }
    g_score[start] = 0;
    f_score[start] = heuristic(start, goal);

    using Element = std::pair<int, int>; // (f_score, varf)
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> open_set;
    open_set.push({f_score[start], start});

    while (!open_set.empty()) {
        int varf_curent = open_set.top().second;
        open_set.pop();

        if (varf_curent == goal) {
            std::vector<int> path;
            for (int varf = goal; varf != -1; varf = parinte[varf]) {
                path.push_back(varf);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (int vecin : obtine_varfuri_iesire(varf_curent)) {
            int tentative_g_score = g_score[varf_curent] + obtine_cost(varf_curent, vecin);
            if (tentative_g_score < g_score[vecin]) {
                parinte[vecin] = varf_curent;
                g_score[vecin] = tentative_g_score;
                f_score[vecin] = g_score[vecin] + heuristic(vecin, goal);
                open_set.push({f_score[vecin], vecin});
            }
        }
    }

    throw ExceptieDrumInexistent("Nu există drum între vârfurile specificate!");
}

bool Graf::havel_hakimi(std::vector<int> degree_sequence) const {
    // Remove all zeros from the degree sequence
    degree_sequence.erase(std::remove(degree_sequence.begin(), degree_sequence.end(), 0), degree_sequence.end());

    // Sort the degree sequence in non-increasing order
    std::sort(degree_sequence.begin(), degree_sequence.end(), std::greater<int>());

    while (!degree_sequence.empty()) {
        // If the first element is greater than the number of remaining elements, return false
        if (degree_sequence[0] > degree_sequence.size() - 1) {
            return false;
        }

        // Remove the first element
        int first = degree_sequence[0];
        degree_sequence.erase(degree_sequence.begin());

        // Subtract 1 from the next 'first' elements
        for (int i = 0; i < first; ++i) {
            if (--degree_sequence[i] < 0) {
                return false;
            }
        }

        // Remove all zeros and sort again
        degree_sequence.erase(std::remove(degree_sequence.begin(), degree_sequence.end(), 0), degree_sequence.end());
        std::sort(degree_sequence.begin(), degree_sequence.end(), std::greater<int>());
    }

    return true;
}