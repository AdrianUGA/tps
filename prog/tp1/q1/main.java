import java.lang.*;

public class main{
	public static void main(String[] args) {
		if(args.length < 1){
			System.out.println("Usage : main <nbTours>");
			return;
		}

		int largeur=100, longueur=100;
		Image image = new Image(largeur, longueur);
		int nbTours = Integer.parseInt(args[0]);

		System.out.println("Start for "+nbTours);

		for(int tour=0; tour<nbTours; tour++){
			for (int colonne=0; colonne<largeur; colonne++) {
				for (int ligne=0; ligne<longueur; ligne++) {
					image.setPixel(new Pixel(), ligne, colonne);
				}
			}
		}

		System.out.println("Done.");
	}
}