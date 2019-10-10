# Flattening on C++

## Authors/Autores:  
[Caio - 2017068734](https://github.com/caiocaldeira3) 

## Description/Descrição:

This project has the objective of simulating the flattening algorithm proposed by Michael K. Reiter, Asad Samar and Chenxi Wang using C++.
Este projeto tem como objetivo simular o algoritmo Flattening proposto por Michael K. Reiter, Asad Samar e Chenxi Wang usando C++

## How to build and execute this project/Como compilar e executar esse projeto:
### Dependencies/Dependências de projeto:
* Compilador `g++` || to plot the results/para plotar os resultados `python3 plotly networkx`
### Build project/Compilar projeto:
`make main`
### Run project/Rodar o projeto:
`make run`
### Plot the results, after running it/ Plotar os resultados depois de rodar:
`make plot ARGS=""`

    Inside ARGS you can specify the range of the results you want to plot.
    Dentro de ARGS você pode especificar qual o intervalo dos resultados que você quer plotar.
    
    ARGS="x y"
    Giving it two numbers (x, y) the program will plot all results between x and y, not inclusive.
    Enviando dois números (x, y) como parâmetro o programa plotará todos os resultados entre x e y, não inclusivamente.
    
    ARGS="x"
    Giving it one number (x) the program will plot all results between 0 and x, not inclusive.
    Enviando um número (x) como parâmetro o programa plotará todos os resultados entre 0 e x, não inclusivamente.
    
    Leaving it blank the program will plot all results.
    Não apresentar nenhum parâmetro fará com que o programa plote todos os resultados.
    
    
### Clean binaries/Limpar arquivos binários (.exe, .out, .o):
`make clean`
