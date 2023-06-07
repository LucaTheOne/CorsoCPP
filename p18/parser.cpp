#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
/*	questo programma legge una stringa, riconosce ed estrae
	da questa i numeri interi e floating, scrive la stringa
	rimanente e infine scrive separatamente i numeri interi
	e i numeri floating estratti, con un formato opportuno 
*/
void main()
{
	// stringa di input, indice corrente e lunghezza stringa
	char inpstr[100];	int inpind=0, strlen=0, numind;;
	cout << "Stringa di input (non terminare con: /cifra/./+/-):"<<endl;
	gets(inpstr);
	while (inpstr[inpind++]) strlen++;

	// inizializzazione info sui numeri int e double da estrarre
	const int maxint=3;		const int maxdoub=3;
	int integ[maxint];		double rnum[maxdoub];
	int currint=0;			int currdoub = 0;
	bool isint=false;		bool isdoub=false;
	
	// stringa di output e indice corrente
	char outstr[100];	int outind=0;

	// loop di estrazione dei numeri
	for (inpind=0; inpind < strlen; inpind++)
	{
		char curch = inpstr[inpind];
		if ( !isint && !isdoub )
		{
			switch ( curch )
			{
			case '-' :
			case '+' :	isint = true;	break;
			case '.' :	isdoub = true;	break;
			default :
				if ( curch >= '0' && curch <= '9' ) isint = true;
			}
			if ( isint || isdoub ) numind = inpind;
			else outstr[outind++] = curch;
		}
		else
		{
			bool convert=false;
			if ( curch == '.' )
			{
				if ( isint ) 
				{
					isint = false;
					isdoub = true;
				}
				else convert = true;
			}
			else convert = curch < '0' || curch > '9';
			if ( convert )
			{
				if ( isint && currint < maxint || 
					 isdoub && currdoub < maxdoub )
				{
					int workind = 0;
					char workstr[100];
					while ( numind < inpind ) 
						workstr[workind++] = inpstr[numind++];
					workstr[workind] = '\0';
					if ( isint ) integ[currint++] = atoi(workstr);
					else rnum[currdoub++] = atof(workstr);
				}
				else while ( numind < inpind ) 
					outstr[outind++] = inpstr[numind++];
				outstr[outind++] = curch;
				isint = false;	isdoub = false;
			}
		}
	}
	outstr[outind] = '\0';

	cout << "\nStringa di output (senza i numeri):"<<endl;
	puts(outstr);

	cout << "\nNumeri interi :\n";
	int i;
	for (i=0; i < currint; i++)
	{
		char workstr[10];
		sprintf(workstr," %08d",integ[i]);
		cout << workstr;
	}

	cout << "\n\nNumeri floating :\n";
	for (i=0; i < currdoub; i++)
	{
		char workstr[12];
		sprintf(workstr," %10.3E",rnum[i]);
		cout << workstr;
	}
	cout << "\n\n\n";
}