///////////////////////////////////////////////////////////////////////////
//                                                                       //
// In questo programma, la classe  "stringa" è  definita come  "handle"  //
// alla struttura  "rappr"  (sua rappresentazione interna), che conserva //
// le principali caratteristiche delle stringhe "in stile C", e cioè:    //
// 1) le stringhe sono rappresentate come array di char, terminate con 0;//
// 2) si possono estrarre o inserire singoli caratteri, utilizzando un   //
//    overload dell'operatore [ ], sia come r-value (estrazione), che    //
//    come l-value (inserimento);                                        //
// 3) sono definite le funzioni esterne friend per gli overload di lettu-//
//    ra operator>> (estrazione da cin), e di scrittura operator<< (inse-//
//    rimento in cout), che riconoscono le "stringhe" (cioè gli oggetti  //
//    della classe stringa) come right-operand.                          //
// In più, la classe presenta le seguenti funzionalità:                  //
//  1) costruttore di default di "stringa" nulla;                        //
//  2) costruttore con un argomento stringa "in stile C" (const char *), //
//     e di conseguenza conversione implicita da stringa "in stile C" a  //
//     "stringa";                                                        //
//  3) costruttore di copia da un'altra "stringa";                       //
//  4) overload dell'operatore di assegnazione da un'altra "stringa";    //
//  5) distruttore di una "stringa", che distrugge anche la sua rappre-  //
//     sentazione se, e solo se, nessun'altra "stringa" è agganciata;    //
//  6) metodo ("dimensione") in sola lettura, che restituisce la lunghez-//
//     za "dim" della "stringa";                                         //
//  7) metodo ("estrai") per l'estrazione di un singolo carattere, di    //
//     indice "i", senza controllo che "i" sia compreso fra 0 e dim-1;   //
//  8) metodo ("inserisci") per l'inserimento di un singolo carattere,   //
//     di indice "i", senza controllo che "i" sia compreso fra 0 e dim-1;//
//  9) controllo dell'operando indice "i" nell'operatore [ ], sia in     //
//     estrazione che in inserimento: se "i" non è compreso fra 0 e dim-1//
//     è sollevata un'eccezione di tipo struttura "Errore";              //
// 10) metodo per la ridefinizione della dimensione di una stringa       //
//     ("ridimensiona"); se la nuova "stringa" è più lunga, la parte     //
//     eccedente viene riempita con blanks;                              //
// 11) concatenazione di una seconda "stringa"  aggiunta alla "stringa"  //
//     data, tramite overload dell'operatore +=  (metodo);               //
// 12) concatenazione fra due "stringhe" tramite overload dell'operatore //
//     + (non è un metodo e non è neppure friend, in quanto non accede a //
//     membri privati di "stringa", ma si avvale di operator+=;          //
// 13) confronto fra due "stringhe" tramite overload dell'operatore ==   //
//     (funzione esterna friend), che restituisce true se le due         //
//     "stringhe" sono identiche;                                        //
// 14) confronto fra due "stringhe" tramite overload dell'operatore !=   //
//     (funzione esterna non friend, in quanto usa solo operator==),     //
//     che restituisce true se le due "stringhe" sono diverse;           //
// 15) infine, metodo privato "ricrea" (chiamato da "ridimensiona" e da  //
//     operator>>) che crea una nuova "rappr",cioè un nuovo oggetto della//
//     struttura di rappresentazione, a cui agganciare una "stringa".    //
// Notare che in tutti gli overload degli operatori binari metodi, in cui//
// il right-operand è una "stringa" (=,+=), è in quelli delle funzioni   //
// esterne in cui entrambi gli operandi sono "stringhe" (+,==,!=), si può//
// fornire uno dei due operandi come stringa "in stile C", grazie alla   //
// presenza del costruttore che converte implicitamente const char* in   //
// "stringa". Fa eccezione operator>>, che non esegue la conversione, in //
// quanto sceglie direttamente l'overload con operando const char* che   //
// esiste già in libreria.                                               //
//                                                                       //
// Ogni volta che è invocata una copia (dal costruttore di copia o dal-  //
// l'operatore di assegnazione), è incrementato di 1 il membro "conta"   //
// della "rappr" a cui è agganciata la "stringa" da copiare, e alla      //
// stessa "rappr" è agganciata anche la "stringa" su cui deve essere ese-//
// guita la copia (l'aggancio avviene tramite copia del membro "prappr"  //
// di "stringa", puntatore a "rappr").                                   //
//                                                                       //
// Quando una "stringa" sta per essere modificata o distrutta, si consi- //
// ra la sua "rappr":                                                    //
// 1) se non esistono altre "stringhe" agganciate ("conta"=1), la "rappr"//
//    viene direttamente modificata o distrutta;                         //
// 2) se esistono altre "stringhe" agganciate ("conta">1), "conta" è     //
//    decrementato di 1, dopodiche' :                                         //
//    a) se la "stringa" deve essere distrutta, non succede altro;       //
//    b) se la "stringa" deve essere modificata, viene clonata una nuova //
//       "rappr" su cui sono eseguite le modifiche;                      //
//    c) se la "stringa" deve essere riassegnata, la sua "rappr" viene   //
//       distrutta e la "stringa" è agganciata alla "rappr" della        //
//       "stringa" da copiare.                                           //
//                                                                       //
// La modifica di una "stringa" può essere determinata da una delle      //
// seguenti funzioni (metodi o friend):                                  //
// a) operator=                                                          //
// b) inserisci                                                          //
// c) ridimensiona                                                       //
// d) operator+=                                                         //
// e) operator>>                                                         //
// f) operator[]                                                         //
// Tutte le operazioni sopraelencate producono sempre la modifica della  //
// "stringa", salvo l'ultima, che può restituire sia un r-value (estra-  //
// zione di un carattere, senza modifica), che un l-value (inserimento di//
// un carattere), e quindi la modifica ci sarà  solo se il carattere re- //
// stituito da operator[] è a sua volta left-operand di un'assegnazione. //
//                                                                       //
// A questo scopo operator[] ha 2 overload: il primo, chiamato quando la //
// la "stringa" è const, chiama a sua volta "estrai" (e quindi da' errore//
// se si tenta di utilizzarne il ritorno come l-value); il secondo, chia-//
// mato quando "stringa" non è const, non ritorna un riferimento a char, //
// ma un'istanza di un'altra struttura annidata, di nome "rifc" (una spe-//
// cie di riferimento a char "intelligente"): questa struttura possiede 2//
// operatori in overload: un'assegnazione e un casting a char, e quindi: //
// a) se il ritorno di operator[] è a sua volta left-operand di un'asse- //
//    gnazione, è azionato operator= di "rifc" che a sua volta chiama    //
//    "inserisci" di "stringa";                                          //
// b) altrimenti "rifc" è convertito implicitamente a char e passato a   //
//    "estrai" di "stringa".                                             //
// I 2 metodi di "rifc" sono in grado di fare queste operazioni, perchè  //
// conoscono sia la "stringa" che l'indice, che sono pure membri di rifc,//
// entrambi passati al suo costruttore da operator[] di "stringa" (in    //
// particolare la "stringa" deve essere la stessa e quindi il membro di  //
// rifc deve essere dichiarato come riferimento a "stringa"              //
//                                                                       //
///////////////////////////////////////////////////////////////////////////
 
#include <iostream.h>

namespace spazio_stringa
{
	class stringa
	{
// la struttura rappr è :
//  1) "privata" di stringa in quanto può essere istanziata solo da stringa
//  2) dichiarata nell'interfaccia e definita nell'implementazione (e quindi
//	   invisibile al main) in quanto i suoi membri sono usati solo dai
//	   metodi di stringa
		struct rappr;
		rappr* prappr;
// la struttura rifc è :
//  1) "privata" di stringa in quanto può essere istanziata solo da stringa
//  2) già definita nell'interfaccia  in quanto i suoi metodi sono usati
//	   anche dal main
		struct rifc
		{
			stringa& srif;
			int ind;
			rifc(stringa& str, int i) : srif(str), ind(i) { }
			void operator=(char c) { srif.inserisci(ind,c); }
			operator char() const { return srif.estrai(ind); }
		};
		void ricrea(char*, int);
	public:
		stringa();
		stringa(const char*);
		stringa(const stringa&);
		stringa& operator=(const stringa&);
		~stringa();
		char estrai(int) const;
		void inserisci(int, char);
		int dimensione() const;
		char operator [](int) const;
		rifc operator[](int); //Nota: restituisce un oggetto di rifc
		void ridimensiona(int);
		stringa& operator+=(const stringa&);
		friend bool operator==(const stringa&, const stringa&);
		friend ostream& operator<<(ostream&, const stringa&);
		friend istream& operator>>(istream&, stringa&);
	};

	struct Errore { };  //Per le eccezioni

//Non occorre che siano friend in quanto non usano membri privati di stringa
	stringa operator+(const stringa&, const stringa&);
	bool operator!=(const stringa&, const stringa&);
}


