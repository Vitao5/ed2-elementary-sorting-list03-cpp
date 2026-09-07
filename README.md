# Lista 03 - Estruturas de Dados II

Este projeto reúne exercícios de algoritmos de ordenação implementados em C++20. O objetivo da lista é praticar diferentes estratégias de ordenação e observar como o número de comparações, trocas e inversões influencia o desempenho.

## Estrutura do projeto

- `main.cpp`: exemplo de Selection Sort que ordena um vetor e mostra os menores elementos.
- `src/ex01-bubbleSorting.cpp`: Bubble Sort com contagem de trocas.
- `src/Exer02_SelectionSort_Min.cpp`: Selection Sort para obter os `k` menores elementos após a ordenação.
- `src/Exer03_InsertionKSorted.cpp`: Insertion Sort com contagem de comparações.
- `src/Exer04_BubbleParitySort.cpp`: programa de ordenação baseado em inserção que lê um vetor e exibe o resultado ordenado e a quantidade de comparações.
- `src/Exer05_InsertionInversions.cpp`: Insertion Sort que conta as inversões do vetor.
- `CMakeLists.txt`: configuração dos executáveis do projeto.

## Exercícios

### Exercício 1 - Bubble Sort

O algoritmo percorre o vetor várias vezes. Elementos maiores são empurrados para o final por meio de trocas entre posições vizinhas. O programa imprime a quantidade de trocas e o vetor ordenado.

Exemplo de saída para a entrada definida no código:

```text
1
1 3 4 5
```

### Exercício 2 - Selection Sort dos menores elementos

Em cada posição, o algoritmo procura o menor elemento restante e troca-o com o elemento daquela posição. Depois de ordenar o vetor, são exibidos os `k` primeiros valores, que correspondem aos `k` menores elementos.

O `main.cpp` usa o vetor `{8, 5, 3, 9, 1}` e imprime os três menores valores:

```text
1 3 5
```

### Exercício 3 - Insertion Sort em vetor quase ordenado

O Insertion Sort considera que a parte esquerda do vetor já está ordenada e insere cada novo elemento na posição correta. O programa lê:

```text
n k
elementos do vetor
```

O valor `k` é lido conforme o formato do exercício, mas a implementação atual não o utiliza para limitar a ordenação. Ao final, são impressos o vetor ordenado e a quantidade de comparações realizadas.

### Exercício 4 - Ordenação por inserção

O programa lê `n` e, em seguida, os `n` elementos do vetor. A ordenação é feita deslocando elementos maiores que a chave para a direita. A saída contém o vetor ordenado e o número de comparações executadas.

Formato da entrada:

```text
n
elementos do vetor
```

### Exercício 5 - Contagem de inversões

Uma inversão é um par de posições `i < j` tal que `vetor[i] > vetor[j]`. Durante o Insertion Sort, cada deslocamento de um elemento maior representa uma inversão. O programa imprime a quantidade total de inversões.

Exemplo:

```text
Entrada:  5 4 3 2 1
Saída:    10
```

## Análise de desempenho

Considere `n` como a quantidade de elementos do vetor.

| Algoritmo | Melhor caso | Caso médio | Pior caso | Memória extra |
| --- | ---: | ---: | ---: | ---: |
| Bubble Sort | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` além da cópia |
| Selection Sort | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` além da cópia |
| Insertion Sort | `O(n)` | `O(n²)` | `O(n²)` | `O(1)` além da cópia |

### Interpretação

- **Bubble Sort** faz muitas comparações e pode fazer muitas trocas. No pior caso, um vetor em ordem decrescente exige aproximadamente `n² / 2` trocas.
- **Selection Sort** sempre procura o menor elemento no trecho restante. Por isso, mesmo quando o vetor já está ordenado, continua realizando aproximadamente `n² / 2` comparações. Sua vantagem é fazer poucas trocas.
- **Insertion Sort** é eficiente para vetores pequenos ou quase ordenados. No melhor caso, quando o vetor já está ordenado, realiza aproximadamente `n - 1` comparações e nenhum deslocamento relevante.
- **Contagem de inversões**: no Insertion Sort, o número de deslocamentos é exatamente o número de inversões do vetor. Esse valor varia de `0`, para um vetor ordenado, até `n(n - 1) / 2`, para um vetor em ordem decrescente.
- Como os vetores são copiados para `vector<int>`, cada função também usa `O(n)` memória para essa cópia, embora o algoritmo de ordenação em si use espaço auxiliar constante.

Para entradas grandes, esses algoritmos podem ficar lentos porque possuem complexidade quadrática. Algoritmos como Merge Sort e Heap Sort oferecem `O(n log n)` no caso médio ou no pior caso e são mais adequados quando `n` é grande.

## Compilação e execução

### Compilação direta com `g++`

Na raiz do projeto, usando um compilador com suporte a C++20:

```bash
g++ -std=c++20 src/ex01-bubbleSorting.cpp -o bubble_sort
g++ -std=c++20 src/Exer02_SelectionSort_Min.cpp -o selection_sort
g++ -std=c++20 src/Exer03_InsertionKSorted.cpp -o insertion_k_sorted
g++ -std=c++20 src/Exer04_BubbleParitySort.cpp -o bubble_parity_sort
g++ -std=c++20 src/Exer05_InsertionInversions.cpp -o insertion_inversions
g++ -std=c++20 main.cpp -o main_app
```

Exemplo para o exercício de inversões:

```bash
echo "5 4 3 2 1" | ./insertion_inversions
```

No Windows, os executáveis normalmente recebem a extensão `.exe`.

### CMake

O projeto também possui configuração para CMake. No CLion, a configuração pode ser carregada diretamente pelo arquivo `CMakeLists.txt`. Atualmente, os alvos configurados são `ex01-bubbleSorting`, `Exer02_SelectionSort_Min` e `main_app`.

Para compilar pela linha de comando:

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```

> Observação: o alvo `ex01-bubbleSorting` inclui atualmente os arquivos de Bubble Sort e Insertion Sort no `CMakeLists.txt`, embora ambos possuam `main`. Se o build apresentar erro de múltiplas definições de `main`, compile os exercícios individualmente ou ajuste os alvos do CMake para que cada arquivo com `main` tenha seu próprio executável.

## Requisitos

- CMake 4.2 ou superior, caso use CMake.
- Compilador compatível com C++20.
- `g++`, MinGW, GCC, Clang ou ferramenta equivalente.
