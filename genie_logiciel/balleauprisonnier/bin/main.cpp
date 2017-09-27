#include <iostream>

class Pixel{
private:
	int red, green, blue;

public:
	Pixel(){
		this->red = 0;
		this->green = 0;
		this->blue = 0;
	}

	int getRed(){
		return this->red;
	}
	int getGreen(){
		return this->green;
	}
	int getBlue(){
		return this->blue;
	}

	void setRed(int red){
		this->red = red;
	}
	void setGreen(int green){
		this->green = green;
	}
	void setBlue(int blue){
		this->blue = blue;
	}


	~Pixel(){

	}
};


class Image{
private:
	int largeur, longueur;
	Pixel *elements;

public:
	Image(int largeur, int longueur){
		this->largeur = largeur;
		this->longueur = longueur;
		this->elements = new Pixel[largeur * longueur];

		int i;
		for(i=0; i<largeur*longueur; i++){
			this->elements[i] = *(new Pixel());
		}
	}

	Pixel getPixel(int ligne, int colonne){
		return *this->elements[ligne * this->largeur + colonne];		
	}

	void setPixel(Pixel *pixel, int ligne, int colonne){
		this->elements[ligne * this->largeur + colonne] = pixel;
	}

	~Image(){
		delete[] this->elements ;
	}

};


int main(int argc, char const *argv[])
{
	if(argc < 2){
		std::cout << "Usage : " << argv[0] << " <nbTours>" << std::endl;
		return -1;
	}

	int nbTours = atoi(argv[1]);
	std::cout << "Start for " << nbTours << std::endl;
	int tour;
	int largeur=100, longueur=100;
	Image *image = new Image(largeur, longueur);
	for(tour=0; tour<nbTours; tour++){
		int colonne;
		for (colonne=0; colonne<largeur; colonne++) {
			int ligne;
			for (ligne=0; ligne<longueur; ligne++) {
				image->setPixel(*(new Pixel()), ligne, colonne);
			}
		}
	}
	std::cout << "Done." << std::endl;
	return 0;
}