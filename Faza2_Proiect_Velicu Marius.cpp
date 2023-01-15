//Velicu Marius - 1061E

#pragma warning (disable:4996)
#include <iostream>
#include <fstream>
using namespace std;


class Stadion
{
private:
	const int idStadion;
	char* numeStadion;
	int nrZone;
	string* denumiriZone;
	int* nrRanduriPerZona;
	int* nrLocuriPerRandZona;
	static int ids;
public:
	//constructor implicit
	Stadion() :idStadion(ids)
	{
		this->numeStadion = new char[strlen("Anonim") + 1];
		strcpy(this->numeStadion, "Anonim");
		this->nrZone = 0;
		this->denumiriZone = nullptr;
		this->nrRanduriPerZona = nullptr;
		this->nrLocuriPerRandZona = nullptr;
		ids++;
	}
	//constructor cu parametrii
	Stadion(const char* numeStadion, int nrZone, string* denumiriZone, int* nrRanduriPerZona, int* nrLocuriPerRandZona) :idStadion(ids)
	{
		this->numeStadion = new char[strlen(numeStadion) + 1];
		strcpy(this->numeStadion, numeStadion);
		this->nrZone = nrZone;
		if (nrZone != 0)
		{
			this->denumiriZone = new string[nrZone];
			this->nrRanduriPerZona = new int[nrZone];
			this->nrLocuriPerRandZona = new int[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				this->denumiriZone[i] = denumiriZone[i];
				this->nrRanduriPerZona[i] = nrRanduriPerZona[i];
				this->nrLocuriPerRandZona[i] = nrLocuriPerRandZona[i];
			}
		}
		else
		{
			this->denumiriZone = denumiriZone;
			this->nrRanduriPerZona = nrRanduriPerZona;
			this->nrLocuriPerRandZona = nrLocuriPerRandZona;
		}
		ids++;
	}
	//constructor de copiere
	Stadion(Stadion& s) :idStadion(s.idStadion)
	{
		this->numeStadion = new char[strlen(s.numeStadion) + 1];
		strcpy(this->numeStadion, s.numeStadion);
		this->nrZone = s.nrZone;
		if (s.nrZone != 0)
		{
			this->denumiriZone = new string[s.nrZone];
			this->nrRanduriPerZona = new int[s.nrZone];
			this->nrLocuriPerRandZona = new int[s.nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				this->denumiriZone[i] = s.denumiriZone[i];
				this->nrRanduriPerZona[i] = s.nrRanduriPerZona[i];
				this->nrLocuriPerRandZona[i] = s.nrLocuriPerRandZona[i];
			}
		}
		else
		{
			this->denumiriZone = s.denumiriZone;
			this->nrRanduriPerZona = s.nrRanduriPerZona;
			this->nrLocuriPerRandZona = s.nrLocuriPerRandZona;
		}
	}
	//operator=
	Stadion& operator=(const Stadion& s)
	{
		if (this != &s)
		{
			if (this->numeStadion != nullptr)
			{
				delete[]this->numeStadion;
				this->numeStadion = nullptr;
			}
			this->numeStadion = new char[strlen(s.numeStadion) + 1];
			strcpy(this->numeStadion, s.numeStadion);
			this->nrZone = s.nrZone;
			if (s.nrZone != 0)
			{
				if (this->denumiriZone != nullptr)
				{
					delete[]this->denumiriZone;
					this->denumiriZone = nullptr;
				}
				this->denumiriZone = new string[s.nrZone];
				for (int i = 0; i < s.nrZone; i++)
					this->denumiriZone[i] = s.denumiriZone[i];
				if (this->nrRanduriPerZona != nullptr)
				{
					delete[]this->nrRanduriPerZona;
					this->nrRanduriPerZona = nullptr;
				}
				this->nrRanduriPerZona = new int[s.nrZone];
				for (int i = 0; i < s.nrZone; i++)
					this->nrRanduriPerZona[i] = s.nrRanduriPerZona[i];
				if (this->nrLocuriPerRandZona != nullptr)
				{
					delete[]this->nrLocuriPerRandZona;
					this->nrLocuriPerRandZona = nullptr;
				}
				this->nrLocuriPerRandZona = new int[s.nrZone];
				for (int i = 0; i < s.nrZone; i++)
					this->nrLocuriPerRandZona[i] = s.nrLocuriPerRandZona[i];
			}
			else
			{
				this->denumiriZone = s.denumiriZone;
				this->nrRanduriPerZona = s.nrRanduriPerZona;
				this->nrLocuriPerRandZona = s.nrLocuriPerRandZona;
			}
		}
		return *this;
	}
	//getteri si setteri
	int getIdStadion()
	{
		return this->idStadion;
	}
	char* getNumeStadion()
	{
		char* copie = new char[strlen(this->numeStadion) + 1];
		strcpy(copie, this->numeStadion);
		return copie;
	}
	void setNumeStadion(char* numeStadion)
	{
		if (numeStadion != nullptr)
		{
			if (this->numeStadion != nullptr)
			{
				delete[]this->numeStadion;
				this->numeStadion = nullptr;
			}
			this->numeStadion = new char[strlen(numeStadion) + 1];
			strcpy(this->numeStadion, numeStadion);
		}
	}
	int getNrZone()
	{
		return this->nrZone;
	}
	void setNrZone(int nrZone)
	{
		if (nrZone > 0)
		{
			this->nrZone = nrZone;
		}
	}
	string* getDenumiriZone()
	{
		string* copie;
		if (this->nrZone > 0)
		{
			copie = new string[this->nrZone];
			for (int i = 0; i < this->nrZone; i++)
				copie[i] = this->denumiriZone[i];
		}
		else
			copie = this->denumiriZone;
		return copie;
	}
	void setDenumiriZone(string* denumiriZone, int nrZone)
	{
		if (nrZone > 0 && denumiriZone != nullptr)
		{
			if (this->denumiriZone != nullptr)
			{
				delete[]this->denumiriZone;
				this->denumiriZone = nullptr;
			}
			this->denumiriZone = new string[nrZone];
			for (int i = 0; i < nrZone; i++)
				this->denumiriZone[i] = denumiriZone[i];
		}
	}
	int* getNrRanduriPerZona()
	{
		int* copie;
		if (this->nrZone > 0)
		{
			copie = new int[this->nrZone];
			for (int i = 0; i < this->nrZone; i++)
				copie[i] = this->nrRanduriPerZona[i];
		}
		else
			copie = this->nrRanduriPerZona;
		return copie;
	}
	void setNrRanduriPerZona(int* nrRanduriPerZona, int nrZone)
	{
		if (nrZone > 0 && nrRanduriPerZona != nullptr)
		{
			bool ok = true;
			for (int i = 0; i < nrZone; i++)
				if (nrRanduriPerZona[i] <= 0)
					ok = false;
			if (ok == true)
			{
				if (this->nrRanduriPerZona != nullptr)
				{
					delete[]this->nrRanduriPerZona;
					this->nrRanduriPerZona = nullptr;
				}
				this->nrRanduriPerZona = new int[nrZone];
				for (int i = 0; i < nrZone; i++)
					this->nrRanduriPerZona[i] = nrRanduriPerZona[i];
			}
		}
	}
	int* getNrLocuriPerRandZona()
	{
		int* copie;
		if (this->nrZone > 0)
		{
			copie = new int[this->nrZone];
			for (int i = 0; i < this->nrZone; i++)
				copie[i] = this->nrLocuriPerRandZona[i];
		}
		else
			copie = this->nrLocuriPerRandZona;
		return copie;
	}
	void setNrLocuriPerRandZona(int* nrLocuriPerRandZona, int nrZone)
	{
		if (nrZone > 0 && nrLocuriPerRandZona != nullptr)
		{
			bool ok = true;
			for (int i = 0; i < nrZone; i++)
				if (nrLocuriPerRandZona[i] <= 0)
					ok = false;
			if (ok == true)
			{
				if (this->nrLocuriPerRandZona != nullptr)
				{
					delete[]this->nrLocuriPerRandZona;
					this->nrLocuriPerRandZona = nullptr;
				}
				this->nrLocuriPerRandZona = new int[nrZone];
				for (int i = 0; i < nrZone; i++)
					this->nrLocuriPerRandZona[i] = nrLocuriPerRandZona[i];
			}
		}
	}
	//alte functii
	void adaugareArenaNume()
	{
		char* arena = new char[strlen("Arena ") + 1];
		strcpy(arena, "Arena ");
		strcat(arena, this->numeStadion);
		if (this->numeStadion != nullptr);
		{
			delete[]this->numeStadion;
			this->numeStadion = nullptr;
		}
		this->numeStadion = new char[strlen(arena) + 1];
		strcpy(this->numeStadion, arena);
	}
	static long* nrLocuriTotalePerZone(const Stadion& s)
	{
		long* locuriTotaleZone = nullptr;
		if (s.nrZone > 0)
		{
			locuriTotaleZone = new long[s.nrZone];
			for (int i = 0; i < s.nrZone; i++)
				locuriTotaleZone[i] = s.nrRanduriPerZona[i] * s.nrLocuriPerRandZona[i];
		}
		return locuriTotaleZone;
	}
	static long nrLocuriTotaleStadion(const Stadion& s)
	{
		long locuri = 0;
		if (s.nrZone > 0)
			for (int i = 0; i < s.nrZone; i++)
				locuri = locuri + s.nrRanduriPerZona[i] * s.nrLocuriPerRandZona[i];
		return locuri;
	}
	static void modificariStadion(Stadion& s)
	{
		cout << "In cazul in care doresti sa efectuezi vreo schimbare la stadionul creat, iata ce modificari poti face: " << endl;
		bool ok = false;
		bool ok1;
		int index;
		char buffer[255];
		char* nume;
		int nr;
		string* zone;
		int* randuri;
		int* locuri;
		string zona;
		int rand;
		int loc;
		while (ok == false)
		{
			cout << "Pentru a schimba numele stadionului, apasa 1" << endl;
			cout << "Pentru a schimba numarul de zone ale stadionului, apasa 2" << endl;
			cout << "Pentru a schimba denumirea unei zone, apasa 3" << endl;
			cout << "Pentru a schimba denumirile tuturor zonelor, apasa 4" << endl;
			cout << "Pentru a schimba numarul de randuri dintr-o anumita zona, apasa 5" << endl;
			cout << "Pentru a schimba numarul de randuri din fiecare zona, apasa 6" << endl;
			cout << "Pentru a schimba numarul de locuri per rand dintr-o anumita zona, apasa 7" << endl;
			cout << "Pentru a schimba numarul de locuri per rand din fiecare zona, apasa 8" << endl;
			cout << "Daca nu doresti sa efectuezi modificari, apasa 9" << endl << endl;
			cout << "Alegerea ta este: ";
			ok1 = false;
			while (ok1 == false)
			{
				cin >> index;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				if (index < 1 || index>9)
				{
					cout << "Alegerea ta nu se regaseste in optiunile de mai sus" << endl;
					cout << "Introdu un numar corect: ";
				}
				else
					ok1 = true;
			}
			if (index == 1)
			{
				cout << "\nNumele nou al stadionului este: Arena ";
				cin >> buffer;
				nume = new char[strlen(buffer) + 1];
				strcpy(nume, buffer);
				s.setNumeStadion(nume);
				s.adaugareArenaNume();
				cout << s;
				delete[]nume;
				nume = nullptr;
			}
			if (index == 2)
			{
				cout << "\nNumarul nou de zone al stadionului este: ";
				ok1 = false;
				while (ok1 == false)
				{
					cin >> nr;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> nr;
						}
					}
					if (nr <= 0)
					{
						cout << "\nNumarul de zone al stadionului nu poate fi negativ sau 0" << endl;
						cout << "Introdu un numar nou de zone valid: ";
					}
					else
						ok1 = true;
				}
				s.setNrZone(nr);
				cout << "\nPentru ca ai schimbat numarul de zone, trebuiesc schimbate si celelalte atribute";
				cout << "\nDenumirile zonelor noi sunt: " << endl << endl;
				zone = new string[nr];
				for (int i = 0; i < nr; i++)
				{
					cout << "\nZona " << i + 1 << " se numeste: " << endl;
					cin >> zone[i];
				}
				s.setDenumiriZone(zone, nr);
				cout << "\n\nNumarul de randuri pe fiecare zona: " << endl << endl;
				randuri = new int[nr];
				for (int i = 0; i < nr; i++)
				{
					cout << "\nNumarul de randuri din zona " << s.getDenumiriZone()[i] << " este: ";
					ok1 = false;
					while (ok1 == false)
					{
						cin >> randuri[i];
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> randuri[i];
							}
						}
						if (randuri[i] <= 0)
						{
							cout << "\nNumarul de randuri al stadionului nu poate fi negativ sau 0" << endl;
							cout << "Introdu un numar nou de randuri valid pentru zona " << s[i] << " : ";
						}
						else
							ok1 = true;
					}
				}
				s.setNrRanduriPerZona(randuri, nr);
				cout << "\n\nNumarul de locuri per rand din fiecare zona:" << endl << endl;
				locuri = new int[nr];
				for (int i = 0; i < nr; i++)
				{
					cout << "\nNumarul de locuri per rand din zona " << s.getDenumiriZone()[i] << " este: ";
					ok1 = false;
					while (ok1 == false)
					{
						cin >> locuri[i];
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> locuri[i];
							}
						}
						if (locuri[i] <= 0)
						{
							cout << "\nNumarul de locuri per rand din stadion nu poate fi negativ sau 0" << endl;
							cout << "Introdu un numar nou de locuri per rand valid pentru zona " << s[i] << " : ";
						}
						else
							ok1 = true;
					}
				}
				s.setNrLocuriPerRandZona(locuri, nr);
				cout << s;
				delete[]zone;
				zone = nullptr;
				delete[]randuri;
				randuri = nullptr;
				delete[]locuri;
				locuri = nullptr;
			}
			if (index == 3)
			{
				cout << "\nIntrodu numarul zonei pe care vrei sa o schimbi: ";
				ok1 = false;
				while (ok1 == false)
				{
					cin >> nr;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> nr;
						}
					}
					nr--;
					if (nr < 0 || nr >= s.getNrZone())
					{
						cout << "\nNumarul nu corespunde niciunei zone" << endl;
						cout << "Introdu un numar de zona valid: ";
					}
					else
						ok1 = true;
				}
				cout << "\nZona " << s.getDenumiriZone()[nr] << " isi schimba denumirea in: ";
				cin >> zona;
				zone = new string[s.getNrZone()];
				zone = s.getDenumiriZone();
				zone[nr] = zona;
				s.setDenumiriZone(zone, s.getNrZone());
				cout << s;
				delete[]zone;
				zone = nullptr;
			}
			if (index == 4)
			{
				cout << "\nDenumirile zonelor noi sunt: " << endl << endl;
				zone = new string[s.getNrZone()];
				for (int i = 0; i < s.getNrZone(); i++)
				{
					cout << "\nZona " << s.getDenumiriZone()[i] << " isi schimba denumirea in: ";
					cin >> zone[i];
				}
				s.setDenumiriZone(zone, s.getNrZone());
				cout << s;
				delete[]zone;
				zone = nullptr;
			}
			if (index == 5)
			{
				cout << "\nIntrodu numarul zonei careia doresti sa ii schimbi numarul de randuri: ";
				ok1 = false;
				while (ok1 == false)
				{
					cin >> nr;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> nr;
						}
					}
					nr--;
					if (nr < 0 || nr >= s.getNrZone())
					{
						cout << "\nNumarul nu corespunde niciunei zone" << endl;
						cout << "Introdu un numar de zona valid: ";
					}
					else
						ok1 = true;
				}
				cout << "\nNumarul nou de randuri este: ";
				ok1 = false;
				while (ok1 == false)
				{
					cin >> rand;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> rand;
						}
					}
					if (rand <= 0)
					{
						cout << "\nNumarul de randuri nu poate fi negativ sau 0" << endl;
						cout << "Introdu un numar de randuri valid: ";
					}
					else
						ok1 = true;
				}
				randuri = new int[s.getNrZone()];
				randuri = s.getNrRanduriPerZona();
				randuri[nr] = rand;
				s.setNrRanduriPerZona(randuri, s.getNrZone());
				cout << s;
				delete[]randuri;
				randuri = nullptr;
			}
			if (index == 6)
			{
				cout << "\n\nNumarul de randuri pe fiecare zona: " << endl << endl;
				randuri = new int[s.getNrZone()];
				for (int i = 0; i < s.getNrZone(); i++)
				{
					cout << "\nNumarul de randuri din zona " << s.getDenumiriZone()[i] << " este: ";
					ok1 = false;
					while (ok1 == false)
					{
						cin >> randuri[i];
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> randuri[i];
							}
						}
						if (randuri[i] <= 0)
						{
							cout << "\nNumarul de randuri al stadionului nu poate fi negativ sau 0" << endl;
							cout << "Introdu un numar nou de randuri valid pentru zona " << s[i] << " : ";
						}
						else
							ok1 = true;
					}
				}
				s.setNrRanduriPerZona(randuri, s.getNrZone());
				cout << s;
				delete[]randuri;
				randuri = nullptr;

			}
			if (index == 7)
			{
				cout << "\nIntrodu numarul zonei careia doresti sa ii schimbi numarul de locuri per rand: ";
				ok1 = false;
				while (ok1 == false)
				{
					cin >> nr;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> nr;
						}
					}
					nr--;
					if (nr < 0 || nr >= s.getNrZone())
					{
						cout << "\nNumarul nu corespunde niciunei zone" << endl;
						cout << "Introdu un numar de zona valid: ";
					}
					else
						ok1 = true;
				}
				cout << "\nNumarul nou de locuri per randuri este: ";
				ok1 = false;
				while (ok1 == false)
				{
					cin >> loc;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> loc;
						}
					}
					if (loc <= 0)
					{
						cout << "\nNumarul de locuri per rand nu poate fi negativ sau 0" << endl;
						cout << "Introdu un numar de locuri per rand valid: ";
					}
					else
						ok1 = true;
				}
				locuri = new int[s.getNrZone()];
				locuri = s.getNrRanduriPerZona();
				locuri[nr] = loc;
				s.setNrLocuriPerRandZona(locuri, s.getNrZone());
				cout << s;
				delete[]locuri;
				locuri = nullptr;
			}
			if (index == 8)
			{
				cout << "\n\nNumarul de locuri per rand din fiecare zona:" << endl << endl;
				locuri = new int[s.getNrZone()];
				for (int i = 0; i < s.getNrZone(); i++)
				{
					cout << "\nNumarul de locuri per rand din zona " << s.getDenumiriZone()[i] << " este: ";
					ok1 = false;
					while (ok1 == false)
					{
						cin >> locuri[i];
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> locuri[i];
							}
						}
						if (locuri[i] <= 0)
						{
							cout << "\nNumarul de locuri per rand din stadion nu poate fi negativ sau 0" << endl;
							cout << "Introdu un numar nou de locuri per rand valid pentru zona " << s[i] << " : ";
						}
						else
							ok1 = true;
					}
				}
				s.setNrLocuriPerRandZona(locuri, s.getNrZone());
				cout << s;
				delete[]locuri;
				locuri = nullptr;
			}
			if (index == 9)
				ok = true;
		}
	}
	//operator de indexare
	string operator[](int i)
	{
		if (i >= 0 && i < this->nrZone)
		{
			return this->denumiriZone[i];
		}
	}
	//operator cast
	explicit operator char** ()
	{
		if (this->nrZone > 0)
		{
			char** copie;
			copie = new char* [this->nrZone];
			for (int i = 0; i < this->nrZone; i++)
				copie[i] = new char[denumiriZone[i].length() + 1];
			for (int i = 0; i < this->nrZone; i++)
				strcpy(copie[i], denumiriZone[i].c_str());
			return copie;
		}
	}
	bool operator==(const Stadion& s)
	{
		if (strcmp(this->numeStadion, s.numeStadion) != 0)
			return 0;
		if (this->nrZone != s.nrZone)
			return 0;
		for (int i = 0; i < this->nrZone; i++)
		{
			if (this->denumiriZone[i] != s.denumiriZone[i])
				return 0;
			if (this->nrRanduriPerZona[i] != s.nrRanduriPerZona[i])
				return 0;
			if (this->nrLocuriPerRandZona[i] != s.nrLocuriPerRandZona[i])
				return 0;
		}
		return 1;
	}
	//destructor
	~Stadion()
	{
		if (this->denumiriZone != nullptr)
		{
			delete[]this->denumiriZone;
			this->denumiriZone = nullptr;
		}
		if (this->nrRanduriPerZona != nullptr)
		{
			delete[]this->nrRanduriPerZona;
			this->nrRanduriPerZona = nullptr;
		}
		if (this->nrLocuriPerRandZona != nullptr)
		{
			delete[]this->nrLocuriPerRandZona;
			this->nrLocuriPerRandZona = nullptr;
		}
	}
	friend istream& operator>>(istream& in, Stadion& s);
	friend ostream& operator<<(ostream& out, Stadion& s);
	friend class Meci;
};
int Stadion::ids = 1;
istream& operator>>(istream& in, Stadion& s)
{
	cout << "\nDetaliile stadionului sunt:";
	cout << "\nNumele stadionului este: Arena ";
	char buffer[255];
	in >> buffer;
	if (buffer != NULL)
	{
		if (s.numeStadion != nullptr)
		{
			delete[]s.numeStadion;
			s.numeStadion = nullptr;
		}
		s.numeStadion = new char[strlen(buffer) + 1];
		strcpy(s.numeStadion, buffer);
	}
	cout << "\nNumarul de zone ale stadionului este: ";
	bool ok = false;
	while (ok == false)
	{
		in >> s.nrZone;
		while (in.good() == 0)
		{
			if (in.bad())
				throw"IO stream corrupted";
			if (in.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				in.clear();
				in.ignore(INT_MAX, '\n');
				in >> s.nrZone;
			}
		}
		if (s.nrZone <= 0)
		{
			cout << "\nNumarul de zone ale unui stadion nu poate fi negativ sau 0";
			cout << "\nIntrodu un numar de zone valid: ";
		}
		else
			ok = true;
	}
	cout << "\nDenumirile zonelor:";
	if (s.denumiriZone != nullptr)
	{
		delete[]s.denumiriZone;
		s.denumiriZone = nullptr;
	}
	s.denumiriZone = new string[s.nrZone];
	for (int i = 0; i < s.nrZone; i++)
	{
		cout << "\nZona " << i + 1 << " se numeste: ";
		in >> s.denumiriZone[i];
	}
	cout << "\n\nNumar de randuri per zona:";
	if (s.nrRanduriPerZona != nullptr)
	{
		delete[]s.nrRanduriPerZona;
		s.nrRanduriPerZona = nullptr;
	}
	s.nrRanduriPerZona = new int[s.nrZone];
	for (int i = 0; i < s.nrZone; i++)
	{
		cout << "\nNumarul de randuri din zona " << s.denumiriZone[i] << " este: ";
		in >> s.nrRanduriPerZona[i];
		while (in.good() == 0)
		{
			if (in.bad())
				throw"IO stream corrupted";
			if (in.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				in.clear();
				in.ignore(INT_MAX, '\n');
				in >> s.nrRanduriPerZona[i];
			}
		}
		ok = false;
		while (ok == false)
		{
			if (s.nrRanduriPerZona[i] <= 0)
			{
				cout << "\nNumarul de randuri din oricare zona nu poate fi negativ sau 0" << endl;
				cout << "Introdu un numar de randuri valid: ";
				in >> s.nrRanduriPerZona[i];
				while (in.good() == 0)
				{
					if (in.bad())
						throw"IO stream corrupted";
					if (in.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						in.clear();
						in.ignore(INT_MAX, '\n');
						in >> s.nrRanduriPerZona[i];
					}
				}
			}
			else
				ok = true;
		}
	}
	cout << "\n\nNumar de locuri per rand din fiecare zona:";
	if (s.nrLocuriPerRandZona != nullptr)
	{
		delete[]s.nrLocuriPerRandZona;
		s.nrLocuriPerRandZona = nullptr;
	}
	s.nrLocuriPerRandZona = new int[s.nrZone];
	for (int i = 0; i < s.nrZone; i++)
	{
		cout << "\nNumarul de locuri per rand din zona " << s.denumiriZone[i] << " este: ";
		in >> s.nrLocuriPerRandZona[i];
		while (in.good() == 0)
		{
			if (in.bad())
				throw"IO stream corrupted";
			if (in.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				in.clear();
				in.ignore(INT_MAX, '\n');
				in >> s.nrLocuriPerRandZona[i];
			}
		}
		ok = false;
		while (ok == false)
		{
			if (s.nrLocuriPerRandZona[i] <= 0)
			{
				cout << "\Numarul de locuri pe oricare rand nu poate fi negativ sau 0" << endl;
				cout << "Introdu un numar de locuri valid: ";
				in >> s.nrLocuriPerRandZona[i];
				while (in.good() == 0)
				{
					if (in.bad())
						throw"IO stream corrupted";
					if (in.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						in.clear();
						in.ignore(INT_MAX, '\n');
						in >> s.nrLocuriPerRandZona[i];
					}
				}
			}
			else
				ok = true;
		}
	}
	return in;
}
ostream& operator<<(ostream& out, Stadion& s)
{
	out << endl;
	out << "Numele stadionului este: " << s.numeStadion << endl;
	out << s.numeStadion << " are " << s.nrZone << " zone" << endl;
	if (s.nrZone > 0)
	{
		for (int i = 0; i < s.nrZone; i++)
		{
			out << "Zona " << i + 1 << " se numeste " << s.denumiriZone[i] << endl;
		}
		out << "\n";
		for (int i = 0; i < s.nrZone; i++)
		{
			out << "Zona " << s.denumiriZone[i] << " are " << s.nrRanduriPerZona[i] << " randuri si " << s.nrLocuriPerRandZona[i] << " locuri pe fiecare rand" << endl;
		}
		out << "\n";
		long locuri = 0;
		for (int i = 0; i < s.nrZone; i++)
			locuri = locuri + Stadion::nrLocuriTotalePerZone(s)[i];
		out << "Numarul total de locuri din stadion este: " << locuri << endl;

	}
	else
		out << "Pentru ca numarul de zone este 0, ceilalti vectori din clasa sunt nuli" << endl;
	out << "\n\n";
	return out;
}


class Meci
{
private:
	const int idMeci;
	char* echipa1;
	char* echipa2;
	char* dataMeci;
	char* oraMeci;
	Stadion stadion;
	float* preturi;
	long* spectatori;
	static int idm;
public:
	//constructor implicit
	Meci() :idMeci(idm)
	{
		this->echipa1 = new char[7];
		strcpy(this->echipa1, "Anonim");
		this->echipa2 = new char[7];
		strcpy(this->echipa2, "Anonim");
		this->dataMeci = new char[11];
		strcpy(this->dataMeci, "DD/MM/YYYY");
		this->oraMeci = new char[6];
		strcpy(this->oraMeci, "HH:HH");
		this->preturi = nullptr;
		this->spectatori = nullptr;
		idm++;
	}
	//constructor cu parametrii
	Meci(const char* echipa1, const char* echipa2, const char* dataMeci, const char* oraMeci) :idMeci(idm)
	{
		if (echipa1 != nullptr)
		{
			this->echipa1 = new char[strlen(echipa1) + 1];
			strcpy(this->echipa1, echipa1);
		}
		if (echipa2 != nullptr)
		{
			this->echipa2 = new char[strlen(echipa2) + 1];
			strcpy(this->echipa2, echipa2);
		}
		if (dataMeci != nullptr)
		{
			this->dataMeci = new char[strlen(dataMeci) + 1];
			strcpy(this->dataMeci, dataMeci);
		}
		if (oraMeci != nullptr)
		{
			this->oraMeci = new char[strlen(oraMeci) + 1];
			strcpy(this->oraMeci, oraMeci);
		}
		this->preturi = nullptr;
		this->spectatori = nullptr;
		idm++;
	}
	//constructor de copiere
	Meci(const Meci& m) :idMeci(m.idMeci)
	{
		if (m.echipa1 != nullptr)
		{
			this->echipa1 = new char[strlen(m.echipa1) + 1];
			strcpy(this->echipa1, m.echipa1);
		}
		if (m.echipa2 != nullptr)
		{
			this->echipa2 = new char[strlen(m.echipa2) + 1];
			strcpy(this->echipa2, m.echipa2);
		}
		if (m.dataMeci != nullptr)
		{
			this->dataMeci = new char[strlen(m.dataMeci) + 1];
			strcpy(this->dataMeci, m.dataMeci);
		}
		if (m.oraMeci != nullptr)
		{
			this->oraMeci = new char[strlen(m.oraMeci) + 1];
			strcpy(this->oraMeci, m.oraMeci);
		}
		this->stadion = m.stadion;
		if (m.stadion.nrZone > 0)
		{
			this->preturi = new float[m.stadion.nrZone];
			this->spectatori = new long[m.stadion.nrZone];
			for (int i = 0; i < m.stadion.nrZone; i++)
			{
				this->preturi[i] = m.preturi[i];
				this->spectatori[i] = m.spectatori[i];
			}
		}
		else
		{
			this->preturi = m.preturi;
			this->spectatori = m.spectatori;
		}
	}
	//getteri si setteri
	int getIdMeci()
	{
		return this->idMeci;
	}
	char* getEchipa1()
	{
		char* copie;
		if (this->echipa1 != nullptr)
		{
			copie = new char[strlen(this->echipa1) + 1];
			strcpy(copie, this->echipa1);
		}
		else
			copie = nullptr;
		return copie;
	}
	void setEchipa1(const char* echipa1)
	{
		if (echipa1 != nullptr)
		{
			if (this->echipa1 != nullptr)
			{
				delete[]this->echipa1;
				this->echipa1 = nullptr;
			}
			this->echipa1 = new char[strlen(echipa1) + 1];
			strcpy(this->echipa1, echipa1);
		}
	}
	char* getEchipa2()
	{
		char* copie;
		if (this->echipa2 != nullptr)
		{
			copie = new char[strlen(this->echipa2) + 1];
			strcpy(copie, this->echipa2);
		}
		else
			copie = nullptr;
		return copie;
	}
	void setEchipa2(const char* echipa2)
	{
		if (echipa2 != nullptr)
		{
			if (this->echipa2 != nullptr)
			{
				delete[]this->echipa2;
				this->echipa2 = nullptr;
			}
			this->echipa2 = new char[strlen(echipa2) + 1];
			strcpy(this->echipa2, echipa2);
		}
	}
	char* getDataMeci()
	{
		char* copie;
		if (this->dataMeci != nullptr)
		{
			copie = new char[strlen(this->dataMeci) + 1];
			strcpy(copie, this->dataMeci);
		}
		else
			copie = nullptr;
		return copie;
	}
	void setDataMeci(const char* dataMeci)
	{
		if ((dataMeci[0] != '0' && dataMeci[0] != '1' && dataMeci[0] != '2' && dataMeci[0] != '3' && dataMeci[0] != '4' && dataMeci[0] != '5' &&
			dataMeci[0] != '6' && dataMeci[0] != '7' && dataMeci[0] != '8' && dataMeci[0] != '9') ||
			(dataMeci[1] != '0' && dataMeci[1] != '1' && dataMeci[1] != '2' && dataMeci[1] != '3' && dataMeci[1] != '4' && dataMeci[1] != '5' &&
				dataMeci[1] != '6' && dataMeci[1] != '7' && dataMeci[1] != '8' && dataMeci[1] != '9') || dataMeci[2] != '/' ||
			(dataMeci[3] != '0' && dataMeci[3] != '1' && dataMeci[3] != '2' && dataMeci[3] != '3' && dataMeci[3] != '4' && dataMeci[3] != '5' &&
				dataMeci[3] != '6' && dataMeci[3] != '7' && dataMeci[3] != '8' && dataMeci[3] != '9') ||
			(dataMeci[4] != '0' && dataMeci[4] != '1' && dataMeci[4] != '2' && dataMeci[4] != '3' && dataMeci[4] != '4' && dataMeci[4] != '5' &&
				dataMeci[4] != '6' && dataMeci[4] != '7' && dataMeci[4] != '8' && dataMeci[4] != '9') || dataMeci[5] != '/' ||
			(dataMeci[6] != '0' && dataMeci[6] != '1' && dataMeci[6] != '2' && dataMeci[6] != '3' && dataMeci[6] != '4' && dataMeci[6] != '5' &&
				dataMeci[6] != '6' && dataMeci[6] != '7' && dataMeci[6] != '8' && dataMeci[6] != '9') ||
			(dataMeci[7] != '0' && dataMeci[7] != '1' && dataMeci[7] != '2' && dataMeci[7] != '3' && dataMeci[7] != '4' && dataMeci[7] != '5' &&
				dataMeci[7] != '6' && dataMeci[7] != '7' && dataMeci[7] != '8' && dataMeci[7] != '9') ||
			(dataMeci[8] != '0' && dataMeci[8] != '1' && dataMeci[8] != '2' && dataMeci[8] != '3' && dataMeci[8] != '4' && dataMeci[8] != '5' &&
				dataMeci[8] != '6' && dataMeci[8] != '7' && dataMeci[8] != '8' && dataMeci[8] != '9') ||
			(dataMeci[9] != '0' && dataMeci[9] != '1' && dataMeci[9] != '2' && dataMeci[9] != '3' && dataMeci[9] != '4' && dataMeci[9] != '5' &&
				dataMeci[9] != '6' && dataMeci[9] != '7' && dataMeci[9] != '8' && dataMeci[9] != '9') || strlen(dataMeci) != 10)
			throw "Data noua care va seta nu respecta formatul (DD/MM/YYYY)";
		else if ((dataMeci[0] - '0') * 10 + (dataMeci[1] - '0') > 31 || (dataMeci[0] - '0') * 10 + (dataMeci[1] - '0') == 0 ||
			(dataMeci[3] - '0') * 10 + (dataMeci[4] - '0') == 0 || (dataMeci[3] - '0') * 10 + (dataMeci[4] - '0') > 12)
			throw"Data noua care va seta nu exista in calendar";
		if (dataMeci != nullptr)
		{
			if (this->dataMeci != nullptr)
			{
				delete[]this->dataMeci;
				this->dataMeci = nullptr;
			}
			this->dataMeci = new char[strlen(dataMeci) + 1];
			strcpy(this->dataMeci, dataMeci);
		}
	}
	char* getOraMeci()
	{
		char* copie;
		if (this->oraMeci != nullptr)
		{
			copie = new char[strlen(this->oraMeci) + 1];
			strcpy(copie, this->oraMeci);
		}
		else
			copie = nullptr;
		return copie;
	}
	void setOraMeci(const char* oraMeci)
	{
		if ((oraMeci[0] != '0' && oraMeci[0] != '1' && oraMeci[0] != '2' && oraMeci[0] != '3' && oraMeci[0] != '4' && oraMeci[0] != '5' &&
			oraMeci[0] != '6' && oraMeci[0] != '7' && oraMeci[0] != '8' && oraMeci[0] != '9') ||
			(oraMeci[1] != '0' && oraMeci[1] != '1' && oraMeci[1] != '2' && oraMeci[1] != '3' && oraMeci[1] != '4' && oraMeci[1] != '5' &&
				oraMeci[1] != '6' && oraMeci[1] != '7' && oraMeci[1] != '8' && oraMeci[1] != '9') || oraMeci[2] != ':' ||
			(oraMeci[3] != '0' && oraMeci[3] != '1' && oraMeci[3] != '2' && oraMeci[3] != '3' && oraMeci[3] != '4' && oraMeci[3] != '5' &&
				oraMeci[3] != '6' && oraMeci[3] != '7' && oraMeci[3] != '8' && oraMeci[3] != '9') ||
			(oraMeci[4] != '0' && oraMeci[4] != '1' && oraMeci[4] != '2' && oraMeci[4] != '3' && oraMeci[4] != '4' && oraMeci[4] != '5' &&
				oraMeci[4] != '6' && oraMeci[4] != '7' && oraMeci[4] != '8' && oraMeci[4] != '9') || strlen(oraMeci) != 5)
			throw "Ora noua care va seta nu respecta formatul (HH:HH)";
		else if ((oraMeci[0] - '0') * 10 + (oraMeci[1] - '0') > 23 || (oraMeci[3] - '0') * 10 + (oraMeci[4] - '0') > 59)
			throw "Ora noua care va seta nu exista pe ceas";
		if (oraMeci != nullptr)
		{
			if (this->oraMeci != nullptr)
			{
				delete[]this->oraMeci;
				this->oraMeci = nullptr;
			}
			this->oraMeci = new char[strlen(oraMeci) + 1];
			strcpy(this->oraMeci, oraMeci);
		}
	}
	Stadion& getStadion()
	{
		return this->stadion;
	}
	void setStadion(Stadion& stadion)
	{
		if (stadion.nrZone > 0)
		{
			this->stadion = stadion;
			if (this->spectatori != nullptr)
			{
				delete[]this->spectatori;
				this->spectatori = nullptr;
			}
			this->spectatori = new long[stadion.nrZone];
			for (int i = 0; i < stadion.nrZone; i++)
				this->spectatori[i] = 0;
			if (this->preturi != nullptr)
			{
				delete[]this->preturi;
				this->preturi = nullptr;
			}
			this->preturi = new float[stadion.nrZone];
		}
	}
	float* getPreturi()
	{
		float* copie;
		if (this->stadion.nrZone > 0)
		{
			copie = new float[this->stadion.nrZone];
			for (int i = 0; i < this->stadion.nrZone; i++)
				copie[i] = this->preturi[i];
		}
		else
			copie = this->preturi;
		return copie;
	}
	void setPreturi(float* preturi, int nr)
	{
		bool ok;
		if (nr > 0 && preturi != nullptr && nr == this->stadion.nrZone)
		{
			ok = true;
			for (int i = 0; i < nr; i++)
				if (preturi[i] < 0)
					ok = false;
			if (ok == true)
			{
				if (this->preturi != nullptr)
				{
					delete[]this->preturi;
					this->preturi = nullptr;
				}
				this->preturi = new float[nr];
				for (int i = 0; i < nr; i++)
					this->preturi[i] = preturi[i];
			}
		}
	}
	long* getSpectatori()
	{
		long* copie;
		if (this->stadion.nrZone > 0)
		{
			copie = new long[this->stadion.nrZone];
			for (int i = 0; i < this->stadion.nrZone; i++)
				copie[i] = this->spectatori[i];
		}
		else
			copie = this->spectatori;
		return copie;
	}
	void setSpectatori(long* spectatori, int nr)
	{
		bool ok;
		if (nr > 0 && nr == this->stadion.nrZone && spectatori != nullptr)
		{
			ok = true;
			for (int i = 0; i < nr; i++)
				if (spectatori[i] < 0)
					ok = false;
			if (ok == true)
			{
				ok = false;
				for (int i = 0; i < nr; i++)
					if (this->stadion.nrRanduriPerZona[i] * this->stadion.nrLocuriPerRandZona[i] >= spectatori[i])
						ok = true;
				if (ok == true)
				{
					if (this->spectatori != nullptr)
					{
						delete[]this->spectatori;
						this->spectatori = nullptr;
					}
					this->spectatori = new long[nr];
					for (int i = 0; i < nr; i++)
						this->spectatori[i] = spectatori[i];
				}
			}
		}

	}
	//alte functii
	static long nrTotalSpectatori(const Meci& m)
	{
		long spectatori = 0;
		for (int i = 0; i < m.stadion.nrZone; i++)
			spectatori = spectatori + m.spectatori[i];
		return spectatori;
	}
	static void nrBileteDisponibilePerZona(Meci& m)
	{
		for (int i = 0; i < m.stadion.nrZone; i++)
		{
			cout << "\nZona " << m.stadion.denumiriZone[i] << " mai are disponibile " << m.stadion.nrRanduriPerZona[i] * m.stadion.nrLocuriPerRandZona[i] - m.spectatori[i] << " bilete";

		}
	}
	static void modificareMeci(Meci& m, Stadion stadioane[50], int ctStadioane)
	{
		char* echipa;
		char* data;
		char* ora;
		bool buffer = false;
		int index;
		bool ok;
		char cuvant[255];
		int id;
		int aux;
		int nr;
		int pret;
		float* preturi;
		cout << "\nDoresti sa efectuezi mofidicari la meciul creat?";
		cout << "\nIata ce modificari poti face:" << endl << endl;
		while (buffer == false)
		{
			cout << "\n\nPentru a modifica numele echipei 1, apasa 1" << endl;
			cout << "Pentru a modifica numele echipei 2, apasa 2" << endl;
			cout << "Pentru a modifica data meciului, apasa 3" << endl;
			cout << "Pentru a modifica ora meciului, apasa 4" << endl;
			cout << "Pentru a da ora meciului inainte cu o ora, apara 5" << endl;
			cout << "Pentru a da ora meciului inapoi cu o ora, apasa 6" << endl;
			cout << "Pentru a modifica stadionul pe care se va juca meciul, apasa 7" << endl;
			cout << "Pentru a modifica un pret dintr-o anumita zona, apasa 8" << endl;
			cout << "Pentru a modifica toate preturile, apasa 9" << endl;
			cout << "Daca nu doresti sa efectuezi modificari, apasa 10" << endl;
			cout << "\nAlegerea ta este: ";
			ok = false;
			cin >> index;
			while (cin.good() == 0)
			{
				if (cin.bad())
					throw"IO stream corrupted";
				if (cin.fail())
				{
					cout << "\nInput gresit" << endl;
					cout << "Inputul trebuie sa fie un numar: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> index;
				}
			}
			while (ok == false)
			{
				if (index < 1 || index>10)
				{
					cout << "\nAlegerea ta nu corespunde niciunei instructiuni" << endl;
					cout << "Introdu un index valid: ";
					cin >> index;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> index;
						}
					}
				}
				else
					ok = true;
			}
			if (index == 1)
			{
				cout << "\nNumele nou al echipei 1 este: ";
				cin >> cuvant;
				echipa = new char[strlen(cuvant) + 1];
				strcpy(echipa, cuvant);
				m.setEchipa1(echipa);
				cout << m;
				delete[]echipa;
				echipa = nullptr;
			}
			if (index == 2)
			{
				cout << "\nNumele nou al echipei 2 este: ";
				cin >> cuvant;
				echipa = new char[strlen(cuvant) + 1];
				strcpy(echipa, cuvant);
				m.setEchipa2(echipa);
				cout << m;
				delete[]echipa;
				echipa = nullptr;
			}
			if (index == 3)
			{
				cout << "\nData noua in care se va desfasura meciul este: ";
				cin >> cuvant;
				ok = false;
				while (ok == false)
				{
					if ((cuvant[0] != '0' && cuvant[0] != '1' && cuvant[0] != '2' && cuvant[0] != '3' && cuvant[0] != '4' && cuvant[0] != '5' &&
						cuvant[0] != '6' && cuvant[0] != '7' && cuvant[0] != '8' && cuvant[0] != '9') ||
						(cuvant[1] != '0' && cuvant[1] != '1' && cuvant[1] != '2' && cuvant[1] != '3' && cuvant[1] != '4' && cuvant[1] != '5' &&
							cuvant[1] != '6' && cuvant[1] != '7' && cuvant[1] != '8' && cuvant[1] != '9') || cuvant[2] != '/' ||
						(cuvant[3] != '0' && cuvant[3] != '1' && cuvant[3] != '2' && cuvant[3] != '3' && cuvant[3] != '4' && cuvant[3] != '5' &&
							cuvant[3] != '6' && cuvant[3] != '7' && cuvant[3] != '8' && cuvant[3] != '9') ||
						(cuvant[4] != '0' && cuvant[4] != '1' && cuvant[4] != '2' && cuvant[4] != '3' && cuvant[4] != '4' && cuvant[4] != '5' &&
							cuvant[4] != '6' && cuvant[4] != '7' && cuvant[4] != '8' && cuvant[4] != '9') || cuvant[5] != '/' ||
						(cuvant[6] != '0' && cuvant[6] != '1' && cuvant[6] != '2' && cuvant[6] != '3' && cuvant[6] != '4' && cuvant[6] != '5' &&
							cuvant[6] != '6' && cuvant[6] != '7' && cuvant[6] != '8' && cuvant[6] != '9') ||
						(cuvant[7] != '0' && cuvant[7] != '1' && cuvant[7] != '2' && cuvant[7] != '3' && cuvant[7] != '4' && cuvant[7] != '5' &&
							cuvant[7] != '6' && cuvant[7] != '7' && cuvant[7] != '8' && cuvant[7] != '9') ||
						(cuvant[8] != '0' && cuvant[8] != '1' && cuvant[8] != '2' && cuvant[8] != '3' && cuvant[8] != '4' && cuvant[8] != '5' &&
							cuvant[8] != '6' && cuvant[8] != '7' && cuvant[8] != '8' && cuvant[8] != '9') ||
						(cuvant[9] != '0' && cuvant[9] != '1' && cuvant[9] != '2' && cuvant[9] != '3' && cuvant[9] != '4' && cuvant[9] != '5' &&
							cuvant[9] != '6' && cuvant[9] != '7' && cuvant[9] != '8' && cuvant[9] != '9'))
					{
						cout << "\nData nu respecta formatul DD/MM/YYYY" << endl;
						cout << "Introdu un format de data de tipul (DD/MM/YYYY): ";
						cin >> cuvant;
					}
					else if ((cuvant[0] - '0') * 10 + (cuvant[1] - '0') > 31 || (cuvant[0] - '0') * 10 + (cuvant[1] - '0') == 0 ||
						(cuvant[3] - '0') * 10 + (cuvant[4] - '0') == 0 || (cuvant[3] - '0') * 10 + (cuvant[4] - '0') > 12)
					{
						cout << "\nNu exista o data cu acel numar de zile sau luni" << endl;
						cout << "Introdu o data valida: ";
						cin >> cuvant;
					}
					else
						ok = true;
				}
				data = new char[strlen(cuvant) + 1];
				strcpy(data, cuvant);
				m.setDataMeci(data);
				cout << m;
				delete[]data;
				data = nullptr;
			}
			if (index == 4)
			{
				cout << "\nOra noua la care se va desfasura meciul este: ";
				cin >> cuvant;
				ok = false;
				while (ok == false)
				{
					if ((cuvant[0] != '0' && cuvant[0] != '1' && cuvant[0] != '2' && cuvant[0] != '3' && cuvant[0] != '4' && cuvant[0] != '5' &&
						cuvant[0] != '6' && cuvant[0] != '7' && cuvant[0] != '8' && cuvant[0] != '9') ||
						(cuvant[1] != '0' && cuvant[1] != '1' && cuvant[1] != '2' && cuvant[1] != '3' && cuvant[1] != '4' && cuvant[1] != '5' &&
							cuvant[1] != '6' && cuvant[1] != '7' && cuvant[1] != '8' && cuvant[1] != '9') || cuvant[2] != ':' ||
						(cuvant[3] != '0' && cuvant[3] != '1' && cuvant[3] != '2' && cuvant[3] != '3' && cuvant[3] != '4' && cuvant[3] != '5' &&
							cuvant[3] != '6' && cuvant[3] != '7' && cuvant[3] != '8' && cuvant[3] != '9') ||
						(cuvant[4] != '0' && cuvant[4] != '1' && cuvant[4] != '2' && cuvant[4] != '3' && cuvant[4] != '4' && cuvant[4] != '5' &&
							cuvant[4] != '6' && cuvant[4] != '7' && cuvant[4] != '8' && cuvant[4] != '9'))
					{
						cout << "\nOra nu respecta formatul (HH:HH)" << endl;
						cout << "Introdu o ora de tipul (HH:HH): ";
						cin >> cuvant;
					}
					else if ((cuvant[0] - '0') * 10 + (cuvant[1] - '0') > 23 || (cuvant[3] - '0') * 10 + (cuvant[4] - '0') > 59)
					{
						cout << "\nNu exista ora cu datele aferente" << endl;
						cout << "Introdu o ora care exista pe ceas: ";
						cin >> cuvant;
					}
					else
						ok = true;
				}
				ora = new char[strlen(cuvant) + 1];
				strcpy(ora, cuvant);
				m.setOraMeci(ora);
				cout << m;
				delete[]ora;
				ora = nullptr;
			}
			if (index == 5)
			{
				m = ++m;
				cout << m;
			}
			if (index == 6)
			{
				m = --m;
				cout << m;
			}
			if (index == 7)
			{
				cout << "\nLista stadioanelor construite sunt:" << endl << endl;
				for (int i = 0; i < ctStadioane; i++)
					cout << stadioane[i].getNumeStadion() << " cu id-ul " << stadioane[i].getIdStadion() << endl;
				cout << "\nPentru a alege un stadion nou, introdu id-ul acestuia: ";
				cin >> id;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> id;
					}
				}
				ok = false;
				while (ok == false)
				{
					for (int i = 0; i < ctStadioane; i++)
						if (stadioane[i].getIdStadion() == id)
						{
							aux = i;
							ok = true;
							i = ctStadioane;
						}
					if (ok == false)
					{
						cout << "\nId-ul introdus de tine nu exista" << endl;
						cout << "\nIntrodu un id care exista: ";
						cin >> id;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> id;
							}
						}
					}
				}
				m.setStadion(stadioane[aux]);
				cout << "\nPentru ca ai modificat stadionul, trebuiesc modificate si preturile in fuctie de zonele disponibile ale noului stadion" << endl;
				preturi = new float[stadioane[aux].getNrZone()];
				for (int i = 0; i < stadioane[aux].getNrZone(); i++)
				{
					cout << "\nPretul pentru zona " << stadioane[aux].getDenumiriZone()[i] << " este: ";
					ok = false;
					cin >> preturi[i];
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> preturi[i];
						}
					}
					while (ok == false)
					{
						if (preturi[i] <= 0)
						{
							cout << "\nPretul nu poate fi negativ sau nul" << endl;
							cout << "Introdu un pret valid: ";
							cin >> preturi[i];
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> preturi[i];
								}
							}
						}
						else
							ok = true;
					}
				}
				m.setPreturi(preturi, stadioane[aux].getNrZone());
				cout << m;
				delete[]preturi;
				preturi = nullptr;
			}
			if (index == 8)
			{
				cout << "\nZonele sunt: " << endl;
				for (int i = 0; i < (m.getStadion()).getNrZone(); i++)
				{
					cout << "Zona " << i + 1 << " se numeste " << (m.getStadion()).getDenumiriZone()[i] << endl;
				}
				cout << "\nIntrodu numarul zonei careia vrei sa ii schimbi pretul: ";
				cin >> nr;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> nr;
					}
				}
				nr = nr--;
				ok = false;
				while (ok == false)
				{
					if (nr<0 || nr>(m.getStadion()).getNrZone())
					{
						cout << "\nNu exista nicio zona cu numarul introdus de tine" << endl;
						cout << "Introdu un numar de zona valid: ";
						cin >> nr;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> nr;
							}
						}
						nr = nr--;
					}
					else
						ok = true;
				}
				preturi = new float[(m.getStadion()).getNrZone()];
				preturi = m.getPreturi();
				cout << "\nPretul nou pentru zona " << (m.getStadion()).getDenumiriZone()[nr] << " este: ";
				cin >> pret;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> pret;
					}
				}
				ok = false;
				while (ok == false)
				{
					if (pret <= 0)
					{
						cout << "\nPretul nu poate fi negativ sau nul" << endl;
						cout << "Introdu un pret valid: ";
						cin >> pret;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> pret;
							}
						}
					}
					else
						ok = true;
				}
				preturi[nr] = pret;
				m.setPreturi(preturi, (m.getStadion()).getNrZone());
				cout << m;
				delete[]preturi;
				preturi = nullptr;
			}
			if (index == 9)
			{
				cout << "\nPreturile noi pentru zonele stadionului sunt: " << endl;
				preturi = new float[(m.getStadion()).getNrZone()];
				for (int i = 0; i < (m.getStadion()).getNrZone(); i++)
				{
					cout << "\nPretul pentru zona " << (m.getStadion()).getDenumiriZone()[i] << " este: ";
					ok = false;
					cin >> preturi[i];
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> preturi[i];
						}
					}
					while (ok == false)
					{
						if (preturi[i] <= 0)
						{
							cout << "\nPretul nu poate fi negativ sau nul" << endl;
							cout << "Introdu un pret valid: ";
							cin >> preturi[i];
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> preturi[i];
								}
							}
						}
						else
							ok = true;
					}
				}
				m.setPreturi(preturi, (m.getStadion()).getNrZone());
				cout << m;
				delete[]preturi;
				preturi = nullptr;
			}
			if (index == 10)
			{
				buffer = true;
			}
		}
	}
	//operator =
	Meci& operator=(const Meci& m)
	{
		if (this != &m)
		{
			if (m.echipa1 != nullptr)
			{
				if (this->echipa1 != nullptr)
				{
					delete[]this->echipa1;
					this->echipa1 = nullptr;
				}
				this->echipa1 = new char[strlen(m.echipa1) + 1];
				strcpy(this->echipa1, m.echipa1);
			}
			else
			{
				if (this->echipa1 != nullptr)
				{
					delete[]this->echipa1;
					this->echipa1 = nullptr;
				}
			}
			if (m.echipa2 != nullptr)
			{
				if (this->echipa2 != nullptr)
				{
					delete[]this->echipa2;
					this->echipa2 = nullptr;
				}
				this->echipa2 = new char[strlen(m.echipa2) + 1];
				strcpy(this->echipa2, m.echipa2);
			}
			else
			{
				if (this->echipa2 != nullptr)
				{
					delete[]this->echipa2;
					this->echipa2 = nullptr;
				}
			}
			if (m.dataMeci != nullptr)
			{
				if (this->dataMeci != nullptr)
				{
					delete[]this->dataMeci;
					this->dataMeci = nullptr;
				}
				this->dataMeci = new char[strlen(m.dataMeci) + 1];
				strcpy(this->dataMeci, m.dataMeci);
			}
			else
			{
				if (this->dataMeci != nullptr)
				{
					delete[]this->dataMeci;
					this->dataMeci = nullptr;
				}
			}
			if (m.oraMeci != nullptr)
			{
				if (this->oraMeci != nullptr)
				{
					delete[]this->oraMeci;
					this->oraMeci = nullptr;
				}
				this->oraMeci = new char[strlen(m.oraMeci) + 1];
				strcpy(this->oraMeci, m.oraMeci);
			}
			else
			{
				if (this->oraMeci != nullptr)
				{
					delete[]this->oraMeci;
					this->oraMeci = nullptr;
				}
			}
			this->stadion = m.stadion;
			if (m.preturi != nullptr && m.stadion.nrZone > 0)
			{
				if (this->preturi != nullptr)
				{
					delete[]this->preturi;
					this->preturi = nullptr;
				}
				this->preturi = new float[m.stadion.nrZone];
				for (int i = 0; i < m.stadion.nrZone; i++)
					this->preturi[i] = m.preturi[i];
			}
			else
			{
				if (this->preturi != nullptr)
				{
					delete[]this->preturi;
					this->preturi = nullptr;
				}
			}
			if (m.spectatori != nullptr && m.stadion.nrZone > 0)
			{
				if (this->spectatori != nullptr)
				{
					delete[]this->spectatori;
					this->spectatori = nullptr;
				}
				this->spectatori = new long[m.stadion.nrZone];
				for (int i = 0; i < m.stadion.nrZone; i++)
					this->spectatori[i] = m.spectatori[i];
			}
			else
			{
				if (this->spectatori != nullptr)
				{
					delete[]this->spectatori;
					this->spectatori = nullptr;
				}
			}
		}
		return *this;
	}
	//Preincrementare
	const Meci operator++()
	{
		int ora = (this->oraMeci[0] - '0') * 10 + (this->oraMeci[1] - '0');
		if (ora == 23)
			ora = 0;
		else
			ora++;
		if (ora >= 0 && ora <= 9)
		{
			this->oraMeci[0] = '0';
			this->oraMeci[1] = ora + '0';
		}
		else
		{
			this->oraMeci[0] = (ora / 10) + '0';
			this->oraMeci[1] = (ora % 10) + '0';
		}
		return *this;
	}
	//Postincrementare
	const Meci operator++(int i)
	{
		Meci copie = *this;
		int ora = (this->oraMeci[0] - '0') * 10 + (this->oraMeci[1] - '0');
		if (ora == 23)
			ora = 0;
		else
			ora++;
		if (ora >= 0 && ora <= 9)
		{
			this->oraMeci[0] = '0';
			this->oraMeci[1] = ora + '0';
		}
		else
		{
			this->oraMeci[0] = (ora / 10) + '0';
			this->oraMeci[1] = (ora % 10) + '0';
		}
		return copie;
	}
	//Predecrementare
	const Meci operator--()
	{
		int ora = (this->oraMeci[0] - '0') * 10 + (this->oraMeci[1] - '0');
		if (ora == 0)
			ora = 23;
		else
			ora--;
		if (ora >= 0 && ora <= 9)
		{
			this->oraMeci[0] = '0';
			this->oraMeci[1] = ora + '0';
		}
		else
		{
			this->oraMeci[0] = (ora / 10) + '0';
			this->oraMeci[1] = (ora % 10) + '0';
		}
		return *this;
	}

	//Postdecrementare
	const Meci operator--(int i)
	{
		Meci copie = *this;
		int ora = (this->oraMeci[0] - '0') * 10 + (this->oraMeci[1] - '0');
		if (ora == 0)
			ora = 23;
		else
			ora--;
		if (ora >= 0 && ora <= 9)
		{
			this->oraMeci[0] = '0';
			this->oraMeci[1] = ora + '0';
		}
		else
		{
			this->oraMeci[0] = (ora / 10) + '0';
			this->oraMeci[1] = (ora % 10) + '0';
		}
		return copie;
	}
	bool operator==(const Meci& m)
	{
		if (strcmp(this->echipa1, m.echipa1) != 0)
			return 0;
		if (strcmp(this->echipa2, m.echipa2) != 0)
			return 0;
		if (strcmp(this->dataMeci, m.dataMeci) != 0)
			return 0;
		if (strcmp(this->oraMeci, m.oraMeci) != 0)
			return 0;
		for (int i = 0; i < m.stadion.nrZone; i++)
			if (this->preturi[i] != m.preturi[i])
				return 0;
		if (this->stadion == m.stadion)
			return 1;
	}
	//destructor
	~Meci()
	{
		if (this->echipa1 != nullptr)
		{
			delete[]this->echipa1;
			this->echipa1 = nullptr;
		}
		if (this->echipa2 != nullptr)
		{
			delete[]this->echipa2;
			this->echipa2 = nullptr;
		}
		if (this->dataMeci != nullptr)
		{
			delete[]this->dataMeci;
			this->dataMeci = nullptr;
		}
		if (this->oraMeci != nullptr)
		{
			delete[]this->oraMeci;
			this->oraMeci = nullptr;
		}
		if (this->preturi != nullptr)
		{
			delete[]this->preturi;
			this->preturi = nullptr;
		}
		if (this->spectatori != nullptr)
		{
			delete[]this->spectatori;
			this->spectatori = nullptr;
		}
		this->stadion.~Stadion();
	}
	//citire si afisare
	friend istream& operator>>(istream& in, Meci& m);
	friend ostream& operator<<(ostream& out, Meci& m);
	friend class Bilet;
};
int Meci::idm = 100;
istream& operator>>(istream& in, Meci& m)
{
	cout << "\n\nMeciuri are urmatoarele detalii:";
	char buffer[255];
	cout << "\nEchipa1 se numeste: ";
	in >> buffer;
	if (m.echipa1 != nullptr)
	{
		delete[]m.echipa1;
		m.echipa1 = nullptr;
	}
	m.echipa1 = new char[strlen(buffer) + 1];
	strcpy(m.echipa1, buffer);
	cout << "\nEchipa2 se numeste: ";
	in >> buffer;
	if (m.echipa2 != nullptr)
	{
		delete[]m.echipa2;
		m.echipa2 = nullptr;
	}
	m.echipa2 = new char[strlen(buffer) + 1];
	strcpy(m.echipa2, buffer);
	cout << "\nData in care se desfasoara meciul este (DD/MM/YYYY) :";
	bool ok = false;
	in >> buffer;
	while (ok == false)
	{
		if ((buffer[0] != '0' && buffer[0] != '1' && buffer[0] != '2' && buffer[0] != '3' && buffer[0] != '4' && buffer[0] != '5' &&
			buffer[0] != '6' && buffer[0] != '7' && buffer[0] != '8' && buffer[0] != '9') ||
			(buffer[1] != '0' && buffer[1] != '1' && buffer[1] != '2' && buffer[1] != '3' && buffer[1] != '4' && buffer[1] != '5' &&
				buffer[1] != '6' && buffer[1] != '7' && buffer[1] != '8' && buffer[1] != '9') || buffer[2] != '/' ||
			(buffer[3] != '0' && buffer[3] != '1' && buffer[3] != '2' && buffer[3] != '3' && buffer[3] != '4' && buffer[3] != '5' &&
				buffer[3] != '6' && buffer[3] != '7' && buffer[3] != '8' && buffer[3] != '9') ||
			(buffer[4] != '0' && buffer[4] != '1' && buffer[4] != '2' && buffer[4] != '3' && buffer[4] != '4' && buffer[4] != '5' &&
				buffer[4] != '6' && buffer[4] != '7' && buffer[4] != '8' && buffer[4] != '9') || buffer[5] != '/' ||
			(buffer[6] != '0' && buffer[6] != '1' && buffer[6] != '2' && buffer[6] != '3' && buffer[6] != '4' && buffer[6] != '5' &&
				buffer[6] != '6' && buffer[6] != '7' && buffer[6] != '8' && buffer[6] != '9') ||
			(buffer[7] != '0' && buffer[7] != '1' && buffer[7] != '2' && buffer[7] != '3' && buffer[7] != '4' && buffer[7] != '5' &&
				buffer[7] != '6' && buffer[7] != '7' && buffer[7] != '8' && buffer[7] != '9') ||
			(buffer[8] != '0' && buffer[8] != '1' && buffer[8] != '2' && buffer[8] != '3' && buffer[8] != '4' && buffer[8] != '5' &&
				buffer[8] != '6' && buffer[8] != '7' && buffer[8] != '8' && buffer[8] != '9') ||
			(buffer[9] != '0' && buffer[9] != '1' && buffer[9] != '2' && buffer[9] != '3' && buffer[9] != '4' && buffer[9] != '5' &&
				buffer[9] != '6' && buffer[9] != '7' && buffer[9] != '8' && buffer[9] != '9'))
		{
			cout << "\nData nu respecta formatul DD/MM/YYYY" << endl;
			cout << "Introdu un format de data de tipul (DD/MM/YYYY): ";
			in >> buffer;
		}
		else if ((buffer[0] - '0') * 10 + (buffer[1] - '0') > 31 || (buffer[0] - '0') * 10 + (buffer[1] - '0') == 0 ||
			(buffer[3] - '0') * 10 + (buffer[4] - '0') == 0 || (buffer[3] - '0') * 10 + (buffer[4] - '0') > 12)
		{
			cout << "\nNu exista o data cu acel numar de zile sau luni" << endl;
			cout << "Introdu o data valida: ";
			in >> buffer;
		}
		else
			ok = true;
	}
	if (m.dataMeci != nullptr)
	{
		delete[]m.dataMeci;
		m.dataMeci = nullptr;
	}
	m.dataMeci = new char[strlen(buffer) + 1];
	strcpy(m.dataMeci, buffer);
	cout << "\nOra la care se desfasoara meciul este (HH:HH) : ";
	ok = false;
	in >> buffer;
	while (ok == false)
	{
		if ((buffer[0] != '0' && buffer[0] != '1' && buffer[0] != '2' && buffer[0] != '3' && buffer[0] != '4' && buffer[0] != '5' &&
			buffer[0] != '6' && buffer[0] != '7' && buffer[0] != '8' && buffer[0] != '9') ||
			(buffer[1] != '0' && buffer[1] != '1' && buffer[1] != '2' && buffer[1] != '3' && buffer[1] != '4' && buffer[1] != '5' &&
				buffer[1] != '6' && buffer[1] != '7' && buffer[1] != '8' && buffer[1] != '9') || buffer[2] != ':' ||
			(buffer[3] != '0' && buffer[3] != '1' && buffer[3] != '2' && buffer[3] != '3' && buffer[3] != '4' && buffer[3] != '5' &&
				buffer[3] != '6' && buffer[3] != '7' && buffer[3] != '8' && buffer[3] != '9') ||
			(buffer[4] != '0' && buffer[4] != '1' && buffer[4] != '2' && buffer[4] != '3' && buffer[4] != '4' && buffer[4] != '5' &&
				buffer[4] != '6' && buffer[4] != '7' && buffer[4] != '8' && buffer[4] != '9'))
		{
			cout << "\nOra nu respecta formatul (HH:HH)" << endl;
			cout << "Introdu o ora de tipul (HH:HH): ";
			in >> buffer;
		}
		else if ((buffer[0] - '0') * 10 + (buffer[1] - '0') > 23 || (buffer[3] - '0') * 10 + (buffer[4] - '0') > 59)
		{
			cout << "\nNu exista ora cu datele aferente" << endl;
			cout << "Introdu o ora care exista pe ceas: ";
			in >> buffer;
		}
		else
			ok = true;
	}
	if (m.oraMeci != nullptr)
	{
		delete[]m.oraMeci;
		m.oraMeci = nullptr;
	}
	m.oraMeci = new char[strlen(buffer) + 1];
	strcpy(m.oraMeci, buffer);
	return in;
}
ostream& operator<<(ostream& out, Meci& m)
{
	out << "\n\nIata detaliile meciului creat de tine" << endl;
	out << "\nId-ul meciului este: " << m.idMeci;
	if (m.echipa1 != nullptr)
		out << "\nEchipa 1 se numeste " << m.echipa1;
	else
		out << "\nEchipa 1 este anonima.";
	if (m.echipa2 != nullptr)
		out << "\nEchipa 2 se numeste " << m.echipa2;
	else
		out << "\nEchipa 2 este anonima.";
	if (m.dataMeci != nullptr)
		out << "\nData in care se va desfasura meciul este " << m.dataMeci;
	else
		out << "\nData in care se va desfasura meciul este nula";
	if (m.oraMeci != nullptr)
		out << "\nOra la care se va desfasura meciul este " << m.oraMeci;
	else
		out << "\nOra la care se va desfasura meciul este nula";
	if (m.stadion.getNrZone() == 0)
		out << "\nMeciul dintre " << m.echipa1 << " si " << m.echipa2 << " nu are un stadion pentru a se putea juca.";
	else
	{
		out << "\nMeciul dintre " << m.echipa1 << " si " << m.echipa2 << " se va juca pe stadionul cu urmatoarele detalii";
		out << m.stadion;
		if (m.preturi != nullptr)
		{
			out << "\nPreturile meciului pentru fiecare zona sunt:" << endl;
			for (int i = 0; i < m.stadion.getNrZone(); i++)
				out << "Pentru zona " << m.stadion.getDenumiriZone()[i] << " pretul este de " << m.preturi[i] << " lei" << endl;
		}
		else
			out << "\nMeciul inca nu are preturile setate";
		if (m.spectatori != nullptr)
		{
			out << "\nZonele stadionului au urmatorul numar de suporteri" << endl;
			for (int i = 0; i < m.stadion.getNrZone(); i++)
				out << "Zona " << m.stadion.getDenumiriZone()[i] << " are " << m.spectatori[i] << " suporteri" << endl;
		}
		else
			out << "\nPentru acest meci nu sunt suporteri";
		Meci::nrBileteDisponibilePerZona(m);
	}
	out << "\n\n\n";
	return out;
}


class iSuporter
{
public:
	virtual void echipaSustinuta() = 0;
};

class Bilet:public iSuporter
{
private:
	const long idBilet;
	char* nume;
	char* prenume;
	Meci meci;
	char* zonaStadion;
	float pretBilet;
	char* echipa;
	static long idb;
public:
	Bilet() :idBilet(idb)
	{
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->prenume = new char[strlen("Necunoscut") + 1];
		strcpy(this->prenume, "Necunoscut");
		this->zonaStadion = new char[strlen("N/A") + 1];
		strcpy(this->zonaStadion, "N/A");
		this->pretBilet = 0;
		this->echipa = nullptr;
		idb = idb + 12345;
	}
	Bilet(const char* nume, const char* prenume):idBilet(idb)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);
		this->zonaStadion = new char[strlen("N/A") + 1];
		strcpy(this->zonaStadion, "N/A");
		this->pretBilet = 0;
		this->echipa = nullptr;
		idb = idb + 12345;
	}
	Bilet(const char* nume, const char* prenume, Meci meci, const char* zonaStadion, const char* echipa) :idBilet(idb)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->prenume = new char[strlen(prenume) + 1];
		strcpy(this->prenume, prenume);
		this->meci = meci;
		bool ok = false;
		int aux;
		for (int i = 0; i < meci.stadion.getNrZone(); i++)
			if (strcmp(meci.stadion.getDenumiriZone()[i].c_str(), zonaStadion) == 0)
			{
				aux = i;
				ok = true;
				i = meci.stadion.getNrZone();
			}
		if (ok == true)
		{
			this->zonaStadion = new char[strlen(zonaStadion) + 1];
			strcpy(this->zonaStadion, zonaStadion);
			this->pretBilet = meci.preturi[aux];
		}
		else
		{
			this->zonaStadion = nullptr;
			this->pretBilet = 0;
			throw"Zona introdusa nu se regaseste in zonele stadionului unde se joaca meciul";
		}
		this->echipa = new char[strlen(echipa) + 1];
		strcpy(this->echipa, echipa);
		idb = idb + 12345;
	}
	Bilet(const Bilet& b) :idBilet(b.idBilet)
	{
		this->nume = new char[strlen(b.nume) + 1];
		strcpy(this->nume, b.nume);
		this->prenume = new char[strlen(b.prenume) + 1];
		strcpy(this->prenume, b.prenume);
		this->meci = b.meci;
		this->zonaStadion = new char[strlen(b.zonaStadion) + 1];
		strcpy(this->zonaStadion, b.zonaStadion);
		this->pretBilet = b.pretBilet;
		this->echipa = new char[strlen(b.echipa) + 1];
		strcpy(this->echipa, b.echipa);
	}
	Bilet& operator=(const Bilet& b)
	{
		if (this != &b)
		{
			if (this->nume != nullptr)
			{
				delete[]this->nume;
				this->nume = nullptr;
			}
			this->nume = new char[strlen(b.nume) + 1];
			strcpy(this->nume, b.nume);
			if (this->prenume != nullptr)
			{
				delete[]this->prenume;
				this->prenume = nullptr;
			}
			this->prenume = new char[strlen(b.prenume) + 1];
			strcpy(this->prenume, b.prenume);
			this->meci = b.meci;
			if (this->zonaStadion != nullptr)
			{
				delete[]this->zonaStadion;
				this->zonaStadion = nullptr;
			}
			this->zonaStadion = new char[strlen(b.zonaStadion) + 1];
			strcpy(this->zonaStadion, b.zonaStadion);
			this->pretBilet = b.pretBilet;
			if (this->echipa != nullptr)
			{
				delete[]this->echipa;
				this->echipa = nullptr;
			}
			this->echipa = new char[strlen(b.echipa) + 1];
			strcpy(this->echipa, b.echipa);
		}
		return *this;
	}
	long getIdBilet()
	{
		return this->idBilet;
	}
	char* getNume()
	{
		char* copie;
		if (this->nume != nullptr)
		{
			copie = new char[strlen(this->nume) + 1];
			strcpy(copie, this->nume);
		}
		else
			copie = this->nume;
		return copie;
	}
	void setNume(const char* nume)
	{
		if (nume != nullptr)
		{
			if (this->nume != nullptr)
			{
				delete[]this->nume;
				this->nume = nullptr;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
			throw"Numele care va seta nu poate fi nul";
	}
	char* getPremume()
	{
		char* copie;
		if (this->prenume != nullptr)
		{
			copie = new char[strlen(this->prenume) + 1];
			strcpy(copie, this->prenume);
		}
		else
			copie = this->prenume;
		return copie;
	}
	void setPrenume(const char* prenume)
	{
		if (prenume != nullptr)
		{
			if (this->prenume != nullptr)
			{
				delete[]this->prenume;
				this->prenume = nullptr;
			}
			this->prenume = new char[strlen(prenume) + 1];
			strcpy(this->prenume, prenume);
		}
		else
			throw"Prenumele care va seta nu poate fi nul";
	}
	Meci getMeci()
	{
		return this->meci;
	}
	void setMeci(Meci& m)
	{
		this->meci = m;
	}
	char* getZonaStadion()
	{
		char* copie;
		if (this->zonaStadion != nullptr)
		{
			copie = new char[strlen(this->zonaStadion) + 1];
			strcpy(copie, this->zonaStadion);
		}
		else
			copie = this->zonaStadion;
		return copie;
	}
	float getPretBilet()
	{
		return this->pretBilet;
	}
	void setZonaStadion(const char*zona)
	{
		if (zona != nullptr)
		{
			if (this->zonaStadion != nullptr)
			{
				delete[]this->zonaStadion;
				this->zonaStadion = nullptr;
			}
			this->zonaStadion = new char[strlen(zona) + 1];
			strcpy(this->zonaStadion, zona);
		}
		else
			throw"Zona care va seta nu poate fi nula";
	}
	void setPret(float p)
	{
		if (p >= 0)
		{
			this->pretBilet = p;
		}
		else
			throw"Pretul care va seta nu poate fi negativ";
	}
	void setZonaStadionSiPretBilet(const char* zonaStadion)
	{
		bool ok = false;
		int aux;
		for (int i = 0; i < this->meci.stadion.getNrZone(); i++)
			if (strcmp(this->meci.stadion.getDenumiriZone()[i].c_str(), zonaStadion) == 0)
			{
				aux = i;
				ok = true;
				i = this->meci.stadion.getNrZone();
			}
		if (ok == true)
		{
			this->zonaStadion = new char[strlen(zonaStadion) + 1];
			strcpy(this->zonaStadion, zonaStadion);
			this->pretBilet = meci.preturi[aux];
		}
		else
			throw"Pentru a seta un nou pret pe bilet, trebuie introdusa o zona noua care se regaseste in stadion";
	}
	char* getEchipaSustinuta()
	{
		char* copie = new char[strlen(this->echipa) + 1];
		strcpy(copie, this->echipa);
		return copie;
	}
	void setEchipaSustinuta(const char* echipa)
	{
		if (echipa != nullptr)
		{
			if (this->echipa != nullptr)
			{
				delete[]this->echipa;
				this->echipa = nullptr;
			}
			this->echipa = new char[strlen(echipa) + 1];
			strcpy(this->echipa, echipa);
		}
		else
			throw"Echipa sustinuta care va seta nu poate fi nula";
	}
	//alte functii
	void echipaSustinuta() override
	{
		int index;
		bool ok;
		cout << "\nAlege echipa pe care vrei sa o sustii" << endl;
		cout << "Pentru a alege echipa " << this->meci.getEchipa1() << " apasa 1" << endl;
		cout << "Pentru a alege echipa " << this->meci.getEchipa2() << " apasa 2" << endl;
		cout << "\nAlegerea ta este: ";
		cin >> index;
		while (cin.good() == 0)
		{
			if (cin.bad())
				throw"IO stream corrupted";
			if (cin.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> index;
			}
		}
		ok = false;
		while (ok == false)
		{
			if (index < 1 || index>2)
			{
				cout << "\nAlegerea ta nu corespunde niciunei variante de mai sus" << endl;
				cout << "Introdu un index valid: ";
				cin >> index;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
			}
			else
				ok = true;
		}
		if (index == 1)
		{
			if (this->echipa != nullptr)
			{
				delete[]this->echipa;
				this->echipa = nullptr;
			}
			this->echipa = new char[strlen(this->meci.getEchipa1()) + 1];
			strcpy(this->echipa, this->meci.getEchipa1());
		}
		else if (index == 2)
		{
			if (this->echipa != nullptr)
			{
				delete[]this->echipa;
				this->echipa = nullptr;
			}
			this->echipa = new char[strlen(this->meci.getEchipa2()) + 1];
			strcpy(this->echipa, this->meci.getEchipa2());
		}
	}


	static void modificariBilet(Bilet& b, Meci meciuri[100], int ctMeciuri)
	{
		bool buffer;
		int index;
		char* nume;
		char cuvant[255];
		cout << "\nDoresti sa efectuezi modificari asupra biletului?";
		buffer = false;
		bool ok;
		long* spectatori;
		int aux;
		int id;
		string zona;
		int ind;
		char** zone;
		int indexMeciInitial;
		int indexMeciFinal;
		int indexZona;
		float cupon;
		int ctCupon = 0;
		int ind1;
		while (buffer == false)
		{
			cout << "\nIata ce modificari poti face: " << endl << endl;
			cout << "Daca doresti sa schimbi numele, apasa 1" << endl;
			cout << "Daca doresti sa schimbi prenumele, apasa 2" << endl;
			cout << "Daca doresti sa schimbi meciul la care vrei sa te uiti, apasa 3" << endl;
			cout << "Daca doresti sa doresti sa schimbi zona din stadion unde doresti sa stai, apasa 4" << endl;
			cout << "Daca ai un cupon de reducere pe care vrei sa-l folosesti, apasa 5" << endl;
			cout << "Daca doresti sa modifici echipa sustinuta, apasa 6" << endl;
			cout << "Daca nu doresti sa efectuezi modificari, apasa 7" << endl;
			cout << "\nAlegerea ta este: ";
			cin >> index;
			while (cin.good() == 0)
			{
				if (cin.bad())
					throw"IO stream corrupted";
				if (cin.fail())
				{
					cout << "\nInput gresit" << endl;
					cout << "Inputul trebuie sa fie un numar: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> index;
				}
			}
			ok = false;
			while (ok == false)
			{
				if (index < 1 || index>7)
				{
					cout << "\nNu exista nicio varinata corespunzatoare alegerii tale" << endl;
					cout << "Introdu un index valid: ";
					cin >> index;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> index;
						}
					}
				}
				else
					ok = true;
			}
			if (index == 1)
			{
				cout << "\nNumele nou este: ";
				cin >> cuvant;
				nume = new char[strlen(cuvant) + 1];
				strcpy(nume, cuvant);
				b.setNume(nume);
				cout << b;
				delete[]nume;
				nume = nullptr;
			}
			if (index == 2)
			{
				cout << "\nPrenumele nou este: ";
				cin >> cuvant;
				nume = new char[strlen(cuvant) + 1];
				strcpy(nume, cuvant);
				b.setPrenume(nume);
				cout << b;
				delete[]nume;
				nume = nullptr;
			}
			if (index == 3)
			{
				for (int i = 0; i < ctMeciuri; i++)
					if (meciuri[i] == b.getMeci())
					{
						indexMeciInitial = i;
						i = ctMeciuri;
					}
				spectatori = new long[(meciuri[indexMeciInitial].getStadion()).getNrZone()];
				for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
					spectatori[i] = (b.getMeci()).getSpectatori()[i];
				for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
					if ((string)b == (meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[i])
					{
						indexZona = i;
						i = (meciuri[indexMeciInitial].getStadion()).getNrZone();
					}
				spectatori[indexZona]--;
				meciuri[indexMeciInitial].setSpectatori(spectatori, (meciuri[indexMeciInitial].getStadion()).getNrZone());
				cout << "\nAlege meciul la care vrei sa te uiti" << endl;
				cout << "Meciurile sunt: " << endl;
				for (int i = 0; i < ctMeciuri; i++)
					cout << meciuri[i].getEchipa1() << " vs " << meciuri[i].getEchipa2() << " din data " << meciuri[i].getDataMeci() << " de la ora " << meciuri[i].getOraMeci() << " cu id-ul " << meciuri[i].getIdMeci() << endl;
				cout << "\nIntrodu id-ul meciului la care vrei sa te uiti: ";
				ok = false;
				cin >> id;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> id;
					}
				}
				while (ok == false)
				{
					for (int i = 0; i < ctMeciuri; i++)
						if (meciuri[i].getIdMeci() == id)
						{
							if (Stadion::nrLocuriTotaleStadion(meciuri[i].getStadion()) == Meci::nrTotalSpectatori(meciuri[i]))
							{
								cout << "\nBiletele pentru acest meci s-au epuizat" << endl;
								cout << "Introdu id-ul altui meci: ";
								i = ctMeciuri;
								cin >> id;
								while (cin.good() == 0)
								{
									if (cin.bad())
										throw"IO stream corrupted";
									if (cin.fail())
									{
										cout << "\nInput gresit" << endl;
										cout << "Inputul trebuie sa fie un numar: ";
										cin.clear();
										cin.ignore(INT_MAX, '\n');
										cin >> id;
									}
								}
							}
							else
							{
								indexMeciFinal = i;
								ok = true;
								i = ctMeciuri;
							}
						}
					if (ok == false)
					{
						cout << "\nNu exista niciun meci cu id-ul introdus de tine" << endl;
						cout << "Introdu un id de meci valid: ";
						cin >> id;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> id;
							}
						}
					}
				}
				b.setMeci(meciuri[indexMeciFinal]);

				cout << "\nAlege zona din stadion unde vrei sa stai";
				cout << "\nZonele sunt:" << endl << endl;
				for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
					cout << "Zona " << i + 1 << " - " << (meciuri[indexMeciFinal].getStadion()).getDenumiriZone()[i] << " - " << meciuri[indexMeciFinal].getPreturi()[i] << " lei" << endl;
				Meci::nrBileteDisponibilePerZona(meciuri[indexMeciFinal]);
				cout << "\nIntrodu numarul zonei in care vrei sa stai: ";
				ok = false;
				cin >> ind1;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> ind1;
					}
				}
				ind1--;
				while (ok == false)
				{
					if (ind1 < 0 || ind1 >= (meciuri[indexMeciFinal].getStadion()).getNrZone())
					{
						cout << "\nNu exista nicio zona cu numarul introdus de tine" << endl;
						cout << "Introdu un numar de zona valid: ";
						cin >> ind1;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> ind;
							}
						}
						ind1--;
					}
					else
					{
						zona = (meciuri[indexMeciFinal].getStadion()).getDenumiriZone()[ind1];
						for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
							if ((meciuri[indexMeciFinal].getStadion()).getDenumiriZone()[i] == zona)
							{
								aux = i;
								i = (meciuri[indexMeciFinal].getStadion()).getNrZone();
							}
						if (meciuri[indexMeciFinal].getSpectatori()[aux] + 1 > meciuri[indexMeciFinal].getStadion().getNrRanduriPerZona()[aux] * meciuri[indexMeciFinal].getStadion().getNrLocuriPerRandZona()[aux])
						{
							cout << "\nNu mai exista locuri disponibile pentru zona " << zona << endl;
							cout << "Introdu numarul unei zone care mai are bilete disponibile: ";
							cin >> ind;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> ind1;
								}
							}
							ind1--;
						}
						else
						{
							ok = true;
							spectatori = new long[(meciuri[indexMeciFinal].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
								spectatori[i] = meciuri[indexMeciFinal].getSpectatori()[i];
							spectatori[aux]++;
							meciuri[indexMeciFinal].setSpectatori(spectatori, (meciuri[indexMeciFinal].getStadion()).getNrZone());
							delete[]spectatori;
							spectatori = nullptr;
							zone = new char* [(meciuri[indexMeciFinal].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
								zone[i] = new char[((meciuri[indexMeciFinal].getStadion()).getDenumiriZone()[i]).length() + 1];
							for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
								strcpy(zone[i], ((char**)meciuri[indexMeciFinal].getStadion())[i]);
							for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
								if (zona == (meciuri[indexMeciFinal].getStadion()).getDenumiriZone()[i])
								{
									ind = i;
									i = (meciuri[indexMeciFinal].getStadion()).getNrZone();
								}
							b.setZonaStadionSiPretBilet(zone[ind]);
							for (int i = 0; i < (meciuri[indexMeciFinal].getStadion()).getNrZone(); i++)
							{
								delete[]zone[i];
								zone[i] = nullptr;
							}
							delete[]zone;
							zone = nullptr;
							b.setMeci(meciuri[indexMeciFinal]);
						}
					}

				}
				b.echipaSustinuta();
				cout << b;

			}
			if (index == 4)
			{
				for (int i = 0; i < ctMeciuri; i++)
					if (meciuri[i] == b.getMeci())
					{
						indexMeciInitial = i;
						i = ctMeciuri;
					}
				spectatori = new long[(meciuri[indexMeciInitial].getStadion()).getNrZone()];
				for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
					spectatori[i] = (b.getMeci()).getSpectatori()[i];
				for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
					if ((string)b == (meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[i])
					{
						indexZona = i;
						i = (meciuri[indexMeciInitial].getStadion()).getNrZone();
					}
				spectatori[indexZona]--;
				meciuri[indexMeciInitial].setSpectatori(spectatori, (meciuri[indexMeciInitial].getStadion()).getNrZone());
				b.setMeci(meciuri[indexMeciInitial]);

				cout << "\nAlege zona din stadion unde vrei sa stai";
				cout << "\nZonele sunt:" << endl << endl;
				for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
					cout << "Zona " << i + 1 << " - " << (meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[i] << " - " << meciuri[indexMeciInitial].getPreturi()[i] << " lei" << endl;
				Meci::nrBileteDisponibilePerZona(meciuri[indexMeciInitial]);
				cout << "\nIntrodu numarul zonei in care vrei sa stai: ";
				ok = false;
				cin >> ind1;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> ind1;
					}
				}
				ind1--;
				while (ok == false)
				{
					if (ind1 < 0 || ind1 >= (meciuri[indexMeciInitial].getStadion()).getNrZone())
					{
						cout << "\nNu exista nicio zona cu numarul introdus de tine" << endl;
						cout << "Introdu un numar de zona valid: ";
						cin >> ind1;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> ind1;
							}
						}
						ind1--;
					}
					else
					{
						zona = (meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[ind1];
						for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
							if ((meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[i] == zona)
							{
								aux = i;
								i = (meciuri[indexMeciInitial].getStadion()).getNrZone();
							}
						if (meciuri[indexMeciInitial].getSpectatori()[aux] + 1 > meciuri[indexMeciInitial].getStadion().getNrRanduriPerZona()[aux] * meciuri[indexMeciInitial].getStadion().getNrLocuriPerRandZona()[aux])
						{
							cout << "\nNu mai exista locuri disponibile pentru zona " << zona << endl;
							cout << "Introdu numarul unei zone care mai are bilete disponibile: ";
							cin >> ind1;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> ind1;
								}
							}
							ind1--;
						}
						else
						{
							ok = true;
							spectatori = new long[(meciuri[indexMeciInitial].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
								spectatori[i] = meciuri[indexMeciInitial].getSpectatori()[i];
							spectatori[aux]++;
							meciuri[indexMeciInitial].setSpectatori(spectatori, (meciuri[indexMeciInitial].getStadion()).getNrZone());
							delete[]spectatori;
							spectatori = nullptr;
							zone = new char* [(meciuri[indexMeciInitial].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
								zone[i] = new char[((meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[i]).length() + 1];
							for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
								strcpy(zone[i], ((char**)meciuri[indexMeciInitial].getStadion())[i]);
							for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
								if (zona == (meciuri[indexMeciInitial].getStadion()).getDenumiriZone()[i])
								{
									ind = i;
									i = (meciuri[indexMeciInitial].getStadion()).getNrZone();
								}
							b.setZonaStadionSiPretBilet(zone[ind]);
							for (int i = 0; i < (meciuri[indexMeciInitial].getStadion()).getNrZone(); i++)
							{
								delete[]zone[i];
								zone[i] = nullptr;
							}
							delete[]zone;
							zone = nullptr;
							b.setMeci(meciuri[indexMeciInitial]);
						}
					}

				}
				cout << b;

			}
			if (index == 5)
			{
				if (ctCupon == 0)
				{
					cout << "\nValoarea cuponului este: ";
					cin >> cupon;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> cupon;
						}
					}
					ok = false;
					while (ok == false)
					{

						if (cupon < 0)
						{
							cout << "\nCuponul nu poate avea valoare negativa" << endl;
							cout << "Introdu un cupon cu valoare pozitiva: ";
							cin >> cupon;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> cupon;
								}
							}
						}
						else
						{
							if (cupon > (b.getPretBilet()) / 2)
							{
								cout << "\nCuponul nu poate fi mai mare decat 50% din pretul initial" << endl;
								cout << "Introdu un cupon cu o valoare corecta: ";
								cin >> cupon;
								while (cin.good() == 0)
								{
									if (cin.bad())
										throw"IO stream corrupted";
									if (cin.fail())
									{
										cout << "\nInput gresit" << endl;
										cout << "Inputul trebuie sa fie un numar: ";
										cin.clear();
										cin.ignore(INT_MAX, '\n');
										cin >> cupon;
									}
								}
							}
							else
							{
								b = b - cupon;
								ok = true;
							}
						}
					}
					cout << b;
					ctCupon++;
				}
				else
				{
					cout << "\nDeja ai folosit un cupon de reducere pentru acest bilet";
				}
			}
			if (index == 6)
			{
				if (strcmp(b.echipa, b.meci.getEchipa1()) == 0)
				{
					b.setEchipaSustinuta(b.meci.getEchipa2());
				}
				else
					b.setEchipaSustinuta(b.meci.getEchipa1());
				cout << b;
			}
			if (index == 7)
			{
				buffer = true;
			}
		}


	}
	static bool verificareIdBilet(Bilet bilete[200], int ctBilete, int id, int& idBilet)
	{
		bool ok = false;
		for (int i = 0; i < ctBilete; i++)
		{
			if (bilete[i].getIdBilet() == id)
			{
				ok = true;
				idBilet = i;
				i = ctBilete;
			}
		}
		return ok;
	}
	void serializareFisier()
	{
		int dimensiune;
		string s;
		ofstream f("dateBileteFisier.dat", ios::binary|ios::ate|ios::app);
		if (f.is_open())
		{
			dimensiune = strlen(this->nume) + 1;
			f.write((char*)&dimensiune, sizeof(int));
			s = string(this->nume);
			f.write(s.c_str(), dimensiune * sizeof(char));
			dimensiune = strlen(this->prenume) + 1;
			f.write((char*)&dimensiune, sizeof(int));
			s = string(this->prenume);
			f.write(s.c_str(), dimensiune * sizeof(char));
			dimensiune = strlen(this->meci.echipa1)+1;
			s = string(this->meci.echipa1);
			f.write((char*)&dimensiune, sizeof(int));
			f.write(s.c_str(), dimensiune * sizeof(char));
			dimensiune = strlen(this->meci.echipa2) + 1;
			s = string(this->meci.echipa2);
			f.write((char*)&dimensiune, sizeof(int));
			f.write(s.c_str(), dimensiune * sizeof(char));
			dimensiune = strlen(this->zonaStadion) + 1;
			s = string(this->zonaStadion);
			f.write((char*)&dimensiune, sizeof(int));
			f.write(s.c_str(), dimensiune * sizeof(char));
			f.write((char*)&this->pretBilet, sizeof(float));
			dimensiune = strlen(this->echipa) + 1;
			s = string(this->echipa);
			f.write((char*)&dimensiune, sizeof(int));
			f.write(s.c_str(), dimensiune * sizeof(char));
			f.close();
		}
		else
			throw"Fisierul binar pentru bilete nu exista";
	}
	static void deserializareFisierInVector(Bilet bilete[200],int &ctBilete)
	{
		char buffer[100];
		ctBilete = 0;
		ifstream f("dateBileteFisier.dat",ios::binary);
		float pret;
		int dimensiune;
		if (f.is_open())
		{
			f.seekg(0, ios::beg);
			while (!f.eof())
			{
				f.read((char*)&dimensiune, sizeof(dimensiune));
				f.read(buffer, dimensiune*sizeof(char));
				bilete[ctBilete].setNume(buffer);
				f.read((char*)&dimensiune, sizeof(dimensiune));
				f.read(buffer, dimensiune * sizeof(char));
				bilete[ctBilete].setPrenume(buffer);
				f.read((char*)&dimensiune, sizeof(dimensiune));
				f.read(buffer, dimensiune * sizeof(char));
				bilete[ctBilete].meci.setEchipa1(buffer);
				f.read((char*)&dimensiune, sizeof(dimensiune));
				f.read(buffer, dimensiune * sizeof(char));
				bilete[ctBilete].meci.setEchipa2(buffer);
				f.read((char*)&dimensiune, sizeof(dimensiune));
				f.read(buffer, dimensiune * sizeof(char));
				bilete[ctBilete].setZonaStadion(buffer);
				f.read((char*)&pret, sizeof(float));
				bilete[ctBilete].setPret(pret);
				f.read((char*)&dimensiune, sizeof(dimensiune));
				f.read(buffer, dimensiune * sizeof(char));
				bilete[ctBilete].setEchipaSustinuta(buffer);
				ctBilete++;
			}
			ctBilete--;
			f.close();
		}
		else
			cout<<"Fisierul binar pentru bilete nu exista";
	}
	//operator cast
	operator string()
	{
		string zona = this->zonaStadion;
		return zona;
	}
	//operator -
	Bilet operator-(float i)
	{
		Bilet copie = *this;
		copie.pretBilet = copie.pretBilet - i;
		return copie;
	}
	~Bilet()
	{
		if (this->nume != nullptr)
		{
			delete[]this->nume;
			this->nume = nullptr;
		}
		if (this->prenume != nullptr)
		{
			delete[]this->prenume;
			this->prenume = nullptr;
		}
		if (this->zonaStadion != nullptr)
		{
			delete[]this->zonaStadion;
			this->zonaStadion = nullptr;
		}
		if (this->echipa != nullptr)
		{
			delete[]this->echipa;
			this->echipa = nullptr;
		}
		this->meci.~Meci();
	}
	friend istream& operator>>(istream& in, Bilet& b);
	friend ostream& operator<<(ostream& out, Bilet& b);
};
long Bilet::idb = 1000000;
istream& operator>>(istream& in, Bilet& b)
{
	cout << "\n\nDetaliile biletului sunt: ";
	char buffer[255];
	cout << "\nNumele este: ";
	in >> buffer;
	if (b.nume != nullptr)
	{
		delete[]b.nume;
		b.nume = nullptr;
	}
	b.nume = new char[strlen(buffer) + 1];
	strcpy(b.nume, buffer);
	cout << "\nPrenumele este: ";
	in >> buffer;
	if (b.prenume != nullptr)
	{
		delete[]b.prenume;
		b.prenume = nullptr;
	}
	b.prenume = new char[strlen(buffer) + 1];
	strcpy(b.prenume, buffer);
	return in;
}
ostream& operator<<(ostream& out, Bilet& b)
{
	out << "\n\n\nDetaliile biletului sunt: " << endl << endl;
	out << "Id-ul unic al biletului este: " << b.idBilet << endl;
	out << "Numele este: " << b.nume << endl;
	out << "Prenumele este: " << b.prenume << endl;
	out << "Ai ales meciul dintre " << b.getMeci().getEchipa1() << " si " << b.getMeci().getEchipa2() << endl;
	out << "Data meciului este: " << b.getMeci().getDataMeci() << endl;
	out << "Ora meciului este: " << b.getMeci().getOraMeci() << endl;
	out << "Zona stadionului este: " << b.zonaStadion << endl;
	out << "Pretul biletului este: " << b.pretBilet << endl;
	out << "Echipa sustinuta este: " << b.echipa << endl;
	out << "\n\n\n";
	return out;
}



class DetaliiSuporter : public Bilet
{
private:
	int varsta;
	char telefon[11];
	char* mail;
	Bilet bilet;
public:
	DetaliiSuporter()
	{
		this->varsta = 0;
		strcpy(this->telefon, "Nesetat");
		this->mail = new char[strlen("Nesetat") + 1];
		strcpy(this->mail, "Nesetat");
	}
	DetaliiSuporter(const char* nume, const char* prenume, int varsta, const char telefon[11], const char* mail,Bilet bilet) :Bilet(nume, prenume)
	{
		this->varsta = varsta;
		strcpy(this->telefon, telefon);
		this->mail = new char[strlen(mail) + 1];
		strcpy(this->mail, mail);
		this->bilet = bilet;
	}
	DetaliiSuporter(const DetaliiSuporter& persoana):Bilet(persoana)
	{
		this->varsta = persoana.varsta;
		strcpy(this->telefon, persoana.telefon);
		this->mail = new char[strlen(persoana.mail) + 1];
		strcpy(this->mail, persoana.mail);
		this->bilet = persoana.bilet;
	}
	DetaliiSuporter& operator=(DetaliiSuporter& persoana)
	{
		Bilet::operator=(persoana);
		this->varsta = persoana.varsta;
		strcpy(this->telefon, persoana.telefon);
		if (this->mail != nullptr)
		{
			delete[]this->mail;
			this->mail = nullptr;
		}
		this->mail = new char[strlen(persoana.mail) + 1];
		strcpy(this->mail, persoana.mail);
		this->bilet = persoana.bilet;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	void setVarsta(int varsta)
	{
		if (varsta >= 18 && varsta <= 100)
		{
			this->varsta = varsta;
		}
		else if (varsta <= 0)
			cout << "\nVarsta care va seta nu poate fi negativa sau 0";
		else if (varsta < 18 && varsta>0)
			cout << "Varsta trebuie sa fie mai mare de 18 ani";
		else if (varsta > 100)
			cout << "\nVarsta maxima a unei persoane a fost setata la 100 de ani";
	}
	string getTelefon()
	{
		return string(this->telefon);
	}
	void setTelefon(char telefon[11])
	{
		if (telefon[0] == '0' && telefon[1] == '7' && telefon[2] >= '0' && telefon[2] <= '9' && telefon[3] >= '0' && telefon[3] <= '9'
			&& telefon[4] >= '0' && telefon[4] <= '9' && telefon[5] >= '0' && telefon[5] <= '9' && telefon[6] >= '0' && telefon[6] <= '9'
			&& telefon[7] >= '0' && telefon[7] <= '9' && telefon[8] >= '0' && telefon[8] <= '9' && telefon[9] >= '0' && telefon[9] <= '9')
			strcpy(this->telefon, telefon);
		else
			cout << "\nNumarul de telefon care va seta nu respecta formatul '07XXXXXXXX' ";
	}
	char* getMail()
	{
		char* copie = new char[strlen(this->mail) + 1];
		strcpy(copie, this->mail);
		return copie;
	}
	void setMail(char* mail)
	{
		if (strchr(mail, '@') != NULL)
		{
			if ((mail[strlen(mail)-4]=='.'&& mail[strlen(mail)-3]=='c'&&mail[strlen(mail)-2]=='o'&&mail[strlen(mail)-1]=='m') ||
				mail[strlen(mail)-3]=='.'&&mail[strlen(mail)-2]=='r'&&mail[strlen(mail)-1]=='o')
			{
				if (this->mail != nullptr)
				{
					delete[]this->mail;
					this->mail = nullptr;
				}
				this->mail = new char[strlen(mail) + 1];
				strcpy(this->mail, mail);
			}
			else
				cout << "\nMail-ul care va seta nu respecta formatul '....@....com' sau '....@....ro' ";
		}
		else
			cout << "\nMail-ul care va seta nu respecta formatul '....@....com' sau '....@....ro' ";
	}
	Bilet getBilet()
	{
		return this->bilet;
	}
	void setBilet(Bilet bilet)
	{
		this->bilet = bilet;
	}
	static void modificariSuporter(DetaliiSuporter& suporter)
	{
		int index;
		bool buffer;
		bool ok;
		int varsta;
		char telefon[255];
		char cuvant[255];
		char* mail;
		buffer = false;
		while (buffer == false)
		{
			ok = false;
			while (ok == false)
			{
				cout << "\n\nDoresti sa efectuezi modificari la detaliile suporterului?" << endl;
				cout << "Iata ce modificari poti face: " << endl << endl;
				cout << "Daca doresti sa schimbi varsta, apasa 1" << endl;
				cout << "Daca doresti sa schimbi numarul de telefon, apasa 2" << endl;
				cout << "Daca doresti sa schimbi adresa de mail, apasa 3" << endl;
				cout << "Daca nu doresti sa efectuezi modificari, apasa 4" << endl << endl;
				cout << "Alegerea ta este: ";
				cin >> index;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				if (index < 1 || index>4)
				{
					cout << "\nAlegerea ta nu corespunde niciunei variante" << endl;
					cout << "Introdu un index valid: ";
				}
				else
					ok = true;
			}
			if (index == 1)
			{
				cout << "\nVarsta noua a suporterului este: ";
				ok = false;
				while (ok == false)
				{
					cin >> varsta;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> varsta;
						}
					}
					if (varsta <= 0)
					{
						cout << "\nVarsta nu poate fi negativa sau 0" << endl;
						cout << "Introdu o varsta mai mare sau egala cu 18 ani si mai mica sau egala decat 100 de ani: ";
					}
					else if (varsta > 100)
					{
						cout << "\nVarsta maxima admisa poate fi de maxim 100 de ani" << endl;
						cout << "Introdu o varsta valida: ";
					}
					else
						ok = true;
				}
				suporter.setVarsta(varsta);
				cout << suporter;
			}
			if (index == 2)
			{
				cout << "\nNumarul de telefon nou al suporterului este (07XXXXXXXX): ";
				ok = false;
				while (ok == false)
				{
					cin >> telefon;
					if (telefon[0] == '0' && telefon[1] == '7' && telefon[2] >= '0' && telefon[2] <= '9' && telefon[3] >= '0' && telefon[3] <= '9'
						&& telefon[4] >= '0' && telefon[4] <= '9' && telefon[5] >= '0' && telefon[5] <= '9' && telefon[6] >= '0' && telefon[6] <= '9'
						&& telefon[7] >= '0' && telefon[7] <= '9' && telefon[8] >= '0' && telefon[8] <= '9' && telefon[9] >= '0' && telefon[9] <= '9')
						ok = true;
					else
					{
						cout << "\nNumarul de telefon nu respecta formatul (07XXXXXXXX)" << endl;
						cout << "Introduceti un numar de telefon valid: ";
					}
				}
				suporter.setTelefon(telefon);
				cout << suporter;
			}
			if (index == 3)
			{
				cout << "\nMail-ul nou al suporterului este (....@....com' sau '....@....ro): ";
				ok = false;
				while (ok == false)
				{
					cin >> cuvant;
					if (strchr(cuvant, '@') != NULL)
					{
						if ((cuvant[strlen(cuvant) - 4] == '.' && cuvant[strlen(cuvant) - 3] == 'c' && cuvant[strlen(cuvant) - 2] == 'o' && cuvant[strlen(cuvant) - 1] == 'm') ||
							cuvant[strlen(cuvant) - 3] == '.' && cuvant[strlen(cuvant) - 2] == 'r' && cuvant[strlen(cuvant) - 1] == 'o')
							ok = true;
						else
						{
							cout << "\nMail-ul nu respecta formatul '....@....com' sau '....@....ro'" << endl;
							cout << "Introduceti un mail valid: ";
						}
					}
					else
					{
						cout << "\nMail-ul nu respecta formatul '....@....com' sau '....@....ro'" << endl;
						cout << "Introduceti un mail valid: ";
					}
				}
				mail = new char[strlen(cuvant) + 1];
				strcpy(mail, cuvant);
				suporter.setMail(mail);
				delete[]mail;
				mail = nullptr;
				cout << suporter;
			}
			if (index == 4)
				buffer = true;
		}
	}
	void serializareFisiserSuporteri()
	{
		ofstream f("dateSuporteri.dat", ios::binary | ios::ate | ios::app);
		string s;
		int dimensiune;
		if (f.is_open())
		{
			f.write((char*)&this->varsta, sizeof(int));
			s = string(this->telefon);
			dimensiune = strlen(this->telefon) + 1;
			f.write((char*)&dimensiune, sizeof(int));
			f.write(s.c_str(), dimensiune * sizeof(char));
			dimensiune = strlen(this->mail) + 1;
			s = string(this->mail);
			f.write((char*)&dimensiune, sizeof(int));
			f.write(s.c_str(), dimensiune * sizeof(char));
			f.close();
		}
		else
			throw"Fisierul binar pentru suporteri nu exista";
	}
	static void deserializareFisierBinar(DetaliiSuporter suporteri[200])
	{
		char buffer[255];
		int dimensiune;
		int ct = 0;
		ifstream f("dateSuporteri.dat", ios::binary);
		if (f.is_open())
		{
			f.seekg(0, ios::beg);
			while (!f.eof())
			{
				f.read((char*)&dimensiune, sizeof(int));
				suporteri[ct].setVarsta(dimensiune);
				f.read((char*)&dimensiune, sizeof(int));
				f.read(buffer, dimensiune * sizeof(char));
				suporteri[ct].setTelefon(buffer);
				f.read((char*)&dimensiune, sizeof(int));
				f.read(buffer, dimensiune * sizeof(char));
				suporteri[ct].setMail(buffer);
				ct++;
			}
			f.close();
		}
		else
			cout << "\nFisierul binar pentru suporteri nu exista" << endl << endl << endl;
	}

	~DetaliiSuporter()
	{
		if (this->mail != nullptr)
		{
			delete[]this->mail;
			this->mail = nullptr;
		}
	}
	friend ostream& operator<<(ostream& out, DetaliiSuporter& suporter);
	friend istream& operator>>(istream& in, DetaliiSuporter& suporter);
};
ostream& operator<<(ostream& out, DetaliiSuporter& suporter)
{
	out << "\n\n\nDetaliile suporterului sunt: " << endl << endl;
	out << "Varsta lui "<<suporter.bilet.getNume()<<" "<<suporter.bilet.getPremume()<<" este de "<<suporter.varsta<<" ani"<<endl;
	out << "Numarul de telefon al lui " << suporter.bilet.getNume() << " " << suporter.bilet.getPremume() << " este: " << suporter.telefon << endl;
	out << "Mail-ul lui " << suporter.bilet.getNume() << " " << suporter.bilet.getPremume() << " este: " << suporter.mail<<endl<<endl;
	return out;
}
istream& operator>>(istream& in, DetaliiSuporter& suporter)
{
	int nr;
	char telefon[11];
	char buffer[255];
	char* mail;
	bool ok;
	cout << "\nVarsta suporterului este: ";
	ok = false;
	while (ok == false)
	{
		in >> nr;
		while (in.good() == 0)
		{
			if (in.bad())
				throw"IO stream corrupted";
			if (in.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				in.clear();
				in.ignore(INT_MAX, '\n');
				in >> nr;
			}
		}
		if (nr <= 0)
		{
			cout << "\nVarsta nu poate fi negativa sau 0" << endl;
			cout << "Introdu o varsta mai mare sau egala cu 18 ani si mai mica sau egala decat 100 de ani: ";
		}
		else if (nr > 100)
		{
			cout << "\nVarsta maxima admisa poate fi de maxim 100 de ani" << endl;
			cout << "Introdu o varsta valida: ";
		}
		else
			ok = true;
	}
	suporter.setVarsta(nr);
	cout << "\nNumarul de telefon al suporterului este (07XXXXXXXX): ";
	ok = false;
	while (ok == false)
	{
		in >> telefon;
		if (telefon[0] == '0' && telefon[1] == '7' && telefon[2] >= '0' && telefon[2] <= '9' && telefon[3] >= '0' && telefon[3] <= '9'
			&& telefon[4] >= '0' && telefon[4] <= '9' && telefon[5] >= '0' && telefon[5] <= '9' && telefon[6] >= '0' && telefon[6] <= '9'
			&& telefon[7] >= '0' && telefon[7] <= '9' && telefon[8] >= '0' && telefon[8] <= '9' && telefon[9] >= '0' && telefon[9] <= '9')
			ok = true;
		else
		{
			cout << "\nNumarul de telefon nu respecta formatul (07XXXXXXXX)" << endl;
			cout << "Introduceti un numar de telefon valid: ";
		}
	}
	suporter.setTelefon(telefon);
	cout << "\nMail-ul suporterului este (....@....com' sau '....@....ro): ";
	ok = false;
	while (ok == false)
	{
		in >> buffer;
		if (strchr(buffer, '@') != NULL)
		{
			if ((buffer[strlen(buffer) - 4] == '.' && buffer[strlen(buffer) - 3] == 'c' && buffer[strlen(buffer) - 2] == 'o' && buffer[strlen(buffer) - 1] == 'm') ||
				buffer[strlen(buffer) - 3] == '.' && buffer[strlen(buffer) - 2] == 'r' && buffer[strlen(buffer) - 1] == 'o')
				ok = true;
			else
			{
				cout << "\nMail-ul nu respecta formatul '....@....com' sau '....@....ro'" << endl;
				cout << "Introduceti un mail valid: ";
			}
		}
		else
		{
			cout << "\nMail-ul nu respecta formatul '....@....com' sau '....@....ro'" << endl;
			cout << "Introduceti un mail valid: ";
		}
	}
	mail = new char[strlen(buffer) + 1];
	strcpy(mail, buffer);
	suporter.setMail(mail);
	delete[]mail;
	mail = nullptr;
	return in;
}



int main()
{
	try {
		cout << "BUN VENIT IN APLICATIA DE CREAT BILETE PENTRU UN MECI DE FOTBAL" << endl << endl;
		cout << "Cum doresti sa prelucrezi datele pentru crearea stadioanelor si a meciurilor?" << endl << endl;
		cout << "De la consola - apasa 1" << endl;
		cout << "Dintr-un fisier text - apasa 2" << endl;
		int consolaSauFisier;
		int index;
		bool ok;
		cout << "\nAlegerea ta este: ";
		ok = false;
		while (ok == false)
		{
			cin >> consolaSauFisier;
			while (cin.good() == 0)
			{
				if (cin.bad())
					throw"IO stream corrupted";
				if (cin.fail())
				{
					cout << "\nInput gresit" << endl;
					cout << "Inputul trebuie sa fie un numar: ";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cin >> consolaSauFisier;
				}
			}
			if (consolaSauFisier < 1 || consolaSauFisier>2)
			{
				cout << "\Alegerea ta nu corespunde cerintelor de mai sus" << endl;
				cout << "Introdu o varianta valida: ";
			}
			else
				ok = true;
		}
		Stadion stadioane[50];
		bool buffer;
		int ctStadioane;
		int id;
		int aux;
		Meci meciuri[100];
		int ctMeciuri;
		if (consolaSauFisier == 1)
		{
			cout << "Sa incepem prin a crea un stadion" << endl << endl;
			buffer = false;
			ctStadioane = 0;
			while (buffer == false)
			{
				cin >> stadioane[ctStadioane];
				stadioane[ctStadioane].adaugareArenaNume();
				cout << stadioane[ctStadioane];
				Stadion::modificariStadion(stadioane[ctStadioane]);
				ctStadioane++;
				cout << "\n\nDoresti sa mai creezi un stadion?" << endl << endl;
				cout << "Da - apasa 1" << endl;
				cout << "Nu - apasa 2" << endl;
				cout << "\nAlegerea ta este: ";
				ok = false;
				while (ok == false)
				{
					cin >> index;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> index;
						}
					}
					if (index < 1 || index>2)
					{
						cout << "\Alegerea ta nu corespunde cerintelor de mai sus" << endl;
						cout << "Introdu o varianta valida: ";
					}
					else
						ok = true;
				}
				if (index == 2)
					buffer = true;
			}
			cout << "\n\nIata stadioanele create de tine: ";
			for (int i = 0; i < ctStadioane; i++)
			{
				cout << "\n\n\nIata detaliile stadionului cu id-ul " << stadioane[i].getIdStadion() << endl;
				cout << stadioane[i];
			}
			ctMeciuri = 0;
			cout << "\nAi terminat constructia stadioanelor" << endl;
			cout << "Haide sa cream si niste meciuri" << endl << endl;
			buffer = false;
			while (buffer == false)
			{
				cin >> meciuri[ctMeciuri];
				cout << "\nPe ce stadion doresti sa se dispute meciul?" << endl;
				cout << "\nLista stadioanelor construite sunt:" << endl << endl;
				for (int i = 0; i < ctStadioane; i++)
					cout << stadioane[i].getNumeStadion() << " cu id-ul " << stadioane[i].getIdStadion() << endl;
				cout << "\nPentru a alege un stadion nou, introdu id-ul acestuia: ";
				cin >> id;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> id;
					}
				}
				ok = false;
				while (ok == false)
				{
					for (int i = 0; i < ctStadioane; i++)
						if (stadioane[i].getIdStadion() == id)
						{
							aux = i;
							ok = true;
							i = ctStadioane;
						}
					if (ok == false)
					{
						cout << "\nId-ul introdus de tine nu exista" << endl;
						cout << "\nIntrodu un id care exista: ";
						cin >> id;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> id;
							}
						}
					}
				}
				meciuri[ctMeciuri].setStadion(stadioane[aux]);
				float* preturi;
				cout << "\nPreturile pentru zonele stadionului sunt: " << endl;
				preturi = new float[(meciuri[ctMeciuri].getStadion()).getNrZone()];
				for (int i = 0; i < (meciuri[ctMeciuri].getStadion()).getNrZone(); i++)
				{
					cout << "\nPretul pentru zona " << (meciuri[ctMeciuri].getStadion()).getDenumiriZone()[i] << " este: ";
					ok = false;
					cin >> preturi[i];
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> preturi[i];
						}
					}
					while (ok == false)
					{
						if (preturi[i] <= 0)
						{
							cout << "\nPretul nu poate fi negativ sau nul" << endl;
							cout << "Introdu un pret valid: ";
							cin >> preturi[i];
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> preturi[i];
								}
							}
						}
						else
							ok = true;
					}
				}
				meciuri[ctMeciuri].setPreturi(preturi, (meciuri[ctMeciuri].getStadion()).getNrZone());
				cout << meciuri[ctMeciuri];
				delete[]preturi;
				preturi = nullptr;
				Meci::modificareMeci(meciuri[ctMeciuri], stadioane, ctStadioane);
				ctMeciuri++;
				cout << "\nDoresti sa mai creezi un meci?" << endl;
				cout << "Da - apasa 1" << endl;
				cout << "Nu - apasa 2" << endl;
				cout << "\nAlegerea ta este: ";
				cin >> index;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				ok = false;
				while (ok == false)
				{
					if (index < 0 || index>2)
					{
						cout << "\nValoarea introdusa nu corespunde niciunei alegeri" << endl;
						cout << "Introdu un index valid: ";
						cin >> index;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> index;
							}
						}
					}
					else
						ok = true;
				}
				if (index == 2)
					buffer = true;
			}
			cout << "\n\n\n---------------------------------------";
			cout << "\nMeciurile au fost create";
			cout << "\nHaide sa facem o scurta recapitulare a meciurilor";
			for (int i = 0; i < ctMeciuri; i++)
			{
				cout << meciuri[i];
				cout << "---------------------------------------";
			}
		}
		else if (consolaSauFisier == 2)
		{
			ofstream f;
			f.open("date.txt", ios::out | ios::trunc);
			//stadioane
			f << "Nationala" << endl;
			f << 3 << endl;
			f << "Peluza" << endl;
			f << "Tribuna" << endl;
			f << "Vip" << endl;
			f << 100 << endl;
			f << 200 << endl;
			f << 50 << endl;
			f << 1000 << endl;
			f << 1500 << endl;
			f << 700 << endl;
			f << "Cluj" << endl;
			f << 4 << endl;
			f << "Peluza" << endl;
			f << "Tribuna1" << endl;
			f << "Tribuna2" << endl;
			f << "Loja" << endl;
			f << 100 << endl;
			f << 200 << endl;
			f << 200 << endl;
			f << 30 << endl;
			f << 2000 << endl;
			f << 1000 << endl;
			f << 1000 << endl;
			f << 100 << endl;
			//meciuri
			f << "Steaua" << endl;
			f << "Dinamo" << endl;
			f << "21/01/2023" << endl;
			f << "21:30" << endl;
			f << 50 << endl;
			f << 100 << endl;
			f << 200 << endl;
			f << "Chelsea" << endl;
			f << "Liverpool" << endl;
			f << "22/01/2023" << endl;
			f << "22:00" << endl;
			f << 100 << endl;
			f << 150 << endl;
			f << 175 << endl;
			f << 300 << endl;
			f.close();
			ifstream g;
			g.open("date.txt", ios::in);
			if (g.is_open())
			{
				ctStadioane = 2;
				ctMeciuri = 2;
				int nr;
				string* denumiri = new string[3];
				char* stadion = new char[10];
				int* randuri = new int[3];
				int* locuri = new int[3];
				g >> stadion;
				stadioane[0].setNumeStadion(stadion);
				g >> nr;
				stadioane[0].setNrZone(nr);
				g >> denumiri[0] >> denumiri[1] >> denumiri[2];
				stadioane[0].setDenumiriZone(denumiri, nr);
				g >> randuri[0] >> randuri[1] >> randuri[2];
				g >> locuri[0] >> locuri[1] >> locuri[2];
				stadioane[0].setNrRanduriPerZona(randuri, nr);
				stadioane[0].setNrLocuriPerRandZona(locuri, nr);
				stadioane[0].adaugareArenaNume();
				delete[]denumiri;
				delete[]randuri;
				delete[]locuri;
				delete[]stadion;
				stadion = new char[5];
				g >> stadion;
				stadioane[1].setNumeStadion(stadion);
				g >> nr;
				stadioane[1].setNrZone(nr);
				denumiri = new string[nr];
				g >> denumiri[0] >> denumiri[1] >> denumiri[2] >> denumiri[3];
				stadioane[1].setDenumiriZone(denumiri, nr);
				randuri = new int[nr];
				locuri = new int[nr];
				g >> randuri[0] >> randuri[1] >> randuri[2] >> randuri[3];
				g >> locuri[0] >> locuri[1] >> locuri[2] >> locuri[3];
				stadioane[1].setNrRanduriPerZona(randuri, nr);
				stadioane[1].setNrLocuriPerRandZona(locuri, nr);
				stadioane[1].adaugareArenaNume();
				delete[]denumiri;
				denumiri = nullptr;
				delete[]randuri;
				randuri = nullptr;
				delete[]locuri;
				locuri = nullptr;
				delete[]stadion;
				stadion = nullptr;
				cout << "----------------------------------------------------" << endl << endl << endl;
				cout << "Detaliile stadioanelor sunt:" << endl << endl << endl;
				for (int i = 0; i < 2; i++)
					cout << stadioane[i];
				cout << "----------------------------------------------------" << endl << endl << endl;
				char* echipa=new char[7];
				char* data = new char[11];
				char* ora = new char[6];
				float* preturi=new float[3];
				g >> echipa;
				meciuri[0].setEchipa1(echipa);
				delete[]echipa;
				echipa = new char[7];
				g >> echipa;
				meciuri[0].setEchipa2(echipa);
				g >> data;
				meciuri[0].setDataMeci(data);
				g >> ora;
				meciuri[0].setOraMeci(ora);
				meciuri[0].setStadion(stadioane[0]);
				g >> preturi[0] >> preturi[1] >> preturi[2];
				meciuri[0].setPreturi(preturi, 3);
				delete[]echipa;
				delete[]preturi;
				echipa = new char[8];
				g >> echipa;
				meciuri[1].setEchipa1(echipa);
				delete[]echipa;
				echipa = new char[10];
				g >> echipa;
				meciuri[1].setEchipa2(echipa);
				g >> data;
				meciuri[1].setDataMeci(data);
				g >> ora;
				meciuri[1].setOraMeci(ora);
				meciuri[1].setStadion(stadioane[1]);
				preturi = new float[4];
				g >> preturi[0] >> preturi[1] >> preturi[2]>>preturi[3];
				meciuri[1].setPreturi(preturi, 4);
				delete[]echipa;
				delete[]data;
				delete[]ora;
				delete[]preturi;
				cout << "Detaliile meciurilor sunt:" << endl << endl << endl;
				for (int i = 0; i < 2; i++)
					cout << meciuri[i];
				cout << "----------------------------------------------------" << endl << endl << endl;
				g.close();
			}
			else
				throw"Fisierul nu exista";

			
			Bilet bilete[200];
			DetaliiSuporter suporteri[200];
			int ctBilete = 0;
			Bilet::deserializareFisierInVector(bilete, ctBilete);
			for (int i = 0; i < ctBilete; i++)
			{
				for (int j = 0; j < ctMeciuri; j++)
					if (strcmp(bilete[i].getMeci().getEchipa1(), meciuri[j].getEchipa1()) == 0 && strcmp(bilete[i].getMeci().getEchipa2(), meciuri[j].getEchipa2()) == 0)
					{
						bilete[i].setMeci(meciuri[j]);
						j = ctMeciuri;
					}
			}
			DetaliiSuporter::deserializareFisierBinar(suporteri);
			if (ctBilete != 0)
			{
				for (int i = 0; i < ctBilete; i++)
					suporteri[i].setBilet(bilete[i]);
				cout << "\nBiletele create pana in prezent sunt:" << endl;
				for (int i = 0; i < ctBilete; i++)
				{
					cout << bilete[i];
					cout << suporteri[i];
				}
			}
			long* spectatori;
			for (int i = 0; i < ctBilete; i++)
			{
				for(int j=0;j<bilete[i].getMeci().getStadion().getNrZone();j++)
					if (string(bilete[i].getZonaStadion()) == bilete[i].getMeci().getStadion().getDenumiriZone()[j])
					{
						for (int k = 0; k < ctMeciuri; k++)
						{
							if (bilete[i].getMeci() == meciuri[k])
							{
								spectatori = new long[bilete[i].getMeci().getStadion().getNrZone()];
								spectatori = meciuri[k].getSpectatori();
								spectatori[j]++;
								meciuri[k].setSpectatori(spectatori, bilete[i].getMeci().getStadion().getNrZone());
								k = ctMeciuri;
								delete[]spectatori;
							}
						}
					}
			}
			buffer = false;
			char** zone;
			string zona;
			bool ok1;
			int ind;
			int indexZona;
			int indexMeci;
			cout << "\n\n\n";
			cout << "Acum ca evenimentele sunt create, haide sa aducem niste suporteri la meci";
			while (buffer == false)
			{
				cin >> bilete[ctBilete];
				cout << "\nAlege meciul la care vrei sa te uiti" << endl;
				cout << "Meciurile sunt: " << endl;
				for (int i = 0; i < ctMeciuri; i++)
					cout << meciuri[i].getEchipa1() << " vs " << meciuri[i].getEchipa2() << " din data " << meciuri[i].getDataMeci() << " de la ora " << meciuri[i].getOraMeci() << " cu id-ul " << meciuri[i].getIdMeci() << endl;
				cout << "\nIntrodu id-ul meciului la care vrei sa te uiti: ";
				ok = false;
				cin >> id;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> id;
					}
				}
				while (ok == false)
				{
					for (int i = 0; i < ctMeciuri; i++)
						if (meciuri[i].getIdMeci() == id)
						{
							if (Stadion::nrLocuriTotaleStadion(meciuri[i].getStadion()) == Meci::nrTotalSpectatori(meciuri[i]))
							{
								cout << "\nBiletele pentru acest meci s-au epuizat" << endl;
								cout << "Introdu id-ul altui meci: ";
								i = ctMeciuri;
								cin >> id;
								while (cin.good() == 0)
								{
									if (cin.bad())
										throw"IO stream corrupted";
									if (cin.fail())
									{
										cout << "\nInput gresit" << endl;
										cout << "Inputul trebuie sa fie un numar: ";
										cin.clear();
										cin.ignore(INT_MAX, '\n');
										cin >> id;
									}
								}
							}
							else
							{
								aux = i;
								ok = true;
								i = ctMeciuri;
							}
						}
					if (ok == false)
					{
						cout << "\nNu exista niciun meci cu id-ul introdus de tine" << endl;
						cout << "Introdu un id de meci valid: ";
						cin >> id;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> id;
							}
						}
					}
				}
				bilete[ctBilete].setMeci(meciuri[aux]);
				cout << "\nAlege zona din stadion unde vrei sa stai";
				cout << "\nZonele sunt:" << endl << endl;
				for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
					cout << "Zona " << i + 1 << " - " << (meciuri[aux].getStadion()).getDenumiriZone()[i] << " - " << meciuri[aux].getPreturi()[i] << " lei" << endl;
				Meci::nrBileteDisponibilePerZona(meciuri[aux]);
				cout << "\nIntrodu numarul zonei in care vrei sa stai: ";
				ok = false;
				cin >> index;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				index--;
				while (ok == false)
				{
					if (index < 0 || index >= (meciuri[aux].getStadion()).getNrZone())
					{
						cout << "\nNu exista nicio zona cu numarul introdus de tine" << endl;
						cout << "Introdu un numar de zona valid: ";
						cin >> index;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> index;
							}
						}
						index--;
					}
					else
					{
						zona = (meciuri[aux].getStadion()).getDenumiriZone()[index];
						if (meciuri[aux].getSpectatori()[index] + 1 > meciuri[aux].getStadion().getNrRanduriPerZona()[index] * meciuri[aux].getStadion().getNrLocuriPerRandZona()[index])
						{
							cout << "\nNu mai exista locuri disponibile pentru zona " << zona << endl;
							cout << "Introdu numarul unei zone care mai are bilete disponibile: ";
							cin >> index;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> index;
								}
							}
							index--;
						}
						else
						{
							ok = true;
							spectatori = new long[(meciuri[aux].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								spectatori[i] = meciuri[aux].getSpectatori()[i];
							spectatori[index]++;
							meciuri[aux].setSpectatori(spectatori, (meciuri[aux].getStadion()).getNrZone());
							delete[]spectatori;
							spectatori = nullptr;
							zone = new char* [(meciuri[aux].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								zone[i] = new char[((meciuri[aux].getStadion()).getDenumiriZone()[i]).length() + 1];
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								strcpy(zone[i], ((char**)meciuri[aux].getStadion())[i]);
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								if (zona == (meciuri[aux].getStadion()).getDenumiriZone()[i])
								{
									ind = i;
									i = (meciuri[aux].getStadion()).getNrZone();
								}
							bilete[ctBilete].setZonaStadionSiPretBilet(zone[ind]);
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
							{
								delete[]zone[i];
								zone[i] = nullptr;
							}
							delete[]zone;
							zone = nullptr;
							bilete[ctBilete].setMeci(meciuri[aux]);
						}
					}

				}
				bilete[ctBilete].echipaSustinuta();
				cout << bilete[ctBilete];
				Bilet::modificariBilet(bilete[ctBilete], meciuri, ctMeciuri);
				bilete[ctBilete].serializareFisier();
				cout << "\nDetaliile suporterului sunt:" << endl;
				cin >> suporteri[ctBilete];
				suporteri[ctBilete].setBilet(bilete[ctBilete]);
				DetaliiSuporter::modificariSuporter(suporteri[ctBilete]);
				suporteri[ctBilete].serializareFisiserSuporteri();
				cout << suporteri[ctBilete];
				ctBilete++;
				ok = false;
				for (int i = 0; i < ctMeciuri; i++)
					if (Stadion::nrLocuriTotaleStadion(meciuri[i].getStadion()) != Meci::nrTotalSpectatori(meciuri[i]))
						ok = true;
				if (ok == false)
				{
					cout << "\nOdata cu crearea acestui bilet, nu mai sunt locuri libere pentru niciun meci";
					buffer = true;
				}
				else
				{
					cout << "\nDoresti sa mai creezi un bilet?" << endl;
					cout << "Da - apasa 1" << endl;
					cout << "Nu - apasa 2" << endl;
					cout << "\nAlegerea ta este: ";
					ok1 = false;
					cin >> index;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> index;
						}
					}
					while (ok1 == false)
					{
						if (index < 1 || index>2)
						{
							cout << "\nVarianta ta nu se regaseste in optiunile de mai sus" << endl;
							cout << "Alege un index valid: ";
							cin >> index;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> index;
								}
							}
						}
						else
							ok1 = true;
					}
					if (index == 2)
						buffer = true;
				}
			}
			cout << "\n--------------------------------------" << endl << endl;
			cout << "Biletele au fost create";
			cout << "\n\nDoresti sa revezi detaliile vreunui bilet?" << endl << endl;
			cout << "Da - apasa 1" << endl;
			cout << "Nu - apasa 2" << endl;
			cout << "\nAlegerea ta este: ";
			int idBilet;
			cin >> index;
			if (cin.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> index;
			}
			ok = false;
			while (ok == false)
			{
				if (index < 1 || index>2)
				{
					cout << "\nAlegerea ta nu corespunde niciunei variante" << endl;
					cout << "Introdu un index valid: ";
					cin >> index;
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				else if (index == 1)
				{
					buffer = false;
					while (buffer == false)
					{
						cout << "\nPentru a vedea detaliile biletului, introdu id-ul acestuia: ";
						cin >> idBilet;
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> idBilet;
						}
						if (Bilet::verificareIdBilet(bilete, ctBilete, idBilet, id) == 1)
						{
							cout << bilete[id];
							cout << suporteri[id];
						}
						else
							cout << "\nId-ul introdus nu apartine niciunui bilet";
						cout << "\n\nDoresti sa continui cu verificarea biletelor?" << endl << endl;
						cout << "Da - apasa 1" << endl;
						cout << "Nu - apasa 2" << endl;
						cout << "\nAlegerea ta este: ";
						cin >> ind;
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> ind;
						}
						ok1 = false;
						while (ok1 == false)
						{
							if (ind < 1 || ind>2)
							{
								cout << "\nAlegerea ta nu corespunde niciunei variante" << endl;
								cout << "Introdu un index valid: ";
								cin >> ind;
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> ind;
								}
							}
							else
								ok1 = true;
						}
						if (ind == 2)
						{
							buffer = true;
							ok = true;
							cout << "\n------------------------------------" << endl;
							cout << "La revedere!!!" << endl << endl;
						}
					}
				}
				else if (index == 2)
				{
					cout << "\n------------------------------------" << endl;
					cout << "La revedere!!!" << endl << endl;
					ok = true;
				}
			}
		}
		if (consolaSauFisier == 1)
		{
			cout << "\n\n\n";
			cout << "Acum ca evenimentele sunt create, haide sa aducem niste suporteri la meci";
			Bilet bilete[200];
			DetaliiSuporter suporteri[200];
			int ctBilete = 0;
			buffer = false;
			char** zone;
			string zona;
			bool ok1;
			int ind;
			long* spectatori;
			int indexZona;
			int indexMeci;
			while (buffer == false)
			{
				cin >> bilete[ctBilete];
				cout << "\nAlege meciul la care vrei sa te uiti" << endl;
				cout << "Meciurile sunt: " << endl;
				for (int i = 0; i < ctMeciuri; i++)
					cout << meciuri[i].getEchipa1() << " vs " << meciuri[i].getEchipa2() << " din data " << meciuri[i].getDataMeci() << " de la ora " << meciuri[i].getOraMeci() << " cu id-ul " << meciuri[i].getIdMeci() << endl;
				cout << "\nIntrodu id-ul meciului la care vrei sa te uiti: ";
				ok = false;
				cin >> id;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> id;
					}
				}
				while (ok == false)
				{
					for (int i = 0; i < ctMeciuri; i++)
						if (meciuri[i].getIdMeci() == id)
						{
							if (Stadion::nrLocuriTotaleStadion(meciuri[i].getStadion()) == Meci::nrTotalSpectatori(meciuri[i]))
							{
								cout << "\nBiletele pentru acest meci s-au epuizat" << endl;
								cout << "Introdu id-ul altui meci: ";
								i = ctMeciuri;
								cin >> id;
								while (cin.good() == 0)
								{
									if (cin.bad())
										throw"IO stream corrupted";
									if (cin.fail())
									{
										cout << "\nInput gresit" << endl;
										cout << "Inputul trebuie sa fie un numar: ";
										cin.clear();
										cin.ignore(INT_MAX, '\n');
										cin >> id;
									}
								}
							}
							else
							{
								aux = i;
								ok = true;
								i = ctMeciuri;
							}
						}
					if (ok == false)
					{
						cout << "\nNu exista niciun meci cu id-ul introdus de tine" << endl;
						cout << "Introdu un id de meci valid: ";
						cin >> id;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> id;
							}
						}
					}
				}
				bilete[ctBilete].setMeci(meciuri[aux]);
				cout << "\nAlege zona din stadion unde vrei sa stai";
				cout << "\nZonele sunt:" << endl << endl;
				for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
					cout << "Zona " << i + 1 << " - " << (meciuri[aux].getStadion()).getDenumiriZone()[i] << " - " << meciuri[aux].getPreturi()[i] << " lei" << endl;
				Meci::nrBileteDisponibilePerZona(meciuri[aux]);
				cout << "\nIntrodu numarul zonei in care vrei sa stai: ";
				ok = false;
				cin >> index;
				while (cin.good() == 0)
				{
					if (cin.bad())
						throw"IO stream corrupted";
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				index--;
				while (ok == false)
				{
					if (index < 0 || index >= (meciuri[aux].getStadion()).getNrZone())
					{
						cout << "\nNu exista nicio zona cu numarul introdus de tine" << endl;
						cout << "Introdu un numar de zona valid: ";
						cin >> index;
						while (cin.good() == 0)
						{
							if (cin.bad())
								throw"IO stream corrupted";
							if (cin.fail())
							{
								cout << "\nInput gresit" << endl;
								cout << "Inputul trebuie sa fie un numar: ";
								cin.clear();
								cin.ignore(INT_MAX, '\n');
								cin >> index;
							}
						}
						index--;
					}
					else
					{
						zona = (meciuri[aux].getStadion()).getDenumiriZone()[index];
						if (meciuri[aux].getSpectatori()[index] + 1 > meciuri[aux].getStadion().getNrRanduriPerZona()[index] * meciuri[aux].getStadion().getNrLocuriPerRandZona()[index])
						{
							cout << "\nNu mai exista locuri disponibile pentru zona " << zona << endl;
							cout << "Introdu numarul unei zone care mai are bilete disponibile: ";
							cin >> index;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> index;
								}
							}
							index--;
						}
						else
						{
							ok = true;
							spectatori = new long[(meciuri[aux].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								spectatori[i] = meciuri[aux].getSpectatori()[i];
							spectatori[index]++;
							meciuri[aux].setSpectatori(spectatori, (meciuri[aux].getStadion()).getNrZone());
							delete[]spectatori;
							spectatori = nullptr;
							zone = new char* [(meciuri[aux].getStadion()).getNrZone()];
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								zone[i] = new char[((meciuri[aux].getStadion()).getDenumiriZone()[i]).length() + 1];
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								strcpy(zone[i], ((char**)meciuri[aux].getStadion())[i]);
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
								if (zona == (meciuri[aux].getStadion()).getDenumiriZone()[i])
								{
									ind = i;
									i = (meciuri[aux].getStadion()).getNrZone();
								}
							bilete[ctBilete].setZonaStadionSiPretBilet(zone[ind]);
							for (int i = 0; i < (meciuri[aux].getStadion()).getNrZone(); i++)
							{
								delete[]zone[i];
								zone[i] = nullptr;
							}
							delete[]zone;
							zone = nullptr;
							bilete[ctBilete].setMeci(meciuri[aux]);
						}
					}

				}
				bilete[ctBilete].echipaSustinuta();
				cout << bilete[ctBilete];
				Bilet::modificariBilet(bilete[ctBilete], meciuri, ctMeciuri);
				cout << "\nDetaliile suporterului sunt:" << endl;
				cin >> suporteri[ctBilete];
				suporteri[ctBilete].setBilet(bilete[ctBilete]);
				cout << suporteri[ctBilete];
				DetaliiSuporter::modificariSuporter(suporteri[ctBilete]);
				ctBilete++;
				ok = false;
				for (int i = 0; i < ctMeciuri; i++)
					if (Stadion::nrLocuriTotaleStadion(meciuri[i].getStadion()) != Meci::nrTotalSpectatori(meciuri[i]))
						ok = true;
				if (ok == false)
				{
					cout << "\nOdata cu crearea acestui bilet, nu mai sunt locuri libere pentru niciun meci";
					buffer = true;
				}
				else
				{
					cout << "\nDoresti sa mai creezi un bilet?" << endl;
					cout << "Da - apasa 1" << endl;
					cout << "Nu - apasa 2" << endl;
					cout << "\nAlegerea ta este: ";
					ok1 = false;
					cin >> index;
					while (cin.good() == 0)
					{
						if (cin.bad())
							throw"IO stream corrupted";
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> index;
						}
					}
					while (ok1 == false)
					{
						if (index < 1 || index>2)
						{
							cout << "\nVarianta ta nu se regaseste in optiunile de mai sus" << endl;
							cout << "Alege un index valid: ";
							cin >> index;
							while (cin.good() == 0)
							{
								if (cin.bad())
									throw"IO stream corrupted";
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> index;
								}
							}
						}
						else
							ok1 = true;
					}
					if (index == 2)
						buffer = true;
				}
			}
			cout << "\n--------------------------------------" << endl << endl;
			cout << "Biletele au fost create";
			cout << "\n\nDoresti sa revezi detaliile vreunui bilet?" << endl << endl;
			cout << "Da - apasa 1" << endl;
			cout << "Nu - apasa 2" << endl;
			cout << "\nAlegerea ta este: ";
			int idBilet;
			cin >> index;
			if (cin.fail())
			{
				cout << "\nInput gresit" << endl;
				cout << "Inputul trebuie sa fie un numar: ";
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cin >> index;
			}
			ok = false;
			while (ok == false)
			{
				if (index < 1 || index>2)
				{
					cout << "\nAlegerea ta nu corespunde niciunei variante" << endl;
					cout << "Introdu un index valid: ";
					cin >> index;
					if (cin.fail())
					{
						cout << "\nInput gresit" << endl;
						cout << "Inputul trebuie sa fie un numar: ";
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cin >> index;
					}
				}
				else if (index == 1)
				{
					buffer = false;
					while (buffer == false)
					{
						cout << "\nPentru a vedea detaliile biletului, introdu id-ul acestuia: ";
						cin >> idBilet;
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> idBilet;
						}
						if (Bilet::verificareIdBilet(bilete, ctBilete, idBilet, id) == 1)
						{
							cout << bilete[id];
							cout << suporteri[id];
						}
						else
							cout << "\nId-ul introdus nu apartine niciunui bilet";
						cout << "\n\nDoresti sa continui cu verificarea biletelor?" << endl << endl;
						cout << "Da - apasa 1" << endl;
						cout << "Nu - apasa 2" << endl;
						cout << "\nAlegerea ta este: ";
						cin >> ind;
						if (cin.fail())
						{
							cout << "\nInput gresit" << endl;
							cout << "Inputul trebuie sa fie un numar: ";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							cin >> ind;
						}
						ok1 = false;
						while (ok1 == false)
						{
							if (ind < 1 || ind>2)
							{
								cout << "\nAlegerea ta nu corespunde niciunei variante" << endl;
								cout << "Introdu un index valid: ";
								cin >> ind;
								if (cin.fail())
								{
									cout << "\nInput gresit" << endl;
									cout << "Inputul trebuie sa fie un numar: ";
									cin.clear();
									cin.ignore(INT_MAX, '\n');
									cin >> ind;
								}
							}
							else
								ok1 = true;
						}
						if (ind == 2)
						{
							buffer = true;
							ok = true;
							cout << "\n------------------------------------" << endl;
							cout << "La revedere!!!" << endl << endl;
						}
					}
				}
				else if (index == 2)
				{
					cout << "\n------------------------------------" << endl;
					cout << "La revedere!!!" << endl << endl;
					ok = true;
				}
			}
		}
		return 0;
	}
	catch (const char* err)
	{
		cout << "\nEroare: " << err;
	}
}
