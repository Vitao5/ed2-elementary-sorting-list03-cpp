# Lista de Exercícios — Algoritmos de Ordenação

Implementações em C++ dos algoritmos **Bubble Sort**, **Selection Sort** e **Insertion Sort**, cada um adaptado para resolver uma variação específica do problema clássico. Todo o código segue o padrão `class Solution` com o método principal encapsulando a lógica e o `main()` já com uma entrada de exemplo fixa, pronta para compilar e rodar.

---

## Sumário

| # | Arquivo | Algoritmo | Problema |
|---|---------|-----------|----------|
| 1 | `ex01_bubbleSorting.cpp` | Bubble Sort | Ordenar e contar trocas |
| 2 | `Exer02_SelectionSort_Min.cpp` | Selection Sort | k-menores elementos |
| 3 | `Exer03_InsertionKSorted.cpp` | Insertion Sort | Vetor k-ordenado + comparações |
| 4 | `Exer04_BubbleParitySort.cpp` | Bubble Sort (comparador customizado) | Pares crescentes / ímpares decrescentes |
| 5 | `Exer05_InsertionInversions.cpp` | Insertion Sort | Contagem de inversões |

---

## 1. Bubble Sort — Contagem de Trocas

**O que faz:** percorre o vetor repetidamente comparando pares adjacentes. Sempre que um par está fora de ordem, os dois elementos são trocados. O processo se repete até que nenhuma troca seja mais necessária.

```cpp
pair<vector<int>, long long> bubbleSortSwapCount(vector<int> nums);
```

- **Entrada de teste:** `{4, 3, 2, 1, 5}`
- **Saída:** vetor ordenado `1 2 3 4 5` e `6` trocas

**Ideia central:** cada troca corrige exatamente uma inversão adjacente, então o total de trocas é igual ao número de inversões do vetor original.

### Performance

| Caso | Complexidade |
|------|--------------|
| Melhor caso (já ordenado) | `O(N)` — com otimização de parada antecipada |
| Médio | `O(N²)` |
| Pior caso (ordem inversa) | `O(N²)` |
| Espaço | `O(1)` — in-place |

> A implementação aqui **não** usa flag de parada antecipada (`swapped`), então sempre executa as `N-1` passagens completas, mesmo em vetores já ordenados. Para uso real, vale adicionar essa otimização.

---

## 2. Selection Sort — k-Menores Elementos

**O que faz:** em cada iteração do laço externo, busca o menor elemento entre os restantes e o posiciona na posição correta. A questão explora a invariante: após `k` iterações, os `k` menores elementos já estão ordenados nas primeiras posições.

```cpp
vector<int> selectionKSmallest(vector<int> nums, int k);
```

- **Entrada de teste:** `{29, 10, 14, 37, 13, 42}`, `k = 3`
- **Saída:** `10 13 14`

**Ideia central:** como só precisamos dos `k` menores, o algoritmo para assim que completa `k` iterações — não há necessidade de ordenar o vetor inteiro.

### Performance

| Caso | Complexidade |
|------|--------------|
| Todos os casos | `O(N·k)` — quando `k < N`, é mais barato que ordenar tudo |
| Pior caso (`k = N`) | `O(N²)` |
| Espaço | `O(1)` — in-place |
| Trocas | `O(k)` — uma troca por iteração, sempre |

> Selection Sort sempre faz o mesmo número de comparações independente da entrada (não existe melhor caso), o que o torna previsível, mas nunca tão rápido quanto um Bubble Sort em um vetor quase ordenado.

---

## 3. Insertion Sort — Vetor k-Ordenado

**O que faz:** insere cada elemento na posição correta dentro da parte já ordenada do vetor, deslocando os maiores para a direita. A questão conta quantas comparações o laço `while` realiza.

```cpp
pair<vector<int>, long long> insertionSortKSorted(vector<int> nums);
```

- **Entrada de teste:** `{3, 2, 1, 5, 4, 6}`
- **Saída:** vetor ordenado `1 2 3 4 5 6` e `7` comparações

**Ideia central:** quando o vetor é k-ordenado (cada elemento está a no máximo `k` posições de seu lugar final), o laço interno nunca precisa recuar mais que `k` posições — daí a complexidade cair de `O(N²)` para `O(N·k)`.

### Performance

| Caso | Complexidade |
|------|--------------|
| Melhor caso (já ordenado) | `O(N)` |
| Vetor k-ordenado | `O(N·k)` |
| Pior caso (ordem inversa) | `O(N²)` |
| Espaço | `O(1)` — in-place |

> É por isso que Insertion Sort é a escolha natural para dados "quase ordenados" — logs cronológicos, resultados de merges parciais, etc.

---

## 4. Bubble Sort — Critério de Paridade

**O que faz:** mesmo esqueleto do Bubble Sort, mas com um **comparador customizado** (`deveTrocar`) em vez do simples `>`. A regra: pares vêm antes de ímpares; pares em ordem crescente; ímpares em ordem decrescente.

```cpp
bool deveTrocar(int a, int b);
vector<int> bubbleParitySort(vector<int> nums);
```

- **Entrada de teste:** `{5, 2, 9, 8, 1, 6, 3, 4}`
- **Saída:** `2 4 6 8 9 5 3 1`

**Ideia central:** Bubble Sort é um algoritmo genérico de ordenação por comparação — basta trocar a regra de "quem vem primeiro" para ordenar sob qualquer critério, mesmo um critério composto como esse.

### Performance

| Caso | Complexidade |
|------|--------------|
| Todos os casos | `O(N²)` |
| Espaço | `O(1)` — in-place |

> Trocar o comparador não muda a complexidade do algoritmo base — o custo de decidir "quem vem primeiro" continua `O(1)` por comparação.

---

## 5. Insertion Sort — Contagem de Inversões

**O que faz:** simula o Insertion Sort e conta quantos deslocamentos (`shifts`) para a direita são necessários. Esse número é exatamente igual à quantidade de inversões do vetor.

```cpp
long long insertionInversions(vector<int> nums);
```

- **Entrada de teste:** `{2, 4, 1, 3, 5}`
- **Saída:** `3`

**Ideia central:** uma inversão é um par `(i, j)` com `i < j` e `A[i] > A[j]`. Cada deslocamento do Insertion Sort resolve exatamente uma inversão, então contar os deslocamentos é contar as inversões.

### Performance

| Caso | Complexidade |
|------|--------------|
| Melhor caso (já ordenado, 0 inversões) | `O(N)` |
| Médio | `O(N²)` |
| Pior caso (ordem decrescente, `N(N-1)/2` inversões) | `O(N²)` |
| Espaço | `O(1)` — in-place |

> Para contar inversões em vetores grandes (`N` alto), essa abordagem `O(N²)` fica cara. A alternativa eficiente é usar **Merge Sort modificado**, que resolve o mesmo problema em `O(N log N)`.

---

## Visão Geral de Performance

| Algoritmo | Melhor Caso | Médio | Pior Caso | Espaço | Estável? | In-place? |
|-----------|:---:|:---:|:---:|:---:|:---:|:---:|
| Bubble Sort | `O(N)`* | `O(N²)` | `O(N²)` | `O(1)` | Sim | Sim |
| Selection Sort | `O(N²)` | `O(N²)` | `O(N²)` | `O(1)` | Não | Sim |
| Insertion Sort | `O(N)` | `O(N²)` | `O(N²)` | `O(1)` | Sim | Sim |

\* *só com otimização de parada antecipada (flag `swapped`), ausente nas implementações acima.*

**Pontos-chave:**

- **Selection Sort** é o único que **não se beneficia** de dados parcialmente ordenados — ele sempre faz `O(N²)` comparações, não importa a entrada. Em compensação, faz o **menor número de trocas** (`O(N)` no total), o que é vantajoso quando o custo de "escrever" é caro (ex.: memória flash).
- **Insertion Sort** é o melhor dos três para dados **quase ordenados** — degrada suavemente conforme a desordem aumenta (`O(N·k)`), e é o algoritmo de escolha para ordenar pequenos vetores ou como parte final de algoritmos híbridos (ex.: Timsort usa Insertion Sort para sublistas pequenas).
- **Bubble Sort**, apesar de didático, raramente é usado em produção — mesmo com a otimização de parada antecipada, seu desempenho prático fica atrás do Insertion Sort na maioria dos casos.
- Todos os três são `O(N²)` no pior caso e por isso **inadequados para N muito grande** (a partir de dezenas de milhares de elementos). Para esses casos, algoritmos `O(N log N)` como **Merge Sort**, **Quick Sort** ou **Heap Sort** são a escolha correta.

---

## Como compilar e rodar

Cada arquivo já contém uma entrada de exemplo fixa no `main()`, então basta compilar e executar:

```bash
g++ -O2 -o exercicio arquivo.cpp
./exercicio
```
