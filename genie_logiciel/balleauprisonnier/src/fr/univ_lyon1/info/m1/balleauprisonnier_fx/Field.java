package fr.univ_lyon1.info.m1.balleauprisonnier_fx;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

import javafx.animation.AnimationTimer;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.input.KeyEvent;
import javafx.scene.paint.Color;

/**
 * Classe gerant le terrain de jeu.
 * 
 */
public class Field extends Canvas {
	
	/** Joueurs */
	List<Player> rouges = new LinkedList<Player>();
	List<Player> bleus = new LinkedList<Player>();
	/** Couleurs possibles */
	String[] colorMap = new String[] {"blue", "green", "orange", "purple", "yellow"};
	/** Tableau traçant les evenements */
    ArrayList<String> input = new ArrayList<String>();
    

    final GraphicsContext gc;
    final int width;
    final int height;
    
    /**
     * Canvas dans lequel on va dessiner le jeu.
     * 
     * @param scene Scene principale du jeu a laquelle on va ajouter notre Canvas
     * @param w largeur du canvas
     * @param h hauteur du canvas
     */
	public Field(Scene scene, int w, int h) 
	{
		super(w, h); 
		width = w;
		height = h;
		
		/** permet de capturer le focus et donc les evenements clavier et souris */
		this.setFocusTraversable(true);
		
        gc = this.getGraphicsContext2D();
        
        /** On initialise le terrain de jeu */
        HashMap<String, String> keys0 = new HashMap<String, String>();
        keys0.put("UP", HumanPlayer.TURN_LEFT);
        keys0.put("DOWN", HumanPlayer.TURN_RIGHT);
        keys0.put("LEFT", HumanPlayer.MOVE_LEFT);
        keys0.put("RIGHT", HumanPlayer.MOVE_RIGHT);
        keys0.put("SPACE", HumanPlayer.SHOOT);
    	rouges.add(new HumanPlayer(gc, colorMap[0], w/2, h-150, "bottom", keys0));
    	rouges.get(0).display();
    	rouges.add(new ComputerPlayer(gc, colorMap[0], w/3, h-100, "bottom"));
    	rouges.get(1).display();
    	rouges.add(new ComputerPlayer(gc, colorMap[0], w-w/3, h-100, "bottom"));
    	rouges.get(2).display();
    	
        HashMap<String, String> keys1 = new HashMap<String, String>();
    	keys1.put("Z", HumanPlayer.TURN_LEFT);
        keys1.put("S", HumanPlayer.TURN_RIGHT);
        keys1.put("Q", HumanPlayer.MOVE_LEFT);
        keys1.put("D", HumanPlayer.MOVE_RIGHT);
        keys1.put("R", HumanPlayer.SHOOT);
    	bleus.add(new HumanPlayer(gc, colorMap[1], w/2, 50, "top", keys1));
    	bleus.get(0).display();
    	bleus.add(new ComputerPlayer(gc, colorMap[1], w/3, 20, "top"));
    	bleus.get(1).display();
    	bleus.add(new ComputerPlayer(gc, colorMap[1], w-w/3, 20, "top"));
    	bleus.get(2).display();


	    /** 
	     * Event Listener du clavier 
	     * quand une touche est pressee on la rajoute a la liste d'input
	     *   
	     */
	    this.setOnKeyPressed(
	    		new EventHandler<KeyEvent>()
	    	    {
	    	        public void handle(KeyEvent e)
	    	        {
	    	            String code = e.getCode().toString();
	    	            // only add once... prevent duplicates
	    	            if ( !input.contains(code) )
	    	                input.add( code );
	    	        }
	    	    });

	    /** 
	     * Event Listener du clavier 
	     * quand une touche est relachee on l'enleve de la liste d'input
	     *   
	     */
	    this.setOnKeyReleased(
	    	    new EventHandler<KeyEvent>()
	    	    {
	    	        public void handle(KeyEvent e)
	    	        {
	    	            String code = e.getCode().toString();
	    	            input.remove( code );
	    	        }
	    	    });
	    
	    /** 
	     * 
	     * Boucle principale du jeu
	     * 
	     * handle() est appelee a chaque rafraichissement de frame
	     * soit environ 60 fois par seconde.
	     * 
	     */
	    new AnimationTimer() 
	    {

			public void handle(long currentNanoTime)
	        {	 
	            // On nettoie le canvas a chaque frame
	            gc.setFill( Color.LIGHTGRAY);
	            gc.fillRect(0, 0, width, height);
	            
	        	
	            // Deplacement et affichage des joueurs
	        	for (Player joueur: getJoueurs()) {
	        		for(String in: input) {
	        			joueur.event(in);
	        		}
	        		joueur.display();
	    	    }
	    	}
	     }.start(); // On lance la boucle de rafraichissement 
	}

	public List<Player> getJoueurs() {
		List<Player> joueurs = new LinkedList<Player>();
	    joueurs.addAll(bleus);
	    joueurs.addAll(rouges);
		return joueurs;
	}
}
