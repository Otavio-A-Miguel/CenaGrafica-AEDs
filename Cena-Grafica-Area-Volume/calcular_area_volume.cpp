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
#include <cmath> 

using namespace std;
//costantes
const double PI = 3.14;
const double RAIZ3 = 1.73;
const double RAIZ2 = 1.41;

int main() {

    ifstream arquivo("cenagrafica.txt");
    string figura;

    if (!arquivo.is_open()) {
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    double soma_areas = 0;
    double soma_volumes = 0;

    arquivo >> figura;

    while (figura != "fim"){
//Area de figuras 2D
        if (figura == "circulo") {      // Area do circulo
            double raio;
            arquivo >> raio;
            double area = PI * raio * raio;
            cout << "AREA DO CIRCULO:" << area << endl;
            soma_areas += area;
        } 
        else if (figura == "triangulo") {       //Confirmaçao se o triangulo e possivel
            double lado1,lado2,lado3;
            arquivo >> lado1 >> lado2 >> lado3;

            if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
            double s = (lado1 + lado2 + lado3) / 2;
            double raiz = s * (s-lado1) * (s - lado2) * (s - lado3);
            double area = sqrt(raiz);       //Area do triangulo (atraves da formula de Heron)

            if (lado1 == lado2 && lado2 == lado3) {     //Verificaçao de que tipo e o triangulo
            //cout << "AREA DO TRIANGULO EQUILATERO::" << area << endl;
                printf("AREA DO TRIANGULO EQUILATERO:%.2f\n", area);
                soma_areas += area;

            } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3){
            //cout << "AREA DO TRIANGULO ISOSCELES:" << area << endl;
                printf ("AREA DO TRIANGULO ISOSCELES:%.2f\n", area);
                soma_areas += area;
            } else if (lado1 != lado2 && lado2 != lado3 && lado1 != lado3 ){
            //cout << "AREA DO TRIANGULO ESCALENO:" << area << endl;
                printf ("AREA DO TRIANGULO ESCALENO:%.2f\n", area);
                soma_areas += area;
            } 
        }
    } else if (figura == "quadrado") {      //Area do quadrado
            double lado;
            arquivo >> lado;
            double area = lado * lado;
            cout << "AREA DO QUADRADO:" << area << endl;
            soma_areas += area;
        } else if (figura == "retangulo" ) {        //Area do retangulo
            double lado1, lado2;
            arquivo >> lado1 >> lado2;
            if ( lado1 != lado2) {      //Verificaçao se e um retangulo verdadeiro
            double area = lado1 * lado2;
            cout << "AREA DO RETANGULO:" << area << endl;
            soma_areas += area;
            } 
        } else if (figura == "losangulo") {     //Area do losangulo
            double dmaior, dmenor;
            arquivo >> dmaior >> dmenor;
            double area = (dmaior * dmenor) / 2;
            cout << "AREA DO LOSANGULO:" << area << endl; 
            soma_areas += area;
        } else if (figura == "trapezio") {      //Area do trapezio
            double bmaior, bmenor, altura;
            arquivo >> bmaior >> bmenor >> altura;
            double area = ((bmaior + bmenor) * altura ) / 2;
            cout << "AREA DO TRAPEZIO:" << area << endl;
            soma_areas += area;
        } else if (figura == "paralelograma") {     //Area do paralelograma
            double altura,base;
            arquivo >> altura >> base;
            double area = base * altura;
            cout << "AREA DO PARALELOGRAMA:" << area << endl;
            soma_areas += area;
        } else if (figura == "pentagono") {     //Area de pentagono
            double altura;
            arquivo >> altura;
            double area = 5 * altura;
            cout << "AREA DO PENTAGONO:" << area << endl;
            soma_areas += area;
        } else if ( figura == "hexagono") {     //Area do hexagono
            double complado;
            arquivo >> complado;
            double area = ((6 * (complado * complado)) * RAIZ3) / 4;
        //cout << "AREA DO HEXAGONO:%.2f" << area << endl;
        printf("AREA DO HEXAGONO: %.2f\n", area);
            soma_areas += area;
        } else if ( figura == "heptagono") {        //Area do heptagono
            double altura, complado;
            arquivo >> altura >> complado;
            double area = (7 *complado * altura) / 2;
        //cout << "AREA DO HEPTAGONO:" << area << endl;
            printf ("AREA DO HEPTAGONO: %.2f\n", area);
            soma_areas += area;
        } else if ( figura == "octagono"){     //Area do octagono
            double altura,complado;
            arquivo >> altura >> complado;
            double area = (8 * altura * complado) / 2;
            cout << "AREA DO OCTAGONO:" << area << endl;
            soma_areas += area;
        }
//volume de figuras 3D
        else if (figura == "cubo") {        //Volume do cubo
            double lado;
            arquivo >> lado;
            double volume = (lado*lado*lado);
        cout << "VOLUME DO CUBO:" << volume << endl;
            soma_volumes += volume;
        } else if (figura == "cilindro") {      //volume do cilindro
            double altura, raio;
            arquivo >> altura >> raio;
            double volume = PI * (raio * raio) * altura;
        //cout << "VOLUME DO CILINDRO:" << volume << endl;
            printf ("VOLUME DO CILINDRO: %.2f\n", volume);
            soma_volumes += volume;
        } else if (figura == "esfera") {        //Volume da esfera
            double raio;
            arquivo >> raio;
            double volume = (4 * (PI * raio * raio *raio)) / 3;
        //cout << "VOLUME DA ESFERA:" << volume << endl;
            printf ("VOLUME DA ESFERA: %.2f\n", volume);
            soma_volumes += volume;
        } else if (figura == "cone") {      //Volume do cone
            double raio, altura;
            arquivo >> raio >> altura;
            double volume = (PI * (raio * raio) * altura) / 3;
        //cout << "VOLUME DO CONE:" << volume << endl;
            printf ("VOLUME DO CONE: %.2f\n", volume);
            soma_volumes += volume;
        } else if (figura == "piramide") {      //Volume da piramide
            double base, altura;
            arquivo >> base >> altura;
            double areabase = base * base;
            double volume = (areabase * altura) / 3;
        //cout << "VOLUME DA PIRAMIDE:" << volume << endl;
            printf ("VOLUME DA PIRAMIDE: %.2f\n", volume);
            soma_volumes += volume;
        } else if (figura == "paralelepipedo") {        //Volume do paralelepipedo
            double altura,comprimento,largura;
            arquivo >> altura >> comprimento >> largura;
            double volume = (largura * altura * comprimento);
            cout << "VOLUME DO PARALELEPIPEDO:" << volume << endl;
            soma_volumes += volume;
        } else if (figura == "tetraedo") {      //Volume do tetraedo
            double lado;
            arquivo >> lado;
            double volume = ((lado * lado * lado ) * RAIZ2)/12;
        //cout << "VOLUME DO TETRAEDO:" << volume << endl;
            printf ("VOLUME DO TETRAEDO: %.2f\n", volume);
            soma_volumes += volume;
        }

        arquivo >> figura;
    }

    //cout << "SOMA TOTAL DAS AREAS:" << soma_areas << endl;
    //cout << "SOMA TOTAL DOS VOLUMES:" << soma_volumes << endl;
        printf("\nSOMA TOTAL DAS AREAS: %.2f\n", soma_areas);       //Soma das Areas utilizados
        printf("SOMA TOTAL DOS VOLUMES: %.2f\n", soma_volumes);     //Soma dos Volumes utilizados

        arquivo.close();        //Para o arquivo fechar

    return 0;
}