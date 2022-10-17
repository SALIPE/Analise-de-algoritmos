# Analise de algoritmos
 Códigos e soluções de problemas para análise de algortimos

 # Para execução:
 1. Compilar biblioteca:

        $ gcc -c commons.c -o commons.o
        $ ar rc libcommons.a commons.o
       
 2. Compilar codigos com a bilbioteca
   
        $ gcc sortfile.c -o sortfile -L. -lcommons
       
 3. Para rodar o codigo

        $ ./sortfile
