class Image{
	private int largeur;
	private int hauteur;
	private Pixel[] elements;

	public Image(int largeur, int hauteur){
		this.elements = new Pixel[largeur*hauteur];
		this.largeur = largeur;
		this.hauteur = hauteur;
		for (int i=0; i<largeur * hauteur; i++) {
			this.elements[i] = new Pixel();
		}
	}

	public Pixel getPixel(int ligne, int colonne){
		return this.elements[ligne * this.largeur + colonne];		
	}

	public void setPixel(Pixel pixel, int ligne, int colonne){
		this.elements[ligne * this.largeur + colonne] = pixel;
	}
}