#include <iostream>
class LaClasse
{
	public :
//Construction, conversion, affectation et destruction
	LaClasse() : l(0)
	{std::cout << "LaClasse::LaClasse()\n";}
	LaClasse(const LaClasse & lc) : l(lc.l)
	{std::cout << "LaClasse::LaClasse(const LaClasse & )\n";}
	LaClasse(int i) : l(i)
	{std::cout << "LaClasse::LaClasse(int)\n";}
	operator bool() const
	{std::cout << "LaClasse::operator bool() const\n"; return true;}
	~LaClasse()
	{std::cout << "~LaClasse::LaClasse()\n";}
	const LaClasse & operator=(const LaClasse & c)
	{std::cout << "LaClasse::operator=(const LaClasse &)\n"; return *this;}
//Autre fonction membre
	LaClasse F(LaClasse);
// Déclaration fonction extérieure amie
	friend std::ostream & operator << (std::ostream & os, const LaClasse & lc);
	private :
	int l;
};
LaClasse F(LaClasse vv)
{
	std::cout << " in F \n";
	return 8;
}
LaClasse LaClasse::F(LaClasse v)
{
	std::cout << " in LaClasse::F \n";
	return ::F(v);
}
std::ostream & operator << (std::ostream & os, const LaClasse & lc)
{
	os << " in ostream << LaClasse "<< lc.l << std::endl;
	return os;
}

class LaClasseSpecialisee{
	// LaClasseSpecialisee()
	// {std::cout << "spe default\n";}
	// LaClasseSpecialisee(LaClasseSpecialisee const & lcs)
	// {std::cout << "spe copie\n";}
	// LaClasseSpecialisee(int i)
	// {std::cout << "se int\n";}

	LaClasseSpecialisee const & operator=(LaClasseSpecialisee const & c)
	{std::cout << "spe =\n"; return *this;}


}

// Testez et analysez la séquence d’appels aux fonctions membres
// de LaClasse dans le programme suivant :
int main()
{

	LaClasseSpecialisee lcs;
	return 0;
	LaClasse c1; /* c1 est créé sur la pile, contructeur par défaut appellé */
	std::cout << std::endl;

	LaClasse c2=LaClasse(); /*
	avec no-elide-constructors :
	objet temporaire créé par LaClasse()
	c2 est créé sur la pile, et constructeur de copie appellé
	objet temporaire supprimé
	sans no-elide-constructors :
	contructeur par défaut
	*/
	std::cout << std::endl;

	LaClasse cc1(c1); /* cc1 est créé sur la pile, constructeur 2 */
	std::cout << std::endl;

	LaClasse cc2=c1; /* cc2 est créé sur la pile, copie de l'adresse de c1 */
	std::cout << std::endl;

	LaClasse cc3=LaClasse(c1);
	/*
	une copie temporaire de C1 est créée par copie
	cc3 est créé par copie de l'objet temporaire
	destruction de l'objet temporaire
	*/
	std::cout << std::endl;

	LaClasse cv1(5); /* Objet temporaire 5 créé, passé par copie */
	std::cout << std::endl;

	LaClasse cv2=5;
	std::cout << std::endl;

	LaClasse cv3=LaClasse(5);
	std::cout << std::endl;

	LaClasse cv4=(LaClasse)5;
	std::cout << std::endl;

	c1=cc1;
	std::cout << std::endl;

	c2=8;
	std::cout << std::endl;

	if(cv1)
	{
		cv1=F(10);
		cv1=F(c1);
		cv1=c1.F(c2);
	}
	std::cout << "Tableaux \n";
	LaClasse tab[3];
	LaClasse *pc=new LaClasse(tab[0]);
	delete pc;
	std::cout << "Avant de sortir ... \n";
	return 0;
}