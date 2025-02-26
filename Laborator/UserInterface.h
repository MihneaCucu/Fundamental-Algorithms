#pragma once

#include "graf.cpp"
#include <iostream>
using namespace std;

class InterfataUtilizator {
private:
    Graf *graf;

public:
    InterfataUtilizator() = default;

    explicit InterfataUtilizator(Graf *graf) {
        this->graf = graf;
    }

    static void afiseaza_meniu_principal() {
        cout << " ---> Meniu Principal <--- " << endl;
        cout << "1 - Afișează numărul de vârfuri" << endl;
        cout << "2 - Parcurge mulțimea de vârfuri" << endl;
        cout << "3 - Verifică dacă există o muchie" << endl;
        cout << "4 - Obține costul unei muchii" << endl;
        cout << "5 - Obține gradul de intrare al unui vârf" << endl;
        cout << "6 - Obține gradul de ieșire al unui vârf" << endl;
        cout << "7 - Parcurge mulțimea muchiilor care ies dintr-un vârf" << endl;
        cout << "8 - Parcurge mulțimea muchiilor care intră într-un vârf" << endl;
        cout << "9 - Parcurge mulțimea de muchii" << endl;
        cout << "10 - Adaugă un vârf nou" << endl;
        cout << "11 - Adaugă o muchie nouă" << endl;
        cout << "12 - Șterge un vârf" << endl;
        cout << "13 - Șterge o muchie" << endl;
        cout << "14 - Modifică costul unei muchii" << endl;
        cout << "15 - Salvează graful într-un fișier" << endl;
        cout << "16 - Copiază graful și salvează-l în copy_graf.txt" << endl;
        cout << "17 - Afișează cel mai ieftin drum între două vârfuri cu costuri" << endl;
        cout << "18 - Afișează cel mai ieftin drum între două vârfuri fara costuri" << endl;
        cout << "19 - Afișează arborele minim folosind algoritmul lui Kruskal" << endl;
        cout << "20 - Parcurgere BFS" << endl;
        cout << "21 - Parcurgere DFS" << endl;
        cout << "22 - Găsește toate ciclurile" << endl;
        cout << "23 - Găsește un ciclu elementar impar" << endl;
        cout << "24 - Calculeaza costul arborelui partial minim" << endl;
        cout << "25 - Adaugă muchia care minimizează costul arborelui parțial minim" << endl;
        cout << "26 - Lant minim capacitate" << endl;
        cout << "27 - Dijkstra" << endl;
        cout << "28 - Prim" << endl;
        cout << "29 - Ford Fulkerson" << endl;
        cout << "30 - Bellman Ford" << endl;
        cout << "31 - Găsește circuit eulerian" << endl;
        cout << "32 - Este hamiltonian" << endl;
        cout << "33 - Este bipartit" << endl;
        cout << "34 - Kahn" << endl;
        cout << "35 - Topological Sort" << endl;
        cout << "36 - Tarjan" << endl;
        cout << "37 - Roy-Floyd" << endl;
        cout << "38 - Edmonds-Karp" << endl;
        cout << "39 - A*" << endl;
        cout << "40 - Havel Hakimi" << endl;
        cout << "41 - Face Parte" << endl;
        cout << "x - Ieșire" << endl;
    }

    void meniu_principal() {
        string comanda;
        while (true) {
            afiseaza_meniu_principal();
            cout << "Introdu comanda: ";
            cin >> comanda;

            if (comanda == "1") {
                cout << "Numărul de vârfuri este: " << graf->numar_varfuri() << endl;
            } else if (comanda == "2") {
                cout << "Mulțimea de vârfuri este: ";
                for (auto varf: graf->obtine_varfuri()) {
                    cout << varf << " ";
                }
                cout << endl;
            } else if (comanda == "3") {
                int varf1, varf2;
                cout << "Introdu primul vârf: ";
                cin >> varf1;
                cout << "Introdu al doilea vârf: ";
                cin >> varf2;
                if (graf->este_muchie(varf1, varf2)) {
                    cout << "Există o muchie între aceste două vârfuri" << endl;
                } else {
                    cout << "Nu există o muchie între aceste două vârfuri" << endl;
                }
            } else if (comanda == "4") {
                int varf1, varf2;
                cout << "Introdu primul vârf: ";
                cin >> varf1;
                cout << "Introdu al doilea vârf: ";
                cin >> varf2;
                cout << "Costul este: " << graf->obtine_cost(varf1, varf2) << endl;
            } else if (comanda == "5") {
                int varf;
                cout << "Introdu vârful: ";
                cin >> varf;
                cout << "Gradul de intrare este: " << graf->grad_intrare(varf) << endl;
            } else if (comanda == "6") {
                int varf;
                cout << "Introdu vârful: ";
                cin >> varf;
                cout << "Gradul de ieșire este: " << graf->grad_iesire(varf) << endl;
            } else if (comanda == "7") {
                int varf;
                cout << "Introdu vârful: ";
                cin >> varf;
                cout << "Mulțimea muchiilor care ies este: ";
                for (auto iesire: graf->obtine_varfuri_iesire(varf)) {
                    cout << iesire << " ";
                }
                cout << endl;
            } else if (comanda == "8") {
                int varf;
                cout << "Introdu vârful: ";
                cin >> varf;
                cout << "Mulțimea muchiilor care intră este: ";
                for (auto intrare: graf->obtine_varfuri_intrare(varf)) {
                    cout << intrare << " ";
                }
                cout << endl;
            } else if (comanda == "9") {
                cout << "Mulțimea de muchii este: ";
                for (auto muchie: graf->obtine_muchii()) {
                    cout << "(" << muchie.first << ", " << muchie.second << ") ";
                }
                cout << endl;
            } else if (comanda == "10") {
                int varf;
                cout << "Introdu vârful de adăugat: ";
                cin >> varf;
                try {
                    graf->adauga_varf(varf);
                    cout << "Vârful a fost adăugat cu succes" << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "11") {
                int varf1, varf2, cost;
                cout << "Introdu primul vârf: ";
                cin >> varf1;
                cout << "Introdu al doilea vârf: ";
                cin >> varf2;
                cout << "Introdu costul: ";
                cin >> cost;
                try {
                    graf->adauga_muchie(varf1, varf2, cost);
                    cout << "Muchia a fost adăugată cu succes" << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                } catch (ExceptieMuchie &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "12") {
                int varf;
                cout << "Introdu vârful de șters: ";
                cin >> varf;
                try {
                    graf->sterge_varf(varf);
                    cout << "Vârful a fost șters cu succes" << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "13") {
                int varf1, varf2;
                cout << "Introdu primul vârf: ";
                cin >> varf1;
                cout << "Introdu al doilea vârf: ";
                cin >> varf2;
                try {
                    graf->sterge_muchie(varf1, varf2);
                    cout << "Muchia a fost ștearsă cu succes" << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                } catch (ExceptieMuchie &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "14") {
                int varf1, varf2, cost;
                cout << "Introdu primul vârf: ";
                cin >> varf1;
                cout << "Introdu al doilea vârf: ";
                cin >> varf2;
                cout << "Introdu noul cost: ";
                cin >> cost;
                try {
                    graf->seteaza_cost(varf1, varf2, cost);
                    cout << "Costul a fost modificat cu succes" << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                } catch (ExceptieMuchie &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "15") {
                string fisier;
                cout << "Introdu numele fișierului: ";
                cin >> fisier;
                try {
                    graf->salveaza_graf_in_fisier(fisier);
                    cout << "Graful a fost salvat cu succes" << endl;
                } catch (ExceptieFisier &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "16") {
                try {
                    Graf *copie = new Graf(*graf);
                    copie->salveaza_graf_in_fisier("copy_graf.txt");
                    cout << "Graful a fost copiat cu succes" << endl;
                } catch (ExceptieFisier &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "17") {
                int varf_start, varf_sfarsit;
                cout << "Introdu vârful de start: ";
                cin >> varf_start;
                cout << "Introdu vârful de sfârșit: ";
                cin >> varf_sfarsit;
                try {
                    auto rezultat = graf->cel_mai_ieftin_drum(varf_start, varf_sfarsit, true);
                    cout << "Costul minim este: " << rezultat.first << endl;
                    cout << "Drumul este: ";
                    for (auto varf: rezultat.second) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieDrumInexistent &e) {
                    cout << e.what() << endl;
                } catch (ExceptieCicluNegativ &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "18") {
                int varf_start, varf_sfarsit;
                cout << "Introdu vârful de start: ";
                cin >> varf_start;
                cout << "Introdu vârful de sfârșit: ";
                cin >> varf_sfarsit;
                try {
                    auto rezultat = graf->cel_mai_ieftin_drum(varf_start, varf_sfarsit, true);
                    cout << "Costul minim este: " << rezultat.first << endl;
                    cout << "Drumul este: ";
                    for (auto varf: rezultat.second) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieDrumInexistent &e) {
                    cout << e.what() << endl;
                } catch (ExceptieCicluNegativ &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "19") {
                Graf arbore_minim = graf->algoritmul_kruskal();
                cout << "Arborele minim este: " << endl;
                for (auto muchie: arbore_minim.obtine_muchii()) {
                    cout << "(" << muchie.first << ", " << muchie.second << ") ";
                }
                cout << endl;
            }

            else if (comanda == "20") {
                int start;
                cout << "Introdu vârful de start: ";
                cin >> start;
                try {
                    auto rezultat = graf->bfs(start);
                    cout << "Parcurgerea BFS este: ";
                    for (auto varf: rezultat) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            } else if (comanda == "21") {
                int start;
                cout << "Introdu vârful de start: ";
                cin >> start;
                try {
                    auto rezultat = graf->dfs(start);
                    cout << "Parcurgerea DFS este: ";
                    for (auto varf: rezultat) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "22") {
                auto cicluri = graf->gaseste_toate_ciclurile();
                if (!cicluri.empty()) {
                    cout << "Ciclurile găsite sunt: " << endl;
                    for (const auto& ciclu : cicluri) {

                            for (int varf : ciclu) {
                                cout << varf << " ";
                            }
                            cout << endl;

                    }
                } else {
                    cout << "Nu a fost găsit niciun ciclu." << endl;
                }
            }

            else if (comanda == "23") {
                auto cicluri = graf->gaseste_toate_ciclurile();
                if (!cicluri.empty()) {
                    std::vector<std::vector<int>> cicluri_impare;
                    for (const auto& ciclu : cicluri) {
                        if (ciclu.size() % 2 == 1) {
                            cout << "a)" << endl;
                            cicluri_impare.push_back(ciclu);
                        }
                    }

                    if (cicluri_impare.size() > 0) {
                        cout << "Ciclul găsit este: " << endl;
                        for (int varf : cicluri_impare[0]) {
                            cout << varf << " ";
                        }
                        cout << endl;

                        for (const auto& ciclu : cicluri) {
                            if (ciclu != cicluri_impare[0] && ciclu.size() > 2) {
                                cout << "b)" << endl;
                                cout << "Ciclul găsit este: " << endl;
                                for (int varf : ciclu) {
                                    cout << varf << " ";
                                }
                                cout << endl;
                                break;
                            }

                        }
                    } else {
                        cout << "Nu a fost găsit niciun ciclu impar." << endl;
                    }
                } else {
                    cout << "Nu a fost găsit niciun ciclu." << endl;
                }
            }

            else if (comanda == "24") {
                cout << "Costul arborelui partial minim este: " << graf->cost_arbore_partial_minim() << endl;
            }

            else if (comanda == "25") {
                int varf1, varf2, cost1, varf3, varf4, cost2;
                cout << "Introdu primul vârf al primei muchii: ";
                cin >> varf1;
                cout << "Introdu al doilea vârf al primei muchii: ";
                cin >> varf2;
                cout << "Introdu costul primei muchii: ";
                cin >> cost1;
                cout << "Introdu primul vârf al celei de-a doua muchii: ";
                cin >> varf3;
                cout << "Introdu al doilea vârf al celei de-a doua muchii: ";
                cin >> varf4;
                cout << "Introdu costul celei de-a doua muchii: ";
                cin >> cost2;

                // Adaugă prima muchie și calculează costul arborelui parțial minim
                graf->adauga_muchie(varf1, varf2, cost1);
                int cost1_total = graf->cost_arbore_partial_minim();
                graf->sterge_muchie(varf1, varf2);

                // Adaugă a doua muchie și calculează costul arborelui parțial minim
                graf->adauga_muchie(varf3, varf4, cost2);
                int cost2_total = graf->cost_arbore_partial_minim();
                graf->sterge_muchie(varf3, varf4);

                // Adaugă muchia care minimizează costul arborelui parțial minim
                if (cost1_total < cost2_total) {
                    graf->adauga_muchie(varf1, varf2, cost1);
                    cout << "Muchia adăugată este: (" << varf1 << ", " << varf2 << ") cu costul " << cost1 << endl;
                } else {
                    graf->adauga_muchie(varf3, varf4, cost2);
                    cout << "Muchia adăugată este: (" << varf3 << ", " << varf4 << ") cu costul " << cost2 << endl;
                }

                // Afișează muchiile arborelui parțial minim
                auto arbore_minim = graf->algoritmul_kruskal();
                cout << "Muchiile arborelui parțial minim sunt: ";
                for (auto muchie : arbore_minim.obtine_muchii()) {
                    cout << "(" << muchie.first << ", " << muchie.second << ") ";
                }
                cout << endl;
            }

            else if (comanda == "26") {
                int varf_start;
                cout << "Introdu vârful de start: ";
                cin >> varf_start;
                try {
                    auto rezultat = graf->lant_minim_capacitate(varf_start);
                    cout << "Costul minim este: " << rezultat.first << endl;
                    cout << "Drumul este: ";
                    for (auto varf: rezultat.second) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "27") {
                int start;
                cout << "Introdu vârful de start: ";
                cin >> start;
                try {
                    auto distanta = graf->dijkstra(start);
                    cout << "Distanțele minime de la vârful " << start << " sunt: " << endl;
                    for (const auto &[varf, dist]: distanta) {
                        cout << "Vârful " << varf << ": " << dist << endl;
                    }
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }
            
            else if (comanda == "28") {
                int start;
                cout << "Introdu vârful de start: ";
                cin >> start;
                try {
                    auto arbore_minim = graf->algoritmul_prim(start);
                    cout << "Arborele minim este: " << endl;
                    for (auto muchie: arbore_minim.obtine_muchii()) {
                        cout << "(" << muchie.first << ", " << muchie.second << ") ";
                    }
                    cout << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "29") {
                int source, sink;
                cout << "Introdu vârful sursă: ";
                cin >> source;
                cout << "Introdu vârful destinație: ";
                cin >> sink;
                try {
                    int max_flow = graf->ford_fulkerson(source, sink);
                    cout << "Fluxul maxim este: " << max_flow << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "30") {
                int start;
                cout << "Introdu vârful de start: ";
                cin >> start;
                try {
                    std::map<int, long long> distanta;
                    std::map<int, int> parinte;
                    graf->bellman_ford(start, distanta, parinte);
                    cout << "Distanțele minime de la vârful " << start << " sunt: " << endl;
                    for (const auto &[varf, dist]: distanta) {
                        cout << "Vârful " << varf << ": " << dist << endl;
                    }
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                } catch (ExceptieCicluNegativ &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "31") {
                try {
                    auto circuit = graf->gaseste_circuit_eulerian();
                    cout << "Circuitul eulerian este: ";
                    for (auto varf : circuit) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieCicluNegativ &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "32") {
                if (graf->este_hamiltonian()) {
                    cout << "Graful este hamiltonian" << endl;
                } else {
                    cout << "Graful nu este hamiltonian" << endl;
                }
            }

            else if (comanda == "33") {
                if (graf->este_bipartit()) {
                    cout << "Graful este bipartit" << endl;
                } else {
                    cout << "Graful nu este bipartit" << endl;
                }
            }

            else if (comanda == "34") {
                try {
                    auto sortare = graf->kahn_topological_sort();
                    cout << "Sortarea topologică este: ";
                    for (auto varf : sortare) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieCicluNegativ &e) {
                    cout << e.what() << endl;
                }
            }
            else if (comanda == "35") {
                try {
                    auto componente = graf->kosaraju();
                    cout << "Componentele tare conexe sunt: " << endl;
                    for (const auto& componenta : componente) {
                        for (int varf : componenta) {
                            cout << varf << " ";
                        }
                        cout << endl;
                    }
                } catch (exception &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "36") {
            try {
                auto componente = graf->tarjan();
                cout << "Componentele tare conexe sunt: " << endl;
                for (const auto& componenta : componente) {
                    for (int varf : componenta) {
                        cout << varf << " ";
                    }
                    cout << endl;
                }
            } catch (exception &e) {
                cout << e.what() << endl;
            }}

            else if (comanda == "37") {
                try {
                    auto dist = graf->roy_floyd();
                    cout << "Matricea distanțelor minime este: " << endl;
                    for (const auto& row : dist) {
                        for (int d : row) {
                            if (d == INT_MAX) {
                                cout << "INF ";
                            } else {
                                cout << d << " ";
                            }
                        }
                        cout << endl;
                    }
                } catch (exception &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "38") {
                int source, sink;
                cout << "Introdu vârful sursă: ";
                cin >> source;
                cout << "Introdu vârful destinație: ";
                cin >> sink;
                try {
                    int max_flow = graf->edmonds_karp(source, sink);
                    cout << "Fluxul maxim este: " << max_flow << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "39") {
                int start, goal;
                cout << "Introdu vârful de start: ";
                cin >> start;
                cout << "Introdu vârful țintă: ";
                cin >> goal;
                try {
                    auto drum = graf->a_star(start, goal, [](int, int) { return 0; });
                    cout << "Drumul găsit este: ";
                    for (int varf : drum) {
                        cout << varf << " ";
                    }
                    cout << endl;
                } catch (ExceptieVarf &e) {
                    cout << e.what() << endl;
                }
            }

            else if (comanda == "40") {
                string secventa;
                cout << "Introdu secvența de grade separate prin spațiu: ";
                cin.ignore();
                getline(cin, secventa);
                vector<int> degree_sequence;
                istringstream iss(secventa);
                int degree;
                while (iss >> degree) {
                    degree_sequence.push_back(degree);
                }
                try {
                    if (graf->havel_hakimi(degree_sequence)) {
                        cout << "Secvența este grafică" << endl;
                    } else {
                        cout << "Secvența nu este grafică" << endl;
                    }
                } catch (exception &e) {
                    cout << "Probabil nu ai introdus valori numerice" << endl;
                }
            }

            else if (comanda == "41") {
                int nr_linii,a,b,c,rez[101];
                cout << "Introdu numarul de linii: ";
                cin >> nr_linii;
                for(int i=0;i<nr_linii;i++){
                    cout << "Introdu linia: ";
                    cin>>a>>b>>c;
                    if(graf->face_parte_din_traseu(a,b,c)){
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
            }




            else if (comanda == "x") {
                break;
            } else {
                cout << "Comandă invalidă" << endl;
            }
        }
    }

    static void afiseaza_meniu_start() {
        cout << "1 - Citește un graf din fișier" << endl;
        cout << "2 - Generează un graf aleator și salvează-l în random_graf.txt" << endl;
        cout << "x - Ieșire" << endl;
    }

    void start() {
        while (true) {
            afiseaza_meniu_start();
            string comanda;
            cout << "Introdu comanda: ";
            cin >> comanda;

            if (comanda == "1") {
                string nume_fisier;
                cout << "Introdu numele fișierului: ";
                cin >> nume_fisier;
                try {
                    graf = new Graf();
                    graf->citeste_graf_din_fisier(nume_fisier);
                    cout << "Graful a fost citit cu succes din fișier" << endl;
                } catch (ExceptieFisier &e) {
                    cout << e.what() << endl;
                }
                meniu_principal();
            } else if (comanda == "2") {
                try {
                    int nr_varfuri;
                    cout << "Introdu numărul de vârfuri: ";
                    cin >> nr_varfuri;
                    int nr_muchii;
                    cout << "Introdu numărul de muchii: ";
                    cin >> nr_muchii;
                    graf = new Graf(nr_varfuri);
                    graf->genereaza_graf_aleator(nr_varfuri, nr_muchii, true);
                    graf->salveaza_graf_in_fisier("random_graf.txt");
                    cout << "Graful aleator a fost generat și salvat" << endl;
                } catch (exception &e) {
                    cout << "Probabil nu ai introdus valori numerice" << endl;
                }
            } else if (comanda == "x") {
                return;
            } else {
                cout << "Comandă invalidă" << endl;
            }
        }
    }
};
