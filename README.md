# Lista 03 | Estruturas de Dados II

Implementações em C++20 de algoritmos de ordenação, com foco em comparações, trocas e inversões.

## Conteúdo

| Arquivo | Algoritmo | Objetivo |
| --- | --- | --- |
| `src/ex01-bubbleSorting.cpp` | Bubble Sort | Ordenar o vetor e contar trocas. |
| `src/Exer02_SelectionSort_Min.cpp` | Selection Sort | Exibir os `k` menores elementos. |
| `src/Exer03_InsertionKSorted.cpp` | Insertion Sort | Ordenar e contar comparações. |
| `src/Exer04_BubbleParitySort.cpp` | Insertion Sort | Ordenar e contar comparações. |
| `src/Exer05_InsertionInversions.cpp` | Insertion Sort | Contar inversões do vetor. |
| `main.cpp` | Selection Sort | Exemplo de execução com vetor fixo. |

## Desempenho

Considere `n` como o número de elementos.

| Algoritmo | Melhor caso | Médio | Pior caso | Espaço auxiliar* |
| --- | ---: | ---: | ---: | ---: |
| Bubble Sort | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` |
| Selection Sort | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` |
| Insertion Sort | `O(n)` | `O(n²)` | `O(n²)` | `O(1)` |

- **Bubble Sort:** realiza muitas comparações e trocas, principalmente em vetores invertidos.
- **Selection Sort:** mantém `O(n²)` comparações mesmo em vetores ordenados, mas realiza poucas trocas.
- **Insertion Sort:** é a melhor opção entre os três para vetores pequenos ou quase ordenados.
- **Inversões:** variam de `0` (vetor ordenado) a `n(n - 1) / 2` (ordem decrescente).

\* As funções recebem uma cópia do vetor, que ocupa `O(n)` memória adicional. A ordenação, isoladamente, usa espaço auxiliar constante.

Para grandes volumes de dados, prefira algoritmos `O(n log n)`, como Merge Sort ou Heap Sort.

## Entrada e saída

### Exercícios 3 e 4

Entrada:

```text
n k
elementos do vetor
```

Saída: vetor ordenado e número de comparações. O parâmetro `k` é lido, mas não é utilizado pela implementação atual.

### Exercício 5

Entrada:

```text
n
elementos do vetor
```

Saída: número total de inversões.

Exemplo:

```text
Entrada: 5 4 3 2 1
Saída: 10
```

## Compilação

Com `g++` e C++20:

```bash
g++ -std=c++20 src/ex01-bubbleSorting.cpp -o bubble_sort
g++ -std=c++20 src/Exer02_SelectionSort_Min.cpp -o selection_sort
g++ -std=c++20 src/Exer03_InsertionKSorted.cpp -o insertion_k_sorted
g++ -std=c++20 src/Exer04_BubbleParitySort.cpp -o insertion_sort
g++ -std=c++20 src/Exer05_InsertionInversions.cpp -o inversions
```

Exemplo:

```bash
echo "5 4 3 2 1" | ./inversions
```

Com CMake:

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```

> O `CMakeLists.txt` atual associa dois arquivos com `main` ao alvo `ex01-bubbleSorting`. Se ocorrer erro de múltipla definição de `main`, compile os exercícios individualmente ou configure um executável para cada arquivo.

## Requisitos

- Compilador com suporte a C++20.
- CMake 4.2 ou superior, opcional.
