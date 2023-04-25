# Tarefa 01 - Breaking Cryptography

Usando o seguinte código abaixo, referente ao programa chamado _histograma_, é possível descobrir a chave dos arquivos `3CWp9sI1` e `SgTAPSra` além da frequência dos caracteres.

```C
#include <stdio.h>
#include <stdlib.h>

#define SIZE 256
#define USAGE                                                           \
    "Prints the amount of occurrencies of each byte on a given file.\n" \
    "The result is printed to standard output.\n\n"                     \
    "%s <min> <file>\n"                                                 \
    "  <min>  - Minimum amount of occurrencies.\n"                      \
    "  <file> - File to read.\n"S

int main(int argc, char **argv)
{
    unsigned int i, h[SIZE];
    unsigned char c;
    FILE *f;
    int k;

    if (argc == 3)
    {
        k = atoi(argv[1]);

        for (i = 0; i < SIZE; i++)
            h[i] = 0;

        f = fopen(argv[2], "r");

        if (f)
        {
            while (fread(&c, 1, 1, f))
                h[c] += 1;
        }

        for (i = 0; i < SIZE; i++)
            if (h[i] >= k)
                printf("%.2x %d\n", i, h[i]);
    }
    else
        printf(USAGE, argv[0]);

    return 0;
}C

```

## 3CWp9sI1

Usando o código acima, é possível compilar usando gcc através do seguinte comando:

```
gcc src/histogram.c -o src/histogram
```

Execute o histograma, informando o tamanho e o arquivo a ser usado:

```
./src/histogram 1 encrypted_files/3CWp9sI1
```

Como resultado, teremos a seguinte saída como resultado:

```
...
5d 339
73 3097
75 16
7a 13
7b 24
...
```

Obsevando a linha 73 (hexadecimal), ou 115 (decimal), pode-se notar que é o que se repete mais vezes, sendo 3097 ocorrências. Logo, pode-se dizer que a chave usada para o arquivo `3CWP9sI1` é `115`.

Usando essa chave para decifrar o arquivo como `caesar`, obtemos o arquivo decrypted_files/3CWp9sl1_Decrypted. Sendo uma cópia do **GNU General Public License**
