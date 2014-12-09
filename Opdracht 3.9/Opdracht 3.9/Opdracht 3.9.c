#include <stdio.h>

int dagnummer;

int main(void)
{
	void error(void);
	void dedag(void);

	int  dag, maand, jaar, goed[5], schrik, jaartellen, jaardagen, maanddagen, geldig;
	char maandnaam[12][10] = { "Januari", "Februari", "Maart", "April", "Mei", "Juni", "Juli", "Augustus", "September", "Oktober", "November", "December" };
	char dagnaam[7][10] = { "Maandag", "Dinsdag", "Woensdag", "Donderdag", "Vrijdag", "Zaterdag", "Zondag" };

	do
	{
		printf("\nWelkom\n");
		dagnummer = 1;
		schrik = 4;
		goed[3] = 1;

		do
		{
			printf("\nVoer een datum in (dd mm jjjj) (1-31 1-12 1900-2100) : ");
			scanf("%d %d %d", &dag, &maand, &jaar);

			if ((dag   >=    1) && (dag   <=   31))						{ goed[0] = 1; }		else	{ goed[0] = 0; }
			if ((maand >=    1) && (maand <=   12))						{ goed[1] = 1; }		else	{ goed[1] = 0; }
			if ((jaar  >= 1900) && (jaar  <= 2100))						{ goed[2] = 1; }		else	{ goed[2] = 0; }
			if ((dag   ==   29) && (maand ==    2))
			{
				for (geldig = 1904; geldig <= 2096; geldig += 4)
				{
					if (jaar == geldig)									{ goed[3] = 1; break; } else	{ goed[3] = 0; }
				}
			}
			if ((dag ==  0) && (maand == 0) && (jaar == 0))				{ goed[4] = 1; }		else	{ goed[4] = 0; }
			if (goed[4] == 1)											{ break; }

			goed[5] = goed[0] + goed[1] + goed[2] + goed[3];
			if (goed[5] != 4)	{ error(); }

		} while (goed[5] != 4);

		if (goed[4] == 1)	{ break; }

		

		for (jaartellen = 0; jaartellen < (jaar - 1900); jaartellen += 1)
		{
			if (jaartellen == schrik)				{ jaardagen = 366; schrik = schrik + 4; }
			else									{ jaardagen = 365; }
			for (; jaardagen > 0; jaardagen -= 1)	{ dedag(); }
		}

		if (jaartellen == schrik)	{ schrik = 1; }
		else						{ schrik = 0; }

		switch (maand)
		{
		case 1:		maanddagen =   0;			break;
		case 2:		maanddagen =  31;			break;
		case 3:		maanddagen =  59 + schrik;	break;
		case 4:		maanddagen =  90 + schrik;	break;
		case 5:		maanddagen = 120 + schrik;	break;
		case 6:		maanddagen = 151 + schrik;	break;
		case 7:		maanddagen = 181 + schrik;	break;
		case 8:		maanddagen = 212 + schrik;	break;
		case 9:		maanddagen = 243 + schrik;	break;
		case 10:	maanddagen = 273 + schrik;	break;
		case 11:	maanddagen = 304 + schrik;	break;
		case 12:	maanddagen = 334 + schrik;	break;
		default:	error();
		}

		for (; maanddagen > 0; maanddagen -= 1)	{ dedag(); }
		for (; dag > 1; dag -= 1)				{ dedag(); }

		printf("\nUw dag is een : %s", dagnaam[dagnummer - 1]);

		getchar();
		getchar();

	} while (goed[4] != 1);
}

void error(void)
{
	printf("\nERROR\tOngeldige invoer\n");
}

void dedag(void)
{
	if (dagnummer < 7)	{ dagnummer = dagnummer + 1; }
	else				{ dagnummer = 1; };
}