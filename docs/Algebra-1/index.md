# Abstract Algebra 1

This page is an index page of the related course _Abstract Algebra_.

## Insiemi e relazioni

- $\cup, \; \cap, \; \setminus, \; \Delta$
- $\cap$ e $\cup$ associativi
- come dimostrare $X = Y$
- prodotto cartesiano 
- insieme delle parti
- complementare, leggi di de Morgan, tabella di verità
- identità notevoli unione, intersezione, differenza simmetrica
- $\emptyset$ neutro di $\Delta$, $X$ neutro di $\cap$
- partizione
- relazioni, relazione bianria, proprietà **R, S, A, T**
- relazione di equivalenza, clasi di equivalenza 
- $x \rho \, y \implies [x] = [y]$
- le classi di equivalenza di $X$ rispetto $\rho$ sono partizione di $X$
- una partizione definisce una relazione di equivalenza
- insieme quoziente, rappresentanti

## Funzioni

- immagine
- singoletto
- controimmagine
- fibra
- $f \textit{ iniettiva} \iff f^*(b) = \emptyset \textit{ o contiene solo un elemento } \forall b$
- $f \textit{ suriettiva} \iff f_*(A) = B$
- $f_\rho \rightarrow a \rho b \iff f(a) = f(b)$
- proiezione canonica, $\pi_\rho$ sempre suriettiva
- $$\pi_\rho^*([y]) = [y] \subset A$$
- composizione, associatività composizione
- $f, g \textit{ suriettive} \implies g \circ f \textit{ suriettiva}$
- $f, g \textit{ iniettive} \implies g \circ f \textit{ iniettive}$
- $g \circ f \textit{ suriettiva} \implies g \textit{ suriettiva}$
- $g \circ f \textit{ iniettiva} \implies f \textit{ iniettiva}$
- identità su insieme $X$, elemento neutro della composizione
- inversa sinistra, destra
- $f \textit{ suriettiva} \iff \textit{f ha inversa dx iniettiva}$
- $f \textit{ iniettiva} \iff \textit{f ha inversa sx suriettiva}$
- $f \textit{ !suriettiva} \implies \nexists \textit{ inversa dx} \textit{ e } sx \textit{ non univoca}$ 
- $f \textit{ !iniettiva} \implies \nexists \textit{ inversa sx} \textit{ e } dx \textit{ non univioca}$
- $f \textit{ biunivoca} \iff f \textit{ ammette inversa (unica)}$

## Cardinalità

- insieme potenza $Y^X$
- $\underline{n} = \{0,1,\dots,n-1\}$
- cardinalità insiemi finiti
- $\exists \textit{ biezione tra } X \textit{ e } Y \implies |X| = |Y|$ 
- $\exists$ biezione tra $\mathcal{P}(X)$ e $\underline{2}^X$
- funzione caratteristica $\chi_A$
- essere in biezione con $\implies$ relazione di equivalenza
- $X, Y \textit{ insiemi finiti, } |X| \leq |Y| \iff \exists X \hookrightarrow Y$
- $X, Y \textit{ insiemi finiti, } \exists X \hookrightarrow Y \textit{, } |X| = |Y| \implies biezione$
- $X, Y \textit{ insiemi finiti, } \exists Y \twoheadrightarrow X \textit{, } |X| = |Y| \implies biezione$
- $X \; infinito, \exists X \hookrightarrow Y \nRightarrow |X| \leq |Y|$ 
- $\forall X \; \exists \textit{ funzione iniettiva } X \hookrightarrow \mathcal{P}(X)$
- $\nexists X \twoheadrightarrow \mathcal{P}(X)$
- insieme infinito
- sono equivalenti: $X \; infinito; \; \exists \varphi : \mathbb{N} \hookrightarrow X; \; \exists \psi : X \hookrightarrow X$
- $\leq$ per la cardinalità è $R, A, T \implies$ relazione di ordine (totale)
- insieme numerabile
- $|X| = \aleph_0, \; |Y| = \aleph_0 \implies |X \times Y| = \aleph_0$
- $|X| = \aleph_0, \; F \subseteq X, \; |X| <\infty \implies |X \; \setminus Y| = \aleph_0$
- $$\{A_i\}_{i \in I}, \; |A_i| = \aleph_0, \; 0 < |I| \leq \aleph_0 \implies \lvert \bigcup\limits_{i \in I} \rvert = \aleph_0$$
- $\mathcal{P}(\mathbb{N})$ non numerabile, con cardianalità del continuo
- $|X| = \aleph_0 \implies \mathcal{P}(X)$ ha cardinalità del continuo
- $\mathbb{R}$ ha cardinalità del continuo

## Combinatoria

- $|X| = m, \; |Y| = n \implies |X^t| = m^t, \; |X^Y| = m^n$
- si hanno $\frac{m!}{(m-n)!}$ funzioni iniettive da $X$ a $Y$
- $\binom{m}{n}$ è il numero di sottoinsiemi con $n$ elementi di $X$, $|X| = m$
- $\binom{m + 1}{n} = \binom{m}{n} + \binom{m}{n - 1}$

## Divisibilità negli interi

- $U(\mathbb{Z}) = \{1,-1\}$
- associati
- $x | y \iff xz = y, \; z \in \mathbb{Z}$
- per | vale $R, T$
- $x | y \textit{ e } y | x \iff \textit{x, y associati}$ 
- numeri primi $\mathbb{P}$
- $\mathbb{P}$ è numerabile
- algoritmo di eratostene (e perché si ferma a $\sqrt{n}$)
- massimo comune divisore, minimo comune multiplo
- $d1, d2$ MCD di $a, b \iff$ $d1, d2$ associati $\implies$ MCD è unico
- $\text{MCD}(a,b) = d \iff -d = \text{MCD}(a,b)$
- $d|a \textit{ e } d|b \implies d | \alpha a + \beta b$
- $a|b \textit{ e } c|d \implies ac | bd$
- $d = \alpha a + \beta b, \; d|a, \; d|b \implies d = \text{MCD}(a,b)$
- $d = \text{MCD}(a,b), \; a = a'd, \; b = b'd \implies \text{MCD}(a',b') = 1$
- teorema divisione con resto
- algoritmo di euclide
- identità di bezout
- algoritmo di euclide esteso
- $\rho$ compatibile con * 

## Anelli

- definizione di anello
- $R_1, \dots R_s \textit{ anelli} \implies R_1 \times \dots R_s \textit{ anello }$
- $R \textit{ anello} \implies R^X \textit{ anello}$
- $D(R) = \{r \in R \mid \exists s \in R^* \text{ t.c. } rs = 0\}$ 
- $U(R) = \{r \in R \mid \exists b \in R \text{ t.c. } ab = ba = 1\}$
- $U(R) = R^* \textit{, R commutativo} \implies R \textit{ campo}$
- $R \textit{ anello} \implies U(R) \cap D(R) = \emptyset$
- $R \textit{ campo} \implies U(R) = R^* \implies D(R) = {0} \implies R \textit{ dominio}$
- $R \textit{ anello, } \rho \textit{ compatibile con } +, \cdot \implies (R/\rho, \oplus, \otimes) \textit{ anello}$

## Aritmetica modulare

- congruenza modulo $n$
- $a \equiv b \text{ mod } n \iff n \mid a - b$
- la relazione $\equiv_n$ è di equivalenza
- classi resto modulo n
- $\mathbb{Z}/{n\mathbb{Z}} \textit{ anello commutativo } \forall n \geq 2$
- rappresentanti canonici
- $\overline{a} \in U(\mathbb{Z}/n\mathbb{Z}) \iff (a, n) = 1$
- $\overline{a}^{-1} = \{b \in \mathbb{Z} \mid 1 = ab - kn \}$
- per calcolare $\overline{a}$ è sufficiente usare Euclide Esteso
- $ac \equiv_n bc, \; (c, n) = 1 \implies a \equiv_n b$
- $a \equiv_n b, \; d \mid n \implies a \equiv_d b$
- $a \equiv_n b, \; a \equiv_m b, \; (m, n) = 1 \implies a \equiv_{mn} b$
- equazioni congruenziali lineari
- $ax \equiv_n b \iff (a + ln)x \equiv_n (b + mn)$
- $(a, n) = d > 1 \implies ax \equiv_n b \iff a'x \equiv b' \text{ mod } n' = \frac{n}{d}$
- $ax \equiv_n b \iff (a, n) \mid b$
- $x_o \in \mathbb{Z} \textit{ soluzione di } ax \equiv_n b \implies x = \{x_o + \frac{n}{(a, n)}k \mid k \in \mathbb{Z} \}$
- $(a, n) = 1 \implies x = (\overline{a}^{-1})\overline{b} \textit{ unica soluzione}$
- sistemi di congruenze
- teorema cinese dei resti
- corollario teorema cinese dei resti

## Gruppi

- definizione
- $1_G$ unico, legge di cancellazione, $gh = 1_G \implies hg = 1_G$, $(gh)^{-1} = h^{-1}g^{-1}$, $g^wh^z = h^zg^w$ se g e h commutano
- $\mathbb{S} := \{f : X \rightarrow X \text{ biezione}\}$ gruppo delle permutazioni di $X$
- $C_G(g) = \{h \in G \mid gh = hg\}$ sottogruppo centralizzante di $g$
- $$Z(G) = \bigcap\limits_{g \in G} C_G(g) = \{h \in G \mid hg = gh \; \forall g \in G \} $$ 
- $H, K \leq G \implies H \cap K \leq G$
- $H \leq G \iff \forall h, g \in H \implies h^{-1}g \in H$
- $H, K \leq G \nRightarrow H \cup K \leq G$
- il sottogruppo generato da $S$ è il minimo sottogruppo che contiene $S$
- $$\langle S \rangle = \bigcap\limits_{S \subseteq H \leq G}{H} = \{g_{i_1}^{a_{i_1}} \dots g_{i_r}^{a_{i_r}}, \; g_{i_j} \in S, \; a_{i_j} \in \mathbb{Z} \}$$
- $H = \langle h \rangle \implies H \textit{ ciclico}$
- $h^n = 1_G, \; n \textit{ minimo} \implies |h| = n$
- $\langle h \rangle \; ciclico \implies |\langle h \rangle| = |h| = n$
- $|h| = \infty \implies \langle h \rangle = \{h^a, \; a \in \mathbb{Z}\}$
- $f(gg') = f(g)f(g') \implies f \textit{ omomorfismo tra gruppi}$
- $$|g| = n \implies |g^m| = \frac{n}{(m, n)}$$
- $|g^m| = n \iff (m, n) = 1 \iff \langle g \rangle = \langle g^m \rangle$
- $G = \langle g \rangle, \; H \leq G \implies \exists m \in \mathbb{Z}_{\geq 0} \text{ t.c. } H = \langle g^m \rangle$
- $$G = \langle g \rangle, \; |g| = n \implies \forall d \mid n \; \exists! \; H = \langle g ^{\frac{n}{d}} \rangle \leq G$$

### Permutazioni

- $\sigma \in \mathbb{S}_n \textit{ ciclico} \implies \sigma = (a_1 \dots a_k)$
- $|(a_1, \dots a_k)| = k$
- $\{j \in \{1, \dots n\} \mid \sigma(j) \neq j\} \cap \{i \in \{1, \dots n\} \mid \tau(i) \neq i\} = \emptyset \iff \sigma \tau = \tau \sigma$
- ogni permutazione si può scrivere come prodotto di cicli **disgiunti** che commutano
- $\sigma^{-1} = c^{-1}_r \dots c^{-1}_1$
- $\sigma = c_1 \dots c_r \implies |\sigma| = mcm(c_1 \dots c_r)$ 
- $\rho, \; \sigma \textit{ coniugati tramite } \tau \implies \rho = (\tau(a_1) \dots \tau(a_n))$
- traslazioni
- segno di una permutazione
- gruppo alterno $\mathbb{A}_n$
- classi laterali
- teorema di lagrange
