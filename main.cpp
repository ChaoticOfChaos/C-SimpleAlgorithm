#include <algorithm>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "randomINT.hpp"

int main() {
    // Map de Conteúdos que Normalmente Aparecem em Redes Sociais
    std::map<std::string, std::map<std::string, int>> Conteudos;

    // Vector do Map de Conteudos
    std::vector<std::string> ConteudosList;

    int tagMin;
    int tagMax;

    // Tag que Simula o Video do Feed
    std::string tag;
    int userResp;
    int maxResultado = 0;
    
    // Conteúdos que Normalmente Aparecem nas Redes Sociais
    Conteudos = {
        {"Carros", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Motos", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"ASMR", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"+18", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Moda", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Programacao", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Hacking", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Musica", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Guitarra", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Baixo", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
        {"Bateria", {{"pontuacao", 0}, {"minimo", 0}, {"maximo", 100}, {"resultado", 0}}},
    };
    
    // Intera as Chaves do Map no Vector
    for (const auto& pair : Conteudos) {
        ConteudosList.push_back(pair.first);
    }
    
    while (1) {
        // É Como Jogar um Par ou Ímpar
        // Gera um Número Aleatório para Cada Tag
        // A Tag com Maior Número Aparece no Seu Feed
        for (std::string tags : ConteudosList) {
            tagMin = Conteudos[tags]["minimo"];
            tagMax = Conteudos[tags]["maximo"];
            Conteudos[tags]["resultado"] = randomINT(tagMin, tagMax);
        }
        
        for (const auto& pair : Conteudos) {
            const std::string& tagPair = pair.first;
            const std::map<std::string, int>& subMap = pair.second;
            
            auto it = subMap.find("resultado");
            if (it != subMap.end()) {
                int resultadoPair = it->second;
                if (resultadoPair > maxResultado){
                    maxResultado = resultadoPair;
                    tag = tagPair;
                }
            }
        }
        
        std::cout << "Video : " << tag << std::endl;
        std::cout << "(1) -> Like\n(2) -> Deslike\n(3) -> Passar\n(0) -> Debug\n(99) -> EXIT\n";
        std::cout << "-> ";
        std::cin >> userResp;
        
        if (userResp == 1) {
            // Caso Você Curta Algum Conteúdo
            // Ele Aumenta um Ponto Daquele Conteúdo
            // E Aumenta a Chance de Aparecer Aquele Conteúdo
            Conteudos[tag]["pontuacao"]++;
            Conteudos[tag]["maximo"] += 5;
        }
        else if (userResp == 2) {
            // Caso Você Não Goste de Algum Conteúdo
            // Ele Diminui um Ponto Daquele Conteúdo
            // 
            Conteudos[tag]["pontuacao"]--;
            if (Conteudos[tag]["maximo"] < 6) {
                // Caso a Tag Tenha o Número Mínimo
                // Ele Não Muda
                Conteudos[tag]["maximo"] = 1;
            }
            else {
                // Caso Contrario
                // Ele Diminui
                Conteudos[tag]["maximo"] -= 5;
            }
        }
        else if (userResp == 0) {
            for (std::string tags : ConteudosList) {
                // Método Para Ver Suas Tags Favoritas
                std::cout << tags << "    :    " << Conteudos[tags]["pontuacao"] << "    :    " << Conteudos[tags]["minimo"] << "    :    " << Conteudos[tags]["maximo"] << "    :    " << Conteudos[tags]["resultado"] << std::endl;
            }
        }
        else if (userResp == 99) {
            // Sair do Aplicativo(Você Não Vai Querer Isso)
            // Ou Ao Menos o Que as Redes Sociais Iriam Dizer
            break;
        }
        
        for (std::string tags : ConteudosList) {
            // Caso Alguma Tag Tenha Menos de -5 Pontos
            // Elas São Removidas do Seu Repertório de Tags
            if (Conteudos[tags]["pontuacao"] < -5) {
                Conteudos.erase(tags);
                ConteudosList.erase(std::remove(ConteudosList.begin(), ConteudosList.end(), tags), ConteudosList.end());
            }
        }
    }
    return 0;
}