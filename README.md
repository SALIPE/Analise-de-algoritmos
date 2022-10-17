# Analise de algoritmos
 Códigos e soluções de problemas para análise de algortimos

 # Para execução:

    - Compilar biblioteca:
        $ gcc -c commons.c -o commons.o
        $ ar rc libcommons.a commons.o

    - Compilar codigos com a bilbioteca
        $ gcc sortfile.c -o sortfile -L. -lcommons
    - Para rodar o codigo
        $ ./sortfile