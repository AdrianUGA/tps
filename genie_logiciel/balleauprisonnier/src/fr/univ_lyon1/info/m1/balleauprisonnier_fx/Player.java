package fr.univ_lyon1.info.m1.balleauprisonnier_fx;


import javafx.scene.canvas.GraphicsContext;
import javafx.scene.transform.Rotate;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.util.Duration;

/**
 * 
 * Classe gerant un joueur
 *
 */
abstract public class Player
{
	  double x;       // position horizontale du joueur
	  final double y; 	  // position verticale du joueur
	  double angle = 90; // rotation du joueur, devrait toujour être en 0 et 180
	  double step;    // pas d'un joueur
	  

	  
	  // On une image globale du joueur 
	  Image directionArrow;
	  Sprite sprite;
	  ImageView PlayerDirectionArrow;
	  Team team;
	  
	  
	  /**
	   * Constructeur du Joueur
	   * 
	   * @param gc ContextGraphic dans lequel on va afficher le joueur
	   * @param team couleur du joueur
	   * @param yInit position verticale
	   */
	  Player(Team team, int xInit, int yInit, String side)
	  {
		this.team = team;
		// Tous les joueurs commencent au centre du canvas, 
	    x = xInit;               
	    y = yInit;
	    
	    angle = 0;

	    // On charge la representation du joueur
        if(side=="top"){
        	directionArrow = new Image("assets/PlayerArrowDown.png");
		}
		else{
			directionArrow = new Image("assets/PlayerArrowUp.png");
		}
        
        PlayerDirectionArrow = new ImageView();
        PlayerDirectionArrow.setImage(directionArrow);
        PlayerDirectionArrow.setFitWidth(10);
        PlayerDirectionArrow.setPreserveRatio(true);
        PlayerDirectionArrow.setSmooth(true);
        PlayerDirectionArrow.setCache(true);

        Image tilesheetImage = new Image("assets/orc.png");
        sprite = new Sprite(tilesheetImage, 0,0, Duration.seconds(.2), side);
        sprite.setX(x);
        sprite.setY(y);
        //directionArrow = sprite.getClip().;

	    // Tous les joueurs ont une vitesse aleatoire entre 0.0 et 1.0
        // Random randomGenerator = new Random();
        // step = randomGenerator.nextFloat();

        // Pour commencer les joueurs ont une vitesse / un pas fixe
        step = 1;
	    
	  }

	  /**
	   *  Affichage du joueur
	   */


	  void rotate(GraphicsContext gc, double angle, double px, double py) {
		  Rotate r = new Rotate(angle, px, py);
		  gc.setTransform(r.getMxx(), r.getMyx(), r.getMxy(), r.getMyy(), r.getTx(), r.getTy());
	  }
	  
	  /**
	   *  Deplacement du joueur vers la gauche, on cantonne le joueur sur le plateau de jeu
	   */
	 
	  void moveLeft(){	    
	    if (x > 10 && x < 520){
			spriteAnimate();
		    x -= step;
	    }
	  }

	  /**
	   *  Deplacement du joueur vers la droite
	   */
	  void moveRight() 
	  {
	    if (x > 10 && x < 520) 
	    {
			spriteAnimate();
		    x += step;
	    }
	  }

	  
	  /**
	   *  Rotation du joueur vers la gauche
	   */
	  void turnLeft() 
	  {
	    if (angle > 0 && angle < 180) 
	    {
	    	angle += 1;
	    }
	    else {
	    	angle += 1;
	    }

	  }

	  
	  /**
	   *  Rotation du joueur vers la droite
	   */
	  void turnRight() 
	  {
	    if (angle > 0 && angle < 180) 
	    {
	    	angle -=1;
	    }
	    else {
	    	angle -= 1;
	    }
	  }


	  void shoot(){
	  	sprite.playShoot();
	  }
	  
	  /**
	   *  Deplacement en mode boost
	   */
	  void boost() 
	  {
	    x += step*2;
		  spriteAnimate();
	  }

	  void spriteAnimate(){
	  	  //System.out.println("Animating sprite");
		  if(!sprite.isRunning) {sprite.playContinuously();}
		  sprite.setX(x);
		  sprite.setY(y);
	  }
	  
	  public double getStep() {
		return step;
		}
	
		public void setStep(double step) {
			this.step = step;
		}
		
		abstract void event(String key);
	  
}
