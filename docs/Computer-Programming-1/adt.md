# Foundamental Data Types

## Abstract Data Type (ADT)

- dati immagazzinati, operazioni supportate, condizioni di errore
- insieme di valori e di operazioni definite in modo indipendente dalla loro implementazione
- piu' implementazioni possibili, ma stessa interfaccia (header)
- possiamo creare una libreria con due implementazioni, e in fase di linking decidere quale usare
- information hiding: solo i file .h e .o disponibili
- quando possibile è bene (se modifichiamo qualcosa) avere funzioni implementate nello stesso modo in diverse versioni
- possiamo avere implementazioni diverse a seconda delle compilation flags

```cpp
#define NOT_USE_ARRAY 0;

typedef struct Point_ Point;

struct Point_ {
#if NOT_USE_ARRAY
	// prima implementazione
	double x;
	double y;
#else
	double coord[2];
#endif
};
```

nell'implementazione dovrò rispettare questo dualismo.

## Stack

- collezione di dati omogenei
- i dati sono gestiti in modo LIFO (Last In First Out)
- viene visualizzato/estratto l'elemento inserito piu' recentemente
- operazioni:
    - `init()/deinit()`
  	- `push(T)` inserisce un elemento, fallisce se stack pieno
  	- `pop()` rimuove l'ultimo elemento, fallisce se stack vuoto
  	- `top(T&)` ritorna l'ultimo elemento estratto, fallisce se stack vuoto
 	- `pop(T&)`: pop e top fuse in'unica operazione
- in tutte le possibili implementazioni le operazioni devono essere atomiche (efficienti). Numero costante di passi computazionali, indipendente dal numero di elementi

Implementazione con Array:
- memorizziamo l'indice h del prossimo elemento da inserire
- stack vuoto: `h = 0`
- stack pieno: `h = size`
- `init()` pone `h = 0`
- `push(T)` inserisce l'elemento in `v[h],` `h++`
- `top(T&)` restituisce `v[h-1]`
- `pop()` decrementa `h`
- `deinit()` dealloca `v` se allocato dinamicamente

```cpp
enum retval { FAIL, OK };

struct Stack {
	int index;
	int size;
	int* el;
};
```

```cpp
// osservazione: è uguale a quando in python passiamo self
void init(Stack&, const int);
void deinit(Stack&);
retval push(Stack&, int&);
retval top(const Stack&, int&);
retval pop(Stack&);
```

nell'implementazione possiamo inizializzare delle funzioni static che controllano la buon riuscita delle operazioni:

```cpp
static void stackIsFull();
static void stackIsEmpty();
```

nel main:

```cpp
#include "stack.h"
```
