/*
Projeto: Gerar a descrição de uma cena gráfica e calcular sua área e volume.
Autor: Otavio Augusto Miguel        Matricula: 2025.1.08.041
Disciplina: Algoritmo e estrutura de dados
Criado em 23/03/25
Local: Universidade Federal de Alfenas
Objetivo: Desenvolver um algoritmo que descreva uma cena grafica e calcule a area e o volume
das formas geometricas e no final somar a area e o volume
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ofstream arquivo("cenagrafica.txt");
    string figura;
    if (!arquivo.is_open()) {
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    int numero = -1;
    
    while (numero != 0) {
        cout << "Quais figuras a cena possui:" << endl;
        cout << "Figuras 2D:" << endl;
        cout << "1. circulo" << endl;
        cout << "2. triangulo" << endl;
        cout << "3. quadrado" << endl;
        cout << "4. retangulo" << endl;
        cout << "5. losangulo" << endl;
        cout << "6. trapezio" << endl;
        cout << "7. paralelograma" << endl;
        cout << "8. pentagono" << endl;
        cout << "9. hexagono" << endl;
        cout << "10. heptagono" << endl;
        cout << "11. octagono" << endl;
        cout << "Figuras 3D:" << endl;
        cout << "12. cubo" << endl;
        cout << "13. cilindro" << endl;
        cout << "14. esfera" << endl; 
        cout << "15. cone" << endl;
        cout << "16. piramide" << endl;
        cout << "17. paralelepipedo" << endl;
        cout << "18. tetraedo" << endl;
        cout << "0. para finalizar" << endl;

        cin >> numero;

    if (numero == 1) {      //Caso a figura for um circulo
        cout << "Digite o raio:";
        double raio;
        cin >> raio;
        arquivo << "circulo\t" << raio << endl;
    } else if (numero == 2) {       //Caso a figura for um triangulo
        cout << "Digite os 3 lados do triangulo:";
        double lado1, lado2, lado3;
        cin >> lado1 >> lado2 >>lado3;
        arquivo << "triangulo\t" << lado1 << " " << lado2 << " " << lado3 << endl;
    } else if (numero == 3) {       //Caso a figura for um quadrado
        cout << "Digite o lado do quadrado:";
        double lado;
        cin >> lado;
        arquivo << "quadrado\t" << lado << endl;
    } else if (numero == 4) {       //Caso a figura for um retangulo
        cout << "Digite os lados do retangulo:";
        double lado1, lado2;
        cin >> lado1 >> lado2;
        arquivo << "retangulo\t" << lado1 << " " << lado2 << endl;
    } else if (numero == 5) {       //Caso a figura for um losangulo
        cout << "Digite o diametro maior e menor do losangulo:";
        double dmaior, dmenor;
        cin >> dmaior >> dmenor;
        arquivo << "losangulo\t" << dmaior << " " << dmenor << endl; 
    } else if (numero == 6) {       //Caso a figura for um trapezio
        cout << "Digite a bases maior e menor do trapezio:";
        double bmaior, bmenor;
        cin >> bmaior >> bmenor;
        arquivo << "trapezio\t" << bmaior << " " << bmenor << endl;
    } else if ( numero == 7) {      //Caso a figura for um paralelograma
        cout << "Digite a altura e base do paralelograma:";
        double altura, base;
        cin >> altura >> base;
        arquivo << "paralelograma\t" << altura << " " << base << endl;
    } else if (numero == 8) {       //Caso a figura for um pentagono
        cout << "Digite a altura do pentagono:";
        double altura;
        cin >> altura;
        arquivo << "pentagono\t" << altura << endl;
    } else if (numero == 9) {       //Caso a figura for um hexagono
        cout << "Digite o comprimento do hexagono:";
        double complado;
        cin >> complado;
        arquivo << "hexagono\t" << complado << endl;
    } else if (numero == 10) {      //Caso a figura for um heptagono
        cout << "Digite a altura e o comprimento do heptagono:";
        double altura, complado;
        cin >> altura >> complado;
        arquivo << "heptagono\t" << altura << " " << complado << endl;
    } else if (numero == 11) {      //Caso a figura for um octagono
        cout << "Digite a altura e o comprimento do octagono:";
        double altura, complado;
        cin >> altura >> complado;
        arquivo << "octagono\t" << altura << " " << complado << endl;
    } else if (numero == 12) {      //Caso a figura for um cubo
        cout << "Digite o lado  do cubo:";
        double lado;
        cin >> lado;
        arquivo << "cubo\t" << lado << endl;
    } else if (numero == 13 ){      //Caso a figura for um cilindro
        cout << "Digite o raio e a altura do cilindro:";
        double raio, altura;
        cin >> raio >> altura;
        arquivo << "cilindro\t" << raio << " " << altura << endl;
     } else if (numero == 14) {     //Caso a figura for uma esfera
        cout << "Digite o raio da esfera:";
        double raio;
        cin >> raio;
        arquivo << "esfera\t" << raio << endl;
     } else if (numero == 15) {     //Caso a figura for um cone
        cout << "Digite o raio e a altura do cone:";
        double raio, altura;
        cin >> raio >> altura;
        arquivo << "cone\t" << raio << " " << altura << endl;
     } else if (numero == 16) {     //Caso a figura for uma piramide
        cout << "Digite a base e a altura da piramide:";
        double base, altura;
        cin >> base >> altura;
        arquivo << "piramide\t" << base << " " << altura << endl;
     } else if (numero == 17) {     //Caso a figura for um paralelepipedo
        cout << "Digite o altura, comprimento e largura do paralelepipedo:";
        double altura, comprimento, largura;
        cin >> altura >> comprimento >> largura;
        arquivo << "paralelepipedo\t" << altura << " " << comprimento << " " << largura << endl;
     } else if (numero == 18) {     //Caso a figura for um tetraedo
        cout << "Digite o lado do tetraedo:";
        double lado;
        cin >> lado;
        arquivo << "tetraedo\t" << lado << endl;
     } else if (numero == 0) {      //Caso for 0, alem de cancelar a repitiçao ele vai escrever no arquivo "fim".
        arquivo << "fim" << endl;
     }
    }
    arquivo.close();        //Para o arquivo fechar

    return 0;
}