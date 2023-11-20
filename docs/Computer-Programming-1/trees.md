# Trees

## Introduction

Alcuni esempi di utilizzo sono:

- la descrizione di proprietà dinamiche degli algoritmi
- un organigramma aziendale
- il file system di un sistema operativo

Distinguiamo:

- Alberi generici
- Alberi con radice
- Alberi ordinati
- Alberi M-ari (il numero di nodi figli è massimo M)
- Alberi binari come caso particolare di albero M-ario

Un albero è in realtà un caso particolare di **grafo**, nel quale due vertici sono connessi da uno e un solo cammino; non sono mai ciclici.

I sottoalberi di un nodo N sono detti **sottoalbero sinistro** e **sottoalbero destro** di N.

- nodo radice (non ha padre)
- nodi foglia (non hanno figli)
- nodi intermedi (padre e almeno un figlio)

Una catena di nodi dalla radice a una foglia è detta **ramo**

- il numero di nodi in un ramo è la **lunghezza** del ramo
- la massima lunghezza di un ramo è **l'altezza** dell'albero
- l'altezza di un albero binario di N elementi è $h = \log_{2}(N + 1),$ o $h = N$
- un albero è bilanciato se la sua altezza è $h = \log_{2}(N + 1)$
- un albero è completo se $N = 2^h - 1$

Se un albero è bilanciato minimizziamo la sua lunghezza

## Albero di ricerca binaria

Un albero è detto di ricerca binaria se per ogni nodo $N$ si ha che:

- tutti i nodi del sottoalbero di sinistra precedono strettamente $N$ (hanno valore minore del nodo $N$)
- tutti i nodi del sottoalbero di destra sono preceduti da $N$ (hanno valore maggiore o uguale del nodo $N$)

Su un albero binario possiamo definire le seguenti operazioni:

``init``:

``print``:

``deinit``:

Una possibile definizione in **tree.h**:

```cpp
typedef node* tree;

struct tree {
    char value;
    tree left, right;
};

void init(tree &);
void deinit(tree &);
bool nullp(const tree &);
retval insert(tree&, char);
tree search(const tree &, char);
void print_ordered(const tree&);
```

## Implementazione con array

array v di dim elementi di tipo Trees


- un (sotto) albero è dato da un puntatore a v eun indice in

```cpp
struct tree {
    T *v;
    int i;
}
```

- v allocato dinamicamente
- v[0] è la radice
