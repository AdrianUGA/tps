package fr.univ_lyon1.info.m1.balleauprisonnier_fx;

import java.util.LinkedList;
import java.util.List;
import java.util.Random;


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

	final GraphicsContext gc;
	final Game game;

	/**
	 * Canvas dans lequel on va dessiner le jeu.
	 * 
	 * @param scene
	 *            Scene principale du jeu a laquelle on va ajouter notre Canvas
	 * @param w
	 *            largeur du canvas
	 * @param h
	 *            hauteur du canvas
	 */
	public Field(Scene scene, Game game) {
		super(game.getWidth(), game.getHeight());
		gc = this.getGraphicsContext2D();
		this.game = game;
		
		/** permet de capturer le focus et donc les evenements clavier et souris */
		this.setFocusTraversable(true);

		List<PlayerInterface> players = new LinkedList<PlayerInterface>();
		 // Tous les joueurs ont une vitesse aleatoire entre 0.0 et 1.0
		Random randomGenerator = new Random();

		String[] player1 = { "UP", "DOWN", "LEFT", "RIGHT", "SPACE" };
		players.add(new GraphicPlayer(gc, new HumanPlayer(Team.RED, new Position(game.getWidth() / 2, game.getHeight() - 150), Side.BOTTOM, randomGenerator.nextFloat(), player1)));
		players.add(new GraphicPlayer(gc, new ComputerPlayer(Team.RED, new Position(game.getWidth() / 3, game.getHeight() - 100), Side.BOTTOM, randomGenerator.nextFloat())));
		players.add(new GraphicPlayer(gc, new ComputerPlayer(Team.RED, new Position(game.getWidth() - game.getWidth() / 3, game.getHeight() - 100), Side.BOTTOM, randomGenerator.nextFloat())));

		String[] player2 = { "Z", "S", "Q", "D", "R" };
		players.add(new GraphicPlayer(gc, new HumanPlayer(Team.BLUE, new Position(game.getWidth() / 2, 50), Side.TOP, randomGenerator.nextFloat(), player2)));
		players.add(new GraphicPlayer(gc, new ComputerPlayer(Team.BLUE, new Position(game.getWidth() / 3, 20), Side.TOP, randomGenerator.nextFloat())));
		players.add(new GraphicPlayer(gc, new ComputerPlayer(Team.BLUE, new Position(game.getWidth() - game.getWidth() / 3, 20), Side.TOP, randomGenerator.nextFloat())));

		this.game.setPlayers(players);
		this.game.setBall(new GraphicBall());
		
		/* Keyboard Event Listener */
		this.setOnKeyPressed(new EventHandler<KeyEvent>() {
			public void handle(KeyEvent e) {
				for (PlayerInterface player : game.getJoueurs()) {
					player.event(e.getCode().toString());
				}
			}
		});


		/**
		 * 
		 * Boucle principale du jeu
		 * 
		 * handle() est appelee a chaque rafraichissement de frame soit environ 60 fois
		 * par seconde.
		 * 
		 */
		new AnimationTimer() {

			public void handle(long currentNanoTime) {
				// On nettoie le canvas a chaque frame
				gc.setFill(Color.LIGHTGRAY);
				gc.fillRect(0, 0, game.getWidth(), game.getHeight());
				
				// affichage des joueurs
				for (PlayerInterface player : game.getJoueurs()) {
					((GraphicPlayer) player).display();
				}
				
				game.playFrame();
			}
		}.start(); // On lance la boucle de rafraichissement
	}

}
