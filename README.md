# Riscaldamento rotto (stanze)

<img style="float: right;" src="https://s2.qwant.com/thumbr/0x380/f/8/7e59fd004cc3c2d980cc51a3eac4fdeb84c3e34affdcd8eb36c3b6f795c6bf/7da7f02b-219d-4917-99c6-be3bb3b6ec0b.jpg?u=https%3A%2F%2Fs3-eu-west-1.amazonaws.com%2Fstatic-sr.s3.instapro.it%2F7da7f02b-219d-4917-99c6-be3bb3b6ec0b.jpg&q=0&b=1&p=0&a=1" />

Ogni anno a fine marzo, in una valle appartata del Trentino, si svolge un evento curioso, per la grande meraviglia di tutti i biologi: lo stage delle OII! Risvegliati dall'odore degli algoritmi in fioritura, i nerd locali strisciano fuori dai loro nascondigli, abbandonando il loro habitat naturale per incontrarsi e risolvere problemi di programmazione. (si dice che comunichino attraverso una lingua diversa da Brainfuck, ma ciò non è mai stato confermato). La città, per proteggere questi rari e delicati esemplari di Homo Computerensis, ha allestito un albergo speciale: ha `N` stanze e ogni stanza contiene `S`<sub>`i`</sub> ragazzi. Recentemente però una tragedia ha colpito i gentili nerd. Il sistema di riscaldamento dell'abitazione si è rotto, facendo precipitare la temperatura di alcune camere sotto lo zero!

Sconvolti, gli studenti hanno iniziato a correre sotto shock, ma dopo un po' di tempo un modello è emerso dal caos: in qualsiasi momento, uno studente lascia la sua stanza attuale `S`<sub>`i`</sub> e si precipita il più velocemente possibile (che purtroppo, nel caso di Homo Computerensis, non è proprio veloce) in un'altra stanza che è già attrettanto affollata di quella che va a lasciare (tutti sanno che le stanze affollate sono più calde). I corridoi sono stretti, quindi solo uno studente alla volta può correre lungo di essi. Nessuno studente lascerà la stanza più affollata, per quanto possa diventare insopportabilmente puzzolente.

I ragazzi hanno notato che più corrono, più si riscaldano. Aiutali a trovare il modo di massimizzare il numero di corse, per riscaldare il più possibile le stanze!

## Input
La prima riga dell'input contiene un solo intero `N`, il numero di stanze. La seconda riga contiene `N` numeri interi `S`<sub>`0`</sub>`, S`<sub>`1`</sub>`, ... S`<sub>`N-2`</sub>`, S`<sub>`N-1`</sub> separati da uno spazio, il numero di studenti presenti inizialmente in ogni stanza.

## Output
L'output è composto da una sola riga contenente il numero massimo di spostamenti che possono fare i ragazzi seguendo le regole descritte sopra.

## Assunzioni
- `N <= 2500`
- `S`<sub>`i`</sub> `<= 100`

## Assegnazione del punteggio
Il tuo programma verrà testato su diversi test case raggruppati in subtask. Per ottenere il punteggio relativo ad un subtask, è necessario risolvere correttamente tutti i test che lo compongono.
- `Subtask 1 [ 1 punto]`: Casi d'esempio
- `Subtask 2 [ 4 punti]`: `N = 2`
- `Subtask 3 [20 punti]`: `S`<sub>`i`</sub> `= 1`
- `Subtask 4 [20 punti]`: `N <= 4, S`<sub>`i`</sub> `<= 10`
- `Subtask 5 [25 punti]`: `N <= 500`
- `Subtask 5 [30 punti]`: Nessuna limitazione specifica

## Esempi di input/output
| stdin | stdout |
|:------|:-------|
|`4`<br>`1 1 0 1`|`2`|
|`3`<br>`1 9 2`|`4`|

## Spiegazione
Nel primo caso d'esempio il massimo numero di spostamenti si può ottenere muovendo sia il ragazzo della prima stanza che quello della quarta nella seconda stanza. Il risultato è quindi `2`.

Nel secondo caso d'esempio il massimo numero di spostamenti si ottiene solamente con questa sequenza:  
```
1  9  2  (situazione iniziale)
0  9  3  (il ragazzo della prima stanza si sposta nella terza)
0 10  2  (un ragazzo della terza stanza si sposta nella seconda)
0 11  1  (un ragazzo della terza stanza si sposta nella seconda)
0 12  0  (il ragazzo rimasto nella terza stanza si sposta nella seconda)
```
Il risultato è quindi `4`.